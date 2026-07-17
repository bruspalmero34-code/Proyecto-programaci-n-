#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <fstream>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void menu();
void leerPacientesDesdeArchivo();
void calcularIMC();
void calcularOsmolaridad();
void calcularAclaramiento();
void calcularASC();
void calcularPAM();
void calcularGastoCardiaco();
void mostrarDatosPaciente();
void guardarDatosPaciente();
void modificarDatosPaciente();
void eliminarDatosPaciente();
void mostrarResultadosTotales();
void buscarPacienteEnArchivo();
void pausa();

using namespace std;
   
char opcion=' ';
double peso=0, altura=0, edad=0;
string nombre, apellido, sexo;
double imc=0, osmolaridad=0, aclaramiento=0;
double pam=0;
double asc=0;
double gastoCardiaco=0;


int main() {

while (true){

system(CLEAR);

menu();

system(CLEAR);


        switch (opcion) {

        case 'a':
            guardarDatosPaciente();
        break;
        
        case 'b':
            mostrarDatosPaciente();
        break;
            
        case 'c':    
            modificarDatosPaciente();
        break;

        case 'd':
            eliminarDatosPaciente();
        break;
            
        case 'e':
            mostrarResultadosTotales();
        break;

        case 'f':
            leerPacientesDesdeArchivo();
        break;
            
        case 'g':
            buscarPacienteEnArchivo();
        break;

        case '1':    
            calcularIMC();
        break;
            
        case '2':
            calcularOsmolaridad();
        break;
            
        case '3':
            calcularAclaramiento();
        break;
            
        case '4':
            calcularASC();    
        break; 
            
        case '5':
            calcularPAM();
        break;
            
        case '6':
            calcularGastoCardiaco();
        break;    

        case '0': 
            cout<<"saliendo del programa..." << endl;
            return 0;
        break;
            
        default:
            cout<< "Opcion no valida, por favor seleccione una opcion del menu." << endl;
        break;  
           
        }
         pausa();
    }
}


void menu() {

    cout<< "===========Calculadora Medica============" << endl;
    cout<< "*****************************************" << endl;
    cout<< "Bienvenido a la calculadora medica, por favor seleccione una opcion: " << endl;
    cout<<" "<< endl;
    cout<<"===========INFORMACION GENERAL============" << endl;
    cout<<"a. Guardar datos del paciente" << endl;
    cout<<"b. Mostrar datos del paciente" << endl;
    cout<<"c. Modificar datos del paciente" << endl;
    cout<<"d. Eliminar datos del paciente" << endl;
    cout<<"e. Resultados totales" << endl;
    cout<<"f. Ver historial de pacientes guardados (.txt)" << endl;
    cout<<"g. Buscar paciente en sistema" << endl;
    cout<<" "<< endl;
    cout<< "===METABOLISMO, NUTRICION E HIDRATACION===" << endl;
    cout<< "1. Calcular IMC (Masa Corporal)" << endl;
    cout<< "2. Calcular osmolaridad plasmatica" << endl;
    cout<<" "<< endl;
    cout<< "====FUNCION RENAL Y AJUSTE DE FARMACOS====" << endl;
    cout<< "3. Aclaramiento de creatinina" << endl;
    cout<< "4. Area de superficie corporal (ASC)" << endl;
    cout<<" "<< endl;
    cout<< "==MONITOREO CARDIOVASCULAR Y HEMODINAMICO==" << endl;
    cout<< "5. Calcular Presion arterial media (PAM)" << endl;
    cout<< "6. Calcular Gasto Cardiaco" << endl;
    cout<<" "<< endl;
    cout<< "0. SALIR" << endl;
    cin >> opcion;
    
}


void pausa() {

    cout << "\nPresione Enter para continuar...";
    cin.ignore(10000, '\n'); // Limpiar el buffer de entrada    
    cin.get();
}

