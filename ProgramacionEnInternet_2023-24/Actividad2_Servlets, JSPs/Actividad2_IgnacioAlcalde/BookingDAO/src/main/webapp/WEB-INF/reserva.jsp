<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Confirmación de Reserva</title>
<link rel="stylesheet" href="css/reserva.css">
</head>
<body>
    <div class="container">
        <h1>Confirmación de Reserva</h1>
        
        <div class="reserva-details">
            <p>Precio por habitación: $${pricePerRoom}</p>
            <p>Número de habitaciones seleccionadas: ${numRooms}</p>
            <p>Precio Total a Pagar: $${totalPrice}</p>
        </div>
        
        <div class="button-container">
            <a href="index.jsp" class="button">Volver al Inicio</a>
        </div>
    </div>
</body>
</html>
