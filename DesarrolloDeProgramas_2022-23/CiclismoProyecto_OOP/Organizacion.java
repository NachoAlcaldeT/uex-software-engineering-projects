
import java.util.*;
import java.io.*;

/**
 * La clase "Organizacion" representa a la clase capaz de gestionar el campeonato.
 * 
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz. 
 * @versión 12/12/2022
 */
public class Organizacion
{
    private Set<Etapa> etapas;
    private List<Equipo> equipos;
    private Map<Ciclista, Equipo> ciclistasCarrera;
    private List<Ciclista> ciclistasCarreraAbandonado;
    private Comparator <Etapa> compEtapa;
    private boolean ordenEtapa;
    private Comparator <Equipo> compEquipo;
    private boolean ordenEquipo;
    private Comparator <Ciclista> compCiclista;
    private boolean ordenCiclista;
    private BufferedWriter writer;
    
    /**
     * Constructor para objetos de la clase Organizacion.
     */
    public Organizacion()
    {
        etapas = new TreeSet<Etapa>(compEtapa);
        equipos = new ArrayList<>();
        ciclistasCarrera = new HashMap<>();
        ciclistasCarreraAbandonado = new ArrayList<>();
        ordenEtapa = true;
        ordenEquipo = true;
        ordenCiclista = true;
        try {
            writer = new BufferedWriter(new FileWriter("SalidaDatosCampeonato.txt"));
        }
        catch(IOException e) {
            System.out.println("No se puede abrir el fichero.");
        }
    }
    
    /**
     * Constructor parametrizado para objetos de la clase Organizacion.
     * 
     * @param _compEtapa es el comparador de etapas.
     * @param _ordenEtapa es el método de ordenación de las etapas (true para ascendente, false para descendente).
     */
    public Organizacion(Comparator <Etapa> _compEtapa, boolean _ordenEtapa)
    {
        etapas = new TreeSet<Etapa>(_compEtapa);
        equipos = new ArrayList<>();
        ciclistasCarrera = new HashMap<>();
        ciclistasCarreraAbandonado = new ArrayList<>();
        compEtapa = _compEtapa;
        ordenEtapa = _ordenEtapa;
        ordenEquipo = true;
        ordenCiclista = true;
        try {
            writer = new BufferedWriter(new FileWriter("SalidaDatosCampeonato.txt"));
        }
        catch(IOException e) {
            System.out.println("No se puede abrir el fichero.");
        }
    }
    
    /**
     * Escribe una línea en el fichero de salida.
     * 
     * @param linea es la línea que se desea escribir.
     */
    private void escribirLinea(String linea) {
        try {
            writer.write(linea); 
        }
        catch(IOException e) {
            System.out.println("No se puede escribir la línea.");
        }
    }
    
    /**
     * Establece un nuevo comparador de equipos.
     * 
     * @param _compEquipo es el nuevo comparador.
     * @param _ordenEquipo es el nuevo orden.
     */
    private void setComparadorEquipos(Comparator <Equipo> _compEquipo, boolean _ordenEquipo)
    {
        compEquipo = _compEquipo;
        ordenEquipo = _ordenEquipo;
    }
    
    /**
     * Asigna un nuevo orden a los equipos.
     * 
     * @param _ordenEquipo es el nuevo orden.
     */
    private void setOrdenEquipo(boolean _ordenEquipo)
    {            
        ordenEquipo = _ordenEquipo;  
    }
    
    /**
     * Establece un nuevo comparador de ciclistas.
     * 
     * @param _compCiclista es el nuevo comparador.
     * @param _ordenCiclista es el nuevo orden.
     */
    private void setComparadorCiclistas(Comparator <Ciclista> _compCiclista, boolean _ordenCiclista)
    {
        compCiclista = _compCiclista;
        ordenCiclista = _ordenCiclista;
    }
    
