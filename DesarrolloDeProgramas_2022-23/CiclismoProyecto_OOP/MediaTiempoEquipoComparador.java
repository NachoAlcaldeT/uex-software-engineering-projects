
import java.util.*;

/**
 * La clase "MediaTiempoEquipoComparador" sirve para comparar la media de tiempo acumulado por un equipo con la de otro.
 * 
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz.
 * @versión 12/12/2022
 */
public class MediaTiempoEquipoComparador implements Comparator<Equipo>
{
    /**
     * Compara la media de tiempo acumulada por un equipo con la media de tiempo acumulada por el otro.
     * 
     * @param e1 es el primer equipo a comparar.
     * @param e2 es el segundo equipo a comparar.
     */
    public int compare(Equipo e1, Equipo e2)
    {
        if(e1.mediaTiempoCiclistas() == e2.mediaTiempoCiclistas())
            return e1.getNombre().compareTo(e2.getNombre());
        else
            if(e1.mediaTiempoCiclistas() > e2.mediaTiempoCiclistas())
                return 1;
            else
                return -1;
    }
}
