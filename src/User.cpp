#include "User.h"
#include "Mahasiswa.h"
#include "Administrator.h"
#include<bits/stdc++.h>

bool User::cekPengguna(const std::string& s, const std::string& t){
    std::ifstream pengguna("ListPengguna.txt");
    std::string line;
    int lineNumber = 0;
    int p = -1;
    bool ditemukan = false;
    if (pengguna.is_open()) {
        while (std::getline(pengguna, line)) {
            lineNumber++;
            if (line.find(s) != std::string::npos) {
                p = lineNumber;
            }
            if (line.find(t) != std::string::npos && lineNumber-1 == p) {
                ditemukan = true;
            }
        }
        pengguna.close();
    }
    return ditemukan;
}

void User::regist() {
    
}

std::string User::login() {
    std::string s, t, tipe;
    std::cout << "Username : ";
    std::cin >> s;
    std::cout << "Password : ";
    std::cin >> t;
    if(User::cekPengguna(s,t)){
        tipe = s;
    }
    else{
        tipe = "Admin";
    }
    return tipe;
}