void mostrarDatosPaciente() {

    cout << "Datos del paciente:" << endl;
    cout << "Nombre: " << nombre << endl;   
    cout << "Apellido: " << apellido << endl;
    cout << "Sexo: " << sexo << endl;
    cout << "Peso: " << peso << " kg" << endl;
    cout << "Altura: " << altura << " m" << endl;
    cout << "Edad: " << edad << " años" << endl;
}

void guardarDatosPaciente() {

    if (nombre.empty() && apellido.empty()) {
        cout << "Ingrese el nombre del paciente: ";
        cin >> nombre;
        cout << "Ingrese el apellido del paciente: ";
        cin >> apellido;
        cout << "Ingrese el sexo del paciente (M/F): ";
        cin >> sexo;
        cout << "Ingrese el peso del paciente en kg: ";
        cin >> peso;
        cout << "Ingrese la altura del paciente en metros: ";
        cin >> altura;
        cout << "Ingrese la edad del paciente: ";
        cin >> edad;    
    } else {
        cout << "[Guardando datos actuales de: " << nombre << " " << apellido << "]" << endl;
    }

    ofstream archivo("pacientes.txt", ios::app);

    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo para guardar los datos." << endl;
        return;
    }

    archivo << "==================================================\n";
    archivo << " PACIENTE: " << apellido << ", " << nombre << "\n";
    archivo << "==================================================\n";
    archivo << " Sexo: " << sexo << " | Edad: " << edad << " anos\n";
    archivo << " Peso: " << peso << " kg | Altura: " << altura << " m\n";
    archivo << "--------------------------------------------------\n";
    archivo << " RESULTADOS DE CALCULOS MEDICOS:\n";
    archivo << "  - IMC: " << imc << "\n";
    archivo << "  - Osmolaridad Plasmatica: " << osmolaridad << " mOsm/L\n";
    archivo << "  - Aclaramiento de Creatinina: " << aclaramiento << " mL/min\n";
    archivo << "  - Area de Superficie Corporal (ASC): " << asc << " m2\n";
    archivo << "  - Presion Arterial Media (PAM): " << pam << " mmHg\n";
    archivo << "  - Gasto Cardiaco: " << gastoCardiaco << " L/min\n";
    archivo << "==================================================\n\n";

    archivo.close();

    cout << "\n¡Datos y calculos del paciente guardados exitosamente en 'pacientes.txt'!" << endl;

}

void modificarDatosPaciente() {
    cout << "Ingrese el nuevo nombre del paciente: ";
    cin >> nombre;
    cout << "Ingrese el nuevo apellido del paciente: ";
    cin >> apellido;
    cout<< "Ingrese el nuevo sexo del paciente (M/F): ";
    cin >> sexo;
    cout << "Ingrese el nuevo peso del paciente en kg: ";
    cin >> peso;
    cout << "Ingrese la nueva altura del paciente en metros: ";
    cin >> altura;
    cout << "Ingrese la nueva edad del paciente: ";
    cin >> edad;
    cout << "Datos del paciente modificados exitosamente." << endl;
}

void eliminarDatosPaciente() {
    nombre = "";
    apellido = "";
    sexo = "";
    peso = 0;
    altura = 0;
    edad = 0;
    cout << "Datos del paciente eliminados exitosamente." << endl;
}

void mostrarResultadosTotales() {

    cout << "Resultados totales del paciente..." << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "Sexo: " << sexo << endl;
    cout << "Peso: " << peso << " kg" << endl;
    cout << "Altura: " << altura << " m" << endl;
    cout << "Edad: " << edad << " años" << endl;
    cout << "IMC: "<< imc << endl;
    cout << "Osmolaridad Plasmatica: " << osmolaridad << " mOsm/L" << endl;
    cout << "Aclaramiento de creatinina: " << aclaramiento << " mL/min" << endl;
    cout << "Gasto Cardiaco: " << gastoCardiaco << " L/min" << endl;
    cout << "Área de Superficie Corporal: " << asc << " m²" << endl;
}

