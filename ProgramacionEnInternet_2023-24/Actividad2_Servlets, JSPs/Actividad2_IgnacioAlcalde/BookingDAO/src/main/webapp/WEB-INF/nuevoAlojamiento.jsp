<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <meta name="author" content="Nacho Alcalde">

    <title>Booking.com</title>

   <link rel="stylesheet" href="css/nuevoAlojamiento.css">
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
	    <form action="CrearAlojamientoServlet.do" method="post">
	        <div class="input-group">
	            <label for="nombreAlojamiento">Nombre del alojamiento</label>
	            <input type="text" id="nombreAlojamiento" name="name" placeholder="Escribe el nombre" required>
	        </div>
			
			<div class="input-group">
	            <label for="direccion">City</label>
	            <input type="text" id="city" name="city" placeholder="Cuidad" required>
	        </div>
	        
	        <div class="input-group">
	            <label for="direccion">Direcci�n</label>
	            <input type="text" id="direccion" name="address" placeholder="Escribe la direcci�n" required>
	        </div>
	
	        <div class="input-group">
	            <label for="telefono">Tel�fono</label>
	            <input type="tel" id="telefono" name="telephone" placeholder="Escribe el tel�fono" required>
	        </div>
	
	        <div class="input-group">
	            <label for="distanciaCentro">Distancia al centro (en km)</label>
	            <input type="text" id="distanciaCentro" name="centerDistance" placeholder="Escribe la distancia" pattern="[0-9]+" title="Debe ser un valor num�rico" required>
	        </div>
	
	        <div class="input-group">
	            <label for="valoracion">Valoraci�n media</label>
	            <input type="text" id="valoracion" name="gradesAverage" placeholder="Escribe la valoraci�n" pattern="[0-9]+" title="Debe ser un valor num�rico" required>
	        </div>
	
	        <div class="input-group">
	            <label for="descripcion">Descripci�n</label>
	            <textarea id="descripcion" name="description" placeholder="Escribe la descripci�n" required></textarea>
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
				        <label for="disponibleSi">S�</label>
				    </div>
				    <div class="checkbox-option">
				        <input type="radio" id="disponibleNo" name="available" value="0" ${property.available == 0 ? "checked":""} onclick="deseleccionar('disponibleSi')">
				        <label for="disponibleNo">No</label>
				    </div>
				</div>
				
				<p>�Permite mascotas?</p>
				<div class="instalaciones">
				    <div class="checkbox-option">
				        <input type="radio" id="mascotasSi" name="petFriendly" value="1" ${property.petFriendly == 1 ? "checked":""} onclick="deseleccionar('mascotasNo')"> 
				        <label for="mascotasSi">S�</label>
				    </div>
				    <div class="checkbox-option">
				        <input type="radio" id="mascotasNo" name="petFriendly" value="0" ${property.petFriendly == 0 ? "checked":""} onclick="deseleccionar('mascotasSi')">
				        <label for="mascotasNo">No</label>
				    </div>
				</div>
	
	        <button type="submit">Crear Nuevo Alojamiento</button>
	    </form>
	</div>

    <div class="footer">
        <a href="#">Sobre Booking.com</a>
        <a href="#">Atenci�n al cliente</a>
        <a href="#">T�rminos y condiciones</a>
        <a href="#">Pol�tica de privacidad y cookies</a>
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