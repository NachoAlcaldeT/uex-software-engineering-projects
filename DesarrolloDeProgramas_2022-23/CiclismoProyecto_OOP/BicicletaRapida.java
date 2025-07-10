
/**
 * La clase "BicicletaRapida" representa a las bicicletas de tipo rapida.
 * 
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz.
 * @versión 12/12/2022
 */
public class BicicletaRapida extends Bicicleta
{
    private double velocidadExtra;
    
    /**
     * Constructor para objetos de la clase BicicletaRapida.
     */
    public BicicletaRapida()
    {
        super();
        velocidadExtra = 0;
    }
    
    /**
     * Constructor parametrizado para objetos de la clase BicicletaRapida.
     * 
     * @param _nombre es el nombre de la bicicleta.
     * @param _peso es el peso de la bicicleta.
     * @param _velocidadExtra es la velocidad extra de la bicicleta.
     */
    public BicicletaRapida(String _nombre, Peso _peso, double _velocidadExtra)
    {
        super(_nombre,_peso);
        velocidadExtra = _velocidadExtra;
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
        return super.equals(obj);
    }
    
    /**
     * Devuelve el código hash del objeto.
     * 
     * @return el código hash.
     */
    @Override
    public int hashCode()
    {
        return super.hashCode();
    }
    
    /**
     * Calcula la velocidad de la bicicleta cuando es usada por un ciclista en una etapa.
     * 
     * @param c es el ciclista que utiliza la bicicleta.
     * @param e es la etapa en la que corre el ciclista con dicha bicicleta.
     * 
     * @return velocidad de la bicicleta.
     */
    @Override
    public double velocidad(Ciclista c, Etapa e)
    {
        double velocidad = Math.round((super.velocidad(c, e) + velocidadExtra) * 100d) / 100d;
        return velocidad;
    }
    
    /**
     * Muestra la bicicleta.
     * 
     * @return la bicicleta.
     */
    @Override
    public String toString()
    {
        return "<BicicletaRapida>"+ " <" + peso + ">";
    }
}
