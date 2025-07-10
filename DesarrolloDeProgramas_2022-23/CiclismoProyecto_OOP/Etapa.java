
/**
 * La clase "Etapa" representa al recorrido donde competirán cada jornada los Ciclistas con sus Bicicletas.
 * 
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz.
 * @versión 12/12/2022
 */
public class Etapa
{
    private String nombre;
    private Dificultad dificultad;
    private Distancia distancia;
    
    /**
     * Constructor para objetos de la clase Etapa.
     */
    public Etapa()
    {
        nombre = "";
    }
    
    /**
     * Constructor parametrizado para objetos de la clase Etapa.
     * 
     * @param _nombre es el nombre de la etapa.
     * @param _dificultad es la dificultad de la etapa.
     * @param _distancia es la distancia de la etapa.
     */
    public Etapa(String _nombre, Dificultad _dificultad, Distancia _distancia )
    {
        nombre = _nombre;
        dificultad = _dificultad;
        distancia = _distancia;
    }
    
    /**
     * Compara un objeto con esta etapa y devuelve true si son iguales false en caso contrario.
     *
     * @param obj es el objeto a comparar.
     * 
     * @return true si los objetos son iguales y false en caso contrario.
     */
    @Override
    public boolean equals(Object obj)
    {
        if(this == obj) return true;
        if (!(obj instanceof Etapa)) return false;
        Etapa other = (Etapa) obj;
        return (getNombre().equals(other.getNombre()) && getDistancia() == other.getDistancia() && getDificultad() == other.getDificultad());
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
     * Asigna un nuevo nombre a la etapa.
     * 
     * @param _nombre es el nuevo nombre de la etapa.
     */
    public void setNombre(String _nombre)
    {
        nombre = _nombre;
    }
    
    /**
     * Obtiene el nombre de la etapa.
     * 
     * @return el nombre de la etapa.
     */
    public String getNombre()
    {
        return nombre;
    }
    
    /**
     * Asigna una nueva distancia a la etapa.
     * 
     * @param _distancia es la nueva distancia de la etapa.
     */
    public void setDistancia(Distancia _distancia)
    {
       distancia = _distancia;
    }
    
    /**
     * Obtiene la distancia de la etapa.
     * 
     * @return la distancia de la etapa.
     */
    public double getDistancia()
    {
       return distancia.getValor();
    }
    
    /**
     * Asigna una nueva dificultad a la etapa.
     * 
     * @param _dificultad es la nueva dificultad de la etapa.
     */
    public void setDificultad(Dificultad _dificultad)
    {
       dificultad = _dificultad;
    }
    
    /**
     * Obtiene la dificultad de la etapa.
     * 
     * @return la dificultad de la etapa.
     */
    public double getDificultad()
    {
       return dificultad.getValor();
    }
    
    /**
     * Muestra los datos de la etapa.
     * 
     * @return los datos de la etapa.
     */
    @Override
    public String toString()
    {        
         return ("<etapa:" + nombre + "> <dificultad:" + dificultad.getNombre() + " (valor: "+ dificultad.getValor() + ")> <distancia:" + distancia.getNombre() + " (valor: " + distancia.getValor()+ ")>");
    }
}
