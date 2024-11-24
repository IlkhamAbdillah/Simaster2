#ifndef _MANAGEACTIVITY_H
#define _MANAGEACTIVITY_H

#include "Activity.h"
#include "Administrator.h"
#include<bits/stdc++.h>

class manageActivity {
private: 
    static void addActivity();
    static void eraseActivity();
    friend class Admin;
};

#endif //_MANAGE ACTIVITY_H