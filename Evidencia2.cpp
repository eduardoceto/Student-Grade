
// Eduardo Cepeda Torres A01782862
#include <iostream>
using namespace std;

class Alumno {  //Clase del ALumno
private:
    string nombre; //Nombre del alumno
    int matricula; //Matricula del alumno
    float C1, C2, C3, Cp1, Cp2, Cp3; //Calificaciones del alumno y calificaciones ponderadas
    bool aprovo; //Variable para saber si aprovo o no
public:
string getNombre(){ //Funcion para obtener el nombre del alumno
    return nombre;
}
int getMatricula(){ //Funcion para obtener la matricula del alumno
    return matricula;
}
float getC1(){  //Funcion para obtener la calificacion 1 del alumno
    return C1; 
}
float getC2(){ //Funcion para obtener la calificacion 2 del alumno
    return C2;
}
float getC3(){ //Funcion para obtener la calificacion 3 del alumno
    return C3;
}
bool getAprovo(){ //Funcion para obtener si aprovo o no el alumno
    return aprovo;
}
void setDatos(string nombreAlum, int matriculaAlum, float C1Alum, float C2Alum, float C3Alum){ //Funcion para ingresar los datos del alumno
    nombre = nombreAlum;
    matricula = matriculaAlum;
    C1 = C1Alum;
    C2 = C2Alum;
    C3 = C3Alum;
}  
float promedio(float por1, float por2, float por3) { //Funcion para obtener el promedio del alumno
    Cp1 = C1 * por1;
    Cp2 = C2 * por2;
    Cp3 = C3 * por3;
    return (Cp1 + Cp2 + Cp3);
}
bool aprobado() { //Funcion para saber si aprovo o no el alumno
    if (Cp1 + Cp2 + Cp3 >= 70){
        aprovo = true;
    }
    else{
        aprovo = false;
    }
    return aprovo;
}
};


class Profesor { //Clase del profesor
private:
    string nombre; //Nombre del profesor
    int numAlum; //Numero de alumnos
    float Por1, Por2, Por3; //Porcentajes de las calificaciones
public:
    Alumno grupo[10]; //Arreglo de alumnos

    string getNombre(){ //Funcion para obtener el nombre del profesor
        return nombre;
    }
    void getNumAlum(int num){ //Funcion para obtener el numero de alumnos
        numAlum = num;
    }
    void setNombre(string nombreProf){ //Funcion para ingresar el nombre del profesor
        nombre = nombreProf;
    }   
    void setPorcentajes(float porIn1, float porIn2, float porIn3){ //Funcion para ingresar los porcentajes de las calificaciones
        Por1 = porIn1;
        Por2 = porIn2;
        Por3 = porIn3;
    }
    float promedioGrupo() { //Funcion para obtener el promedio del grupo
        float sum = 0;
        for (int i = 0; i < numAlum; ++i) {
            sum += grupo[i].promedio(Por1, Por2, Por3);
        }
        return sum / numAlum;
    }
    void reprobados () { //Funcion para obtener los alumnos reprobados
        for (int i = 0; i < numAlum; ++i) {
            if (!grupo[i].getAprovo() == true) {
                cout << "Nombre: " << grupo[i].getNombre() << endl;
                cout << "Matricula: " << grupo[i].getMatricula() << endl;
                cout << "Promedio: " << grupo[i].promedio(Por1, Por2, Por3) << endl;
                cout << endl;
            }
            else{
                cout << endl;
            }
    }
}
};
//Variables
int numGrupos; //Numero de grupos
string nombreProf, nombreAlum; //Nombre del profesor y del alumno
int canAlum; //Cantidad de alumnos
int matriculaAlum;  //Matricula del alumno
float c1Alum, c2Alum, c3Alum; //Calificaciones del alumno
float porIn1, porIn2, porIn3; //Porcentajes de las calificaciones


