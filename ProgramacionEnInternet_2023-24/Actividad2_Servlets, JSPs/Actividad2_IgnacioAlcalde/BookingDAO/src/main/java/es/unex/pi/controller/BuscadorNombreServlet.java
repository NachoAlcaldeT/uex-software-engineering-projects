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
 * Servlet implementation class buscardorServlet
 */
@WebServlet("/BuscadorNombreServlet.do")
public class BuscadorNombreServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public BuscadorNombreServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        Connection conn = (Connection) getServletContext().getAttribute("dbConn");
        HttpSession session = request.getSession(false);
        String searchQuery = request.getParameter("search");
        User user = (User) session.getAttribute("user");
        
        request.setAttribute("user", user);
        
        PropertyDAO propertyDao = new JDBCPropertyDAOImpl();
        propertyDao.setConnection(conn);
        List<Property> propertyList = propertyDao.getAllBySearchName(searchQuery);
        request.setAttribute("propertyList", propertyList);
        
        FavoritosDAO favoritoDao = new JDBCFavoritosDAOImpl();
        favoritoDao.setConnection(conn);
        List<Favoritos> favProperty = favoritoDao.getAll();
        request.setAttribute("favProperty", favProperty);
        
      
        request.getRequestDispatcher("/WEB-INF/index3.jsp").forward(request, response);
    }

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}