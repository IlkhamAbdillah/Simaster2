#ifndef _ACTIVITY_H
#define _ACTIVITY_H

#include<bits/stdc++.h>

class Activity {
public:
    std::string judul;
    std::string tanggal;
    std::string waktu;
    std::string prioritas;
    std::string status;

    static std::vector<Activity> activityList;
    static std::vector<Activity> historyActivity;
    static std::vector<Activity> upcomingActivity;

    static void showActivityList();
    static void showUpcomingActivity();
    static void markActivity();
    static void showHistory();
};

#endif //_ACTIVITY_H
