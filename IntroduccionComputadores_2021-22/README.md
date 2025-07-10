# 🖥️ Juego 2048 - Introducción a los Computadores (2021/2022)

**Asignatura:** Introducción a los Computadores  
**Curso:** 1º de Grado en Ingeniería del Software  
**Autor:** Ignacio Alcalde Torrescusa  
**Herramienta usada:** Emu8086 (emulador de procesador Intel 8086)

---

## 🎯 Objetivo del proyecto

Implementar el juego **2048** en lenguaje ensamblador (Assembly), ejecutándose sobre un entorno DOS, controlado por teclado y con impresión en pantalla en modo texto. El objetivo didáctico fue profundizar en el uso de estructuras de datos en memoria, operaciones bit a bit, gestión de la pantalla, manipulación del teclado y generación de números pseudoaleatorios.

---

## 🧩 Contenido del proyecto

### Código principal
- `2048_BASE.asm`: archivo ensamblador principal, modularizado con múltiples procedimientos.
- Organización en procedimientos reutilizables como:
  - `MatrizAVector`, `VectorAMatriz`
  - `CopiarVector`, `BorrarVector`
  - `NumAleatorio2o4`, `comprobarFinJuego`
  - `pintarTablero`, `comandoEntrada`, `controlEntrada16_2048`, etc.

---

## 🕹️ Mecánica del juego

- **Tablero 4x4**, almacenado en un vector de 16 celdas tipo `DW`.
- **Movimientos controlados** con teclas:
  - `W` (Arriba), `S` (Abajo), `A` (Izquierda), `D` (Derecha)
  - `O` (Nuevo juego), `E` (Salir)
- **Modo Debug**: tablero precargado con valores para pruebas.
- **Condiciones de fin de juego**:
  - Ganar: se alcanza el número introducido como `tope` (ej. 2048).
  - Perder: no quedan celdas vacías ni se alcanzó el tope.

---

## 🖥️ Requisitos técnicos

- El juego se desarrolla en **lenguaje ensamblador x86**, utilizando:
  - Registros como `AX`, `SI`, `DI`, `CX`, `AL`, `AH`
  - Interrupciones DOS (`int 21h` y `int 10h`) para E/S y gráficos.
- Ejecutable en **Emu8086**, **DOSBox**, o entornos virtualizados compatibles con código DOS.
- Se hace uso extensivo de macros, saltos condicionales y operaciones bit a bit.

---

## 🧠 Aprendizajes clave

- Manipulación de **estructuras matriciales** en memoria lineal.
- Generación de **números pseudoaleatorios** con interrupciones.
- Desarrollo de **interfaces de usuario en modo texto**.
- Gestión de entradas sin eco (`LeerTeclaSinEco`) y control robusto de errores.
- Uso eficiente de la pila (`push/pop`) y segmentación `data/code`.

---

## 🛠️ Cómo ejecutar el juego

### Con Emu8086 (recomendado)
1. Descarga e instala Emu8086.
2. Abre el archivo `2048_BASE.asm` desde el entorno de Emu8086.
3. Compila y ejecuta directamente desde el botón “Compile and Run”.
4. Usa las teclas del teclado para controlar el juego.

---

## 📝 Conclusión

Este proyecto supuso un desafío técnico importante al ser una de las primeras tomas de contacto con la programación de bajo nivel. La implementación del juego 2048 en ensamblador permitió afianzar los conceptos fundamentales de la arquitectura de computadores y el control total de la memoria, pantalla y lógica algorítmica.

---

```
## 📁 Archivos incluidos
├── README.md
├── 2048_BASE.asm # Código ensamblador del juego completo
├── 2048Game-Ensamblador_Enunciado.pdf # Contiene todos los enunciados por fases del proyecto.
└── 2048Game-MemoriaProyecto_2021-22.pdf # Explicación paso a paso de la interfaz, ejemplos y funcionamiento interno
```

---

## 👨‍💻 Autor

**Ignacio Alcalde Torrescusa**  
(Universidad de Extremadura, 2021–22)
