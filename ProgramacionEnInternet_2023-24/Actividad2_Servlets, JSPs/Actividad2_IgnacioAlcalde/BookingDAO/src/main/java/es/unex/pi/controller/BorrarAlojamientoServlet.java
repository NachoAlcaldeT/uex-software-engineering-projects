package es.unex.pi.controller;

import java.io.IOException;
import java.sql.Connection;
import java.util.logging.Logger;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

import es.unex.pi.dao.JDBCPropertyDAOImpl;
import es.unex.pi.dao.PropertyDAO;
import es.unex.pi.model.Property;
import es.unex.pi.model.User;

@WebServlet("/BorrarAlojamientoServlet.do")
public class BorrarAlojamientoServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
    private static final Logger logger = Logger.getLogger(HttpServlet.class.getName());

    public BorrarAlojamientoServlet() {
        super();
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        Connection conn = (Connection) getServletContext().getAttribute("dbConn");
        PropertyDAO propertyDao = new JDBCPropertyDAOImpl();
        propertyDao.setConnection(conn);
        HttpSession session = request.getSession();
        
        long propertyId= Long.parseLong(request.getParameter("id"));
        
        Property property = propertyDao.get(propertyId);

        if (property != null) {
            session.setAttribute("property", property);
            request.getRequestDispatcher("/WEB-INF/borrarAlojamiento.jsp").forward(request, response);
        } else {
            response.sendRedirect(request.getContextPath() + "PerfilServlet.do");
        }
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        Connection conn = (Connection) getServletContext().getAttribute("dbConn");
        PropertyDAO propertyDao = new JDBCPropertyDAOImpl();
        propertyDao.setConnection(conn);
        HttpSession session = request.getSession();
        
        Property property = (Property) session.getAttribute("property");
        if (property != null) {
            propertyDao.delete(property.getId());
            session.removeAttribute("property");
        }

        response.sendRedirect("PerfilServlet.do");
    }
}