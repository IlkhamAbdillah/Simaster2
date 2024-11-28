#ifndef _MAHASISWA_H
#define _MAHASISWA_H

#include "User.h"

class Mahasiswa: public User {
public: 
    static void showUpcomingActivity();
    static void showHistory();
    static void sortActivity();
};

#endif //_MAHASISWA_H