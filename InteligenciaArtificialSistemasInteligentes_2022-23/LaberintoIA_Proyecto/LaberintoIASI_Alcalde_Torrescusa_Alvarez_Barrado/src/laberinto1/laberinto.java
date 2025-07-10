package laberinto1;

import java.io.BufferedReader;
import java.util.ArrayList;
import java.util.Date;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Random;
import java.util.Scanner; 
import java.lang.Math;

public class laberinto {

	static int Precio;
	static int Puntos=0;
	static int[][] matriz;
	static int Roboti;
	static int Robotj;
	static int Salidai;
	static int Salidaj;
	static String cad="";
	static double distanciaSalida=0;
	static double distanciaMonedaCerca=0;
	static double distanciaMonedaMasValor=0;
	static boolean esMuro=false;
	static double vectorDistancias[];
	static boolean sinSalida=false;
	static boolean terminar=false;
	static int posicion;
	static int Nodos=0;
	static double α=1;
	static int INFINITO=999999;
	static int[] vector = new int[8];
	static int movimientosMax=15;
	static int numMov=0;
	

	public static void lecturaMatriz() {

		try {
			BufferedReader br = new BufferedReader(new FileReader("LABECOIN2.txt"));
			//Primera linea nos dice el precio a conseguir antes de poder salir del laberinto
			String linea = br.readLine();

			String[] hh = linea.split(" ");
			Precio=Integer.parseInt(hh[0]);

			matriz = new int[10][10];
			//Las siguientes lineas son filas de la matriz
			linea = br.readLine();
			int fila = 0; //Para recorrer las filas de la matriz
			while(linea != null) {
				/*
				 * Tenemos todos los enteros JUNTOS en el String linea.
				 * Con split() los SEPARAMOS en un array donde cada entero
				 * es un String individual. Con un bucle, los parseamos a Integer
				 * para guardarlos en la matriz
				 */
				String[] enteros = linea.split(",");
				for (int i = 0; i < enteros.length; i++) {
					matriz[fila][i] = Integer.parseInt(enteros[i]);
				}
				fila++; //Incrementamos fila para la próxima línea de enteros
				linea = br.readLine(); //Leemos siguiente línea
			}
			br.close(); //Cerramos el lector de ficheros

		} catch (FileNotFoundException e) {
			System.out.println("No se encuentra archivo");
			e.printStackTrace();
		} catch (NumberFormatException e) {
			System.out.println("No se pudo convertir a entero");
			e.printStackTrace();
		} catch (IOException e) {
			System.out.println("Error accediendo al archivo.");
			e.printStackTrace();
		}

	}

