
import java.util.*;

/**
 * La clase "HabilidadCiclistaComparador" sirve para comparar la habilidad de un ciclista con la de otro.
 * 
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz.
 * @versión 12/12/2022
 */
public class HabilidadCiclistaComparador implements Comparator<Ciclista>
{
    /**
     * Compara la habilidad de un ciclista con la habilidad de otro.
     * 
     * @param c1 es el primer ciclista a comparar.
     * @param c2 es el segundo ciclista a comparar.
     */
    public int compare(Ciclista c1, Ciclista c2)
    {
        if(c1.getHabilidad() == c2.getHabilidad())
            return c1.getNombre().compareTo(c2.getNombre());
        else
            if(c1.getHabilidad() > c2.getHabilidad())
                return 1;
            else
                return -1;
    }
}
