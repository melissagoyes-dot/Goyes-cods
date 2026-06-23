typedef struct
{
   int ID;
   char titulo[100];
   char autor[20];
   int añoDePublicacion;
   char Estado[12];
}Libros;

float validacion(float min);
int validacionentero(int a, int b);
void limpiarSaltoDeLinea(char cadena[]);
void limpiarBuffer();
int menu();
int BuscarID(Libros libro[], int *n, int idBuscado);
void Registrarlibro(Libros libros[], int *n);
void MostrarDatosLibro(Libros libro[], int *n);
int BuscarPorTitulo(Libros libro[], int *n, char tituloBuscado[]);
void MostrarLibroEspecifico(Libros libro[], int *n);
void PedirEstado(char estadoFinal[]);
void ActualizarEstado(Libros libro[], int *n);
void EliminarLibro(Libros libro[], int *n);