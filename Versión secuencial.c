/*
El código anterior tiene dos funciones. La primera es la función de Fibonacci que se usa para calcular la secuencia de Fibonacci. La segunda es la función auxiliar que se utiliza para inicializar el vector, ejecutar el cálculo de Fibonacci y mostrar el resultado con el tiempo de ejecución.

La función Fibonacci es recursiva y utiliza la fórmula de Fibonacci para calcular la secuencia. La función auxiliar inicializa el vector y luego ejecuta un ciclo para calcular la secuencia de Fibonacci para cada elemento del vector. Luego, imprime el vector resultante y el tiempo de ejecución en segundos y minutos.

En el método principal, se llama a la función auxiliar tres veces con diferentes valores de entrada para probar el código. Para cada valor de entrada, se calcula la secuencia de Fibonacci y se muestra el tiempo de ejecución correspondiente.

En resumen, el código es una implementación de la secuencia de Fibonacci con una función auxiliar para ejecutar y mostrar los resultados con el tiempo de ejecución.
*/

//Se importan las liberías a utilizar
#include <stdio.h>
#include <string.h>
#include <time.h>

//Variables globales
int MAX_VECTOR = 1000; //Declaración de una constante llamada MAX_VECTOR

//Declaración de una función recursiva que devuelve el valor de la secuencia de Fibonacci para un número n dado
int fibonacci(int n) {
  if(n == 0 || n == 1){
    return n;
  } 
  return fibonacci(n-1) + fibonacci(n-2);
}

int main() { //Inicio método principal
  int vector[MAX_VECTOR]; //Declaración de un array llamado "vector" de tamaño MAX_VECTOR
  int i;
  clock_t iniciotem1 = clock();
  //Inicialización de los elementos del array "vector" a 35
  for (i = 0; i < MAX_VECTOR; i++) {
    vector[i] = 35;
  }
  clock_t fintem1 = clock();
  double cronometro1 = (double)(fintem1 - iniciotem1) / CLOCKS_PER_SEC;
  clock_t iniciotem2 = clock();
  //Cálculo de la secuencia de Fibonacci para cada elemento del array "vector"
  for (i = 0; i < MAX_VECTOR; i++) {
      vector[i] = fibonacci(vector[i]);
  }
  clock_t fintem2 = clock();
  double cronometro2 = (double)(fintem2 - iniciotem2) / CLOCKS_PER_SEC;
  clock_t iniciotem3 = clock();
  printf("[");
  //Impresión de cada elemento del array "vector"
  for (i = 0; i < MAX_VECTOR; i++) { 
      printf(" %d ", vector[i]);
  }
  printf("]");
  clock_t fintem3 = clock();
  double cronometro3 = (double)(fintem3 - iniciotem3) / CLOCKS_PER_SEC;
  //Impresión de los tiempos de ejecución
  printf("\n\nTiempo de ejecución del primer ciclo for: %f segundos\n", cronometro1);
  printf("Tiempo de ejecución del segundo ciclo for: %f segundos\n", cronometro2);
  printf("Tiempo de ejecución del tercer ciclo for: %f segundos\n", cronometro3);
  return 0; //Finalización del programa
} //Fin método principal
