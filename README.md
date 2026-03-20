# Curso MacetoHuerto
> [!NOTE]
> Repositorio del curso hecho por [LabGluon](https://www.youtube.com/laboratoriogluon)
## 📋 Descripción
Este proyecto consiste en un **sistema inteligente de monitorización ambiental y riego automatizado para plantas**. Basado en el microcontrolador **ESP32-C3**.
El dispositivo está diseñado para recopilar datos ambientales y del entorno de la planta y enviarlos mediante protocolo MQTT para su almacenamiento, análisis y visualización. 
Además, funciona de manera autónoma gracias a un sistema de alimentación solar con gestión inteligente de la batería.
## 🛠️ Hardware
#### Microcontrolador
- **ESP32-C3 Mini:**
	- Comunicación **I2C** con los sensores.
	- Enviar datos por **Wifi** usando **MQTT**.
	- Uso del **bajo consumo**.
	- Uso de **FreeRTOS** y **multihilo**.
#### Sensores
- **BME280**: Implementación librería Bosch para leer temperatura, humedad y presión.
- **LDR**:  
- **Sensor de humedad del suelo (capacitivo)**:  
- **ADS1115**: 
- **HX711** y **Célula de carga**: 
#### Actuadores
- **Bomba de agua** controlada por **MASFETs**.
#### Alimentación
- **Panel solar** con sistema de carga y balanceador con **batería 18650**.
## 🖥️ Servidor
- Configuración **Proxmox**.
- **Docker** + **Docker Compose**.
- **Telegraf** + **InfluxDB** + **Grafana**.
- Recibir y mostrar datos desde **MQTT**.