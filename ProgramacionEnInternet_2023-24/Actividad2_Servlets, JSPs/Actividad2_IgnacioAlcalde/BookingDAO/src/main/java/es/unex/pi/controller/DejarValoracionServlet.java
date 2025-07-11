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
import es.unex.pi.dao.JDBCPropertyDAOImpl;
import es.unex.pi.dao.JDBCReviewDAOImpl;
import es.unex.pi.dao.PropertyDAO;
import es.unex.pi.dao.ReviewDAO;
import es.unex.pi.model.Property;
import es.unex.pi.model.Review;
import es.unex.pi.model.User;

/**
 * Servlet implementation class DejarValoracionServlet
 */
@WebServlet("/DejarValoracionServlet.do")
public class DejarValoracionServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private static final Logger logger = Logger.getLogger(HttpServlet.class.getName());   

    public DejarValoracionServlet() {
        super();
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        logger.info("Handling GET");
        HttpSession session = request.getSession();
        Connection conn = (Connection) getServletContext().getAttribute("dbConn");
        ReviewDAO reviewDao = new JDBCReviewDAOImpl();
        reviewDao.setConnection(conn);
        PropertyDAO propertyDao = new JDBCPropertyDAOImpl();
        propertyDao.setConnection(conn);

        String idPropertyParam = request.getParameter("idProperty");
        if (idPropertyParam == null || idPropertyParam.isEmpty()) {
            response.sendRedirect("VerAlojamiento.do");
            return;
        }

        long idProperty;
        try {
            idProperty = Long.parseLong(idPropertyParam);
        } catch (NumberFormatException e) {
            response.sendRedirect("VerAlojamiento.do");
            return;
        }

        User user = (User) session.getAttribute("user");
        if (user != null) {
            Property property = propertyDao.get(idProperty);
            if (property.getIdu() == user.getId()) {
                RequestDispatcher view = request.getRequestDispatcher("/WEB-INF/dejarValoracionPropietario.jsp");
                view.forward(request, response);
                return;
            }

            Review existingReview = reviewDao.get(idProperty, user.getId());
            if (existingReview != null) {
                request.setAttribute("existingReview", existingReview);
            }
        }

        request.setAttribute("idProperty", idProperty);
        RequestDispatcher view = request.getRequestDispatcher("/WEB-INF/dejarValoracion.jsp");
        view.forward(request, response);
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        logger.info("Handling POST");
        HttpSession session = request.getSession();
        User user = (User) session.getAttribute("user");

        String idPropertyParam = request.getParameter("idProperty");
        if (idPropertyParam == null || idPropertyParam.isEmpty()) {
            response.sendError(HttpServletResponse.SC_BAD_REQUEST, "Missing idProperty");
            return;
        }

        Connection conn = (Connection) getServletContext().getAttribute("dbConn");
        ReviewDAO reviewDAO = new JDBCReviewDAOImpl();
        reviewDAO.setConnection(conn);
        PropertyDAO propertyDao = new JDBCPropertyDAOImpl();
        propertyDao.setConnection(conn);

        long idProperty = Long.parseLong(idPropertyParam);

        if (user != null) {
            Property property = propertyDao.get(idProperty);
            if (property.getIdu() == user.getId()) {
                RequestDispatcher view = request.getRequestDispatcher("/WEB-INF/dejarValoracionPropietario.jsp");
                view.forward(request, response);
                return;
            }

            Long idu = user.getId();
            int iduInt = idu.intValue();

            String comment = request.getParameter("comment");
            int rating = Integer.parseInt(request.getParameter("rating"));

            Review existingReview = reviewDAO.get(idProperty, iduInt);
            boolean result;

            if (existingReview != null) {
                existingReview.setReview(comment);
                existingReview.setGrade(rating);
                result = reviewDAO.update(existingReview);
            } else {
                Review newReview = new Review();
                newReview.setIdp(idProperty);
                newReview.setIdu(iduInt);
                newReview.setReview(comment);
                newReview.setGrade(rating);
                result = reviewDAO.add(newReview);
            }

            if (result) {
                request.setAttribute("message", "Operación realizada con éxito");
                RequestDispatcher dispatcher = request.getRequestDispatcher("AlojamientoServlet.do");
                dispatcher.forward(request, response);
            } else {
                request.setAttribute("errorMessage", "Hubo un problema al procesar la solicitud");
                RequestDispatcher dispatcher = request.getRequestDispatcher("error.jsp");
                dispatcher.forward(request, response);
            }
        }
    }
}
