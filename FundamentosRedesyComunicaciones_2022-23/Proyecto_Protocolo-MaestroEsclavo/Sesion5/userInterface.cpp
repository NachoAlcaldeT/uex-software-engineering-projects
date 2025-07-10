//Ignacio Alcalde Torrescusa. Grupo de practicas: L2

#include "userInterface.h"
#include <iostream>

using namespace std;

void mostrarMac(interface_t *iface){
 for(int i=0;i<6;i++){
 cout<<": "<<hex<<(int) iface->MACaddr[i];
 }
}


void menuMaestroEsclavo(int num_estacion){      //Menu que se muestra segun se eliga: ser esclavo o maestro
 cout<<"Seleccion de modo:"<<endl;
 if(num_estacion==1){ 
    cout<<" [F1]:Envio de caracteres interactivo."<<endl;
    cout<<" [F2]:Envio de un fichero."<<endl;
    cout<<" [F3]:Protocolo paro y espera."<<endl;
    cout<<" [F4]:Introduccion de errores durante el protocolo"<<endl;
    cout<<" [ESC]:Salir."<<endl;
    }else{
    cout<<" [F1]:Envio de caracteres interactivo."<<endl;
    cout<<" [F3]:Protocolo paro y espera."<<endl;
    cout<<" [F4]:Introduccion de errores durante el protocolo"<<endl;
    cout<<" [ESC]:Salir."<<endl;
 }
}


void ImprimirTramaTotal(char a,char b,char c,char d,unsigned char e,unsigned char f){
 char palabra[5];
 if(c==5){
    palabra[0]='E';
    palabra[1]='N';
    palabra[2]='Q';
    palabra[3]='\0';
    printf("%c %c %s %c",a,b,palabra,d);
 }
 if(c==6){
    palabra[0]='A';
    palabra[1]='C';
    palabra[2]='K';
    palabra[3]='\0';
    printf("%c %c %s %c",a,b,palabra,d);
 }
 if(c==2 && a=='E'){
    palabra[0]='S';
    palabra[1]='T';
    palabra[2]='X';
    palabra[3]='\0';
    printf("%c %c %s %c %u",a,b,palabra,d,e);
 }
 if(c==2 && a=='R'){
    palabra[0]='S';
    palabra[1]='T';
    palabra[2]='X';
    palabra[3]='\0';
    printf("%c %c %s %c %u %u",a,b,palabra,d,e,f);
 }
 if(c==4){
    palabra[0]='E';
    palabra[1]='O';
    palabra[2]='T';
    palabra[3]='\0';
    printf("%c %c %s %c",a,b,palabra,d);
 }
 if(c==21){
    palabra[0]='N';
    palabra[1]='A';
    palabra[2]='C';
    palabra[3]='K';
    palabra[4]='\0';
    printf("%c %c %s %c",a,b,palabra,d);
 }
}

void Imprimirbce(unsigned char bce){
    printf("%u",bce);
}