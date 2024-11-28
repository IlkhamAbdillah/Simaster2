#include "User.h"
#include "Mahasiswa.h"
#include "Administrator.h"
#include <bits/stdc++.h>
#include <conio.h>

std::vector<std::string> User::username;
std::vector<std::string> User::password;

void User::getUser(){
    std::ifstream pengguna("ListPengguna.txt");
    std::string line;
    int lineNumber = 0;
    if(pengguna.is_open()){
        while (std::getline(pengguna, line)) {
            lineNumber++;
            if(lineNumber%2 == 1 && line != ""){
                username.push_back(line.substr(11));
            }
            if(lineNumber%2 == 0 && line != ""){
                password.push_back(line.substr(11));
            }
        }
        pengguna.close();
    }
}

bool User::cekPengguna(const std::string s, const std::string t){
    bool ditemukan = false;
    auto it = std::find(username.begin(), username.end(), s);
    if (it != username.end()) {
        int indeks = std::distance(username.begin(), it);
        if(password[indeks]==t){
            ditemukan = true;
        }
    }
    return ditemukan;
}

void User::regist() {
    std::string s, t;
    bool berhasil = false;
    do{
        std::cout << "=== Menu Registrasi ===" << std::endl;
        std::cout << "Username : ";
        std::cin >> s;

        if(s.substr(0,5) == "Admin"){
            std::cout << "\n!!!Tidak boleh mendaftar dengan awalan Admin!!!\n\n";
            char p;
            std::cout << "Tekan ENTER untuk mencoba username lain\n";
            std::cout << "Tekan tombol lain untuk kembali ke menu awal \n";
            std::cin.ignore();
            p = _getch();
            if(p!='\r'){
                break;
            }
            std::cout << "\033[2J\033[H";
            continue;
        }

        std::ifstream pengguna("ListPengguna.txt");
        std::string line;
        bool usedName = false;
        int lineNumber = 0;

        if(pengguna.is_open()){
            while(std::getline(pengguna, line)){
                lineNumber++;
                if(line.find(s) != std::string::npos && lineNumber%2 == 1){
                    usedName = true;
                    break;
                }
           }
           pengguna.close();
        }

        if(usedName){
            char p;
            std::cout << "\n!!!Username sudah digunakan!!!\n\n";
            std::cout << "Tekan ENTER untuk mencoba username lain\n";
            std::cout << "Tekan tombol lain untuk kembali ke menu awal \n";
            std::cin.ignore();
            p = _getch();
            if(p!='\r'){
                break;
            }
            std::cout << "\033[2J\033[H";
            continue;
        }

        std::cout << "Password : ";
        std::cin >> t;

        std::ofstream penggunaOut("ListPengguna.txt", std::ios::app);
        if(penggunaOut.is_open()){
            penggunaOut << "Username = " << s << "\n" << "Password = " << t << "\n\n\n";
            penggunaOut.close();
            berhasil = true;
            std::cout << "Registrasi berhasil! Silahkan menuju Menu Login... " << std::endl;
        }
    }while(!berhasil);
}

std::string User::login() {
    std::string s, t, tipe;
    bool ada = false;
    do{
        std::cout << "=== Menu Login ===" << std::endl;
        std::cout << "Username : ";
        std::cin >> s;
        std::cout << "Password : ";
        std::cin >> t;
        if(User::cekPengguna(s,t)){
            tipe = s;
            ada = true;
        }
        else{
            char p;
            std::cout << "\n!!!Username atau Password yang Anda masukkan salah!!!\n\n";
            std::cout << "Tekan ENTER untuk kembali ke menu login...\n";
            std::cout << "Tekan tombol lain untuk kembali ke menu awal \n";
            p = _getch();
            if(p!='\r'){
                tipe = "Adminout";
                break;
            }
            std::cout << "\033[2J\033[H";
        }
    }while(!ada);

    return tipe;
}