void calcularIMC() {

    if (peso <= 0) {
        cout << "No hay peso registrado. Ingrese el peso en kg: ";
        cin >> peso;
    } else {
        cout << "[Usando peso registrado: " << peso << " kg]" << endl;
    }
    if (altura <= 0) {
        cout << "No hay altura registrada. Ingrese la altura en metros: ";
        cin >> altura;
    } else {
        cout << "[Usando altura registrada: " << altura << " m]" << endl;
    }
    if (altura <= 0 || peso <= 0) {
        cout << "Error: El peso y la altura deben ser mayores que cero." << endl;
        return;
    }
    imc = peso / pow(altura, 2);
    cout << "Su IMC es: " << imc << endl;
    if (imc < 18.5) {
        cout << "Bajo peso" << endl;
    } else if (imc >= 18.5 && imc < 25) {
        cout << "Peso normal" << endl;
    } else if (imc >= 25 && imc < 30) {
        cout << "Sobrepeso" << endl;
    } else {
        cout << "Obesidad" << endl;
    }
}

void calcularOsmolaridad() {

    double sodio=0, glucosa=0, urea=0;

    cout << "Ingrese el nivel de sodio en mEq/L: ";
    cin >> sodio;
    cout << "Ingrese el nivel de glucosa en mg/dL: ";
    cin >> glucosa;
    cout << "Ingrese el nivel de urea en mg/dL: ";
    cin >> urea;

    osmolaridad = 2 * sodio + (glucosa / 18) + (urea / 2.8);

    cout << "La osmolaridad plasmática es: " << osmolaridad << " mOsm/L" << endl;
    if (osmolaridad < 275) {
        cout << "Hiposmolaridad" << endl;
    } else if (osmolaridad >= 275 && osmolaridad <= 295) { 
        cout << "Osmolaridad normal" << endl;
    } else {
        cout << "Hiperosmolaridad" << endl;
    }
}

void calcularAclaramiento() {

    double creatinina=0;

    if (peso <= 0) {
        cout << "No hay peso registrado. Ingrese el peso en kg: ";
        cin >> peso;
    } else {
        cout << "[Usando peso registrado: " << peso << " kg]" << endl;
    }

    if (edad <= 0) {
        cout << "No hay edad registrada. Ingrese edad del paciente: ";
        cin >> edad;
    } else {
        cout << "[Usando edad registrada: " << edad << " anos]" << endl;
    }
    if (sexo.empty()) {
        cout << "No hay sexo registrado. Ingrese el sexo del paciente: ";
        cin >> sexo;
    } else {
        cout << "[Usando sexo registrado: " << sexo << "]" << endl;
    }   
    
    cout << "Ingrese el valor de creatinina serica (mg/dL): ";
    cin >> creatinina;

    aclaramiento = ((140 - edad) * peso) / (72 * creatinina);

    if (sexo == "F" || sexo == "f") {
        aclaramiento = aclaramiento * 0.85;
    }

    cout << "El aclaramiento de creatinina es: " << aclaramiento << " mL/min" << endl;
}

void calcularASC() {
    if (peso <= 0) {
        cout << "No hay peso registrado. Ingrese el peso en kg: ";
        cin >> peso;
    } else {
        cout << "[Usando peso registrado: " << peso << " kg]" << endl;
    }
    if (altura <= 0) {
        cout << "No hay altura registrada. Ingrese la altura en metros: ";
        cin >> altura;
    } else {
        cout << "[Usando altura registrada: " << altura << " m]" << endl;
    }
    asc=sqrt(altura*peso)/3600;
    cout << "El área de superficie corporal (ASC) es: " << asc << " m²" << endl;
}

