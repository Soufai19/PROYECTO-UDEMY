int cargarEmpleados(struct empleado empleados[100]){
    int n = 0;
    FILE *f;
    f = fopen("empleados.txt","r");
    char cadena[255];
    char delimitador[] = ";";

    while (feof(f) == 0){

        struct empleado e;
        fgets(cadena,255,f);
        char *token = strtok(cadena,delimitador);

        if(token != NULL){
            int campo = 1;
            while (token != NULL){
                if (campo == 1){
                    strcpy(e.nombre,token);
                }
                else if(campo == 2){
                    e.id = atoi(token);
                }
                else if(campo == 3){
                    e.sueldo = atof(token);
                }
                else if(campo == 4){
                    e.horas = atoi(token);
                }
                campo++;
                token = strtok(NULL, delimitador);
            }
        }
        empleados[n] = e;
        n++;

    }
    fclose(f);
    return n;
}

void guardarEmpleados(struct empleado empleados[100], int num){
    FILE *f;
    f = fopen("empleados.txt","w");

    for (int i=0; i<num-1; i++){
        fprintf(f, "%s;%d;%.2f;%d\n",empleados[i].nombre,empleados[i].id,empleados[i].sueldo,empleados[i].horas);
    }
    fprintf(f, "%s;%d;%.2f;%d",empleados[num-1].nombre,empleados[num-1].id,empleados[num-1].sueldo,empleados[num-1].horas);

    fclose(f);
}
