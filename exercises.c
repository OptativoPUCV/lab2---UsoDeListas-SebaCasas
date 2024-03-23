#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
  List* list = create_list();
  for (int i = 1; i <= 10; i++) {
    int* element = (int*)malloc(sizeof(int));
    *element = i;
    pushBack(list, element);
  }
  return list;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
  int large = get_size(L);
  int sumaElem = 0;
  int* elem = first(L);
  for(int i = 0 ; i < large ; i++){
    sumaElem += *(elem);
    elem = next(L);
  }
  return sumaElem;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
  int large = get_size(L);
  int* actual = first(L);
  for(int i = 0 ; i < large ; i++){
    if(elem == *(actual))
      popCurrent(L);
    actual = next(L);
  }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
  Stack* aux = create_stack();
  while(top(P1) !=NULL && *(int*)top(P1) != -1){
    int* elemento = (int*)top(P1);
    push(aux, elemento);
    pop(P1);}
  while(top(aux) != NULL && *(int*)top(aux) != -1){
    int* elemento = (int*)top(aux);
    push(P1, (int*)top(aux));
    push(P2, elemento);
    pop(aux);}
  free(aux);
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
  Stack* P = create_stack();
  int largoP = 0;
  for(int i = 0 ; cadena[i] != '\0' ; i++){
    if(cadena[i] == '(' || cadena[i] == '{' || cadena[i] == '['){
      push(P, &cadena[i]);
      largoP++;
    }
    else{
      switch (cadena[i]) {
        case ')':
          cadena[i] = '(';
          break;
        case '}':
          cadena[i] = '{';
          break;
        case ']':
          cadena[i] = '[';
          break;}
      
      if( cadena[i] == *(char*)top(P)){
        pop(P);
        largoP--;}
      else
        return 0;
    }
  }
  if(largoP != 0)
    return 0;
  return 1;
}