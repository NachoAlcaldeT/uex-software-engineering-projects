
/**
 * La clase "BicicletaPrototipo" representa a las bicicletas de tipo prototipo.
 * 
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz.
 * @versión 12/12/2022
 */
public class BicicletaPrototipo extends Bicicleta 
{
    /**
     * Constructor para objetos de la clase BicicletaRapida.
     */
    public BicicletaPrototipo()
    {
        super();
    }
    
    /**
     * Constructor parametrizado para objetos de la clase BicicletaPrototipo.
     * 
     * @param _nombre es el nombre de la bicicleta.
     * @param _peso es el peso de la bicicleta.
     */
    public BicicletaPrototipo(String _nombre, Peso _peso)
    {
        super(_nombre,_peso);
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
     * Calcula el tiempo (en minutos) necesario para terminar una etapa para un ciclista concreto y una etapa concreta.
     * 
     * @param c es el ciclista que utiliza la bicicleta.
     * @param e es la etapa en la que corre la bicicleta.
     * 
     * @return tiempo necesario para terminar una etapa para un ciclista concreto y una etapa concreta.
     */
    @Override
    public double tiempoEtapa(Ciclista c, Etapa e)
    {
        double tiempo = Math.round((e.getDistancia() / (velocidad(c, e) * c.destreza())) * 100d) / 100d;
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
        return "<BicicletaPrototipo>" + " <" + peso + ">";
    }
}
