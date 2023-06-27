#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    string cadena;
    cout << "Ingrese una cadena de caracteres: ";
    getline(cin, cadena);

    deque<char> caracteres(cadena.begin(), cadena.end());

    cout << "Caracteres en el contenedor: ";
    for (auto it = caracteres.begin(); it != caracteres.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    for (auto it = caracteres.begin(); it != caracteres.end(); ++it) {
        if (tolower(*it) == 'a' || tolower(*it) == 'e' || tolower(*it) == 'i' ||
            tolower(*it) == 'o' || tolower(*it) == 'u') {
            *it = '*';
        }
    }

    cout << "Caracteres en orden inverso: ";
    for (auto rit = caracteres.rbegin(); rit != caracteres.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    cout << "Cadena resultante: ";
    for (char c : caracteres) {
        cout << c;
    }
    cout << endl;

    return 0;
}