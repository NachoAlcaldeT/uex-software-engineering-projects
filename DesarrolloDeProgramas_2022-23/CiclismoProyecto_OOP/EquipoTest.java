
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import java.util.Comparator;
import java.io.*;

/**
 * La clase "EquipoTest" es la clase de pruebas de Equipo.
 *
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz.
 * @versión 12/12/2022
 */
public class EquipoTest
{
    private Equipo movistarWomen;
    private Etapa etapa1;
    private Etapa etapa2;
    private Ciclista ciclista1;
    private Ciclista ciclista2;
    private Bicicleta bicicleta1;
    private Bicicleta bicicleta2;
    private BufferedWriter writer;
    
    /**
     * Constructor por defecto de la clase EquipoTest.
     */
    public EquipoTest()
    {
    }    

    /**
     * Construye el fixture de la prueba.
     *
     * Método llamado antes de cada caso de pruebas.
     */
    @BeforeEach
    public void setUp()
    {
        try {
            writer = new BufferedWriter(new FileWriter("SalidaDatosCampeonato.txt"));
        }
        catch(IOException e) {
            System.out.println("No se puede abrir el fichero.");
        }
        
        movistarWomen = new Equipo("Movistar Women", new HabilidadCiclistaComparador(), true, new PesoBicicletaComparador(), true);
        etapa1 = new Etapa("sencilla larga", Dificultad.SENCILLA, Distancia.LARGA);
        etapa2 = new Etapa("compleja intermedia", Dificultad.COMPLEJA, Distancia.INTERMEDIA);
        bicicleta1= new BicicletaRapida("CANYON Ultimate CFR eTap", Peso.LIGERA, 0.4);
        bicicleta2 = new Bicicleta("CANYON Aeroad CF SLX 8 Disc Di2", Peso.NORMAL);
        ciclista1 = new CiclistaEstrella("VAN VLEUTEN", Habilidad.BUENA, 1200, movistarWomen);
        ciclista2 = new CiclistaExperimentado("NORSGAARD", Habilidad.NORMAL, 1145, movistarWomen);
        
        movistarWomen.anadirBicicleta(bicicleta1);
        movistarWomen.anadirBicicleta(bicicleta2);
        movistarWomen.anadirCiclista(ciclista1);
        movistarWomen.anadirCiclista(ciclista2);
        
        ciclista1.setBicicleta(bicicleta1);
        ciclista2.setBicicleta(bicicleta2);
    }    
   
    /**
     * Prueba que la media de minutos acumulados por los ciclistas del equipo se realiza correctamente.
     */
    @Test
    public void testMediaTiempoCiclistas()
    {
        ciclista1.hacerCarrera(etapa1, writer);
        ciclista2.hacerCarrera(etapa1, writer);
        ciclista1.hacerCarrera(etapa2, writer);
        ciclista2.hacerCarrera(etapa2, writer);
        assertEquals(274.46, movistarWomen.mediaTiempoCiclistas());
    }    
   
    /**
     * Prueba que los ciclistas del equipo se envían correctamente a la organización.
     */
    @Test
    public void testSiguienteCiclista()
    {
        ciclista1 = movistarWomen.siguienteCiclista();
        ciclista2 = movistarWomen.siguienteCiclista();
        assertEquals(0, movistarWomen.numTotalCiclistas());
    }
    
    /**
     * Prueba que los ciclistas se ordenan correctamente.
     */
    @Test
    public void testOrdenarCiclistas()
    {
        movistarWomen.setComparadorCiclistas(new EnergiaCiclistaComparador(), true);
        movistarWomen.ordenarCiclistas();
        assertTrue(movistarWomen.siguienteCiclista().equals(ciclista2));
        assertTrue(movistarWomen.siguienteCiclista().equals(ciclista1));
    }
    
    /**
     * Prueba que las bicicletas se ordenan correctamente.
     */
    @Test
    public void testOrdenarBicicletas()
    {
        movistarWomen.setComparadorCiclistas(new EnergiaCiclistaComparador(), false);
        movistarWomen.setComparadorBicicletas(new PesoBicicletaComparador(), false);

        movistarWomen.asignarBicicletas(); // Al asignar las bicicletas a los ciclistas estas se ordenan según el comparador (ordenarBicicletas se llama de forma interna)
        
        assertTrue(ciclista1.getBicicleta().equals(bicicleta2));
        assertTrue(ciclista2.getBicicleta().equals(bicicleta1));
    }
    
    /**
     * Destruye el fixture de la prueba.
     *
     * Método llamado después de cada caso de pruebas.
     */
    @AfterEach
    public void tearDown()
    {
    }    
}