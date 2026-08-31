#ifndef REGISTRAR_SALIDA_H
#define REGISTRAR_SALIDA_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cctype>

using namespace std;

// registrarSalida
// -----------------
// Recibe el codigo que el usuario recibio al entrar y lo busca dentro
// de la lista de codigos activos. Si lo encuentra, lo elimina de la
// lista (el vehiculo ya salio) y confirma la salida. Si no lo
// encuentra, avisa que el codigo no es valido, sin modificar nada.
inline bool registrarSalida(string codigo, vector<string> &codigosActivos) {
    for (char &c : codigo) {
        c = toupper(c);
    }

    auto posicion = find(codigosActivos.begin(), codigosActivos.end(), codigo);

    if (posicion != codigosActivos.end()) {
        codigosActivos.erase(posicion);
        cout << "Salida registrada para el codigo: " << codigo << endl;
        return true;
    }

    cout << "Codigo no encontrado, no se pudo registrar la salida." << endl;
    return false;
}

#endif