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
import java.util.logging.Logger;

import es.unex.pi.dao.AccommodationDAO;
import es.unex.pi.dao.JDBCAccommodationDAOImpl;
import es.unex.pi.model.Accommodation;

/**
 * Servlet implementation class CrearHabitacionServlet
 */
@WebServlet("/CrearHabitacionServlet.do")
public class CrearHabitacionServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private static final Logger logger = Logger.getLogger(HttpServlet.class.getName());   
    /**
     * @see HttpServlet#HttpServlet()
     */
    public CrearHabitacionServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		logger.info("Handling GET");
        HttpSession session = request.getSession();
        Connection conn = (Connection) getServletContext().getAttribute("dbConn");
        AccommodationDAO accommodationDao = new JDBCAccommodationDAOImpl();
        accommodationDao.setConnection(conn);

        if (session.getAttribute("accommodation") != null) {
            session.removeAttribute("accommodation");
        }

        String idPropertyParam = request.getParameter("idProperty");
        if (idPropertyParam == null || idPropertyParam.isEmpty()) {
            // Si el parámetro "idProperty" no está presente o está vacío, redirigir o manejar el error adecuadamente
            response.sendRedirect("PerfilServlet.do");
            return;
        }

        long idProperty;
        try {
            idProperty = Long.parseLong(idPropertyParam);
        } catch (NumberFormatException e) {
            // Manejar el caso en que el parámetro "idProperty" no sea un número válido
            response.sendRedirect("PerfilServlet.do");
            return;
        }

        request.setAttribute("idProperty", idProperty);

        // Evitar un problema potencial si el usuario hace clic en el botón Atrás del navegador antes de confirmar la creación del alojamiento
        RequestDispatcher view = request.getRequestDispatcher("/WEB-INF/crearHabitacion.jsp");
        view.forward(request, response);
    }

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		HttpSession session = request.getSession();

	    logger.info("Handling POST");
	    String idPropertyParam = request.getParameter("idProperty");
	    logger.info("Received idProperty: " + idPropertyParam);

	    if (idPropertyParam == null || idPropertyParam.isEmpty()) {
	        // Manejar el error de parámetro faltante
	        logger.severe("idProperty is missing");
	        response.sendError(HttpServletResponse.SC_BAD_REQUEST, "Missing idProperty");
	        return;
	    }

	    Connection conn = (Connection) getServletContext().getAttribute("dbConn");
	    AccommodationDAO accommodationDAO = new JDBCAccommodationDAOImpl();
	    accommodationDAO.setConnection(conn);

	    try {
	        long idProperty = Long.parseLong(idPropertyParam);
	        
	        Accommodation accommodation = new Accommodation();
	        
	        String name = request.getParameter("name");
	        if(name != null && !name.isEmpty()) {
	            accommodation.setName(name);
	        }
	        
	        String description = request.getParameter("description");
	        if(description != null && !description.isEmpty()) {
	            accommodation.setDescription(description);
	        }

	        String price = request.getParameter("price");
	        if(price != null && !price.isEmpty()) {
	            accommodation.setPrice(Integer.parseInt(price));
	        }
	        
	        String numAccommodations = request.getParameter("numAccommodations");
	        if(numAccommodations != null && !numAccommodations.isEmpty()) {
	            accommodation.setNumAccommodations(Integer.parseInt(numAccommodations));
	        }
	        
	       
	        accommodation.setIdp(idProperty);

	        long accommodationId = accommodationDAO.add(accommodation);
	        accommodation.setId(accommodationId);

	        session.setAttribute("accommodation", accommodation);

	        response.sendRedirect("EditarAlojamientoServlet.do?id=" + idProperty);
	    } catch (NumberFormatException e) {
	        logger.severe("Invalid number format for idProperty");
	        response.sendError(HttpServletResponse.SC_BAD_REQUEST, "Invalid idProperty format");
	    }
	}
}
