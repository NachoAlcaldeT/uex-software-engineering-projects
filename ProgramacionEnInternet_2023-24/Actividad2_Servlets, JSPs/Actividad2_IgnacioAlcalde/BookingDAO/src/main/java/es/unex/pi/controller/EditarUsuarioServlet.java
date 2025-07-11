package es.unex.pi.controller;

import java.io.IOException;
import java.sql.Connection;
import java.util.HashMap;
import java.util.Map;
import java.util.logging.Logger;

import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import es.unex.pi.dao.JDBCUserDAOImpl;
import es.unex.pi.dao.UserDAO;
import es.unex.pi.model.User;

@WebServlet("/EditarUsuarioServlet.do")
public class EditarUsuarioServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
    private static final Logger logger = Logger.getLogger(HttpServlet.class.getName());

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        logger.info("Handling GET");
        HttpSession session = request.getSession();
        Connection conn = (Connection) getServletContext().getAttribute("dbConn");
		
		UserDAO userDao = new JDBCUserDAOImpl();
        userDao.setConnection(conn);
        
        User user = (User) session.getAttribute("user");
        long id = user.getId();
        User user2 = userDao.get(id);
        		
        if (user2 != null) {
            RequestDispatcher view = request.getRequestDispatcher("/WEB-INF/editUsuario.jsp");
            view.forward(request, response);
        } else {
        	response.sendRedirect("PerfilServlet.do");
        }   
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    	HttpSession session = request.getSession();
        Connection conn = (Connection) getServletContext().getAttribute("dbConn");
		
		UserDAO userDao = new JDBCUserDAOImpl();
        userDao.setConnection(conn);

        User user = new User();
        user.setId(Long.parseLong(request.getParameter("id")));
        user.setEmail(request.getParameter("email"));
        user.setPassword(request.getParameter("password"));
        user.setName(request.getParameter("name"));
        user.setSurname(request.getParameter("surname"));

        logger.info("Handling POST");

        Map<String, String> messages = new HashMap<String, String>();

        // if(user.validate(messages)) {
        userDao.update(user);
        session.setAttribute("user", user);
        logger.info("User updated successfully: " + user.getId());
        response.sendRedirect("PerfilServlet.do");
        // } else {
        //     messages.put("update", "Error al actualizar los datos del usuario");
        //     request.setAttribute("messages", messages);
        //     request.setAttribute("user", user);
        //     RequestDispatcher view = request.getRequestDispatcher("/WEB-INF/editUsuario.jsp");
        //     view.forward(request, response);
        //     logger.warning("Validation error while updating user: " + messages.toString());
        // }
    } 
}

