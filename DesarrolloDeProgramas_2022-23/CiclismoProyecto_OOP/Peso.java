
/**
 * El enum "Peso" representa los distintos tipos de pesos de las bicicletas.
 * 
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz.
 * @versión 12/12/2022
 */
public enum Peso
{
  LIGERA ("Ligera", 7.35),
  NORMAL ("Normal", 7.50),
  PESADA ("Pesada", 7.85);
  
  private final String nombre;
  private final double valor;
  
  /**
   * Constructor parametrizado del enum Peso.
   * 
   * @param _nombre es el nombre del tipo de peso.
   * @param _valor es el valor del tipo de peso.
   */
  Peso(String _nombre,double _valor)
  {
      nombre = _nombre;
      valor = _valor;
  }
  
  /**
   * Devuelve el nombre del tipo de peso.
   * 
   * @return el tipo de peso.
   */
  public String getNombre()
  {
      return nombre;
  }
  
  /**
   * Devuelve el valor del tipo de peso.
   * 
   * @return el valor del peso.
   */
  public double getValor()
  {
     return valor;  
  }
  
  /**
   * Muestra el peso.
   * 
   * @return los datos del peso.
   */
  @Override
  public String toString()
  {
      return "peso: " + nombre + " (valor: " + valor + ")"; 
  }
}
