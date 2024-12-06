#include "Activity.h"
#include "Administrator.h"
#include <conio.h>
using namespace std;

bool isValidDate(const string& date){
    regex datePattern(R"(^\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])$)");
    if (regex_match(date, datePattern)){
        int year, month, day;
        char delimiter1, delimiter2;
        istringstream iss(date);
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

bool isValidTime(const string& time){
    regex timePattern(R"(^([01]\d|2[0-3]):([0-5]\d)$)");
    return regex_match(time, timePattern);
}

bool isValidPriority(string priority){
    if(priority == "Tinggi" || priority == "Sedang" || priority == "Rendah") return true;
    else return false;
}

void Admin::addActivity(){
    Activity adding;
    cout << "=== Menambah Aktivitas ===\n";
    cout << "Judul : ";
    getline(cin, adding.judul);
    cout << "Tanggal (YYYY-MM-DD): ";
    getline(cin, adding.tanggal);
    while(!isValidDate(adding.tanggal)){
        cout << "Tanggal tidak valid \n";
        cout << "Tanggal (YYYY-MM-DD): ";
        getline(cin, adding.tanggal);
    }
    cout << "Waktu (HH:MM): ";
    getline(cin, adding.waktu);
    while(!isValidTime(adding.waktu)){
        cout << "Waktu tidak valid \n";
        cout << "Waktu (HH:MM): ";
        getline(cin, adding.waktu);
    }
    cout << "Prioritas (Tinggi/Sedang/Rendah): ";
    getline(cin, adding.prioritas);
    while(!isValidPriority(adding.prioritas)){
        cout << "Prioritas tidak valid \n";
        cout << "Prioritas (Tinggi/Sedang/Rendah): ";
        getline(cin, adding.prioritas);
    }
    cout << "Lokasi : ";
    getline(cin, adding.lokasi);
    string delimiter = ";";
    Activity::adminActivity.push_back(adding);
    string gabung = adding.judul + delimiter + adding.tanggal + delimiter + adding.waktu + delimiter + adding.prioritas + delimiter + adding.lokasi;
    ofstream aktif("ListAktivitas.txt", ios::app);
    if (aktif.is_open()){
        aktif << gabung + "\n";
        aktif.close();
    }
    Activity::activityList = Activity::adminActivity;
}

void Admin::deleteActivity(){
    bool sesuai = true;
    int input;
    Activity::showActivityList(Activity::adminActivity);
    cout << "\nMemilih yang diluar daftar akan kembali ke menu utama\n";
    cout << "Pilih aktivitas untuk dihapus : ";
    cin >> input;
    if (cin.fail() || input < 1 || input > Activity::adminActivity.size()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        sesuai = false;
    }
    if(sesuai){
        Activity::adminActivity.erase(Activity::adminActivity.begin() + input-1);
        ofstream outputFile("ListAktivitas.txt", ios::trunc);
        if (outputFile.is_open()){
            for (int i=0; i<Activity::adminActivity.size(); i++){
                outputFile << Activity::adminActivity[i].judul << ";"
                        << Activity::adminActivity[i].tanggal << ";"
                        << Activity::adminActivity[i].waktu << ";"
                        << Activity::adminActivity[i].prioritas << ";"
                        << Activity::adminActivity[i].lokasi << "\n";
            }
            outputFile.close();
        }
        Activity::activityList = Activity::adminActivity;
        cout << "\n";
        cout << "Aktivitas " << input << " berhasil dihapus\n";
        cout << "Tekan tombol apa saja untuk kembali";
        _getch();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}