#include <stdio.h>
#include <string.h> // Manipular cadenas
#include <stdlib.h> // Gestionar memoria dinamica

#define Max 15
#define valor -1

// Estructuras a utilizar
struct equipo {
    int tipoE;
    int nSerie;
    char marca[20];
    char modelo[20];
};
typedef struct equipo Equipo;

struct historico {
    int id;
    char motivo[80];
    char personaAt[80];
    char fecha[Max];
};
typedef struct historico Historico;

// Funciones utilizadas
void menuPrincipal();
void menuInsertar();
void menuModificar();
void menuEliminar();
void menuBuscar();
void menuMostrar();
void menuInsertarH();
void menuMostrarH();
void menuModificarH();

// Funciones de operaciones base
char existeEquipo(int nSerie, Equipo * equipo);
char existeEquipoT(int tipo, Equipo *equipo);
char existeEquipoM(char lineaM, Equipo *equipo);
char existeHistorial(int id, Historico *historico);
char insertarEquipo(Equipo equipo);
char eliminar(int nSerie);
char modificarEquipo(Equipo equipo);
char insertarHistorial(Historico historico);
char modificarHistorial(Historico historico);
void menuBuscarH();

//Funcion de lectura de cadenas
int leerCad(char *cad, int n); // Recibe la cadena y su tamaño

// Funcion obtener desde archivo
Equipo *obtenerEquipos(int *n);
Historico *obtenerEquiposH(int *n);

char linea[Max];


// Funcion Principal
int main() {
    menuPrincipal();
    return 0;
}

void menuPrincipal() {
    char repetir = 1;
    int opc = 0;

    do {
        printf("\n\t\t.:MENÚ:.");
        printf("\n1. Insertar equipo");
        printf("\n2. Mostrar lista de equipos");
        printf("\n3. Modificar un equipo");
        printf("\n4. Eliminar un equipo");
        printf("\n5. Buscar equipo por Nº de serie, tipo o marca");
        printf("\n6. Insertar historial");
        printf("\n7. Mostrar historial");
        printf("\n8. Modificar historial");
        printf("\n9. Buscar historial por Nº de serie");
        printf("\n10 Salir");
        printf("\nDigite la opción: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                menuInsertar();
                break;
            case 2:
                menuMostrar();
                break;
            case 3:
                menuModificar();
                break;
            case 4:
                menuEliminar();
                break;
            case 5:
                menuBuscar();
                break;
            case 6:
                menuInsertarH();
                break;
            case 7:
                menuMostrarH();
                break;
            case 8:
                menuModificarH();
                break;
            case 9:
                menuBuscarH();
                break;
            case 10:
                repetir = 0;
                break;
            default:
                printf("\nError. Ingrese una opción válida");
        }
    } while (repetir);
}

// Funciones de los equipos
void menuInsertar() {
    Equipo equipo;
    int nSerie = 0;
    char repetir = 1;
    char respuesta[Max];

    do {
        printf("\n\t.:INSERTAR EQUIPO:.");
        printf("\nNúmero de serie: ");
        scanf("%d", &nSerie);

        if (!existeEquipo(nSerie, &equipo)) {
            equipo.nSerie = nSerie;
            printf("\nTipo de equipo: ");
            int tipo = 0;
            printf("\n1. CPU | 2. Monitor | 3. Impresora | 4. Escaner");
            printf("\nOpcion: ");
            scanf("%d", &tipo);

            switch (tipo) {
                case 1:
                    printf("\n- CPU");
                    equipo.tipoE = tipo;
                    break;
                case 2:
                    printf("\n- Monitor");
                    equipo.tipoE = tipo;
                    break;
                case 3:
                    printf("\n- Impresora");
                    equipo.tipoE = tipo;
                    break;
                case 4:
                    printf("\n- Escaner");
                    equipo.tipoE = tipo;
                    break;
                default:
                    printf("\nError. No existe el tipo de equipo seleccionado");
                    break;
            }
            printf("\nMarca del equipo: ");
            leerCad(equipo.marca, 20);
            printf("\nModelo: ");
            leerCad(equipo.modelo, 20);

            if (insertarEquipo(equipo)) {
                printf("\nEl equipo se insertó correctamente");
            } else {
                printf("\nError. No se pudo insertar el equipo");
            }
        } else {
            printf("\nEl equipo con Nº de serie %d ya existe", nSerie);
            printf("\nNo se puede ingresar dos equipos con el mismo ID");
        }
        printf("\n¿Desea seguir ingresando equipos? [S/N]: ");
        leerCad(respuesta, Max);
        if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
            repetir = 0;
        }
    } while (repetir);
}

