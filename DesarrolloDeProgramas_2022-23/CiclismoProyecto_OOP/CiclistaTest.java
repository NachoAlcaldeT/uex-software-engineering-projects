
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import java.util.Comparator;
import java.io.*;

/**
 * La clase "CiclistaTest" es la clase de pruebas de Ciclista.
 *
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz.
 * @versión 12/12/2022
 */
public class CiclistaTest
{    
    private Equipo movistarWomen;
    private Etapa etapa1;
    private Etapa etapa2;
    private Bicicleta bicicleta1;
    private Bicicleta bicicleta2;
    private Ciclista ciclista1;
    private Ciclista ciclista2;
    private Ciclista ciclista1Cansado;
    private BufferedWriter writer;
    
    /**
     * Constructor por defecto de la clase CiclistaTest.
     */
    public CiclistaTest()
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
        bicicleta1 = new BicicletaRapida("CANYON Ultimate CFR eTap", Peso.LIGERA, 0.4);
        bicicleta2 = new Bicicleta("CANYON Aeroad CF SLX 8 Disc Di2", Peso.NORMAL);
        ciclista1 = new CiclistaEstrella("VAN VLEUTEN", Habilidad.BUENA, 1200, movistarWomen);
        ciclista2 = new CiclistaExperimentado("NORSGAARD", Habilidad.NORMAL, 1145, movistarWomen);
        ciclista1Cansado = new CiclistaEstrella("VAN VLEUTEN", Habilidad.BUENA, 100, movistarWomen);
        
        ciclista1.setBicicleta(bicicleta1);
        ciclista2.setBicicleta(bicicleta2);
        ciclista1Cansado.setBicicleta(bicicleta1);
    }
    
    /**
     * Prueba que el ciclista realiza correctamente la carrera. 
     */
    @Test
    public void testHacerCarrera()
    {
        ciclista1.hacerCarrera(etapa1, writer);
        assertEquals(1088.74, ciclista1.getEnergia());
        ciclista2.hacerCarrera(etapa1, writer);
        assertEquals(993.13, ciclista2.getEnergia());
    }
    
    /**
     * Prueba que el ciclista guarda y suma correctamente los resultados.
     */
    @Test
    public void testTiempoTotal()
    {
        ciclista1.hacerCarrera(etapa1, writer);
        ciclista1.hacerCarrera(etapa2, writer);
        assertEquals(232.05,ciclista1.tiempoTotal());
        ciclista2.hacerCarrera(etapa1, writer);
        ciclista2.hacerCarrera(etapa2, writer);
        assertEquals(316.86,ciclista2.tiempoTotal());
    }
    
    @Test
    public void getDestreza()
    {
        assertEquals(1.0, ciclista1.destreza());
    }
    
    /**
     * Prueba que la etapa que ha abandonado el ciclista se guarda correctamente.
     */
    @Test
    public void testEtapaAbandonada()
    {
        ciclista1Cansado.hacerCarrera(etapa1, writer);
        ciclista1Cansado.hacerCarrera(etapa2, writer);
        assertTrue(ciclista1Cansado.etapaAbandonada().equals(etapa1));
    }
    
    /**
     * Prueba que los resultados se guardan correctamente.
     */
    @Test
    public void testConsultarTiempoEtapa()
    {
        ciclista1.hacerCarrera(etapa1, writer);
        ciclista1.hacerCarrera(etapa2, writer);
        assertTrue(111.26 == ciclista1.consultarTiempoEtapa(etapa1));
    }
    
    /**
     * Prueba que el número de etapas terminadas por el ciclista se calcula correctamente.
     */
    @Test
    public void testNumEtapasTerminadas()
    {
        ciclista1.hacerCarrera(etapa1, writer);
        ciclista1.hacerCarrera(etapa2, writer);
        assertTrue(2 == (ciclista1.numEtapasTerminadas()));
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
