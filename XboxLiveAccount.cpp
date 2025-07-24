#include "XboxLiveAccount.h"
#include "Friend.h"
#include <iostream>
#include <ctime>
#include <cctype>
using namespace std;

XboxLiveAccount::XboxLiveAccount(){ // Constructor
    // Initialize member variables
    gamertag = "";
    email = "";
    password = "";
    date_created = "";
    subscription_status = "";
    gamerscore = 0;
}
void XboxLiveAccount::SetGamertag(string gtag){ // Setter for gamertag
    gamertag = gtag;
}
string XboxLiveAccount::GetGamertag() const{ // Getter for gamertag
    return gamertag;
}
void XboxLiveAccount::SetEmail(string e){ // Setter for email
    email = e;
}
string XboxLiveAccount::GetEmail() const{ // Getter for email
    return email;
}
void XboxLiveAccount::SetPassword(string pw){ // Setter for password
    password = pw;
}
string XboxLiveAccount::GetPassword() const{ // Getter for password
    return password;
}
void XboxLiveAccount::SetDateCreated(string date){ // Setter for date created
    date_created = date;
    time_t now = time(0); // Get current time
    tm *ltm = localtime(&now); // Convert to local time
    // Format date as "MM/DD/YYYY"
    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;
    date_created = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}
string XboxLiveAccount::GetDateCreated() const{ // Getter for date created
    return date_created;
}
void XboxLiveAccount::SetSubscriptionStatus(string subscription){ // Setter for subscription status
    subscription_status = subscription;
}
string XboxLiveAccount::GetSubscriptionStatus() const { // Getter for subscription status
    return subscription_status;
}
void XboxLiveAccount::SetGamerscore(int gscore){ // Setter for gamerscore
    gamerscore = gscore;
}
int XboxLiveAccount::GetGamerscore() const{ // Getter for gamerscore
    return gamerscore;
}
void XboxLiveAccount::SetGamesOwned(const string& games){ // Method to set games owned
    games_owned.push_back(games);
}
vector<string> XboxLiveAccount::GetGamesOwned() const{ // Method to get games owned
    return games_owned;
}
void XboxLiveAccount::SetRecentlyPlayedGame(const string& recent_games){ // Method to set recently played games
    recently_played_games.push_back(recent_games);
}
vector<string> XboxLiveAccount::GetRecentlyPlayedGames() const{ // Method to get recently played games
    return recently_played_games;
}
void XboxLiveAccount::SetPaymentHistory(const string& payment){ // Method to set payment history
    payment_history.push_back(payment);
}
vector<string> XboxLiveAccount::GetPaymentHistory() const{ // Method to get payment history
    return payment_history;
}

void XboxLiveAccount::AddFriend(const Friend& f){ // Method to add a friend
    friends_list.push_back(f);
}
void XboxLiveAccount::RemoveFriend(const Friend& remove_f){ // Method to remove a friend
    // Find the friend in the list and remove them
    auto it = find_if(friends_list.begin(), friends_list.end(),
                    [&](const Friend& f) {return f.gamertag == remove_f.gamertag;});
    // If found, erase the friend from the list
    if (it != friends_list.end()) {
        friends_list.erase(it);
        cout << remove_f.gamertag << " has been removed from your friends list." << endl;
    }
    // If not found, print a message
    else {
        cout << remove_f.gamertag << " not found in your friends list." << endl;
    }
}
vector<Friend> XboxLiveAccount::GetFriendsList() const{ // Method to get the friends list
    return friends_list;
}

FreeAccount::FreeAccount() : XboxLiveAccount() { // Constructor for FreeAccount
    free_features = "Free Xbox Account allows access to basic features like friend management, messaging, and limited game demos.";
}
void FreeAccount::SetFreeFeatures(const string& features) { // Setter for free features
    free_features = features;
}
string FreeAccount::GetFreeFeatures() const { // Getter for free features
    return free_features;
}
GoldAccount::GoldAccount() : XboxLiveAccount() { // Constructor for GoldAccount
    gold_features = "Xbox Live Gold adds access to online multiplayer, free monthly games, and exclusive member discounts.";
}
void GoldAccount::SetGoldFeatures(const string& features) { // Setter for gold features
    gold_features = features;
}
string GoldAccount::GetGoldFeatures() const { // Getter for gold features
    return gold_features;
}
UltimateAccount::UltimateAccount() : XboxLiveAccount() {
    ultimate_features = "Xbox Game Pass Ultimate includes everything in Gold plus a library of hundreds of downloadable games, cloud gaming, and Game Pass for PC.";
}
void UltimateAccount::SetUltimateFeatures(const string& features) { // Setter for ultimate features
    ultimate_features = features;
}
string UltimateAccount::GetUltimateFeatures() const { // Getter for ultimate features
    return ultimate_features;
}