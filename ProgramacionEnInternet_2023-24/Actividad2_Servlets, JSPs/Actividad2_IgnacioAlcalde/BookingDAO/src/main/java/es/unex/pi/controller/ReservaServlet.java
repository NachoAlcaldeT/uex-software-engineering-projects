package es.unex.pi.controller;

import es.unex.pi.dao.AccommodationDAO;
import es.unex.pi.dao.BookingDAO;
import es.unex.pi.dao.BookingsAccommodationsDAO;
import es.unex.pi.dao.JDBCAccommodationDAOImpl;
import es.unex.pi.dao.JDBCBookingDAOImpl;
import es.unex.pi.dao.JDBCBookingsAccommodationsDAOImpl;
import es.unex.pi.dao.JDBCPropertyDAOImpl;
import es.unex.pi.dao.PropertyDAO;
import es.unex.pi.model.Accommodation;
import es.unex.pi.model.Booking;
import es.unex.pi.model.BookingsAccommodations;
import es.unex.pi.model.Property;
import es.unex.pi.model.Review;
import es.unex.pi.model.User;
import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

import java.io.IOException;
import java.sql.Connection;
import java.util.logging.Logger;

@WebServlet("/ReservaServlet.do")
public class ReservaServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
    private static final Logger logger = Logger.getLogger(HttpServlet.class.getName());

    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
    	Connection conn = (Connection) getServletContext().getAttribute("dbConn");
    	HttpSession session = request.getSession(false);
    	PropertyDAO propertyDao = new JDBCPropertyDAOImpl();
    	propertyDao.setConnection(conn);
    	
    	User user = (User) session.getAttribute("user");       
    	request.setAttribute("user", user);
    	
    	Review review = (Review) session.getAttribute("review");       
    	request.setAttribute("review", review);
    	
    	long accommodationId= Long.parseLong(request.getParameter("id"));
    	
    	int price = Integer.parseInt(request.getParameter("price"));
        int numHabitaciones = Integer.parseInt(request.getParameter("habitaciones"));
        int totalPrice = price * numHabitaciones;
         
    	AccommodationDAO accommodationDao = new JDBCAccommodationDAOImpl();
    	accommodationDao.setConnection(conn);
    	Accommodation accommodation = accommodationDao.get(accommodationId);
    	request.setAttribute("accommodation", accommodation);
    	
    	long idp = accommodation.getIdp();
    	Property property = propertyDao.get(idp);
    	request.setAttribute("property", property);
    	
    	request.setAttribute("numHabitaciones", numHabitaciones);
    	logger.info("El usuario: " + user.getId() + "ha reservado: "+ numHabitaciones + "habitaciones, del alojamiento: " + accommodationId);
        request.setAttribute("totalPrice", totalPrice);
        logger.info("Precio total de la reserva: " + totalPrice);
       	 
    	request.getRequestDispatcher("/WEB-INF/index5.jsp").forward(request, response);
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
    	doGet(request, response);
    }
}
