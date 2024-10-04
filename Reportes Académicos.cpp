//este codigo es en base a la asignacion de cursos
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Curso {
    string codigoCurso;
    string nombreCurso;
    int creditos;
    
    Curso() {} 
    Curso(string codigo, string nombre, int cred) {
        codigoCurso = codigo;
        nombreCurso = nombre;
        creditos = cred;
    }
};

struct CursoAsignado {
    Curso curso;
    int semestre;

    CursoAsignado(Curso c, int sem) {
        curso = c;
        semestre = sem;
    }
};

vector<Curso> cursosAsignados;
vector<CursoAsignado> cursosAsignadosConSemestre;

void mostrarReporteAsignacionCursos() {
    if (cursosAsignadosConSemestre.empty()) {
        cout << "No hay cursos asignados.\n";
    } else {
        cout << "\nReporte de Asignacion de Cursos:\n";
        for (int i = 0; i < cursosAsignadosConSemestre.size(); i++) {
            cout << "Semestre: " << cursosAsignadosConSemestre[i].semestre
                 << ", Codigo: " << cursosAsignadosConSemestre[i].curso.codigoCurso
                 << ", Nombre: " << cursosAsignadosConSemestre[i].curso.nombreCurso
                 << ", Creditos: " << cursosAsignadosConSemestre[i].curso.creditos << '\n';
        }
    }
}

void asignarCurso(int semestre, const Curso& curso) {
    cursosAsignados.push_back(curso);
    cursosAsignadosConSemestre.push_back(CursoAsignado(curso, semestre));
}

int main() {
    Curso curso1("001", "DESARROLLO HUMANO Y PROFESIONAL", 4);
    asignarCurso(1, curso1);
    
    Curso curso2("002", "METODOLOGIA DE LA INVESTIGACION", 5);
    asignarCurso(1, curso2);

    mostrarReporteAsignacionCursos();
    return 0;
}

