#include "Activity.h"
#include<bits/stdc++.h>

std::vector<Activity> Activity::activityList;
std::vector<Activity> Activity::historyActivity;
std::vector<Activity> Activity::upcomingActivity;
int Activity::maks_judul = 0;
std::time_t waktu_sekarang;

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

bool compareTime(std::string tanggal, std::string waktu, std::time_t x){
    std::time_t waktu_aktivitas = toTime(tanggal, waktu);
    return waktu_aktivitas < x;
}

void Activity::showActivityList(const std::vector<Activity> a){
    upcomingActivity.clear();
    historyActivity.clear();
    std::time_t y = setTime();
    int p = 0;
    for (size_t i = 0; i < a.size(); ++i){
        p = a[i].judul.length();
        if(p > maks_judul){
            maks_judul = p;
        }
    }
    std::cout << "=== Daftar Aktivitas ===" << std::endl;
    for (size_t i = 0; i < a.size(); ++i){
        std::cout << i + 1 << ". " << a[i].judul;
        int q = a[i].judul.length();
        while(q < maks_judul){
            std::cout<<" ";
            q++;
        }
        std::cout << "\t" << "Tanggal: " << a[i].tanggal
                  << "\t" << "Waktu: " << a[i].waktu
                  << "\t" << "Prioritas: " << a[i].prioritas
                  << "\t" << "Lokasi: " << a[i].lokasi << std::endl;
        if(!compareTime(a[i].tanggal, a[i].waktu, y)){
            upcomingActivity.push_back(a[i]);
        }
        else{
            historyActivity.push_back(a[i]);
        }
    }
}