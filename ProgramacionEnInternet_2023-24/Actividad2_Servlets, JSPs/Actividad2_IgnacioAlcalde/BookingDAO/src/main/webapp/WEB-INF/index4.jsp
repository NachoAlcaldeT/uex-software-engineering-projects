<%@ page language="java" contentType="text/html; charset=ISO-8859-1" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions"%>
<!DOCTYPE html>
<html lang="es">

<head>
    <meta charset="utf-8">
    <meta name="author" content="Nacho Alcalde">

    <title>Booking.com</title>

    <link rel="stylesheet" href="css/style44.css">
    <link rel="icon" href="img/icono.svg">
</head>

<body>
    <header>
        <div id="bannerAzul">
            <div class="cabecera">
                <h3>Booking.com</h3>

                <p id="EUR">EUR</p>

                <div id="icono1" class="iconosInicioSesion"><img src="img/bandera.png" width="30" alt="Selección de idioma"></div>
                <div id="icono2" class="iconosInicioSesion"><img src="img/ayudaWhite.png" width="30" alt="Ayuda"></div>

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
                <button class="boton" onclick="activarBoton(this)"><img class="iconoBotones" src="img/alojamientoWhite.png" alt="Alojamientos">Alojamiento</button>
                <button class="boton" onclick="activarBoton(this)"><img class="iconoBotones" src="img/vueloWhite.png" alt="Vuelos">Vuelos</button>
                <button class="boton" onclick="activarBoton(this)"><img class="iconoBotones" src="img/hotelWhite.png" alt="vueloHotel">Vuelo + Hotel</button>
                <button class="boton" onclick="activarBoton(this)"><img class="iconoBotones" src="img/cocheWhite.png" alt="coche">Alquiler de coches</button>
                <button class="boton" onclick="activarBoton(this)"><img class="iconoBotones" src="img/noriaWhite.png" alt="atraccionTuristica">Atracciones turísticas</button>
                <button class="boton" onclick="activarBoton(this)"><img class="iconoBotones" src="img/taxiWhite.png" alt="taxi">Taxis aeropuerto</button>
            </div>
        </div>
    </header>

    <div class="container">
        <p id="rutaNavegacion"> España > Extremadura > Caceres > Resultados de la búsqueda</p>

        <div class="sections">
            <div class="left-section">
                <div class="top-div"><img src="img/etiqueta.png" alt="Etiqueta"> Igualamos el precio</div>

                <div class="medium-div">
                    <p id="tituloMedium">Buscar</p>

                    <p class="especificacionesBuscar">Destino/Nombre del alojamiento:</p>
                    <div class="filtrosBuscar"><img src="img/lupa.png" alt="Ícono de búsqueda"> Cáceres</div>
                    <p class="especificacionesBuscar">Fecha de entrada</p>

                    <div class="filtrosBuscar"><img src="img/calendario.png" alt="Ícono de calendario">Lunes, 4 de marzo de 2024</div>
                    <p class="especificacionesBuscar">Fecha de salida</p>
                    <div class="filtrosBuscar"><img src="img/calendario.png" alt="Ícono de calendario">Martes, 5 de marzo de 20...</div>
                    <p class="especificacionesBuscar">Estancia de 1 noche</p>
                    <div class="filtrosBuscar">2 adultos-0 niños-1 habitaci...</div>

                    <div class="checkbox-filtros">
                        <input type="checkbox" name="checkbox1" value="casas">
                        <p>Casas y apartamentos enteros</p>
                        <img src="img/ayuda.png" alt="Ícono de ayuda">
                    </div>

                    <div class="checkbox-filtros">
                        <input type="checkbox" name="checkbox2" value="trabajo">
                        <p>Viajo por trabajo</p>
                        <img id="interrogacion" src="img/ayuda.png" alt="Ícono de ayuda">
                    </div>

                    <button id="search-button">Buscar</button>

                </div>
                <div class="bottom-div">
                    <button id="ver-mapa-button">Ver en el mapa</button>
                    <img src="img/mapa.jpg" alt="Mapa del lugar">
                </div>
            </div>
            <div class="right-section">
                <div class="vistaGeneral">
                    <p>Vista General</p>
                    <p>Info y precios</p>
                    <p>Servicios</p>
                    <p>Leeme</p>
                    <p>A tener en cuenta</p>
                    <p>Comentarios de clientes (4.637)</p>
                </div>
                <div class="separador-linea"></div>
                <div class="estrellas">
                    <img id="valoracionEstellas" src="img/hojasEstrellas.JPG" alt="Valoración en estrellas">
                    <img id="corazon" src="img/corazon.JPG" alt="Corazón">
                    <button id="reservarAhora">Reserva ahora</button>
                </div>
                <div class="tituloAlojamiento">
                    <p id="nombreAlojamiento">${property.name}</p>
                    <div class="etiqueta"><img src="img/etiqueta.png" alt="Etiqueta"> Igualamos el precio</div>
                </div>
                <img id="ubicacionSimbolo" src="img/ubicacion.png" alt="Ícono de ubicación">
                <p id="ubicacion">Plaza de San Juan, 11, 10003 Cáceres, España - Ubicacion Excelente - Ver mapa</p>

                <div class="imagenes">
                    <div id="imagen1"><img class="imagenAlojamiento" src="img/1a.jpg" alt="Imagen del alojamiento"></div>
                    <div id="imagen2"><img class="imagenAlojamiento" src="img/2a.jpg" alt="Imagen del alojamiento"></div>
                    <div id="imagen3"><img class="imagenAlojamiento" src="img/3a.jpg" alt="Imagen del alojamiento"></div>
                    <div id="imagen4"><img class="imagenAlojamiento" src="img/4a.jpg" alt="Imagen del alojamiento"></div>
                    <div id="imagen5"><img class="imagenAlojamiento" src="img/5a.jpg" alt="Imagen del alojamiento"></div>
                    <div id="imagen6"><img class="imagenAlojamiento" src="img/6a.JPG" alt="Imagen del alojamiento"></div>
                    <div id="imagen7">
                        <img class="imagenAlojamiento" src="img/7a.JPG" alt="Imagen del alojamiento">
                    </div>
                </div>
            </div>
        </div>
        <div class="requisitosCliente">
            <div class="requisito"><img src="img/desayuno.png" alt="Desayuno"> Muy buen desayuno</div>
            <div class="requisito"><img src="img/restaurante.png" alt="Restaurante">Restaurante</div>
            <div class="requisito"><img src="img/mascotas.png" alt="Admite mascotas">Admite mascotas</div>
            <div class="requisito"><img src="img/bañoPrivado.png" alt="Baño privado">Baño privado</div>
            <div class="requisito"><img src="img/balcon.png" alt="Balcón">Balcon</div>
        </div>
        <div class="requisitosCliente2">
            <div class="requisito"><img src="img/bañera.png" alt="Bañera"> Bañera</div>
            <div class="requisito"><img src="img/wifi.png" alt="WiFi gratis">WiFi gratis</div>
            <div class="requisito"><img src="img/aireAcondicionado.png" alt="Aire Acondicionado">Aire Acondicionado</div>
            <div class="requisito"><img src="img/vistas.png" alt="Vistas">Vistas</div>
            <div class="requisito"><img src="img/gimnasio.png" alt="Gimnasio">Gimnasio</div>
        </div>
        <div class="descripcionAlojamiento">
            ¡Puedes conseguir un descuento Genius en NH Collection Cáceres Palacio de Oquendo! Para ahorrar en este alojamiento, solo tienes que iniciar sesión.<br><br> Este precioso palacio reconvertido del siglo XVI se encuentra en el centro histórico
            de Cáceres, junto a las antiguas murallas romanas y árabes de la ciudad. El alojamiento ofrece habitaciones elegantes con aire acondicionado, WiFi gratuita y acceso gratuito a la sala de fitness.<br><br> Las habitaciones del NH Collection
            Cáceres Palacio de Oquendo son amplias, presentan una decoración moderna y disponen de TV de 48 pulgadas, cafetera, hervidor eléctrico con infusiones gratuitas y carta de almohadas. También incluyen baño con ducha de efecto lluvia y secador
            de pelo profesional.<br><br> El restaurante del hotel alberga una terraza en la plaza de San Juan y sirve tapas locales tradicionales y especialidades clásicas españolas, así como cocina internacional. El bar ocupa las antiguas caballerizas
            y ofrece vistas a la plaza.<br><br> El alojamiento está situado a solo 100 metros del centro histórico de Cáceres, declarado Patrimonio de la Humanidad por la UNESCO, y de la iglesia de San Juan. El establecimiento se halla a 10 minutos a
            pie de la plaza de toros.<br><br> A las parejas les encanta la ubicación — Le han puesto un <strong>9,6</strong> para viajes de dos personas.

            <p>Las distancias en la descripción del alojamiento se calculan con OpenStreetMap©</p>
        </div>
        <div class="marcaAlojamiento">
            <div class="marcaHotel">
                <div id="cadenaHotel">
                    <p>Marca/cadena de hotel</p>
                    <p>NH Collection</p>
                </div>
                <div id="logoHotel">
                    <img src="img/logoHotel.jpg" alt="Logo del Hotel NH Collection">
                </div>
            </div>
            <div id="puntosFuertes">
                <h3>Puntos fuertes del alojamiento</h3>
                <p>¡Ideal para estancias de 1 noche!</p>
                <div class="situado"><img src="img/puntero.png" alt="Icono de puntero"> Situado en la zona mejor valorada de Caceres, este hotel tiene una excelente puntuación en ubicación (9,6).</div>
                <div class="situado"><img src="img/alojamiento.png" alt="Icono de alojamiento">¿Quieres dormir a pierna suelta? Este hotel tiene una puntuación muy alta por la comodidad de sus camas.</div>
                <p>Informacion sobre el desayuno</p>
                Continental, Vegetariano, Vegano, Sin gluten, Americano, Buffet
                <button id="reservarAhora2">Reserva ahora</button>
            </div>
        </div>
        <div class="serviciosPopulares">
            <p>Servicios más populares</p>
            <div class="requisitosPopulares">
                <div class="populares"><img src="img/sinHumo.png" alt="Icono de habitaciones sin humo">Habitaciones sin humo</div>
                <div class="populares"><img src="img/gimnasio.png" alt="Icono de gimnasio">Gimnasio</div>
                <div class="populares"><img src="img/servicio.png" alt="Icono de servicio de habitaciones">Servicio de habitaciones</div>
            </div>
            <div class="requisitosPopulares">
                <div class="populares"><img src="img/restaurante.png" alt="Icono de restaurante">Restaurante</div>
                <div class="populares"><img src="img/parking.png" alt="Icono de parking">Parking</div>
                <div class="populares"><img src="img/wifi.png" alt="Icono de WiFi">WiFi</div>
                <div class="populares"><img src="img/familiar.png" alt="Icono de habitaciones familiares">Habitaciones familiares</div>
            </div>
            <div class="requisitosPopulares">
                <div class="populares"><img src="img/recepcion.png" alt="Icono de recepción 24 horas">Recepción 24 horas</div>
                <div class="populares"><img src="img/bar.png" alt="Icono de bar">Bar</div>
                <div class="populares"><img src="img/desayuno.png" alt="Icono de muy buen desayuno">Muy buen desayuno</div>
            </div>
        </div>
        <div class="separador-linea"></div>
        <div class="ahorro">
            <div class="ofertas1">
                <div class="textoOferta">
                    <h2>Inicia sesión y ahorra</h2>
                    <p>Podrías ahorrar un 10% o más en este alojamiento al iniciar sesión</p>
                    <div class="botonesVarios">
                        <button id="iniciaSesion">Inicia sesión</button>
                        <p id="hazteCuenta">Hazte una cuenta</p>
                    </div>
                </div>
                <div class="imagenOferta">
                    <img src="img/regalo.jpeg" alt="Regalo de bienvenida al iniciar sesión">
                </div>
            </div>
            <div class="ofertas2">
                <div class="textoOferta">
                    <p id="decisionesSostenibles">Te ayudamos a tomar decisiones mas sostenibles</p>
                    <h2>Travel Sustainable Nivel 3+</h2>
                    <p>Al elegir este alojamiento, tu estancia será más sostenible.</p>
                    <div class="botonesVarios">
                        <button id="masInfo">Más info</button>
                    </div>
                </div>
                <div class="imagenOferta">
                    <img src="img/sustainable.jpeg" alt="Certificación Travel Sustainable Nivel 3+">
                </div>
            </div>
        </div>
        <div class="disponibilidad">
            <h2>Disponibilidad</h2>
            <div class="nav-rectangle">
                <div class="filter-option"><img src="img/calendario.png" alt="Calendario">vie, 26 ene - dom, 28 ene</div>
                <div class="filter-option"><img src="img/usuario.png" alt="Icono de usuario">2 adultos - 0 niños - 1 habitación</div>
                <button id="search-button">Modificar búsqueda</button>
            </div>
            <table>
                <thead>
                    <tr>
                        <th>Tipo de habitación</th>
                        <th>Descripcion</th>
                        <th>Precio</th>
                        <th>Tus opciones</th>
                        <th>Numero de habitaciones</th>
                        <th></th>
                    </tr>
                </thead>
                <tbody>
			        <c:choose>
			            <c:when test="${empty accommodationsList}">
			                <tr>
			                    <td colspan="6">Aún no hay alojamientos disponibles para esta propiedad.</td>
			                </tr>
			            </c:when>
			            <c:otherwise>
			                <c:forEach var="accommodation" items="${accommodationsList}">
							    <c:if test="${property.id eq accommodation.getIdp()}">
							        <tr>
							            <td>${accommodation.getName()}</td>
							            <td>${accommodation.getDescription()}</td>
							            <td>$${accommodation.getPrice()}</td>
							            <td>
							                <p>Desayuno muy bueno por € 20</p>
							                <p class="listado">· No reembolsable</p>
							                <p class="listado">· Pagas por adelantado</p>
							            </td>
							            <td>
							                <input type="number" id="habitaciones_${accommodation.getId()}" name="habitaciones_${accommodation.getId()}" min="1" max="${accommodation.getNumAccommodations()}" value="1">
							            </td>
							            <td>
							                <form action="ReservaServlet.do" method="get">
							                    <input type="hidden" name="id" value="${accommodation.getId()}">
							                    <input type="hidden" name="price" value="${accommodation.getPrice()}">
							                    <input type="hidden" id="habitaciones_hidden_${accommodation.getId()}" name="habitaciones" value="1">
							                    <c:choose>
											        <c:when test="${not empty user.id}">
											            <button type="submit" class="reservar-button">Reservar</button>
											        </c:when>
											        <c:otherwise>
											            <a href="LoginServlet.do"><button type="button" class="reservar-button">Iniciar Sesión</button></a>
											        </c:otherwise>
											    </c:choose>
							                </form>
							            </td>
							        </tr>
							    </c:if>
							</c:forEach>
			            </c:otherwise>
			        </c:choose>
			    </tbody>
            </table>
        </div>
        <div class="comentariosClientes">
		    <h2>Valoraciones</h2>
		    <c:if test="${hasReviews}">
		        <c:forEach var="review" items="${reviews}">
		            <div class="comentario">
		                <div class="valoracion">
		                    <h3><span>${review.review}</span> <span class="valoracion-numero">${review.grade}</span></h3>
		                    <div class="estrellas">
		                        <c:forEach var="i" begin="1" end="${review.grade}">
		                            <img src="img/star_filled.png" alt="Estrella llena">
		                        </c:forEach>
		                    </div>
		                </div>
		                <p class="comentario-texto">Buen sitio, buena ubicación y habitaciones cómodas. El desayuno también es muy bueno. Definitivamente lo recomendaría.</p>
		                <c:forEach var="userNombre" items="${userList}">
		                	<c:if test="${userNombre.id == review.idu}">
		                		<p>Usuario: ${userNombre.name}</p>
		                	</c:if>
		                </c:forEach>
		            </div>
		        </c:forEach>
		    </c:if>
		    <c:if test="${not hasReviews}">
		        <p>Aún no hay comentarios sobre este alojamiento.</p>
		    </c:if>
		</div>
		
		<c:choose>
		    <c:when test="${not empty user.id}">
		        <!-- Usuario registrado: mostrar botón para valorar -->
		        <div class="dejarValoracion">
		            <a href="DejarValoracionServlet.do?idProperty=${property.id}">
		                <button id="valoracion-button" type="button">¡Valora tu experiencia!</button>
		            </a>
		        </div>
		    </c:when>
		    <c:otherwise>
		        <!-- Usuario no registrado: mostrar botón para registrarse -->
		        <div class="registroDejarValoracion">
		            <a href="LoginServlet.do">
		                <button id="registroValoracion-button">¡Inicia Sesión y deja una valoración!</button>
		            </a>
		        </div>
		    </c:otherwise>
		</c:choose>

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
        <button class="registroSesion-button">Registra tu alojamiento</button>
    </div>

    <script>
        function activarBoton(boton) {

            // Desactivar todos los botones
            let botones = document.querySelectorAll('.boton');
            botones.forEach(b => b.classList.remove('activado'));

            // Activar el botón clicado
            boton.classList.add('activado');
        }
        document.getElementById('masInfo').addEventListener('click', function() {
            // Redirige a la página index5.html
            window.location.href = 'index5.html';
        });
    </script>
    <script>
	    document.querySelectorAll('input[type=number]').forEach(input => {
	        input.addEventListener('input', function() {
	            const hiddenInput = document.getElementById('habitaciones_hidden_' + this.id.split('_')[1]);
	            hiddenInput.value = this.value;
	        });
	    });
	</script>


</body>

</html>