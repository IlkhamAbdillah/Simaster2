#ifndef _ADMINISTRATOR_H
#define _ADMINISTRATOR_H

#include "User.h"
#include<bits/stdc++.h>

class Admin: public User {
public: 
    static void accessAdd();
    static void accessErase();
};

#endif //_ADMINISTRATOR_H