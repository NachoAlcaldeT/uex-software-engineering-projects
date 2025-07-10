//Ignacio Alcalde Torrescusa. Grupo de practicas: L2

#include <stdio.h>
#include <stdio_ext.h>
#include <iostream>
#include <fstream>
#include "linkLayer.h"
#include "networkFunctions.h"
#include "userInterface.h"

using namespace std;

bool RecibirTrama(interface_t iface,int num_grupo,char num_trama){
bool ack = false;
bool enc=false;
char recibido='R';
unsigned char type[2]; 
type[0]=48+num_grupo;
type[1]=0;
    while(!enc){
        apacket_t trama=ReceiveFrame(&iface);   //Guardamos la trama recibida en la variable trama.
        const unsigned char *p=trama.packet;
        if(p!=NULL){                            //Comprobamos si no esta vacio. 
            if(p[12]==type[0] && p[13]==0){     //Comprobamos que la trama recibida es para nosotros.   
               if(p[14]=='R' && p[15]==6 && p[16]==num_trama){
                    cout<<endl;
                    ImprimirTramaTotal(recibido,p[14],p[15],p[16],' ',' ');
                    enc=true;
                    ack=true;
                } 
                if(p[14]=='T' && p[15]==6 && p[16]==num_trama){
                    cout<<endl;
                    ImprimirTramaTotal(recibido,p[14],p[15],p[16],' ',' ');
                    enc=true;
                    ack=true;
                }
                if(p[14]=='R' && p[15]==21 && p[16]==num_trama){
                    cout<<endl;
                    ImprimirTramaTotal(recibido,p[14],p[15],p[16],' ',' ');
                    enc=true;
                    ack=false;
                } 
                if(p[14]=='T' && p[15]==21 && p[16]==num_trama){
                    cout<<endl;
                    ImprimirTramaTotal(recibido,p[14],p[15],p[16],' ',' ');
                    enc=true;
                    ack=false;
                }     
            }
        }
    }
    return ack;
}



unsigned char CalculoBCE(char cadenaFichero [255]){
    int bce=cadenaFichero[0];
    for(int i=1;i<strlen(cadenaFichero);i++){
        bce=bce xor cadenaFichero[i];
    }
    if(bce==0 || bce==255){
        bce=1;
    }
    return bce;
}

void EnviarCaracter(interface_t iface,unsigned char p,unsigned char mac_origen[6],unsigned char mac_dst[6],unsigned char type[2]){

 unsigned char *car=new unsigned char;                           //Reservamos espacio en memmoria.
 *car=p; 
 unsigned char *trama=BuildFrame(mac_origen, mac_dst,type, car); //construimos la trama a mandar.
 SendFrame(&iface,trama,1);                                      //Mandamos la trama.
 free(trama);                                                    //Liberamos la trama.
 delete car;                                                     //Liberamos el espacio en memoria que habiamos reservado anteriormente.
}

bool RecibirTramaLiberacionEnviaFichero(interface_t iface,int num_grupo,char num_trama){
char recibido='R';
bool enc=false;
bool ack;
 unsigned char type[2]; 
    type[0]=48+num_grupo;
    type[1]=0;
    while(!enc){
        apacket_t trama=ReceiveFrame(&iface);   //Guardamos la trama recibida en la variable trama.
        const unsigned char *p=trama.packet;
        if(p!=NULL){                            //Comprobamos si no esta vacio.
            if(p[12]==type[0] && p[13]==0){     //Comprobamos que la trama recibida es para nosotros.
               if(p[14]=='R' && p[15]==6 && p[16]==num_trama){
                ImprimirTramaTotal(recibido,p[14],p[15],p[16],' ',' ');
                cout<<endl;
                enc=true;
                ack=true;
                }
                if(p[14]=='T' && p[15]==21 && p[16]==num_trama){
                ImprimirTramaTotal(recibido,p[14],p[15],p[16],' ',' ');
                cout<<endl;
                enc=true;
                ack=false;
                }
                if(p[14]=='T' && p[15]==6 && p[16]==num_trama){
                ImprimirTramaTotal(recibido,p[14],p[15],p[16],' ',' ');
                cout<<endl;
                enc=true;
                ack=true;
                }
            }
        }
    }
    return ack;
}

void FaseLiberacionMaestroSeleccion(interface_t iface,unsigned char mac_origen[6],unsigned char mac_dest[6],int num_grupo){
    bool enc=false;
    char enviado='E';
    char num_trama='0';
    unsigned char type[2]; 
    type[0]=48+num_grupo;
    type[1]=0;

    cout<<endl;
    char cadena [3];
    cadena[0]='R';
    cadena[1]=4;
    cadena[2]=num_trama;
    unsigned char *trama=BuildFrame(mac_origen, mac_dest,type, (unsigned char *) cadena);
    ImprimirTramaTotal(enviado,cadena[0],cadena[1],cadena[2],' ',' ');
    SendFrame(&iface,trama,3);      //Enviamos la trama del cierre de la communicacion.
    free(trama);
    cout<<endl;
    RecibirTramaLiberacionEnviaFichero(iface,num_grupo,num_trama);
    cout<<endl;
    cout<<"Fin de Seleccion por parte del maestro"<<endl;
    cout<<endl;
}

