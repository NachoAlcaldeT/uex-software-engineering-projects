
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import java.io.*;

/**
 * La clase "OrganizacionTest" es la clase de pruebas de Organizacion.
 *
 * @autor Ignacio Alcalde Torrescusa, Darío Álvarez Barrado y Lucía Vega Cruz.
 * @versión 12/12/2022
 */
public class OrganizacionTest
{
    private Organizacion organizacion;
    private Equipo movistarWomen;
    private Etapa etapa1;
    private Etapa etapa2;
    private Ciclista ciclista1;
    private Ciclista ciclista2;
    private Bicicleta bicicleta1;
    private Bicicleta bicicleta2;
    private BufferedWriter writer;
    
    /**
     * Constructor por defecto de la clase OrganizacionTest.
     */
    public OrganizacionTest()
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
        
        organizacion = new Organizacion(new DificultadEtapaComparador(), true);
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
        movistarWomen.asignarBicicletas();
    }
    
    /**
     * Prueba si los equipos se inscriben correctamente (se guardan correctamente en el ArrayList).
     */
    @Test
    public void testInscribirEquipo()
    {
        organizacion.inscribirEquipo(movistarWomen);
        assertEquals(1, organizacion.numEquipos());
    }
    
     /**
     * Prueba que la comprobación de si todos los ciclistas han abandonado se realiza correctamente.
     */
    @Test
    public void testHayCiclistas()
    {
         organizacion.anadirEtapa(etapa1);
         organizacion.anadirEtapa(etapa2);
         organizacion.inscribirEquipo(movistarWomen);
         organizacion.anadirCiclistas();
         assertTrue(organizacion.hayCiclistas());
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
