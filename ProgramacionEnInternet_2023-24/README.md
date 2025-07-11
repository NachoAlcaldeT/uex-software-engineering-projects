# 🌐 Booking - Programación en Internet (2023/2024)

**Asignatura:** Programación en Internet  
**Curso:** 3º de Grado en Ingeniería Software  
**Autor:** Ignacio Alcalde Torrescusa

---

## 📌 Descripción general

Este proyecto consiste en el desarrollo completo de una aplicación web de reservas de alojamientos, inspirada en el funcionamiento de plataformas como `Booking.com`. A lo largo de la asignatura, hemos construido el sistema de forma progresiva en tres fases, aplicando conocimientos clave de **desarrollo web full-stack**, desde el diseño del front-end hasta la implementación del back-end.

Cada actividad ha consolidado habilidades fundamentales en tecnologías web modernas, arquitectura en capas, seguridad, usabilidad y despliegue de aplicaciones interactivas.

- **Actividad 1:** Creación de la interfaz de usuario utilizando HTML y CSS.
- **Actividad 2:** Implementación de funcionalidades dinámicas con Servlets y JSP.
- **Actividad 3:** Exposición de servicios REST y desarrollo del cliente en AngularJS.

Este proyecto completo simula una aplicación real de gestión de alojamientos, desde el diseño estático hasta la lógica de negocio completa y la interacción dinámica mediante APIs REST.
---
```
## 📦 Contenido del repositorio
/ProgramacionEnInternet_2023-24  
│  
├── README.md                         # Documentación principal del proyecto  
│  
├── Actividad1_HTML_and_CSS/         # Interfaz web estática con HTML5 y CSS3  
│   ├── index.html                   # Página principal de la aplicación  
│   ├── [index2.html - index7.html]  # Vistas adicionales (login, resultados, detalle...)  
│   ├── style.css                    # Estilos base  
│   ├── [style2.css - style7.css]    # Estilos específicos por página  
│   └── img/                         # Recursos gráficos utilizados en la maqueta  
│  
├── Actividad2_Servlets_JSP/         # Back-end con Servlets, JSP y JDBC  
│   ├── src/                         # Código fuente Java (controladores, DAO, modelos)  
│   ├── webapp/                      # Archivos JSP, CSS y recursos web  
│   ├── WEB-INF/web.xml              # Configuración del despliegue  
│   ├── ServletContextListener.java  # Inicialización y cierre de conexión a la BBDD  
│   └── AT.db                        # Base de datos SQLite para pruebas  
│  
└── Actividad3_REST_AngularJS/       # API REST con JAX-RS y cliente SPA en AngularJS  
    ├── src/                         # Código fuente del servidor REST  
    ├── webapp/                      # Aplicación AngularJS (html, js, css, rutas)  
    ├── WEB-INF/web.xml              # Configuración de servicios REST  
    └── Booking.db                   # Base de datos para la API REST
```
---

## ✨ Actividad 1 – HTML y CSS

### ✅ Objetivo
Diseñar las páginas principales de la aplicación simulando las funcionalidades del sitio final sin implementar lógica. Se trabajó exclusivamente con HTML5 y CSS3 siguiendo buenas prácticas, diseño modular y estructura semántica.

### 📄 Funcionalidades representadas (mockup visual):
- Registro e inicio de sesión
- Búsqueda de alojamientos y listado de resultados de búsqueda con filtros.
- Vista detallada del alojamiento
- Edición de alojamiento
- Carrito de la compra (reserva)
- Histórico de reservas del usuario
- Página de destinos populares con estadísticas básicas

### 🖼️ Interfaz visual
- Uso intensivo de recursos gráficos: iconografía, imágenes y logotipos
- Estructura modular de páginas con hojas de estilo reutilizables
- Navegación clara, consistente y visualmente intuitiva

---

## 🧠 Actividad 2 – JSP + Servlets

> Desarrollo completo del back-end con Java EE (Servlets y JSP), lógica de negocio, persistencia y arquitectura en capas conectada a base de datos SQLite.

### ✅ Funcionalidades implementadas
- Registro e inicio de sesión con validación segura y edición de perfil
- Gestión **CRUD completa** de alojamientos y habitaciones
- Sistema de reservas, carrito y confirmación
- Valoraciones de alojamientos con comentarios visibles 
- Gestión de favoritos por usuario
- Filtro por disponibilidad y categoría
- Búsqueda avanzada de alojamientos por filtros.
- Seguridad aplicada: control de sesiones, visibilidad restringida, cifrado básico

---

## 🔁 Actividad 3 – API REST + AngularJS

> Refactorización a arquitectura RESTful y cliente SPA desarrollado con AngularJS.

### ✅ Migración completa de la app a arquitectura REST
- Exposición de servicios REST para usuarios, alojamientos, reservas, favoritos, valoraciones, etc.
- Cliente SPA (Single Page Application) en AngularJS con rutas y navegación dinámica
- Consumo de la API REST mediante servicios AngularJS y controladores independientes
- Gestión completa desde el cliente: reservas, edición, valoración, navegación

---

## ⚙️ Cómo ejecutar el proyecto

> Cada actividad se trata de un proyecto independiente.

### Actividades 2 y 3:

1. Importa el proyecto en **Eclipse IDE** usando "Import > Existing Projects into Workspace".
2. Asegúrate de tener instalado **Apache Tomcat** y configurado como servidor.
3. Lanza el proyecto desde Eclipse como "Run on Server".
4. Accede a `http://localhost:8080/BookingDAO/` en tu navegador.

> La base de datos SQLite (`AT.db` o `Booking.db`) debe estar correctamente referenciada en el archivo `ServletContextListener.java`.

---

## 📘 Aprendizajes clave

Durante el desarrollo del proyecto hemos aplicado conocimientos fundamentales de desarrollo web, tanto en el lado del cliente como en el servidor:

- Maquetación semántica y estructurada con **HTML5** y **CSS3**
- Diseño modular de interfaces visuales y uso eficiente de recursos gráficos
- Programación del **back-end en Java EE** mediante **Servlets y JSP**
- Acceso a bases de datos con **JDBC** y estructura DAO
- Gestión de sesiones, validación de usuarios y control de acceso
- Exposición de **servicios RESTful** con **JAX-RS**
- Desarrollo de un cliente SPA en **AngularJS**, con rutas y consumo de APIs

---

## 📌 Conclusiones

Este proyecto ha sido una oportunidad real para poner en práctica los conceptos clave del desarrollo web. A través de las tres actividades, hemos trabajado con tecnologías esenciales del ecosistema Java, herramientas actuales de frontend y backend, integrando todo en una aplicación completa.
