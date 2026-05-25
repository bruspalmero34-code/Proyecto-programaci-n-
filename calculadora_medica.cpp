#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

using namespace std;

int main() {    
char opcion;
double peso=0, altura=0, edad=0;
string nombre, apellido, sexo;
double imc=0, osmolaridad=0, aclaramiento=0;
double pam=0;
double asc=0;
double gastoCardiaco=0;

while (true){

system(CLEAR);

cout<< "===========Calculadora Medica============" << endl;
cout<< "*****************************************" << endl;
cout<< "Bienvenido a la calculadora medica, por favor seleccione una opcion: " << endl;
cout<<" "<< endl;
cout<<"===========INFORMACION GENERAL============" << endl;
cout<<"a. guardar datos del paciente" << endl;
cout<<"b. mostrar datos del paciente" << endl;
cout<<"c. modificar datos del paciente" << endl;
cout<<"d. eliminar datos del paciente" << endl;
cout<<"e. resultados totales" << endl;
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

system(CLEAR);

switch (opcion) {


            case 'a':{

            cout << "Ingrese el nombre del paciente: ";
            cin >> nombre;
            cout << "Ingrese el apellido del paciente: ";
            cin >> apellido;
            cout<< "Ingrese el sexo del paciente (M/F): ";
            cin >> sexo;
            cout << "Ingrese el peso del paciente en kg: ";
            cin >> peso;
            cout << "Ingrese la altura del paciente en metros: ";
            cin >> altura;
            cout << "Ingrese la edad del paciente: ";
            cin >> edad;    
            cout << "Datos del paciente guardados exitosamente." << endl;
        break;
        }
        case 'b':{
          cout << "Mostrando datos del paciente..." << endl;
            cout << "Datos del paciente:" << endl;
            cout << "Nombre: " << nombre << endl;   
            cout << "Apellido: " << apellido << endl;
            cout << "Sexo: " << sexo << endl;
            cout << "Peso: " << peso << " kg" << endl;
            cout << "Altura: " << altura << " m" << endl;
            cout << "Edad: " << edad << " años" << endl;
            break;
            }
            case 'c':{
            cout << "Modificar datos del paciente..." << endl;
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
            break;
            }

            case 'd':{
            cout << "Eliminar datos del paciente..." << endl;
            nombre = "";
            apellido = "";
            sexo = "";
            peso = 0;
            altura = 0;
            edad = 0;
            cout << "Datos del paciente eliminados exitosamente." << endl;
            break;
            }

            case 'e':{
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
            break;
            }


            case '1':{
            
         if (peso <= 0) {
                cout << "No hay peso registrado. Ingrese el peso en kg: ";
                cin >> peso;
                } else {
                    cout << "[Usando peso registrado: " << peso << " kg]" << endl;
                }if (altura <= 0) {
                cout << "No hay altura registrada. Ingrese la altura en metros: ";
                cin >> altura;
                } else {
                cout << "[Usando altura registrada: " << altura << " m]" << endl;
                }if (altura <= 0 || peso <= 0) {
                cout << "Error: El peso y la altura deben ser mayores que cero." << endl;
                    break; }
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


            break;
            }
            case '2':{

            double sodio, glucosa, urea;

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

            break;
            }
            case '3':{

            double creatinina;

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
                    cout << "No hay sexo registrado. Ingrese el sexo del paciente (M/F): ";
                    cin >> sexo;
                } else {
                    cout << "[Usando sexo registrado: " << sexo << "]" << endl;
                }
            cout << "Ingrese su nivel de creatinina en mg/dL: ";
            cin >> creatinina;
            aclaramiento = (140 - edad) * peso / (72 * creatinina);
                if (sexo == "F" || sexo == "f") {
                aclaramiento *= 0.85;
                }else if (sexo == "M" || sexo == "m") {
                aclaramiento *= 1.0;
                }

            cout << "El aclaramiento de creatinina es: " << aclaramiento << " mL/min" << endl;
            if(aclaramiento < 60) {
            cout << "Función renal disminuida" << endl;
            } else {
            cout << "Función renal normal" << endl;
            }

            break;
            }
            case '4': {

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
                break;
              }

            case '5':{

            double presionSistolica=0, presionDiastolica=0;
            cout << "Ingrese la presión sistólica en mmHg: ";
            cin >> presionSistolica;
            cout << "Ingrese la presión diastólica en mmHg: ";
            cin >> presionDiastolica;
            pam = (presionSistolica* presionDiastolica) / 3;
            cout << "La presión arterial media (PAM) es: " << pam << " mmHg" << endl;
            if (pam < 70) {
            cout << "PAM baja, posible hipotensión" << endl;
            } else if (pam >= 70 && pam <= 100) { 
            cout << "PAM normal" << endl;
            } else {
            cout << "PAM alta, posible hipertensión" << endl;
            }   
        
            break;
            }

            case '6':{

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
           
            break;
            }

            case '0': {

                cout <<"saliendo del programa..." << endl;
            return 0;

            break;
            }
            default:{

            cout << "Opcion no valida, por favor seleccione una opcion del menu." << endl;

            break;  
            }

            }
                cout << "\nPresione Enter para continuar...";
                cin.ignore(10000, '\n'); // Limpiar el buffer de entrada    
                cin.get();
        }
    }