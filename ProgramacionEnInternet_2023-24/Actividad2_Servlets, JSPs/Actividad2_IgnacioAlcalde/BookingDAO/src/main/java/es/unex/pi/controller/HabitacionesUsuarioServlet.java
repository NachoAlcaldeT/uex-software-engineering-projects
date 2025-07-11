package es.unex.pi.controller;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.util.List;
import java.util.logging.Logger;

import es.unex.pi.dao.AccommodationDAO;
import es.unex.pi.dao.JDBCAccommodationDAOImpl;
import es.unex.pi.dao.JDBCPropertyDAOImpl;
import es.unex.pi.dao.PropertyDAO;
import es.unex.pi.model.Accommodation;
import es.unex.pi.model.Property;

/**
 * Servlet implementation class HabitacionesUsuarioServlet
 */
@WebServlet("/HabitacionesUsuarioServlet.do")
public class HabitacionesUsuarioServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private static final Logger logger = Logger.getLogger(HttpServlet.class.getName());   
    /**
     * @see HttpServlet#HttpServlet()
     */
    public HabitacionesUsuarioServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		 long userId = Long.parseLong(request.getParameter("userId"));

		 	Connection conn = (Connection) getServletContext().getAttribute("dbConn");
	        PropertyDAO propertyDAO = new JDBCPropertyDAOImpl();
	        propertyDAO.setConnection(conn);
	        AccommodationDAO accommodationDAO = new JDBCAccommodationDAOImpl();
	        accommodationDAO.setConnection(conn);

	        List<Property> properties = propertyDAO.getAllByUser(userId);
	        int totalHabitaciones = 0;

	        for (Property property : properties) {
	            List<Accommodation> accommodations = accommodationDAO.getAllByProperty(property.getId());
	            for (Accommodation accommodation : accommodations) {
	                totalHabitaciones += accommodation.getNumAccommodations();
	            }
	        }

	        response.setContentType("text/html");
	        PrintWriter out = response.getWriter();
	        out.println("<html><body>");
	        out.println("<h1>Total de habitaciones: " + totalHabitaciones + "</h1>");
	        out.println("</body></html>");
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
