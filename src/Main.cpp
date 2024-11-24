#include "Activity.h"
#include "ManageActivity.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
    Activity newActivity;
    newActivity.judul = "Belajar Pemrograman";
    newActivity.tanggal = "2024-11-23";
    newActivity.waktu = "14:00";
    newActivity.prioritas = "Tinggi";
    newActivity.status = "Belum selesai";

    Activity newActivity2;
    newActivity2.judul = "Belajar KVT";
    newActivity2.tanggal = "2024-11-24";
    newActivity2.waktu = "14:00";
    newActivity2.prioritas = "Tinggi";
    newActivity2.status = "Belum selesai";

    Activity::activityList.push_back(newActivity);
    Activity::activityList.push_back(newActivity2);

    while(true){
        cout<<"\033[2J\033[H";
        Activity::showActivityList();
        Activity::showUpcomingActivity();
        Activity::showHistory();
        Activity::markActivity();
        Admin::accessAdd();
        Admin::accessErase();
    }

    return 0;
}