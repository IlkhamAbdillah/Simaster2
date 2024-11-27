#include "Mahasiswa.h"
#include "Menu.h"
#include "Activity.h"

void Mahasiswa::showUpcomingActivity(){
    std::cout << "=== Aktivitas Yang Akan Datang ===" << std::endl;
    for (size_t i = 0; i < Activity::upcomingActivity.size(); ++i){
        std::cout << i + 1 << ". " << Activity::upcomingActivity[i].judul;
        int q = Activity::upcomingActivity[i].judul.length();
        while(q < Activity::maks_judul){
            std::cout<<" ";
            q++;
        }
        std::cout << "\t" << "Tanggal: " << Activity::upcomingActivity[i].tanggal
                << "\t" << "Waktu: " << Activity::upcomingActivity[i].waktu
                << "\t" << "Prioritas: " << Activity::upcomingActivity[i].prioritas
                << "\t" << "Lokasi: " << Activity::upcomingActivity[i].lokasi << std::endl;
    }
}

void Mahasiswa::showHistory() {
    std::cout << "=== Riwayat Aktivitas ===" << std::endl;
    for (size_t i = 0; i < Activity::historyActivity.size(); ++i){
        std::cout << i + 1 << ". " << Activity::historyActivity[i].judul;
        int q = Activity::historyActivity[i].judul.length();
        while(q < Activity::maks_judul){
            std::cout<<" ";
            q++;
        }
        std::cout << "\t" << "Tanggal: " << Activity::historyActivity[i].tanggal
                    << "\t" << "Waktu: " << Activity::historyActivity[i].waktu
                    << "\t" << "Prioritas: " << Activity::historyActivity[i].prioritas
                    << "\t" << "Lokasi: " << Activity::historyActivity[i].lokasi << std::endl;
    }
}