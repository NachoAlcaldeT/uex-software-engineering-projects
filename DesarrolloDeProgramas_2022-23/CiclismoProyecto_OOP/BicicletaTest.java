
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import java.util.Comparator;

/**
 * La clase "BicicletaTest" es la clase de pruebas de Bicicleta.
 *
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz.
 * @versión 12/12/2022
 */

public class BicicletaTest
{
    private Equipo movistarWomen;
    private Etapa etapa1;
    private Etapa etapa2;
    private Bicicleta bicicleta1;
    private Bicicleta bicicleta2;
    private Ciclista ciclista1;
    private Ciclista ciclista2;
        
    /**
     * Constructor por defecto de la clase BicicletaTest.
     */
    public BicicletaTest()
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
        movistarWomen = new Equipo("Movistar Women", new HabilidadCiclistaComparador(), true, new PesoBicicletaComparador(), true);
        etapa1 = new Etapa("sencilla larga", Dificultad.SENCILLA, Distancia.LARGA);
        etapa2 = new Etapa("compleja intermedia", Dificultad.COMPLEJA, Distancia.INTERMEDIA);
        bicicleta1 = new BicicletaRapida("CANYON Ultimate CFR eTap", Peso.LIGERA, 0.4);
        bicicleta2 = new Bicicleta("CANYON Aeroad CF SLX 8 Disc Di2", Peso.NORMAL);
        ciclista1 = new CiclistaEstrella("VAN VLEUTEN", Habilidad.BUENA, 1200, movistarWomen);
        ciclista2 = new CiclistaExperimentado("NORSGAARD", Habilidad.NORMAL, 1145, movistarWomen);
    }    
        
    /**
     * Prueba que el cálculo de la velocidad de un ciclista en una etapa se realiza correctamente.
     */
    @Test
    public void testVelocidad()
    {
        assertEquals(121.34, bicicleta1.velocidad(ciclista1, etapa1));
        assertEquals(99.35, bicicleta1.velocidad(ciclista1, etapa2));
        assertEquals(88.89, bicicleta2.velocidad(ciclista2, etapa1));
        assertEquals(72.73, bicicleta2.velocidad(ciclista2, etapa2));
    }    
    
    /**
     * Prueba que el tiempo que tarda un ciclista en realizar una etapa se calcula correctamente.
     */ 
    @Test
    public void testTiempoEtapa()
    {
        assertEquals(111.26, bicicleta1.tiempoEtapa(ciclista1, etapa1));
        assertEquals(120.79, bicicleta1.tiempoEtapa(ciclista1, etapa2));
        assertEquals(151.87, bicicleta2.tiempoEtapa(ciclista2, etapa1));
        assertEquals(164.99, bicicleta2.tiempoEtapa(ciclista2, etapa2));
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
