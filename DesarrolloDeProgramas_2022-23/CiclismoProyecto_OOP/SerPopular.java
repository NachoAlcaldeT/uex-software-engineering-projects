
/**
 * La interface SerPopular aumenta o disminuye la popularidad de los ciclistas en redes sociales.
 * 
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz.
 * @versión 12/12/2022
 */

public interface SerPopular
{
    /**
     * Incrementa la popularidad de un ciclista.
     */
    public void aumentarPopularidad();
    
    /**
     * Decrementa la popularidad de un ciclista.
     */
    public void disminuirPopularidad();
    
    /**
     * Devuelve la popularidad de un ciclista.
     */
    public int getPopularidad();
}
