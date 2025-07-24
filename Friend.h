#ifndef FRIEND_H
#define FRIEND_H

#include <string>
#include <iostream>
using namespace std;

struct Friend { // Struct to represent a friend in the Xbox Live account
    string gamertag;
    bool online_status;
    string last_seen_online;
};
void PrintFriend(const Friend& f);// Function to print the details of a friend
#endif /* FRIEND_H */