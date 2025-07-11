package es.unex.pi.controller;

import java.io.IOException;
import java.sql.Connection;
import java.util.List;
import java.util.logging.Logger;

import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import es.unex.pi.dao.FavoritosDAO;
import es.unex.pi.dao.JDBCFavoritosDAOImpl;
import es.unex.pi.dao.JDBCPropertyDAOImpl;
import es.unex.pi.dao.PropertyDAO;
import es.unex.pi.model.Favoritos;
import es.unex.pi.model.Property;
import es.unex.pi.model.User;

/**
 * Servlet implementation class DetailOrderServlet
 */
@WebServlet("/PerfilServlet.do")
public class PerfilServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private static final Logger logger = Logger.getLogger(HttpServlet.class.getName());
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public PerfilServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		Connection conn = (Connection) getServletContext().getAttribute("dbConn");
    	PropertyDAO propertyDao = new JDBCPropertyDAOImpl();
    	propertyDao.setConnection(conn);
    	
    	FavoritosDAO favoritosDao= new JDBCFavoritosDAOImpl();
		favoritosDao.setConnection(conn);
    	
		List<Favoritos> favoritosList = favoritosDao.getAll(); // Cambio de nombre a FavoritosList
	    request.setAttribute("favoritosList", favoritosList);
		
        List<Property> propertyList = propertyDao.getAll();
        request.setAttribute("propertyList", propertyList);
        
		HttpSession session = request.getSession(false);
		
		try{			
			if (session != null && session.getAttribute("user") != null){
				User user= (User) session.getAttribute("user");
				request.setAttribute("user",user);
			}
			else response.sendRedirect("PaginaInicio.do");
		}
			catch (Exception e) {
				logger.severe("Exception: "+ e.getMessage());
		}
		RequestDispatcher view = request.getRequestDispatcher("/WEB-INF/perfil.jsp");
		view.forward(request,response);	
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}
}