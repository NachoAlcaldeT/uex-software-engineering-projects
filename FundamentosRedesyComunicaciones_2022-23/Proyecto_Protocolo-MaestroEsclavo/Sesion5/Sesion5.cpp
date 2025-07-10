//============================================================================
// ----------- PRACTICAS DE FUNDAMENTOS DE REDES DE COMUNICACIONES -----------
// ---------------------------- CURSO 2023/24 --------------------------------
// ----------------------------- SESION5.CPP ---------------------------------
//============================================================================

//Ignacio Alcalde Torrescusa. Grupo de practicas: L2

#include <stdio.h>
#include <stdio_ext.h>
#include <iostream>
#include <fstream>
#include "linkLayer.h"
#include "userInterface.h"
#include "networkFunctions.h"

using namespace std;

int main()
{

 interface_t iface;
 pcap_if_t *avail_ifaces=NULL;
 int i=0,j=0;
 int num;
 unsigned char mac_dst[6]={0x00, 0x01, 0x02, 0x03,0x04, 0x05};
 unsigned char type[2]={0x30,0x00};
 char car;
 char tecla;
 int num_grupo;
 int num_estacion;

 
 printf("\n----------------------------\n");
 printf("------ SESION 5 - FRC ------\n");
 printf("----------------------------\n");
 
 //Obtenemos las interfaces disponibles.
 avail_ifaces=GetAvailAdapters();

 //Mostramos las interfaces que hemos obtenido.
 while(avail_ifaces->next != NULL){
    cout<<"["<<i<<"]"<<avail_ifaces->name<<endl;
    avail_ifaces=avail_ifaces->next;
    i++;
 }
 
 //El usuario elige una interfaz.
 cout<<"Seleccione interfaz: ";
 cin>>num;
 avail_ifaces=GetAvailAdapters();

 //Recorremos las interfaces hasta encontrar la que ha seleccionado el usuario para mostrarla.
 if(num>=0 && num<i){
    while(avail_ifaces->next != NULL){
        if(j==num){
            char *nombre_interfaz=avail_ifaces->name;
            setDeviceName(&iface,nombre_interfaz);
            GetMACAdapter(&iface);
            cout<<"Interfaz elegida: "<<iface.deviceName<<endl;
            cout<<"La mac origen es";
            mostrarMac(&iface);
        }
        j++;
        avail_ifaces=avail_ifaces->next;
    }
}else{
 cout<<"El numero introducido no corresponde a ninguna interfaz."<<endl;
}

cout<<endl;


//Abrimos el puerto:
int Puerto=OpenAdapter(&iface);

 if(Puerto != 0){
    printf("Error al abrir el puerto.\n");
    getch();
    return(1);
 }else{
 printf("Puerto abierto correctamente.\n");
 }

 cout<<endl;

 __fpurge(stdin);
 

 cout<<"Introduce el numero de grupo: "; //Eleccion del numero de grupo.
 cin>>num_grupo;
 while(num_grupo<1 || num_grupo>12){     //Comprobamos que es un numero de grupo correcto.
    cout<<"Error. Introduzca un numero de grupo valido: ";
    cin>>num_grupo;
 }
cout<<endl;

 cout<<"Selecciona el modo de la estacion:"<<endl; //Eleccion del modo de estacion.

 cout<<" [1]:Modo Maestra."<<endl;
 cout<<" [2]:Modo Esclava."<<endl;
 cin>>num_estacion;
 while(num_estacion<1 || num_estacion>2){          //Comprobamos que es un numero de estacion valido.
    cout<<"Error. Introduzca un numero de estacion valido: ";
    cin>>num_estacion;
 }

 if(num_estacion==1){
    Maestro(iface,iface.MACaddr,num_grupo,num_estacion);
 }else{
    Esclavo(iface,iface.MACaddr,num_grupo,num_estacion);
 }

 
 //Cerramos el puerto:
 CloseAdapter(&iface);
 cout<<endl;
 }