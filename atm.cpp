#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>

using namespace std; 

class Account {
    private:
        char name[20];
        int password;
        int balance;

    public:
        char* getName(void){
            return name;
        };
        int getPassword(void){
            return password;
        };

        void showInfo(){
            cout << "Name:"<< name << "\n"<< "Total:" << balance << "\n";
        };
        void getInfo();
        void createAccount();
        bool login(char*, int);
        void withdrawal(char*, int);
        void deposit(char*, int);
        void showBalance();
};

class Admin {
    private:
        string name = "admin";
        string password = "1234";
    public:
        bool adminLogin(){
            string ID;
            string PW;

            cout << "ADMIN USER ID:\n";
            cin >> ID;
            cout << "ADMIN PASSWORD:\n";
            cin >> PW;

            if (ID == name && PW == password) {
                cout << "Welcome to Admin Page!" << endl;
                return true;
            } else {
                cout << "Wrong ID or PASSWORD!" << endl;
                return false;
            }
        };

        int viewUsers(){
            // Admin User Login 
            // file open 
            Account account;
            ifstream file;
            
            file.open("data.txt", ios::in);
            if (!file){
                cout << "File Error!" << endl;
                return 0;
            }
            file.read((char*)&account, sizeof(account));
            while(!file.eof()) {
                account.showInfo();
                file.read((char*)&account, sizeof(account));
            }

            file.close();
            return 0;
        };

        void adminService(){
            cout << "Admin Page Menu\n";
            cout << "1. See All Users\n";
        };
};

void Account::getInfo(){
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cout << "Enter name:";
    cin >> name;

    cout << "Enter PIN number: \n";
    cin >> password;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    cout << "Enter initial balance: \n";
    cin >> balance;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

}

void Account::createAccount(){
    ofstream file;
    Account account;

    file.open("data.txt", ios::out | ios::app);
    if (!file) {
        cout << "File Error!" << endl;
    }
    account.getInfo();
    file.write((char*)&account, sizeof(account));
    file.close();
};

void Account::showBalance(){
    cout << name << "'s Account" << "/n";
    cout << "Total Balance : " << balance << "/n";
}

bool Account::login(char* userID, int userPW){
    Account account;
    fstream file;

    file.open("data.txt", ios::in);
    if (!file) {
        cout << "File Error!" << endl;
        return false;
    }
    file.read((char*)&account, sizeof(account));
    
    while (!file.eof()){
        if (!strcmp(account.getName(), userID)) {
            
            if (account.getPassword() == userPW){
                cout << "Welcome ," << userID << endl; 
                file.close();
                return true;
            } 
            file.read((char*)&account, sizeof(account));
        }
    }
    file.close();
    return false;
}

void Account::deposit(char* userName, int userPW){
    Account account;
    fstream file, newFile;

    file.open("data.txt", ios::in | ios::out | ios::ate);
    newFile.open("newData.txt", ios::out | ios::app);
    file.seekg(0); 
    file.read((char*)&account, sizeof(account));

    while (!file.eof()){

        // compare string userName with account name
        if (!strcmp(account.getName(), userName)){
            if (userPW != account.getPassword()){
                cout << "Login Failed!\n";
                break;
            } else {
                cout << "Login Succeeded!\n";
            }

            int amount;
            cout << "Enter the amount to deposit:\n";
            cin >> amount;
            account.balance += amount;
            cout << "Total:" << account.balance << endl;
            newFile.write((char*)&account, sizeof(account));
        } else {
            newFile.write((char*)&account, sizeof(account));
        }
        file.read((char*)&account, sizeof(account));
    }

    file.close();
    newFile.close();
    remove("data.txt");
    rename("newData.txt", "data.txt");
}

void Account::withdrawal(char* userName, int userPW){
    Account account;
    fstream file, newFile;

    file.open("data.txt", ios::in | ios::out | ios::ate);
    newFile.open("newData.txt", ios::out | ios::app);
    file.seekg(0); 
    file.read((char*)&account, sizeof(account));

    while (!file.eof()){
        // compare string userName with account name
        if (!strcmp(account.getName(), userName)){
            if (userPW != account.getPassword()) {
                cout << "Login Failed!\n";
                break;
            } else {
                cout << "Login Succeeded!\n";
            }

            int amount;
            cout << "Enter the amount to withdraw:\n";
            cin >> amount;
            if (account.balance < amount) {
                cout << "Not Enough Money!\n";
            } else {
                account.balance -= amount; // update the value 
                cout << "Total:" << account.balance << endl;
                newFile.write((char*)&account, sizeof(account));
            }
        } else {
            // new file migration  
            newFile.write((char*)&account, sizeof(account));
        }
        file.read((char*)&account, sizeof(account));
    }

    file.close();
    newFile.close();
    remove("data.txt");
    rename("newData.txt", "data.txt");
}


void atmService() {
    Account account;
    Admin admin;

    int menu = 0;
    int amenu = 0;
    char userID[20];
    int userPW;

    cout << "Welcome to ATM Service!\n";
    cout << "\t1. Create Account \n";
    cout << "\t2. Deposit \n";
    cout << "\t3. Withdraw \n";
    cout << "\t9. Admin Page\n";
    cout << "\t0. Exit\n";
    cin >> menu;
    
    switch (menu){
    case 1:
        cout << "<Create Account>\n";
        account.createAccount();
        break;
    case 2:
        cout << "<Deposit>\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Enter Name:\n";
        cin.getline(userID, 20);
        cout << "Enter Password:\n";
        cin >> userPW;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        account.deposit(userID, userPW);
        break;
    case 3:
        cout << "<Withdraw>\n";
        cout << "Enter Name:\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cin.getline(userID, 20);
        cout << "Enter Password:\n";
        cin >> userPW;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        account.withdrawal(userID, userPW);
        break;
    case 9:
        cout << "<Admin Page>\n";
        if (admin.adminLogin()) {
            cout << "Login Successfully!\n";
        } else {
            break;
        };
        admin.adminService();
        cout << "Enter Menu: \n";
        cin >> amenu;
        if (amenu == 1){
            admin.viewUsers();
        } 
        break;
    case 0:
        cout << "Thank You for using our ATM Service!\n";
        exit(0);
    }
}

int main(){
    cout << R"(
     _  _____ __  __    ____            _             _ _           
    / \|_   _|  \/  |  / ___|___  _ __ | |_ _ __ ___ | | | ___ _ __ 
   / _ \ | | | |\/| | | |   / _ \| '_ \| __| '__/ _ \| | |/ _ \ '__|
  / ___ \| | | |  | | | |__| (_) | | | | |_| | | (_) | | |  __/ |   
 /_/   \_\_| |_|  |_|  \____\___/|_| |_|\__|_|  \___/|_|_|\___|_|   
                                                                    
)" << endl;

    while(1){
         atmService();
    }
    
    return 0;
}