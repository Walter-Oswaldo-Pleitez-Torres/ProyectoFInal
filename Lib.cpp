#include <iostream>
#include "Lib.hpp"
#include <fstream>

using namespace std;

struct Inventario
{
    string Productos[8] = {"SANDWICH", "PUPUSAS", "CROISANDWICH", "PAPAS", "CAFE", "CHOCOLATE", "SODA", "LICUADO"};
    float Precios[8] = {0.75, 0.35, 0.50, 1.00, 0.35, 0.40, 0.50, 1.25};
};

void CrearFichero(string Nombre, int Cantidad, float Precio, int ContProducto, int ContPedido, int ContOrden, string Fecha)
{
    ofstream Registro((Fecha + ".txt").c_str(), ios ::out | ios::app);
    // Metodo para comprobar si se crea el archivo
    if (Registro.fail() == true)
    {
        cout << "No se logro crear el archivo";
        return;
    }
    else
    {
        // Insertar texto al fichero
        Registro << "-----------------------------------" << endl;
        Registro << "---------- Orden No: " << ContOrden << " -----------" << endl;
        Registro << "Pedido No: " << ContPedido << " - Producto No: " << ContProducto << endl;
        Registro << "Nombre Producto: " << Nombre << endl;
        Registro << "Cantidad Producto: " << Cantidad << endl;
        Registro << "Precio Unitario Producto: " << Precio << endl;
        Registro << "-----------------------------------" << endl;
        // Cerrar la conexion con el fichero
        Registro.close();
    }
}

void LeerFichero()
{
    // Crear una variable para la salida del texto
    int opcion;
    string texto;
    string nombreArchivo;

    // Crear dos opciones para el administrador, ya sea para ver el historial de venta o la comida mas vendida

    cout << "Deseas ver el historial de ventas o la comida mas consumida por dia: 1 - Historial o 2 - Comida: ";
    cin >> opcion;

    if (opcion == 1)
    {
        cout << "Ingrese el dia que quieres ver: ";
        cin >> nombreArchivo;
        ifstream fichero(nombreArchivo + ".txt", ios::in);

        if (fichero.fail())
        {
            cout << "No existe archivo" << endl;
        }

        // Leer el fichero
        while (getline(fichero, texto))
        {
            // Salida
            cout << texto << endl;
        }
        // Cerrar la conexion con el fichero
        fichero.close();
    }
    else if (opcion == 2)
    {
        cout << "Ingrese el dia que quieres ver: ";
        cin >> nombreArchivo;
        ifstream fichero(nombreArchivo + "-comida" + ".txt", ios::in);

        if (fichero.fail())
        {
            cout << "No existe archivo" << endl;
        }

        // Leer el fichero
        while (getline(fichero, texto))
        {
            // Salida
            cout << texto << endl;
        }
        // Cerrar la conexion con el fichero
        fichero.close();
    }
    else
    {
        cout << "Esa opcion no existe" << endl;
    }
}

void CrearMasVendido(int contsandwich, int contpupusas, int contcroi, int contpapas, int contcafe, int contchoco, int contsoda, int contlicuado, string Fecha)
{
    struct Inventario pr;
    int mayor = 0;
    string producto;
    // Pasa todas las variables a un array para ver la que mas productos de la misma a vendido
    int array[8] = {contsandwich, contpupusas, contcroi, contpapas, contcafe, contchoco, contsoda, contlicuado};
    for (int i = 0; i < 8; i++)
    {
        if (array[i] > mayor)
        {
            mayor = array[i];
            producto = pr.Productos[i];
        }
    }
    ofstream archivo((Fecha + "-comida" + ".txt").c_str(), ios::out);
    if (archivo.fail() == true)
    {
        cout << "No se logro crear el archivo";
        return;
    }
    else
    {
        archivo << "--- El producto mas vendido del " << Fecha << " ha sido ---" << endl;
        archivo << "----- " << producto << " -----" << endl;
        archivo << "----- " << mayor << " -----" << endl;
        archivo.close();
    }
}

void InicioSesion(string Usuario, string Clave)
{
    string User1 = "user1", Clave1 = "12345";
    string User2 = "user2", Clave2 = "54321";
    string User3 = "user3", Clave3 = "56789";
    bool Acceso1 = (Usuario == User1) && (Clave == Clave1);
    bool Acceso2 = (Usuario == User2) && (Clave == Clave2);
    bool Acceso3 = (Usuario == User3) && (Clave == Clave3);

    if ((Acceso1) || (Acceso2) || (Acceso3))
    {
        cout << "ACCESO CONCEDIDO" << endl;
        cout << endl;
        Ordenar();
    }
    else
    {
        cout << endl;
        cout << "ACCESO DENEGADO" << endl;
    }
}

