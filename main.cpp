#include <iostream>
#include <vector>
using namespace std;

#include "XboxLiveAccount.h"
#include "Friend.h"

int main() {
    XboxLiveAccount account;
    string gtag, email, password, date_created, subscription_status;
    int gamerscore;
    vector<Friend> friends_list;
    FreeAccount free_account;
    GoldAccount gold_account;
    UltimateAccount ultimate_account;
    
    /** ACCOUNT SETUP */
    // Validate email address
    cout << "Enter your email address: " << endl;
    bool hasAtSymbol = false;
    bool hasDot = false;
    while(true){
        getline(cin, email);
        hasAtSymbol = false;
        hasDot = false;
        for(int i = 0; i < email.length(); i++){
            if(email[i] == '@'){
                hasAtSymbol = true; // Check for '@' symbol
            }
            if(email[i] == '.'){
                hasDot = true; // Check for '.' symbol
            }
        }
        if(hasAtSymbol && hasDot){
            break; // Exit loop if email is valid
        }
        else{
            cout << "Invalid email. Please enter a valid email address: " << endl; // Prompt for a new email
        }
    }
    account.SetEmail(email);
    // Validate password
    cout << "Enter your password (must be at least 8 characters long, contain at least one uppercase letter and special character): " << endl;
    bool hasUpper = false;
    bool hasSpecialChar = false;
    while(true){
        getline(cin, password);
        hasUpper = false;
        hasSpecialChar = false;
        for(int i = 0; i < password.length(); i++){
            if(isupper(password[i])){
                hasUpper = true; // Check for uppercase letters
            }
            if(ispunct(password[i])){
                hasSpecialChar = true; // Check for special characters
            }
        }
        if(password.length() >= 8 && hasUpper && hasSpecialChar){
            break; // Exit loop if password is valid
        }
        else{
            cout << "Invalid password. Please enter a new password: " << endl; // Prompt for a new password
        }
    }
    account.SetPassword(password);

    cout << "Enter your gamertag: " << endl;
    getline(cin, gtag);
    account.SetGamertag(gtag);
    account.SetDateCreated(date_created);
    cout << "Choose a subscription (Free: $0.00, Gold: $9.99, Ultimate: $19.99): " << endl;
    getline(cin, subscription_status);
    if(subscription_status == "Free" || subscription_status == "free") {
        account.SetPaymentHistory("Free Account - $0.00");
        account.SetSubscriptionStatus("Free");
        free_account.SetFreeFeatures("Basic features with no cost.");
        free_account.GetFreeFeatures();
        cout << "Subscribed to Free Xbox Account - $0.00" << endl;
    } 
    else if(subscription_status == "Gold" || subscription_status == "gold") {
        account.SetSubscriptionStatus("Gold");
        account.SetPaymentHistory("Xbox Live Gold - $9.99");
        gold_account.SetGoldFeatures("Access to online multiplayer, free monthly games, and exclusive discounts.");
        gold_account.GetGoldFeatures();
        cout << "Subscribed to Xbox Live Gold - $9.99" << endl;
    } 
    else if(subscription_status == "Ultimate" || subscription_status == "ultimate") {
        account.SetSubscriptionStatus("Ultimate");
        account.SetPaymentHistory("Xbox Game Pass Ultimate - $19.99");
        ultimate_account.SetUltimateFeatures("Includes everything in Gold plus a library of hundreds of downloadable games, cloud gaming, and Game Pass for PC.");
        ultimate_account.GetUltimateFeatures();
        cout << "Subscribed to Xbox Game Pass Ultimate - $19.99" << endl;
    } 
    else {
        cout << "Invalid subscription type. Defaulting to Free Account." << endl;
        account.SetSubscriptionStatus("Free");
        account.SetPaymentHistory("Free Account - $0.00");
        free_account.SetFreeFeatures("Basic features with no cost.");
        free_account.GetFreeFeatures();
        cout << "Subscribed to Free Xbox Account - $0.00" << endl;
    }
    account.SetGamerscore(0);
    cout << "Your Xbox Live account has been created successfully!" << endl;
    cout << "Gamertag: " << account.GetGamertag() << endl;
    cout << "Email: " << account.GetEmail() << endl;
    cout << "Subscription Status: " << account.GetSubscriptionStatus() << endl;
    cout << "Gamerscore: " << account.GetGamerscore() << endl;
    cout << "Date Created: " << account.GetDateCreated() << endl;

    /** ACCOUNT MANAGEMENT */
    // Add a game to the account
    char input;
    cout << "Would you like to add a game to your account?\nPress (A) for Yes\nPress (B) for No" << endl;
    cin >> input;
    cin.ignore();

    if(input == 'A' || input == 'a'){
        while(true){
            string game;
            cout << "Enter the name of the game you want to add: ";
            getline(cin, game);
            account.SetGamesOwned(game);
            cout << game << " has been downloaded to your account!" << endl;

            cout << "Would you like to play " << game << " now?\nPress (A) for Yes\nPress (B) for No" << endl;
            cin >> input;
            cin.ignore();
            if(input == 'A' || input == 'a'){
                account.SetRecentlyPlayedGame(game);
            }
            cout << "Would you like to add another game?\nPress (A) for Yes\nPress (B) for No" << endl;
            cin >> input;
            cin.ignore();
            if(input == 'B' || input == 'b'){
                break;
            }
        }
    }
    cout << "Games owned by " << account.GetGamertag() << ":" << endl;
    for(int i = 0; i < account.GetGamesOwned().size(); i++){
        cout << account.GetGamesOwned()[i] << endl;
    }

    // Display recently played games
    cout << "Would you like to view your recently played games?\nPress (A) for Yes\nPress (B) for No" << endl;
    cin >> input;
    cin.ignore();

    if(input == 'A' || input == 'a'){
        vector<string> recently_played_games = account.GetRecentlyPlayedGames();
        if (recently_played_games.empty()){
            cout << "No recently played games." << endl;
        }
        else{
            cout << "Recently played games:" << endl;
            for(int i = 0; i < recently_played_games.size(); i++){
                cout << recently_played_games[i] << endl;
            }
        }
    }

    // Display payment history
    cout << "Would you like to view your payment history?\nPress (A) for Yes\nPress (B) for No" << endl;
    cin >> input;
    cin.ignore();
    if(input == 'A' || input == 'a'){
        vector<string> payment_history = account.GetPaymentHistory();
        if(payment_history.empty()){
            cout << "No payment history." << endl;
        }
        else{
            cout << "Payment history:" << endl;
            for(int i = 0; i < payment_history.size(); i++){
                cout << payment_history[i] << endl;
            }
        }
    }

    // Add a friend
    string friend_gamertag;
    Friend new_friend;
    Friend remove_friend;
    cout << "Would you like to add a friend?\nPress (A) for Yes\nPress (B) for No" << endl;
    cin >> input;
    cin.ignore();
    if(input == 'A' || input == 'a'){
        while(true){
            cout << "Enter the gamertag of the friend you want to add: ";
            getline(cin, friend_gamertag);
            new_friend.gamertag = friend_gamertag;
            new_friend.online_status = true;
            new_friend.last_seen_online = "N/A";
            account.AddFriend(new_friend);
            cout << friend_gamertag << " has been added to your friends list!" << endl;
            
            cout << "Would you like to add another friend?\nPress (A) for Yes\nPress (B) for No" << endl;
            cin >> input;
            cin.ignore();
            if(input == 'B' || input == 'b'){
                break;
            }
        }
    }
    cout << "Friends list: " << endl;
    for(int i = 0; i < account.GetFriendsList().size(); i++){
        PrintFriend(account.GetFriendsList()[i]);
    }

    // Remove a friend
    cout << "\nWould you like to remove a friend?\nPress (A) for Yes\nPress (B) for No" << endl;
    cin >> input;
    cin.ignore();
    if(input == 'A' || input == 'a'){
        Friend remove_friend;
        cout << "Enter gamertag of friend to remove: ";
        getline(cin, remove_friend.gamertag);
        account.RemoveFriend(remove_friend);
    }

    // Prints updated friends list
    cout << "Friends list: " << endl;
    for(int i = 0; i < account.GetFriendsList().size(); i++){
        PrintFriend(account.GetFriendsList()[i]);
        cout << endl;
    }

    /* ACCOUNT INTERACTIONS */
    string message;
    int friend_gamerscore;

    cout << "Press (Y) to invite a friend to play a game with you\nPress (X) to send a message to a friend\nPress (A) to compare gamerscore\nPress (B) to exit" << endl;
    cin >> input;
    cin.ignore();
    while (true){
        if(input == 'Y' || input == 'y'){
            cout << "Enter your friend's gamertag to send an invite: ";
            getline(cin, friend_gamertag);
            cout << "Invite sent to " << friend_gamertag << "!" << endl;
        }
        else if(input == 'X' || input == 'x'){
            cout << "Enter the gamertag of the friend you want to message: ";
            getline(cin, friend_gamertag);
            cout << "Enter your message: ";
            getline(cin, message);
            cout << "Message sent to " << friend_gamertag << ": " << message << endl;
        }
        else if(input == 'A' || input == 'a'){
            cout << "Enter your friend's gamertag to compare gamerscore: ";
            getline(cin, friend_gamertag);
            cout << "Enter your friend's gamerscore: ";
            cin >> friend_gamerscore;
            cin.ignore();
        
            if(account.GetGamerscore() > friend_gamerscore){
                cout << "You have a higher gamerscore than " << friend_gamertag << "!" << endl;
            }
            else if(account.GetGamerscore() < friend_gamerscore){
                cout << friend_gamertag << " has a higher gamerscore than you!" << endl;
            }
            else{
                cout << "You and " << friend_gamertag << " have the same gamerscore!" << endl;
            }
        }
        else if(input == 'B' || input == 'b'){
            cout << "Exiting the program. Thank you for using Xbox Live!" << endl;
            return 0;
        }
        cout << "Press (Y) to invite a friend to play a game with you\nPress (X) to send a message to a friend\nPress (A) to compare gamerscore\nPress (B) to exit" << endl;
        cin >> input;
        cin.ignore();
    }
}