
/**
 * La clase "Bicicleta" representa a las distintas bicicletas que los Ciclistas pueden usar en las Etapas.
 * 
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz. 
 * @versión 12/12/2022
 */
public class Bicicleta
{
    public String nombre;
    public Peso peso;

    /**
     * Constructor para objetos de la clase Bicicleta.
     */
    public Bicicleta()
    {
        nombre = "";
    }
    
    /**
     * Constructor parametrizado para objetos de la clase Bicicleta.
     * 
     * @param _nombre es el nombre de la bicicleta.
     * @param _peso es el peso de la bicicleta.
     */
    public Bicicleta(String _nombre, Peso _peso) throws IllegalArgumentException
    {
        nombre = _nombre;
        peso = _peso;
        
        if (_nombre.length() == 0 || _peso == null)
            throw new IllegalArgumentException("Alguno de los argumentos está vacío.");
    }
    
    /**
     * Compara un objeto con esta bicicleta y devuelve true si son iguales false en caso contrario.
     *
     * @param obj es el objeto a comparar.
     * 
     * @return true si los objetos son iguales y false en caso contrario.
     */
    @Override
    public boolean equals(Object obj)
    {
        if(this == obj) return true;
        if (!(obj instanceof Bicicleta)) return false;
        Bicicleta other = (Bicicleta) obj;
        return (getNombre().equals(other.getNombre()) && getPeso() == other.getPeso());
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
     * Asigna un nuevo nombre a la bicicleta.
     * 
     * @param _nombre es el nuevo nombre de la bicicleta.
     */
    public void setNombre(String _nombre)
    {
        nombre = _nombre;
    }
    
    /**
     * Obtiene el nombre de la bicicleta.
     * 
     * @return el nombre de la bicicleta.
     */
    public String getNombre()
    {
        return nombre;
    }
    
    /**
     * Asigna un nuevo peso a la bicicleta.
     * 
     * @param _peso es el nuevo peso de la bicicleta.
     */
    public void setPeso(Peso _peso)
    {
       peso = _peso;
    }
    
    /**
     * Obtiene el peso de la bicicleta.
     * 
     * @return el peso de la bicicleta.
     */
    public double getPeso()
    {
        return peso.getValor();
    }
    
    /**
     * Calcula la velocidad de la bicicleta cuando es usada por un ciclista en una etapa.
     * 
     * @param c es el ciclista que utiliza la bicicleta.
     * @param e es la etapa en la que corre el ciclista con dicha bicicleta.
     * 
     * @return velocidad de la bicicleta.
     */
    public double velocidad(Ciclista c, Etapa e)
    {
        double v;        
        v = Math.round(((c.getHabilidad() * 100) / (peso.getValor() * e.getDificultad())) * 100d) / 100d;        
        return v;
    }
    
    /**
     * Calcula el tiempo (en minutos) necesario para terminar una etapa para un ciclista concreto y una etapa concreta.
     * 
     * @param c es el ciclista que utiliza la bicicleta.
     * @param e es la etapa en la que corre la bicicleta.
     * 
     * @return tiempo necesario para terminar una etapa para un ciclista concreto y una etapa concreta.
     */
    public double tiempoEtapa(Ciclista c, Etapa e)
    {
        double tiempo;
        tiempo = Math.round(((e.getDistancia() / velocidad(c, e)) * 60) * 100d) / 100d;
        return tiempo;
    }
    
    /**
     * Muestra la bicicleta.
     * 
     * @return la bicicleta.
     */
    @Override
    public String toString()
    {
        return "<BicicletaNormal>" +" <"+peso+">";
    }    
}