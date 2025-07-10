
import java.util.*;
import javax.swing.Box;
import java.io.*;;

/**
 * La clase "Equipo" representa los equipos que participarán en la competición.
 * 
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz.
 * @versión 12/12/2022
 */
public class Equipo
{
    private String nombre;
    private List<Ciclista> ciclistas;
    private List<Ciclista> ciclistasAbandonado;
    private List<Bicicleta> bicicletas;
    private Comparator <Ciclista> compCiclista;
    private boolean ordenCiclista;
    private Comparator <Bicicleta> compBicicleta;
    private boolean ordenBicicleta;

    /**
     * Constructor para objetos de la clase Equipo.
     */
    public Equipo()
    {
        nombre = "";
        ciclistas = new ArrayList<Ciclista>();
        ciclistasAbandonado = new ArrayList<Ciclista>();
        bicicletas = new ArrayList<Bicicleta>();
        ordenCiclista = true;
        ordenBicicleta = true;
    }
    
    /**
     * Constructor parametrizado para objetos de la clase Equipo.
     * 
     * @param _nombre es el nombre que queremos asignar al equipo.
     * @param _compCiclista es el comparador de ciclistas.
     * @param _ordenCiclista es el método de ordenación de los ciclistas (true para ascendente, false para descendente).
     * @param _compBicicleta es el comparador de bicicletas.
     * @param _ordenBicicleta es el método de ordenación de las bicicletas (true para ascendente, false para descendente).
     */
    public Equipo(String _nombre, Comparator <Ciclista> _compCiclista, boolean _ordenCiclista, Comparator <Bicicleta> _compBicicleta, boolean _ordenBicicleta)
    {
        nombre = _nombre;
        ciclistas = new ArrayList<Ciclista>();
        ciclistasAbandonado = new ArrayList<Ciclista>();
        bicicletas = new ArrayList<Bicicleta>();
        compCiclista = _compCiclista;
        ordenCiclista = _ordenCiclista;
        compBicicleta = _compBicicleta;
        ordenBicicleta = _ordenBicicleta;
    }
    
    /**
     * Escribe una línea en el fichero de salida.
     * 
     * @param linea es la línea que se desea escribir.
     * @param writer es el buffer del fichero de salida.
     */
    private void escribirLinea(String linea, BufferedWriter writer) {
        try {
            writer.write(linea); 
        }
        catch(IOException e) {
            System.out.println("No se puede escribir la línea.");
        }
    }
    
    /**
     * Compara un objeto con este equipo y devuelve true si son iguales false en caso contrario.
     *
     * @param obj es el objeto a comparar.
     * 
     * @return true si los objetos son iguales y false en caso contrario.
     */
    @Override
    public boolean equals(Object obj)
    {
        if(this == obj) return true;
        if (!(obj instanceof Equipo)) return false;
        Equipo other = (Equipo) obj;
        return (getNombre().equals(other.getNombre()));
    }
    
    /**
     * Devuelve el código hash del objeto.
     * 
     * @return el código hash.
     */
    @Override
    public int hashCode()
    {
        int res = 7;
        res = 3 * res + getNombre().hashCode();
        return res;
    }
    
    /**
     * Asigna un nuevo nombre al equipo.
     * 
     * @param _nombre es el nuevo nombre del equipo.
     */
    public void setNombre(String _nombre)
    {            
        nombre = _nombre;  
    }
    
    /**
     * Obtiene el nombre del equipo.
     * 
     * @return el nombre del equipo.
     */
    public String getNombre()
    {
        return nombre;  
    }
    
    /**
     * Obtiene el número de ciclistas del equipo.
     * 
     * @return el número de ciclistas del equipo.
     */
    public int numTotalCiclistas()
    {
        return ciclistas.size();
    } 
    
    /**
     * Obtiene el número de ciclistas del equipo que han abandonado.
     * 
     * @return el número de ciclistas del equipo que han abandonado.
     */
    public int numTotalCiclistasAbandonado()
    {
        return ciclistasAbandonado.size();
    }   
    
    /**
     * Añade un ciclista al equipo.
     * 
     * @param c es el ciclista añadido al equipo.
     */
    public void anadirCiclista(Ciclista c)
    {            
        ciclistas.add(c);
    }
    
    /**
     * Elimina un ciclista del equipo.
     * 
     * @param c es el ciclista eliminado del equipo.
     */
    private void borrarCiclista(Ciclista c)
    {            
        ciclistas.remove(c);
    }
    
    /**
     * Añade un ciclista que ha abandonado al ArrayList de (ciclistasAbandonado).
     * 
     * @param c es el ciclista añadido de dicho ArrayList.
     */
    private void anadirCiclistaAbandonado(Ciclista c)
    {            
          ciclistasAbandonado.add(c);
    }
    
    /**
     * Elimina del ArrayList ciclistasAbandonado un ciclista que ha abandonado.
     * 
     * @param c es el ciclista eliminado de dicho ArrayList.
     */
    private void borrarCiclistaAbandonado(Ciclista c)
    {
        ciclistasAbandonado.remove(c);
    }
    
    /**
     * Añade una bicicleta del equipo.
     * 
     * @param b es la bicicleta añadida.
     */
    public void anadirBicicleta(Bicicleta b)
    {            
        bicicletas.add(b);
    }
    
    /**
     * Eliminar del ArrayList una bicicleta del equipo.
     * 
     * @param b es la bicicleta eliminada.
     */
    private void borrarBicicleta(Bicicleta b)
    {            
        bicicletas.remove(b);
    }
    
    /**
     * Establece un nuevo comparador de ciclistas.
     * 
     * @param _compCiclista es el nuevo comparador.
     * @param _ordenCiclista es el nuevo orden.
     */
    public void setComparadorCiclistas(Comparator <Ciclista> _compCiclista, boolean _ordenCiclista)
    {
        compCiclista = _compCiclista;
        ordenCiclista = _ordenCiclista;
    }
    
