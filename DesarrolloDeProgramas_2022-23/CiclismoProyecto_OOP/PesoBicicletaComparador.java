
import java.util.*;

/**
 * La clase "PesoBicicletaComparador" sirve para comparar el peso de una bicicleta con la de otra.
 * 
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz.
 * @versión 12/12/2022
 */
public class PesoBicicletaComparador implements Comparator<Bicicleta>
{
    /**
     * Compara el peso de una bicicleta con el peso de otra.
     * 
     * @param b1 es la primera bicicleta a comparar.
     * @param b2 es la segunda bicicleta a comparar.
     */
    public int compare(Bicicleta b1, Bicicleta b2)
    {
        if(b1.getPeso() == b2.getPeso())
            return b1.getNombre().compareTo(b2.getNombre());
        else
            if(b1.getPeso() > b2.getPeso())
                return 1;
            else
                return -1;
    }
}
