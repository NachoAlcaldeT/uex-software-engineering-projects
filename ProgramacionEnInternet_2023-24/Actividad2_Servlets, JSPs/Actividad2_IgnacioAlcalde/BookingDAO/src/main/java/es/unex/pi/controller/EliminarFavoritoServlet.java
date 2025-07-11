package es.unex.pi.controller;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

import java.io.IOException;
import java.sql.Connection;
import java.util.List;

import es.unex.pi.dao.FavoritosDAO;
import es.unex.pi.dao.JDBCFavoritosDAOImpl;
import es.unex.pi.dao.JDBCPropertyDAOImpl;
import es.unex.pi.dao.PropertyDAO;
import es.unex.pi.model.Favoritos;
import es.unex.pi.model.Property;
import es.unex.pi.model.User;

/**
 * Servlet implementation class EliminarFavoritoServlet
 */
@WebServlet("/EliminarFavoritoServlet.do")
public class EliminarFavoritoServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
       
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        Connection conn= (Connection) getServletContext().getAttribute("dbConn");
        HttpSession session = request.getSession(false);
        User user = (User) session.getAttribute("user");
        
        FavoritosDAO favoritosDao = new JDBCFavoritosDAOImpl();
        favoritosDao.setConnection(conn);
        
        long idProperty = Long.parseLong(request.getParameter("idProperty"));
        
        if (favoritosDao.isFavorite(user.getId(), idProperty)) {
            favoritosDao.delete(user.getId(), idProperty);
            session.setAttribute("favoritoEliminado", true);
            session.setAttribute("idPropertyEliminado", idProperty);
        }
        
        response.sendRedirect(request.getHeader("referer")); // Redirigir de nuevo a la página anterior
    }


	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
