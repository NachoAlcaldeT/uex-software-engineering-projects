package es.unex.pi.controller;
import java.io.IOException;
import java.sql.Connection;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import es.unex.pi.dao.JDBCPropertyDAOImpl;
import es.unex.pi.dao.JDBCReviewDAOImpl;
import es.unex.pi.dao.PropertyDAO;
import es.unex.pi.dao.ReviewDAO;
import es.unex.pi.model.Property;
import es.unex.pi.model.Review;

@WebServlet("/AlojamientoServlet.do")
public class AlojamientoServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
    

    public AlojamientoServlet() {
        super();
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    	Connection conn = (Connection) getServletContext().getAttribute("dbConn");
        PropertyDAO propertyDao = new JDBCPropertyDAOImpl();
        propertyDao.setConnection(conn);

        String destino = request.getParameter("destino");
        String filtro = request.getParameter("filtro");

        List<Property> propertyList = propertyDao.getAll();
        List<Property> filteredProperties = new ArrayList<>();

        // Filtrar por destino
        if (destino != null && !destino.isEmpty()) {
            for (Property property : propertyList) {
                if (property.getCity().equalsIgnoreCase(destino)) {
                    filteredProperties.add(property);
                }
            }
        } else {
            filteredProperties = propertyList;
        }

        // Aplicar filtros adicionales sobre los resultados ya filtrados por destino
        if (filtro != null && !filtro.isEmpty() && filteredProperties != null) {
            List<Property> finalFilteredProperties = new ArrayList<>();
            if ("disponible".equals(filtro)) {
                for (Property property : filteredProperties) {
                    if (property.getAvailable() == 1) {
                        finalFilteredProperties.add(property);
                    }
                }
            } else if ("no_disponible".equals(filtro)) {
                for (Property property : filteredProperties) {
                    if (property.getAvailable() == 0) {
                        finalFilteredProperties.add(property);
                    }
                }
            } else if ("valoracion".equals(filtro)) {
                filteredProperties.sort((p1, p2) -> Double.compare(p2.getGradesAverage(), p1.getGradesAverage()));
                finalFilteredProperties = filteredProperties;
            } else {
                finalFilteredProperties = filteredProperties;
            }
            filteredProperties = finalFilteredProperties;
        }

        request.setAttribute("propertyList", filteredProperties);
        request.setAttribute("destino", destino);  // Conservar el valor de destino
        request.setAttribute("filtro", filtro);    // Conservar el valor del filtro

        RequestDispatcher view = request.getRequestDispatcher("/WEB-INF/index3.jsp");
        view.forward(request, response);
    }


    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request, response);
    }
}
