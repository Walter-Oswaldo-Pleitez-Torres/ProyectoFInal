#include <iostream>
#define Lib_h

using namespace std;



void CrearFichero(string Nombre, int Cantidad, float Precio, int ContProducto, int ContPedido, int ContOrden, string Fecha);
void LeerFichero();
void CrearMasVendido(int contsandwich, int contpupusas, int contcroi, int contpapas, int contcafe, int contchoco, int contsoda, int contlicuado, string Fecha);
void InicioSesion(string Usuario, string Clave);
void InicioSesionAdmin(string Usuario, string Clave);
void MenuDesplegable();
void Ordenar();
int BuscadorPosicion(string NombreItem, string PosicionProductos[]);
float BuscadorPrecio(int PosicionPrecio, float BuscarPrecio[]);
float CalculoPagoIndividuo(float PrecioItem, int CantItem);
float SumaPagosGrales(float PagoGral[], int CantProductos);
float SumaTotales(float Totales[], int CantClientes);