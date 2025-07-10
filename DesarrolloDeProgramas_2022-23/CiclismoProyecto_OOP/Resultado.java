
/**
 * La clase "Resultado" representa el tiempo obtenido por cada Ciclista en cada Etapa.
 * 
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz.
 * @versión 12/12/2022
 */
public class Resultado
{
    private double tiempo;
    private Etapa etapa;

    /**
     * Constructor para objetos de la clase Resultado.
     */
    public Resultado()
    {
        tiempo = 0;
    }
    
    /**
     * Constructor parametrizado para objetos de la clase Resultado.
     * 
     * @param _tiempo es el resultado en tiempo.
     * @param _etapa es la etapa de la que se guarda el resultado.
     */
    public Resultado(double _tiempo, Etapa _etapa)
    {
        tiempo = _tiempo;
        etapa = _etapa;
    }

    /**
     * Compara un objeto con este resultado y devuelve true si son iguales false en caso contrario.
     *
     * @param obj es el objeto a comparar.
     * 
     * @return true si los objetos son iguales y false en caso contrario.
     */
    @Override
    public boolean equals(Object obj)
    {
        if(this == obj) return true;
        if (!(obj instanceof Resultado)) return false;
        Resultado other = (Resultado) obj;
        return (getEtapa().equals(other.getEtapa()) && getTiempo() == other.getTiempo());
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
        res = 3 * res + getEtapa().hashCode();
        return res;
    }
    
    /**
     * Asigna un nuevo tiempo al resultado.
     * 
     * @param _tiempo es el nuevo tiempo del resultado.
     */
    public void setTiempo(double _tiempo)
    {
        tiempo = _tiempo;
    }
    
    /**
     * Obtiene el tiempo del resultado.
     * 
     * @return el tiempo del resultado.
     */
    public double getTiempo()
    {
        return tiempo;
    }
    
    /**
     * Asigna una nueva etapa al resultado (tiempo que se ha tardado en recorrerla).
     * 
     * @param _etapa es la nueva etapa del resultado.
     */
    public void setEtapa(Etapa _etapa)
    {
        etapa = _etapa;
    }
    
    /**
     * Obtiene la etapa de la que se tiene el resultado en tiempo.
     * 
     * @return la etapa de la que se tiene el resultado en tiempo.
     */
    public Etapa getEtapa()
    {
        return etapa;
    }
    
    /**
     * Muestra el resultado de una etapa.
     * 
     * @return el resultado de una etapa.
     */
    @Override
    public String toString()
    {
        return ("Carrera(" + etapa.getNombre() + ") - Tiempo: " + tiempo + " minutos\n");
    }
}
