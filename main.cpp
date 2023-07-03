#include <iostream>
#include <string>
#include <fstream>
#include "Lib.hpp"

// RAMA PARA FILES
using namespace std;

// STRUCTS PARA ARCHIVOS Y APLICAICION

int main()
{
    string Usuario, Clave;
    int Opcion, Continuar = 1;

    cout << "----------------Restaurante Sabor Casero----------------" << endl;
    cout << endl;
    do
    {
        cout << "0) SALIR 1) SISTEMA DE VENTAS  2) HISTORIAL" << endl;
        cin >> Opcion;

        switch (Opcion)
        {
        case 0:
            cout << "Para confirmar Salida del Sistema Ingrese 0, sino Ingrese 1: " << endl;
            cin >> Continuar;
            break;
        case 1: // Sistema de Ventas
            cout << "**** Come con confianza ****" << endl;
            cout << "Ingrese el usuario: " << endl;
            cin >> Usuario;
            cout << "Ingrese la clave: " << endl;
            cin >> Clave;

            InicioSesion(Usuario, Clave);
            break;

        case 2: // Configuraciones
            cout << "**** Come con confianza ****" << endl;
            cout << "Ingrese el usuario Administrador: " << endl;
            cin >> Usuario;
            cout << "Ingrese la clave de Administrador: " << endl;
            cin >> Clave;
            InicioSesionAdmin(Usuario, Clave);

            break;
        }

    } while (Continuar == 1);

    return 0;
}