void FaseLiberacionEsclavoSondeo(interface_t iface,unsigned char mac_origen[6],unsigned char mac_dest[6],int num_grupo){
bool enc=false;
char enviado='E';
char num_trama='0';
unsigned char type[2]; 
type[0]=48+num_grupo;
type[1]=0;
while(!enc){
    cout<<endl;
    char cadena [3];
    cadena[0]='T';
    cadena[1]=4;
    cadena[2]=num_trama;
    unsigned char *trama=BuildFrame(mac_origen, mac_dest,type, (unsigned char *) cadena);
    ImprimirTramaTotal(enviado,cadena[0],cadena[1],cadena[2],' ',' ');
    SendFrame(&iface,trama,3); //Enviamos la trama del cierre de la comunicacion.
    free(trama);
    cout<<endl;

    enc=RecibirTramaLiberacionEnviaFichero(iface,num_grupo,num_trama); //Comprobamos si el maestro acepta el cierre de la comunicacion.Si no lo acepta le volvemos a enviar la trama de ciere de comunicacion hasta que la acepte.
    if(num_trama=='0'){
        num_trama='1';
    }else{
        num_trama='0';
     }

    }
    cout<<endl;
    cout<<"Fin de Sondeo por parte del esclavo"<<endl;
    cout<<endl;
}

int pulsacionf4(){
char tecla;
int contador=0;
    while(kbhit()){  
         tecla=getch();          
        if(tecla==27){
            if(kbhit()){                                                  
                tecla=getch();
                if(tecla=='O'){
                    tecla=getch();
                    if(tecla=='S'){
                        contador++;
                    }
                }
            }
        } 
                                                
    }
    return contador;
}

void MaestroSeleccion(interface_t iface,unsigned char mac_origen[6],unsigned char mac_dest[6],int num_grupo){
    int contador=0;
    char primer_caracter;
    char num_trama='0';
    bool enc=false;
    bool ack= false;
    char enviado='E';
    char recibido='R';
    int control;
    unsigned char type[2]; 
    type[0]=48+num_grupo;
    type[1]=0;
    char cadena [3];
    cadena[0]='R';
    cadena[1]=5;
    cadena[2]=num_trama;
    unsigned char *trama=BuildFrame(mac_origen, mac_dest,type, (unsigned char *) cadena);
    ImprimirTramaTotal(enviado,cadena[0],cadena[1],cadena[2],' ',' ');
    SendFrame(&iface,trama,3);          //Enviamos la trama de estabblecimiento al esclavo.
    free(trama);

    contador+=pulsacionf4();

    RecibirTrama(iface,num_grupo,num_trama);      //Recibimos la confirmacion del estabblecimiento.

    char cadenaTotal [259];             //Creamos la trama que mandaremos al maestro con los datos leidos de fichero, el control, la longitud...
    char cadenaFichero [255];           //Creamos la cadena donde vamos a guardar los 254 caracteres que leamos de fichero.
    int bce;
    ifstream archivo("EProtoc.txt"); //abrimos el archivo
    cout<<endl;
    if(archivo.is_open()){ //Comprobamos que el archivo se ha abierto correctamente.
         contador+=pulsacionf4();
        while(!archivo.eof()){ //Realizamos el envio de cadenas de maximo 254 caracteres hasta que llegue al final del archivo.
            contador+=pulsacionf4();
            int j=0;
            cadenaTotal[0]='R';
            cadenaTotal[1]=2;
            cadenaTotal[2]=num_trama;
            archivo.read(cadenaFichero, 254);       //Leemos un maximo de  254 caracteres y los añadimos a la cadena.
            cadenaFichero[archivo.gcount()]='\0';   //En la ultima posicion añadimos '\0' para marcar el final de la cadena.
            cadenaTotal[3]=strlen(cadenaFichero);
            for(j;j<strlen(cadenaFichero);j++){
             cadenaTotal[4+j]=cadenaFichero[j];
            }
    
            cadenaTotal[j+4]=CalculoBCE(cadenaFichero);

            primer_caracter=cadenaTotal[4];
            if(contador>0){
                cadenaTotal[4]=184;
                contador--;
                cout<<endl;
                cout<<"PRODUCIENDO ERROR";
            }
            
            unsigned char *trama=BuildFrame(mac_origen, mac_dest,type, (unsigned char *) cadenaTotal); //Construimos la trama con la cadena: cadenaTotal.
            SendFrame(&iface,trama,strlen(cadenaFichero)+5); //enviamos la trama 
            cout<<endl;
            ImprimirTramaTotal(enviado,cadenaTotal[0],cadenaTotal[1],cadenaTotal[2],cadenaTotal[strlen(cadenaFichero)+4],' ');
            unsigned char k=CalculoBCE(cadenaFichero);
            ack= RecibirTrama(iface,num_grupo,num_trama);        //Compprobamos que el maestro ha recibido bien la trama.
            while(!ack){                               //Mientras no la reciba bien se la volvemos a enviar.
            
            cadenaTotal[4]=primer_caracter;
            unsigned char *trama=BuildFrame(mac_origen, mac_dest,type, (unsigned char *) cadenaTotal); //Construimos la trama con la cadena: cadenaTotal.
            SendFrame(&iface,trama,strlen(cadenaFichero)+5); //enviamos la trama 
            
                //SendFrame(&iface,trama,strlen(cadenaFichero)+5);
                cout<<endl;
                ImprimirTramaTotal(enviado,cadenaTotal[0],cadenaTotal[1],cadenaTotal[2],cadenaTotal[strlen(cadenaFichero)+4],' ');
                ack= RecibirTrama(iface,num_grupo,num_trama);
            }
            if(num_trama=='0'){
                num_trama='1';
            }else{
                num_trama='0';
            }
            }
        }
    else{
        cout<<"Error al abrir el fichero"<<endl;
    }
    archivo.close(); //Una vez hemos realizado el envio de fichero lo cerramos
    cout<<endl;

    FaseLiberacionMaestroSeleccion(iface,mac_origen, mac_dest,num_grupo);       //Una vez enviado el fichero pasamos a la fase de liberacion.

}

