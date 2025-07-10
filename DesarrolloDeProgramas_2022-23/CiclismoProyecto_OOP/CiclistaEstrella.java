import java.util.ArrayList;
import java.io.*;

/**
 * La clase "CiclistaNovato" representa a los ciclistas de tipo estrella.
 * 
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz.
 * @versión 12/12/2022
 */

public class CiclistaEstrella extends Ciclista implements SerPopular
{
    private int popularidad;
    
    /**
     * Constructor para objetos de la clase CiclistaEstrella.
     */
    public CiclistaEstrella()
    {
        super();
        popularidad = 6;
    }
    
    /**
     * Constructor parametrizado para objetos de la clase CiclistaEstrella.
     * 
     * @param _nombre es el nombre del ciclista.
     * @param _habilidad es la habilidad del ciclista.
     * @param _energia es la energía del ciclista.
     * @param _equipo es el equipo del ciclista.
     */
    public CiclistaEstrella(String _nombre, Habilidad habilidad, double _energia, Equipo _equipo)
    {
        super(_nombre, habilidad, _energia, _equipo);
        popularidad = 6;
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
     * Escribe una línea en el fichero de salida.
     * 
     * @param linea es la línea que se desea escribir.
     * @param writer es el buffer del fichero de salida.
     */
    private void escribirLinea(String linea, BufferedWriter writer) {
        try {
            writer.write(linea); 
        }
        catch(IOException e) {
            System.out.println("No se puede escribir la línea.");
        }
    }
    
    /**
     * Calcula la destreza del ciclista.
     * 
     * @return la destreza del ciclista.
     */
    @Override
    public double destreza()
    {
        double d = Math.round((((habilidad.getValor() + 6.0) / 140) * 10) *100d)/100d;
        return d;
    }
    
    /**
     * Incrementa la popularidad del ciclista.
     */
    @Override
    public void aumentarPopularidad()
    {
        popularidad = popularidad + 4;
    }
    
    /**
     * Decrementa la popularidad del ciclista.
     */
    @Override
    public void disminuirPopularidad()
    {
        popularidad--;
    }
    
    /**
     * Devuelve la popularidad del ciclista.
     */
    @Override
    public int getPopularidad()
    {
        return popularidad;
    }
    
    /**
     * Guarda los resultados del ciclista en una etapa (hace la carrera) y actualiza la popularidad.
     * 
     * @param _etapa es la etapa que va a correr el ciclista.
     * @param writer es el buffer del fichero de salida.
     */
    @Override
    public void hacerCarrera(Etapa _etapa, BufferedWriter writer)
    {
        super.hacerCarrera(_etapa, writer);
        double tiempo = consultarTiempoEtapa(_etapa);
        if (tiempo > 0 && tiempo < 160){
            aumentarPopularidad();
            escribirLinea("@@@\n" + "+++ La popularidad del ciclista " + nombre + " ha aumentado y ahora su nivel de popularidad es de: " +
            popularidad + " unidades\n", writer);
        }
        else{
            disminuirPopularidad();
            escribirLinea("@@@\n" + "--- La popularidad del ciclista " + nombre + " ha disminuido y ahora su nivel de popularidad es de: " +
            popularidad + " unidades\n", writer);
        }
    }
    
    /**
     * Muestra el ciclista. 
     * 
     * @return los datos del ciclista.
     */
    @Override
    public String toString()
    {
        return (super.toString() + "<popularidad: " + getPopularidad() + ">\n");
    }
}