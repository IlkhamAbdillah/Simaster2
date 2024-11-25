#include "Activity.h"
#include "ManageActivity.h"
#include "Mahasiswa.h"
#include "User.h"
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
        cout << "3. Menandai aktivitas yang sudah lewat" << endl;
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
            Admin::accessErase();
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
    //baca file dulu
    while(true){
        startMenu();
        while(!logout){
            showMenu();
        }
    }
    // Activity newActivity;
    // newActivity.judul = "Belajar Pemrograman";
    // newActivity.tanggal = "2024-11-23";
    // newActivity.waktu = "14:00";
    // newActivity.prioritas = "Tinggi";
    // newActivity.status = "Belum selesai";

    // Activity newActivity2;
    // newActivity2.judul = "Belajar KVT";
    // newActivity2.tanggal = "2024-11-24";
    // newActivity2.waktu = "14:00";
    // newActivity2.prioritas = "Tinggi";
    // newActivity2.status = "Belum selesai";

    // Activity::activityList.push_back(newActivity);
    // Activity::activityList.push_back(newActivity2);

    // while(true){
    //     cout<<"\033[2J\033[H";
    //     Activity::showActivityList();
    //     Activity::showUpcomingActivity();
    //     Activity::showHistory();
    //     Activity::markActivity();
    //     Admin::accessAdd();
    //     Admin::accessErase();
    // }

    return 0;
}