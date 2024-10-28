#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Curso {
    string codigoCurso;
    string nombreCurso;
    int creditos;
};

// Vectores de cursos por semestre
vector<Curso> primerCiclo = {
    {"001", "DESARROLLO HUMANO Y PROFESIONAL", 4},
    {"002", "METODOLOGÍA DE LA INVESTIGACIÓN", 5},
    {"003", "CONTABILIDAD I", 5},
    {"004", "INTRODUCCIÓN A LOS SISTEMAS DE CÓMPUTO", 5},
    {"005", "LÓGICA DE SISTEMAS", 5}
};

// (Se omiten los otros ciclos para abreviar)

// Vectores de cursos asignados
vector<Curso> cursosAsignados;

// Función para guardar los cursos asignados en un fichero
void guardarCursosAsignados() {
    ofstream archivo("cursos_asignados.txt");
    if (archivo.is_open()) {
        for (const auto& curso : cursosAsignados) {
            archivo << curso.codigoCurso << "," << curso.nombreCurso << "," << curso.creditos << '\n';
        }
        archivo.close();
        cout << "Cursos asignados guardados en 'cursos_asignados.txt'.\n";
    } else {
        cout << "No se pudo abrir el archivo para guardar.\n";
    }
}

// Función para cargar los cursos asignados desde un fichero
void cargarCursosAsignados() {
    ifstream archivo("cursos_asignados.txt");
    if (archivo.is_open()) {
        string codigo, nombre;
        int creditos;
        char delimitador;

        cursosAsignados.clear();
        while (archivo >> codigo >> delimitador) {
            getline(archivo, nombre, ',');
            archivo >> creditos;
            archivo.ignore();

            cursosAsignados.push_back({codigo, nombre, creditos});
        }
        archivo.close();
        cout << "Cursos asignados cargados desde 'cursos_asignados.txt'.\n";
    } else {
        cout << "No se encontró un archivo previo de cursos asignados.\n";
    }
}

// Función para mostrar cursos del semestre
void mostrarCursosDelSemestre(int semestre) {
    vector<Curso> cursos;

    switch (semestre) {
        case 1: cursos = primerCiclo; break;
        // (Se omiten los otros casos para abreviar)
        default:
            cout << "Semestre no válido.\n";
            return;
    }

    cout << "\nCursos disponibles en el semestre " << semestre << ":\n";
    for (const auto& curso : cursos) {
        cout << "Código: " << curso.codigoCurso << ", Nombre: " << curso.nombreCurso << ", Créditos: " << curso.creditos << '\n';
    }
}

// Función para asignar un curso
void asignarCurso(int semestre) {
    mostrarCursosDelSemestre(semestre);

    int opcion;
    do {
        cout << "\n1. Asignar un curso\n2. Regresar al menú principal\nOpción: ";
        cin >> opcion;

        if (opcion == 1) {
            string codigoCurso;
            cout << "Ingrese el código del curso que desea asignar: ";
            cin >> codigoCurso;

            vector<Curso> cursos;

            switch (semestre) {
                case 1: cursos = primerCiclo; break;
                // (Se omiten los otros casos para abreviar)
                default:
                    cout << "Semestre no válido.\n";
                    return;
            }

            bool encontrado = false;
            for (const auto& curso : cursos) {
                if (curso.codigoCurso == codigoCurso) {
                    cursosAsignados.push_back(curso);
                    cout << "Curso asignado con éxito: " << curso.nombreCurso << " con " << curso.creditos << " créditos.\n";
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado) {
                cout << "El código ingresado no corresponde a ningún curso del semestre.\n";
            }

            guardarCursosAsignados(); // Guardar después de asignar un curso

        } else if (opcion == 2) {
            cout << "Regresando al menú principal...\n";
        } else {
            cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (opcion != 2);
}

// Función para mostrar cursos asignados
void mostrarCursosAsignados() {
    if (cursosAsignados.empty()) {
        cout << "No hay cursos asignados.\n";
    } else {
        cout << "\nCursos asignados:\n";
        for (const auto& curso : cursosAsignados) {
            cout << "Código: " << curso.codigoCurso << ", Nombre: " << curso.nombreCurso << ", Créditos: " << curso.creditos << '\n';
        }
    }
}

int main() {
    cargarCursosAsignados(); // Cargar cursos asignados al iniciar

    int opcion;
    int semestre;

    do {
        cout << "\n1. Asignar cursos\n2. Cursos asignados\n3. Salir\nOpción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el semestre para asignar los cursos (1 a 10): ";
                cin >> semestre;
                asignarCurso(semestre);
                break;
            case 2:
                mostrarCursosAsignados();
                break;
            case 3:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no válida.\n";
        }
    } while (opcion != 3);

    return 0;
}
