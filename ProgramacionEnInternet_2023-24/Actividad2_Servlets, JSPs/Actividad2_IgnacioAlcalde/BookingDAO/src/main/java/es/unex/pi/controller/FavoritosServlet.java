package es.unex.pi.controller;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

import java.io.IOException;
import java.sql.Connection;
import java.util.List;
import java.util.logging.Logger;

import es.unex.pi.dao.FavoritosDAO;
import es.unex.pi.dao.JDBCFavoritosDAOImpl;
import es.unex.pi.dao.JDBCPropertyDAOImpl;
import es.unex.pi.dao.PropertyDAO;
import es.unex.pi.model.Favoritos;
import es.unex.pi.model.Property;
import es.unex.pi.model.User;

/**
 * Servlet implementation class FavoritosServlet
 */

@WebServlet("/FavoritosServlet.do")
public class FavoritosServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private static final Logger logger = Logger.getLogger(HttpServlet.class.getName());
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public FavoritosServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		Connection conn = (Connection) getServletContext().getAttribute("dbConn");
		HttpSession session = request.getSession(false);
		User user = (User) session.getAttribute("user");

			
			  if (user != null) {
			       FavoritosDAO favoritosDao = new JDBCFavoritosDAOImpl();
			       favoritosDao.setConnection(conn);
			       PropertyDAO propertyDao = new JDBCPropertyDAOImpl();
			       propertyDao.setConnection(conn);

			       long idProperty = Long.parseLong(request.getParameter("idProperty"));

			       // Verificar si ya es favorito
			       boolean isFavorite = favoritosDao.isFavorite(user.getId(), idProperty);

			       if (isFavorite) {
			           // Si ya es favorito, eliminarlo
			           favoritosDao.delete(user.getId(), idProperty);
			           logger.info("Property ID " + idProperty + " removed from favorites for user " + user.getId());
			       } else {
			           // Si no es favorito, agregarlo
			           Favoritos favoritos = new Favoritos();
			           favoritos.setIdp(idProperty);
			           favoritos.setIdu(user.getId());
			           favoritos.setFavorite(true); // Set isFavorite to 1

			           long favoritosID = favoritosDao.add(favoritos);
			           favoritos.setId(favoritosID);
			           logger.info("Property ID " + idProperty + " added to favorites for user " + user.getId());
			       }

			       List<Property> propertyList = propertyDao.getAll();
			        
			       // Obtener lista de IDs de propiedades favoritas del usuario
			       List<Long> favoriteIds = favoritosDao.getFavoritePropertyIds(user.getId());
			        
			        
			       request.setAttribute("propertyList", propertyList);
			       request.setAttribute("favoriteIds", favoriteIds);
			       request.getRequestDispatcher("/WEB-INF/index3.jsp").forward(request, response);
			   } else {
			       // Manejar caso en el que el usuario no está autenticado o la sesión ha expirado
			       response.sendRedirect("login.jsp"); // Redirigir al usuario a la página de inicio de sesión
			    }
			}


	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
