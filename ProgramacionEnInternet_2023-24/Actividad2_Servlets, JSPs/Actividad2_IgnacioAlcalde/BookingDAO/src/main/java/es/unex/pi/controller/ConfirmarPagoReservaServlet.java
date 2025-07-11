package es.unex.pi.controller;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

import java.io.IOException;
import java.sql.Connection;

import es.unex.pi.dao.AccommodationDAO;
import es.unex.pi.dao.BookingDAO;
import es.unex.pi.dao.BookingsAccommodationsDAO;
import es.unex.pi.dao.JDBCAccommodationDAOImpl;
import es.unex.pi.dao.JDBCBookingDAOImpl;
import es.unex.pi.dao.JDBCBookingsAccommodationsDAOImpl;
import es.unex.pi.dao.JDBCUserDAOImpl;
import es.unex.pi.dao.UserDAO;
import es.unex.pi.model.Accommodation;
import es.unex.pi.model.Booking;
import es.unex.pi.model.BookingsAccommodations;
import es.unex.pi.model.User;

/**
 * Servlet implementation class ConfirmarPagoReservaServlet
 */
@WebServlet("/ConfirmarPagoReservaServlet.do")
public class ConfirmarPagoReservaServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ConfirmarPagoReservaServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		 doPost(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		 Connection conn = (Connection) getServletContext().getAttribute("dbConn");
		    HttpSession session = request.getSession(false);

		    // Obtener los parámetros del request y almacenarlos en la sesión si no están presentes
		    String numHabitacionesParam = request.getParameter("numHabitaciones");
		    String totalPriceParam = request.getParameter("totalPrice");
		    long idAccommodation = Long.parseLong(request.getParameter("idAccommodation"));

		    int numHabitaciones;
		    int totalPrice;

		    if (numHabitacionesParam != null) {
		        numHabitaciones = Integer.parseInt(numHabitacionesParam);
		        session.setAttribute("numHabitaciones", numHabitaciones);
		    } else {
		        numHabitaciones = (int) session.getAttribute("numHabitaciones");
		    }

		    if (totalPriceParam != null) {
		        totalPrice = Integer.parseInt(totalPriceParam);
		        session.setAttribute("totalPrice", totalPrice);
		    } else {
		        totalPrice = (int) session.getAttribute("totalPrice");
		    }

		    AccommodationDAO accommodationDao = new JDBCAccommodationDAOImpl();
		    accommodationDao.setConnection(conn);

		    Accommodation accommodation = accommodationDao.get(idAccommodation);

		    User user = (User) session.getAttribute("user");
		    UserDAO userDao = new JDBCUserDAOImpl();
		    userDao.setConnection(conn);

		    BookingDAO bookingDao = new JDBCBookingDAOImpl();
		    bookingDao.setConnection(conn);
		    Booking booking = new Booking();
		    booking.setIdu(user.getId());
		    booking.setTotalPrice(totalPrice);
		    long id = bookingDao.add(booking);
		    booking.setId(id);

		    BookingsAccommodationsDAO bookingAccommodationDao = new JDBCBookingsAccommodationsDAOImpl();
		    bookingAccommodationDao.setConnection(conn);
		    BookingsAccommodations bookingAccommodation = new BookingsAccommodations();
		    bookingAccommodation.setIdb(booking.getId());
		    bookingAccommodation.setIdacc(accommodation.getId());
		    bookingAccommodation.setNumAccommodations(numHabitaciones);

		    bookingAccommodationDao.add(bookingAccommodation);

		    session.setAttribute("booking", booking);

		    request.setAttribute("user", user);
		    request.setAttribute("booking", booking);
		    request.setAttribute("accommodation", accommodation);
		    request.getRequestDispatcher("/WEB-INF/confirmarPagoReserva.jsp").forward(request, response);
    }
}
