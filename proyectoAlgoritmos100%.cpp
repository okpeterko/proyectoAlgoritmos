#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

struct Curso {
    string codigoCurso;
    string nombreCurso;
    int creditos;
    vector<double> notasParciales;
    double notaFinal;
    string estado;

    Curso(string cCodigo, string cNombre, int cCreditos) 
        : codigoCurso(cCodigo), nombreCurso(cNombre), creditos(cCreditos), notaFinal(0.0), estado("No evaluado") {}

    void calcularNotaFinal() {
        double suma = 0.0;
        for (size_t i = 0; i < notasParciales.size(); i++) {
            suma += notasParciales[i];
        }
        notaFinal = suma / notasParciales.size();
        estado = (notaFinal >= 10.5) ? "Aprobado" : "Reprobado";
    }

    void mostrarInfo() const {
        cout << "Curso: " << nombreCurso << endl;
        cout << "Notas parciales: ";
        for (size_t i = 0; i < notasParciales.size(); i++) {
            cout << notasParciales[i] << " ";
        }
        cout << endl;
        cout << "Nota final: " << notaFinal << endl;
        cout << "Estado: " << estado << endl;
    }
};

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
    vector<Curso> cursosAsignados;

    void calcularEdad() {
        int dia, mes, anio;
        sscanf(fechaNacimiento.c_str(), "%d-%d-%d", &dia, &mes, &anio);
        time_t t = time(0);
        struct tm* ahora = localtime(&t);
        int anioActual = ahora->tm_year + 1900;
        int mesActual = ahora->tm_mon + 1;
        int diaActual = ahora->tm_mday;
        edad = anioActual - anio;
        if (mesActual < mes || (mesActual == mes && diaActual < dia)) {
            edad--;
        }
    }
};

vector<Curso> primerCiclo;
vector<Curso> segundoCiclo;
vector<Curso> tercerCiclo;
vector<Curso> cuartoCiclo;
vector<Curso> quintoCiclo;
vector<Curso> sextoCiclo;
vector<Curso> septimoCiclo;
vector<Curso> octavoCiclo;
vector<Curso> novenoCiclo;
vector<Curso> decimoCiclo;

void inicializarCursos() {
    // Inicializar cursos del primer ciclo
    primerCiclo.push_back(Curso("001", "DESARROLLO HUMANO Y PROFESIONAL", 4));
    primerCiclo.push_back(Curso("002", "METODOLOGIA DE LA INVESTIGACION", 5));
    primerCiclo.push_back(Curso("003", "CONTABILIDAD I", 5));
    primerCiclo.push_back(Curso("004", "INTRODUCCION A LOS SISTEMAS DE COMPUTO", 5));
    primerCiclo.push_back(Curso("005", "LOGICA DE SISTEMAS", 5));
    // Continua con los cursos restantes...
}

// Lista de estudiantes
vector<Estudiante> estudiantes;

void registrarEstudiante() {
    Estudiante estudiante;
    estudiante.codigo = estudiantes.size() + 1;
    cout << "Registro de Estudiante #" << estudiante.codigo << endl;
    cout << "Nombres: ";
    cin.ignore();
    getline(cin, estudiante.nombres);
    cout << "Apellidos: ";
    getline(cin, estudiante.apellidos);
    cout << "Carrera: ";
    getline(cin, estudiante.carrera);
    cout << "Departamento: ";
    getline(cin, estudiante.departamento);
    cout << "Municipio: ";
    getline(cin, estudiante.municipio);
    cout << "Aldea: ";
    getline(cin, estudiante.aldea);
    cout << "Telefono personal: ";
    getline(cin, estudiante.telefonoPersonal);
    cout << "Telefono de casa: ";
    getline(cin, estudiante.telefonoCasa);
    cout << "Telefono de emergencia: ";
    getline(cin, estudiante.telefonoEmergencia);
    cout << "Fecha de nacimiento (dd-mm-yyyy): ";
    cin >> estudiante.fechaNacimiento;

    estudiante.calcularEdad();
    cout << "Edad: " << estudiante.edad << endl;
    cout << "Anio de ingreso: ";
    cin >> estudiante.anioIngreso;
    cout << "Correo electronico: ";
    cin >> estudiante.correoElectronico;

    estudiantes.push_back(estudiante);
}

