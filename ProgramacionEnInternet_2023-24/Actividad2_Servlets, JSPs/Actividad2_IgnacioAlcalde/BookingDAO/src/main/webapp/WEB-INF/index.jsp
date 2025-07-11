<%@ page language="java" contentType="text/html; charset=ISO-8859-1" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions"%>
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <meta name="author" content="Nacho Alcalde">
    <title>Booking.com</title>
    <link rel="stylesheet" href="css/style1.css">
    <link rel="icon" href="img/icono.svg">
</head>

<body>
    <header>
        <div id="bannerAzul">
            <div id="encuentraEstancia">
                <div id="logo">Booking.com</div>
                <a href="RegistroServlet.do"><button class="inicioSesion">¡Registrate!</button></a>
                <div id="icono1" class="iconosInicioSesion"><img src="img/bandera.png" width="30" alt="Icono Bandera"></div>
                <div id="icono2" class="iconosInicioSesion"><img src="img/ayudaWhite.png" width="30" alt="Icono Ayuda"></div>
            </div>
        </div>
    </header>
	
	<form action="HabitacionesUsuarioServlet.do" method="get">
    	<input type="number" id="userId" name="userId" placeholder="ID de usuario" class="inputAncho" min="1">
        <button type="submit" id="buscarUsuario" class="botonBuscar">Buscar</button>
    </form>
	
    <div id="login-container">
        <p class="login-message">Inicia Sesión o crea una cuenta nueva</p>
        
        <form action="LoginServlet.do" method="post">
    		<div class="form-group">
        		<label for="email" class="form-label">E-mail:</label>
        		<input type="text" id="email" name="email" class="form-input" placeholder="Indica tu dirección de email">
    		</div>
    		<div class="form-group">
        		<label for="password" class="form-label">Contraseña:</label>
        		<input type="password" id="password" name="password" class="form-input" placeholder="Introduce tu contraseña">
    		</div>
    		
    		 <c:if test="${not empty loginMessage}">
            	<div class="error-message">${loginMessage}</div>
       		 </c:if>
    		
    		<div class="form-group">
        		<button id="submit-button" class="submit-button">Iniciar Sesion</button>
    		</div>
		</form>
		
        <div class="separator-line">
            <span class="separator-text">o usar una de estas opciones</span>
        </div>
        <div id="registration-options">
            <div class="registration-option"><img src="img/icono_facebook.png" width="30" alt="Icono Facebook"></div>
            <div class="registration-option"><img src="img/icono_google.png" width="30" alt="Icono Google"></div>
            <div class="registration-option"><img src="img/icono_apple.png" width="30" alt="Icono Apple"></div>
        </div>
        <div class="separator"></div>
        <p class="disclaimer-text">Al iniciar sesión o al crear una cuenta, aceptas nuestros <span class="link-text">Términos y condiciones</span> y la <span class="link-text">Política de Privacidad</span>.</p>
        <div class="separator"></div>
        <p class="copyright-text">Todos los derechos reservados.</p>
        <p class="copyright-text">Copyright (2006-2024) - Booking.com</p>
    </div>
</body>

</html>