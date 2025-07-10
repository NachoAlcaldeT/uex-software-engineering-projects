
import java.util.*;

/**
 * La clase "NombreEquipoComparador" sirve para comparar el nombre de un equipo con el de otro.
 * 
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz.
 * @versión 12/12/2022
 */
public class NombreEquipoComparador implements Comparator<Equipo>
{
    /**
     * Compara el nombre de un equipo con el nombre del otro.
     * 
     * @param e1 es el primer equipo a comparar.
     * @param e2 es el segundo equipo a comparar.
     */
    public int compare(Equipo e1, Equipo e2)
    {
        return e1.getNombre().compareTo(e2.getNombre());
    }
}