int main(){
Profesor profe[10]; //Arreglo de profesores/grupos
cout << "Ingresa cuantos grupos hay en la escuela (maximo 10): "; //Se pide el numero de grupos
cin >> numGrupos;
cout  << endl;
while (numGrupos > 10 || numGrupos < 1){ //Se verifica que el numero de grupos sea valido
    cout << "El numero de grupos no puede ser mayor a 10 o menor a 1, por favor ingresa el numero de grupos de nuevo: ";
    cin >> numGrupos;
}   
for (int i = 0; i < numGrupos; i++){ //Se ingresan los datos de los profesores
    cout << "Ingresa el nombre del profesor " << i + 1 << ": ";
    cin >> nombreProf;
    profe[i].setNombre(nombreProf);
    cout  << endl; //Se ingresan los porcentajes de las calificaciones
    cout << "Ingresa el porcentaje de las calificaciones del grupo " << i + 1 << "(Deben de estar en decimales y su suma debe de dar a 1): " << endl;
    cout << "Ingresa el porcentaje de la calificacion 1: ";
    cin >> porIn1;
    cout << "Ingresa el porcentaje de la calificacion 2: ";
    cin >> porIn2;
    cout << "Ingresa el porcentaje de la calificacion 3: ";
    cin >> porIn3;
    cout  << endl;
    while (porIn1 + porIn2 + porIn3 != 1){ //Se verifica que la suma de los porcentajes sea igual a 1
        cout  << endl;
        cout << "La suma de los porcentajes no es igual a 1, por favor ingresa los porcentajes de nuevo: " << endl;
        cout  << endl;
        cout << "Ingresa el porcentaje de la calificacion 1: ";
        cin >> porIn1;
        cout << "Ingresa el porcentaje de la calificacion 2: ";
        cin >> porIn2;
        cout << "Ingresa el porcentaje de la calificacion 3: ";
        cin >> porIn3;
        cout  << endl;
    }
    profe[i].setPorcentajes(porIn1, porIn2, porIn3); //Se ingresan los porcentajes de las calificaciones
    cout << "Ingresa cuantos alumnos hay en el grupo " << i + 1 << ": "; //Se ingresa la cantidad de alumnos por grupo
    cin >> canAlum;
    profe[i].getNumAlum(canAlum); //Se ingresa la cantidad de alumnos por grupo
    cout  << endl;
    for (int j = 0; j < canAlum; j++){ //Se ingresan los datos de los alumnos
        cout << "Ingresa el nombre del alumno " << j + 1 << ": ";
        cin >> nombreAlum;
        cout << "Ingresa la matricula del alumno " << j + 1 << ": ";
        cin >> matriculaAlum;
        cout << "Ingresa la calificacion 1 del alumno " << j + 1 << ": ";
        cin >> c1Alum;
        cout << "Ingresa la calificacion 2 del alumno " << j + 1 << ": ";
        cin >> c2Alum;
        cout << "Ingresa la calificacion 3 del alumno " << j + 1 << ": ";
        cin >> c3Alum;
        profe[i].grupo[j].setDatos(nombreAlum, matriculaAlum, c1Alum, c2Alum, c3Alum); //Se ingresan los datos de los alumnos
        cout  << endl;
        if (profe[i].grupo[j].getAprovo() == true){ //Se verifica si aprovo o no el alumno
            cout << "El alumno " << nombreAlum << " con matricula " << matriculaAlum << " del grupo " << i + 1 << " ha aprobado" << endl;
            cout  << endl;
        }
        else{ 
            cout << "El alumno " << nombreAlum << " con matricula " << matriculaAlum << " del grupo " << i + 1 << " ha reprobado" << endl;
            cout  << endl;
        }
    }
}
for (int i = 0; i < numGrupos; i++){ //Se imprime el promedio del grupo y los alumnos reprobados
    cout << "El promedio del grupo " << i + 1 << " del profesor " << profe[i].getNombre() << " es: " << profe[i].promedioGrupo() << endl;
    cout  << endl;
    cout << "Los alumnos reprobados del grupo " << i + 1 << " son: " << endl;
    profe[i].reprobados();

}
return 0;
}

