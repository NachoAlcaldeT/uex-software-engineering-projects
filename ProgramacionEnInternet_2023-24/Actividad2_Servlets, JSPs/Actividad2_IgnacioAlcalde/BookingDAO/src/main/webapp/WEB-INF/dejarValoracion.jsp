<%@ page language="java" contentType="text/html; charset=ISO-8859-1" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions"%>
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <meta name="author" content="Nacho Alcalde">

    <title>Booking.com</title>

    <link rel="stylesheet" href="css/dejarValoracion.css">
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
        <div class="feedback">
            <h2>Valoración</h2>
            <div class="informacion-extra1">
                <p>Este comentario será público</p>
                <img src="img/informacion.png" alt="Información">
            </div>
            <form action="DejarValoracionServlet.do" method="post">
            <input type="hidden" name="idProperty" value="${idProperty}">
                <div class="star-rating" id="star-rating">
                    <img src="img/star_empty.png" alt="1 estrella" data-value="1">
                    <img src="img/star_empty.png" alt="2 estrellas" data-value="2">
                    <img src="img/star_empty.png" alt="3 estrellas" data-value="3">
                    <img src="img/star_empty.png" alt="4 estrellas" data-value="4">
                    <img src="img/star_empty.png" alt="5 estrellas" data-value="5">
                </div>
                <input type="hidden" id="rating" name="rating" required>
                <br><br>
                <div class="input-group">
                    <label for="descripcion">Comparte un comentario sobre tu estancia</label>
                    <textarea id="descripcion" name="comment" rows="4" cols="50" placeholder="Excelente, buen sitio..." required></textarea>
                </div>
                <div class="button-group">
                    <button class="btn" type="submit">Enviar Valoración</button>
                     <a class="btn" href="paginaInicio.do">Cancelar</a>
                </div>
                
                <!-- Código para cargar la valoración existente si existe -->
			    <c:if test="${not empty existingReview}">
			        <script>
			            document.addEventListener('DOMContentLoaded', () => {
			                const existingRating = ${existingReview.grade};
			                const existingComment = "${existingReview.review}";
			
			                // Poner el rating existente en el input hidden
			                document.getElementById('rating').value = existingRating;
			
			                // Marcar las estrellas del rating existente como llenas
			                const stars = document.querySelectorAll('#star-rating img');
			                stars.forEach((star, index) => {
			                    if (index < existingRating) {
			                        star.src = 'img/star_filled.png';
			                        star.classList.add('filled');
			                    } else {
			                        star.src = 'img/star_empty.png';
			                        star.classList.remove('filled');
			                    }
			                });
			
			                // Poner el comentario existente en el textarea
			                document.getElementById('descripcion').value = existingComment;
			            });
			        </script>
			    </c:if>
               
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

    <script>
        document.addEventListener('DOMContentLoaded', (event) => {
            const stars = document.querySelectorAll('#star-rating img');
            const ratingInput = document.getElementById('rating');

            stars.forEach(star => {
                star.addEventListener('click', () => {
                    const ratingValue = star.getAttribute('data-value');
                    ratingInput.value = ratingValue;
                    updateStars(ratingValue);
                });

                star.addEventListener('mouseover', () => {
                    const ratingValue = star.getAttribute('data-value');
                    updateStars(ratingValue);
                });

                star.addEventListener('mouseout', () => {
                    updateStars(ratingInput.value);
                });
            });

            function updateStars(ratingValue) {
                stars.forEach(star => {
                    if (star.getAttribute('data-value') <= ratingValue) {
                        star.src = 'img/star_filled.png';
                        star.classList.add('filled');
                    } else {
                        star.src = 'img/star_empty.png';
                        star.classList.remove('filled');
                    }
                });
            }
        });
    </script>
</body>

</html>