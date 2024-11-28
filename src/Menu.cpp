#include "Mahasiswa.h"
#include "Activity.h"
#include "Administrator.h"
#include "Menu.h"
#include <bits/stdc++.h>
#include <conio.h>

bool mahasigma = true;
bool Menu::logout = false;
std::string tipe;

void Menu::generate(){
    User::getUser();
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
    char p;
    std::cout << "Semalat Datang di Aplikasi Simaster 2.0 \n\n";
    std::cout << "1. Register" << std::endl << "2. Login \n" << std::endl << "Tekan tombol lain untuk keluar ";
    p = _getch();
    if(p=='1'){
        std::cout<<"\033[2J\033[H";
        User::regist();
        startMenu();
    }
    else if(p=='2'){
        std::cout<<"\033[2J\033[H";
        tipe = User::login();
        if(tipe == "Adminout"){
            logout = true;
        }
        else if(tipe.substr(0,5) == "Admin"){
            mahasigma = false;
        }
    }
    else{
        exit(0);
    }
}

void Menu::showMenu(){
    std::cout<<"\033[2J\033[H";
    std::cout << "Halo " << tipe << std::endl;
    std::cout << "Aplikasi Simaster 2.0" << std::endl;
    if(mahasigma){
        Mahasiswa UGM;
        char p;
        Activity::showActivityList(Activity::activityList);
        std::cout << std::endl;
        std::cout << "1. Melihat aktivitas yang akan datang" << std::endl;
        std::cout << "2. Melihat aktivitas yang sudah lewat" << std::endl;
        std::cout << "3. Sort aktivitas" << std::endl;
        std::cout << "4. Logout\n" << std::endl;
        std::cout << "Tekan tombol yang lain untuk keluar ";
        p = _getch();
        if(p=='1'){
            std::cout<<"\033[2J\033[H";
            UGM.showUpcomingActivity();
            std::cout << "\nTekan tombol apa saja untuk kembali";
            _getch();
        }
        else if (p=='2'){
            std::cout<<"\033[2J\033[H";
            UGM.showHistory();
            std::cout << "\nTekan tombol apa saja untuk kembali";
            _getch();
        }
        else if (p=='3'){
            std::cout<<"\033[2J\033[H";
            UGM.sortActivity();
        }
        else if (p=='4'){
            logout = true;
        }
        else{
            exit(0);
        }
    }
    else{
        Admin UGM;
        char p;
        Activity::showActivityList(Activity::activityList);
        std::cout << std::endl;
        std::cout << "1. Menambah aktivitas" << std::endl;
        std::cout << "2. Menghapus aktivitas" << std::endl;
        std::cout << "3. Logout\n" << std::endl;
        std::cout << "Tekan tombol yang lain untuk keluar ";
        p = _getch();
        if(p=='1'){
            std::cout<<"\033[2J\033[H";
            UGM.addActivity();
        }
        else if (p=='2'){
            std::cout<<"\033[2J\033[H";
            UGM.deleteActivity();
        }
        else if (p=='3'){
            logout = true;  
        }
        else{
            exit(0);
        }
    }
}