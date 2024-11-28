#include "Mahasiswa.h"
#include "Menu.h"
#include "Activity.h"
#include <conio.h>

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

void Mahasiswa::showHistory(){
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

int prioritasToInt(const Activity a){
        if (a.prioritas == "Tinggi") return 3;
        if (a.prioritas == "Sedang") return 2;
        return 1;
    }

bool comparepriority(const Activity a, const Activity b){
    return prioritasToInt(a) > prioritasToInt(b);
}

bool comparetime(const Activity a, const Activity b){
    std::string datetimeA = a.tanggal + " " + a.waktu;
    std::string datetimeB = b.tanggal + " " + b.waktu;

    if (datetimeA != datetimeB) {
        return datetimeA < datetimeB;
    }
    return comparepriority(a, b);
}

void Mahasiswa::sortActivity(){
    std::vector<Activity> sortedActivity = Activity::activityList;
    char p;
    std::cout << "=== Urutkan Aktivitas ===\n" << std::endl;
    std::cout << "1. Berdasarkan waktu\n" << "2. Berdasaarkan prioritas\n\n";
    std::cout << "\nTekan tombol yang lain untuk kembali";
    p = _getch();
    if(p=='1'){
        std::sort(sortedActivity.begin(), sortedActivity.end(), comparetime);
    }
    else if(p=='2'){
        std::sort(sortedActivity.begin(), sortedActivity.end(), comparepriority);
    }
    std::cout<<"\033[2J\033[H";
    Activity::showActivityList(sortedActivity);
    std::cout << "\nTekan tombol apa saja untuk kembali";
    _getch();
}