void menuMostrar() {
    Equipo *equipos;
    int numeroEquipos;
    equipos = obtenerEquipos(&numeroEquipos);
    if (numeroEquipos == 0) {
        printf("\nEl archivo está vacío");
    } else {
        printf("\n\t.:LISTA DE EQUIPOS REGISTRADOS:.");
        printf("\n%10s %15s %10s %10s", "Nº de serie |", "Marca |", "Tipo |", "Modelo");
        printf("\n---------------------------------------------------------------------");
        for (int i = 0; i < numeroEquipos; ++i) {
            if (equipos[i].nSerie != valor) {
                printf("\n%7d \t%12s \t%7d \t%10s", equipos[i].nSerie, equipos[i].marca, equipos[i].tipoE, equipos[i].modelo);
            }
        }
        printf("\n---------------------------------------------------------------------\n");
    }
}

void menuModificar() {
    Equipo equipo;
    int nSerie;
    char repetir = 1;
    int tipoT = 0;
    int opc = 0;
    char respuesta[Max];

    do {
        printf("\n\t.:MODIFICAR EQUIPO:.");
        printf("\nDigite el número de serie: ");
        leerCad(linea, Max);
        sscanf(linea, "%d", &nSerie);
        if (existeEquipo(nSerie, &equipo)) {
            printf("\n\t-- Equipo encontrado --");
            printf("\nTipo: %d", equipo.tipoE);
            printf("\nMarca: %s", equipo.marca);
            printf("\nModelo: %s", equipo.modelo);
            do {
                printf("\n\n\tElija la opción a modificar: ");
                printf("\n1. Tipo | 2. Marca | 3. Modelo | 4. Guardar | 5. Cancelar/Salir");
                printf("\nOpción: ");
                scanf("%d", &opc);

                switch (opc) {
                    case 1:
                        printf("\nDigite el nuevo tipo: ");
                        leerCad(linea, Max);
                        tipoT = equipo.tipoE;
                        break;
                    case 2:
                        printf("\nIngrese la nueva marca: ");
                        leerCad(equipo.marca, Max);
                        break;
                    case 3:
                        printf("\nDigite el nuevo modelo: ");
                        leerCad(linea, Max);
                        sscanf(linea, "s", &equipo.modelo);
                        break;
                    case 4:
                        printf("\n¿Está seguro de modificar los datos del equipo? [S/N]: ");
                        leerCad(respuesta, Max);
                        if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
                            if (modificarEquipo(equipo)) {
                                printf("\nEl equipo fue modificado correctamente");
                            } else {
                                printf("Error. No se pudieron guardar los cambios");
                            }
                        }
                        break;
                    case 5:
                        break;
                    default:
                        printf("\nError. Digite una opción válida");
                        break;
                }
            } while (opc != 5);
        } else {
            printf("\nEl equipo con Nº de serie %d no existe", nSerie);
        }
        printf("\n¿Desea modificar otro equipo? [S/N]: ");
        leerCad(respuesta, Max);
        if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
            repetir = 0;
        }
    } while (repetir);
}

