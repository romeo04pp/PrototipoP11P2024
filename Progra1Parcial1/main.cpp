// PrototipoP11P2024
// Nombre: Pablo Romeo Palencia Rosales   Carnet: 9959-23-736
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

#define NUMERO_EMPRESAS 5 //alumnos
#define NUMERO_AÑOS 5 //materias
#define NUMERO_INGRESOS 5 //notas
#define MAX_INGRESOS 1000000 //notas max
#define MIN_INGRESOS 1000 //notas min
#define MAXIMA_LONGITUD_CADENA 100 //igual

void llamaCiclo();
int busquedaAleatorios(int minimo, int maximo);
void llenarMatriz(float matriz[NUMERO_EMPRESAS][NUMERO_INGRESOS + 1]);
void imprimirMatrizLinea();
float imprimirMatriz(float matriz[NUMERO_EMPRESAS][NUMERO_INGRESOS + 1], char alumnos[NUMERO_EMPRESAS][MAXIMA_LONGITUD_CADENA], string nombreIndustria);

//inicia Main
int main()
{
    srand(getpid());
    llamaCiclo();
    return 0;
}
//termina Main, llama a llamaCiclo y ya

//inicia llamaCiclo
void llamaCiclo()
{
    float matriz_camara_industria[NUMERO_EMPRESAS][NUMERO_INGRESOS + 1];
    float matriz_camara_construccion[NUMERO_EMPRESAS][NUMERO_INGRESOS + 1];
    float matriz_camara_transporte[NUMERO_EMPRESAS][NUMERO_INGRESOS + 1];
    char opcion;
    bool repetir = true;

    float promedio_camara_industria; //facu1
    float promedio_camara_construccion;//facu2
    float promedio_camara_transporte;//facu3

    char empresas[NUMERO_EMPRESAS][MAXIMA_LONGITUD_CADENA] = {"Empresa1","Empresa2","Empresa3","Empresa4","Empresa5"};
    do
    {
        system("cls");
        promedio_camara_industria=0;
        promedio_camara_construccion=0;
        promedio_camara_transporte=0;
        cout << "*** Comparativo de Industrias ***" << endl << endl;
        llenarMatriz(matriz_camara_industria);
        promedio_camara_industria = imprimirMatriz(matriz_camara_industria, empresas, "Camara de Industria");
        llenarMatriz(matriz_camara_construccion);
        promedio_camara_construccion = imprimirMatriz(matriz_camara_construccion, empresas, "Camara de Construcción");
        llenarMatriz(matriz_camara_transporte);
        promedio_camara_transporte = imprimirMatriz(matriz_camara_transporte, empresas, "Camara de Transporte");
        if (promedio_camara_industria > promedio_camara_construccion && promedio_camara_industria > promedio_camara_transporte)
        {
            cout << " La industria con mayor monto de ventas es : " << "Camara de Industria" << " Promedio: Q " << promedio_camara_industria << endl;
        } else
        if (promedio_camara_construccion > promedio_camara_industria && promedio_camara_construccion > promedio_camara_transporte)
        {
            cout << " La industria con mayor monto de ventas es : " << "Camara de Construccion" << " Promedio: Q " << promedio_camara_construccion << endl;
        } else
        if (promedio_camara_transporte> promedio_camara_construccion && promedio_camara_transporte > promedio_camara_industria)
        {
            cout << " La industria con mayor monto de ventas es : : " << "Camara de Transporte" << " Promedio: Q " << promedio_camara_transporte << endl;
        } else
        {
            cout << " Algunas industrias tienen el mismo promedio " << endl << endl;
        }
        cout << "Desea otro calculo (s/n)? ";
        cin >> opcion;
        if (opcion == 'n')
        {
            repetir=false;
        }
    } while (repetir);
}
//termina llamaCiclo

