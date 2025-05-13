//
// Created by Mario Bustillo on 29/01/25.
//

#ifndef UTILS_H
#define UTILS_H
#include<print>
#include<unordered_map>
#include<string>

using std::print, std::string, std::unordered_map;

/*
 * Print menu items
 * @param menu_items: unordered_map with menu items
 */
void print_menu(unordered_map<string, string> menu_items) {
    print("MENU:");
    for (auto menu_item: menu_items) {
        print("\nOpcion {0}: \033[1;40;33m{1}\033[0m\n", menu_item.first, menu_item.second);
    }
}

#endif //UTILS_H