void menuEliminar() {
    Equipo equipo;
    int nSerie;
    char repetir = 1;
    char respuesta[Max];

    do {
        printf("\n\t.:ELIMINAR EQUIPO:.");
        printf("\nDigite el número de serie: ");
        leerCad(linea, Max);
        sscanf(linea, "%d", &nSerie);
        if (existeEquipo(nSerie, &equipo)) {
            printf("\n\t-- Detalles del equipo a eliminar");
            printf("\nNumero de serie: %d", equipo.nSerie);
            printf("\nTipo: %d", equipo.tipoE);
            printf("\nMarca: %s", equipo.marca);
            printf("\nModelo: %s", equipo.modelo);
            printf("\n\n¿Seguro que desea eliminar el equipo? [S/N]: ");
            leerCad(respuesta, Max);
            if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
                if (eliminar(nSerie)) {
                    printf("\nEquipo eliminado correctamente");
                } else {
                    printf("\nError. El equipo no pudo ser eliminado");
                }
            }
        } else  {
            printf("\nEl equipo con Nº de serie %d no existe", nSerie);
        }
        printf("\n¿Desea eliminar otro equipo? [S/n]: ");
        leerCad(respuesta, Max);
        if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
            repetir = 0;
        }
    } while (repetir);
}

void menuBuscar() {
    Equipo equipo;
    int nSerie;
    int tipo;
    int opc = 0;
    char repetir = 1;
    char respuesta[Max];
    char lineaM;

    do {
        printf("\n\t.:BUSCAR EQUIPO:.");
        printf("\n1. Buscar por Nª de serie");
        printf("\n2. Buscar por tipo");
        printf("\n3. Buscar por marca");
        printf("\nOpción: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                printf("\n\t--Buscar por Nº de serie");
                printf("\nDigite el número de serie: ");
                leerCad(linea, Max);
                sscanf(linea, "%d", &nSerie);
                if (existeEquipo(nSerie, &equipo)) {
                    printf("\nNumero de serie: %d", equipo.nSerie);
                    printf("\nTipo: %d", equipo.tipoE);
                    printf("\nMarca: %s", equipo.marca);
                    printf("\nModelo: %s", equipo.modelo);
                } else {
                    printf("\nEl equipo con Nº de serie %d no existe", nSerie);
                }
                break;
            case 2:
                printf("\n\t-- Buscar por tipo");
                printf("\nDigite el tipo: ");
                leerCad(linea, Max);
                sscanf(linea, "%d", &tipo);
                if (existeEquipoT(tipo, &equipo)) {
                    printf("\nNumero de serie: %d", equipo.nSerie);
                    printf("\nTipo: %d", equipo.tipoE);
                    printf("\nMarca: %s", equipo.marca);
                    printf("\nModelo: %s", equipo.modelo);
                } else {
                    printf("\nEl equipo de tipo %d no existe", tipo);
                }
                break;
            case 3:
                printf("\n\t-- Buscar por marca");
                printf("\nIngrese la marca: ");
                leerCad(linea, Max);
                sscanf(linea, "%s", &lineaM);
                if (existeEquipoM(lineaM, &equipo)) {
                    printf("\nNumero de serie: %d", equipo.nSerie);
                    printf("\nTipo: %d", equipo.tipoE);
                    printf("\nMarca: %s", equipo.marca);
                    printf("\nModelo: %s", equipo.modelo);
                } else {
                    printf("\nEl equipo con la marca %s no existe", linea);
                }
                break;
            default:
                printf("\nError. Digite una opción válida");
                break;
        }
        printf("\n¿Desea seguir buscando equipos? [S/N]: ");
        leerCad(respuesta, Max);
        if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
            repetir = 0;
        }
    } while (repetir);
}

