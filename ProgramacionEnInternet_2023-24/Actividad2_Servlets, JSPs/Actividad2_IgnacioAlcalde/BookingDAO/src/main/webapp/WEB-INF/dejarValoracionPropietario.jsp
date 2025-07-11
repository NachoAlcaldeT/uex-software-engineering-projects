<%@ page language="java" contentType="text/html; charset=ISO-8859-1" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions"%>
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <meta name="author" content="Nacho Alcalde">

    <title>Booking.com</title>

    <link rel="stylesheet" href="css/dejarValoracion.css">
    <link rel="icon" href="img/icono.svg">

</head>

<body>
    <header>
        <div id="bannerAzul">
            <div class="cabecera">
                <h3>Booking.com</h3>
            </div>
        </div>
    </header>

    <div class="container">
        <div class="feedback">
            <h2>Valoración</h2>
            <div class="informacion-extra1">
                <p>Eres propietario de este alojamiento, no puedes valorar tu propio alojamiento</p>
                <img src="img/informacion.png" alt="Información">
            </div>
            <div class="button-group">
                 <a class="btn" href="paginaInicio.do">Volver</a>
            </div>
        </div>
    </div>

    <div class="footer">
        <a href="#">Sobre Booking.com</a>
        <a href="#">Atención al cliente</a>
        <a href="#">Términos y condiciones</a>
        <a href="#">Política de privacidad y cookies</a>
        <a href="#">Gestiona las recomendaciones personalizadas</a>
    </div>
</body>


</html>