void calcularPAM() {
    double presionSistolica=0, presionDiastolica=0;
    cout << "Ingrese la presión sistólica en mmHg: ";
    cin >> presionSistolica;
    cout << "Ingrese la presión diastólica en mmHg: ";
    cin >> presionDiastolica;

    pam = (presionSistolica + (2 * presionDiastolica)) / 3;

    cout << "La presión arterial media (PAM) es: " << pam << " mmHg" << endl;
    if (pam < 70) {
        cout << "PAM baja, posible hipotensión" << endl;
    } else if (pam >= 70 && pam <= 100) { 
        cout << "PAM normal" << endl;
    } else {
        cout << "PAM alta, posible hipertensión" << endl;
    }   
}

void calcularGastoCardiaco() {
    double volumenSistolico, frecuenciaCardiaca;
    cout << "Ingrese el volumen sistólico en mL: ";
    cin >> volumenSistolico;
    cout << "Ingrese la frecuencia cardíaca en latidos por minuto: ";
    cin >> frecuenciaCardiaca;
    gastoCardiaco = (volumenSistolico * frecuenciaCardiaca) / 1000;
    cout << "El gasto cardíaco es: " << gastoCardiaco << " L/min" << endl;
    if (gastoCardiaco < 4) {
        cout << "Gasto cardíaco bajo, posible insuficiencia cardíaca" << endl;
    } else if (gastoCardiaco >= 4 && gastoCardiaco <= 8) {
        cout << "Gasto cardíaco normal" << endl;
    } else {
        cout << "Gasto cardíaco alto, posible hiperactividad cardíaca" << endl;
    }   
}

void mostrarResultadosTotales() {
    cout << "Resultados totales del paciente..." << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "Sexo: " << sexo << endl;
    cout << "Peso: " << peso << " kg" << endl;
    cout << "Altura: " << altura << " m" << endl;
    cout << "Edad: " << edad << " años" << endl;
    cout << "IMC: "<< imc << endl;
    cout << "Osmolaridad Plasmatica: " << osmolaridad << " mOsm/L" << endl;
    cout << "Aclaramiento de creatinina: " << aclaramiento << " mL/min" << endl;
    cout << "Gasto Cardiaco: " << gastoCardiaco << " L/min" << endl;
    cout << "Área de Superficie Corporal: " << asc << " m²" << endl;
}

void leerPacientesDesdeArchivo() {

    ifstream archivo("pacientes.txt");

    if (!archivo.is_open()) {
        cout << "\n[Aviso]: No se encontraron pacientes registrados o el archivo 'pacientes.txt' aun no existe.\n";
        return;
    }

    string linea;
    cout << "\n=========================================\n";
    cout << "      LISTA DE PACIENTES REGISTRADOS     \n";
    cout << "=========================================\n";

    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    cout << "=========================================\n";

    archivo.close();
}

void buscarPacienteEnArchivo() {
    ifstream archivo("pacientes.txt");

    if (!archivo.is_open()) {
        cout << "\n[Aviso]: No se encontraron registros o el archivo 'pacientes.txt' aun no existe.\n";
        return;
    }

    string busqueda;
    cout << "Ingrese el apellido o nombre del paciente a buscar: ";
    cin >> busqueda;

    string linea;
    bool encontrado = false;
    string bloquePaciente = "";
    bool leyendoPaciente = false;
    bool coincideBusqueda = false;

    
    while (getline(archivo, linea)) {

        if (linea == "==================================================") {
            if (leyendoPaciente) {
                if (coincideBusqueda) {
                    cout << bloquePaciente << "==================================================\n\n";
                    encontrado = true;
                }

                bloquePaciente = "";
                coincideBusqueda = false;
                leyendoPaciente = false;
            } else {
                leyendoPaciente = true;
                bloquePaciente += linea + "\n";
            }
            continue;
        }

        if (leyendoPaciente) {
            bloquePaciente += linea + "\n";
            if (linea.find(busqueda) != string::npos) {
                coincideBusqueda = true;
            }
        }
    }

    if (coincideBusqueda) {
        cout << bloquePaciente << "==================================================\n\n";
        encontrado = true;
    }

    archivo.close();

    if (!encontrado) {
        cout << "\nNo se encontro ningun paciente que coincida con: '" << busqueda << "'\n";
    }
}