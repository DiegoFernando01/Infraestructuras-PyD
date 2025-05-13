<p align='center'>
  <img width='200' heigth='225' src='https://user-images.githubusercontent.com/62605744/171186764-43f7aae0-81a9-4b6e-b4ce-af963564eafb.png'>
</p>

# 🧮 Fibonacci: Comparativa de Implementaciones Secuencial y Paralela

## 📝 Descripción del Proyecto

Este proyecto demuestra las diferencias de rendimiento entre dos implementaciones para calcular la secuencia de Fibonacci:

- ⏱️ **Versión Secuencial**: Implementación tradicional utilizando un solo hilo de ejecución
- ⚡ **Versión Paralela**: Implementación optimizada que utiliza múltiples hilos para distribuir la carga de trabajo

El objetivo es mostrar cómo la programación paralela puede mejorar significativamente el rendimiento en algoritmos computacionalmente intensivos como el cálculo recursivo de Fibonacci.

## 🔢 Algoritmo de Fibonacci

La secuencia de Fibonacci se implementa mediante la siguiente función recursiva:

```c
int fibonacci(int n) {
  if(n == 0 || n == 1) {
    return n;
  }
  return fibonacci(n-1) + fibonacci(n-2);
}
```

## 💻 Implementaciones

### Versión Secuencial

- 🔄 Procesa cada elemento de un vector de 1000 elementos secuencialmente
- 📊 Utiliza un único hilo de ejecución
- ⏲️ Mide y muestra el tiempo de ejecución de cada fase:
  - Inicialización del vector
  - Cálculo de Fibonacci
  - Impresión de resultados

### Versión Paralela

- 🚀 Utiliza múltiples hilos (2 × número de procesadores disponibles)
- 🧩 Divide el vector en bloques para evitar problemas de concurrencia
- 🔄 Cada hilo procesa su propio bloque independientemente
- 📈 Aprovecha al máximo los recursos del sistema para un rendimiento óptimo

## 🛠️ Compilación y Ejecución

### Para la versión secuencial:

```bash
gcc "Versión secuencial.c" -o fibonacci_secuencial
./fibonacci_secuencial
```

### Para la versión paralela:

```bash
gcc "Versión paralela.c" -o fibonacci_paralelo -pthread
./fibonacci_paralelo
```

## 📊 Resultados y Análisis

Al ejecutar ambas versiones, se puede observar una notable diferencia en tiempo de ejecución:

- La versión secuencial procesa los 1000 elementos uno tras otro
- La versión paralela reparte el trabajo entre múltiples hilos

Esto demuestra cómo la programación paralela puede aprovechar mejor los recursos hardware disponibles, especialmente en sistemas multicore modernos.

## 📋 Requisitos

- Compilador de C (GCC recomendado)
- Soporte para pthreads (incluido en la mayoría de sistemas UNIX/Linux)
- Para Windows: compilador compatible con pthreads, como MinGW

## 💡 Conclusiones

Este proyecto ilustra de manera práctica cómo la programación paralela puede mejorar significativamente el rendimiento en problemas computacionalmente intensivos, especialmente aquellos que pueden dividirse en tareas independientes.

---

🔬 **Desarrollado en Infraestructuras Paralelas y Distribuidas.**
