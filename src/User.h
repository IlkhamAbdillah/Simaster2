#ifndef _USER_H
#define _USER_H

#include<bits/stdc++.h>

class User {
public: 
    static void regist();
    static std::string login();
    static void getUser();
    static bool cekPengguna(const std::string, const std::string);

private: 
    static std::vector<std::string> username;
    static std::vector<std::string> password;
};

#endif //_USER_H