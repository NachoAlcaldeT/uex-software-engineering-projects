 
import java.util.*;
import java.io.*;

/**
 * La clase "Ciclista" representa a los ciclistas que competirán con sus Bicicletas cada Etapa.
 * 
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz.
 * @versión 12/12/2022
 */

public abstract class Ciclista
{
    public String nombre;
    public Bicicleta bicicleta;
    public Habilidad habilidad;
    public double energia;
    public List<Resultado> resultados;
    public Equipo equipo;
    public boolean abandono;
    
    /**
     * Constructor para objetos de la clase Ciclista.
     */
    public Ciclista()
    {
        nombre = "";
        bicicleta = null;
        energia = 0;
        resultados = new ArrayList<Resultado>();
        abandono = false;
    }
        
    /**
     * Constructor parametrizado para objetos de la clase Ciclista.
     * 
     * @param _nombre es el nombre del ciclista.
     * @param _habilidad es el nivel de habilidad del ciclista.
     * @param _energia es la energia del ciclista.
     * @param _equipo es el equipo al que pertenece el ciclista.
     * @throws IllegalArgumentException si alguno de los argumentos está vacío.
     */
    public Ciclista(String _nombre, Habilidad _habilidad, double _energia, Equipo _equipo) throws IllegalArgumentException
    {
        nombre = _nombre;
        bicicleta = null;
        habilidad = _habilidad;
        energia = _energia;
        resultados = new ArrayList<Resultado>();
        equipo = _equipo;
        abandono = false;
        
        if (_nombre.length() == 0 || _habilidad == null || _energia == 0 || _equipo == null)
            throw new IllegalArgumentException("Alguno de los argumentos está vacío.");
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
     * Compara un objeto con este ciclista y devuelve true si son igualesy false en caso contrario.
     *
     * @param obj es el objeto a comparar.
     * 
     * @return true si los objetos son iguales y false en caso contrario.
     */
    @Override
    public boolean equals(Object obj)
    {
        if(this == obj) return true;
        if (!(obj instanceof Ciclista)) return false;
        Ciclista other = (Ciclista) obj;
        return (getNombre().equals(other.getNombre()) && getHabilidad() == other.getHabilidad() && getEnergia() == other.getEnergia());
    }
    
    /**
     * Devuelve el código hash del objeto.
     * 
     * @return el código hash.
     */
    @Override
    public int hashCode()
    {
        int res = 7;
        res = 3 * res + getNombre().hashCode();
        return res;
    }

    /**
     * Asigna un nuevo nombre al ciclista.
     *  
     * @param _nombre es el nuevo nombre del ciclista.
     */
    public void setNombre(String _nombre)
    {
        nombre = _nombre;        
    }
    
    /**
     * Obtiene el nombre del ciclista.
     *  
     * @return el nombre del ciclista.
     */
    public String getNombre()
    {
        return nombre;        
    }
        
    /**
     * Asigna un nuevo nivel de habilidad al ciclista.
     *
     * @param _habilidad es el nuevo nivel de habilidad del ciclista.
     */
    public void setHabilidad(Habilidad _habilidad)
    {
        habilidad = _habilidad;        
    }
    
    /**
     * Obtiene el nivel de habilidad del ciclista.
     *  
     * @return la habilidad del ciclista.
     */
    public double getHabilidad()
    {
        return habilidad.getValor();        
    }
    
    /**
     * Asigna una nueva energía al ciclista.
     * 
     * @param _energia es la nueva energía del ciclista.
     */
    public void setEnergia(double _energia)
    {   
        energia = _energia;        
    }
    
    /**
     * Obtiene la energía del ciclista.
     *  
     * @return energía del ciclista.
     */
    public double getEnergia()
    {        
        return energia;        
    }
    
    /**
     * Asigna una bicicleta al ciclista.
     *  
     * @param _bicicleta es la nueva bicicleta del ciclista.
     */
    public void setBicicleta(Bicicleta _bicicleta)
    {
        bicicleta = _bicicleta;        
    }
    
    /**
     * Devuelve la bicicleta del ciclista.
     * 
     * @return bicicleta del ciclista.
     */
    public Bicicleta getBicicleta()
    {
        return bicicleta;
    }
    
    /**
     * Asigna un equipo al ciclista.
     *  
     * @param _equipo es el nuevo equipo del ciclista.
     */
    public void setEquipo(Equipo _equipo)
    {
        equipo = _equipo;        
    }
    
    /**
     * Devuelve el equipo del ciclista.
     *  
     * @return equipo del ciclista.
     */
    public Equipo getEquipo()
    {
        return equipo;        
    }
    
    /**
     * Comprueba si el ciclista ha abandonado.
     * 
     * @return true si el ciclista ha abandonado y false en caso contrario.
     */
    public boolean abandonado()
    {
        return abandono;
    }
    
    /**
     * Consulta el resultado obtenido en una etapa específica por el ciclista.
     *
     * @param _etapa es la etapa de la que queremos saber el resultado del ciclista.
     * 
     * @return el tiempo (en minutos) que ha tardado el ciclista en realizar la etapa.
     */
    public double consultarTiempoEtapa(Etapa _etapa)
    {   
       double res = 0;
       boolean enc = false;
       int i = 0;
       
       Iterator<Resultado> it = resultados.iterator(); 
       while(!enc && it.hasNext())
       {
           Resultado r = it.next();
           if (r.getEtapa().equals(_etapa))
           {
               enc = true;
               res = Math.round((r.getTiempo()) * 100d) / 100d;
           }
       }
       
       return res;
    }
    
    /**
     * Obtiene el número de etapas que ha corrido el ciclista.
     * 
     * @return el número de etapas.
     */
    public int numTotalEtapas()
    {
        return resultados.size();
    }
    
    /**
     * Obtiene el número de etapas que ha terminado un ciclista.
     * 
     * @return el número de etapas terminadas.
     */
    public int numEtapasTerminadas()
    {
        int total = 0;
        double tiempo = 0;
        
        Iterator<Resultado> it = resultados.iterator();        
        while (it.hasNext())
        {
            Resultado resultado = it.next();
            tiempo = resultado.getTiempo();
            if (tiempo > 0)
                total++;
        }
        
        return total;
    }
    
    /**
     * Obtiene el tiempo total (en minutos) que ha corrido un ciclista.
     * 
     * @return el tiempototal (en minutos).
     */
    public double tiempoTotal()
    {
        double total = 0;
        double tiempo = 0;
        
        Iterator<Resultado> it = resultados.iterator();        
        while (it.hasNext())
        {
            Resultado resultado = it.next();
            tiempo = resultado.getTiempo();
            if (tiempo > 0)
                total = Math.round((total + tiempo) * 100d) / 100d;
        }
        
        return total;
    }
    
    /**
     * Obtiene la etapa en la que abandonó el ciclista.
     * 
     * @return la etapa.
     */
    public Etapa etapaAbandonada()
    {
        Resultado res;
        Etapa e = null;
        int tam = resultados.size();

        if (tam > 0)
        {
            res = resultados.get(tam - 1);
            e = res.getEtapa();
        }
        
        return e;
    }
    
    /**
     * Guarda los resultados del ciclista en una etapa (hace la carrera).
     * 
     * @param _etapa es la etapa que va a correr el ciclista.
     * @param writer es el buffer del fichero de salida.
     */
    public void hacerCarrera(Etapa _etapa, BufferedWriter writer)
    {
        if (bicicleta != null && abandono != true)
        {
            double tiempo = bicicleta.tiempoEtapa(this, _etapa);
            double e = energia;
            energia = Math.round((energia - tiempo) * 100d) / 100d;
            
            if (energia > 0) {
                Resultado resultado = new Resultado(tiempo, _etapa);
                resultados.add(resultado);
                escribirLinea("+++ Con estas condiciones el ciclista " + nombre + " con la bicicleta " + bicicleta.getNombre() +
                " alcanza una velocidad de " + bicicleta.velocidad(this, _etapa) + " km/hora +++\n" +
                "+++ " + nombre + " termina la etapa en " + tiempo + " minutos +++\n" +
                "+++ la energía del ciclista " + nombre + " tras la carrera es " + energia + " +++\n", writer);
            }
            else
            {
                abandono = true;
                Resultado resultado = new Resultado(energia, _etapa);
                resultados.add(resultado);
                escribirLinea("+++ Con estas condiciones el ciclista " + nombre + " con la bicicleta " + bicicleta.getNombre() +
                " alcanza una velocidad de " + bicicleta.velocidad(this, _etapa) + " km/hora +++\n" + "¡¡¡ El ciclista " + nombre + 
                " se quedó sin energia a falta de " + (-1*energia) + " minutos para terminar !!!\n" +
                "¡¡¡ En el momento de quedarse sin energia llevaba en carrera " + Math.round((energia+tiempo) * 100d) / 100d + " minutos !!!\n" +
                "+++ la energía del ciclista " + nombre + " tras la carrera es " + energia + " +++\n", writer);
            } 
        }
        else
        {
            abandono = true;
            escribirLinea("¡¡¡ El ciclista " + nombre + " no puede competir porque no tiene bicicleta !!!\n", writer);
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
        return ("<" + getClass().getName() + ":" + nombre + "> <energía: " + energia + "> " + habilidad + " <tiempo acumulado sin abandonar: " + tiempoTotal() + " minutos> <abandonado:" + abandono + ">\n");
    }
    
    /**
     * Obtiene el tiempo (en minutos) que consiguió el ciclista en su última carrera.
     * 
     * @return el tiempo (en minutos).
     */
    public double ultimoTiempo()
    {
        Resultado res;
        double tiempo = 0;
        int tamaño = resultados.size();
        
        if (tamaño > 0)
        {
            res = resultados.get(resultados.size() - 1);
            tiempo = res.getTiempo();
        }
        
        return tiempo;
    }
    
    /**
     * Muestra todos los resultados del ciclista.
     * 
     * @param writer es el buffer del fichero de salida.
     */
    public void mostrarResultados(BufferedWriter writer)
    {
        for (Resultado resultado : resultados)
        {
            escribirLinea(resultado.toString(), writer);
        }
    }
    
    /**
     * Calcula la destreza del ciclista.
     */
    public abstract double destreza();
}