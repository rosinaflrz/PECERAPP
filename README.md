# PECERAPP
IoT final project

PECERAPP es un proyecto creado para la materia de IoT, con el objetivo de innovar en el sector de la acuicultura.
La acuicultura es responsable de más de 50% de los productos acuáticos consumidos a nivel mundial.
Los problemas más comunes son:
  * Condiciones de agua inadecuadas y fluctuante
  * Falta de herramientas eficientes de monitoreo en tiempo real

## ¿Qué es PECERAPP?
Pecerapp es una plataforma IoT diseñada para monitorear y gestionar las condiciones de los acuarios de forma remota y eficiente.

*Objetivo:* Garantizar condiciones óptimas para la flora y fauna acuática
*Cómo lo logra:* Mediante sensores avanzador y automatización en tiempo real
*Notificaciones:* Alertas automáticas cuando los parámetros que activa el servomotor MG995 para el relleno automático del agua en caso de niveles bajos.
*Visualización en la nube:* Plataforma en la nube (Ubidots con protocolo HTTP) para acceso a los datos actuales y su hitorial.
*Accionamiento automático:* Cuando los parámetros de la pecera (como el nivel del agua) caigan por debajo de los límites, el sistema debe activar el actuador para rellenar automáticamente el agua, esto con el servomotor conectado al sistema de bombeo, de esta manera el sistema podrá controlar el flujo de agua en la pecera

### Arquitectura técnica de PECERAPP
*Hardware*
  * Semsores DS18B20 (temperatura) y HC-SR04 (nivel de agua)
  * Actuador MG995 para el control del servomotor
  * Microcontrolador (Arduino)

*Software*
  * Plataforma en la nube (Ubidots)
  * Web para la visualización de datos en tiempo real y notificaciones

