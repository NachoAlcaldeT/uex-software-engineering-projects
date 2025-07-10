
/**
 * El enum "Habilidad" representa los distintos tipos de habilidad de los ciclistas.
 * 
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz.
 * @versión 12/12/2022
 */
public enum Habilidad
{
  BUENA ("Buena", 8.0),
  NORMAL ("Normal", 6.0),
  LENTA ("Lenta", 4.0);
  
  private final String nombre;
  private final double valor;
  
  /**
   * Constructor parametrizado del enum habilidad.
   * 
   * @param _nombre es el nombre del tipo de habilidad.
   * @param _valor es el valor del tipo de habilidad.
   */
  Habilidad(String _nombre,double _valor)
  {
      nombre = _nombre;
      valor = _valor;
  }
  
  /**
   * Devuelve el nombre del tipo de habilidad.
   * 
   * @return el tipo de habilidad.
   */
  public String getNombre()
  {
      return nombre;
  }
  
  /**
   * Devuelve el valor del tipo de habilidad.
   * 
   * @return el valor de la habilidad.
   */
  public double getValor()
  {
     return valor;  
  }
  
  /**
   * Muestra la habilidad.
   * 
   * @return los datos de la habilidad.
   */
  @Override
  public String toString()
  {
      return "<habilidad:" + nombre + " (valor:" + valor + ")>";
  }
}
