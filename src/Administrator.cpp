#include "Activity.h"
#include "Menu.h"
#include "Administrator.h"

bool isValidDate(const std::string& date) {
    std::regex datePattern(R"(^\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])$)");
    if (std::regex_match(date, datePattern)) {
        int year, month, day;
        char delimiter1, delimiter2;
        std::istringstream iss(date);
        iss >> year >> delimiter1 >> month >> delimiter2 >> day;
        if (delimiter1 == '-' && delimiter2 == '-') {
            int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                daysInMonth[1] = 29;
            }
            return day > 0 && day <= daysInMonth[month - 1];
        }
    }
    return false;
}

bool isValidTime(const std::string& time) {
    std::regex timePattern(R"(^([01]\d|2[0-3]):([0-5]\d)$)");
    return std::regex_match(time, timePattern);
}

bool isValidPriority(std::string priority){
    if(priority == "Tinggi" || priority == "Sedang" || priority == "Rendah") return true;
    else return false;
}

void Admin::addActivity() {
    Activity adding;
    char x;
    std::cin.ignore();
    std::cout << "Judul : ";
    std::getline(std::cin, adding.judul);
    std::cout << "Tanggal (YYYY-MM-DD): ";
    std::getline(std::cin, adding.tanggal);
    while(!isValidDate(adding.tanggal)){
        std::cout << "Tanggal tidak valid \n";
        std::cout << "Tanggal (YYYY-MM-DD): ";
        std::getline(std::cin, adding.tanggal);
    }
    std::cout << "Waktu (HH:MM): ";
    std::getline(std::cin, adding.waktu);
    while(!isValidTime(adding.waktu)){
        std::cout << "Waktu tidak valid \n";
        std::cout << "Waktu (HH:MM): ";
        std::getline(std::cin, adding.waktu);
    }
    std::cout << "Prioritas (Tinggi/Sedang/Rendah): ";
    std::getline(std::cin, adding.prioritas);
    while(!isValidPriority(adding.prioritas)){
        std::cout << "Prioritas tidak valid \n";
        std::cout << "Prioritas (Tinggi/Sedang/Rendah): ";
        std::getline(std::cin, adding.prioritas);
    }
    std::cout << "Lokasi : ";
    std::getline(std::cin, adding.lokasi);
    std::string l = ";";
    Activity::activityList.push_back(adding);
    std::string gabung = adding.judul + l + adding.tanggal + l + adding.waktu + l + adding.prioritas + l + adding.lokasi;
    std::ofstream aktif("ListAktivitas.txt", std::ios::app);
    if (aktif.is_open()) {
        aktif << gabung + "\n";
        aktif.close();
    }
}

void Admin::deleteActivity() {
    bool sesuai = true;
    int a;
    Activity::showActivityList(Activity::activityList);
    std::cout << "\nMemilih yang diluar daftar akan kembali ke menu utama\n";
    std::cout << "Pilih aktivitas untuk dihapus : ";
    std::cin >> a;
    if (std::cin.fail() || a > Activity::activityList.size()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Membersihkan buffer
        sesuai = false;
    }
    if(sesuai){
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
                    else if (currentIndex == 4) activity.lokasi = isi;
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
                        << activity.lokasi << "\n";
            }
            outputFile.close();
        }
        Activity::activityList.erase(Activity::activityList.begin() + a - 1);
        std::cout << "Aktivitas " << a << " berhasil dihapus" << std::endl;
    }
}