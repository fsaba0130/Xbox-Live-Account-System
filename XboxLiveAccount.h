#ifndef XBOXLIVEACCOUNT_H
#define XBOXLIVEACCOUNT_H

#include "Friend.h"
#include <string>
#include <vector>
using namespace std;

class XboxLiveAccount{
    public:
        // Constructor
        XboxLiveAccount();

        // Setters and getters for gamertag, email, password, date created, subscription status, and gamerscore
        void SetGamertag(string gtag);
        string GetGamertag() const;
        void SetEmail(string e);
        string GetEmail() const;
        void SetPassword(string pw);
        string GetPassword() const;
        void SetDateCreated(string date);
        string GetDateCreated() const;
        void SetSubscriptionStatus(string subscription);
        string GetSubscriptionStatus() const;
        void SetGamerscore(int gscore);
        int GetGamerscore() const;

        // Include the following methods to manage friends
        void AddFriend(const Friend& f);
        void RemoveFriend(const Friend& remove_f);
        vector<Friend> GetFriendsList() const;

        // Methods to manage games owned, recently played games, and payment history
        void SetGamesOwned(const string& games);
        vector<string> GetGamesOwned() const;
        void SetRecentlyPlayedGame(const string& recent_games);
        vector<string> GetRecentlyPlayedGames() const;
        void SetPaymentHistory(const string& payment);
        vector<string> GetPaymentHistory() const;
    private:
        // Private member variables
        string gamertag;
        string email;
        string password;
        string date_created;
        string subscription_status;
        int gamerscore;

        // Vector of Friend objects to store friends list
        vector<Friend> friends_list;

        // Vector of strings to store games owned, recently played games, and payment history
        vector<string> games_owned;
        vector<string> recently_played_games;
        vector<string> payment_history;
};

// FreeAccount, GoldAccount, and UltimateAccount classes inherit from XboxLiveAccount
class FreeAccount : public XboxLiveAccount {
    public:
        FreeAccount();
        void SetFreeFeatures(const string& features);
        string GetFreeFeatures() const;
    private:
        string free_features;
};

class GoldAccount : public XboxLiveAccount {
    public:
        GoldAccount();
        void SetGoldFeatures(const string& features);
        string GetGoldFeatures() const;
    private:
        string gold_features;
};

class UltimateAccount : public XboxLiveAccount {
    public:
        UltimateAccount();
        void SetUltimateFeatures(const string& features);
        string GetUltimateFeatures() const;
    private:
        string ultimate_features;
};

#endif /* XBOXLIVEACCOUNT_H */