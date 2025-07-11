package es.unex.pi.controller;

import java.io.IOException;
import java.sql.Connection;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.logging.Logger;

import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import es.unex.pi.dao.JDBCAccommodationDAOImpl;
import es.unex.pi.dao.JDBCPropertyDAOImpl;
import es.unex.pi.dao.PropertyDAO;
import es.unex.pi.dao.AccommodationDAO;
import es.unex.pi.model.Accommodation;
import es.unex.pi.model.Property;
import es.unex.pi.model.User;

@WebServlet("/EditarAlojamientoServlet.do")
public class EditarAlojamientoServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
    private static final Logger logger = Logger.getLogger(HttpServlet.class.getName());

    public EditarAlojamientoServlet() {
        super();
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        Connection conn = (Connection) getServletContext().getAttribute("dbConn");
        PropertyDAO propertyDao = new JDBCPropertyDAOImpl();
        AccommodationDAO accommodationDao= new JDBCAccommodationDAOImpl();
        propertyDao.setConnection(conn);
        accommodationDao.setConnection(conn);
        
        HttpSession session = request.getSession();
        User user = (User) session.getAttribute("user");

        long alojamientoId= Long.parseLong(request.getParameter("id"));

        List<Accommodation> accommodationList = accommodationDao.getAll();
        request.setAttribute("accommodationList", accommodationList);
        Property property = propertyDao.get(alojamientoId);

        if (property != null && property.getIdu() == user.getId()) {
            request.setAttribute("property", property);
            // Obtener la propiedad correspondiente a este alojamiento
            request.getRequestDispatcher("/WEB-INF/editarAlojamiento.jsp").forward(request, response);
        } else {
            response.sendRedirect("paginaInicio.do");
        }
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        Connection conn = (Connection) getServletContext().getAttribute("dbConn");
        PropertyDAO propertyDao = new JDBCPropertyDAOImpl();
        propertyDao.setConnection(conn);
        
        HttpSession session = request.getSession();
        User user = (User) session.getAttribute("user");       

        Property property = new Property();
        // Obtén los parámetros del formulario y asigna los valores al objeto de propiedad
        
        if (property != null && property.getIdu() == user.getId()) {
        
        String idParam = request.getParameter("id");
        if(idParam != null && !idParam.isEmpty()) {
            property.setId(Long.parseLong(idParam));
        }

        String name = request.getParameter("name");
        if(name != null && !name.isEmpty()) {
            property.setName(name);
        }
        
        String city = request.getParameter("city");
        if(city != null && !city.isEmpty()) {
            property.setCity(city);
        }

        String address = request.getParameter("address");
        if(address != null && !address.isEmpty()) {
            property.setAddress(address);
        }

        String telephone = request.getParameter("telephone");
        if(telephone != null && !telephone.isEmpty()) {
            property.setTelephone(telephone);
        }

        String centerDistanceParam = request.getParameter("centerDistance");
        if(centerDistanceParam != null && !centerDistanceParam.isEmpty()) {
            property.setCenterDistance(Double.parseDouble(centerDistanceParam));
        }

        String gradesAverageParam = request.getParameter("gradesAverage");
        if(gradesAverageParam != null && !gradesAverageParam.isEmpty()) {
            property.setGradesAverage(Double.parseDouble(gradesAverageParam));
        }

        String description = request.getParameter("description");
        if(description != null && !description.isEmpty()) {
            property.setDescription(description);
        }
        
        String availableParam = request.getParameter("available");
        if (availableParam != null && !availableParam.isEmpty()) {
            property.setAvailable(Integer.parseInt(availableParam));
        }
        
        String petFriendlyParam = request.getParameter("petFriendly");
        if(petFriendlyParam != null && !petFriendlyParam.isEmpty()) {
            property.setPetFriendly(Integer.parseInt(petFriendlyParam));
        }
        
        String wifiParam = request.getParameter("wifi");
        if(wifiParam != null && !wifiParam.isEmpty()) {
            property.setWiFi(Integer.parseInt(wifiParam));
        }
        
        String tvParam = request.getParameter("tv");
        if(tvParam != null && !tvParam.isEmpty()) {
            property.setTV(Integer.parseInt(tvParam));
        }
        
        String aireAcondicionadoParam = request.getParameter("aireAcondicionado");
        if(aireAcondicionadoParam != null && !aireAcondicionadoParam.isEmpty()) {
            property.setaireAcondicionado(Integer.parseInt(aireAcondicionadoParam));
        }
        
        Long idu = user.getId();
        int iduInt = idu.intValue(); // Convertir Long a int
        property.setIdu(iduInt);
        
        logger.info("Handling POST");

        propertyDao.update(property);
        logger.info("Property updated successfully: " + property.getId());
        List<Property> updatedPropertyList = propertyDao.getAll();
        request.setAttribute("propertyList", updatedPropertyList);

        // Redirigir al PerfilServlet con las propiedades actualizadas
        RequestDispatcher dispatcher = request.getRequestDispatcher("PerfilServlet.do");
        dispatcher.forward(request, response);
        }
    }
}