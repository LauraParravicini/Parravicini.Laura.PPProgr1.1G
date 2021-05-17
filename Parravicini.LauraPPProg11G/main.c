#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3

typedef struct{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
}eNotebook;

float aplicarDescuento(float precio);
int contarCaracteres(char cadena[],char buscado);
int ordenarNotebooks(eNotebook notebooks[], int tam);

int main()
{
    //Ejercicio 1
    float precioPrueba = 100;
    float precioDescuento = aplicarDescuento(precioPrueba);
    printf(" Ejercicio 1: Aplicar descuento: %.2f",precioDescuento);

    //Ejercicio 2
    char cadenaPrueba[10] = "papanatas";
    char buscadoPrueba = 'a';
    int encontrados = contarCaracteres(cadenaPrueba,buscadoPrueba);
    printf("\n\n Ejercicio 2: Se encontro el caracter buscado %d veces\n",encontrados);

    //Ejercicio 3
    printf("\n Ejercicio 3: \n");
    eNotebook notebooks[TAM] = { {1,"Intel","hp",400} , {2,"AMD","dell",450}, {3,"AMD","dell",350} };
    ordenarNotebooks(notebooks,TAM);
    for(int i = 0; i < TAM; i++){
        printf(" %d   %s    %.2f   %s \n", notebooks[i].id, notebooks[i].marca , notebooks[i].precio ,notebooks[i].procesador);
    }

    return EXIT_SUCCESS;
}

float aplicarDescuento(float precio){
    float descuento;
    float precioFinal;
    descuento = precio *5/100;
    precioFinal = precio - descuento;
    return precioFinal;
}

int contarCaracteres(char cadena[],char buscado){
    int cant = 0;
    if(cadena != NULL){
        for(int i = 0; i < strlen(cadena); i++){
            if(cadena[i] == buscado){
                cant++;
            }
        }
    }
    return cant;
}

int ordenarNotebooks(eNotebook notebooks[], int tam){
    eNotebook aux;
    int status = -1;
    if(notebooks != NULL && tam > 0){
        for(int i = 0; i < tam -1; i++){
            for(int j = i+1; j < tam; j++){
                if( strcmp(notebooks[i].marca,notebooks[j].marca) > 0 ||
                    ( strcmp(notebooks[i].marca,notebooks[j].marca) == 0 &&  notebooks[i].precio > notebooks[j].precio) ){ //mayor a cero: el segundo str mas grande - menor a cero: el primero mas grande
                    aux = notebooks[i];
                    notebooks[i] = notebooks[j];
                    notebooks[j] = aux;
                }
            }
        }
        status = 0;
    }
    return status;
}
