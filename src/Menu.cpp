#include "Mahasiswa.h"
#include "Activity.h"
#include "Administrator.h"
#include "Menu.h"
#include <bits/stdc++.h>

bool mahasigma = true;
bool Menu::logout = false;
std::string tipe;

void Menu::generateActivity(){
    std::ifstream daftarAktivitas("ListAktivitas.txt");
    std::string line;
    if (daftarAktivitas.is_open()){
        while (std::getline(daftarAktivitas, line)){
            std::stringstream ss(line);
            std::string isi;
            Activity baca;
            int currentIndex = 0;
            while (std::getline(ss, isi, ';')){ 
                if (currentIndex == 0) baca.judul = isi;
                else if (currentIndex == 1) baca.tanggal = isi;
                else if (currentIndex == 2) baca.waktu = isi;
                else if (currentIndex == 3) baca.prioritas = isi;
                else if (currentIndex == 4) baca.lokasi = isi;
                currentIndex++;
            }
            if (currentIndex == 5){ 
                Activity::activityList.push_back(baca);
            }
        }
        daftarAktivitas.close();
    }
}

void Menu::startMenu(){
    std::cout<<"\033[2J\033[H";
    logout = false;
    mahasigma = true;
    int p;
    std::cout << "Semalat Datang di Aplikasi Simaster 2.0" << std::endl;
    std::cout << "1. Register" << std::endl << "2. Login" << std::endl << "3. Exit" << std::endl;
    std::cout << "Masukkan pilihan Anda : ";
    std::cin >> p;
    if(p==1){
        std::cout<<"\033[2J\033[H";
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
        std::cout<<"\033[2J\033[H";
        tipe = User::login();
        if(tipe.substr(0,5) == "Admin"){
            mahasigma = false;
        }
    }
}

void Menu::showMenu(){
    std::cout<<"\033[2J\033[H";
    std::cout << "Halo " << tipe << std::endl;
    std::cout << "Aplikasi Simaster 2.0" << std::endl;
    if(mahasigma){
        Mahasiswa UGM;
        int p;
        char q;
        Activity::showActivityList();
        std::cout << std::endl;
        std::cout << "1. Melihat aktivitas yang akan datang" << std::endl;
        std::cout << "2. Melihat aktivitas yang sudah lewat" << std::endl;
        std::cout << "3. Menandai aktivitas" << std::endl;
        std::cout << "4. Logout" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Masukkan pilihan Anda : ";
        std::cin >> p;
        if(p==1){
            std::cout<<"\033[2J\033[H";
            UGM.showUpcomingActivity();
            std::cout << "Press any key untuk keluar";
            std::cin >> q;
        }
        else if (p==2){
            std::cout<<"\033[2J\033[H";
            UGM.showHistory();
            std::cout << "Press any key untuk keluar";
            std::cin >>q;
        }
        else if (p==3){
            std::cout<<"\033[2J\033[H";
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
        std::cout << std::endl;
        std::cout << "1. Menambah aktivitas" << std::endl;
        std::cout << "2. Menghapus aktivitas" << std::endl;
        std::cout << "3. Logout" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Masukkan pilihan Anda : ";
        std::cin >> p;
        if(p==1){
            std::cout<<"\033[2J\033[H";
            Admin::addActivity();
        }
        else if (p==2){
            std::cout<<"\033[2J\033[H";
            Admin::deleteActivity();
        }
        else if (p==4){
            exit(0);
        }
        else{
            logout = true;
        }
    }
}