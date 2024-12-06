#include "Mahasiswa.h"
#include "Activity.h"
#include "Administrator.h"
#include "Menu.h"
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

bool is_mahasiswa = true;
bool Menu::logout = false;
vector<Activity> Activity::adminActivity;
string tipe;

void Menu::generate(){
    User::getUser();
    ifstream daftarAktivitas("ListAktivitas.txt");
    string line;
    if (daftarAktivitas.is_open()){
        while (getline(daftarAktivitas, line)){
            stringstream ss(line);
            string isi_file;
            Activity baca_file;
            int currentIndex = 0;
            while (getline(ss, isi_file, ';')){ 
                if (currentIndex == 0) baca_file.judul = isi_file;
                else if (currentIndex == 1) baca_file.tanggal = isi_file;
                else if (currentIndex == 2) baca_file.waktu = isi_file;
                else if (currentIndex == 3) baca_file.prioritas = isi_file;
                else if (currentIndex == 4) baca_file.lokasi = isi_file;
                currentIndex++;
            }
            if (currentIndex == 5){ 
                Activity::activityList.push_back(baca_file);
            }
        }
        daftarAktivitas.close();
    }
    Activity::adminActivity = Activity::activityList;
}

void Menu::startMenu(){
    cout<<"\033[2J\033[H";
    logout = false;
    is_mahasiswa = true;
    char input;
    cout << "Selamat Datang di Aplikasi Simaster 2.0 \n\n";
    cout << "1. Register\n" << "2. Login\n\n" << "Tekan tombol lain untuk keluar ";
    input = _getch();
    if(input=='1'){
        cout<<"\033[2J\033[H";
        User::regist();
        startMenu();
    }
    else if(input=='2'){
        cout<<"\033[2J\033[H";
        tipe = User::login();
        if(tipe == "Adminout"){
            logout = true;
        }
        else if(tipe.substr(0,5) == "Admin"){
            is_mahasiswa = false;
        }
    }
    else{
        exit(0);
    }
}

void Menu::showMenu(){
    cout<<"\033[2J\033[H";
    cout << "Halo " << tipe << "\n";
    cout << "Aplikasi Simaster 2.0\n\n";
    char input;
    if(is_mahasiswa){
        Mahasiswa UGM;
        Activity::showActivityList(Activity::activityList);
        cout <<"\n";
        cout << "1. Melihat aktivitas yang akan datang\n";
        cout << "2. Melihat aktivitas yang sudah lewat\n";
        cout << "3. Sort aktivitas\n";
        cout << "4. Logout\n\n";
        cout << "Tekan tombol yang lain untuk keluar ";
        input = _getch();
        if(input=='1'){
            cout<<"\033[2J\033[H";
            UGM.showUpcomingActivity();
            cout << "\nTekan tombol apa saja untuk kembali";
            _getch();
        }
        else if (input=='2'){
            cout<<"\033[2J\033[H";
            UGM.showHistory();
            cout << "\nTekan tombol apa saja untuk kembali";
            _getch();
        }
        else if (input=='3'){
            cout<<"\033[2J\033[H";
            UGM.sortActivity();
        }
        else if (input=='4'){
            logout = true;
        }
        else{
            exit(0);
        }
    }
    else{
        Admin UGM;
        Activity::showActivityList(Activity::adminActivity);
        cout << "\n";
        cout << "1. Menambah aktivitas\n";
        cout << "2. Menghapus aktivitas\n";
        cout << "3. Logout\n\n";
        cout << "Tekan tombol yang lain untuk keluar ";
        input = _getch();
        if(input=='1'){
            cout<<"\033[2J\033[H";
            UGM.addActivity();
        }
        else if (input=='2'){
            cout<<"\033[2J\033[H";
            UGM.deleteActivity();
        }
        else if (input=='3'){
            logout = true;  
        }
        else{
            exit(0);
        }
    }
}