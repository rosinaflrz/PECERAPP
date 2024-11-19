// CODIGO DE PROYECTO FINAL
// Elaborado por Pedro Fregoso y Rosina Flores
// Version 2.0

// Librerías
#include <WiFi.h> 
#include <PubSubClient.h> 
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP32Servo.h>

// Configuración WiFi y MQTT
#define WIFISSID "Reptar" //WIFI SSID 
#define PASSWORD "AmadeusBonito002" // WIFI password 
#define TOKEN "BBUS-n5isK7rLjYwmbwxRwMpjZ1swLWGCSB" // Ubidots TOKEN 
#define MQTT_CLIENT_NAME "ESP32Client123" // MQTT Client ID 
#define VARIABLE_LABEL_TEMP "temperature" // Variable label para temperature 
#define VARIABLE_LABEL_DIST "distance" // Variable label para distance 
#define DEVICE_LABEL "esp32s3-device" // Device label 


char mqttBroker[] = "industrial.api.ubidots.com"; 
char payload[200]; 
char topic[150]; 

// Variables para publicar valores
char str_temp[10]; 
char str_dist[10]; 

// Configuración del sensor y el servo
OneWire ourWire(2);
DallasTemperature sensors(&ourWire);
Servo miServo;
const int pinServo = 19; 

// Pines del sensor ultrasónico
const int trigPin = 5;
const int echoPin = 18;
#define SOUND_SPEED 0.034  // Velocidad del sonido en cm/us
long duration;
float distanceCm;
int angulo_rotacion = 0;

// Configuración MQTT
WiFiClient ubidots; 
PubSubClient client(ubidots); 

/**************************************** 
 * Funciones auxiliares 
 ****************************************/ 
void callback(char* topic, byte* payload, unsigned int length) { 
  // Procesar mensajes entrantes si es necesario
  char p[length + 1]; 
  memcpy(p, payload, length); 
  p[length] = NULL; 
  String message(p); 
  Serial.write(payload, length); 
  Serial.println(topic); 
} 
 
void reconnect() { 
  while (!client.connected()) { 
    Serial.println("Attempting MQTT connection..."); 
     
    if (client.connect(MQTT_CLIENT_NAME, TOKEN, "")) { 
      Serial.println("Connected"); 
    } else { 
      Serial.print("Failed, rc="); 
      Serial.print(client.state()); 
      Serial.println(" try again in 2 seconds"); 
      delay(2000); 
    } 
  } 
} 

/**************************************** 
 * Funciones principales 
 ****************************************/ 
void setup() { 
  Serial.begin(115200); 
  WiFi.begin(WIFISSID, PASSWORD); 
 
  Serial.print("Wait for WiFi..."); 
  while (WiFi.status() != WL_CONNECTED) { 
    Serial.print("."); 
    delay(500); 
  } 
   
  Serial.println("\nWiFi Connected"); 
  Serial.println("IP address: "); 
  Serial.println(WiFi.localIP()); 
  client.setServer(mqttBroker, 1883); 
  client.setCallback(callback);   
 
  // Inicializar sensores y servo
  sensors.begin(); 
  miServo.attach(pinServo);
  
  // Configurar los pines del sensor ultrasónico
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);
} 
 
void loop() { 
  if (!client.connected()) { 
    reconnect(); 
  } 
  
  client.loop();

  // Medición de temperatura
  sensors.requestTemperatures(); 
  float temp = sensors.getTempCByIndex(0);
  Serial.print("Measured Temperature (°C): ");
  Serial.println(temp); 
  dtostrf(temp, 4, 2, str_temp); 

  // Medición de distancia
  digitalWrite(trigPin, LOW);
  delayMicroseconds(20);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * SOUND_SPEED / 2;
  Serial.print("Measured Distance (cm): ");
  Serial.println(distanceCm);
  dtostrf(distanceCm, 4, 2, str_dist);

  // Publicar temperatura
  sprintf(topic, "/v1.6/devices/%s", DEVICE_LABEL); 
  sprintf(payload, "{\"%s\": {\"value\": %s}}", VARIABLE_LABEL_TEMP, str_temp); 
  Serial.println("Sending Temperature to Ubidots...");
  client.publish(topic, payload);

  // Publicar distancia
  sprintf(payload, "{\"%s\": {\"value\": %s}}", VARIABLE_LABEL_DIST, str_dist); 
  Serial.println("Sending Distance to Ubidots...");
  client.publish(topic, payload);

  // Movimiento del Servo basado en distancia
  if (distanceCm <= 15) {
    angulo_rotacion = 180;
  } else {
    angulo_rotacion = 0;
  }

  miServo.write(angulo_rotacion);
  Serial.print("Servo rotation: ");
  Serial.print(angulo_rotacion);
  Serial.println(" degrees");

  delay(2000); // Esperar 2 segundos antes de la siguiente lectura
}
