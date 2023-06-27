#include <iostream>
#include <list>
#include <algorithm>
#include <cctype>  // Para transformar a mayúsculas

using namespace std;

list<string> leerSecuenciaPalabras(int numPalabras) {
    list<string> palabras;
    string palabra;
    cout << "Ingrese " << numPalabras << " palabra(s):\n";
    for (int i = 0; i < numPalabras; i++) {
        cin >> palabra;
        palabras.push_back(palabra);
    }
    return palabras;
}

void ordenarPalabras(list<string>& palabras) {
    palabras.sort();
}

int contarApariciones(const list<string> palabras, const string palabraBuscada) {
    return count(palabras.begin(), palabras.end(), palabraBuscada);
}

void convertirMayuscula(list<string> palabras) {
    transform(palabras.begin(), palabras.end(), palabras.begin(), [](string palabra) {
        for (char& c : palabra) {
            c = toupper(c);
        }
        return palabra;
    });
}

void mostrarLista(const list<string> palabras) {
    cout << "Lista de palabras:\n";
    for (const string& palabra : palabras) {
        cout << palabra << endl;
    }
}

int main() {
    int numPalabras;
    cout << "Ingrese el numero de palabras: ";
    cin >> numPalabras;
    string palabraBuscada;
    int apariciones;

    list<string> palabras;

    int opcion;
    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Ingresar palabras\n";
        cout << "2. Ordenar palabras\n";
        cout << "3. Contar apariciones de una palabra\n";
        cout << "4. Convertir palabras a mayúsculas\n";
        cout << "5. Mostrar lista de palabras\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                palabras = leerSecuenciaPalabras(numPalabras);
                break;
            case 2:
                ordenarPalabras(palabras);
                cout << "Las palabras se han ordenado.\n";
                break;
            case 3:
                cout << "Ingrese una palabra para buscar: ";
                cin >> palabraBuscada;
                apariciones = contarApariciones(palabras, palabraBuscada);
                cout << "La palabra '" << palabraBuscada << "' aparece " << apariciones << " veces.\n";
                break;
            case 4:
                convertirMayuscula(palabras);
                cout << "Las palabras se han convertido a mayúsculas.\n";
                break;
            case 5:
                mostrarLista(palabras);
                break;
            case 6:
                cout << "¡Hasta luego!\n";
                return 0;
            default:
                cout << "Opción inválida. Por favor, seleccione una opción válida.\n";
                break;
        }
    }

    return 0;
}