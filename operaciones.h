#ifndef OPERACIONES_H_INCLUDED
#define OPERACIONES_H_INCLUDED


struct empleado{
    char nombre[255];
    int id;
    float sueldo;
    int horas;
};

void mostrarMenu();
void listarEmpleados(struct empleado empleados[100], int num);
int alta(struct empleado empleados[100], int num);
int baja(struct empleado empleados[100], int num);
void consultarDatosEmpleado(struct empleado empleados[100], int num);
void modificarSueldo(struct empleado empleados[100], int num);
void modificarHoras(struct empleado empleados[100], int num);

#endif // OPERACIONES_H_INCLUDED
