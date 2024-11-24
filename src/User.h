#ifndef _USER_H
#define _USER_H

#include<bits/stdc++.h>

class User {
public: 
    
void regist();
    
void login();
private: 
    std::string userID;
    std::string username;
    std::string password;
};

#endif //_USER_H