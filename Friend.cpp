#include "Friend.h"
#include <iostream>
using namespace std;

void PrintFriend(const Friend& f) {
    cout << f.gamertag << ": ";
    if (f.online_status == true) {
        cout << "Online" << endl;
    } else {
        cout << "Offline" << endl;
        cout << "Last seen: " << f.last_seen_online << endl;
    }
}