void RecibirTramaLiberacionrecibeFichero(interface_t iface,int num_grupo){
    char recibido='R';
    unsigned char type[2]; 
    type[0]=48+num_grupo;
    type[1]=0;
    bool enc= false;
    while(!enc){
     apacket_t trama=ReceiveFrame(&iface); //Guardamos la trama recibida en la variable trama.
     const unsigned char *p=trama.packet;
     if(p!=NULL){                           //Comprobamos si no esta vacio. 
        if(p[12]==type[0] && p[13]==0){     //Comprobamos que la trama recibida es para nosotros.
            if(p[14]=='R' && p[15]==4 && (p[16]=='0' || p[16]=='1')){
                ImprimirTramaTotal(recibido,p[14],p[15],p[16],' ',' ');
                enc=true;
            }
            if(p[14]=='T' && p[15]==4 && (p[16]=='0' || p[16]=='1')){
                 ImprimirTramaTotal(recibido,p[14],p[15],p[16],' ',' ');
                enc=true;
            }
        }
     }
}
}

void FaseLiberacionEsclavoSeleccion(interface_t iface,unsigned char mac_origen[6],unsigned char mac_dest[6],int num_grupo){
    char enviado='E';
    char num_trama= '0';
    unsigned char type[2]; 
    type[0]=48+num_grupo;
    type[1]=0;
    char cadena[3];
    cadena[0]='R';
    cadena[1]=6;
    cadena[2]=num_trama;
    unsigned char *trama=BuildFrame(mac_origen, mac_dest,type, (unsigned char *) cadena);
    cout<<endl;
    ImprimirTramaTotal(enviado,cadena[0],cadena[1],cadena[2],' ',' ');
    cout<<endl;
    SendFrame(&iface,trama,3); //Enviamos la trama de confirmacion a la solicitud de finalizacion de la comunicacion.
     free(trama);   
     cout<<endl;
    cout<<"Fin de Selección por parte del esclavo."<<endl;
    cout<<endl;
}

void FaseLiberacionMaestroSondeo(interface_t iface,unsigned char mac_origen[6],unsigned char mac_dest[6],int num_grupo){
    bool enc=false;
    int n; 
    char enviado='E';
    char num_trama= '0';
    unsigned char type[2]; 
    type[0]=48+num_grupo;
    type[1]=0;
    while(!enc){
        cout<<endl;
        cout<<endl;
        cout<<"Acepta el cierre de la comunicacion: "<<endl;
        cout<<" [1]:Sí."<<endl;
        cout<<" [2]:No"<<endl;
        cin>>n;
        while(n<1 || n>2){      //Decidimos si queremos aceptar el cierre de la comunicacoin ya.
            cin>>n;
        }
        cout<<endl;
        char cadena [3];
        cadena[0]='T';
        if(n==1){              //Si queremos aceptar el cierre enviamos un 'ack'.
            cadena[1]=6;
        }
        else{                  //Si no enviamos un 'nack'.
            cadena[1]=21;
        }
        cadena[2]=num_trama;
        unsigned char *trama=BuildFrame(mac_origen, mac_dest,type, (unsigned char *) cadena);
         ImprimirTramaTotal(enviado,cadena[0],cadena[1],cadena[2],' ',' ');
        cout<<endl;
        SendFrame(&iface,trama,3); //enviamos la trama 
        free(trama);

        if(num_trama=='0'){
            num_trama='1';
        }else{
            num_trama='0';
        }
        if(n==1){       //Si hemos aceptado el cierre de la comunicacion hemos acabado el protocolo de paro y espera por parte del maestro.
            cout<<"Fin de Sondeo por parte del maestro."<<endl;
            cout<<endl;
            enc=true;
        }else{         //Si no hemos aceptado esperamos a recibir otra peticion de finalizacion.
        cout<<endl;
        RecibirTramaLiberacionrecibeFichero(iface,num_grupo);
        }
    }
}

