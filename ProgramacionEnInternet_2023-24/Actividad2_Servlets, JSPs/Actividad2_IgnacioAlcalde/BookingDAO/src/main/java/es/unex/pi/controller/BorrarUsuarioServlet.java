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

import es.unex.pi.dao.JDBCUserDAOImpl;
import es.unex.pi.dao.UserDAO;
import es.unex.pi.model.User;

@WebServlet("/BorrarUsuarioServlet.do")
public class BorrarUsuarioServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
    private static final Logger logger = Logger.getLogger(HttpServlet.class.getName());

    public BorrarUsuarioServlet() {
        super();
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        Connection conn = (Connection) getServletContext().getAttribute("dbConn");
        UserDAO userDao = new JDBCUserDAOImpl();
        userDao.setConnection(conn);
        HttpSession session = request.getSession();
        
        long userId= Long.parseLong(request.getParameter("id"));
        
        User user = userDao.get(userId);

        if (user != null) {
            session.setAttribute("user", user);
            request.getRequestDispatcher("/WEB-INF/borrarUsuario.jsp").forward(request, response);
        } else {
            response.sendRedirect(request.getContextPath() + "PerfilServlet.do");
        }
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        Connection conn = (Connection) getServletContext().getAttribute("dbConn");
        UserDAO userDao = new JDBCUserDAOImpl();
        userDao.setConnection(conn);
        HttpSession session = request.getSession();
        
        User user = (User) session.getAttribute("user");
        if (user != null) {
        	userDao.delete(user.getId());
            session.removeAttribute("user");
        }

        response.sendRedirect("paginaInicio.do");
    }
}