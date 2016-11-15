// Ingenieria de Software 
// Pamela Blacutt
// Practica 1
// 14-11-16

#include "stdafx.h"

#define ANCHOMUNDO 50
#define FPS 20 //Frames por segundo

int main()
{
	//---INICIALIZACION DE VARIABLES---

	//Variables personaje
	int posicionPersonaje = ANCHOMUNDO / 2;
	char teclaPulsada;

	//Variables bala
	int posicionBala = 0;
	bool disparar = false;
	int contadorPosicionBala = 0;
	int direccionBala = 1; //+1 a la derecha -1 a la izquierda

	//Variables generales
	int delay = 1000 / 20;

	while (true)
	{

		//Pone el mundo al medio
		printf("\n\n\n\n\n\n             ");

		if (_kbhit())//Devuelve 0 si no se ha pulsado una tecla
		{
			teclaPulsada = _getch();

			//---MOVIMIENTO---

			//Movimiento derecha
			if (teclaPulsada=='p') {

				if (posicionPersonaje < ANCHOMUNDO) {//Proteccion para que no se salga del mundo

					posicionPersonaje = posicionPersonaje + 1;
				}
			}

			//Movimiento izquierda
			if (teclaPulsada == 'o') {

				if (posicionPersonaje >=0) { //Proteccion para que no se salga del mundo

					posicionPersonaje = posicionPersonaje - 1;
				}
			}


			//---DISPARO---

			//Disparo hacia la derecha
			if (teclaPulsada == 'm' && !disparar) {

				disparar = true;
				direccionBala = 1;
			}

			//Disparo hacia la izquierda
			else if (teclaPulsada == 'n' && !disparar) {

				disparar = true;
				direccionBala = -1;
			}
		}

		//Se realizó un disparo
		if (disparar) {

			contadorPosicionBala = contadorPosicionBala + 1;
			posicionBala = posicionPersonaje + (contadorPosicionBala * direccionBala);

			if (contadorPosicionBala >= ANCHOMUNDO || contadorPosicionBala <= 0) { //Fin del mundo

				disparar = false;
				contadorPosicionBala = 0;
			}
		}
		
		//---IMPRIMIR MUNDO---

		for (int i = 0; i < ANCHOMUNDO; i++) {

			if(i== posicionPersonaje)  printf("%c", '*');				//imprime personaje
			else if (i == posicionBala && disparar)  printf("%c", '.'); //imprime bala
			else  printf("%c", '-');									//imprime mundo
		}

		Sleep(delay);
		system("cls");
	}

    return 0;
}