void EsclavoSeleccion(interface_t iface,unsigned char mac_origen[6],unsigned char mac_dest[6],int num_grupo,char num_trama){
    bool enc=false;
    char enviado='E';
    char recibido='R';
    unsigned char type[2]; 
    type[0]=48+num_grupo;
    type[1]=0;
    char cadena [3];
    cadena[0]='R';
    cadena[1]=6;
    cadena[2]=num_trama;
    unsigned char *trama=BuildFrame(mac_origen, mac_dest,type, (unsigned char *) cadena);
     ImprimirTramaTotal(enviado,cadena[0],cadena[1],cadena[2],' ',' ');
    cout<<endl;
    cout<<endl;
    SendFrame(&iface,trama,3);           //Enviamos la trama de confirmacion al maestro.
    free(trama);

    ofstream archivo("RProtoc.txt");     //Abrimos el fichero
    while(!enc){
        char cadenaCaracteres [255];
        apacket_t trama=ReceiveFrame(&iface);  //Guardamos la trama recibida en la variable trama.
        const unsigned char *p=trama.packet;
        if(p!=NULL){                           //Comprobamos si no esta vacio. 
            if(p[12]==type[0] && p[13]==0){    //Comprobamos que la trama recibida es para nosotros.
                if(p[14]=='R' && p[15]==2 && (p[16]=='0' || p[16]=='1')){
                    int k=0;
                    struct pkthdr h= trama.header; 
                    int longitud= h.len; 
                    for(k=0;k<p[17];k++){       //Guardamos los datos recibidos del fichero en cadenaCaracteres.
                        cadenaCaracteres[k]=p[18+k];
                    }
                    cadenaCaracteres[k]='\0';   //En la ultima posicion añadimos '\0' para marcar el final de la cadena.
                    ImprimirTramaTotal(recibido,p[14],p[15],p[16],p[p[17]+18],CalculoBCE(cadenaCaracteres));
                    cout<<endl;
                    if(p[p[17]+18]==CalculoBCE(cadenaCaracteres)){      //Comprobamos que el bce que nos llega en la trama es el mismo que nosotros calculamos. Si es asi mandamos una trama de confirmacion.
                         archivo.write(cadenaCaracteres,p[17]);         //Ecribimos la cadenaCaracteres en el fichero.
                        char cadena [3];
                        cadena[0]='R';
                        cadena[1]=6;
                        cadena[2]=p[16];
                        unsigned char *trama=BuildFrame(mac_origen, mac_dest,type, (unsigned char *) cadena);
                        ImprimirTramaTotal(enviado,cadena[0],cadena[1],cadena[2],' ',' ');
                        SendFrame(&iface,trama,3); //enviamos la trama 
                        free(trama);
                         cout<<endl;
                    }else{       //Si hemos recibido una trama incorrecta le enviamos un 'nack' para que nos la vuelva a enviar.
                        char cadena [3];
                        cadena[0]='R';
                        cadena[1]=21;
                        cadena[2]=p[16];
                        unsigned char *trama=BuildFrame(mac_origen, mac_dest,type, (unsigned char *) cadena);
                        ImprimirTramaTotal(enviado,cadena[0],cadena[1],cadena[2],' ',' ');
                        SendFrame(&iface,trama,3); //enviamos la trama 
                        free(trama);
                        cout<<endl;
                    }
                }
                if(p[14]=='R' && p[15]==4 && (p[16]=='0' || p[16]=='1')){    //Si la trama que hemos recibido es la de la fase de liberacion cerramos el fichero y pasamos a la fase de liberacion.
                     archivo.close();
                    enc=true;
                    cout<<endl;
                     ImprimirTramaTotal(recibido,p[14],p[15],p[16],' ',' ');
            }
        }
    }
   
    }
    FaseLiberacionEsclavoSeleccion(iface,mac_origen, mac_dest,num_grupo);
}

