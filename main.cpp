#include "Utils.hpp"

using std::unordered_map, std::string;

int main() {
    const unordered_map<string, string> menu_items = {
        {"(L)", "Cargar libros"},
        {"(M)", "Mostrar Libros"},
        {"(B)", "Buscar Libros"},
        {"(S)", "Salir"}
    };
    print_menu(menu_items);

    return 0;
}
