
/**
 * El enum "Distancia" representa los distintos tipos de distancia de las etapas.
 * 
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz.
 * @versión 12/12/2022
 */
public enum Distancia
{
  CORTA ("Corta", 150.0),
  INTERMEDIA ("Intermedia", 200.0),
  LARGA ("Larga", 225.0);
  
  private final String nombre;
  private final double valor;
  
  /**
   * Constructor parametrizado del enum distancia.
   * 
   * @param _nombre es el nombre del tipo de distancia.
   * @param _valor es el valor del tipo de distancia.
   */
  Distancia(String _nombre,double _valor)
  {
      nombre = _nombre;
      valor = _valor;
  }
  
  /**
   * Devuelve el nombre del tipo de distancia.
   * 
   * @return el tipo de distancia.
   */
  public String getNombre()
  {
      return nombre;
  }
  
  /**
   * Devuelve el valor del tipo de distancia.
   * 
   * @return el valor de la distancia.
   */
  public double getValor()
  {
     return valor;  
  }
  
  /**
   * Muestra la distancia.
   * 
   * @return los datos de la distancia.
   */
  @Override
  public String toString()
  {
      return "<distancia:" + nombre + " (valor:" + valor + ")>";
  }
}