void MaestroSondeo(interface_t iface,unsigned char mac_origen[6],unsigned char mac_dest[6],int num_grupo){
char num_trama='0';
char enviado='E';
char recibido='R';
    bool enc=false;
    int control;
    unsigned char type[2]; 
    type[0]=48+num_grupo;
    type[1]=0;
    char cadena [3];
    cadena[0]='T';
    cadena[1]=5;
    cadena[2]=num_trama;
    unsigned char *trama=BuildFrame(mac_origen, mac_dest,type, (unsigned char *) cadena);
    ImprimirTramaTotal(enviado,cadena[0],cadena[1],cadena[2],' ',' ');
    SendFrame(&iface,trama,3);      //Enviamos la trama de estabblecimiento al esclavo.
    free(trama);

    RecibirTrama(iface,num_grupo,num_trama);   //Recibimos la confirmacion del establecimiento.

    cout<<endl;
    cout<<endl;

    ofstream archivo("RProtoc.txt");        //Abrimos el fichero
    while(!enc){
        char cadenaCaracteres [255];
        apacket_t trama=ReceiveFrame(&iface);   //Guardamos la trama recibida en la variable trama.
        const unsigned char *p=trama.packet;
        if(p!=NULL){                            //Comprobamos si no esta vacio.
            if(p[12]==type[0] && p[13]==0){     //Comprobamos que la trama recibida es para nosotros.
                if(p[14]=='T' && p[15]==2 && (p[16]=='0' || p[16]=='1')){
                    int k=0;
                    struct pkthdr h= trama.header; 
                    int longitud= h.len; 
                    for(k=0;k<p[17];k++){       //Guardamos los datos recibidos del fichero en cadenaCaracteres.
                        cadenaCaracteres[k]=p[18+k];
                    }
                    cadenaCaracteres[k]='\0';   //En la ultima posicion añadimos '\0' para marcar el final de la cadena.
                    ImprimirTramaTotal(recibido,p[14],p[15],p[16],p[p[17]+18],CalculoBCE(cadenaCaracteres));
                    cout<<endl;
                    if(p[p[17]+18]==CalculoBCE(cadenaCaracteres)){  //Comprobamos que el bce que nos llega en la trama es el mismo que nosotros calculamos. Si es asi mandamos una trama de confirmacion.
                        archivo.write(cadenaCaracteres,p[17]);  //Ecribimos la cadenaCaracteres en el fichero.
                        char cadena [3];
                        cadena[0]='T';
                        cadena[1]=6;
                        cadena[2]=p[16];
                        unsigned char *trama=BuildFrame(mac_origen, mac_dest,type, (unsigned char *) cadena);
                        ImprimirTramaTotal(enviado,cadena[0],cadena[1],cadena[2],' ',' ');
                        SendFrame(&iface,trama,3); //enviamos la trama 
                        free(trama);
                         cout<<endl;
                    }
                    else{   //Si hemos recibido una trama incorrecta le enviamos un 'nack' para que nos la vuelva a enviar.
                        char cadena [3];
                        cadena[0]='R';
                        cadena[1]=21;
                        cadena[2]=p[16];
                        unsigned char *trama=BuildFrame(mac_origen, mac_dest,type, (unsigned char *) cadena);
                        ImprimirTramaTotal(enviado,cadena[0],cadena[1],cadena[2],' ',' ');
                        SendFrame(&iface,trama,3); //enviamos la trama 
                        free(trama);
                        cout<<endl;
                    }
                }
                if(p[14]=='T' && p[15]==4 && (p[16]=='0' || p[16]=='1')){//Si la trama que hemos recibido es la de la fase de liberacion cerramos el fichero y pasamos a la fase de liberacion.
                    enc=true;
                    cout<<endl;
                    ImprimirTramaTotal(recibido,p[14],p[15],p[16],' ',' ');
                    archivo.close();
            }
        }
    }
    }
    FaseLiberacionMaestroSondeo(iface,mac_origen, mac_dest,num_grupo);
}

void EsclavoSondeo(interface_t iface,unsigned char mac_origen[6],unsigned char mac_dest[6],int num_grupo,char num_trama){
    int contador=0;
    char primer_caracter;
    bool ack;
    bool enc=false;
    char enviado='E';
    char recibido='R';
    unsigned char type[2]; 
    type[0]=48+num_grupo;
    type[1]=0;
    char cadena [3];
    cadena[0]='T';
    cadena[1]=6;
    cadena[2]=num_trama;

    contador+=pulsacionf4();

    unsigned char *trama=BuildFrame(mac_origen, mac_dest,type, (unsigned char *) cadena);
    ImprimirTramaTotal(enviado,cadena[0],cadena[1],cadena[2],' ',' ');
    SendFrame(&iface,trama,3);    //Enviamos la trama de confirmacion al maestro.
    free(trama);
    cout<<endl;
    char cadenaTotal [259];       //Creamos la trama que mandaremos al maestro con los datos leidos de fichero, el control, la longitud...
    char cadenaFichero [255];     //Creamos la cadena donde vamos a guardar los 254 caracteres que leamos de fichero.
    int bce;
    ifstream archivo("EProtoc.txt"); //Abrimos el archivo.
    cout<<endl;
    if(archivo.is_open()){          //Comprobamos que el archivo se ha abierto correctamente.
        contador+=pulsacionf4();
        while(!archivo.eof()){ //Realizamos el envio de cadenas de maximo 254 caracteres hasta que llegue al final del archivo.
            contador+=pulsacionf4();
            int j=0;
            cadenaTotal[0]='T';
            cadenaTotal[1]=2;
            cadenaTotal[2]=num_trama;
            archivo.read(cadenaFichero, 254); //Leemos un maximo de  254 caracteres y los añadimos a la cadena.
            cadenaFichero[archivo.gcount()]='\0'; //En la ultima posicion añadimos '\0' para marcar el final de la cadena.
            cadenaTotal[3]=strlen(cadenaFichero);
            for(j;j<strlen(cadenaFichero);j++){
             cadenaTotal[4+j]=cadenaFichero[j];
            }
    
            cadenaTotal[j+4]=CalculoBCE(cadenaFichero);
            primer_caracter=cadenaTotal[4];
            if(contador>0){
                cadenaTotal[4]=184;
                contador--;
                cout<<"PRODUCIENDO ERROR";
                cout<<endl;
            }

            unsigned char *trama=BuildFrame(mac_origen, mac_dest,type, (unsigned char *) cadenaTotal); //Construimos la trama con la cadena: cadenaTotal.
            SendFrame(&iface,trama,strlen(cadenaFichero)+5);    //enviamos la trama 
            free(trama);
            ImprimirTramaTotal(enviado,cadenaTotal[0],cadenaTotal[1],cadenaTotal[2],cadenaTotal[strlen(cadenaFichero)+4],' ');
            unsigned char k=CalculoBCE(cadenaFichero);
            ack= RecibirTrama(iface,num_grupo,num_trama);         //Compprobamos que el maestro ha recibido bien la trama.
            while(!ack){                                //Miesntras no la reciba bien se la volvemos a enviar.

                cadenaTotal[4]=primer_caracter;
                unsigned char *trama=BuildFrame(mac_origen, mac_dest,type, (unsigned char *) cadenaTotal); //Construimos la trama con la cadena: cadenaTotal.
                SendFrame(&iface,trama,strlen(cadenaFichero)+5); //enviamos la trama 

                //SendFrame(&iface,trama,strlen(cadenaFichero)+5);
                cout<<endl;
                ImprimirTramaTotal(enviado,cadenaTotal[0],cadenaTotal[1],cadenaTotal[2],cadenaTotal[strlen(cadenaFichero)+4],' ');
                ack= RecibirTrama(iface,num_grupo,num_trama);
            }
            cout<<endl;

            if(num_trama=='0'){
                num_trama='1';
            }else{
                num_trama='0';
            }
            }
        }
    else{
        cout<<"Error al abrir el fichero"<<endl;
    }
    archivo.close(); //Una vez hemos realizado el envio de fichero lo cerramos
    cout<<endl;
    FaseLiberacionEsclavoSondeo(iface,mac_origen, mac_dest,num_grupo);    //Una vez enviado el fichero pasamos a la fase de liberacion.

}


