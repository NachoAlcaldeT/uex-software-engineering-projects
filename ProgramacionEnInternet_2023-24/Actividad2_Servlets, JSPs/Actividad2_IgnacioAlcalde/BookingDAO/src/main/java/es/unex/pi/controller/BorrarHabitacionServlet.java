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
import es.unex.pi.dao.AccommodationDAO;
import es.unex.pi.dao.JDBCAccommodationDAOImpl;
import es.unex.pi.dao.JDBCPropertyDAOImpl;
import es.unex.pi.dao.PropertyDAO;
import es.unex.pi.model.Accommodation;
import es.unex.pi.model.Property;
import es.unex.pi.model.User;

@WebServlet("/BorrarHabitacionServlet.do")
public class BorrarHabitacionServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
    private static final Logger logger = Logger.getLogger(HttpServlet.class.getName());

    public BorrarHabitacionServlet() {
        super();
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        Connection conn = (Connection) getServletContext().getAttribute("dbConn");
        AccommodationDAO accommodationDao = new JDBCAccommodationDAOImpl();
        accommodationDao.setConnection(conn);
        HttpSession session = request.getSession();
        
        long accommodationId= Long.parseLong(request.getParameter("id"));
        
        Accommodation accommodation = accommodationDao.get(accommodationId);
        
	    logger.info("Received accommodationId: " + accommodationId);
        
        if (accommodation != null) {
            session.setAttribute("accommodation", accommodation);
            request.getRequestDispatcher("/WEB-INF/borrarHabitacion.jsp").forward(request, response);
        } else {
            response.sendRedirect(request.getContextPath() + "EditarAlojamientoServlet.do");
        }
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        Connection conn = (Connection) getServletContext().getAttribute("dbConn");
        AccommodationDAO accommodationDao = new JDBCAccommodationDAOImpl();
        accommodationDao.setConnection(conn);
        HttpSession session = request.getSession();
        
        Accommodation accommodation = (Accommodation) session.getAttribute("accommodation");
        if (accommodation != null) {
        	accommodationDao.delete(accommodation.getId());
            session.removeAttribute("property");
        }

        response.sendRedirect("PerfilServlet.do");
    }
}