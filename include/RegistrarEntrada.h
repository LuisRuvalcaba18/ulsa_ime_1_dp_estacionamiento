#ifndef REGISTRAR_ENTRADA_H
#define REGISTRAR_ENTRADA_H

#include <string>
#include <vector>
#include <iostream>
#include <cctype>

using namespace std;

// registrarEntrada
// ------------------
// Recibe lo que el usuario tecleo (por ejemplo "suv" o "sedan"),
// lo convierte a mayusculas y le agrega un numero consecutivo para
// formar el codigo de acceso del vehiculo (ejemplo: "SUV1").
// El codigo generado se agrega a la lista de codigos activos
// (los vehiculos que en este momento estan dentro del estacionamiento)
// y se regresa al cliente  por si se necesita usar mas adelante.
string registrarEntrada(string textoIngresado, int &consecutivo, vector<string> &codigosActivos) {
    // Buena practica: no asumir que el usuario siempre escribe en
    // mayusculas, lo convertimos nosotros para mantener consistencia.
    for (char &c : textoIngresado) {
        c = toupper(c);
    }

    consecutivo++;
    string codigo = textoIngresado + to_string(consecutivo);

    codigosActivos.push_back(codigo);

    cout << "Entrada registrada. Tu codigo de acceso es: " << codigo << endl;

    return codigo;
}

#endif