    /**
     * Asigna un nuevo orden al ArrayList de ciclistas.
     * 
     * @param _ordenEquipo es el nuevo orden.
     */
    private void setOrdenCiclista(boolean _ordenCiclista)
    {            
        ordenCiclista = _ordenCiclista;  
    }
    
    /**
     * Ordena los ciclistas que han abandonado la carrera.
     */
    private void ordenarCiclistasAbandonado()
    {
        if(ordenCiclista)
        {
            Collections.sort(ciclistasCarreraAbandonado, compCiclista);
        }
        else
        {
            Collections.sort(ciclistasCarreraAbandonado, Collections.reverseOrder(compCiclista));
        }
    }
    
    /**
     * Añade una etapa al Set de etapas.
     * 
     * @param e es la etapa añadida.
     */
    public void anadirEtapa(Etapa e)
    {      
        etapas.add(e);
    }
    
    /**
     * Añade un equipo al Arraylist de equipos.
     * 
     * @param e es el equipo inscrito.
     */
    public void inscribirEquipo(Equipo e)
    {      
        equipos.add(e);
    }
    
    /**
     * Devuelve el número de equipos que compiten.
     * 
     * @return número de equipos en la competición.
     */
    protected int numEquipos() // Protegido porque es un método utilizado en las pruebas
    {
        return equipos.size();
    }
    
