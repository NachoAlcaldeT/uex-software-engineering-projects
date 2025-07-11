package es.unex.pi.controller;

import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.Connection;
import java.util.List;
import java.util.logging.Logger;

import es.unex.pi.dao.AccommodationDAO;
import es.unex.pi.dao.JDBCAccommodationDAOImpl;
import es.unex.pi.dao.JDBCPropertyDAOImpl;
import es.unex.pi.dao.JDBCReviewDAOImpl;
import es.unex.pi.dao.JDBCUserDAOImpl;
import es.unex.pi.dao.PropertyDAO;
import es.unex.pi.dao.ReviewDAO;
import es.unex.pi.dao.UserDAO;
import es.unex.pi.model.Accommodation;
import es.unex.pi.model.Property;
import es.unex.pi.model.Review;
import es.unex.pi.model.User;

/**
 * Servlet implementation class VerAlojamientoServlet
 */
@WebServlet("/VerAlojamientoServlet.do")
public class VerAlojamientoServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private static final Logger logger = Logger.getLogger(HttpServlet.class.getName());
    /**
     * @see HttpServlet#HttpServlet()
     */
    public VerAlojamientoServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
    	Connection conn = (Connection) getServletContext().getAttribute("dbConn");
        PropertyDAO propertyDao = new JDBCPropertyDAOImpl();
        ReviewDAO reviewDao = new JDBCReviewDAOImpl();
        UserDAO userDao = new JDBCUserDAOImpl();
        AccommodationDAO accommodationDao = new JDBCAccommodationDAOImpl();
        propertyDao.setConnection(conn);
        reviewDao.setConnection(conn);
        userDao.setConnection(conn);
        accommodationDao.setConnection(conn);

        try {
            // Obtener el ID del alojamiento desde la solicitud
            String idParam = request.getParameter("id");
            logger.info("ID del alojamiento recibido: " + idParam);
            
            if (idParam == null || idParam.isEmpty()) {
                throw new IllegalArgumentException("ID del alojamiento no proporcionado");
            }
            
            long propertyId = Long.parseLong(request.getParameter("id"));
            // Obtener el objeto Property correspondiente al ID
            Property property = propertyDao.get(propertyId);
            

            // Obtener todas las revisiones asociadas a esta propiedad
            List<Review> reviews = reviewDao.getAllByProperty(propertyId);
            
            List<Accommodation> accommodations = accommodationDao.getAll();
            request.setAttribute("accommodationsList", accommodations);
            
            List<User> userList = userDao.getAll();
            request.setAttribute("userList", userList);

            // Establecer la lista de revisiones como atributo de solicitud
            request.setAttribute("reviews", reviews);

            // Establecer un atributo para indicar si hay comentarios disponibles o no
            request.setAttribute("hasReviews", !reviews.isEmpty());

            // Establecer el objeto Property como atributo de solicitud
            request.setAttribute("property", property);

            // Redirigir a index4.jsp para mostrar los detalles del alojamiento
            RequestDispatcher view = request.getRequestDispatcher("/WEB-INF/index4.jsp");
            view.forward(request, response);
        } catch (Exception e) {
            logger.severe("Exception: " + e.getMessage());
            // Manejar cualquier error y redirigir a una página de error
            response.sendRedirect("error.jsp");
        }
    }
    
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
