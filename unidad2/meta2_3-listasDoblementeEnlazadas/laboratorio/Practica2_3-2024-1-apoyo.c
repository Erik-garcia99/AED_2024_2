#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Alumno
typedef struct Alumno {
    char nombre[50];
    float promedio;
    struct Alumno *siguiente_nombre;
    struct Alumno *anterior_nombre;
    struct Alumno *siguiente_promedio;
    struct Alumno *anterior_promedio;
} Alumno;

// Definición de la estructura ListaDoblementeEnlazada
typedef struct ListaDoblementeEnlazada {
    Alumno *inicio_nombre;
    Alumno *inicio_promedio;
} ListaDoblementeEnlazada;

// Función para crear un nuevo alumno
Alumno *crear_alumno(char nombre[], float promedio) {
    Alumno *nuevo_alumno = (Alumno *)malloc(sizeof(Alumno));
    if (nuevo_alumno != NULL) {
        strcpy(nuevo_alumno->nombre, nombre);
        nuevo_alumno->promedio = promedio;
        nuevo_alumno->siguiente_nombre = NULL;
        nuevo_alumno->anterior_nombre = NULL;
        nuevo_alumno->siguiente_promedio = NULL;
        nuevo_alumno->anterior_promedio = NULL;
    }
    return nuevo_alumno;
}

// Función para insertar un nuevo alumno en la lista
void insertar_alumno(ListaDoblementeEnlazada *lista, char nombre[], float promedio) {
    Alumno *nuevo_alumno = crear_alumno(nombre, promedio);
    if (nuevo_alumno == NULL) {
        printf("Error: No se pudo crear el nuevo alumno.\n");
        return;
    }

    // Insertar en la lista ordenada por nombre
    if (lista->inicio_nombre == NULL) {
        lista->inicio_nombre = nuevo_alumno;
    } else {
        Alumno *actual = lista->inicio_nombre;
        while (actual->siguiente_nombre != NULL && strcmp(actual->nombre, nombre) < 0) {
            actual = actual->siguiente_nombre;
        }
        if (strcmp(actual->nombre, nombre) < 0) {
            nuevo_alumno->anterior_nombre = actual;
            nuevo_alumno->siguiente_nombre = actual->siguiente_nombre;
            if (actual->siguiente_nombre != NULL) {
                actual->siguiente_nombre->anterior_nombre = nuevo_alumno;
            }
            actual->siguiente_nombre = nuevo_alumno;
        } else {
            nuevo_alumno->siguiente_nombre = actual;
            nuevo_alumno->anterior_nombre = actual->anterior_nombre;
            if (actual->anterior_nombre != NULL) {
                actual->anterior_nombre->siguiente_nombre = nuevo_alumno;
            } else {
                lista->inicio_nombre = nuevo_alumno;
            }
            actual->anterior_nombre = nuevo_alumno;
        }
    }

    // Insertar en la lista ordenada por promedio
    if (lista->inicio_promedio == NULL || lista->inicio_promedio->promedio <= promedio) {
    nuevo_alumno->siguiente_promedio = lista->inicio_promedio;
    if (lista->inicio_promedio != NULL) {
        lista->inicio_promedio->anterior_promedio = nuevo_alumno;
    }
    lista->inicio_promedio = nuevo_alumno;
    } else {
    Alumno *actual = lista->inicio_promedio;
    while (actual->siguiente_promedio != NULL && actual->siguiente_promedio->promedio > promedio) {
        actual = actual->siguiente_promedio;
    }
    nuevo_alumno->anterior_promedio = actual;
    nuevo_alumno->siguiente_promedio = actual->siguiente_promedio;
    if (actual->siguiente_promedio != NULL) {
        actual->siguiente_promedio->anterior_promedio = nuevo_alumno;
    }
    actual->siguiente_promedio = nuevo_alumno;
}

}

