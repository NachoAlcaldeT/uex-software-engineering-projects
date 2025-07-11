<%@ page language="java" contentType="text/html; charset=ISO-8859-1" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions"%>
<!DOCTYPE html>
<html lang="es">

<head>
    <meta charset="utf-8">
    <meta name="author" content="Nacho Alcalde">

    <title>Booking.com</title>
	<link rel="stylesheet" href="css/style33.css">
    <link rel="icon" href="img/icono.svg">
    
    <style>
        /* Estilo para el cursor cuando se coloca sobre la imagen del favorito */
        .favoritos {
            cursor: pointer;
        }
    </style>
    
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

            <div class="botones-container">
                <button class="boton" onclick="activarBoton(this)"><img class="iconoBotones" src="img/alojamientoWhite.png" alt="Alojamiento">Alojamiento</button>
                <button class="boton" onclick="activarBoton(this)"><img class="iconoBotones" src="img/vueloWhite.png" alt="Vuelos">Vuelos</button>
                <button class="boton" onclick="activarBoton(this)"><img class="iconoBotones" src="img/hotelWhite.png" alt="Vuelo + Hotel">Vuelo + Hotel</button>
                <button class="boton" onclick="activarBoton(this)"><img class="iconoBotones" src="img/cocheWhite.png" alt="Alquiler de coches">Alquiler de coches</button>
                <button class="boton" onclick="activarBoton(this)"><img class="iconoBotones" src="img/noriaWhite.png" alt="Atracciones turísticas">Atracciones turísticas</button>
                <button class="boton" onclick="activarBoton(this)"><img class="iconoBotones" src="img/taxiWhite.png" alt="Taxis aeropuerto">Taxis aeropuerto</button>
            </div>
        </div>
    </header>

    <div class="container">
        <form action="AlojamientoServlet.do" method="GET">
        
            <nav>
                <div class="nav-rectangle">
                    <div class="filter-option">
                        <img src="img/coche.png" alt="¿A dónde vas?">
                        <input type="text" name="destino" placeholder="¿A dónde vas?" style="width: 150px;"value="${param.destino != null ? param.destino : ''}">
                    </div>
                    <div class="filter-option">
                        <img src="img/calendario.png" alt="Fecha de entrada - Fecha de salida">
                        <input type="date" name="fecha_entrada">
                        <input type="date" name="fecha_salida">
                    </div>
                    <div class="filter-option">
                        <img src="img/usuario.png" alt="2 adultos - 0 niños - 1 habitación">
                        <input type="number" name="adultos" placeholder="Adultos" style="width: 60px;">
                        <input type="number" name="niños" placeholder="Niños" style="width: 80px;">
                        <input type="number" name="habitaciones" placeholder="Habitaciones" style="width: 100px;">
                    </div>
                    <button type="submit" id="search-button">Buscar</button>
                </div>
            </nav>
        </form>



        <p>Inicio > España > Extremadura > Caceres > Resultados de la búsqueda</p>

        <div class="sections">
            <div class="left-section">

                <div class="top-div">
                    <button class="ver-mapa-button">Ver en el mapa</button>
                    <img src="img/mapa.jpg" alt="Mapa">
                </div>

                <div class="bottom-div">
                    <p class="filtros">Filtrar por:</p>
                    <div class="separador-linea"></div>
                    <p class="tu-presupuesto">Tu presupuesto (por noche)</p>
                    <p id="cantidad-dinero">500</p>
                    <input type="range" id="presupuesto" min="0" max="1000" step="10" value="500">
                    <div class="separador-linea"></div>

                    <div class="filtros-populares">
                        <p>Filtros populares:</p>

                        <div class="checkbox-filtros">
                            <input type="checkbox" name="checkbox1" value="hoteles">
                            <p>Hoteles</p>
                        </div>

                        <div class="checkbox-filtros">
                            <input type="checkbox" name="checkbox2" value="hoteles">
                            <p>Desayuno incluido</p>
                        </div>

                        <div class="checkbox-filtros">
                            <input type="checkbox" name="checkbox3" value="hoteles">
                            <p>4 estrellas</p>
                        </div>

                        <div class="checkbox-filtros">
                            <input type="checkbox" name="checkbox3" value="hoteles">
                            <p>Fantastico: 9 o más</p>
                        </div>

                        <p id="fantastico">Según los comentarios de los clientes</p>

                        <div class="checkbox-filtros">
                            <input type="checkbox" name="checkbox3" value="hoteles">
                            <p>Hostales y pensiones</p>
                        </div>

                        <div class="checkbox-filtros">
                            <input type="checkbox" name="checkbox3" value="hoteles">
                            <p>Cancelación gratis</p>
                        </div>

                        <div class="checkbox-filtros">
                            <input type="checkbox" name="checkbox3" value="hoteles">
                            <p>Parking</p>
                        </div>

                        <div class="checkbox-filtros">
                            <input type="checkbox" name="checkbox3" value="hoteles">
                            <p>Villas</p>
                        </div>
                    </div>


                    <!--<div class="separador-linea"></div>-->

                </div>
            </div>
            <div class="right-section">
                <p><c:if test="${not empty param.destino}">${param.destino}:</c:if> ${propertyList.size()} alojamientos encontrados</p>

                <form action="AlojamientoServlet.do" method="GET">
			    <input type="hidden" name="destino" value="${param.destino}">
			    <label for="filtro">Filtrar por disponibilidad:</label>
			    <select name="filtro" id="filtro">
			        <option value="todos" ${param.filtro == 'todos' ? 'selected' : ''}>Todos</option>
			        <option value="disponible" ${param.filtro == 'disponible' ? 'selected' : ''}>Disponible</option>
			        <option value="no_disponible" ${param.filtro == 'no_disponible' ? 'selected' : ''}>No disponible</option>
			        <option value="valoracion" ${param.filtro == 'valoracion' ? 'selected' : ''}>Por valoración</option>
			    </select>
			    <button id="filtroDisponibilidad" type="submit">Filtrar</button>
			</form>
                
                <div class="informacion-extra1">
                    <img src="img/informacion.png" alt="Información">
                    <p>Un 79% de los alojamientos ya no estan disponibles en nuestra web para esas fechas.</p>
                    <img src="img/cruz.png" alt="Cruz">
                </div>
                <div class="informacion-extra2">
                    <p>La comisión que pagan por alojamientos por las reservas y otros factores pueden influir en su puesto en el ranking. Descubre mas sobre los parametros del ranking y como seleccionarlos y modificarlos. <span class="mas-informacion-link">Más información</span></p>
                    <img src="img/cruz.png" alt="Cruz">
                </div>
                
                <c:forEach var="property" items="${propertyList}">
                <div class="alojamiento1">
                    <div class="alojamiento1-img">
                    	<img src="img/NH.JPG" alt="NH">
			                <c:choose>
			                	<c:when test="${not empty user.id}">
				                	<div class="favoritos" onclick="toggleFavorite(this, ${property.id})">
						                <c:choose>
						                    <c:when test="${property.favorite}">
						                        <img id="favorito${property.id}" src="img/favoritoRojo.png" alt="favoritoRojo">
						                    </c:when>
						                    <c:otherwise>
						                        <img id="favorito${property.id}" src="img/favoritoBlanco.png" alt="favoritoBlanco">
						                    </c:otherwise>
						                </c:choose>
						            </div>
		                        </c:when>
		                    </c:choose>
                    </div>
                    <div class="alojamiento1-infoIzq">
                        <p id="tituloAlojamiento">${property.name}<img src="img/estrellitas.JPG" alt="estrellitas"></p>
                        <p id="alojamientoLocalizacion">
                            <span class="mas-informacion-link">${property.city}</span>
                            <span class="mas-informacion-link">Mostrar en el mapa</span> a ${property.centerDistance} m del centro
                        </p>
                        <img id="hojas" src="img/hojas.JPG" alt="Hojas">
                        <p id="habitacion-info">Habitación Doble Superior -1 o 2 camas</p>
                        <p id="cama-info">Camas: 1 doble o 2 individuales</p>
                       	<p id="aviso-info">
					        Habitaciones disponibles: 
					        <c:choose>
					            <c:when test="${property.available == 1}">
					                sí
					            </c:when>
					            <c:otherwise>
					                no
					            </c:otherwise>
					        </c:choose>
					    </p>
                    </div>
                    <div class="alojamiento1-infoDer">
                        <div class="valoracion">
                            <p>Fabuloso</p>
                            <div class="valoracion-numerica">${property.gradesAverage}</div>
                        </div>
                        <p id="comentarios">4.559 comentarios</p>
                        <p id="ubicacion">Ubicacion 9,6</p>
                        <p id="noches">2 noches, 2 adultos</p>
                        <p id="precio">€ 285</p>
                        <p id="impuestos">Incluye impuestos y cargos</p>

                        <form action="VerAlojamientoServlet.do" method="GET">
			                <input type="hidden" name="id" value="${property.id}">
			                <button type="submit" id="verDisponibilidadBtn" class="verDisponibilidad">Ver disponibilidad   ></button>
			            </form>
                    </div>
                </div>
                </c:forEach>
        </div>
    </div>