    /**
     * Asigna un nuevo orden al ArrayList de ciclistas.
     * 
     * @param _ordenCiclista es el nuevo orden de dicho ArrayList.
     */
    public void setOrdenCiclista(boolean _ordenCiclista)
    {            
        ordenCiclista = _ordenCiclista;  
    }
    
    /**
     * Establece un nuevo comparador de bicicletas.
     * 
     * @param _compBicicleta es el nuevo comparador.
     * @param _ordenBicicleta es el nuevo orden.
     */
    public void setComparadorBicicletas(Comparator <Bicicleta> _compBicicleta, boolean _ordenBicicleta)
    {
        compBicicleta = _compBicicleta;
        ordenBicicleta = _ordenBicicleta;
    }
    
    /**
     * Asigna un nuevo orden al ArrayList de bicicletas.
     * 
     * @param _ordenBicicleta es el nuevo orden de dicho ArrayList.
     */
    public void setOrdenBicicleta(boolean _ordenBicicleta)
    {            
        ordenBicicleta = _ordenBicicleta;  
    }
    
    /**
     * Ordena los ciclistas por el comparador indicado. 
     */
    protected void ordenarCiclistas() // Protegido porque es un método utilizado en las pruebas
    {
        if(ordenCiclista)
        {
            Collections.sort(ciclistas, compCiclista);
        }
        else
        {
            Collections.sort(ciclistas, Collections.reverseOrder(compCiclista));
        }
    }
    
    /**
     * Ordena los ciclistas que han abandonado por el comparador indicado. 
     */
    private void ordenarCiclistasAbandonado()
    {
        if(ordenCiclista)
        {
            Collections.sort(ciclistas, compCiclista);
        }
        else
        {
            Collections.sort(ciclistas, Collections.reverseOrder(compCiclista));
        }
    }
    
    /**
     * Ordena las bicicletas por el comparador indicado.
     */
    private void ordenarBicicletas()
    {
        if(ordenBicicleta)
        {
            Collections.sort(bicicletas, compBicicleta);
        }
        else
        {
            Collections.sort(bicicletas, Collections.reverseOrder(compBicicleta));
        }
    }
    
    /**
     * Obtiene el tiempo total que ha acumulado el equipo.
     * 
     * @return el tiempo total que ha acumulado el equipo.
     */
    private double tiempoTotalEquipo()
    {
        double total = 0;
        double tiempo = 0;
        
        for (Ciclista ciclista : ciclistas)
        {
            tiempo = ciclista.tiempoTotal();
            total = total + tiempo;
        }
        return total;
    }
    
    /**
     * Devuelve el siguiente ciclista del equipo y lo elimina del ArrayList ciclistas (para mandarlo a Organizacion).
     * 
     * @return el siguiente ciclista.
     */
    public Ciclista siguienteCiclista()
    {
        Ciclista c = null;
        if (ciclistas.size() > 0)
        {
            c = ciclistas.get(0);
            if (c.getBicicleta() != null)
                borrarCiclista(c);
            else
                c = null;
        }
        return c;
    }
    
    /**
     * Devuelve el siguiente ciclista que ha abandonado del equipo y lo elimina del ArrayList ciclistasAbandonado (para mandarlo a Organizacion).
     * 
     * @return el siguiente ciclista que ha abandonado.
     */
    public Ciclista siguienteCiclistaAbandonado()
    {
        Ciclista c = null;
        if (ciclistasAbandonado.size() > 0)
        {
            c = ciclistasAbandonado.get(0);
            borrarCiclistaAbandonado(c);
        }
        return c;
    }
    
    /**
     * Recupera los ciclistas de la organizacion y los inserta en el Arraylist correspondiente.
     * 
     * @param _ciclista el ciclista a devolver a su equipo.
     */
    public void devolverCiclista(Ciclista _ciclista)
    {
        if (!_ciclista.abandonado())
            anadirCiclista(_ciclista);
        else
            anadirCiclistaAbandonado(_ciclista);
    }
    
    /**
     * Devuelve la media de tiempo acumulado por los ciclistas del equipo.
     * 
     * @return la media de tiempo.
     */
    public double mediaTiempoCiclistas()
    {
        double media = Math.round((tiempoTotalEquipo() / ciclistas.size()) * 100d) / 100d;
        return media;    
    }
    
    /**
     * Muestra el equipo y todos sus ciclistas.
     * 
     * @param writer es el buffer del fichero de salida.
     */
    public void mostrarEquipo(BufferedWriter writer)
    {        
        ordenarCiclistas();
        ordenarCiclistasAbandonado();
        escribirLinea("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n" +        
        "%%% " + nombre + " %%% Media Minutos de Ciclistas sin abandonar " + mediaTiempoCiclistas() + " %%%\n\n", writer);
        
        for(Ciclista ciclista : ciclistas)
            escribirLinea(ciclista.toString(), writer);
        for (Ciclista ciclista : ciclistasAbandonado)
            escribirLinea(ciclista.toString(), writer);
            
        escribirLinea("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n", writer);
    }
    
    /**
     * Asigna las bicicletas a los ciclistas.
     */
    public void asignarBicicletas()
    {
        int i;
        
        ordenarBicicletas();
        ordenarCiclistas();
        for (i = 0; i < bicicletas.size(); i++)
        {
            if (i < ciclistas.size())
                ciclistas.get(i).setBicicleta(bicicletas.get(i));
        }
        for (i = bicicletas.size(); i < ciclistas.size(); i++)
        {
            ciclistas.get(i).setBicicleta(null);        
        }
    }
}    
    