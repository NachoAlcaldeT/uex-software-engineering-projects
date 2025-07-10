//Ignacio Alcalde Torrescusa. Grupo de practicas: L2

#ifndef NETWORK_FUNCTIONS_H
#define NETWORK_FUNCTIONS_H

#include "linkLayer.h"

// Declaraciones de funciones de red

bool RecibirTrama(interface_t iface,int num_grupo,char num_trama);  
unsigned char CalculoBCE(char cadenaFichero [255]);  

void EnviarCaracter(interface_t iface, unsigned char p, unsigned char mac_origen[6], unsigned char mac_dst[6], unsigned char type[2]);  

bool RecibirTramaLiberacionEnviaFichero(interface_t iface,int num_grupo,char num_trama);  
void FaseLiberacionMaestroSeleccion(interface_t iface,unsigned char mac_origen[6],unsigned char mac_dest[6],int num_grupo);  
void FaseLiberacionEsclavoSondeo(interface_t iface,unsigned char mac_origen[6],unsigned char mac_dest[6],int num_grupo); 

int pulsacionf4();

void MaestroSeleccion(interface_t iface,unsigned char mac_origen[6],unsigned char mac_dest[6],int num_grupo);  
void RecibirTramaLiberacionrecibeFichero(interface_t iface,int num_grupo);  
void FaseLiberacionEsclavoSeleccion(interface_t iface,unsigned char mac_origen[6],unsigned char mac_dest[6],int num_grupo); 
void FaseLiberacionMaestroSondeo(interface_t iface,unsigned char mac_origen[6],unsigned char mac_dest[6],int num_grupo); 
void EsclavoSeleccion(interface_t iface,unsigned char mac_origen[6],unsigned char mac_dest[6],int num_grupo,char num_trama); 
void MaestroSondeo(interface_t iface,unsigned char mac_origen[6],unsigned char mac_dest[6],int num_grupo); 
void EsclavoSondeo(interface_t iface,unsigned char mac_origen[6],unsigned char mac_dest[6],int num_grupo,char num_trama); 
void RecibirTramaProtocolo(interface_t iface,unsigned char mac_origen[6],unsigned char mac_dest[6],int num_grupo); 

void RecibirCaracteres (interface_t iface,int num_grupo,unsigned char mac_origen[6],unsigned char mac_dest[6]); 
char RecibirCaracter (interface_t iface,int num_grupo,int &longitud); 
void envioCaracteresInteractivo(interface_t iface,unsigned char mac_origen[6],unsigned char mac_dest[6],int num_grupo); 
void enviarFichero(int num_grupo, interface_t iface, unsigned char mac_origen[6],unsigned char mac_dest[6]); 

void ParoyEspera(interface_t iface,unsigned char mac_origen[6],unsigned char mac_dest[6],int num_estacion,int num_grupo); 

void envio(int num_grupo, int num_estacion,interface_t iface,unsigned char mac_origen[6],unsigned char mac_dest[6]); 

void Maestro(interface_t iface,unsigned char mac_origen[6], int n,int num_estacion); 
void Esclavo(interface_t iface,unsigned char mac_origen[6], int n,int num_estacion); 


#endif // NETWORK_FUNCTIONS_H
