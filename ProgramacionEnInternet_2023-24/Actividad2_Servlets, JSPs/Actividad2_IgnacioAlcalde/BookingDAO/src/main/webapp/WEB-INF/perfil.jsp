<%@ page language="java" contentType="text/html; charset=ISO-8859-1" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions"%>

<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <meta name="author" content="Nacho Alcalde">
    <title>Booking.com</title>
    <link rel="stylesheet" href="css/perfilUsuario1.css">
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
    <label for="nombre" class="form-label">Nombre</label>
    <input type="text" id="name" class="form-input" value="${user.name}" readonly required>
    <label for="surname" class="form-label">Apellido</label>
    <input type="text" id="surname" class="form-input" value="${user.surname}" readonly required>
    <label for="email" class="form-label">E-mail</label>
    <input type="text" id="email" class="form-input" value="${user.email}" readonly required>
    <label for="contraseña" class="form-label">Contraseña</label>
    <input type="text" id="password" class="form-input" value="${user.password}" readonly required>
    <div class="separator-line">
        <span class="separator-text">MIS ALOJAMIENTOS</span>
    </div>

        <table id="apartamentos">
    <thead>
        <tr>
            <th class="listaApartamentos">ID Apartamentos</th>
            <th class="listaApartamentos">Nombre</th>
            <th class="listaApartamentos">Ciudad</th>
            <th class="listaApartamentos">EDIT</th>
            <th class="listaApartamentos">DELETE</th>
        </tr>
    </thead>
    <tbody>
        <c:forEach var="property" items="${propertyList}">
            <c:if test="${property.idu == user.id}">
                <tr>
                    <td class="listaApartamentos">${property.id}</td>
                    <td class="listaApartamentos">${property.name}</td>
                    <td class="listaApartamentos">${property.city}</td>
                    <td class="listaApartamentos">
                        <a href="EditarAlojamientoServlet.do?id=${property.id}">
                            <img src="${pageContext.request.contextPath}/img/edit.png" alt="edit ${property.id}">
                        </a>
                    </td>
                    <td class="listaApartamentos">
                        <a href="BorrarAlojamientoServlet.do?id=${property.id}">
                            <img src="${pageContext.request.contextPath}/img/delete.png" alt="delete ${property.id}">
                        </a>
                    </td>
                </tr>
            </c:if>
        </c:forEach>
    </tbody>
	</table>
	
	<div class="separator-line">
        <span class="separator-text">MIS FAVORITOS</span>
    </div>
    
    <table id="favoritos">
            <thead>
                <tr>
                    <th class="listaFavoritos">ID Apartamentos</th>
                    <th class="listaFavoritos">Nombre</th>
                    <th class="listaFavoritos">Ciudad</th>
                </tr>
            </thead>
            <tbody>
		        <c:if test="${not empty favoritosList}">
		            <c:forEach var="favorito" items="${favoritosList}">
		                <tr>
		                    <td>${favorito.getIdp()}</td>
		                    <!-- Aquí puedes obtener información adicional de la propiedad a través de su ID -->
		                    <c:choose>
		                        <c:when test="${empty propertyList}">
		                            <td colspan="2">No hay propiedades disponibles</td>
		                        </c:when>
		                        <c:otherwise>
		                            <c:forEach var="property" items="${propertyList}">
		                                <c:if test="${property.id eq favorito.getIdp()}">
		                                    <td>${property.name}</td>
		                                    <td>${property.city}</td>
		                                </c:if>
		                            </c:forEach>
		                        </c:otherwise>
		                    </c:choose>
		                </tr>
		            </c:forEach>
		        </c:if>
		        <c:if test="${empty favoritosList}">
		            <tr>
		                <td colspan="3">No tienes favoritos</td>
		            </tr>
		        </c:if>
		    </tbody>
        </table>

        <div id="registration-options">
        	<a href="CrearAlojamientoServlet.do"><button class="button-crear">Crear Alojamiento</button></a>
            <a href="CerrarSesionServlet.do"><button class="button-cerrar">Cerrar Sesión</button></a>
            <a href="EditarUsuarioServlet.do"> <button class="button-editar">Editar Perfil</button></a>
            <a href="BorrarUsuarioServlet.do?id=${user.id}"><button class="button-eliminar">Eliminar Perfil</button></a>
        </div>
        
         <div id="misReservas-options">
             <a href="ReservasUsuarioServlet.do?"><button class="button-reservas">Mis reservas</button></a>
        </div>

        <p class="disclaimer-text">Al iniciar sesión o al crear una cuenta, aceptas nuestros <span class="link-text">Términos y condiciones</span> y la <span class="link-text">Política de Privacidad</span>.</p>
        <div class="separator"></div>
        <p class="copyright-text">Todos los derechos reservados.</p>
        <p class="copyright-text">Copyright (2006-2024) - Booking.com</p>
    </div>
</body>

</html>