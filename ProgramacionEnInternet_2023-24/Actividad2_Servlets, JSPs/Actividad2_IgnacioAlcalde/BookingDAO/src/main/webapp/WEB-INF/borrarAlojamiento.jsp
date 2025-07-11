<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <meta name="author" content="Nacho Alcalde">

    <title>Booking.com</title>

    <link rel="stylesheet" href="css/borrados.css">
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
	        <h2>�Est�s seguro de que deseas borrar tu alojamiento?</h2>
	        <p>Esta acci�n es irreversible y todos los datos asociados con tu alojamiento ser�n eliminados.</p>
	        <form action="BorrarAlojamientoServlet.do" method="post" style="display: inline;">
	            <button class="btn" type="submit">Borrar Alojamiento</button>
	        </form>
	        <form action="PerfilServlet.do" method="post" style="display: inline;">
	            <button class="btn" type="submit">Cancelar</button>
	        </form>
	    </div>
	</div>

    <div class="footer">
        <a href="#">Sobre Booking.com</a>
        <a href="#">Atenci�n al cliente</a>
        <a href="#">T�rminos y condiciones</a>
        <a href="#">Pol�tica de privacidad y cookies</a>
        <a href="#">Gestiona las recomendaciones personalizadas</a>
    </div>

</body>

</html>