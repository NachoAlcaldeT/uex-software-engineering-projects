# 📊 FeedApp – Advanced Software Technologies (2024/2025)

**Asignatura:** Desarrollo Web / Prototipado de Aplicaciones  
**Curso:** 4º de Grado en Ingeniería Software  
**Autores:** Ignacio Alcalde Torrescusa, Darío Álvarez Barrado, Rafael Guiberteau Tinoco, Carlos Fernández Calderón    
**Universidad:** Western Norway University of Applied Sciences (HVL), Bergen, Noruega  

## 🎯 Objetivo del Proyecto

Desarrollar una aplicación web llamada **FeedApp**, diseñada para la creación, edición y gestión de encuestas interactivas, permitiendo a los usuarios participar en votaciones y visualizar resultados en tiempo real.  
El sistema incorpora autenticación, persistencia de datos, mensajería en tiempo real, analítica y una arquitectura robusta. Durante el desarrollo, se reflexionó sobre el uso de tecnologías como **Java Servlets** frente a alternativas como **Spring Boot**, profundizando en sus ventajas y limitaciones para proyectos de pequeña escala.

---

## 🧩 Funcionalidades Clave

- Crear, editar y eliminar encuestas.
- Votar (usuarios registrados o invitados).
- Visualizar resultados en tiempo real.
- Gestión de perfil de usuario (encuestas creadas y votos emitidos).
- Sistema de autenticación y sesiones.
- Informes analíticos mediante MongoDB y RabbitMQ.

---

## 🏗️ Arquitectura y Tecnologías

### 📦 Backend

- **Java Servlets** como tecnología principal para la lógica del servidor.
- **JDBC** para conexión con bases de datos relacionales.
- **RabbitMQ** para comunicación asíncrona con el módulo de analítica.

### 🖥️ Frontend

- **JSP** para la generación dinámica de páginas.
- **CSS** y **JavaScript** para la capa visual e interacción dinámica.

### 🗄️ Almacenamiento

- **SQLite** para datos estructurados (usuarios, encuestas, votos).
- **MongoDB** para estadísticas y datos analíticos semiestructurados.

### 🧪 Herramientas Complementarias

- **LaTeX** para la elaboración profesional de la documentación técnica del proyecto.
- **Postman** para la realización de pruebas y validaciones sobre la API REST.

---

## 📋 Contenido del repositorio
```
/AdvancedSoftwareTechnologies_2024-25
│
├── FeedApp_FinalProyect  
│   ├── Databases/                  # Base de datos SQLite (BGFA.db)  
│   └── Project Code/              
│       └── src/main/              
│           ├── java/es/unex/pi/   
│           │   ├── controller/     # Servlets principales  
│           │   ├── dao/            # Acceso a datos (DAOs)  
│           │   ├── model/          # Entidades: User, Poll, Vote...  
│           │   └── util/           # Conexión MongoDB y helpers  
│           └── webapp/            
│               ├── css/            # Estilos CSS  
│               ├── js/             # Scripts  
│               ├── img/            # Recursos gráficos  
│               ├── WEB-INF/        # JSPs y configuración  
│               └── META-INF/  
└── FeedApp_LaTex/
    ├── FeedApp.pdf                # Memoria documental del proyecto                
    ├── report.tex                 # Documento principal en LaTeX  
    ├── report.bib                 # Bibliografía  
    └── sections/                  # Secciones del informe divididas
```
---

## 📘 Aprendizajes clave

- Profundización en tecnologías como **Servlets, JDBC, JSP, RabbitMQ y MongoDB**.
- Diseño de arquitectura híbrida relacional/NoSQL.
- Experiencia comparativa entre frameworks (Servlets vs Spring Boot).
- Gestión de sesiones, peticiones HTTP y asincronía.
- Validación de endpoints mediante **Postman**.
- Organización en equipo, integración continua y despliegue local.

---

## 📌 Conclusiones

FeedApp representó una experiencia enriquecedora de trabajo colaborativo en el contexto de un entorno internacional. 

La posibilidad de trabajar en equipo desde distintas perspectivas, combinar enfoques y documentar de forma rigurosa todo el proceso fue uno de los mayores aprendizajes del proyecto.

> Proyecto desarrollado durante el **programa Erasmus 2024–2025** en la **Western Norway University of Applied Sciences (HVL)**, en Bergen, Noruega.

---
