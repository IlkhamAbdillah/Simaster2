#include "Activity.h"
#include "ManageActivity.h"
#include "Administrator.h"

void manageActivity::addActivity() {
    Activity adding;
    char x;
    std::cin.ignore();
    std::cout << "Judul : ";
    std::getline(std::cin, adding.judul);
    std::cout << "Tanggal (YYYY-MM-DD): ";
    std::getline(std::cin, adding.tanggal);
    std::cout << "Waktu (HH:MM): ";
    std::getline(std::cin, adding.waktu);
    std::cout << "Prioritas (Tinggi/Sedang/Rendah): ";
    std::getline(std::cin, adding.prioritas);
    adding.status = "Belum selesai";
    std::string l = ";";
    Activity::activityList.push_back(adding);
    std::string gabung = adding.judul + l + adding.tanggal + l + adding.waktu + l + adding.prioritas + l + adding.status;
    std::ofstream aktif("ListAktivitas.txt", std::ios::app);
    if (aktif.is_open()) {
        aktif << gabung + "\n";
        aktif.close();
    }
}

void manageActivity::deleteActivity() {
    int a;
    Activity::showActivityList();
    std::cout << "Pilih aktivitas untuk dihapus : ";
    std::cin >> a;
    std::string targetJudul = Activity::activityList[a-1].judul;
    std::ifstream inputFile("ListAktivitas.txt");
    std::vector<Activity> activities;
    std::string line;
    if (inputFile.is_open()) {
        while (std::getline(inputFile, line)) {
            std::stringstream ss(line);
            std::string isi;
            Activity activity;
            int currentIndex = 0;

            while (std::getline(ss, isi, ';')) {
                if (currentIndex == 0) activity.judul = isi;
                else if (currentIndex == 1) activity.tanggal = isi;
                else if (currentIndex == 2) activity.waktu = isi;
                else if (currentIndex == 3) activity.prioritas = isi;
                else if (currentIndex == 4) activity.status = isi;
                currentIndex++;
            }

            if (currentIndex == 5 && activity.judul != targetJudul) {
                activities.push_back(activity);
            }
        }
        inputFile.close();
    }
    std::ofstream outputFile("ListAktivitas.txt", std::ios::trunc);
    if (outputFile.is_open()) {
        for (const auto& activity : activities) {
            outputFile << activity.judul << ";"
                       << activity.tanggal << ";"
                       << activity.waktu << ";"
                       << activity.prioritas << ";"
                       << activity.status << "\n";
        }
        outputFile.close();
    }
    Activity::activityList.erase(Activity::activityList.begin() + a - 1);
    std::cout << "Aktivitas " << a << " berhasil dihapus" << std::endl;
}