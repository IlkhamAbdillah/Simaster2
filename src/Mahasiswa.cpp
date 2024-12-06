#include "Mahasiswa.h"
#include "Activity.h"
#include <conio.h>
using namespace std;

void Mahasiswa::showUpcomingActivity(){
    cout << "=== Aktivitas Yang Akan Datang ===" << endl;
    for (size_t i = 0; i < Activity::upcomingActivity.size(); ++i){
        cout << i + 1 << ". " << Activity::upcomingActivity[i].judul;
        int tambah = Activity::upcomingActivity[i].judul.length();
        while(tambah < Activity::maks_judul){
            cout<<" ";
            tambah++;
        }
        cout << "\t" << "Tanggal: " << Activity::upcomingActivity[i].tanggal
                << "\t" << "Waktu: " << Activity::upcomingActivity[i].waktu
                << "\t" << "Prioritas: " << Activity::upcomingActivity[i].prioritas
                << "\t" << "Lokasi: " << Activity::upcomingActivity[i].lokasi << endl;
    }
}

void Mahasiswa::showHistory(){
    cout << "=== Riwayat Aktivitas ===" << endl;
    for (size_t i = 0; i < Activity::historyActivity.size(); ++i){
        cout << i + 1 << ". " << Activity::historyActivity[i].judul;
        int tambah = Activity::historyActivity[i].judul.length();
        while(tambah < Activity::maks_judul){
            cout<<" ";
            tambah++;
        }
        cout << "\t" << "Tanggal: " << Activity::historyActivity[i].tanggal
                    << "\t" << "Waktu: " << Activity::historyActivity[i].waktu
                    << "\t" << "Prioritas: " << Activity::historyActivity[i].prioritas
                    << "\t" << "Lokasi: " << Activity::historyActivity[i].lokasi << endl;
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
    string datetimeA = a.tanggal + " " + a.waktu;
    string datetimeB = b.tanggal + " " + b.waktu;

    if (datetimeA != datetimeB){
        return datetimeA < datetimeB;
    }
    return comparepriority(a, b);
}

void Mahasiswa::sortActivity(){
    char input;
    cout << "=== Urutkan Aktivitas ===\n\n";
    cout << "1. Berdasarkan waktu\n" << "2. Berdasarkan prioritas\n\n";
    cout << "Tekan tombol yang lain untuk kembali";
    input = _getch();
    if(input=='1'){
        sort(Activity::activityList.begin(), Activity::activityList.end(), comparetime);
    }
    else if(input=='2'){
        sort(Activity::activityList.begin(), Activity::activityList.end(), comparepriority);
    }
}