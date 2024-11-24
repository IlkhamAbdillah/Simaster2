#include "Activity.h"
#include "ManageActivity.h"
#include "Administrator.h"

void manageActivity::addActivity() {
    Activity adding;
    char x;
    std::cout << "Judul : ";
    std::cin >> adding.judul;
    std::cout << "Tanggal (YYYY-MM-DD): ";
    std::cin >> adding.tanggal;
    std::cout << "Waktu (HH:MM): ";
    std::cin >> adding.waktu;
    std::cout << "Prioritas (Tinggi/Sedang/Rendah): ";
    std::cin >> adding.prioritas;
    adding.status = "Belum selesai";
    Activity::activityList.push_back(adding);
}

void manageActivity::eraseActivity() {
    int a;
    Activity::showActivityList();
    std::cout << "Pilih aktivitas untuk dihapus : ";
    std::cin >> a;
    Activity::activityList.erase(Activity::activityList.begin() + a - 1);
    std::cout << "Aktivitas " << a << " berhasil dihapus" << std::endl;
}