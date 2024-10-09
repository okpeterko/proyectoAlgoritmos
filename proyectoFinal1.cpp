#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

struct Estudiante {
    int codigo;
    string nombres;
    string apellidos;
    string carrera;
    string departamento;
    string municipio;
    string aldea;
    string telefonoPersonal;
    string telefonoCasa;
    string telefonoEmergencia;
    string fechaNacimiento;
    int edad;
    int anioIngreso;
    string correoElectronico;
};

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

struct Nota {
    Curso curso;
    vector<double> notasParciales;
    double notaFinal;
    string estado;
};

// Listas de Cursos según la carrera
vector<Curso> primerCicloIngenieria = { 
    {"001", "DESARROLLO HUMANO Y PROFESIONAL", 4}, 
    {"002", "METODOLOGÍA DE LA INVESTIGACIÓN", 5}, 
    {"003", "CONTABILIDAD I", 5}, 
    {"004", "INTRODUCCIÓN A LOS SISTEMAS DE CÓMPUTO", 5}, 
    {"005", "LÓGICA DE SISTEMAS", 5} 
};

vector<Curso> segundoCicloIngenieria = { 
    {"006", "PRECÁLCULO", 5}, 
    {"007", "ÁLGEBRA LINEAL", 5}, 
    {"008", "ALGORITMOS", 5}, 
    {"009", "CONTABILIDAD II", 5}, 
    {"010", "MATEMÁTICA DISCRETA", 5} 
};

vector<Curso> primerCicloAdministracion = {
    {"101", "INTRODUCCIÓN A LA ADMINISTRACIÓN", 4}, 
    {"102", "ECONOMÍA I", 5}, 
    {"103", "MATEMÁTICAS FINANCIERAS", 5}, 
    {"104", "CONTABILIDAD GENERAL", 5}, 
    {"105", "MERCADOTECNIA BÁSICA", 5}
};

vector<Curso> segundoCicloAdministracion = { 
    {"106", "GESTIÓN EMPRESARIAL", 5}, 
    {"107", "ECONOMÍA II", 5}, 
    {"108", "FINANZAS CORPORATIVAS", 5}, 
    {"109", "GESTIÓN DE RECURSOS HUMANOS", 5}, 
    {"110", "PLANEACIÓN ESTRATÉGICA", 5} 
};

vector<Curso> primerCicloDerecho = {
    {"201", "INTRODUCCIÓN AL DERECHO", 4}, 
    {"202", "DERECHO CONSTITUCIONAL", 5}, 
    {"203", "TEORÍA DEL ESTADO", 5}, 
    {"204", "HISTORIA DEL DERECHO", 5}, 
    {"205", "CIVIL I", 5}
};

vector<Curso> segundoCicloDerecho = { 
    {"206", "DERECHO PENAL", 5}, 
    {"207", "CIVIL II", 5}, 
    {"208", "DERECHO INTERNACIONAL PÚBLICO", 5}, 
    {"209", "DERECHO MERCANTIL", 5}, 
    {"210", "FUNDAMENTOS DE DERECHO LABORAL", 5} 
};

vector<Estudiante> estudiantes;
vector<CursoAsignado> cursosAsignadosConSemestre;
vector<Nota> controlNotas;

// Función para calcular edad
int calcularEdad(const string& fechaNacimiento) {
    int dia, mes, anio;
    sscanf(fechaNacimiento.c_str(), "%d-%d-%d", &dia, &mes, &anio);

    time_t t = time(0);
    struct tm* ahora = localtime(&t);
    int anioActual = ahora->tm_year + 1900;
    int mesActual = ahora->tm_mon + 1;
    int diaActual = ahora->tm_mday;

    int edad = anioActual - anio;
    if (mesActual < mes || (mesActual == mes && diaActual < dia)) {
        edad--;
    }

    return edad;
}

