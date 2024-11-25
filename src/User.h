#ifndef _USER_H
#define _USER_H

#include<bits/stdc++.h>

class User {
public: 
    static void regist();
    static std::string login();
    static bool cekPengguna(const std::string&, const std::string&);

private: 
    std::string userID;
    std::string username;
    std::string password;
};

#endif //_USER_H