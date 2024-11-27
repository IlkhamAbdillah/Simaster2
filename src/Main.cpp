#include "ManageActivity.h"
#include "Mahasiswa.h"
#include <bits/stdc++.h>
using namespace std;

bool mahasigma = true;
bool logout = false;
string tipe;

void startMenu(){
    cout<<"\033[2J\033[H";
    logout = false;
    mahasigma = true;
    int p;
    cout << "Semalat Datang di Aplikasi Simaster 2.0" << endl;
    cout << "1. Register" << endl << "2. Login" << endl << "3. Exit" << endl;
    cout << "Masukkan pilihan Anda : ";
    cin >> p;
    if(p==1){
        cout<<"\033[2J\033[H";
        User::regist();
        std::cout << "Tekan ENTER untuk kembali ke menu awal \n";
        std::cin.ignore();
        std::cin.get();
        startMenu();
    }
    else if(p==3){
        exit(0);
    }
    else{
        cout<<"\033[2J\033[H";
        tipe = User::login();
        if(tipe.substr(0,5) == "Admin"){
            mahasigma = false;
        }
    }
}

void showMenu(){
    cout<<"\033[2J\033[H";
    cout << "Halo " << tipe << endl;
    cout << "Aplikasi Simaster 2.0" << endl;
    if(mahasigma){
        int p;
        char q;
        Activity::showActivityList();
        cout << endl;
        cout << "1. Melihat aktivitas yang akan datang" << endl;
        cout << "2. Melihat aktivitas yang sudah lewat" << endl;
        cout << "3. Menandai aktivitas" << endl;
        cout << "4. Logout" << endl;
        cout << "5. Exit" <<endl;
        cout << "Masukkan pilihan Anda : ";
        cin >> p;
        if(p==1){
            cout<<"\033[2J\033[H";
            Activity::showUpcomingActivity();
            cout << "Press any key untuk keluar";
            cin >> q;
        }
        else if (p==2){
            cout<<"\033[2J\033[H";
            Activity::showHistory();
            cout << "Press any key untuk keluar";
            cin >>q;
        }
        else if (p==3){
            cout<<"\033[2J\033[H";
            Mahasiswa::markActivity();
        }
        else if (p==5){
            exit(0);
        }
        else{
            logout = true;
        }
    }
    else{
        int p;
        char q;
        Activity::showActivityList();
        cout << endl;
        cout << "1. Menambah aktivitas" << endl;
        cout << "2. Menghapus aktivitas" << endl;
        cout << "3. Logout" << endl;
        cout << "4. Exit" << endl;
        cout << "Masukkan pilihan Anda : ";
        cin >> p;
        if(p==1){
            cout<<"\033[2J\033[H";
            Admin::accessAdd();
        }
        else if (p==2){
            cout<<"\033[2J\033[H";
            Admin::accessDelete();
        }
        else if (p==4){
            exit(0);
        }
        else{
            logout = true;
        }
    }
}

int main() {
    Activity::generateActivity();
    while(true){
        startMenu();
        while(!logout){
            showMenu();
        }
    }
}