void InicioSesionAdmin(string Usuario, string Clave)
{
    string User1 = "Admin1", Clave1 = "12345";
    string User2 = "Admin2", Clave2 = "54321";
    bool Acceso1 = (Usuario == User1) && (Clave == Clave1);
    bool Acceso2 = (Usuario == User2) && (Clave == Clave2);

    if ((Acceso1) || (Acceso2))
    {
        cout << "ACCESO CONCEDIDO" << endl;
        cout << endl;
        LeerFichero();
    }
    else
    {
        cout << endl;
        cout << "ACCESO DENEGADO" << endl;
    }
}

void MenuDesplegable()
{
    cout << " " << endl;
    cout << "************ MENU ************" << endl;
    cout << "------------ COMIDA RAPIDA ------------" << endl;
    cout << "1) Sandwich $0.75" << endl;
    cout << "2) Pupusas $0.35 c/u" << endl;
    cout << "3) Croisandwich $0.50" << endl;
    cout << "4) Papas" << endl;

    cout << "------------ BEBIDAS CALIENTES ------------" << endl;
    cout << "5) Cafe $0.35" << endl;
    cout << "6) Chocolate $0.40" << endl;

    cout << "------------ BEBIDAS FRIAS ------------" << endl;
    cout << "7) Soda $0.50" << endl;
    cout << "8) Licuado $1.25" << endl;
    cout << "************************" << endl;
    cout << " " << endl;
}

void Ordenar()
{
    int contsandwich = 0, contpupusas = 0, contcroi = 0, contpapas = 0, contcafe = 0, contchoco = 0, contsoda = 0, contlicuado = 0;
    struct Inventario Menu;
    float TotalIndividuo, TotalDefinitivo; // TOTAL A PAGAR PARA UN PEDIDO
    float TotalPagarPorPersona, PrecioItem, PagoItem;
    int CantidadPersonas, CantidadProductos, CantidadItem, PosicionItem, Continuar = 1;
    int ContadorProductos = 0, ContadorPedidos = 0, ContadorOrden = 0;
    string NombreItem;
    string Fecha;

    cout << "Ingrese la fecha que se hace la compra: ";
    cin >> Fecha;

    do
    {
        cout << "*********** AREA DE RECEPCION DE ORDENES ***************" << endl;
        cout << "Para cuantas personas desean ordenar: " << endl;
        cin >> CantidadPersonas;
        ContadorOrden++;

        float TotalOrden[CantidadPersonas];

        for (int i = 0; i < CantidadPersonas; i++) // Ingresa los datos de Todos los Clientes
        {
            ContadorPedidos++;
            MenuDesplegable();
            cout << "*********** Cliente " << i + 1 << "***********" << endl;
            cout << "Cuantos Productos del Menu llaman su atencion: " << endl;
            cin >> CantidadProductos;

            string CarritoNombre[CantidadProductos];
            float CarritoPrecio[CantidadProductos];
            float CarritoPago[CantidadProductos];

            for (int j = 0; j < CantidadProductos; j++) // Ingresa todos los Pedidos de un Cliente
            {
                cout << endl;
                cout << "*********** Ingrese Pedido ***********" << endl;
                ContadorProductos++;
                cout << "Ingrese el nombre del producto que desea comprar: " << endl;
                cin >> NombreItem;                                           // PIDE EL NOMBRE DEL PRODUCTO DESEADO
                BuscadorPosicion(NombreItem, Menu.Productos);                // Confirmara que el producto exista o que se haya escrito bien
                PosicionItem = BuscadorPosicion(NombreItem, Menu.Productos); // PosicionItem tiene la posicion del precio
                BuscadorPrecio(PosicionItem, Menu.Precios);                  // PIDE LA POSICION DEL PRECIO DEL PRODUCTO INGRESADO
                PrecioItem = BuscadorPrecio(PosicionItem, Menu.Precios);     // ALMACENA EL PRECIO (FLOAT) DEL PRODUCTO

                cout << "Ingrese la cantidad de " << NombreItem << endl;
                cin >> CantidadItem; // PIDE LA CANTIDAD DE UN MISMO PRODUCTO DESEADO

                CrearFichero(NombreItem, CantidadItem, PrecioItem, ContadorProductos, ContadorPedidos, ContadorOrden, Fecha);
                // AnalizarMasVendido(NombreItem, CantidadItem);
                cout << endl;
                cout << "*********** Fin Ingreso ***********" << endl;

                CalculoPagoIndividuo(PrecioItem, CantidadItem);            // CALCULA PAGO POR PEDIDO DE CLIENTE
                PagoItem = CalculoPagoIndividuo(PrecioItem, CantidadItem); // ALMACENA EL MONTO DE CADA PEDIDO

                CarritoNombre[j] = NombreItem;                // ALMACENA EL NOMBRE DEL PRODUCTO DESEADO
                CarritoPrecio[j] = PrecioItem;                // ALMACENA EL PRECIO A PAGAR POR UN MISMO PRODUCTO
                CarritoPago[j] = PagoItem;                    // ALMACENA EL MONTO DEL PRODUCTO INGRESADO
                for (int i = 0; i < NombreItem.length(); i++) // CONVIERTE TODAS LAS PALABRAS EN MAYUSCULAS
                {
                    NombreItem[i] = towupper(NombreItem[i]);
                }
                // Agregar a cada contador la cantidad de productos dependiendo el producto que se lleva
                if (NombreItem == "SANDWICH")
                {
                    contsandwich += CantidadItem;
                }
                else if (NombreItem == "PUPUSAS")
                {
                    contpupusas += CantidadItem;
                }
                else if (NombreItem == "CROISANDWICH")
                {
                    contcroi += CantidadItem;
                }
                else if (NombreItem == "PAPAS")
                {
                    contpapas += CantidadItem;
                }
                else if (NombreItem == "CAFE")
                {
                    contcafe += CantidadItem;
                }
                else if (NombreItem == "CHOCOLATE")
                {
                    contchoco += CantidadItem;
                }
                else if (NombreItem == "SODA")
                {
                    contsoda += CantidadItem;
                }
                else if (NombreItem == "LICUADO")
                {
                    contlicuado += CantidadItem;
                }
            } // FIN DEL BUCLE DE INGRESO DE PEDIDOS DE UNA PERSONA

            TotalPagarPorPersona = SumaPagosGrales(CarritoPago, CantidadProductos);

            for (int i = 0; i < CantidadProductos; i++)
            {
                cout << endl;
                cout << "--------- Vea su Pedido ----------" << endl;
                cout << "Nombre: " << CarritoNombre[i] << endl;
                cout << "Precio: " << CarritoPrecio[i] << endl;
                cout << "Total por Pedido: " << CarritoPago[i] << endl;
                cout << "---------- Fin Pedido ----------" << endl;

            } // FIN DE BUCLE PARA IMPRIMIR LOS PEDIDOS DE CADA PERSONA
            cout << "Total a Pagar por Persona: " << TotalPagarPorPersona << endl;
            TotalOrden[i] = TotalPagarPorPersona;

        } // FIN DE BUCLE DE INGRESO DE PEDIDOS DE TODAS LAS PERSONAS

        TotalDefinitivo = SumaTotales(TotalOrden, CantidadPersonas); // TOTAL A PAGAR POR TODAS LAS PERSONAS DE LA ORDEN

        cout << " " << endl;
        cout << "*********************************************************" << endl;
        cout << "El Total a Pagar para todas las personas de la Orden es de: $" << TotalDefinitivo << endl;
        cout << "*********************************************************" << endl;
        cout << " " << endl;

        cout << "Si desea PERMANECER en el Area de Recepcion de Ordenes Ingrese 1, si desea SALIR Ingrese 0: " << endl;
        cin >> Continuar;
    } while (Continuar == 1);

    CrearMasVendido(contsandwich, contpupusas, contcroi, contpapas, contcafe, contchoco, contsoda, contlicuado, Fecha);
}

