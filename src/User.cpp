#include "User.h"
#include "Mahasiswa.h"
#include "Administrator.h"
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

vector<string> User::username;
vector<string> User::password;

void User::getUser(){
    ifstream pengguna("ListPengguna.txt");
    string line;
    int lineNumber = 0;
    if(pengguna.is_open()){
        while (getline(pengguna, line)) {
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

bool User::checkUser(const string input_username, const string input_password){
    bool ditemukan = false;
    auto ambil = find(username.begin(), username.end(), input_username);
    if (ambil != username.end()) {
        int indeks = distance(username.begin(), ambil);
        if(password[indeks]==input_password){
            ditemukan = true;
        }
    }
    return ditemukan;
}

void User::regist() {
    string input_username, input_password;
    bool berhasil = false;
    do{
        cout << "=== Menu Registrasi ===" << endl;
        cout << "Username : ";
        cin >> input_username;

        if(input_username.substr(0,5) == "Admin"){
            cout << "\n!!!Tidak boleh mendaftar dengan awalan Admin!!!\n\n";
            char input;
            cout << "Tekan ENTER untuk mencoba username lain\n";
            cout << "Tekan tombol lain untuk kembali ke menu awal \n";
            cin.ignore();
            input = _getch();
            if(input!='\r'){
                break;
            }
            cout << "\033[2J\033[H";
            continue;
        }

        ifstream pengguna("ListPengguna.txt");
        string line;
        bool usedName = false;
        int lineNumber = 0;

        if(pengguna.is_open()){
            while(getline(pengguna, line)){
                lineNumber++;
                if(line.find(input_username) != string::npos && lineNumber%2 == 1){
                    usedName = true;
                    break;
                }
           }
           pengguna.close();
        }

        if(usedName){
            char input;
            cout << "\n!!!Username sudah digunakan!!!\n\n";
            cout << "Tekan ENTER untuk mencoba username lain\n";
            cout << "Tekan tombol lain untuk kembali ke menu awal \n";
            cin.ignore();
            input = _getch();
            if(input!='\r'){
                break;
            }
            cout << "\033[2J\033[H";
            continue;
        }

        cout << "Password : ";
        cin >> input_password;

        ofstream penggunaOut("ListPengguna.txt", ios::app);
        if(penggunaOut.is_open()){
            penggunaOut << "Username = " << input_username << "\n" << "Password = " << input_password << "\n\n\n";
            penggunaOut.close();
            berhasil = true;
            username.push_back(input_username);
            password.push_back(input_password);
            cout << "Registrasi berhasil! Silahkan menuju Menu Login... " << endl;
        }
    }while(!berhasil);
}

string User::login() {
    string input_username, input_password, tipe;
    bool ada = false;
    do{
        cout << "=== Menu Login ===" << endl;
        cout << "Username : ";
        cin >> input_username;
        cout << "Password : ";
        cin >> input_password;
        if(User::checkUser(input_username,input_password)){
            tipe = input_username;
            ada = true;
        }
        else{
            char input;
            cout << "\n!!!Username atau Password yang Anda masukkan salah!!!\n\n";
            cout << "Tekan ENTER untuk kembali ke menu login...\n";
            cout << "Tekan tombol lain untuk kembali ke menu awal \n";
            input = _getch();
            if(input!='\r'){
                tipe = "Adminout";
                break;
            }
            cout << "\033[2J\033[H";
        }
    }while(!ada);

    return tipe;
}