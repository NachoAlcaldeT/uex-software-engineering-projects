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
import es.unex.pi.dao.JDBCAccommodationDAOImpl;
import es.unex.pi.dao.JDBCPropertyDAOImpl;
import es.unex.pi.dao.JDBCUserDAOImpl;
import es.unex.pi.dao.PropertyDAO;
import es.unex.pi.dao.UserDAO;
import es.unex.pi.model.Accommodation;
import es.unex.pi.model.Property;
import es.unex.pi.model.User;

/**
 * Servlet implementation class EditarHabitacionServlet
 */
@WebServlet("/EditarHabitacionServlet.do")
public class EditarHabitacionServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
    private static final Logger logger = Logger.getLogger(HttpServlet.class.getName());

    public EditarHabitacionServlet() {
        super();
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        Connection conn = (Connection) getServletContext().getAttribute("dbConn");
        AccommodationDAO accommodationDao= new JDBCAccommodationDAOImpl();
        accommodationDao.setConnection(conn);
        PropertyDAO propertyDao = new JDBCPropertyDAOImpl();
        propertyDao.setConnection(conn);
        UserDAO userDao = new JDBCUserDAOImpl();
        userDao.setConnection(conn);
        HttpSession session = request.getSession();
        
        long accommodationId= Long.parseLong(request.getParameter("id"));

        Accommodation accommodation = accommodationDao.get(accommodationId);
        long idProperty=accommodation.getIdp();
        Property property = propertyDao.get(idProperty);
        long idUser= property.getIdu();
        User user = userDao.get(idUser);
        User sessionUser = (User) session.getAttribute("user");
        
        if (accommodation != null && user.getId() == sessionUser.getId()) {
            request.setAttribute("accommodation", accommodation);
            // Obtener la propiedad correspondiente a este alojamiento
            request.getRequestDispatcher("/WEB-INF/editarHabitacion.jsp").forward(request, response);
        } else {
            response.sendRedirect("PerfilServlet.do");
        }
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        Connection conn = (Connection) getServletContext().getAttribute("dbConn");
        AccommodationDAO accommodationDao = new JDBCAccommodationDAOImpl();
        accommodationDao.setConnection(conn);
        
        HttpSession session = request.getSession();
        long accommodationId = Long.parseLong(request.getParameter("id"));
        Accommodation accommodation = accommodationDao.get(accommodationId);
        
        long propertyId = accommodation.getIdp();
        // Obtén los parámetros del formulario y asigna los valores al objeto de propiedad
        
        String idParam = request.getParameter("id");
        if(idParam != null && !idParam.isEmpty()) {
        	accommodation.setId(Long.parseLong(idParam));
        }

        String name = request.getParameter("name");
        if(name != null && !name.isEmpty()) {
            accommodation.setName(name);
        }
        
        String description = request.getParameter("description");
        if(description != null && !description.isEmpty()) {
            accommodation.setDescription(description);
        }

        String priceParam = request.getParameter("price");
        if(priceParam != null && !priceParam.isEmpty()) {
            accommodation.setPrice(Integer.parseInt(priceParam));
        }
        
        String numAccommodationsParam = request.getParameter("numAccommodations");
        if(numAccommodationsParam != null && !numAccommodationsParam.isEmpty()) {
            accommodation.setNumAccommodations(Integer.parseInt(numAccommodationsParam));
        }
  
        accommodation.setIdp(propertyId);
        
        logger.info("Handling POST");

        accommodationDao.update(accommodation);
        logger.info("Accommodation updated successfully: " + accommodation.getId());

        // Redirigir al PerfilServlet con las propiedades actualizadas
        RequestDispatcher dispatcher = request.getRequestDispatcher("EditarAlojamientoServlet.do");
        dispatcher.forward(request, response);
    }

}
