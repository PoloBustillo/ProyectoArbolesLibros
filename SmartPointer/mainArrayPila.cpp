#include <iostream>
#include <unordered_map>
#include <string>
#include "TArrayStack.hpp"
#include "Utils.hpp"

using std::cin, std::cout, std::string, std::unordered_map;


int main() {
    TArrayStack<double> stack(10);
    char option;
    double data;

    const unordered_map<string, string> menu = {
        {"(p/P)", "Push"},
        {"(o/O)", "Pop"},
        {"(e/E)", "Top"},
        {"(s/S)", "Show"},
        {"(q/Q)", "Quit"}
    };

    do {
        print_menu(menu);
        cin >> option;

        switch (tolower(option)) {
            case 'p':
                cout << "Agrega dato: ";
                cin >> data;
                stack.push(data);
                break;
            case 'o': {
                auto popped = stack.pop();
                if (popped.has_value()) {
                    cout << "Eliminado: " << popped.value() << '\n';
                }
                break;
            }
            case 'e': {
                auto top = stack.peek();
                if (top.has_value()) {
                    cout << "Tope: " << top.value() << '\n';
                }
                break;
            }
            case 's':
                stack.show();
                break;
            case 'q':
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
                break;
        }
    } while (tolower(option) != 'q');

    return 0;
}
