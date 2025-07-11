<%@ page language="java" contentType="text/html; charset=ISO-8859-1" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions"%>
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <meta name="author" content="Nacho Alcalde">

    <title>Booking.com</title>

    <link rel="stylesheet" href="css/style7.css">
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
		<form action="EditarAlojamientoServlet.do" method="post">
			<input type="hidden" name="id" value="${property.id}">
	        <div class="input-group">
		   		<label for="nombreAlojamiento">Nombre del alojamiento</label>
		    	<input type="text" id="name" name="name" value="${property.name}" required>
			</div>
			
			<div class="input-group">
			    <label for="direccion">Cuidad</label>
			    <input type="text" id="city" name="city" value="${property.city}" required>
			</div>
			
			<div class="input-group">
			    <label for="direccion">Dirección</label>
			    <input type="text" id="address" name="address" value="${property.address}" required>
			</div>
			
			<div class="input-group">
			    <label for="telefono">Teléfono</label>
			    <input type="tel" id="telephone" name="telephone" value="${property.telephone}" required>
			</div>
			
			<div class="input-group">
			    <label for="distanciaCentro">Distancia al centro (en km)</label>
			    <input type="text" id="centerDistance" name="centerDistance" value="${property.centerDistance}" required>
			</div>
			
			<div class="input-group">
			    <label for="valoracion">Valoración media</label>
			    <input type="text" id="gradesAverage" name="gradesAverage" value="${property.gradesAverage}" required>
			</div>
			
			<div class="input-group">
			    <label for="descripcion">Descripción</label>
			    <input type="text" id="description" name="description" value="${property.description}" required>
			</div>
	
	        <p>Servicios o instalaciones ofrecidos:</p>
	        <div class="instalaciones">
	            <div class="checkbox-option">
	                 <input type="checkbox" id="wifi" name="wifi" value="1">
	                <label>WiFi</label>
	            </div>
	            <div class="checkbox-option">
	                <input type="checkbox" id="tv" name="tv" value="1">
	                <label>TV</label>
	            </div>
	            <div class="checkbox-option">
	                <input type="checkbox" id="aireAcondicionado" name="aireAcondicionado" value="1">
	                <label>Aire</label>
	            </div>
	        </div>
	        
	        <p>Disponibilidad:</p>
				<div class="instalaciones">
				    <div class="checkbox-option">
				        <input type="radio" id="disponibleSi" name="available" value="1" ${property.available == 1 ? "checked":""} onclick="deseleccionar('disponibleNo')">
				        <label for="disponibleSi">Sí</label>
				    </div>
				    <div class="checkbox-option">
				        <input type="radio" id="disponibleNo" name="available" value="0" ${property.available == 0 ? "checked":""} onclick="deseleccionar('disponibleSi')">
				        <label for="disponibleNo">No</label>
				    </div>
				</div>
				
				<p>¿Permite mascotas?</p>
				<div class="instalaciones">
				    <div class="checkbox-option">
				        <input type="radio" id="mascotasSi" name="petFriendly" value="1" ${property.petFriendly == 1 ? "checked":""} onclick="deseleccionar('mascotasNo')"> 
				        <label for="mascotasSi">Sí</label>
				    </div>
				    <div class="checkbox-option">
				        <input type="radio" id="mascotasNo" name="petFriendly" value="0" ${property.petFriendly == 0 ? "checked":""} onclick="deseleccionar('mascotasSi')">
				        <label for="mascotasNo">No</label>
				    </div>
				</div>
	
	        <table id="habitaciones">
	    <thead>
	        <tr>
	            <th class="listaHabitaciones">Nombre</th>
	            <th class="listaHabitaciones">Descripcion</th>
	            <th class="listaHabitaciones">Precio/noche</th>
	            <th class="listaHabitaciones">Habitaciones</th>
	            <th class="listaHabitaciones">EDIT</th>
	            <th class="listaHabitaciones">DELETE</th>
	        </tr>
	    </thead>
	    <tbody>
	        <c:forEach var="accommodation" items="${accommodationList}">
	        	<c:if test="${accommodation.idp == property.id}">
	            <tr>
	                <td class="listaHabitaciones">${accommodation.name}</td>
	                <td class="listaHabitaciones">${accommodation.description}</td>
	                <td class="listaHabitaciones">${accommodation.price}</td>
	                <td class="listaHabitaciones">${accommodation.numAccommodations}</td>
	                <td class="listaHabitaciones">
	                    <a href="EditarHabitacionServlet.do?id=${accommodation.id}">
                            <img src="${pageContext.request.contextPath}/img/edit.png" alt="edit ${accommodation.id}">
                        </a>
	                </td>
	                <td class="listaHabitaciones">
	                    <a href="BorrarHabitacionServlet.do?id=${accommodation.id}">
                            <img src="${pageContext.request.contextPath}/img/delete.png" alt="delete ${accommodation.id}">
                        </a>
	                </td>
	            </tr>
	            </c:if>
	        	</c:forEach>
	   		 </tbody>
			</table>
	        <a href="CrearHabitacionServlet.do?idProperty=${property.id}">
			    <button id="nuevaHabitacion" type="button">Nueva Habitacion</button>
			</a>
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
	<script>
	    function deseleccionar(id) {
	        var checkboxes = document.getElementsByName(id);
	        checkboxes.forEach(function(checkbox) {
	            checkbox.checked = false;
	        });
	    }
	</script>
</body>

</html>