int BuscadorPosicion(string NombreItem, string PosicionProductos[])
{

    for (int i = 0; i < NombreItem.length(); i++) // CONVIERTE TODAS LAS PALABRAS EN MAYUSCULAS
    {
        NombreItem[i] = towupper(NombreItem[i]);
    }

    int Posicion;
    for (int i = 0; i < 8; i++) // ENCUENTRA LA POSICION DEL PRODUCTO EN EL ARRAY
    {
        if (NombreItem == PosicionProductos[i])
        {
            Posicion = i;
        }
    }
    return Posicion;
}

float BuscadorPrecio(int PosicionPrecio, float BuscarPrecio[])
{ // Aqui entra la posicion del precio que es la misma del producto
    float PrecioProducto;
    PrecioProducto = BuscarPrecio[PosicionPrecio];

    return PrecioProducto;
}

float CalculoPagoIndividuo(float PrecioItem, int CantItem)
{
    float Pagar = PrecioItem * CantItem;
    return Pagar;
}

float SumaPagosGrales(float PagoGral[], int CantProductos)
{
    float TotalGral;
    for (int i = 0; i < CantProductos; i++)
    {
        TotalGral = TotalGral + PagoGral[i];
    }
    return TotalGral;
}

float SumaTotales(float Totales[], int CantClientes)
{
    float SumaTotalPagar;
    for (int i = 0; i < CantClientes; i++)
    {
        SumaTotalPagar = SumaTotalPagar + Totales[i];
    }

    return SumaTotalPagar;
}