#include <iostream>
#include "intervalo.h"
using namespace std;

/** 
 * **
   @file intervalo.cpp
   @brief Se proporciona parte de la clase intervalo y es necesario definir ciertos métodos para darle operatividad 
   @author MP Grupos B, C 
   @warning Módulo no definitivo (creado para ser modificado)

   Un ejemplo de ejecución es:

    Cuantos intervalos (max 10):5 
    Introduce [ o ( cotaInferior, cotaSuperior ) o ]: [0,10] (0,10] [0,10) (0,10) (10,10)
    Cuantos valores reales (max 10):6
    Introduce valor real: -1 -0.001 0 5.7  9.6  10
    Da como salida: 
    
 [0,10] : 0 5.7 9.6 10 
 (0,10] : 5.7 9.6 10 
 [0,10) : 0 5.7 9.6 
 (0,10) : 5.7 9.6 
 (0) :

 */

// Implementacion o definicion de metodos y funciones

bool Intervalo::valido(double cinf,double csup,bool cerrinf, bool cerrsup){

    return (( cinf < csup ) || ( cinf == csup && cerrinf == cerrsup));
}

//Constructor sin parametros
Intervalo::Intervalo(){

    cerradoInf =false;
    cerradoSup = false;
    cotaInf = 0;
    cotaSup = 0;

}

//Constructor 1 con parametros
Intervalo::Intervalo(double cotaInferior, double cotaSuperior){
    cerradoInf = true;
    cerradoSup = true;

    if(valido(cotaInferior,cotaSuperior,cerradoInf,cerradoSup)){
        cotaInf=cotaInferior;
        cotaSup=cotaSuperior;

    }else{

        cerradoInf =false;
        cerradoSup = false;
        cotaInf = 0;
        cotaSup = 0;

    }
}

//Constructor 2 con parametros
Intervalo::Intervalo(double cotaInferior, double cotaSuperior,bool cerradoInferior, bool cerradoSuperior){
   
   if(valido(cotaInferior,cotaSuperior,cerradoInf,cerradoSup)){
        cotaInf=cotaInferior;
        cotaSup=cotaSuperior;
        cerradoSup=cerradoSuperior;
        cerradoInf= cerradoInferior;


    }else{

        cerradoInf =false;
        cerradoSup = false;
        cotaInf = 0;
        cotaSup = 0;

    }
}
//_____________________________Consultores__________________________________

//Consultor de la cota inferior
double Intervalo:: getCotaInf()const{
    return cotaInf;
}

//Consultor de la cota Superior
double Intervalo:: getCotaSup()const{
    return cotaSup;
}

//Consulta si es cerrado en la cota inferior
bool Intervalo:: dentroCotaInf()const{
    return cerradoInf;
}

//Consulta si es cerrado en la cota superior
bool Intervalo:: dentroCotaSup()const{
    return cerradoSup;
}

//______________________________Otros____________________________________

//Modificar el intervalo
void Intervalo:: setIntervalo(double cotaInferior, double cotaSuperior,bool cerradoInferior, bool cerradoSuperior){
   
    if(valido(cotaInferior,cotaSuperior,cerradoInf,cerradoSup)){
        cotaInf=cotaInferior;
        cotaSup=cotaSuperior;
        cerradoSup=cerradoSuperior;
        cerradoInf= cerradoInferior;

    }else{
        cout << "Intervalo no valido";
    }

  }

//Te devuelve si un intervalo es vacio
bool Intervalo:: esVacio()const{
    bool es_vacio= false;

    if( cerradoInf == false &&  cerradoSup == false &&  cotaInf == 0 && cotaSup == 0){
        es_vacio = true;
    }
    return es_vacio;
}

//te devuelve si el numero esta dentro 
bool Intervalo:: estaDentro(double n)const{
    bool dentro = false;

    if(n >= cotaInf && n<= cotaSup){
        
        if(n == cotaSup && cerradoSup)
            dentro= true;
        else 
            if(n == cotaInf && cerradoInf)
                dentro= true;
        else 
            if( n < cotaSup && n > cotaInf )
                dentro=true;

    }
    return dentro;
}


//_________________________________________________________________________________________________________________

//Funciones auxiliares
void escribir(const Intervalo & obj) {
    if (obj.esVacio())
        cout << "(0)";
    else {
        if (obj.dentroCotaInf())
         cout << '[';
        else cout << '(';
        cout << obj.getCotaInf() << "," << obj.getCotaSup();
        if (obj.dentroCotaSup())
            cout << ']';
        else cout << ')';
    }
}

void leer(Intervalo & obj){
    // Formato de lectura del intervalo: [|( x,y )|]
    bool cerradoInf = true;
    bool cerradoSup = true;
    double cotaInf, cotaSup;
    char car;
    cin >> car;
    
    if (car == '(')
        cerradoInf = false;
    cin >> cotaInf;
    cin >> car;
    cin >> cotaSup;
    cin >> car;
    if (car == ')')
        cerradoSup = false;
    obj.setIntervalo(cotaInf, cotaSup, cerradoInf, cerradoSup);
}

void comprobarVacio(Intervalo obj){
	 escribir(obj);
    if (obj.esVacio())
        cout << " Vacio";
    else  cout << " NO Vacio";
    cout << endl;
}


