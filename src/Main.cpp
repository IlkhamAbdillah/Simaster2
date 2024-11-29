#include "Menu.h"

int main(){
    Menu::generate();
    while(true){
        Menu::startMenu();
        while(!Menu::logout){
            Menu::showMenu();
        }
    }
}