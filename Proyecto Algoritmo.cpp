#include <iostream>
#include <string>
#include <vector>
#include <ctime>

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

// Formato esperado: dd-mm-yyyy
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

int main() {
    vector<Estudiante> estudiantes;
    int numeroEstudiantes;

    cout << "Ingrese el numero de estudiantes a registrar: ";
    cin >> numeroEstudiantes;
    cin.ignore(); // Limpiar el buffer

    for (int i = 0; i < numeroEstudiantes; i++) {
        Estudiante estudiante;
        estudiante.codigo = i + 1;

        cout << "Registro de Estudiante #" << estudiante.codigo << endl;

        cout << "Nombres: ";
        getline(cin, estudiante.nombres);

        cout << "Apellidos: ";
        getline(cin, estudiante.apellidos);

        cout << "Carrera (Ingenieria, Administracion, Derecho, Medicina, Auditoria, Enfermeria, Ing. Civil, etc.): ";
        getline(cin, estudiante.carrera);

        cout << "Departamento: ";
        getline(cin, estudiante.departamento);

        cout << "Municipio: ";
        getline(cin, estudiante.municipio);

        cout << "Aldea (opcional): ";
        getline(cin, estudiante.aldea);

        cout << "Telefono Personal: ";
        getline(cin, estudiante.telefonoPersonal);

        cout << "Telefono Casa: ";
        getline(cin, estudiante.telefonoCasa);

        cout << "Telefono de Emergencia: ";
        getline(cin, estudiante.telefonoEmergencia);

        cout << "Fecha de Nacimiento (formato dd-mm-yyyy): ";
        getline(cin, estudiante.fechaNacimiento);

        estudiante.edad = calcularEdad(estudiante.fechaNacimiento);
        cout << "Edad calculada: " << estudiante.edad << " anios" << endl;

        cout << "Anio de ingreso a la universidad: ";
        cin >> estudiante.anioIngreso;
        cin.ignore(); // Limpiar el buffer

        cout << "Correo Electronico: ";
        getline(cin, estudiante.correoElectronico);

        estudiantes.push_back(estudiante);

        cout << endl;
    }

    cout << "Lista de estudiantes registrados:" << endl;

    // Bucle clásico en lugar de for basado en rango
    for (size_t i = 0; i < estudiantes.size(); i++) {
        const Estudiante& est = estudiantes[i];
        cout << "Codigo: " << est.codigo << endl;
        cout << "Nombres: " << est.nombres << endl;
        cout << "Apellidos: " << est.apellidos << endl;
        cout << "Carrera: " << est.carrera << endl;
        cout << "Departamento: " << est.departamento << endl;
        cout << "Municipio: " << est.municipio << endl;
        cout << "Aldea: " << (est.aldea.empty() ? "No especificado" : est.aldea) << endl;
        cout << "Telefono Personal: " << est.telefonoPersonal << endl;
        cout << "Telefono Casa: " << est.telefonoCasa << endl;
        cout << "Telefono de Emergencia: " << est.telefonoEmergencia << endl;
        cout << "Fecha de Nacimiento: " << est.fechaNacimiento << endl;
        cout << "Edad: " << est.edad << " anios" << endl;
        cout << "Anio de ingreso: " << est.anioIngreso << endl;
        cout << "Correo Electronico: " << est.correoElectronico << endl;
        cout << "-----------------------" << endl;
    }

    return 0;
}

