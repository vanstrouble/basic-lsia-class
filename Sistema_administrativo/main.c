#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void MenuPrincipal ();
void MenuBuscar(struct usuario usuarios[]);

struct fecha_nacimiento{
    int dia;
    int mes;
    int ano;
};
struct usuario{
    int usuarioID;
    char correo[20];
    char nombre[80];
    int telefono[10];
    struct fecha_nacimiento fecha_usuarios;
}usuarios[];


int main() {

    printf("\tSISTEMA ADMINISTRATIVO");

    MenuPrincipal();


    return 0;
}
void MenuPrincipal () {
    int opcion;

    do{
        printf("\nMENÚ PRINCIPAL\n");
        printf("Digite un numero para ingresar a las opciones\n\n");
        printf("1. Buscar cliente\n");
        printf("2. Ingresar un nuevo usuario\n");
        printf("3. Eliminar usuario\n");
        printf("4. Editar usuario\n");
        printf("5. Salir\n\n");
        printf("Opción: ");
        scanf("%i", &opcion);

        switch (opcion){
            case 1: MenuBuscar();
                break;
            case 2: MenuIngresar();
                break;
            case 3: MenuEliminar();
                break;
            case 4: MenuEditar();
                break;
            case 5:
                break;
        }
    }
    while (opcion != 5);
}

void MenuBuscar(struct usuario usuarios[]){
    int usuarioID;
    FILE *fd;
    char direccion[] = "D\\prueba\\usuarios";

    printf("\tBúsqueda de usuarios\n");

    do {
        printf("\tIngrese el usuarioID: ");
        scanf("&i",&usuarioID);

        if ()
    } while();
}

void MenuIngresar(){
    FILE *fd;
    char direccion = "Macintosh HD\\Usuarios\\pedrovazquez\\Escritorio\\Sistema\\Sistema.txt";

    fd = fopen(direccion,"wt");

    if (fd == NULL){
        printf("Error al tratar de crear el archivo");
        return 1;
    }
    printf("\t DATOS DE USUARIO");
    fprintf(fd,"\tDATOS DE USUARIO");

    do{
        printf("\n\nusuarioID: "); gets(usuarios->usuarioID);
        printf("\nNombre: "); gets(usuarios->nombre);
        printf("\nTeléfono: "); gets(usuarios->telefono);
        printf("\nCorreos: "); gets(usuarios->correo);
        printf("\nFecha de nacimiento Día: "); gets(usuarios->fecha_usuarios.dia);
        printf("\nFecha de nacimiento Mes: "); gets(usuarios->fecha_usuarios.mes);
        printf("\nFecha de nacimiento Año: "); gets(usuarios->fecha_usuarios.ano);

        fprintf(fd,"\nusuarioID: ");
        fwrite(usuarios->usuarioID,1,strlen(usuarios->usuarioID));
        fprintf(fd,"\nNombre: ");
        fwrite(usuarios->usuarioID,1,strlen(usuarios->nombre));
        fprintf(fd,"\nTeléfono: ");
        fwrite(usuarios->usuarioID,1,strlen(usuarios->telefono));
        fprintf(fd,"\nCorreo: ");
        fwrite(usuarios->usuarioID,1,strlen(usuarios->correo));
        fprintf(fd,"\nFecha de nacimiento (Día): ");
        fwrite(usuarios->usuarioID,1,strlen(usuarios->fecha_usuarios.dia));
        fprintf(fd,"\nFecha de nacimiento (Mes): ");
        fwrite(usuarios->usuarioID,1,strlen(usuarios->fecha_usuarios.mes));
        fprintf(fd,"\nFecha de nacimiento (Año): ");
        fwrite(usuarios->usuarioID,1,strlen(usuarios->fecha_usuarios.ano));


    } while

}