void RecibirTramaProtocolo(interface_t iface,unsigned char mac_origen[6],unsigned char mac_dest[6],int num_grupo){
 bool enc=false;
 char recibido='R';
 unsigned char type[2]; 
 char num_trama;
type[0]=48+num_grupo;
type[1]=0;
while(!enc){
    apacket_t trama=ReceiveFrame(&iface);       //Guardamos la trama recibida en la variable trama.
    const unsigned char *p=trama.packet;
    if(p!=NULL){                                //Comprobamos si no esta vacio y si lo esta devolvemos un 0. 
        if(p[12]==type[0] && p[13]==0){         //Comprobamos que la trama recibida es para nosotros.
            if(p[14]=='R' && p[15]==5 && p[16]=='0'){   //Si en la posicion 14 de la trama hemos recibido una 'R' iremos a seleccion.
                ImprimirTramaTotal(recibido,p[14],p[15],p[16],' ',' ');
                num_trama=p[16];
                cout<<endl;
                EsclavoSeleccion( iface, mac_origen, mac_dest, num_grupo,num_trama);
                enc=true;
                }
            if(p[14]=='T' && p[15]==5 && p[16]=='0'){  //Si en la posicion 14 de la trama hemos recibido una 'T' iremos a sondeo.
                    ImprimirTramaTotal(recibido,p[14],p[15],p[16],' ',' ');
                    num_trama=p[16];
                    cout<<endl;
                    EsclavoSondeo( iface, mac_origen, mac_dest, num_grupo,num_trama);
                    enc=true;
                    
                }
            }
        }
    }
}


void RecibirCaracteres (interface_t iface,int num_grupo,unsigned char mac_origen[6],unsigned char mac_dest[6]) {

 unsigned char type[2]; 
 type[0]=48+num_grupo;
 char num_trama;
 type[1]=0;
 char car;
 int longitud=0;
 apacket_t trama=ReceiveFrame(&iface);      //Guardamos la trama recibida en la variable trama.
 const unsigned char *p=trama.packet;       //Obtenemos la información del paquete capturado.
 if(p!=NULL){                               //Comprobamos si no esta vacio y si lo esta devolvemos un 0. 
    if(p[12]==type[0] && p[13]==0){ 
        struct pkthdr h= trama.header; 
        longitud= h.len;                    //Obtenemos la longitud de la trama recibida.
        longitud= longitud -14;             //Nos quedamos con el numero de datos que hemos realizado.
        cout<<"Recibido: ";
        for(int i=0;i<longitud;i++){        //Mostramos todos los datos recibidos.
            car=p[i+14];
            cout<<car;
        }
        cout<<endl;
        cout<<"Numero de caracteres recibidos: ";
        printf("%u",longitud);
        cout<<endl;
        cout<<endl;
        }else{
        return;
        } 
    }else{
 return ;
 }
}

