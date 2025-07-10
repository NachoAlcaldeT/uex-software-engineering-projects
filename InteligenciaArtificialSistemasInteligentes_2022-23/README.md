# 🤖 Inteligencia Artificial y Sistemas Inteligentes (2022/2023)

**Asignatura:** Inteligencia Artificial y Sistemas Inteligentes  
**Curso:** 2º del Grado en Ingeniería Informática

---

## 🧠 Proyecto Final: Resolución de Laberintos con Algoritmos Heurísticos

### 🎯 Objetivo

Diseñar e implementar un agente inteligente (robot) capaz de recorrer laberintos con obstáculos y recolectar monedas hasta encontrar la salida.  
La resolución se basa en técnicas de búsqueda heurística aprendidas en la asignatura.

---

### 🧩 Algoritmos implementados

Se han implementado y comparado tres algoritmos:

- **Escalada de Máxima Pendiente**: Explora todas las direcciones posibles y elige la mejor.
- **Escalada Simple**: Selección aleatoria del movimiento que mejore la situación.
- **Escalada Estocástica**: Movimiento solo si mejora respecto a la situación actual y además supera un umbral (α).

Los resultados muestran diferencias en tiempo de ejecución y número de nodos generados, destacando la eficiencia del algoritmo estocástico en ciertos casos.

---

### 🧪 Pruebas realizadas

Se ha validado el comportamiento del agente sobre 10 laberintos distintos (`LABECOIN1.txt` a `LABECOIN10.txt`), analizando:

- Ruta encontrada (si la hay)
- Tiempo de ejecución
- Número de nodos generados

Los resultados completos se encuentran en el informe `IASI_Memoria_ResolucionLaberinto.pdf`.

---

### ⚙️ Cómo ejecutar el proyecto

1. Instalar Eclipse para Java.
2. Importar el proyecto como `Existing Project into Workspace`.
3. En el archivo `laberinto.java`, modificar la línea 42 para seleccionar el laberinto deseado (`LABECOIN1.txt`, etc.).
4. Descomenta **solo una** de las técnicas heurísticas entre las líneas 1184 y 1186 del archivo `laberinto.java`, según el algoritmo que quieras probar.
5. Ejecutar el `main()`.

---

## 📦 Contenido del repositorio
```
/InteligenciaArtificialSistemasInteligentes_2022-23
│
├── README.md                               
├── LaberintoIA_Enunciado                     # Enunciado oficial de la práctica LABECOIN
├── LaberintoIA-MemoriaProyecto               # Informe final del proyecto
├── Portfolio_LabAzureML-AlcaldeIgnacio.pdf   # Portfolio de prácticas de ML con Azure
└── LaberintoIA_Proyecto                      # Proyecto completo en Java
    ├── src/laberinto1/laberinto.java            # Lógica del agente inteligente
    ├── LABECOIN1.txt … LABECOIN10.txt           # Archivos de laberinto para las pruebas
    ├── matriz.txt                               # Mapa base de obstáculos
    ├── bin/                                     # Archivos compilados (.class)
    └── .project / .classpath / .settings/       # Configuración del proyecto Eclipse
```

---

## 📚 Portfolio de Laboratorio – Machine Learning con Azure

Además del proyecto principal, se realizaron prácticas individuales centradas en **Machine Learning con Azure**, resumidas en el documento:

- **`Portfolio_LabAzureML-AlcaldeIgnacio.pdf`**

### Contenido del portfolio:

- Sesión 1: Introducción y partición de datos con `Split Data`.
- Sesión 2: Árboles de decisión (comparativa entre 10 y 100 árboles).
- Sesión 3: Redes neuronales multicategoría.
- Sesión 4: Convolución y clasificación de imágenes (MNIST).
- Sesión 5: Comparativa entre kernels 3x3 vs 7x7 en procesamiento de imágenes con Python.

---
## 📘 Aprendizajes clave

- Aplicación de técnicas heurísticas en problemas de búsqueda con restricciones.
- Análisis comparativo de rendimiento de algoritmos en entornos dinámicos.
- Programación modular orientada a agentes inteligentes.
- Uso de entornos profesionales (Eclipse) para organizar proyectos complejos.
- Introducción práctica al aprendizaje automático con herramientas cloud como Azure ML.

---

## 📌 Conclusiones

Este proyecto permitió experimentar con distintas estrategias de resolución de problemas mediante búsqueda local.  
El diseño del agente, la gestión de laberintos y la recolección de recursos forzaron un razonamiento eficiente basado en heurísticas.  
Las prácticas de laboratorio ofrecieron una primera toma de contacto con Machine Learning moderno aplicado a entornos reales.

---

## 👨‍💻 Autores del proyecto laberinto

- Ignacio Alcalde Torrescusa  
- Darío Álvarez Barrado  
(Trabajo en pareja)

---

## 👤 Autor del portfolio de laboratorio

- Ignacio Alcalde Torrescusa  
(Trabajo individual)