// Funciones del historico
void menuInsertarH() {
    Historico historico;
    Equipo equipo;
    int nSerie = 0;
    char repetir = 1;
    char respuesta[Max];

    do {
        printf("\n\t.:INSERTAR HISTORIAL:.");
        printf("\nDigite el Nª de serie del equipo: ");
        leerCad(linea, Max);
        sscanf(linea, "%d", &nSerie);
        if (existeEquipo(nSerie, &equipo)) {
            historico.id = nSerie;
            printf("\nPersona que atendió: ");
            leerCad(historico.personaAt, 80);
            printf("\nMotivo: ");
            leerCad(historico.motivo, 80);
            printf("\nFecha de servicio: ");
            leerCad(historico.fecha, Max);
            if (insertarHistorial(historico)) {
                printf("\nEl historico se insertó correctamente");
            } else {
                printf("\nError. No se pudo insertar el historico");
            }
        } else {
            printf("\nEl historico asociado al equipo con Nª de serie %d ya existe", nSerie);
        }
        printf("\n¿Desea seguir realizando históricos? [S/N]: ");
        leerCad(respuesta, Max);
        if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
            repetir = 0;
        }
    } while (repetir);
}

void menuMostrarH() {
    Historico *historicos;
    int numeroEquipos;
    historicos = obtenerEquiposH(&numeroEquipos);
    if (numeroEquipos == 0) {
        printf("\nEl archivo está vacío");
    } else {
        printf("\n\t.:HISTORIAL:.");
        printf("\n%10s %20s %20s %10s", "Nº de serie |", "P. Atendió |", "Motivo |", "Fecha");
        printf("\n---------------------------------------------------------------------");
        for (int i = 0; i < numeroEquipos; ++i) {
            printf("\n%7d \t%20s \t%17s \t%10s", historicos[i].id, historicos[i].personaAt, historicos[i].motivo, historicos[i].fecha);
        }
    }
    printf("\n---------------------------------------------------------------------\n");
}

void menuModificarH() {
    Historico historico;
    int id;
    int opc = 0;
    char repetir = 1;
    char respuesta[Max];

    do {
        printf("\n\t.:MODIFICAR HISTÓRICO:.");
        printf("\nDigite el ID del historial: ");
        leerCad(linea, Max);
        sscanf(linea, "%d", &id);
        if (existeHistorial(id, &historico)) {
            printf("\nMotivo: %s", historico.motivo);
            printf("\nPersona que atendió: %s", historico.personaAt);
            printf("\nFecha: %s", historico.fecha);
            do {
                printf("\n\n\tElija la opción a modificar: ");
                printf("\n1. Motivo | 2. Persona que atendió  | 3. Fecha | 4. Guardar | 5. Cancelar/Salir");
                printf("\nOpción: ");
                scanf("%d", &opc);

                switch (opc) {
                    case 1:
                        printf("\nNuevo motivo: ");
                        leerCad(historico.motivo, 80);
                        break;
                    case 2:
                        printf("\nNueva persona que atendió: ");
                        leerCad(historico.personaAt, 80);
                        break;
                    case 3:
                        printf("\nDigite la nueva fecha: ");
                        leerCad(historico.fecha, 15);
                        break;
                    case 4:
                        printf("\n¿Está seguro de modificar los datos del histórico? [S/N]: ");
                        leerCad(respuesta, Max);
                        if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
                            if (modificarHistorial(historico)) {
                                printf("\nEl historial fue modificado correctamente");
                            } else {
                                printf("Error. No se pudieron guardar los cambios");
                            }
                        }
                        break;
                    case 5:
                        break;
                    default:
                        printf("\nError. Digite una opción válida");
                        break;
                }
            } while (opc != 5);
        } else {
            printf("\nEl el historial con %d no existe", id);
        }
        printf("\n¿Desea modificar otro historial? [S/N]: ");
        leerCad(respuesta, Max);
        if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
            repetir = 0;
        }
    } while (repetir);
}

void menuBuscarH() {
    Historico historico;
    int id;
    char repetir = 1;
    char respuesta[Max];

    do {
        printf("\n\t.:BUSCAR HISTORIAL:.");
        printf("\nDigite el ID del histórico: ");
        leerCad(linea, Max);
        sscanf(linea, "%d", &id);
        if (existeHistorial(id, &historico)) {
            printf("\nID: %d", historico.id);
            printf("\nMotivo: %s", historico.motivo);
            printf("\nPersona que atendió: %s", historico.personaAt);
            printf("\nFecha: %s", historico.fecha);
        } else {
            printf("\nEl historial con el ID %d no existe", id);
        }
        printf("\n¿Desea seguir buscando otro historial? [S/N]: ");
        leerCad(respuesta, Max);
        if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
            repetir = 0;
        }
    } while (repetir);
}

