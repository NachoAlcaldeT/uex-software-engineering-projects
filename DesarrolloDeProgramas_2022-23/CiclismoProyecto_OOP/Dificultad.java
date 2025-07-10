
/**
 * El enum "Dificultad" representa los distintos tipos de dificultad de las etapas.
 * 
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz.
 * @versión 12/12/2022
 */
public enum Dificultad
{    
  SENCILLA ("Sencilla", 0.9),
  NORMAL ("Normal", 1.0),
  COMPLEJA ("Compleja", 1.1);
  
  private final String nombre;
  private final double valor;
  
  /**
   * Constructor parametrizado del enum dificultad.
   * 
   * @param _nombre es el nombre del tipo de dificultad.
   * @param _valor es el valor del tipo de dificultad.
   */
  Dificultad(String _nombre,double _valor)
  {
      nombre = _nombre;
      valor = _valor;
  }
  
  /**
   * Devuelve el nombre del tipo de dificultad.
   * 
   * @return el tipo de dificultad.
   */
  public String getNombre()
  {
      return nombre;
  }
  
  /**
   * Devuelve el valor del tipo de dificultad.
   * 
   * @return el valor de la dificultad.
   */
  public double getValor()
  {
     return valor;  
  }
  
  /**
   * Muestra la dificultad.
   * 
   * @return los datos de la dificultad.
   */
  @Override
  public String toString()
  {
      return "<dificultad: " + nombre + " (valor: " + valor + ")>"; 
  }
}
