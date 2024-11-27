#include "User.h"
#include "Mahasiswa.h"
#include "Administrator.h"
#include<bits/stdc++.h>

bool User::cekPengguna(const std::string& s, const std::string& t){
    std::ifstream pengguna("ListPengguna.txt");
    std::string line;
    std::string lastUsername;
    std::string lastPassword;
    int lineNumber = 0;
    int p = -1;
    bool ditemukan = false;
    if (pengguna.is_open()) {
        while (std::getline(pengguna, line)) {
            lineNumber++;
            if(lineNumber%2 == 1 && line != ""){
                lastUsername = line.substr(11);
                if(s == lastUsername){
                    p = lineNumber;
                }
            }
            else if(lineNumber%2 == 0 && line !=""){
                lastPassword = line.substr(11);
                if(t == lastPassword && lineNumber-1 == p){
                    ditemukan = true;
                }
            }
        }
        pengguna.close();
    }
    return ditemukan;
}

bool User::regist() {
    std::string s, t;
    bool berhasil = false;
    do{
        std::cout << "=== Menu Registrasi ===" << std::endl;
        std::cout << "Username : ";
        std::cin >> s;

        if(s.substr(0,5) == "Admin"){
            std::cout << "Tidak boleh mendaftar dengan awalan Admin... \n";
            std::cin.ignore();
            std::cin.get();
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
            std::cout << "Username sudah ada yang menggunakan, Tekan ENTER untuk mencoba username lain... \n";
            std::cin.ignore();
            std::cin.get();
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

    return berhasil;
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
            std::cout << "Username atau Password yang Anda masukkan salah \nTekan ENTER untuk kembali ke menu login...\n";
            std::cin.ignore();
            std::cin.get();
            std::cout << "\033[2J\033[H";
        }
    }while(!ada);

    return tipe;
}