void asignarCurso(Estudiante& estudiante) {
    int ciclo;
    cout << "Seleccionar ciclo (1-10): ";
    cin >> ciclo;

    vector<Curso>* cursos = nullptr;
    switch (ciclo) {
        case 1: cursos = &primerCiclo; break;
        case 2: cursos = &segundoCiclo; break;
        case 3: cursos = &tercerCiclo; break;
        case 4: cursos = &cuartoCiclo; break;
        case 5: cursos = &quintoCiclo; break;
        case 6: cursos = &sextoCiclo; break;
        case 7: cursos = &septimoCiclo; break;
        case 8: cursos = &octavoCiclo; break;
        case 9: cursos = &novenoCiclo; break;
        case 10: cursos = &decimoCiclo; break;
        default:
            cout << "Ciclo no valido." << endl;
            return;
    }

    if (cursos) {
        cout << "Cursos disponibles en el ciclo " << ciclo << ":" << endl;
        for (size_t i = 0; i < cursos->size(); i++) {
            cout << i + 1 << ". " << cursos->at(i).nombreCurso << " (" << cursos->at(i).codigoCurso << ")" << endl;
        }

        int seleccion;
        cout << "Seleccionar curso: ";
        cin >> seleccion;

        if (seleccion >= 1 && seleccion <= cursos->size()) {
            estudiante.cursosAsignados.push_back(cursos->at(seleccion - 1));
            cout << "Curso asignado." << endl;
        } else {
            cout << "Seleccion no valida." << endl;
        }
    }
}

void calcularNotas(Estudiante& estudiante) {
    for (size_t i = 0; i < estudiante.cursosAsignados.size(); i++) {
        Curso& curso = estudiante.cursosAsignados[i];
        cout << "Ingrese las notas para el curso " << curso.nombreCurso << " (maximo 4 notas):" << endl;
        for (int j = 0; j < 4; j++) {
            double nota;
            cout << "Nota " << (j + 1) << ": ";
            cin >> nota;
            curso.notasParciales.push_back(nota);
        }
        curso.calcularNotaFinal();
    }
}

void mostrarResultados(const Estudiante& estudiante) {
    cout << "Resultados para el estudiante " << estudiante.nombres << " " << estudiante.apellidos << ":" << endl;
    for (size_t i = 0; i < estudiante.cursosAsignados.size(); i++) {
        cout << "Curso: " << estudiante.cursosAsignados[i].nombreCurso << endl;
        estudiante.cursosAsignados[i].mostrarInfo();
    }
}

int main() {
    inicializarCursos();

    int opcion;
    do {
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Asignar curso a estudiante" << endl;
        cout << "3. Calcular notas de estudiante" << endl;
        cout << "4. Mostrar resultados de estudiante" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarEstudiante();
                break;
            case 2:
                if (estudiantes.empty()) {
                    cout << "No hay estudiantes registrados." << endl;
                } else {
                    int codigoEstudiante;
                    cout << "Ingrese el codigo del estudiante: ";
                    cin >> codigoEstudiante;
                    if (codigoEstudiante > 0 && codigoEstudiante <= estudiantes.size()) {
                        asignarCurso(estudiantes[codigoEstudiante - 1]);
                    } else {
                        cout << "Codigo de estudiante no valido." << endl;
                    }
                }
                break;
            case 3:
                if (estudiantes.empty()) {
                    cout << "No hay estudiantes registrados." << endl;
                } else {
                    int codigoEstudiante;
                    cout << "Ingrese el codigo del estudiante: ";
                    cin >> codigoEstudiante;
                    if (codigoEstudiante > 0 && codigoEstudiante <= estudiantes.size()) {
                        calcularNotas(estudiantes[codigoEstudiante - 1]);
                    } else {
                        cout << "Codigo de estudiante no valido." << endl;
                    }
                }
                break;
            case 4:
                if (estudiantes.empty()) {
                    cout << "No hay estudiantes registrados." << endl;
                } else {
                    int codigoEstudiante;
                    cout << "Ingrese el codigo del estudiante: ";
                    cin >> codigoEstudiante;
                    if (codigoEstudiante > 0 && codigoEstudiante <= estudiantes.size()) {
                        mostrarResultados(estudiantes[codigoEstudiante - 1]);
                    } else {
                        cout << "Codigo de estudiante no valido." << endl;
                    }
                }
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
                break;
        }
    } while (opcion != 5);

    return 0;
}
