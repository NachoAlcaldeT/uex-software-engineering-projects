package es.unex.pi.controller;

import jakarta.servlet.RequestDispatcher;
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

import es.unex.pi.dao.AccommodationDAO;
import es.unex.pi.dao.BookingDAO;
import es.unex.pi.dao.BookingsAccommodationsDAO;
import es.unex.pi.dao.FavoritosDAO;
import es.unex.pi.dao.JDBCAccommodationDAOImpl;
import es.unex.pi.dao.JDBCBookingDAOImpl;
import es.unex.pi.dao.JDBCBookingsAccommodationsDAOImpl;
import es.unex.pi.dao.JDBCFavoritosDAOImpl;
import es.unex.pi.dao.JDBCPropertyDAOImpl;
import es.unex.pi.dao.PropertyDAO;
import es.unex.pi.model.Accommodation;
import es.unex.pi.model.Booking;
import es.unex.pi.model.BookingsAccommodations;
import es.unex.pi.model.Favoritos;
import es.unex.pi.model.Property;
import es.unex.pi.model.User;

/**
 * Servlet implementation class ReservasUsuarioServlet
 */
@WebServlet("/ReservasUsuarioServlet.do")
public class ReservasUsuarioServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private static final Logger logger = Logger.getLogger(HttpServlet.class.getName());
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ReservasUsuarioServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		 Connection conn = (Connection) getServletContext().getAttribute("dbConn");
	        HttpSession session = request.getSession(false);
	        User user = (User) session.getAttribute("user");
	        request.setAttribute("user", user);

	        // Logger para verificar la carga de datos
	        logger.info("Cargando reservas para el usuario: " + user.getName());

	        try {
	            // Obtener reservas
	            BookingDAO bookingDAO = new JDBCBookingDAOImpl();
	            bookingDAO.setConnection(conn);
	            List<Booking> bookingList = bookingDAO.getAll();
	            request.setAttribute("bookingList", bookingList);
	            logger.info("Número de reservas obtenidas: " + bookingList.size());

	            // Obtener propiedades
	            PropertyDAO propertyDAO = new JDBCPropertyDAOImpl();
	            propertyDAO.setConnection(conn);
	            List<Property> propertyList = propertyDAO.getAll();
	            request.setAttribute("propertyList", propertyList);
	            logger.info("Número de propiedades obtenidas: " + propertyList.size());

	            // Obtener relaciones de reservas con alojamientos
	            BookingsAccommodationsDAO bookingsAccommodationsDAO = new JDBCBookingsAccommodationsDAOImpl();
	            bookingsAccommodationsDAO.setConnection(conn);
	            List<BookingsAccommodations> bookingAccomodationsList = bookingsAccommodationsDAO.getAll();
	            request.setAttribute("bookingAccomodationsList", bookingAccomodationsList);
	            logger.info("Número de relaciones de reservas con alojamientos obtenidas: " + bookingAccomodationsList.size());

	            // Obtener alojamientos
	            AccommodationDAO accommodationDAO = new JDBCAccommodationDAOImpl();
	            accommodationDAO.setConnection(conn);
	            List<Accommodation> accommodationList = accommodationDAO.getAll();
	            request.setAttribute("accommodationList", accommodationList);
	            logger.info("Número de alojamientos obtenidos: " + accommodationList.size());
	        } catch (Exception e) {
	            logger.severe("Error al obtener datos del DAO: " + e.getMessage());
	        }

	        // Redirigir al JSP para mostrar las reservas
	        request.getRequestDispatcher("/WEB-INF/index6.jsp").forward(request, response);
	    }

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