//para aleatorios del monto de ventas
int busquedaAleatorios(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void llenarMatriz(float matriz[NUMERO_EMPRESAS][NUMERO_INGRESOS + 1])
{
    int y, x;
    for (y = 0; y < NUMERO_EMPRESAS; y++)
    {
        float suma = 0;
        int monto_ventas = 0; //calificacion
        for (x = 0; x < NUMERO_EMPRESAS; x++)
        {
            if (x == 0 || x == 3)  //año 2015 y 2018
            {
                monto_ventas = busquedaAleatorios(MIN_INGRESOS, MAX_INGRESOS);
            } else if (x == 1 || x == 4)  //año 2016
            {
                monto_ventas = busquedaAleatorios(MIN_INGRESOS, MAX_INGRESOS);
            } else if (x == 2)  //año 2017
            {
                monto_ventas = busquedaAleatorios(MIN_INGRESOS, MAX_INGRESOS);
            }
            suma += (float)monto_ventas;
            matriz[y][x] = monto_ventas;
            monto_ventas=0;
        }
        // Agregar promedio

        matriz[y][NUMERO_EMPRESAS] = suma;
    }
}

void imprimirMatrizLinea()
{
    int x;

    cout << "+--------";
    for (x = 0; x < NUMERO_EMPRESAS + 1; x++)
    {
        cout << "+---------";
    }
    cout << "+\n";
}
float imprimirMatriz(float matriz[NUMERO_EMPRESAS][NUMERO_INGRESOS + 1], char empresas[NUMERO_EMPRESAS][MAXIMA_LONGITUD_CADENA], string nombreIndustria) //nombrefacultad
{
    //Funciòn que imprime la matriz en pantalla y realizando los calculos necesarios del promedio
    int y, x, an=4;
    float promedioMayor = matriz[0][NUMERO_INGRESOS];
    float promedioMenor = matriz[0][NUMERO_INGRESOS];
    float totalGeneral = 0;
    float promedioGeneral = 0;
    char empresaPromedioMayor[MAXIMA_LONGITUD_CADENA];
    char empresaPromedioMenor[MAXIMA_LONGITUD_CADENA];
    memcpy(empresaPromedioMayor, empresas[0], MAXIMA_LONGITUD_CADENA);
    memcpy(empresaPromedioMenor, empresas[0], MAXIMA_LONGITUD_CADENA);
    cout << nombreIndustria << endl;
    cout << "(AÑO 2015)    (AÑO 2016)    (AÑO 2017)    (AÑO 2018)" << endl;
    imprimirMatrizLinea();
    cout << setw(9) << "Empresa";
    for (x = 0; x < NUMERO_INGRESOS; x++)
    {
        cout << setw(9) << "201" << an;
        an++;
    }
    cout << setw(8) << "Total" << endl;
    imprimirMatrizLinea();
    for (y = 0; y < NUMERO_EMPRESAS; y++)
    {
        cout << "!" << setw(8) << empresas[y] << "!";
        float suma = 0;
        for (x = 0; x < NUMERO_EMPRESAS; x++)
        {
            int monto_ventas = matriz[y][x];
            cout << setw(9) << monto_ventas << "!";
        }
        float promedio = matriz[y][NUMERO_INGRESOS];
        totalGeneral += matriz[y][NUMERO_INGRESOS];
        if (promedio > promedioMayor)
        {
            promedioMayor = promedio;
            memcpy(empresaPromedioMayor, empresas[y], MAXIMA_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor)
        {
            promedioMenor = promedio;
            memcpy(empresaPromedioMenor, empresas[y], MAXIMA_LONGITUD_CADENA);
        }
        cout << setw(9) << fixed << setprecision(2) << promedio << "!" << endl;
        imprimirMatrizLinea();
    }
    promedioGeneral = totalGeneral / NUMERO_EMPRESAS;
    cout << "Monto de ventas mayor: " << setw(10) << empresaPromedioMayor <<  setw(10) << " Q " << promedioMayor << endl;
    cout << "Monto de ventas menor: " << setw(10) << empresaPromedioMenor <<  setw(10) << " Q " << promedioMenor << endl;
    cout << "Monto de ventas promedio : " << setw(10) << " Q " <<  promedioGeneral << endl << endl;
    return promedioGeneral;
}