char RecibirCaracter (interface_t iface,int num_grupo,int &longitud) {
 unsigned char type[2]; 
 type[0]=48+num_grupo;
 type[1]=0; 
 apacket_t trama=ReceiveFrame(&iface);      //Guardamos la trama recibida en la variable trama.
 const unsigned char *p=trama.packet;       //Obtenemos la información del paquete capturado.
 if(p!=NULL){                               //Comprobamos si no esta vacio y si lo esta devolvemos un 0.
 struct pkthdr h= trama.header; 
        longitud= h.len;                    //Obtenemos la longitud de la trama recibida.
        longitud= longitud -14;
    if(p[12]==type[0] && p[13]==0){
        char dato=p[14];                    //Si no esta vacio nos quedamos con el caracter recibido.
        return dato;                        //Devolvemos el dato recibido.
        } else{
            return 0;
        } 
        }else{
            return 0;
        }
    delete p;
}

void envioCaracteresInteractivo(interface_t iface,unsigned char mac_origen[6],unsigned char mac_dest[6],int num_grupo){

char tecla;
char car;
unsigned char type_iteractiva[2];
type_iteractiva[0]=48+num_grupo;
type_iteractiva[1]=0;
int longitud;

__fpurge(stdin);
cout<<endl;
cout<<"Introduce los caracteres a enviar: "<<endl;

while(tecla!=27){
 car=RecibirCaracter(iface,num_grupo,longitud);          //Guardamos el caracter recibido.
 if(car){                                       //Si hemos recibido un caracter lo mostramos.
    printf("Caracter recibido: %c",car);
    cout<<endl;
    cout<<"Numero de caracteres recibidos: ";
    printf("%u",longitud);
    cout<<endl;
    }
    if(kbhit()){                                //Esperamos a que el usario escriba algo por teclado.
        tecla=getch();
        if(tecla!=27){
            EnviarCaracter(iface,tecla,mac_origen,mac_dest,type_iteractiva); //Enviamos un carácter.
        }
        }
}
cout<<endl;
cout<<"Salimos del envio de caracteres interactivo"<<endl;
}

void enviarFichero(int num_grupo, interface_t iface, unsigned char mac_origen[6],unsigned char mac_dest[6]){
unsigned char type[2];
 char cadena [255];                 //Creamos la cadena donde vamos a guardar los primeros 254 caracteres.
type[0]=48+num_grupo;
type[1]=0; 
ifstream archivo("envio.txt");      //Abrimos el archivo.
cout<<endl;
 if(archivo.is_open()){             //Comprobamos que el archivo se ha abierto correctamente
    cout<<"Fichero abierto correctamente"<<endl;

    while(!archivo.eof()){                  //Realizamos el envio de cadenas de maximo 255 caracteres hasta que llegue al final del archivo.
        archivo.read(cadena, 254);          //Leemos hasta un maximo de 254 caracteres y los añadimos a la cadena.
        cadena[archivo.gcount()]='\0';      //En la ultima posicion añadimos '\0' para marcar el final de la cadena.
        unsigned char *trama=BuildFrame(mac_origen, mac_dest,type, (unsigned char *) cadena);   //Construimos la trama con la cadena.
        SendFrame(&iface,trama,strlen(cadena));         //Enviamos la trama 
        free(trama);
    }
 }else{
    cout<<"Error al abrir el fichero"<<endl;
 }
 archivo.close();                            //Una vez hemos realizado el envio de fichero lo cerramos.
 cout<<"Fichero cerrado correctamente"<<endl;
 cout<<endl;
 cout<<"Salimos del envio de fichero"<<endl;
}


void ParoyEspera(interface_t iface,unsigned char mac_origen[6],unsigned char mac_dest[6],int num_estacion,int num_grupo){
 int num;
 bool enc=false;
 __fpurge(stdin);
 cout<<endl;
 while(!enc){
    cout<<"Protocolo paro y espera. Para salir pulse esc.";
    
    if(num_estacion==1){             //Si somos el maestro podemos eleir entre hacer operacion de selecion o sondeo.
        cout<<"Seleccione el tipo de operacion"<<endl;
        cout<<" [1]:Operacion de seleccion."<<endl;
        cout<<" [2]:Operacion de sondeo."<<endl;
        cout<<" [3]:Salir"<<endl; 

        cin>>num;
        while(num<1 || num>3){       //Comprobamos que la opcion elegida es correcta.   
        cout<<"Error. Introduzca un numero de grupo valido: ";
        cin>>num;
        }
        cout<<endl;

        if(num==1){
            
            MaestroSeleccion(iface,mac_origen,mac_dest,num_grupo);
            enc=true;
        }
        if(num==2){
             MaestroSondeo(iface,mac_origen,mac_dest,num_grupo);
             enc=true;
        }
        if(num==3){
            enc=true;
        }
        }else{                              //Si somos el esclavo esperaremos a recibir la trama del maestro para ver si estamos en seleccion o sondeo.
    cout<<"Estas en modo esclavo"<<endl;
    cout<<endl;
    RecibirTramaProtocolo(iface,mac_origen, mac_dest,num_grupo);
    enc=true;
    }
    }
}