	public static void mostrarMatriz() {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++)
				System.out.print(matriz[i][j] + " ");
			System.out.println();
		}
		System.out.println();
	}

	public static void coordenadasRobotyFin() {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if(matriz[i][j]==8){
					Roboti=i;
					Robotj=j;
				}
				if(matriz[i][j]==7){
					Salidai=i;
					Salidaj=j;
				}
			}	
		}
	}

	public static void Arriba() {

		if(!muro(Roboti-1,Robotj)) {
			if(matriz[Roboti-1][Robotj]!=0 && matriz[Roboti-1][Robotj]!=7){
				Puntos+=matriz[Roboti-1][Robotj];
			}
			matriz[Roboti][Robotj]=0;
			matriz[Roboti-1][Robotj]=8;
			Roboti=Roboti-1;
			cad+="A,";
		}

	}

	public static void ArribaIzquierda() {

		if(!muro(Roboti-1,Robotj-1)) {
			if(matriz[Roboti-1][Robotj-1]!=0 && matriz[Roboti-1][Robotj-1]!=7){
				Puntos+=matriz[Roboti-1][Robotj-1];
			}
			matriz[Roboti][Robotj]=0;
			matriz[Roboti-1][Robotj-1]=8;
			Roboti=Roboti-1;
			Robotj=Robotj-1;
			cad+="AI,";
		}
	}

	public static void ArribaDerecha() {

		if(!muro(Roboti-1,Robotj+1)) {
			if(matriz[Roboti-1][Robotj+1]!=0 && matriz[Roboti-1][Robotj+1]!=7){
				Puntos+=matriz[Roboti-1][Robotj+1];
			}
			matriz[Roboti][Robotj]=0;
			matriz[Roboti-1][Robotj+1]=8;
			Roboti=Roboti-1;
			Robotj=Robotj+1;
			cad+="AD,";
		}
	}

	public static void Izquierda() {

		if(!muro(Roboti,Robotj-1)) {
			if(matriz[Roboti][Robotj-1]!=0 && matriz[Roboti][Robotj-1]!=7){
				Puntos+=matriz[Roboti][Robotj-1];
			}

			matriz[Roboti][Robotj]=0;
			matriz[Roboti][Robotj-1]=8;
			Robotj=Robotj-1;
			cad+="I,";
		}
	}

	public static void Derecha() {

		if(!muro(Roboti,Robotj+1)) {
			if(matriz[Roboti][Robotj+1]!=0 && matriz[Roboti][Robotj+1]!=7){
				Puntos+=matriz[Roboti][Robotj+1];
			}
			matriz[Roboti][Robotj]=0;
			matriz[Roboti][Robotj+1]=8;
			Robotj=Robotj+1;
			cad+="D,";
		}
	}

	public static void Abajo() {

		if(!muro(Roboti+1,Robotj)) {
			if(matriz[Roboti+1][Robotj]!=0 && matriz[Roboti+1][Robotj]!=7){
				Puntos+=matriz[Roboti+1][Robotj];
			}
			matriz[Roboti][Robotj]=0;
			matriz[Roboti+1][Robotj]=8;
			Roboti=Roboti+1;
			cad+="B,";
		}
	}

	public static void AbajoIzquierda() {

		if(!muro(Roboti+1,Robotj-1)) {
			if(matriz[Roboti+1][Robotj-1]!=0 && matriz[Roboti+1][Robotj-1]!=7){
				Puntos+=matriz[Roboti+1][Robotj-1];
			}
			matriz[Roboti][Robotj]=0;
			matriz[Roboti+1][Robotj-1]=8;
			Roboti=Roboti+1;
			Robotj=Robotj-1;
			cad+="BI,";
		}
	}

	public static void AbajoDerecha() {

		if(!muro(Roboti+1,Robotj+1)) {
			if(matriz[Roboti+1][Robotj+1]!=0 && matriz[Roboti+1][Robotj+1]!=7){
				Puntos+=matriz[Roboti+1][Robotj+1];
			}
			matriz[Roboti][Robotj]=0;
			matriz[Roboti+1][Robotj+1]=8;
			Roboti=Roboti+1;
			Robotj=Robotj+1;
			cad+="BD,";
		}
	}

	public static void MetodoDistanciaSalida(int x,int y) {
		int distanciai=0;
		int distanciaj=0;


		distanciai=Math.abs(x-Salidai);
		distanciaj=Math.abs(y-Salidaj);
		distanciai=distanciai*distanciai;
		distanciaj=distanciaj*distanciaj;
		distanciaSalida=(float) Math.sqrt(distanciai+distanciaj);

	}

	public static void MetodoDistanciaMonedaCerca() {
		int distanciai=0;
		int distanciaj=0;
		float distanciaAux=0;
		distanciaMonedaCerca=1000;

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if(matriz[i][j]!=9 && matriz[i][j]!=8 && matriz[i][j]!=0 && matriz[i][j]!=7) {
					distanciai=Math.abs(Roboti-i);
					distanciaj=Math.abs(Robotj-j);
					distanciai=distanciai*distanciai;
					distanciaj=distanciaj*distanciaj;
					distanciaAux=(float) Math.sqrt(distanciai+distanciaj);
					if(distanciaAux<distanciaMonedaCerca) {
						distanciaMonedaCerca=distanciaAux;
					}
				}
			}
		}
	}

	public static void MetodoDistanciaMonedaMasValor(int x,int y) {
		int distanciai=0;
		int distanciaj=0;
		int PuntosAux=0;

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if(matriz[i][j]!=9 && matriz[i][j]!=8 && matriz[i][j]!=0 && matriz[i][j]!=7) {
					if(matriz[i][j]>PuntosAux) {
						PuntosAux=matriz[i][j];
						distanciai=Math.abs(x-i);
						distanciaj=Math.abs(y-j);
						distanciai=distanciai*distanciai;
						distanciaj=distanciaj*distanciaj;
						distanciaMonedaMasValor=(float) Math.sqrt(distanciai+distanciaj);

					}
				}
			}
		}
	}

	public static boolean muro(int x,int y) {
		if(matriz[x][y]==9){
			return true;
		}
		return false;
	}

	public static void MaximaPendiente(){

		while(Puntos<Precio) {
			MetodoDistanciaMonedaMasValor(Roboti,Robotj);
			double distanciaminima=distanciaMonedaMasValor;
			double distanciact=distanciaminima;
			vectorDistancias  = new double[8];
			for(int i=0;i<8;i++) {
				switch(i) {
				case 0:
					//Arriba
					if(!muro(Roboti-1,Robotj)) {
						MetodoDistanciaMonedaMasValor(Roboti-1,Robotj);
						vectorDistancias[i]=distanciaMonedaMasValor;
					}else {
						vectorDistancias[i]=INFINITO;
					}
					Nodos++;
					break;
				case 1:
					//ArribaIzquierda
					if(!muro(Roboti-1,Robotj-1)) {
						MetodoDistanciaMonedaMasValor(Roboti-1,Robotj-1);
						vectorDistancias[i]=distanciaMonedaMasValor;
					}else {
						vectorDistancias[i]=INFINITO;
					}
					Nodos++;
					break;
				case 2:
					//ArribaDerecha
					if(!muro(Roboti-1,Robotj+1)) {
						MetodoDistanciaMonedaMasValor(Roboti-1,Robotj+1);
						vectorDistancias[i]=distanciaMonedaMasValor;
					}else {
						vectorDistancias[i]=INFINITO;
					}
					Nodos++;
					break;
				case 3:
					//Izquierda
					if(!muro(Roboti,Robotj-1)) {
						MetodoDistanciaMonedaMasValor(Roboti,Robotj-1);
						vectorDistancias[i]=distanciaMonedaMasValor;
					}else {
						vectorDistancias[i]=INFINITO;
					}
					Nodos++;
					break;
				case 4:
					//Derecha
					if(!muro(Roboti,Robotj+1)) {
						MetodoDistanciaMonedaMasValor(Roboti,Robotj+1);
						vectorDistancias[i]=distanciaMonedaMasValor;
					}else {
						vectorDistancias[i]=INFINITO;
					}
					Nodos++;
					break;
				case 5:
					//Abajo
					if(!muro(Roboti+1,Robotj)) {
						MetodoDistanciaMonedaMasValor(Roboti+1,Robotj);
						vectorDistancias[i]=distanciaMonedaMasValor;
					}else {
						vectorDistancias[i]=INFINITO;
					}
					Nodos++;
					break;
				case 6:
					//AbajoIzquierda
					if(!muro(Roboti+1,Robotj-1)) {
						MetodoDistanciaMonedaMasValor(Roboti+1,Robotj-1);
						vectorDistancias[i]=distanciaMonedaMasValor;
					}else {
						vectorDistancias[i]=INFINITO;
					}
					Nodos++;
					break;
				case 7:
					//AbajoDerecha
					if(!muro(Roboti+1,Robotj+1)) {
						MetodoDistanciaMonedaMasValor(Roboti+1,Robotj+1);
						vectorDistancias[i]=distanciaMonedaMasValor;
					}else {
						vectorDistancias[i]=INFINITO;
					}
					Nodos++;
					break;
				}
			}
			
			for(int i=0;i<8;i++) {
				if(vectorDistancias[i]<distanciaminima) {
					distanciaminima=vectorDistancias[i];
					posicion=i;
				}
			}

			if(distanciact==distanciaminima) {
				System.out.println("Este laberinto no tiene solucion.");
				return ;
			}

			ActualizarPosicion(posicion);
			
			if(numMov>=movimientosMax) {
				System.out.println("Has llegado al numero maximo de movimientos que se pueden realizar. ");
				return ; 
			}
		}

		if(Roboti!=Salidai) {
			if(Robotj!=Salidaj) {
				terminar=false;
			}
		}

		while(!terminar) {
			MetodoDistanciaSalida(Roboti,Robotj);
			double distanciaminima=distanciaSalida;
			double distanciact=distanciaminima;
			vectorDistancias  = new double[8];
			for(int i=0;i<8;i++) {
				switch(i) {
				case 0:
					if(!muro(Roboti-1,Robotj)) {
						MetodoDistanciaSalida(Roboti-1,Robotj);
						vectorDistancias[i]=distanciaSalida;
					}else {
						vectorDistancias[i]=INFINITO;
					}Nodos++;
					break;
				case 1:
					//ArribaIzquierda
					if(!muro(Roboti-1,Robotj-1)) {
						MetodoDistanciaSalida(Roboti-1,Robotj-1);
						vectorDistancias[i]=distanciaSalida;
					}else {
						vectorDistancias[i]=999999;
					}Nodos++;
					break;
				case 2:
					//ArribaDerecha
					if(!muro(Roboti-1,Robotj+1)) {
						MetodoDistanciaSalida(Roboti-1,Robotj+1);
						vectorDistancias[i]=distanciaSalida;
					}else {
						vectorDistancias[i]=INFINITO;
					}Nodos++;
					break;
				case 3:
					//Izquierda
					if(!muro(Roboti,Robotj-1)) {
						MetodoDistanciaSalida(Roboti,Robotj-1);
						vectorDistancias[i]=distanciaSalida;
					}else {
						vectorDistancias[i]=INFINITO;
					}Nodos++;
					break;
				case 4:
					//Derecha
					if(!muro(Roboti,Robotj+1)) {
						MetodoDistanciaSalida(Roboti,Robotj+1);
						vectorDistancias[i]=distanciaSalida;
					}else {
						vectorDistancias[i]=INFINITO;
					}Nodos++;
					break;
				case 5:
					//Abajo
					if(!muro(Roboti+1,Robotj)) {
						MetodoDistanciaSalida(Roboti+1,Robotj);
						vectorDistancias[i]=distanciaSalida;
					}else {
						vectorDistancias[i]=INFINITO;
					}Nodos++;
					break;
				case 6:
					//AbajoIzquierda
					if(!muro(Roboti+1,Robotj-1)) {
						MetodoDistanciaSalida(Roboti+1,Robotj-1);
						vectorDistancias[i]=distanciaSalida;
					}else {
						vectorDistancias[i]=INFINITO;
					}Nodos++;
					break;
				case 7:
					//AbajoDerecha
					if(!muro(Roboti+1,Robotj+1)) {
						MetodoDistanciaSalida(Roboti+1,Robotj+1);
						vectorDistancias[i]=distanciaSalida;
					}else {
						vectorDistancias[i]=INFINITO;
					}Nodos++;
					break;
				}
			}
			for(int i=0;i<8;i++) {
				if(vectorDistancias[i]<distanciaminima) {
					distanciaminima=vectorDistancias[i];
					posicion=i;
				}
			}

			if(distanciact==distanciaminima) {
				System.out.println("Este laberinto no tiene solucion.");
				return ;
			}

			ActualizarPosicion(posicion);
			
			if(Roboti==Salidai) {
				if(Robotj==Salidaj) {
					terminar=true;
					System.out.println("¡Has llegado a la salida! ");
				}
			}
			if(numMov>=movimientosMax && !terminar) {
				System.out.println("Has llegado al numero maximo de movimientos que se pueden realizar. ");
				return ; 
			}
		}
	}

	

	public static void GenerarVector(){

		Random random = new Random();

		for (int i = 0; i < vector.length; i++) {
			int numeroAleatorio;
			boolean numeroRepetido;
			do {
				numeroAleatorio = random.nextInt(8);
				numeroRepetido = false;
				for (int j = 0; j < i; j++) {
					if (vector[j] == numeroAleatorio) {
						numeroRepetido = true;
						break;
					}
				}
			} while (numeroRepetido);
			vector[i] = numeroAleatorio;
		}
	}


	public static void Estocastico(){


		while(Puntos<Precio) {
			GenerarVector();
			int i=0;
			while(i<vector.length) {

				MetodoDistanciaMonedaMasValor(Roboti,Robotj);
				double distanciact=distanciaMonedaMasValor;
				double distancia;

				switch(vector[i]) {
				case 0:
					//Arriba
					if(!muro(Roboti-1,Robotj)) {
						MetodoDistanciaMonedaMasValor(Roboti-1,Robotj);
						distancia=distanciaMonedaMasValor;
						posicion=INFINITO;
						if((distancia-distanciact)<0 && Math.abs(distancia-distanciact)>=α || distancia==0 ){
							posicion=0;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 1:
					//ArribaIzquierda
					if(!muro(Roboti-1,Robotj-1)) {
						MetodoDistanciaMonedaMasValor(Roboti-1,Robotj-1);
						distancia=distanciaMonedaMasValor;
						posicion=INFINITO;
						if((distancia-distanciact)<0 && Math.abs(distancia-distanciact)>=α || distancia==0)	{
							posicion=1;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 2:
					//ArribaDerecha
					if(!muro(Roboti-1,Robotj+1)) {
						MetodoDistanciaMonedaMasValor(Roboti-1,Robotj+1);
						distancia=distanciaMonedaMasValor;
						posicion=INFINITO;
						if((distancia-distanciact)<0 && Math.abs(distancia-distanciact)>=α|| distancia==0)	{
							posicion=2;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 3:
					//Izquierda
					if(!muro(Roboti,Robotj-1)) {
						MetodoDistanciaMonedaMasValor(Roboti,Robotj-1);
						distancia=distanciaMonedaMasValor;
						posicion=INFINITO;
						if((distancia-distanciact)<0 && Math.abs(distancia-distanciact)>=α || distancia==0)	{
							posicion=3;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 4:
					//Derecha
					if(!muro(Roboti,Robotj+1)) {
						MetodoDistanciaMonedaMasValor(Roboti,Robotj+1);
						distancia=distanciaMonedaMasValor;
						posicion=INFINITO;
						if((distancia-distanciact)<0 && Math.abs(distancia-distanciact)>=α || distancia==0)	{
							posicion=4;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 5:
					//Abajo
					if(!muro(Roboti+1,Robotj)) {
						MetodoDistanciaMonedaMasValor(Roboti+1,Robotj);
						distancia=distanciaMonedaMasValor;
						posicion=INFINITO;
						if((distancia-distanciact)<0 && Math.abs(distancia-distanciact)>=α || distancia==0)	{
							posicion=5;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 6:
					//AbajoIzquierda
					if(!muro(Roboti+1,Robotj-1)) {
						MetodoDistanciaMonedaMasValor(Roboti+1,Robotj-1);
						distancia=distanciaMonedaMasValor;
						posicion=INFINITO;
						if((distancia-distanciact)<0 && Math.abs(distancia-distanciact)>=α || distancia==0)	{
							posicion=6;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 7:
					//AbajoDerecha
					if(!muro(Roboti+1,Robotj+1)) {
						MetodoDistanciaMonedaMasValor(Roboti+1,Robotj+1);
						distancia=distanciaMonedaMasValor;
						posicion=INFINITO;
						if((distancia-distanciact)<0 && Math.abs(distancia-distanciact)>=α || distancia==0)	{
							posicion=7;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;

				}

				ActualizarPosicion(posicion);
				if(numMov>=movimientosMax) {
					System.out.println("Has llegado al numero maximo de movimientos que se pueden realizar. ");
					return ; 
				}
				
				
				i++;
			}//while del vector
			if(i==8) {
				System.out.println("Este laberinto no tiene solucion");
				return ;
			}
		}//while del terminar



		if(Roboti!=Salidai) {
			if(Robotj!=Salidaj) {
				terminar=false;
			}
		}

		while(!terminar) {
			GenerarVector();
			int i=0;
			while(i<vector.length) {

				MetodoDistanciaSalida(Roboti,Robotj);
				double distanciact=distanciaSalida;
				double distancia;

				switch(vector[i]) {
				case 0:
					//Arriba
					if(!muro(Roboti-1,Robotj)) {
						MetodoDistanciaSalida(Roboti-1,Robotj);
						distancia=distanciaSalida;
						posicion=INFINITO;
						if((distancia-distanciact)<0 && Math.abs(distancia-distanciact)>=α || distancia==0 ){
							posicion=0;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 1:
					//ArribaIzquierda
					if(!muro(Roboti-1,Robotj-1)) {
						MetodoDistanciaSalida(Roboti-1,Robotj-1);
						distancia=distanciaSalida;
						posicion=INFINITO;
						if((distancia-distanciact)<0 && Math.abs(distancia-distanciact)>=α || distancia==0)	{
							posicion=1;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 2:
					//ArribaDerecha
					if(!muro(Roboti-1,Robotj+1)) {
						MetodoDistanciaSalida(Roboti-1,Robotj+1);
						distancia=distanciaSalida;
						posicion=INFINITO;
						if((distancia-distanciact)<0 && Math.abs(distancia-distanciact)>=α|| distancia==0)	{
							posicion=2;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 3:
					//Izquierda
					if(!muro(Roboti,Robotj-1)) {
						MetodoDistanciaSalida(Roboti,Robotj-1);
						distancia=distanciaSalida;
						posicion=INFINITO;
						if((distancia-distanciact)<0 && Math.abs(distancia-distanciact)>=α || distancia==0)	{
							posicion=3;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 4:
					//Derecha
					if(!muro(Roboti,Robotj+1)) {
						MetodoDistanciaSalida(Roboti,Robotj+1);
						distancia=distanciaSalida;
						posicion=INFINITO;
						if((distancia-distanciact)<0 && Math.abs(distancia-distanciact)>=α || distancia==0)	{
							posicion=4;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 5:
					//Abajo
					if(!muro(Roboti+1,Robotj)) {
						MetodoDistanciaSalida(Roboti+1,Robotj);
						distancia=distanciaSalida;
						posicion=INFINITO;
						if((distancia-distanciact)<0 && Math.abs(distancia-distanciact)>=α || distancia==0)	{
							posicion=5;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 6:
					//AbajoIzquierda
					if(!muro(Roboti+1,Robotj-1)) {
						MetodoDistanciaSalida(Roboti+1,Robotj-1);
						distancia=distanciaSalida;
						posicion=INFINITO;
						if((distancia-distanciact)<0 && Math.abs(distancia-distanciact)>=α || distancia==0)	{
							posicion=6;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 7:
					//AbajoDerecha
					if(!muro(Roboti+1,Robotj+1)) {
						MetodoDistanciaSalida(Roboti+1,Robotj+1);
						distancia=distanciaSalida;
						posicion=INFINITO;
						if((distancia-distanciact)<0 && Math.abs(distancia-distanciact)>=α || distancia==0)	{
							posicion=7;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;

				}

				ActualizarPosicion(posicion);
				
				if(Roboti==Salidai) {
					if(Robotj==Salidaj) {
						terminar=true;
						System.out.println("¡Has llegado a la salida! ");
					}
				}
				if(numMov>=movimientosMax && !terminar) {
					System.out.println("Has llegado al numero maximo de movimientos que se pueden realizar. ");
					return ; 
				}
				
				i++;
				
			}//while del vector
			if(i==8) {
				System.out.println("Este laberinto no tiene solucion");
				return ;
			}
		}//while del terminar

	}


	public static void Simple(){

		while(Puntos<Precio) {
			GenerarVector();
			int i=0;
			while(i<vector.length) {

				MetodoDistanciaMonedaMasValor(Roboti,Robotj);
				double distanciact=distanciaMonedaMasValor;
				double distancia;

				switch(vector[i]) {
				case 0:
					//Arriba
					if(!muro(Roboti-1,Robotj)) {
						MetodoDistanciaMonedaMasValor(Roboti-1,Robotj);
						distancia=distanciaMonedaMasValor;
						posicion=INFINITO;
						if((distancia-distanciact)<0 || distancia==0 ){
							posicion=0;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 1:
					//ArribaIzquierda
					if(!muro(Roboti-1,Robotj-1)) {
						MetodoDistanciaMonedaMasValor(Roboti-1,Robotj-1);
						distancia=distanciaMonedaMasValor;
						posicion=INFINITO;
						if((distancia-distanciact)<0 || distancia==0)	{
							posicion=1;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 2:
					//ArribaDerecha
					if(!muro(Roboti-1,Robotj+1)) {
						MetodoDistanciaMonedaMasValor(Roboti-1,Robotj+1);
						distancia=distanciaMonedaMasValor;
						posicion=INFINITO;
						if((distancia-distanciact)<0 || distancia==0)	{
							posicion=2;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 3:
					//Izquierda
					if(!muro(Roboti,Robotj-1)) {
						MetodoDistanciaMonedaMasValor(Roboti,Robotj-1);
						distancia=distanciaMonedaMasValor;
						posicion=INFINITO;
						if((distancia-distanciact)<0 || distancia==0)	{
							posicion=3;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 4:
					//Derecha
					if(!muro(Roboti,Robotj+1)) {
						MetodoDistanciaMonedaMasValor(Roboti,Robotj+1);
						distancia=distanciaMonedaMasValor;
						posicion=INFINITO;
						if((distancia-distanciact)<0 || distancia==0)	{
							posicion=4;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 5:
					//Abajo
					if(!muro(Roboti+1,Robotj)) {
						MetodoDistanciaMonedaMasValor(Roboti+1,Robotj);
						distancia=distanciaMonedaMasValor;
						posicion=INFINITO;
						if((distancia-distanciact)<0 || distancia==0)	{
							posicion=5;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 6:
					//AbajoIzquierda
					if(!muro(Roboti+1,Robotj-1)) {
						MetodoDistanciaMonedaMasValor(Roboti+1,Robotj-1);
						distancia=distanciaMonedaMasValor;
						posicion=INFINITO;
						if((distancia-distanciact)<0 || distancia==0)	{
							posicion=6;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 7:
					//AbajoDerecha
					if(!muro(Roboti+1,Robotj+1)) {
						MetodoDistanciaMonedaMasValor(Roboti+1,Robotj+1);
						distancia=distanciaMonedaMasValor;
						posicion=INFINITO;
						if((distancia-distanciact)<0 || distancia==0)	{
							posicion=7;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;

				}

				ActualizarPosicion(posicion);
				
				if(numMov>=movimientosMax) {
					System.out.println("Has llegado al numero maximo de movimientos que se pueden realizar. ");
					return ; 
				}
				
				
				i++;
			}//while del vector
			
			if(i==8) {
				System.out.println("Este laberinto no tiene solucion");
				return ;
			}
		}//while del terminar



		if(Roboti!=Salidai) {
			if(Robotj!=Salidaj) {
				terminar=false;
			}
		}

		while(!terminar) {
			GenerarVector();
			int i=0;
			while(i<vector.length) {

				MetodoDistanciaSalida(Roboti,Robotj);
				double distanciact=distanciaSalida;
				double distancia;

				switch(vector[i]) {
				case 0:
					//Arriba
					if(!muro(Roboti-1,Robotj)) {
						MetodoDistanciaSalida(Roboti-1,Robotj);
						distancia=distanciaSalida;
						posicion=INFINITO;
						if((distancia-distanciact)<0 || distancia==0 ){
							posicion=0;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 1:
					//ArribaIzquierda
					if(!muro(Roboti-1,Robotj-1)) {
						MetodoDistanciaSalida(Roboti-1,Robotj-1);
						distancia=distanciaSalida;
						posicion=INFINITO;
						if((distancia-distanciact)<0 || distancia==0)	{
							posicion=1;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 2:
					//ArribaDerecha
					if(!muro(Roboti-1,Robotj+1)) {
						MetodoDistanciaSalida(Roboti-1,Robotj+1);
						distancia=distanciaSalida;
						posicion=INFINITO;
						if((distancia-distanciact)<0 || distancia==0)	{
							posicion=2;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 3:
					//Izquierda
					if(!muro(Roboti,Robotj-1)) {
						MetodoDistanciaSalida(Roboti,Robotj-1);
						distancia=distanciaSalida;
						posicion=INFINITO;
						if((distancia-distanciact)<0 || distancia==0)	{
							posicion=3;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 4:
					//Derecha
					if(!muro(Roboti,Robotj+1)) {
						MetodoDistanciaSalida(Roboti,Robotj+1);
						distancia=distanciaSalida;
						posicion=INFINITO;
						if((distancia-distanciact)<0 || distancia==0)	{
							posicion=4;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 5:
					//Abajo
					if(!muro(Roboti+1,Robotj)) {
						MetodoDistanciaSalida(Roboti+1,Robotj);
						distancia=distanciaSalida;
						posicion=INFINITO;
						if((distancia-distanciact)<0 || distancia==0)	{
							posicion=5;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 6:
					//AbajoIzquierda
					if(!muro(Roboti+1,Robotj-1)) {
						MetodoDistanciaSalida(Roboti+1,Robotj-1);
						distancia=distanciaSalida;
						posicion=INFINITO;
						if((distancia-distanciact)<0 || distancia==0)	{
							posicion=6;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;
				case 7:
					//AbajoDerecha
					if(!muro(Roboti+1,Robotj+1)) {
						MetodoDistanciaSalida(Roboti+1,Robotj+1);
						distancia=distanciaSalida;
						posicion=INFINITO;
						if((distancia-distanciact)<0 || distancia==0)	{
							posicion=7;
							i=INFINITO;
						}
					}else {
						posicion=INFINITO;
					}Nodos++;
					break;

				}
				
				ActualizarPosicion(posicion);
				
				if(Roboti==Salidai) {
					if(Robotj==Salidaj) {
						terminar=true;
						System.out.println("¡Has llegado a la salida! ");
					}
				}
				if(numMov>=movimientosMax && !terminar) {
						System.out.println("Has llegado al numero maximo de movimientos que se pueden realizar. ");
						return ; 
				}
				
				i++;
			}//while del vector
			
			if(i==8) {
				System.out.println("Este laberinto no tiene solucion");
				return ;
			}
		}//while del terminar

	}
	
	
	
	
	public static void ActualizarPosicion(int posicion){
		
		switch(posicion) {
		case 0:
			Arriba();
			numMov++;
			mostrarMatriz();
			break;
		case 1:
			ArribaIzquierda();
			numMov++;
			mostrarMatriz();
			break;
		case 2:
			ArribaDerecha();
			numMov++;
			mostrarMatriz();
			break;
		case 3:
			Izquierda();
			numMov++;
			mostrarMatriz();
			break;
		case 4:
			Derecha();
			numMov++;
			mostrarMatriz();
			break;
		case 5:
			Abajo();
			numMov++;
			mostrarMatriz();
			break;
		case 6:
			AbajoIzquierda();
			numMov++;
			mostrarMatriz();
			break;
		case 7:
			AbajoDerecha();
			numMov++;
			mostrarMatriz();
			break;
		}
		
	}

	public static void main(String[] args){
		Long time = new Date().getTime();
		lecturaMatriz();
		mostrarMatriz();
		coordenadasRobotyFin();
		
		//MaximaPendiente();
		//Estocastico();
		Simple();
		
		
		System.out.println();
		System.out.print("Los movimmientos utilizados en esta prueba han sido: ");
		System.out.println(cad);
		System.out.println("Tiempo transcurrido durante la ejecucion: 0.0"+(new Date().getTime()-time)+" segundos");
		System.out.println("Nodos abiertos: "+ Nodos );
	}
}



