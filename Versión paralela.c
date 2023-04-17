//se importan las librerías que se van a utilizar
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

int num_processors;

//inicialización de las variables globales
int MAX_VECTOR = 1000;
int MAX_THREADS;
int vector[1000];

//función que calcula los números de la sucesión de fibonacci de manera
//recursiva

int fibonacci(int n) {
  if(n == 0 || n == 1){
    return n;
  } 
  return fibonacci(n-1) + fibonacci(n-2);
}

//se inicializa el vector con un valor entero de 35 en cada posición
void inicializar() {
    for (int i = 0; i < MAX_VECTOR; i++) {
        vector[i] = 35;
    }
}

/*
 esta función separa el vector en bloques y asigna un índice a cada hilo
 con una posición de inicio y una final, lo cual evita que que haya errores
 de concurrencia al acceder a los elementos de un vector, es decir, que dos
 hilos no accedan al mismo elemento del vector

 calcula el fibonacci de 35 para cada posición del vector y almacena el
 resultado en la misma
*/

void *operacion(void *arg) {
    int indice = *((int *) arg);
    int tamano_bloque = MAX_VECTOR / MAX_THREADS;
    int inicio = indice * tamano_bloque; //se especifica el inicio del vector
    int fin = (indice + 1) * tamano_bloque; //se especifica el final del vector

    for (int i = inicio; i < fin; i++) {
        vector[i] = fibonacci(vector[i]);
    }
    return NULL;
}

//imprime los valores de todas las posiciones del vector
void imprimir() {
    printf("[");

    for (int i = 0; i < MAX_VECTOR; i++) {
        printf(" %d ", vector[i]);
    }
    printf("]\n");
}

/*
  se crea un vector de tipo pthread_t 
  se crea un vector de indices para identificar cada uno de los hilos
  y pasar el puntero de este vector a la función operacion
*/
int main() {
    //se calcula y almacena el número de procesadores en el sistema
    num_processors = (int) sysconf(_SC_NPROCESSORS_ONLN);

    //y el número de hilos a utilizar en el programa
    MAX_THREADS = num_processors*2;

    pthread_t threads[MAX_THREADS];
    int indices[MAX_THREADS];
    inicializar();

    //inicia los hilos y se pasa como parámetro el indicador de cada hilo, 
    //la función a ejecutar por el hilo y los argumentos que recibe dicha función
    for (int i = 0; i < MAX_THREADS; i++) {
        indices[i] = i;
        pthread_create(&threads[i], NULL, operacion, &indices[i]);
    }

    //Este bucle asegura que todos los hilos hayan terminado su ejecución
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    imprimir();
    return 0;
}