void envio(int num_grupo, int num_estacion,interface_t iface,unsigned char mac_origen[6],unsigned char mac_dest[6]){
 bool enc=false;
 char tecla;
 int longitud;
 char car;
 __fpurge(stdin);
 menuMaestroEsclavo(num_estacion);
 while(!enc){
    if(num_estacion==2){
        RecibirCaracteres(iface,num_grupo,mac_origen,mac_dest);
    }
    if(kbhit()){                //Comprobamos si hay algo en el buffer de entrada
        tecla=getch();          //Obtenemos lo primero que haya.
        if(tecla!=27){
        cout<<"Tecla invalida"<<endl;
        }else{
            if(kbhit()){                                                      //Si sigue habiendo algo lo obtenemos.
                tecla=getch();
                if(tecla=='O'){
                    tecla=getch();
                    if(tecla=='P'){                                           //Si hemos pulsado f1 realzamos el envio de caracteres interactivo.
                         envioCaracteresInteractivo(iface,mac_origen,mac_dest,num_grupo);
                         menuMaestroEsclavo(num_estacion);
                    }
                    if(tecla=='Q'){                                           //Si hemos pulsado f2 comprobamos que lo ha pulsado el maestro ya que el esclavo no puede reslizar esta funcion.
                        if(num_estacion==1){
                        enviarFichero(num_grupo, iface, mac_origen,mac_dest); //Realizamos el envio del fichero: envio.txt
                        menuMaestroEsclavo(num_estacion);
                        }else{
                        cout<<"Tecla invalida"<<endl;
                        }
                    }
                    if(tecla=='R'){                                           //Si hemos pulsado f3 realizamos el protocolo de paro y espera.
                        ParoyEspera(iface,mac_origen,mac_dest,num_estacion,num_grupo);
                         __fpurge(stdin);
                         menuMaestroEsclavo(num_estacion);
                    }
                    }
                }else{
                enc=true;
                }
            }
        }
    }
}




void Maestro(interface_t iface,unsigned char mac_origen[6], int n,int num_estacion){
 cout<<"Esperando que se una la estacion esclava."<<endl;
 unsigned char mac_dst[6]={0xFF, 0xFF, 0xFF, 0xFF,0xFF, 0xFF}; //Creamos la broadcast.
 unsigned char mac_dst1[6]; 
 unsigned char type[2]; 
 type[0]=48+n;
 type[1]=1;                                                  //Creamos el tipo segun el numero de grupo y la opcion 1 ya que estamos en la fase de peticion de descubrimiento.
 unsigned char *trama=BuildHeader(mac_origen, mac_dst,type); //Cronstruimos la trama.
 SendFrame(&iface,trama,0);                                  //enviamos la trama creada.
 bool enc=false;

 while(!enc){
    apacket_t trama_recibida=ReceiveFrame(&iface);      //Recibimos la trama enviada por el esclavo.
    const unsigned char *p=trama_recibida.packet;       //Cogemos el paquete de la trama recibida.
    if(p!=NULL){
        if(p[12]==type[0] && p[13]==2){                 //Comprobamos la que es la trama que nos corresponde.
            cout<<"Estacion encontrada. La MAC es";

            for(int i=6; i<12; i++){                    //Obtenemos la mac del esclavo.
                mac_dst1[i-6] = p[i];
            } 
            
            for(int i=0; i<6; i++){                     //Mostramos la mac del esclavo.
                cout<<": "<<hex<<(int) mac_dst1[i];
            } 
            cout<<endl; 
            enc=true;
            }
        }
    }
 envio(n, num_estacion,iface,mac_origen,mac_dst1);
}

void Esclavo(interface_t iface,unsigned char mac_origen[6], int n,int num_estacion){
 cout<<"Esperando que se una la estacion Maestra."<<endl;
 unsigned char mac_dst1[6];
 unsigned char type[2]; 
 type[0]=48+n;
 type[1]=2;                                                             //Creamos el tipo con el numero de grupo y la opcion 2 ya que estamos en fase de contestacion de la peticion.
 bool enc=false;
 while(!enc){
    apacket_t trama_recibida=ReceiveFrame(&iface);                      //Recibimos la trama del maestro.
    const unsigned char *p=trama_recibida.packet;                       //Cogemos el paquete de la trama recibida.
    if(p!=NULL){
        if(p[12]==type[0] && p[13]==1){                                 //Comprobamos la que es la trama que nos corresponde.
            cout<<"Estacion encontrada. La MAC es ";

            for(int i=6; i<12; i++){                                    //Obtenemos la mac del maestro.
                mac_dst1[i-6] = p[i];
            }
            
            for(int i=0; i<6; i++){                                      //Mostramos la mac del maestro.
                cout<<": "<<hex<<(int) mac_dst1[i];
            }
            cout<<endl; 
            unsigned char *trama=BuildHeader(mac_origen, mac_dst1,type); //Cronstruimos la trama para enviarla al maestro con la mac que hemos capturado antes.
            SendFrame(&iface,trama,0);                                   //Enviamos la trama.
            enc=true;
            }
        }
    }
 envio(n, num_estacion,iface,mac_origen,mac_dst1);
}