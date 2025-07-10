# 🚴‍♂️ Desarrollo de Programas – Ciclismo (2022/2023)

**Asignatura:** Desarrollo de Programas  
**Curso:** 2º del Grado en Ingeniería Software  
**Entorno:** BlueJ (Java 11)  
**Autores:**  
- Ignacio Alcalde Torrescusa  
- Darío Álvarez Barrado  
- Lucía Vega Cruz

---

## 🎯 Objetivo del Proyecto

Diseñar e implementar una simulación completa de una **competición ciclista por etapas**, aplicando todos los principios del **paradigma orientado a objetos**.  
El sistema modela la gestión de un campeonato por parte de una **Organización**, integrando entidades como `Ciclistas`, `Bicicletas`, `Equipos`, `Etapas` y sus **interacciones dinámicas** a lo largo del torneo.

Se trata de un proyecto progresivo con requisitos exigentes que abordan desde la **composición y herencia** hasta la gestión avanzada de **colecciones, comparadores, pruebas unitarias y documentación JavaDoc**.

---

## 🏁 Funcionamiento del sistema

- Se simula un campeonato por etapas con diferentes niveles de **dificultad** y **distancia**.
- Cada `Equipo` inscribe a sus `Ciclistas` y asigna `Bicicletas` en función de su estrategia.
- Cada `Ciclista` compite según su **habilidad, energía y tipo**, usando su bicicleta asignada.
- El sistema gestiona abandonos, clasificaciones individuales y por equipos, estadísticas detalladas y la **ceremonia de entrega de premios**.
- La simulación puede ejecutarse con datos de entrada distintos, sin interacción del usuario.

---

## 📦 Contenido del repositorio
```
/DesarrolloProgramas_Ciclismo_2022-23
│
├── README.md 
├── Ciclismo_LabEnunciados             # Enunciados oficial del proyecto
│   ├── Entrega_Inicial_Proyecto.pdf
│   └── Entrega_Final_Proyecto.pdf
└── CiclismoProyecto_OOP               # Código fuente del proyecto
    ├── CiclismoDemo.java                   # Clase principal (main)
    ├── DatosCampeonato*.java               # Datos de entrada (con y sin abandonos)
    ├── SalidaDatosCampeonato*.txt          # Resultados de la simulación
    ├── Bicicleta*.java                     # Clases de bicicletas
    ├── Ciclista*.java                      # Clases de ciclistas
    ├── Equipo.java / Etapa.java / Organizacion.java / Resultado.java
    ├── Comparadores/*.java                 # Comparadores por habilidad, energía, tiempos...
    └── *Test.java                          # Pruebas unitarias JUnit
```
---

## 🧩 Estructura del Código

Clases y componentes principales:

- **Modelo de Carrera**:  
  `Etapa`, `Dificultad`, `Distancia`

- **Entidades Ciclistas**:  
  `Ciclista`, `CiclistaNovato`, `CiclistaExperimentado`, `CiclistaEstrella`  
  → Cada tipo calcula su `destreza` de forma distinta. Los ciclistas estrella incluyen el comportamiento `SerPopular`.

- **Bicicletas**:  
  `Bicicleta`, `BicicletaRapida`, `BicicletaPrototipo`, `Peso`

- **Comparadores personalizados**:  
  `EnergiaCiclistaComparador`, `HabilidadComparador`, `PesoBicicletaComparador`, `TiempoAcumuladoComparador`, `MediaTiempoEquipoComparador`, etc.

- **Gestión de equipos y competición**:  
  `Equipo`, `Organizacion`, `CiclismoDemo` (clase `main`)

---

## ✅ Requisitos implementados

- [x] Encapsulación y composición correctamente aplicadas.
- [x] Herencia y polimorfismo funcional en `Ciclistas` y `Bicicletas`.
- [x] Gestión dinámica de colecciones: `List`, `Set`, `Map`.
- [x] Comparadores con `Comparator`, `Lambda` y `Stream`.
- [x] Uso de `Iterator`, `Enum`, `Interfaces` y `Excepciones`.
- [x] Escritura de salida a fichero (formato igual que por pantalla).
- [x] Pruebas unitarias con `JUnit` para métodos clave.
- [x] Documentación completa con `JavaDoc`.
- [x] Control de versiones con `Git` desde BlueJ.

---

## 🧪 Pruebas unitarias implementadas

Se han validado funcionalidades críticas con `JUnit` y Fixtures:

- `Ciclista`: `correr()`, `getDestreza()`, `getResultadoEtapa()`, `getEtapasTerminado()`
- `Bicicleta`: `calcularVelocidadConCiclistaEnEtapa()`, `calcularMinutosEnEtapa()`
- `Equipo`: `getMediaMinutosEquipo()`, `enviarSiguienteCiclista()`, `ordenarCiclistas()`
- `Organizacion`: `inscribirEquipo()`, `comprobarTodosCiclistasAbandonado()`

---

## 📘 Aprendizajes clave

- Diseño y simulación de sistemas complejos en Java usando OOP.
- Modularización y responsabilidades distribuidas por entidad.
- Comparación múltiple de objetos con criterios personalizados.
- Manejo de colecciones genéricas de Java (`List`, `Map`, `Set`) con orden dinámico.
- Pruebas unitarias robustas y documentadas con `JUnit`.
- Trabajo colaborativo en Git desde entorno BlueJ.

---

## 🏆 Conclusiones

Este proyecto representa una simulación completa e integral del desarrollo de un campeonato deportivo.  
Permite consolidar conocimientos clave de diseño orientado a objetos, colecciones, jerarquías, estructuras dinámicas y pruebas automatizadas.  
Ha sido una excelente práctica para entender cómo transformar requisitos complejos en soluciones modulares, extensibles y bien organizadas.
