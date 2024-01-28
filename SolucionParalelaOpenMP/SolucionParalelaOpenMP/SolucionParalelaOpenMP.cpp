// SolucionParalela.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <omp.h>
#include <ctime>
#include <omp.h>


int main() {

    int N;
    std::cout << "Ingrese el tamano del arreglo: ";
    std::cin >> N;

    //  arreglos A, B y R con tamaño N
    int* A = new int[N];
    int* B = new int[N];
    int* C = new int[N];

    // números aleatorios
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    //  valores aleatorios entre 0 y 99 para arreglos A y B
    for (int i = 0; i < N; ++i) {
        A[i] = std::rand() % 1000;
        B[i] = std::rand() % 1000;
    }

    // suma en paralelo usando OpenMP
#pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        C[i] = A[i] + B[i];
    }

    // Imprimir los arreglos
    std::cout << "Arreglo A: ";
    for (int i = 0; i < N; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Arreglo B: ";
    for (int i = 0; i < N; ++i) {
        std::cout << B[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Arreglo resultante R: ";
    for (int i = 0; i < N; ++i) {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
