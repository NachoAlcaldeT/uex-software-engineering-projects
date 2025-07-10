# 🌐 Fundamentos de Redes y Comunicaciones (2022/2023)

**Asignatura:** Fundamentos de Redes y Comunicaciones  
**Curso:** 2º de Grado en Ingeniería Software  
**Autores:** Ignacio Alcalde Torrescusa  

---

## 🎯 Objetivo del Proyecto

Diseñar e implementar un protocolo de comunicaciones **Maestro–Esclavo**, basado en tramas Ethernet personalizadas, con soporte para **control de flujo** y **detección y corrección de errores**.  
El proyecto simula un entorno de red realista a nivel de enlace, desarrollando progresivamente funcionalidades de bajo nivel que permiten gestionar la comunicación punto a punto, detectar errores, y aplicar retransmisiones automáticas. Todo ello se probó con tramas reales y archivos intercambiados entre emisor y receptor.

Este trabajo refleja en profundidad cómo funciona la transmisión fiable de datos en redes físicas, desde el nivel más próximo al hardware.

---

## 🧩 Evolución del Proyecto

El protocolo se construyó en cinco etapas prácticas:

- **Entrega 1:**  
  - Introducción al modelo OSI, TCP/IP y a la tecnología Ethernet.  
  - Instalación de herramientas (Wireshark, libpcap, VSCode).  
  - Configuración de la librería `LinkLayer` para acceso a tarjetas de red.

- **Entrega 2:**  
  - Creación de tramas Ethernet con campos personalizados.  
  - Envío y recepción de tramas utilizando direcciones MAC reales.  

- **Entrega 3:**  
  - Implementación de un protocolo Maestro–Esclavo simple (sin errores).  
  - Lógica de selección y sondeo, visualización de tramas.  

- **Entrega 4:**  
  - Mejora del protocolo con **control de flujo** mediante técnica de **parada y espera**.  
  - Introducción de tramas numeradas, ACKs y sincronización entre nodos.

- **Entrega 5 (final):**  
  - Añadido de **detección de errores con BCE** y tramas NACK.  
  - Simulación de errores mediante tecla `F4` y validación completa de comunicación.  
  - Asegura la coincidencia exacta entre los archivos `EProtoc.txt` (emisor) y `RProtoc.txt` (receptor), incluso en presencia de fallos.

> El sistema final reproduce fielmente cómo funcionan los protocolos reales en redes cableadas, incluyendo errores, retransmisiones y recuperación completa.

## 📦 Contenido del repositorio
```
/FundamentosRedesComunicaciones_2022-23
│
├── README.md                              
├── Enunciados_FRC                      # Enunciados originales de cada entrega
│   ├── FRC-Entrega 1.pdf
│   ├── FRC-Entrega 2.pdf
│   ├── FRC-Entrega 3.pdf
│   ├── FRC-Entrega 4.pdf
│   └── FRC-Entrega 5.pdf
└── ProyectoProtocolo_MaestroEsclavo     # Proyecto completo (Entrega 5)
    ├── envio.txt                               # Contenido a transmitir
    ├── EProtoc.txt / RProtoc.txt               # Archivos de prueba (envío/recepción)
    ├── Sesion5.cpp                             # Programa principal que ejecuta el protocolo de comunicación
    ├── networkFunctions.cpp / .h               # Funciones de red y lógica de tramas
    └── userInterface.cpp / .h                  # Interfaz de usuario en consola
```

---

### ⚙️ Cómo ejecutar el proyecto

1. Abre la carpeta del proyecto en **Visual Studio Code**.
2. Asegúrate de tener instalado `g++`, `libpcap-dev` y los permisos adecuados.
3. Compila el programa desde terminal y ejecútalo con privilegios de superusuario:

```bash
sudo ./Sesion5
```

## 📘 Aprendizajes clave

- Comprensión práctica del modelo TCP/IP, OSI.
- Desarrollo desde cero de un protocolo de comunicaciones completo y fiable.
- Diseño de tramas Ethernet personalizadas con campos adaptados al protocolo.
- Implementación de técnicas de **control de flujo** y **detección/corrección de errores** (ACK/NACK, BCE).
- Simulación de canales de red ruidosos e integración de fallos intencionados.
- Trabajo con librerías externas como `LinkLayer` y `libpcap` para acceder directamente a dispositivos de red.
- Configuración profesional de entornos de desarrollo en Linux con Visual Studio Code.

---

## 📌 Conclusiones

Este proyecto supuso una aproximación realista a cómo funcionan las redes físicas en entornos industriales y académicos.  
La progresión por entregas permitió construir un protocolo robusto desde los fundamentos, abordando retos de sincronización, fiabilidad y detección de errores.  
El trabajo demuestra competencias sólidas en programación de bajo nivel, comprensión del tráfico Ethernet y dominio del ciclo completo de desarrollo de protocolos de comunicación.
