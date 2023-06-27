#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct Evento {
    string nombre;
    string fecha;
    set<string> asistentes;
};

void agregarEvento(map<string, Evento>& eventos) {
    string nombreEvento, fechaEvento;
    cout << "Ingrese el nombre del evento: ";
    cin.ignore();
    getline(cin, nombreEvento);
    cout << "Ingrese la fecha del evento: ";
    getline(cin, fechaEvento);

    Evento evento;
    evento.nombre = nombreEvento;
    evento.fecha = fechaEvento;
    eventos[nombreEvento] = evento;

    cout << "Se ha agregado el evento exitosamente.\n";
}

void agregarAsistente(map<string, Evento>& eventos) {
    string nombreEvento, nombreAsistente;
    cout << "Ingrese el nombre del evento: ";
    cin.ignore();
    getline(cin, nombreEvento);

    auto it = eventos.find(nombreEvento);
    if (it != eventos.end()) {
        cout << "Ingrese el nombre del asistente: ";
        getline(cin, nombreAsistente);

        it->second.asistentes.insert(nombreAsistente);

        cout << "Se ha agregado el asistente al evento exitosamente.\n";
    } else {
        cout << "No se encontró el evento especificado.\n";
    }
}

void mostrarAsistentes(map<string, Evento>& eventos) {
    string nombreEvento;
    cout << "Ingrese el nombre del evento: ";
    cin.ignore();
    getline(cin, nombreEvento);

    auto it = eventos.find(nombreEvento);
    if (it != eventos.end()) {
        cout << "Lista de asistentes del evento \"" << it->second.nombre << "\":\n";
        for (const string& asistente : it->second.asistentes) {
            cout << asistente << endl;
        }
    } else {
        cout << "No se encontró el evento especificado.\n";
    }
}

void buscarPorFecha(const map<string, Evento>& eventos) {
    string fechaBuscada;
    cout << "Ingrese la fecha a buscar: ";
    cin.ignore();
    getline(cin, fechaBuscada);

    vector<string> eventosEncontrados;
    for (const auto& par : eventos) {
        if (par.second.fecha == fechaBuscada) {
            eventosEncontrados.push_back(par.second.nombre);
        }
    }

    if (!eventosEncontrados.empty()) {
        cout << "Eventos encontrados en la fecha \"" << fechaBuscada << "\":\n";
        for (const string& nombreEvento : eventosEncontrados) {
            cout << nombreEvento << endl;
        }
    } else {
        cout << "No se encontraron eventos en la fecha especificada.\n";
    }
}

int main() {
    map<string, Evento> eventos;
    int opcion;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Agregar un nuevo evento\n";
        cout << "2. Agregar asistentes a un evento\n";
        cout << "3. Mostrar lista de asistentes de un evento\n";
        cout << "4. Buscar eventos por fecha\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarEvento(eventos);
                break;
            case 2:
                agregarAsistente(eventos);
                break;
            case 3:
                mostrarAsistentes(eventos);
                break;
            case 4:
                buscarPorFecha(eventos);
                break;
            case 5:
                cout << "¡Hasta luego!\n";
                return 0;
            default:
                cout << "Opción inválida. Por favor, seleccione una opción válida.\n";
                break;
        }
    }

    return 0;
}