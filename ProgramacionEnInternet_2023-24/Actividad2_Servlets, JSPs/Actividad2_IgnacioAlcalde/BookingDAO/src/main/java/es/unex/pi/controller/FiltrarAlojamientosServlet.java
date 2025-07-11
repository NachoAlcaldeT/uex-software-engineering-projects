package es.unex.pi.controller;

import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.Connection;
import java.util.List;

import es.unex.pi.dao.JDBCPropertyDAOImpl;
import es.unex.pi.dao.PropertyDAO;
import es.unex.pi.model.Property;

/**
 * Servlet implementation class FiltrarAlojamientosServlet
 */
@WebServlet("/FiltrarAlojamientosServlet.do")
public class FiltrarAlojamientosServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public FiltrarAlojamientosServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
    	 Connection conn = (Connection) getServletContext().getAttribute("dbConn");
         PropertyDAO propertyDao = new JDBCPropertyDAOImpl();
         propertyDao.setConnection(conn);

         String filtro = request.getParameter("filtro");
         List<Property> propertyList = null;
         
         if ("disponible".equals(filtro)) {
             propertyList = propertyDao.getAvailables();
         } else if ("no_disponible".equals(filtro)) {
             propertyList = propertyDao.getNotAvailables();
         } else if ("valoracion".equals(filtro)) {
             propertyList = propertyDao.getAllOrderedByRating();
         } else {
             // En caso de que no se haya especificado un filtro válido, mostrar todos los alojamientos
             propertyList = propertyDao.getAll();
         }
         
         request.setAttribute("propertyList", propertyList);

         // Enviar la solicitud al JSP adecuado para su visualización
         RequestDispatcher view = request.getRequestDispatcher("/WEB-INF/index3.jsp");
         view.forward(request, response);
     }

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