// Registro de Estudiantes
void registrarEstudiantes() {
    int numeroEstudiantes;
    cout << "Ingrese el numero de estudiantes a registrar: ";
    cin >> numeroEstudiantes;
    cin.ignore();

    for (int i = 0; i < numeroEstudiantes; i++) {
        Estudiante estudiante;
        estudiante.codigo = estudiantes.size() + 1;

        cout << "Registro de Estudiante #" << estudiante.codigo << endl;
        cout << "Nombres: "; getline(cin, estudiante.nombres);
        cout << "Apellidos: "; getline(cin, estudiante.apellidos);
        cout << "Carrera (Ingenieria, Administracion, Derecho): "; getline(cin, estudiante.carrera);
        cout << "Departamento: "; getline(cin, estudiante.departamento);
        cout << "Municipio: "; getline(cin, estudiante.municipio);
        cout << "Aldea (opcional): "; getline(cin, estudiante.aldea);
        cout << "Telefono Personal: "; getline(cin, estudiante.telefonoPersonal);
        cout << "Telefono Casa: "; getline(cin, estudiante.telefonoCasa);
        cout << "Telefono Emergencia: "; getline(cin, estudiante.telefonoEmergencia);
        cout << "Fecha de Nacimiento (formato dd-mm-yyyy): "; getline(cin, estudiante.fechaNacimiento);
        estudiante.edad = calcularEdad(estudiante.fechaNacimiento);
        cout << "Edad calculada: " << estudiante.edad << " años" << endl;
        cout << "Año de ingreso a la universidad: "; cin >> estudiante.anioIngreso; cin.ignore();
        cout << "Correo Electronico: "; getline(cin, estudiante.correoElectronico);

        estudiantes.push_back(estudiante);
        cout << endl;
    }
}

// Mostrar Cursos del Semestre por Carrera
void mostrarCursosDelSemestre(string carrera, int semestre) {
    vector<Curso> cursos;

    if (carrera == "Ingenieria") {
        cursos = (semestre == 1) ? primerCicloIngenieria : segundoCicloIngenieria;
    } else if (carrera == "Administracion") {
        cursos = (semestre == 1) ? primerCicloAdministracion : segundoCicloAdministracion;
    } else if (carrera == "Derecho") {
        cursos = (semestre == 1) ? primerCicloDerecho : segundoCicloDerecho;
    } else {
        cout << "Carrera no válida.\n";
        return;
    }

    cout << "\nCursos disponibles para la carrera " << carrera << " en el semestre " << semestre << ":\n";
    for (const auto& curso : cursos) {
        cout << "Código: " << curso.codigoCurso << ", Nombre: " << curso.nombreCurso << ", Créditos: " << curso.creditos << '\n';
    }
}

// Asignar Curso
void asignarCurso(string carrera, int semestre) {
    mostrarCursosDelSemestre(carrera, semestre);

    string codigoCurso;
    cout << "Ingrese el código del curso que desea asignar: ";
    cin >> codigoCurso;

    vector<Curso> cursos;

    if (carrera == "Ingenieria") {
        cursos = (semestre == 1) ? primerCicloIngenieria : segundoCicloIngenieria;
    } else if (carrera == "Administracion") {
        cursos = (semestre == 1) ? primerCicloAdministracion : segundoCicloAdministracion;
    } else if (carrera == "Derecho") {
        cursos = (semestre == 1) ? primerCicloDerecho : segundoCicloDerecho;
    } else {
        cout << "Carrera no válida.\n";
        return;
    }

    for (const auto& curso : cursos) {
        if (curso.codigoCurso == codigoCurso) {
            cursosAsignadosConSemestre.push_back(CursoAsignado(curso, semestre));
            cout << "Curso asignado con éxito: " << curso.nombreCurso << " con " << curso.creditos << " créditos.\n";
            return;
        }
    }

    cout << "El código ingresado no corresponde a ningún curso del semestre.\n";
}

// Control de Notas
void registrarNotas(int codigoEstudiante) {
    for (const auto& curso : cursosAsignadosConSemestre) {
        if (curso.semestre == 1 || curso.semestre == 2) {
            Nota nuevaNota;
            nuevaNota.curso = curso.curso;
            cout << "Ingrese las notas parciales del curso " << curso.curso.nombreCurso << ":\n";
            for (int i = 1; i <= 3; i++) {
                double nota;
                cout << "Nota parcial " << i << ": ";
                cin >> nota;
                nuevaNota.notasParciales.push_back(nota);
            }

            nuevaNota.notaFinal = (nuevaNota.notasParciales[0] + nuevaNota.notasParciales[1] + nuevaNota.notasParciales[2]) / 3;

            if (nuevaNota.notaFinal >= 60) {
                nuevaNota.estado = "Aprobado";
            } else {
                nuevaNota.estado = "Reprobado";
            }

            controlNotas.push_back(nuevaNota);

            cout << "Nota final: " << nuevaNota.notaFinal << " (" << nuevaNota.estado << ")\n";
        }
    }
}

int main() {
    registrarEstudiantes();
    asignarCurso(estudiantes[0].carrera, 1);
    registrarNotas(estudiantes[0].codigo);

    return 0;
}