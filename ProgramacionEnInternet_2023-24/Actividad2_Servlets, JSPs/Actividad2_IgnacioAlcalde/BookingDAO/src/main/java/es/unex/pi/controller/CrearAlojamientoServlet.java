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
import java.util.HashMap;
import java.util.Map;
import java.util.logging.Logger;

import es.unex.pi.dao.JDBCPropertyDAOImpl;
import es.unex.pi.dao.JDBCUserDAOImpl;
import es.unex.pi.dao.PropertyDAO;
import es.unex.pi.dao.UserDAO;
import es.unex.pi.model.Property;
import es.unex.pi.model.User;

/**
 * Servlet implementation class CrearAlojamientoServlet
 */
@WebServlet("/CrearAlojamientoServlet.do")
public class CrearAlojamientoServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private static final Logger logger = Logger.getLogger(HttpServlet.class.getName());   
    /**
     * @see HttpServlet#HttpServlet()
     */
    public CrearAlojamientoServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		HttpSession session = request.getSession();
		if(session.getAttribute("property") != null) {
			session.removeAttribute("property");
		}
		
		RequestDispatcher view = request.getRequestDispatcher("/WEB-INF/nuevoAlojamiento.jsp");
		view.forward(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	    HttpSession session = request.getSession();
	    request.setCharacterEncoding("UTF-8");

	    // Configurar el logger
	    Logger logger = Logger.getLogger(CrearAlojamientoServlet.class.getName());
	    logger.info("Handling POST");

	    Connection conn = (Connection) getServletContext().getAttribute("dbConn");

	    PropertyDAO propertyDao = new JDBCPropertyDAOImpl();
	    propertyDao.setConnection(conn);

	    // Obtener parámetros del formulario y asignarlos al objeto de propiedad
	    String name = request.getParameter("name");
	    logger.info("Name: " + name);

	    String address = request.getParameter("address");
	    logger.info("Address: " + address);

	    String telephone = request.getParameter("telephone");
	    logger.info("Telephone: " + telephone);

	    float gradesAverage = Float.parseFloat(request.getParameter("gradesAverage"));
	    logger.info("Grades Average: " + gradesAverage);

	    String city = request.getParameter("city");
	    logger.info("City: " + city);

	    int centerDistance = Integer.parseInt(request.getParameter("centerDistance"));
	    logger.info("Center Distance: " + centerDistance);

	    String description = request.getParameter("description");
	    logger.info("Description: " + description);

	    int petFriendly = 0;
	    if (request.getParameter("petFriendly") != null && request.getParameter("petFriendly").equals("1")) {
	        petFriendly = 1;
	    }
	    logger.info("Pet Friendly: " + petFriendly);

	    int available = 0;
	    if (request.getParameter("available") != null && request.getParameter("available").equals("1")) {
	        available = 1;
	    }
	    logger.info("Available: " + available);

	    int aireAcondicionado = 0;
	    if (request.getParameter("aireAcondicionado") != null && request.getParameter("aireAcondicionado").equals("1")) {
	        aireAcondicionado = 1;
	    }
	    logger.info("Aire Acondicionado: " + aireAcondicionado);

	    int wifi = 0;
	    if (request.getParameter("wifi") != null && request.getParameter("wifi").equals("1")) {
	        wifi = 1;
	    }
	    logger.info("WiFi: " + wifi);

	    int tv = 0;
	    if (request.getParameter("tv") != null && request.getParameter("tv").equals("1")) {
	        tv = 1;
	    }
	    logger.info("TV: " + tv);
	    
	    Property property = new Property();
	    
	    property.setName(name);
	    property.setAddress(address);
	    property.setTelephone(telephone);
	    property.setGradesAverage(gradesAverage);
	    property.setCity(city);
	    property.setCenterDistance(centerDistance);
	    property.setDescription(description);
	    property.setPetFriendly(petFriendly);
	    property.setAvailable(available);
	    property.setaireAcondicionado(aireAcondicionado);
	    property.setWiFi(wifi);
	    property.setTV(tv);

	    User user = (User) session.getAttribute("user");
        int userId = (int) user.getId(); // Se convierte el id del usuario a int
        property.setIdu(userId);
        
        long propertyId = propertyDao.add(property);
        
	    if (propertyId != -1) {
	        property.setId(propertyId);
	        session.setAttribute("property", property);
	        logger.info("Property created successfully with ID: " + propertyId);
	        response.sendRedirect("PerfilServlet.do");
	    } else {
	        logger.warning("Failed to create Property");
	        // Aquí podrías redirigir a una página de error o manejar el fallo de otra manera
	        // Por ejemplo:
	        // response.sendRedirect("error.jsp");
	    }
	}
	
}
