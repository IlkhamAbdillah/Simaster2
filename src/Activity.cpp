#include "Activity.h"
#include<bits/stdc++.h>

std::vector<Activity> Activity::activityList;
std::vector<Activity> Activity::historyActivity;
std::vector<Activity> Activity::upcomingActivity;
std::time_t waktu_sekarang;
int maks_judul = 0;

std::time_t setTime(){
    auto x = std::chrono::system_clock::now();
    std::time_t xy = std::chrono::system_clock::to_time_t(x);
    return xy;
}

std::time_t toTime(std::string tanggal, std::string waktu){
    std::tm jikan = {};
    std::string gabung = tanggal + " " + waktu;
    std::istringstream ss(gabung);
    ss >> std::get_time(&jikan, "%Y-%m-%d %H:%M:%S");
    std::time_t menjadi = std::mktime(&jikan);
    return menjadi;
}

bool compareTime(std::string tanggal, std::string waktu, std::time_t x) {
    std::time_t waktu_aktivitas = toTime(tanggal, waktu);
    return waktu_aktivitas < x;
}

void Activity::showActivityList() {
    upcomingActivity.clear();
    historyActivity.clear();
    std::time_t y = setTime();
    int p = 0;
    for (size_t i = 0; i < Activity::activityList.size(); ++i) {
        p = Activity::activityList[i].judul.length();
        if(p > maks_judul){
            maks_judul = p;
        }
    }
    std::cout << "=== Daftar Aktivitas ===" << std::endl;
    for (size_t i = 0; i < activityList.size(); ++i) {
        std::cout << i + 1 << ". Judul: " << activityList[i].judul;
        int q = activityList[i].judul.length();
        while(q < maks_judul){
            std::cout<<" ";
            q++;
        }
        std::cout << "\t" << "Tanggal: " << activityList[i].tanggal
                  << "\t" << "Waktu: " << activityList[i].waktu
                  << "\t" << "Prioritas: " << activityList[i].prioritas
                  << "\t" << "Status: " << activityList[i].status << std::endl;
        if(!compareTime(activityList[i].tanggal, activityList[i].waktu, y) || activityList[i].status != "Selesai"){
            upcomingActivity.push_back(activityList[i]);
        }
        else{
            historyActivity.push_back(activityList[i]);
        }
    }
}

void Activity::showUpcomingActivity(){
    std::cout << "=== Aktivitas Yang Akan Datang ===" << std::endl;
    for (size_t i = 0; i < upcomingActivity.size(); ++i) {
        std::cout << i + 1 << ". Judul: " << upcomingActivity[i].judul;
        int q = upcomingActivity[i].judul.length();
        while(q < maks_judul){
            std::cout<<" ";
            q++;
        }
        std::cout << "\t" << "Tanggal: " << upcomingActivity[i].tanggal
                << "\t" << "Waktu: " << upcomingActivity[i].waktu
                << "\t" << "Prioritas: " << upcomingActivity[i].prioritas
                << "\t" << "Status: " << upcomingActivity[i].status << std::endl;
    }
}

void Activity::markActivity() {
    if(activityList.empty()){
        std::cout << "Tidak ada aktivitas";
        exit(0);
    }
    else{
        int x;
        char y;
        Activity::showActivityList();
        std::cout << "Pilih nomor aktivitas untuk ditandai : ";
        std::cin >> x;
        if(activityList[x-1].status != "Selesai"){
            std::cout << "Tandai sebagai selesai? (y/n) : ";
            std::cin >> y;
            if(y=='y'){
                activityList[x-1].status = "Selesai";
                std::cout<<"Aktivitas " << x << " berhasil diselesaikan" << std::endl;
            }
        }
    }
}

void Activity::showHistory() {
    std::cout << "=== Riwayat Aktivitas ===" << std::endl;
    for (size_t i = 0; i < historyActivity.size(); ++i) {
        std::cout << i + 1 << ". Judul: " << historyActivity[i].judul;
        int q = historyActivity[i].judul.length();
        while(q < maks_judul){
            std::cout<<" ";
            q++;
        }
        std::cout << "\t" << "Tanggal: " << historyActivity[i].tanggal
                    << "\t" << "Waktu: " << historyActivity[i].waktu
                    << "\t" << "Prioritas: " << historyActivity[i].prioritas
                    << "\t" << "Status: " << historyActivity[i].status << std::endl;
    }
}
