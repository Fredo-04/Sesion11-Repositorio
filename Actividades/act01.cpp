#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template <typename T>
T sumaVector(const vector<T> numeros) {
    T suma = 0;
    for (T numero : numeros) {
        suma += numero;
    }
    return suma;
}

template <typename M>
M encontrarMaximo(const vector<M> numeros) {
    M maximo = numeros[0];
    for (M numero : numeros) {
        if (numero > maximo) {
            maximo = numero;
        }
    }
    return maximo;
}

template <typename N>
N encontrarMinimo(const vector<N> numeros) {
    N minimo = numeros[0];
    for (N numero : numeros) {
        if (numero < minimo) {
            minimo = numero;
        }
    }
    return minimo;
}

template <typename O>
vector<O> ordenarNumeros(const vector<O> numeros) {
    vector<O> numerosOrdenados = numeros;
    sort(numerosOrdenados.begin(), numerosOrdenados.end());
    return numerosOrdenados;
}

template <typename P>
vector<P> eliminarPares(const vector<P> numeros) {
    vector<P> numerosImpares;
    for (P numero : numeros) {
        if (numero % 2 != 0) {
            numerosImpares.push_back(numero);
        }
    }
    return numerosImpares;
}

int main() {
    vector<int> numeros;
    int opcion, num;

    do {
        // Menú de opciones
        cout << "\tMENU\t" << endl;
        cout << "1. Agregar numero" << endl;
        cout << "2. Calcular suma" << endl;
        cout << "3. Encontrar maximo" << endl;
        cout << "4. Encontrar minimo" << endl;
        cout << "5. Ordenar numeros" << endl;
        cout << "6. Eliminar numeros pares" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese un número entero: ";
                cin >> num;
                numeros.push_back(num);
                break;
            case 2:
                cout << "Suma del vector: " << sumaVector(numeros) << endl;
                break;
            case 3:
                cout << "El numero maximo es: " << encontrarMaximo(numeros) << endl;
                break;
            case 4:
                cout << "El numero minimo es: " << encontrarMinimo(numeros) << endl;
                break;
            case 5: {
                vector<int> numerosOrdenados = ordenarNumeros(numeros);
                cout << "El vector ordenado de forma ascendente son: ";
                for (int numero : numerosOrdenados) {
                    cout << numero << " ";
                }
                cout << endl;
                break;
            }
            case 6: {
                vector<int> numerosImpares = eliminarPares(numeros);
                cout << "Los numeros impares son: ";
                for (int numero : numerosImpares) {
                    cout << numero << " ";
                }
                cout << endl;
                break;
            }
            case 0:
                cout << "END" << endl;
                break;
            default:
                cout << "Incorrecto. Ingrese caracter valido\n";
        }
    } while (opcion != 0);

    return 0;
}