    /**
     * Gestiona el campeonato completo.
     */
    public void gestionarCampeonato()
    {
        Etapa etapa;
        int i = 1;
        boolean fin = false;
        
        mostrarEtapas();
        setComparadorEquipos(new NombreEquipoComparador(), true);
        ordenarEquipos();
        mostrarEquipos();
        
        Iterator <Etapa> it = etapas.iterator();
        while(it.hasNext() && !fin){
            etapa = it.next();
            for(Equipo equipo : equipos)
                equipo.asignarBicicletas();
            anadirCiclistas();
            anadirCiclistasAbandonado();
            if (ciclistasCarrera.size() > 1)
            {
                escribirLinea("\n********************************************************************************************************\n" +
                "*** CARRERA<"+ i +"> EN "+ etapa + " ***\n" +
                "********************************************************************************************************\n" +
                "********************************************************************************************************\n" +
                "******************************** Ciclistas que van a competir en "+ etapa.getNombre() + " *******************************\n" +
                "**********************************************************************************************************\n");
                mostrarCiclistas();
                escribirLinea("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n" + 
                "+++++++++++++++++++++++++ Comienza la carrera en " + etapa.getNombre() + " ++++++++++++++++++++++++++\n" + 
                "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
                competir(etapa);
            }
            else
            {
                fin = true;
            }
            devolverCiclistas();
            i++;
        }
        anadirCiclistas();
        anadirCiclistasAbandonado();
        
        mostrarFinCampeonato();
        try {
            writer.close();
        }
        catch(IOException e) {
            System.out.println("No se puede cerrar el fichero.");
        }
    }
    
    /**
     * Muestra todas las etapas.
     */
    private void mostrarEtapas()
    {   
        escribirLinea("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n" +
        "||||||||||||||||||| ETAPAS DEL CAMPEONATO |||||||||||||||||||\n" + "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        for(Etapa etapa : etapas)
        {
            escribirLinea(etapa.toString() + "\n");
        }
        escribirLinea("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    }
    
    /**
     * Muestra todos los equipos.
     */
    private void mostrarEquipos()
    { 
        escribirLinea("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n" + "%%%%%%%% EQUIPOS DEL CAMPEONATO %%%%%%%%\n" + "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
        for(Equipo equipo : equipos)
        {
            equipo.mostrarEquipo(writer);
        }
    }
    
    /**
     * Añade los ciclistas de los distintos equipos al Map de ciclistas y equipos.
     */
    protected void anadirCiclistas() // Protegido porque es un método utilizado en las pruebas
    {
        Ciclista c;
        
        for(Equipo equipo : equipos)
        {
            int num = equipo.numTotalCiclistas();
            for(int i = 0; i < num; i++)
            {
                c = equipo.siguienteCiclista();
                ciclistasCarrera.put(c, equipo);
            }
        }
    }
    
    /**
     * Comprueba que todavía hay ciclistas que pueden competir.
     * 
     * @return si hay ciclistas para competir.
     */
    protected boolean hayCiclistas() // Protegido porque es un método utilizado en las pruebas
    {
        boolean aux = false;
        if (ciclistasCarrera.size() > 0)
            aux = true;
        return aux;
    }
    
    /**
     * Añade los ciclistas que han abandonado de los distintos equipos al ArrayList de ciclistas abandonados.
     */
    private void anadirCiclistasAbandonado()
    {
        Ciclista c;
        
        for(Equipo equipo : equipos)
        {
            int num = equipo.numTotalCiclistasAbandonado();
            for(int i = 0; i < num; i++)
            {
                c = equipo.siguienteCiclistaAbandonado();
                ciclistasCarreraAbandonado.add(c);
            }
        }
    }
    
    /**
     * Muestra todos los ciclistas.
     */
    private void mostrarCiclistas()
    {
        List <Ciclista> claves = new ArrayList<>(ciclistasCarrera.keySet());
        Collections.sort(claves, Collections.reverseOrder(new TotalTiempoCiclistaComparador()));
        for(Ciclista ciclista : claves)
        {
             escribirLinea(ciclista.toString());
        }
    }
    
    /**
     * Gestiona cada carrera, es decir, hace que cada ciclista realice la etapa.
     * 
     * @param e es la etapa a realizar.
     */
    private void competir(Etapa e)
    {
        List <Ciclista> claves = new ArrayList<>(ciclistasCarrera.keySet());
        Collections.sort(claves, Collections.reverseOrder(new TotalTiempoCiclistaComparador()));
        Bicicleta b;
        
        for(int i = 0; i < claves.size(); i++)
        {
            b = claves.get(i).getBicicleta();
            if (b != null)
            {
                escribirLinea("@@@ ciclista " + (i+1) + " de " + claves.size() + "\n");
                escribirLinea(claves.get(i) + " con bicicleta\n" + b + " en etapa " + e.getNombre() + "\n");
                claves.get(i).hacerCarrera(e, writer);
                escribirLinea("@@@\n");
            }
            else
            {
                escribirLinea("@@@ ciclista " + (i+1) + " de " + claves.size() + "\n");
                escribirLinea(claves.get(i) + "\n");
                claves.get(i).hacerCarrera(e, writer);
            }
        }        
        mostrarClasificacionFinalEtapa(e);
    }
    
    /**
     * Muestra la clasificación final de la etapa realizada.
     * 
     * @param e es la etapa realizada.
     */
    private void mostrarClasificacionFinalEtapa(Etapa e)
    {
        List <Ciclista> claves = new ArrayList<>(ciclistasCarrera.keySet());
        Collections.sort(claves, new UltimoTiempoCiclistaComparador());
        escribirLinea("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n" +
        "+++++++++++++++++ Clasificación final de la carrera en "+ e.getNombre() + " ++++++++++++++++++\n" +
        "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");        
        
        int cont = 1;
        for(Ciclista ciclista : claves)
            if (ciclista.ultimoTiempo() > 0)
            {
                escribirLinea("@@@ Posición("+ cont + "):" + ciclista.getNombre() + " - Tiempo: " + ciclista.ultimoTiempo() + " minutos @@@\n");
                cont++;
            }
        for(Ciclista ciclista : claves)
            if (ciclista.ultimoTiempo() <= 0)
            {
                escribirLinea("¡¡¡ Ha abandonado " + ciclista.getNombre() + " - Tiempo: " +
                ciclista.ultimoTiempo() + " - Además ha abandonado para el resto del Campeonato !!!\n");
            }
    }
    
    /**
     * Devuelve los ciclistas a sus diferentes equipos.
     */
    private void devolverCiclistas()
    {
        Equipo e;
        Ciclista c;
        
        Set <Map.Entry<Ciclista, Equipo>> pares = ciclistasCarrera.entrySet();
        Iterator <Map.Entry<Ciclista, Equipo>> it = pares.iterator();
        while(it.hasNext())
        {
            c = it.next().getKey();
            e = ciclistasCarrera.get(c);
            e.devolverCiclista(c);
            it.remove();
        }
        while(ciclistasCarreraAbandonado.size() > 0)
        {
            c = ciclistasCarreraAbandonado.get(0);
            e = c.getEquipo(); 
            e.devolverCiclista(c);
            ciclistasCarreraAbandonado.remove(c);
        }
    }
    
    /**
     * Ordena los equipos que han participado en la carrera.
     */
    private void ordenarEquipos()
    {
        if(ordenEquipo)
        {
            Collections.sort(equipos, compEquipo);
        }
        else
        {
            Collections.sort(equipos, Collections.reverseOrder(compEquipo));
        }
    }
    
    /**
     * Muestra la clasificación final del campeonato.
     */
    private void mostrarFinCampeonato()
    {
        escribirLinea("****************************************************\n" +
        "**************** FIN DEL CAMPEONATO ****************\n" + "***************************************************\n");
        escribirLinea("*********** CLASIFICACIÓN FINAL DE CICLISTAS **********\n" + "****************************************************\n");
        int ind = 1;
        if (ciclistasCarrera.size() > 0)
        {
            List <Ciclista> claves = new ArrayList<>(ciclistasCarrera.keySet());
            Collections.sort(claves, new TotalTiempoCiclistaComparador());
            for(Ciclista ciclista : claves)
            {
                escribirLinea("@@@ Posición(" + ind + "): "+ ciclista.getNombre() +" -  Tiempo total: "+ ciclista.tiempoTotal() + " @@@\n");
                ciclista.mostrarResultados(writer);
                escribirLinea("\n");
                ind++;
            }
        }
        
        if (ciclistasCarreraAbandonado.size() > 0)
        {
            setComparadorCiclistas(new TotalTiempoCiclistaComparador(), true);
            ordenarCiclistasAbandonado();
            escribirLinea("****************************************************\n" + "************** CICLISTAS QUE ABANDONARON **************\n" +
            "****************************************************\n");
            for(Ciclista ciclista : ciclistasCarreraAbandonado)
            {
                escribirLinea("--- ciclista Abandonado: " + ciclista.getNombre() + " - Puntos Totales Anulados: " + ciclista.tiempoTotal() + " ---\n");
                ciclista.mostrarResultados(writer);
                escribirLinea("\n");
            }
        }
        
        escribirLinea("****************************************************\n" + "******** CLASIFICACIÓN FINAL DE EQUIPOS *********\n" + "****************************************************\n");
        if (ciclistasCarrera.size() > 0)
        {
            ind = 1;
            devolverCiclistas();
            setComparadorEquipos(new MediaTiempoEquipoComparador(), true);
            ordenarEquipos();
            for(int i = 0; i < equipos.size(); i++)
            {
                if (equipos.get(i).numTotalCiclistas() > 0)
                {
                    escribirLinea("@@@ Posición(" + ind + ") "+ equipos.get(i).getNombre() + " con "+ equipos.get(i).mediaTiempoCiclistas() + " minutos de media @@@\n");
                    equipos.get(i).mostrarEquipo(writer);
                    ind++;
                }
            }
        }
        
        if (ciclistasCarreraAbandonado.size() > 0)
        {
            setComparadorEquipos(new NombreEquipoComparador(), true);
            ordenarEquipos();
            escribirLinea("****************************************************\n" + "************** EQUIPOS QUE ABANDONARON **************\n" +
            "****************************************************\n");
            for(int i = 0; i < equipos.size(); i++)
            {
                if (equipos.get(i).numTotalCiclistas() == 0)
                {
                    equipos.get(i).mostrarEquipo(writer);
                }
            }
        }
    }
}