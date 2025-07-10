
import java.util.*;

/**
 * La clase "TotalTiempoCiclistaComparador" sirve para comparar el tiempo total que ha corrido un ciclista con el de otro.
 * 
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz.
 * @versión 12/12/2022
 */
public class TotalTiempoCiclistaComparador implements Comparator<Ciclista>
{
    /**
     * Compara el tiempo total que ha corrido un ciclista con el tiempo total que ha corrido el otro.
     * 
     * @param c1 es el primer ciclista a comparar.
     * @param c2 es el segundo ciclista a comparar.
     */
    public int compare(Ciclista c1, Ciclista c2)
    {
        if(c1.tiempoTotal() == c2.tiempoTotal())
            return c1.getNombre().compareTo(c2.getNombre());
        else
            if(c1.tiempoTotal() > c2.tiempoTotal())
                return 1;
            else
                return -1;
    }
}
