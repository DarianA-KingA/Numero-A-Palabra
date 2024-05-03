#include <iostream>
#include <cmath>
using namespace std;

/*
Enunciado: Realizar un programa C++ que lea un número real (correspondiente a un monto) y convertir
este monto a palabra.

Restricciones:
• El # tiene mascara 999,999,999.99
• Si el grupo determina puede variar el alcance del algoritmo.
• Solo llevar a palabras la parte entera del número.
• Utilizar el enfoque de divide y venceras

Autores: Darian Anderson King Arias

Fecha: 3/5/2024
*/

string ConvertirAPalabras(int numero, bool unEnLugarDeUno=false);
void ConvertirAPalabras(double num);


string cero_a_29[] = {"uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve", "diez",
                  "once", "doce", "trece", "catorce", "quince", "dieciséis", "diecisiete", "dieciocho", "diecinueve", "veinte",
                  "veintiuno", "veintidós", "veintitrés", "veinticuatro", "veinticinco", "veintiséis", "veintisiete", "veintiocho", "veintinueve"};
string decenas[] = { "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa" };
string centenas[] = {"ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos" };

string ConvertirAPalabras(int numero, bool unEnLugarDeUno) {
    int unidad;
    int decena;
    int centena;
    //0
    if (numero == 0)
        return "cero";
    //1-29
    if (numero <= 29)
    {
        if (unEnLugarDeUno && numero == 21)
            return "veintiún ";
        if (unEnLugarDeUno && numero == 1)
            return "un ";
        return  cero_a_29[numero-1]+" " ;
    }
    //99
    if (numero <=100) 
    {

        unidad = numero % 10;
        decena = numero / 10;
        return numero == 100 ? "cien " : decenas[decena - 3] + (unidad != 0 ? " y " + ConvertirAPalabras(unidad, unEnLugarDeUno) :"");
    }
    //999
    if (numero <= 1000)
    {
        //centena
        decena = numero % 100;
        centena = numero / 100;
        return numero == 1000? "mil " : centenas[centena - 1] + (decena != 0 ? " " + ConvertirAPalabras(decena, unEnLugarDeUno) : "");

    }
    // 999,999
    if (numero / 1000<1000)
    {
        int Miles= numero/1000;
        int restante = numero%1000;
        return Miles == 1 ? "mil " + (restante != 0 ? "" + ConvertirAPalabras(restante) : "") : ConvertirAPalabras(Miles,true) + "mil " + (restante != 0 ? "" + ConvertirAPalabras(restante) : "");
    }
    if (numero / 1000000 < 1000000)
    {
        int Millones = numero / 1000000;
        int restante = numero % 1000000;
        return Millones == 1 ? "Un millon " + (restante != 0 ? "" + ConvertirAPalabras(restante) : "") : ConvertirAPalabras(Millones, true) + "millones " + (restante != 0 ? "" + ConvertirAPalabras(restante) : "");
    }
    //corregin para un
    return "numero fuera de los limitas 0-999,999,999";
}

void ConvertirAPalabras(double num) {
     int parteEntera = static_cast<int>(std::floor(num));
     int centavos = static_cast<int>((num - parteEntera) * 100);
     string parteEnteraEnPalabras = ConvertirAPalabras(parteEntera);
     std::cout << "El monto en palabras es: " << parteEnteraEnPalabras << "con " << centavos << " centavos." << std::endl;
}
int main() {
    ConvertirAPalabras(999999999.12);
    return 0;
}
