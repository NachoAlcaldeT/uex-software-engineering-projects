
import java.util.*;

/**
 * La clase "DificultadEtapaComparador" sirve para comparar la dificultad de una etapa con la de otra.
 * 
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz.
 * @versión 12/12/2022
 */
public class DificultadEtapaComparador implements Comparator<Etapa>
{
    /**
     * Compara la dificultad de una etapa con la dificultad de otra.
     * 
     * @param e1 es la primera etapa a comparar.
     * @param e2 es la segunda etapa a comparar.
     */
    public int compare(Etapa e1, Etapa e2)
    {
        if(e1.getDificultad() == e2.getDificultad())
            return e1.getNombre().compareTo(e2.getNombre());
        else
            if(e1.getDificultad() > e2.getDificultad())
                return 1;
            else
                return -1;
    }
}
