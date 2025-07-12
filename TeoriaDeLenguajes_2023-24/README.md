# 🪑 AMUEBLA – Proyecto de Creación de Lenguaje (2023/2024)

**Asignatura:** Teoría de Lenguajes  
**Curso:** 3º de Grado en Ingeniería Software  
**Autores:** Ignacio Alcalde Torrescusa, Darío Álvarez Barrado

---

## 🎯 Descripción general

Este proyecto forma parte de la asignatura **Teoría de Lenguajes**, cuyo objetivo principal es comprender cómo se diseña y construye un lenguaje de programación desde cero.  
Durante el curso se trabajan conceptos clave como:

- Diseño de gramáticas y lenguajes formales.
- Análisis léxico y sintáctico con herramientas como **Flex** y **Bison**.
- Traducción e interpretación de programas fuente.
- Gestión de estructuras de datos y semántica de lenguajes.

Como trabajo final, desarrollamos **AMUEBLA**, un lenguaje específico de dominio (DSL) que permite describir habitaciones amuebladas y generar automáticamente su representación gráfica en C++.

---

## 🛠️ AMUEBLA: diseño y funcionamiento del lenguaje

**AMUEBLA** es un lenguaje específico de dominio (DSL) diseñado para describir gráficamente habitaciones amuebladas mediante instrucciones legibles y estructuradas.

Durante su desarrollo, implementamos tanto el **análisis léxico** (usando Flex) como el **análisis sintáctico** (usando Bison), junto con un sistema de generación de código en C++ que permite visualizar el resultado de un programa escrito en AMUEBLA.

Un programa en AMUEBLA permite:

- Declarar variables (enteras, reales y booleanas).
- Definir muebles con forma (rectángulo o círculo) y color.
- Describir habitaciones con dimensiones y título.
- Situar muebles en posiciones específicas dentro de una habitación.
- Mostrar mensajes, realizar pausas y controlar el flujo mediante estructuras como condicionales y bucles.

El proceso de traducción y ejecución consiste en:

1. El usuario escribe un programa `.amu` con las instrucciones del lenguaje.
2. El traductor analiza el fichero y genera como salida un archivo `.cpp` con llamadas a una librería gráfica personalizada basada en Allegro.
3. Al compilar y ejecutar el `.cpp`, se muestra una visualización animada de las habitaciones definidas en el archivo de entrada.

---

## 📦 Contenido del repositorio
```
/TeoriaDeLenguajes_2023-24
│
├── README.md                                       
├── AmueblaLenguaje_Enunciado2023-24.pdf            # Enunciado oficial del proyecto
└── AmueblaLenguaje_Proyecto/                       # Código fuente del proyecto AMUEBLA
    ├── AmueblaLenguaje_MemoriaProyecto.pdf         	# Memoria técnica y explicación del desarrollo
    └── src/                                        	# Código fuente principal
        ├── basica.amu                              		# Fichero de entrada en lenguaje AMUEBLA
        ├── basica.cpp                              		# Código generado a partir del .amu
        ├── amuebla.cpp / amuebla.h                		# Lógica principal del traductor
        ├── estructura.cpp / estructura.h           		# Tabla de identificadores y variables
        ├── estructuramuebles.cpp / .h              		# Gestión de muebles
        ├── lexico.l                                		# Análisis léxico (Flex)
        ├── expresiones.y                           		# Análisis sintáctico (Bison)
        ├── expresiones.c / expresiones.h           		# Archivos generados por Bison
        ├── makefile                                		# Compilación del traductor
        └── makeAmuebla                             		# Compilación completa y ejecución gráfica
 
```

---

## ▶️ Ejecución del proyecto

Para compilar y ejecutar el proyecto AMUEBLA, sigue estos pasos:

1. **Generar el fichero de salida C++** a partir del archivo de entrada en lenguaje AMUEBLA:

```bash
   make
```

2. **Compilar el programa completo y lanzar la visualización gráfica:**

```bash
make -f makeAmuebla
```

Esto compilará automáticamente el fichero basica.cpp generado, enlazando con la librería gráfica, y ejecutará el resultado, mostrando las habitaciones definidas en el archivo basica.amu.

> Requisito: Asegúrate de tener instalada la librería Allegro para que la interfaz gráfica funcione correctamente.

---

## 📌 Conclusión

El desarrollo de AMUEBLA nos permitió:

- Diseñar un lenguaje desde cero con su propia sintaxis y semántica.
- Implementar un **analizador léxico** con Flex y un **analizador sintáctico** con Bison.
- Generar código C++ de forma automática a partir del lenguaje creado.
- Utilizar **estructuras de datos eficientes** en C++ para representar identificadores, valores y elementos gráficos (muebles).

Este proyecto ha sido una experiencia técnica completa que nos ayudó a entender en profundidad cómo se construye e interpreta un lenguaje de programación.

