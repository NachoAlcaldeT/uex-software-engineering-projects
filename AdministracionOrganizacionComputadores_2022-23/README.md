# 🧱 Tetris en C++ y Ensamblador - Administración y Organización de Computadores (2022-23)

**Curso:** 2º Grado en Ingeniería Software – UEx  
**Asignatura:** Administración y Organización de Computadores (2022-23)  
**Autor:** Ignacio Alcalde Torrescusa

---

## 🎯 Objetivo de la Práctica

Desarrollar una versión funcional y completa del juego **Tetris**, combinando la programación en **C++ con interfaz Qt** y la implementación en **ensamblador x86-64** de las funciones principales que controlan la lógica del juego.  
El proyecto incluye el diseño de la interfaz gráfica, la gestión del contenedor de juego, el control de piezas, la detección de huecos y líneas completas, y la manipulación directa de memoria usando instrucciones en ensamblador integradas mediante `asm volatile`.

---

## 📦 Estructura del Proyecto

```
/AdministracionOrganizacionComputadores_2022-23
│
├── TetrisGame_Enunciado.pdf # Enunciado original de la práctica
└── TetrisGame_CppASM # Proyecto completo
	├── main.cpp
	├── mainForm.ui # Interfaz gráfica creada con Qt Designer
	├── pracaoc.h / pracaoc.cpp # Clase principal de la aplicación
	├── tetris.h / tetris.cpp # Lógica del juego y funciones a completar en ASM
	└── pracaoc.pro # Fichero Qt para compilar el proyecto
```

---

## 🛠️ Funcionalidades Implementadas en ensamblador

Se han implementado en ensamblador (x86-64) las siguientes funciones del juego:

| Función         | Descripción                                                                 |
|----------------|-----------------------------------------------------------------------------|
| `vaciaContenedor` | Vacía el contenedor de juego dejando solo los "muros" laterales y inferiores. |
| `borraPieza`       | Elimina una pieza específica del contenedor en su posición actual.           |
| `insertaPieza`     | Inserta una pieza en una posición concreta dentro del contenedor.            |
| `huecoLibre`       | Comprueba si se puede colocar una pieza en una determinada posición.         |
| `borraFilas`       | Borra filas completas y desplaza hacia abajo las que estén encima.           |
| `annadeFila`       | Añade una nueva fila en la parte inferior del contenedor.                    |

---

## 🖥️ Requisitos Técnicos

- Sistema operativo Linux.
- Qt Creator y librerías Qt instaladas.
- Compilador `g++` con soporte para ensamblador (x86-64).

---

## 🕹️ Instrucciones de Uso

1. Abre el archivo `pracaoc.pro` con **Qt Creator**.
2. Verifica que tienes configurado un **kit de compilación** con `g++` y arquitectura **x86-64**.
3. Haz clic en el botón **Run (▶️)** para compilar y lanzar la aplicación.
4. Una vez abierta la interfaz, podrás jugar al Tetris o probar individualmente las funciones implementadas en ensamblador desde los botones disponibles.

---

## 🎮 Interfaz de Usuario

- Área principal de juego con visualización de piezas.
- Controles para rotación, movimiento, velocidad y pruebas.
- Sistema de puntuación por filas eliminadas.

---

## 🧠 Aprendizajes clave

- Comprensión profunda de cómo interactúa el ensamblador con estructuras de datos en memoria.
- Uso del ensamblado en línea (`asm volatile`) para integrar código en C++ y lenguaje ensamblador.
- Manipulación eficiente de matrices en memoria y acceso mediante punteros y registros.
- Diseño modular y estructurado de una aplicación con interfaz gráfica usando Qt.
- Depuración y validación de funciones de bajo nivel a través de un entorno visual interactivo.

---

## 📌 Conclusión

Este proyecto permitió aplicar conocimientos tanto de programación de alto nivel como de bajo nivel, integrando ensamblador en una aplicación gráfica real.  
Una experiencia muy completa para entender cómo se comunica el hardware con el software desde el nivel más bajo.

---

## 👨‍💻 Autor

- **Ignacio Alcalde Torrescusa**
