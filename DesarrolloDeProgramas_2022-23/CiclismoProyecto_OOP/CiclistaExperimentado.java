import java.util.ArrayList;

/**
 * La clase "CiclistaNovato" representa a los ciclistas de tipo expeerimentado.
 * 
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz.
 * @versión 12/12/2022
 */

public class CiclistaExperimentado extends Ciclista 
{
    /**
     * Constructor para objetos de la clase CiclistaExperimentado.
     */
    public CiclistaExperimentado()
    {
        super();
    }
    
    /**
     * Constructor parametrizado para objetos de la clase CiclistaExperimentado.
     * 
     * @param _nombre es el nombre del ciclista.
     * @param _habilidad es la habilidad del ciclista.
     * @param _energia es la energía del ciclista.
     * @param _equipo es el equipo del ciclista.
     */
    public CiclistaExperimentado(String _nombre, Habilidad habilidad, double _energia, Equipo _equipo)
    {
        super(_nombre, habilidad, _energia, _equipo);
    }
    
    /**
     * Compara un objeto con este ciclista y devuelve true si son igualesy false en caso contrario.
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
     * Calcula la destreza del ciclista.
     * 
     * @return la destreza del ciclista.
     */
    @Override
    public double destreza()
    {
        double d = Math.round((((habilidad.getValor() + 4.0) / 130) * 10) * 100d) / 100d;
        return d;
    }
    
    /**
     * Muestra el ciclista. 
     * 
     * @return los datos del ciclista.
     */
    @Override
    public String toString()
    {
        return super.toString();
    }
}
