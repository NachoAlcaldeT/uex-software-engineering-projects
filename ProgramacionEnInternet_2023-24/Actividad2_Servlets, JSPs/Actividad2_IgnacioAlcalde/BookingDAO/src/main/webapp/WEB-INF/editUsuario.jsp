<%@ page language="java" contentType="text/html; charset=ISO-8859-1" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions"%>
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <meta name="author" content="Nacho Alcalde">
    <title>Booking.com</title>
    <link rel="stylesheet" href="css/editUsuario.css">
    <link rel="icon" href="img/icono.svg">
</head>

<body>
    <header>
        <div id="bannerAzul">
            <div id="encuentraEstancia">
                <div id="logo">Booking.com</div>
                <div id="icono1" class="iconosInicioSesion"><img src="img/bandera.png" width="30" alt="Icono Bandera"></div>
                <div id="icono2" class="iconosInicioSesion"><img src="img/ayudaWhite.png" width="30" alt="Icono Ayuda"></div>
            </div>
        </div>
    </header>

    <div id="login-container">
        <p class="login-message">Perfil</p>
        <form action="EditarUsuarioServlet.do" method="post">
        <input type="hidden" name="id" value="${user.id}">
            <label for="name" class="form-label">Nombre</label>
            <input type="text" id="name" class="form-input" name="name" value="${user.name}">
            <label for="surname" class="form-label">Apellido</label>
            <input type="text" id="surname" class="form-input" name="surname" value="${user.surname}">
            <label for="email" class="form-label">E-mail</label>
            <input type="text" id="email" class="form-input" name="email" value="${user.email}" >
            <label for="password" class="form-label">Contraseña</label>
            <input type="text" id="password" class="form-input" name="password" value="${user.password}">

            <button id="submit-button" class="submit-button" type= "submit">Confirmar cambios</button>
        </form>
        
        <div class="separator"></div>
        <p class="disclaimer-text">Al iniciar sesión o al crear una cuenta, aceptas nuestros <span class="link-text">Términos y condiciones</span> y la <span class="link-text">Política de Privacidad</span>.</p>
        <div class="separator"></div>
        <p class="copyright-text">Todos los derechos reservados.</p>
        <p class="copyright-text">Copyright (2006-2024) - Booking.com</p>
    </div>
</body>

</html>
