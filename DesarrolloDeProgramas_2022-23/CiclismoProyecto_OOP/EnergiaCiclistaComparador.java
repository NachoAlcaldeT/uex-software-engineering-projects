
import java.util.*;

/**
 * La clase "EnergiaCiclistaComparador" sirve para comparar la energía que tiene un ciclista con la que tiene otro.
 * 
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz.
 * @versión 12/12/2022
 */
public class EnergiaCiclistaComparador implements Comparator<Ciclista>
{
    /**
     * Compara la energía de un ciclista con la energía de otro.
     * 
     * @param c1 es el primer ciclista a comparar.
     * @param c2 es el segundo ciclista a comparar.
     */
    public int compare(Ciclista c1, Ciclista c2)
    {
        if(c1.getEnergia() == c2.getEnergia())
            return c1.getNombre().compareTo(c2.getNombre());
        else
            if(c1.getEnergia() > c2.getEnergia())
                return 1;
            else
                return -1;
    }
}
