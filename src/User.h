#ifndef _USER_H
#define _USER_H

#include<bits/stdc++.h>
using namespace std;

class User {
public: 
    static void regist();
    static string login();
    static void getUser();
    static bool checkUser(const string, const string);

private: 
    static vector<string> username;
    static vector<string> password;
};

#endif //_USER_H