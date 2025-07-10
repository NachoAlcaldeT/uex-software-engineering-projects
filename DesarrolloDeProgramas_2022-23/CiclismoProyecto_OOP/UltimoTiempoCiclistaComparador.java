
import java.util.*;

/**
 * La clase "UltimoTiempoCiclistaComparador" sirve para comparar el último tiempo que ha conseguido un ciclista con el de otro.
 * 
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz.
 * @versión 12/12/2022
 */
public class UltimoTiempoCiclistaComparador implements Comparator<Ciclista>
{
    /**
     * Compara el último tiempo que ha conseguido un ciclista con el último tiempo que ha conseguido el otro.
     * 
     * @param c1 es el primer ciclista a comparar.
     * @param c2 es el segundo ciclista a comparar.
     */
    public int compare(Ciclista c1, Ciclista c2)
    {
        if(c1.ultimoTiempo() == c2.ultimoTiempo())
            return c1.getNombre().compareTo(c2.getNombre());
        else
            if(c1.ultimoTiempo() > c2.ultimoTiempo())
                return 1;
            else
                return -1;
    }    
}
