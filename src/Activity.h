#ifndef _ACTIVITY_H
#define _ACTIVITY_H
#include "Mahasiswa.h"
#include<bits/stdc++.h>

class Activity {
public:
    static int maks_judul; //agar tampilan terlihat rapi
    std::string judul;
    std::string tanggal;
    std::string waktu;
    std::string prioritas;
    std::string lokasi;
    static std::vector<Activity> activityList;

    static void showActivityList();

private:
    static std::vector<Activity> historyActivity;
    static std::vector<Activity> upcomingActivity;
    friend class Mahasiswa;
};

#endif //_ACTIVITY_H