// Función para eliminar un alumno de la lista
void eliminar_alumno(ListaDoblementeEnlazada *lista, char nombre[]) {
    Alumno *alumno = lista->inicio_nombre;
    while (alumno != NULL && strcmp(alumno->nombre, nombre) != 0) {
        alumno = alumno->siguiente_nombre;
    }
    if (alumno == NULL) {
        printf("El alumno no se encuentra en la lista.\n");
        return;
    }

    // Eliminar de la lista ordenada por nombre
    if (alumno->anterior_nombre != NULL) {
        alumno->anterior_nombre->siguiente_nombre = alumno->siguiente_nombre;
    } else {
        lista->inicio_nombre = alumno->siguiente_nombre;
    }
    if (alumno->siguiente_nombre != NULL) {
        alumno->siguiente_nombre->anterior_nombre = alumno->anterior_nombre;
    }

    // Eliminar de la lista ordenada por promedio
    if (alumno->anterior_promedio != NULL) {
        alumno->anterior_promedio->siguiente_promedio = alumno->siguiente_promedio;
    } else {
        lista->inicio_promedio = alumno->siguiente_promedio;
    }
    if (alumno->siguiente_promedio != NULL) {
        alumno->siguiente_promedio->anterior_promedio = alumno->anterior_promedio;
    }

    free(alumno);
}

// Función para modificar el promedio de un alumno
void modificar_promedio(ListaDoblementeEnlazada *lista, char nombre[], float nuevo_promedio) {
    Alumno *alumno = lista->inicio_nombre;
    while (alumno != NULL && strcmp(alumno->nombre, nombre) != 0) {
        alumno = alumno->siguiente_nombre;
    }
    if (alumno == NULL) {
        printf("El alumno no se encuentra en la lista.\n");
        return;
    }
    alumno->promedio = nuevo_promedio;
}

// Función para mostrar la lista de alumnos ordenada por nombre
void mostrar_orden_nombre(ListaDoblementeEnlazada lista) {
    Alumno *actual = lista.inicio_nombre;
    while (actual != NULL) {
        printf("%s, %.2f\n", actual->nombre, actual->promedio);
        actual = actual->siguiente_nombre;
    }
}

// Función para mostrar la lista de alumnos ordenada por promedio
void mostrar_orden_promedio(ListaDoblementeEnlazada lista) {
    Alumno *actual = lista.inicio_promedio;
    while (actual != NULL) {
        printf("%s, %.2f\n", actual->nombre, actual->promedio);
        actual = actual->siguiente_promedio;
    }
}

// Función para buscar un alumno por nombre
Alumno *buscar_alumno_por_nombre(ListaDoblementeEnlazada lista, char nombre[]) {
    Alumno *actual = lista.inicio_nombre;
    while (actual != NULL && strcmp(actual->nombre, nombre) != 0) {
        actual = actual->siguiente_nombre;
    }
    return actual;
}

int main() {
    ListaDoblementeEnlazada lista_alumnos = {NULL, NULL};
    int opcion;
    char nombre[50];
    float promedio, nuevo_promedio;
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insertar alumno\n");
        printf("2. Eliminar alumno\n");
        printf("3. Modificar promedio\n");
        printf("4. Mostrar ordenados alfabeticamente\n");
        printf("5. Mostrar ordenados por promedio\n");
        printf("6. Salir\n");
        
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                printf("Ingrese el nombre del alumno: ");
                scanf("%s", nombre);
                printf("Ingrese el promedio del alumno: ");
                scanf("%f", &promedio);
                insertar_alumno(&lista_alumnos, nombre, promedio);
                printf("Alumno insertado correctamente.\n");
                break;
            case 2:
                printf("Ingrese el nombre del alumno que desea eliminar: ");
                scanf("%s", nombre);
                eliminar_alumno(&lista_alumnos, nombre);
                printf("Alumno eliminado correctamente.\n");
                break;
            case 3:
                printf("Ingrese el nombre del alumno que desea modificar: ");
                scanf("%s", nombre);
                printf("Ingrese el nuevo promedio del alumno: ");
                scanf("%f", &nuevo_promedio);
                modificar_promedio(&lista_alumnos, nombre, nuevo_promedio);
                printf("Promedio modificado correctamente.\n");
                break;
            case 4:
                printf("\n--- Lista de alumnos ordenados alfabeticamente ---\n");
                mostrar_orden_nombre(lista_alumnos);
                break;
            case 5:
                printf("\n--- Lista de alumnos ordenados por promedio ---\n");
                mostrar_orden_promedio(lista_alumnos);
                break;
            case 6:
                printf("¡Hasta luego!\n");
                exit(0);
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }
    }

    return 0;
}
