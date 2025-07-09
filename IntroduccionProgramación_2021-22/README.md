# 🃏 Proyecto Set – Introducción a la Programación (2021/2022)

**Asignatura:** Introducción a la Programación  
**Curso:** 1º de Grado en Ingeniería Informática  
**Autores:** Ignacio Alcalde Torrescusa, Darío Álvarez Barrado  

---

## 🎯 Objetivo del proyecto

Diseñar, implementar y documentar en C++ una versión del juego **Set**, utilizando los fundamentos de programación estructurada, tipos abstractos de datos (TADs) y estructuras modulares.  
El juego cuenta con una interfaz gráfica proporcionada por la librería `entorno`, y su funcionamiento se basa en la identificación de tríos de cartas (sets) con características particulares.

---

## 🕹️ Funcionamiento del juego

- El usuario se desplaza por el tablero con las teclas `← ↑ ↓ →` y selecciona cartas con `Enter`.
- Se muestran inicialmente 9, 12 o 15 cartas, dependiendo del fichero de configuración `set.cnf`.
- Si tres cartas seleccionadas forman un **set válido**, desaparecen y se reemplazan por otras nuevas.
- El juego continúa hasta alcanzar una puntuación objetivo o pulsar `Esc`.

---

## 🧩 Estructura del código

El proyecto está organizado en módulos bien estructurados que implementan los siguientes TADs:

### 🔹 TAD Carta
- Gestión de las características de cada carta (forma, color, número, relleno).

### 🔹 TAD Baraja
- Control y aleatorización de las 81 cartas posibles.

### 🔹 TAD Tablero
- Gestión del conjunto de cartas visibles y su selección.

### 🔹 TAD Juego
- Control de la lógica general del juego: interacción, puntuación, interfaz y flujo.

### 🔹 Librería Entorno
- Proporcionada por la asignatura, utilizada para la interfaz gráfica (Allegro5).

---

## 📦 Contenido del repositorio
```
/IntroduccionProgramacion_2021-22
│
├── README.md
├── IP2122_Proyecto_Set.pdf          # Enunciado original
└── JuegoSet                         # Proyecto completo
    ├── src
    │   ├── TADcarta.cpp / .h
    │   ├── TADbaraja.cpp / .h
    │   ├── TADtablero.cpp / .h
    │   ├── TADjuego.cpp / .h
    │   ├── entorno.cpp / .h
    │   └── main.cpp
    ├── img                          # Imágenes PNG + fuente .ttf
    └── Memoria_JuegoSet(IP).pdf    # Documento final del proyecto
```

---

## 🛠️ Requisitos técnicos

- Compilación en **Eclipse** con soporte de C++.
- Requiere tener instalada la librería **Allegro5**.
- Utiliza el fichero de configuración `set.cnf` para los parámetros iniciales.

---

## 📝 Conclusiones

Este proyecto marcó nuestro primer contacto real con el desarrollo completo de software, desde el análisis y diseño hasta la codificación y pruebas.  
La experiencia de trabajar en pareja fue muy enriquecedora, mejorando nuestra capacidad de resolver problemas, organizar módulos y mantener una lógica limpia y funcional.

> “Nos ha despertado el interés por seguir programando, descubrir nuevos lenguajes y disfrutar construyendo desde cero.”

---

## 👨‍💻 Autores

- **Darío Álvarez Barrado**  
- **Ignacio Alcalde Torrescusa**
