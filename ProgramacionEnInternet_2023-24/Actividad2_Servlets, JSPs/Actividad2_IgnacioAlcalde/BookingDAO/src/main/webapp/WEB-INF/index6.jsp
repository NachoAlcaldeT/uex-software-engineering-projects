<%@ page language="java" contentType="text/html; charset=ISO-8859-1" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions"%>
<!DOCTYPE html>
<html lang="es">

<head>
    <meta charset="utf-8">
    <meta name="author" content="Nacho Alcalde">

    <title>Booking.com</title>

     <link rel="stylesheet" href="css/style66.css">
    <link rel="icon" href="img/icono.svg">
</head>

<body>
    <header>
        <div id="bannerAzul">
            <div class="cabecera">
                <h3>Booking.com</h3>

                <p id="EUR">EUR</p>

                <div id="icono1" class="iconosInicioSesion"><img src="img/bandera.png" alt="Bandera" width="30"></div>
                <div id="icono2" class="iconosInicioSesion"><img src="img/ayudaWhite.png" alt="Ayuda" width="30"></div>

                <p>Registra tu alojamiento</p>

                <c:choose>
	            <c:when test="${not empty user.id}">
	                <a href="PerfilServlet.do"><button class="inicioSesion">Perfil</button></a>
	            </c:when>
	            <c:otherwise>
	                <div id="botonesInicioSesion">
	                    <a href="LoginServlet.do"><button class="inicioSesion">Inicia sesión</button></a>
	                    <a href="RegistroServlet.do"><button class="inicioSesion">Hazte una cuenta</button></a>
	                </div>
	            </c:otherwise>
	        	</c:choose>
            </div>
    </header>
    <div class="container">
        <div id="inicio_reservas">
            <div id="titulo">
                Reserva y viajes
            </div>
            <div id="pregunta_inicial_reservas">
                <a href="#" class="blue-link">¿No encuentras una reserva?</a>
            </div>
        </div> 
        <c:forEach var="booking" items="${bookingList}" varStatus="loop">
			<c:forEach var="property" items="${propertyList}">
				<c:forEach var="bookingAcc" items="${bookingAccomodationsList}">
					<c:forEach var="accommodation" items="${accommodationList}">
		    			<c:if test="${booking.idu ==  user.id && booking.id == bookingAcc.idb && bookingAcc.idacc == accommodation.id && accommodation.idp == property.id }">
					        <div class="Reserva">
					            <div class="Ubicacion_reserva">
					                ${property.city}
					            </div>
					            <div class="fechas_reserva">
					                30 nov 2023 - 1 dic 2023
					            </div>
					            <div id="Desc_reserva">
					                <img src="img/Reserva${loop.index % 3 + 1}.png" alt="Foto reserva${loop.index % 3 + 1}" id="foto_reserva">
					                <div>
					                    <div class="Nombre_hotel_reserva">
					                         ${property.name}
					                    </div>
					                    <div class="Fechas_reserva_rectangulo">
					                        30 nov 2023 - 1 dic 2023 - Madrid
					                    </div>
					                    <div class="Fechas_reserva_rectangulo">
					                        Cancelada
					                    </div>
					                </div>
					                <div class="Precio_reserva">
					                    ${booking.totalPrice}
					                </div>
					                <img src="img/3puntos_reservas.png" alt="Foto menu" id="foto_menu_reserva">
					            </div>
					        </div>
			            </c:if>
					</c:forEach>
				</c:forEach>
			</c:forEach>
		</c:forEach>
    </div>

    <div class="footer">
        <a href="#">Sobre Booking.com</a>
        <a href="#">Atención al cliente</a>
        <a href="#">Términos y condiciones</a>
        <a href="#">Política de privacidad y cookies</a>
        <a href="#">Gestiona las recomendaciones personalizadas</a>
    </div>

    <script>
        document.getElementById('inicioSesion').addEventListener('click', function() {
            // Redirige a la página index5.html
            window.location.href = 'index7.html';
        });
    </script>
</body>

</html>