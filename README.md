# MinjeeWoo Assignment 
## Simple-ATM-Controller

This is a simple ATM controller service that user can deposit, withdraw and check the balance. 

## How to Start
- Make sure that you have C++ compiler on your environment. 
- Clone the remote repository. 

```
git clone https://github.com/freemjstudio/MinjeeWoo-Simple-ATM-Controller.git
```

## MacOS

```
cd "/YourDirectory/MinjeeWoo-Simple-ATM-Controller/" && g++ -std=c++14 atm.cpp -o atm && "/YourDirectory/MinjeeWoo-Simple-ATM-Controller/"atm
```

## Linux (Ubuntu)
```
# move to directory 
cd /YourDirectory/MinjeeWoo-Simple-ATM-Controller/

# compile the c++ file with g++ 
g++ -o atm atm.cpp 

# run the execution file
./atm 
```

## Welcome to ATM Service!

Enter the number that you want to run. 

#### 1. Create Account   
You can create the account.  

#### 2. Deposit   
You can deposit to your account.  

#### 3. Withdraw   
You can withdraw money from your account. 

#### 9. Admin Page  
You can view all of the users & account information. 

Admin User : "admin"
Admin Password : 1234

#### 0. Exit  
You can quit the ATM Service. Thank you for using our service. 

## TestCode

A. User
a. create a new user 
- user input  
menu = 1  

- user input  
name = "test"  
password = 1234  
balance = 1000  

b. deposit   
enter the amount to deposit   
- user input   
100  

c. withdraw   
enter the amount to deposit   
- user input    
300   


B. Admin   
- user input   
name = "admin"  
password = "1234"  

To view all of the users,   
menu = 1  
