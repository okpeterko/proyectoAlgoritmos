#include <iostream>
#include <vector>
#include <string>

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

vector<Curso> segundoCiclo = {
    {"006", "PRECÁLCULO", 5},
    {"007", "ÁLGEBRA LINEAL", 5},
    {"008", "ALGORITMOS", 5},
    {"009", "CONTABILIDAD II", 5},
    {"010", "MATEMÁTICA DISCRETA", 5}
};

vector<Curso> tercerCiclo = {
    {"011", "FÍSICA I", 5},
    {"012", "PROGRAMACIÓN I", 5},
    {"013", "CÁLCULO I", 5},
    {"014", "PROCESO ADMINISTRATIVO", 4},
    {"015", "DERECHO INFORMÁTICO", 5}
};

vector<Curso> cuartoCiclo = {
    {"016", "MICROECONOMÍA", 5},
    {"017", "PROGRAMACIÓN II", 5},
    {"018", "CÁLCULO II", 5},
    {"019", "ESTADÍSTICA I", 5},
    {"020", "FÍSICA II", 5}
};

vector<Curso> quintoCiclo = {
    {"021", "MÉTODOS NUMÉRICOS", 5},
    {"022", "PROGRAMACIÓN III", 5},
    {"023", "EMPRENDEDORES DE NEGOCIOS", 5},
    {"024", "ELECTRÓNICA ANALÓGICA", 5},
    {"025", "ESTADÍSTICA II", 5}
};

vector<Curso> sextoCiclo = {
    {"026", "INVESTIGACIÓN DE OPERACIONES", 5},
    {"027", "BASES DE DATOS I", 5},
    {"028", "AUTÓMATAS Y LENGUAJES FORMALES", 5},
    {"029", "SISTEMAS OPERATIVOS I", 5},
    {"030", "ELECTRÓNICA DIGITAL", 5}
};

vector<Curso> septimoCiclo = {
    {"031", "BASES DE DATOS II", 5},
    {"032", "ANÁLISIS DE SISTEMAS I", 5},
    {"033", "SISTEMAS OPERATIVOS II", 5},
    {"034", "ARQUITECTURA DE COMPUTADORAS I", 5},
    {"035", "COMPILADORES", 5}
};

vector<Curso> octavoCiclo = {
    {"036", "DESARROLLO WEB", 5},
    {"037", "ANÁLISIS DE SISTEMAS II", 5},
    {"038", "REDES DE COMPUTADORAS I", 5},
    {"039", "ÉTICA PROFESIONAL", 4},
    {"040", "ARQUITECTURA DE COMPUTADORAS II", 5}
};

vector<Curso> novenoCiclo = {
    {"041", "ADMINISTRACIÓN DE TECNOLOGÍAS DE INFORMACIÓN", 5},
    {"042", "INGENIERÍA DE SOFTWARE", 5},
    {"043", "PROYECTO DE GRADUACIÓN I", 6},
    {"044", "REDES DE COMPUTADORAS II", 5},
    {"045", "INTELIGENCIA ARTIFICIAL", 5}
};

vector<Curso> decimoCiclo = {
    {"046", "TELECOMUNICACIONES", 5},
    {"047", "SEMINARIO DE TECNOLOGÍAS DE INFORMACIÓN", 6},
    {"048", "ASEGURAMIENTO DE LA CALIDAD DE SOFTWARE", 5},
    {"049", "PROYECTO DE GRADUACIÓN II", 6},
    {"050", "SEGURIDAD Y AUDITORÍA DE SISTEMAS", 5}
};

vector<Curso> cursosAsignados;

void mostrarCursosDelSemestre(int semestre) {
    vector<Curso> cursos;

    switch (semestre) {
        case 1: cursos = primerCiclo; break;
        case 2: cursos = segundoCiclo; break;
        case 3: cursos = tercerCiclo; break;
        case 4: cursos = cuartoCiclo; break;
        case 5: cursos = quintoCiclo; break;
        case 6: cursos = sextoCiclo; break;
        case 7: cursos = septimoCiclo; break;
        case 8: cursos = octavoCiclo; break;
        case 9: cursos = novenoCiclo; break;
        case 10: cursos = decimoCiclo; break;
        default:
            cout << "Semestre no válido.\n";
            return;
    }

    cout << "\nCursos disponibles en el semestre " << semestre << ":\n";
    for (const auto& curso : cursos) {
        cout << "Código: " << curso.codigoCurso << ", Nombre: " << curso.nombreCurso << ", Créditos: " << curso.creditos << '\n';
    }
}

void asignarCurso(int semestre) {
    mostrarCursosDelSemestre(semestre);

    string codigoCurso;
    cout << "Ingrese el código del curso que desea asignar: ";
    cin >> codigoCurso;

    vector<Curso> cursos;

    switch (semestre) {
        case 1: cursos = primerCiclo; break;
        case 2: cursos = segundoCiclo; break;
        case 3: cursos = tercerCiclo; break;
        case 4: cursos = cuartoCiclo; break;
        case 5: cursos = quintoCiclo; break;
        case 6: cursos = sextoCiclo; break;
        case 7: cursos = septimoCiclo; break;
        case 8: cursos = octavoCiclo; break;
        case 9: cursos = novenoCiclo; break;
        case 10: cursos = decimoCiclo; break;
        default:
            cout << "Semestre no válido.\n";
            return;
    }

    for (const auto& curso : cursos) {
        if (curso.codigoCurso == codigoCurso) {
            cursosAsignados.push_back(curso);
            cout << "Curso asignado con éxito: " << curso.nombreCurso << " con " << curso.creditos << " créditos.\n";
            return;
        }
    }

    cout << "El código ingresado no corresponde a ningún curso del semestre.\n";
}

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
