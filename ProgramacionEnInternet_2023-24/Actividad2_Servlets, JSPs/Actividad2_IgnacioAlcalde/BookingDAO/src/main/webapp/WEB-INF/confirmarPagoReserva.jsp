<%@ page language="java" contentType="text/html; charset=ISO-8859-1" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions"%>
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <meta name="author" content="Nacho Alcalde">

    <title>Booking.com</title>

    <link rel="stylesheet" href="css/confirmarPagoReserva.css">
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
        <div class="confirmation">
            <h2>Pago Confirmado</h2>
            <p>Gracias por su reserva, ${user.name} ${user.surname} </p>
        </div>
    </div>
    <div class="container2">
        <div class="detallesReserva">
            <h3>Detalles de su reserva</h3>

            <table id="informacionReserva">
                <thead>
                    <tr>
                        <th class="listaFavoritos">ID reserva</th>
                        <th class="listaFavoritos">Nº de habitaciones</th>
                        <th class="listaFavoritos">Precio Total</th>
                    </tr>
                </thead>
                <tbody>
                    <tr>
                        <td class="listaFavoritos">${booking.id}</td>
                        <td class="listaFavoritos">${numHabitaciones}</td>
                        <td class="listaFavoritos">${booking.totalPrice} $</td>
                    </tr>
                </tbody>
            </table>

            <form action="ReservasUsuarioServlet.do" method="post" style="display: inline;">
                <button class="btn" type="submit">Continuar</button>
            </form>
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