#include "Menu.h"

int main() {
    Menu::generateActivity();
    while(true){
        Menu::startMenu();
        while(!Menu::logout){
            Menu::showMenu();
        }
    }
}