</div>
    <div class="footer">
        <div class="footer-text">
            <p id="ahorraTiempo">¡Ahorra tiempo y dinero!</p>
            <p>Regístrate y te enviamos las mejores ofertas para ti.</p>
        </div>

        <form>
            <input type="email" class="email-input" placeholder="Tu dirección de e-mail">
            <button type="submit" class="subscribe-button">¡Suscríbete!</button>
        </form>
    </div>
    <div class="registroSesion">
        	<a href="PerfilServlet.do"><button class="registroSesion-button">Registra tu alojamiento</button></a>
    </div>
    
    
    <script>
		function toggleFavorite(element, propertyId) {
		    var favorito = element.querySelector('img'); // Buscar la imagen dentro del contenedor
		    
		    // Cambiar el src de la imagen de favorito
		    if (favorito.src.includes('favoritoBlanco.png')) {
		        favorito.src = 'img/favoritoRojo.png';
		        addFavorite(propertyId);
		    } else {
		        favorito.src = 'img/favoritoBlanco.png';
		        removeFavorite(propertyId);
		    }
		}
		
		function addFavorite(propertyId) {
		    fetch('FavoritosServlet.do?idProperty=' + propertyId, {
		        method: 'GET'
		    }).then(response => {
		        if (!response.ok) {
		            throw new Error('Error al agregar favorito');
		        }
		    }).catch(error => {
		        console.error('Error:', error);
		    });
		}
		
		function removeFavorite(propertyId) {
		    fetch('FavoritosServlet.do?idProperty=' + propertyId, {
		        method: 'GET'
		    }).then(response => {
		        if (!response.ok) {
		            throw new Error('Error al eliminar favorito');
		        }
		    }).catch(error => {
		        console.error('Error:', error);
		    });
		}
		</script>
    
</html>