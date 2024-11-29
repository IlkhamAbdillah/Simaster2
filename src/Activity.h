#ifndef _ACTIVITY_H
#define _ACTIVITY_H
#include "Mahasiswa.h"
#include <bits/stdc++.h>
using namespace std;

class Activity {
public:
    static int maks_judul; //agar tampilan terlihat rapi
    string judul;
    string tanggal;
    string waktu;
    string prioritas;
    string lokasi;
    static vector<Activity> activityList;
    static vector<Activity> adminActivity;

    static void showActivityList(const vector<Activity>);

private:
    static vector<Activity> historyActivity;
    static vector<Activity> upcomingActivity;
    friend class Mahasiswa;
};

#endif //_ACTIVITY_H