// Funciones de operaciones base - Verificación de que existen equipos e historial
char existeEquipo(int nSerie, Equipo * equipo) {
    FILE *archivo;
    char existe;
    archivo = fopen("equipos.dat", "rb");
    if (archivo == NULL) {
        existe = 0;
    } else {
        existe = 0;
        fread(&(*equipo), sizeof(*equipo), 1, archivo);
        while (!feof(archivo)) {
            if ((*equipo).nSerie == nSerie) {
                existe = 1;
                break;
            }
            fread(&(*equipo), sizeof(*equipo), 1, archivo);
        }
        fclose(archivo);
    }
    return existe;
}

char existeEquipoT(int tipo, Equipo *equipo) {
    FILE *archivo;
    char existeT;
    archivo = fopen("equipos.dat", "rb");

    if (archivo == NULL) {
        existeT = 0;
    } else {
        existeT = 0;
        fread(&(*equipo), sizeof(*equipo), 1, archivo);
        while (!feof(archivo)) {
            if ((*equipo).tipoE == tipo) {
                existeT = 1;
                break;
            }
            fread(&(*equipo), sizeof(*equipo), 1, archivo);
        }
        fclose(archivo);
    }
    return existeT;
}

char existeEquipoM(char lineaM, Equipo *equipo) {
    FILE *archivo;
    char existeM;
    archivo = fopen("equipos.dat", "rb");

    if (archivo == NULL) {
        existeM = 0;
    } else {
        existeM = 0;
        fread(&(*equipo), sizeof(*equipo), 1, archivo);
        while (!feof(archivo)) {
            if ((*equipo).marca[20] == lineaM) {
                existeM = 1;
                break;
            }
            fread(&(*equipo), sizeof(*equipo), 1, archivo);
        }
        fclose(archivo);
    }
    return existeM;
}

char existeHistorial(int id, Historico *historico) {
    FILE *archivo;
    char existe;
    archivo = fopen("historico.dat", "rb");
    if (archivo == NULL) {
        existe = 0;
    } else {
        existe = 0;
        fread(&(*historico), sizeof(*historico), 1, archivo);
        while (!feof(archivo)) {
            if ((*historico).id == id) {
                existe = 1;
                break;
            }
            fread(&(*historico), sizeof(*historico), 1, archivo);
        }
        fclose(archivo);
    }
    return existe;
}

// Inserciones de equipos e historial
char insertarEquipo(Equipo equipo) {
    FILE *archivo;
    char insercion;
    archivo = fopen("equipos.dat", "ab");

    if (archivo == NULL) {
        insercion = 0;
    } else {
        fwrite(&equipo, sizeof(equipo), 1, archivo);
        insercion = 1;
        fclose(archivo);
    }
    return insercion;
}

char insertarHistorial(Historico historico) {
    FILE *archivo;
    char insercion;
    archivo = fopen("historico.dat", "ab");
    if (archivo == NULL) {
        insercion = 0;
    } else {
        fwrite(&historico, sizeof(historico), 1, archivo);
        insercion = 1;
        fclose(archivo);
    }
    return insercion;
}

// Archivos
Equipo *obtenerEquipos(int *n) {
    FILE * archivo;
    Equipo equipo;
    Equipo *equipos;
    int i;
    archivo = fopen("equipos.dat", "rb"); // Lectura de datos

    if (archivo == NULL) {
        *n = 0;
        equipos = NULL;
    } else {
        fseek(archivo, 0, SEEK_END); // Posición respecto al final del archivo
        *n = ftell(archivo) / sizeof(Equipo);
        equipos = (Equipo *)malloc((*n) * sizeof(Equipo)); // Reservar memoria para los registros
        fseek(archivo, 0, SEEK_SET); // Posicionar el cursor al inicio del archivo
        fread(&equipo, sizeof(equipo), 1, archivo);
        i = 0;
        while (!feof(archivo)) { // No sobrepasar el final del archivo
            equipos[i++] = equipo;
            fread(&equipo, sizeof(equipo), 1, archivo);
        }
        fclose(archivo); // Siempre cerrar el archivo
    }
    return equipos;
}

