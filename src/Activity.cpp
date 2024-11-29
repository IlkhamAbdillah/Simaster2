#include "Activity.h"
#include <bits/stdc++.h>
using namespace std;

vector<Activity> Activity::activityList;
vector<Activity> Activity::historyActivity;
vector<Activity> Activity::upcomingActivity;
int Activity::maks_judul = 0;
time_t waktu_sekarang;

time_t setTime(){
    auto x = chrono::system_clock::now();
    time_t xy = chrono::system_clock::to_time_t(x);
    return xy;
}

time_t toTime(string tanggal, string waktu){
    tm to_waktu = {};
    string gabung = tanggal + " " + waktu;
    istringstream ss(gabung);
    ss >> get_time(&to_waktu, "%Y-%m-%d %H:%M:%S");
    time_t menjadi_waktu = mktime(&to_waktu);
    return menjadi_waktu;
}

bool compareTime(string tanggal, string waktu, time_t banding_waktu){
    time_t waktu_aktivitas = toTime(tanggal, waktu);
    return waktu_aktivitas < banding_waktu;
}

void Activity::showActivityList(const vector<Activity> aktivitas){
    upcomingActivity.clear();
    historyActivity.clear();
    time_t banding_waktu = setTime();
    int panjang_judul = 0;
    for (size_t i = 0; i < aktivitas.size(); ++i){
        panjang_judul = aktivitas[i].judul.length();
        if(panjang_judul > maks_judul){
            maks_judul = panjang_judul;
        }
    }
    cout << "=== Daftar Aktivitas ===" << endl;
    for (size_t i = 0; i < aktivitas.size(); ++i){
        cout << i + 1 << ". " << aktivitas[i].judul;
        int tambah = aktivitas[i].judul.length();
        while(tambah < maks_judul){
            cout<<" ";
            tambah++;
        }
        cout << "\t" << "Tanggal: " << aktivitas[i].tanggal
                  << "\t" << "Waktu: " << aktivitas[i].waktu
                  << "\t" << "Prioritas: " << aktivitas[i].prioritas
                  << "\t" << "Lokasi: " << aktivitas[i].lokasi << endl;
        if(!compareTime(aktivitas[i].tanggal, aktivitas[i].waktu, banding_waktu)){
            upcomingActivity.push_back(aktivitas[i]);
        }
        else{
            historyActivity.push_back(aktivitas[i]);
        }
    }
}