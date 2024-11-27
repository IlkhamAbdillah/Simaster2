#ifndef _USER_H
#define _USER_H

#include<bits/stdc++.h>

class User {
public: 
    static bool regist();
    static std::string login();
    static bool cekPengguna(const std::string&, const std::string&);

private: 
    std::string username;
    std::string password;
};

#endif //_USER_H