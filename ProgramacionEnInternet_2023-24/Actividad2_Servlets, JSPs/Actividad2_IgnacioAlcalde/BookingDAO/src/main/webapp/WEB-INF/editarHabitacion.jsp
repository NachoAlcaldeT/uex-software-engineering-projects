<%@ page language="java" contentType="text/html; charset=ISO-8859-1" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions"%>
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <meta name="author" content="Nacho Alcalde">

    <title>Booking.com</title>

   <link rel="stylesheet" href="css/editarHabitacion.css">
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
	<form action="EditarHabitacionServlet.do" method="post">
		<input type="hidden" name="id" value="${accommodation.id}">
        <div class="input-group">
            <label for="nombreAlojamiento">Nombre del alojamiento</label>
            <input type="text" id="nombreAlojamiento" name="name" placeholder="Escribe el nombre de la habitacion" value="${accommodation.name}" required>
        </div>

        <div class="input-group">
            <label for="descripcion">Descripcion de la habitacion</label>
            <input type="text" id="descripcion" name="descripcion"  placeholder="Escribe la dirección" value="${accommodation.description}" required>
        </div>

        <div class="input-group">
            <label for="precio">Precio por noche</label>
            <input type="number" id="precio" name="price" placeholder="Escribe el precio por noche" value="${accommodation.price}" required>
        </div>

        <div class="input-group">
            <label for="habitaciones">Numero de habitaciones</label>
            <input type="number" id="habitaciones" name="numAccommodations" placeholder="Escribe el numero de habitaciones" value="${accommodation.numAccommodations}" required>
        </div>

        <button id="guardarCambios" class="submit-button" type= "submit">Guardar cambios</button>
        </form>
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