Historico *obtenerEquiposH(int *n) {
    FILE *archivo;
    Historico historico;
    Historico *equipos;
    int i;
    archivo = fopen("historico.dat", "rb");

    if (archivo == NULL) {
        *n = 0;
        equipos = NULL;
    } else {
        fseek(archivo, 0, SEEK_END);
        *n = ftell(archivo) / sizeof(Historico);
        equipos = (Historico *)malloc((*n) * sizeof(Historico));
        fseek(archivo, 0, SEEK_SET); // pocicionarse al inicio
        fread(&historico, sizeof(historico), 1, archivo);
        i = 0;
        while (!feof(archivo)) {
            equipos[i++] = historico;
            fread(&historico, sizeof(historico), 1, archivo);
        }
        fclose(archivo);
    }
    return equipos;
}

// Eliminación
char eliminar(int nSerie) {
    FILE *archivo;
    FILE *aux;
    Equipo equipo;
    char eliminar;
    archivo = fopen("equipos.dat", "r+b");

    if (archivo == NULL) {
        eliminar = 0;
    } else {
        eliminar = 0;
        fread(&equipo, sizeof(equipo), 1, archivo);
        while (!feof(archivo)) {
            if (equipo.nSerie == nSerie) {
                fseek(archivo, ftell(archivo) - sizeof(equipo), SEEK_SET);
                equipo.nSerie = valor;
                fwrite(&equipo, sizeof(equipo), 1, archivo);
                eliminar = 1;
                break;;
            }
            fread(&equipo, sizeof(equipo), 1, archivo);
        }
        fclose(archivo);
    }
    return eliminar;
}

// Modificación
char modificarEquipo(Equipo equipo) {
    FILE *archivo;
    char modificar;
    Equipo equipo2;
    archivo = fopen("equipos.dat", "rb+");

    if (archivo == NULL) {
        modificar = 0;
    } else {
        modificar = 0;
        fread(&equipo2, sizeof(equipo2), 1, archivo);
        while (!feof(archivo)) {
            if (equipo2.nSerie == equipo.nSerie) {
                fseek(archivo, ftell(archivo) - sizeof(equipo), SEEK_SET);
                fwrite(&equipo, sizeof(equipo), 1, archivo);
                modificar = 1;
                break;
            }
            fread(&equipo2, sizeof(equipo2), 1, archivo);
        }
        fclose(archivo);
    }
    return modificar;
}

char modificarHistorial(Historico historico) {
    FILE *archivo;
    char modificar;
    Historico historico2;
    archivo = fopen("historico.dat", "rb+");

    if (archivo == NULL) {
        modificar = 0;
    } else {
        modificar = 0;
        fread(&historico2, sizeof(historico2), 1, archivo);
        while (!feof(archivo)) {
            if (historico2.id == historico.id) {
                fseek(archivo, ftell(archivo) - sizeof(historico), SEEK_SET);
                fwrite(&historico, sizeof(historico), 1, archivo);
                modificar = 1;
                break;
            }
            fread(&historico2, sizeof(historico2), 1, archivo);
        }
        fclose(archivo);
    }
    return modificar;
}

int leerCad(char *cad, int n) {
    int i, c;
    c = getchar();
    if (c == EOF) {
        cad[0] = '\0';
        return 0;
    }
    if (c == '\n') {
        i = 0;
    } else {
        cad[0] = c;
        i = 1;
    }
    for (; i < n - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        cad[i] = c;
    }
    cad[i] = '\0'; // Verificando si el buffer está limpio
    if (c != '\n' && c != EOF) {
        while ((c = getchar()) != '\n' && c != EOF);
    }
    return -1;
}