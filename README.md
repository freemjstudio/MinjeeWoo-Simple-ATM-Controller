# MinjeeWoo Assignment 
## Simple-ATM-Controller

This is a simple ATM controller service that user can deposit, withdraw and check the balance. 

```
     _  _____ __  __    ____            _             _ _           
    / \|_   _|  \/  |  / ___|___  _ __ | |_ _ __ ___ | | | ___ _ __ 
   / _ \ | | | |\/| | | |   / _ \| '_ \| __| '__/ _ \| | |/ _ \ '__|
  / ___ \| | | |  | | | |__| (_) | | | | |_| | | (_) | | |  __/ |   
 /_/   \_\_| |_|  |_|  \____\___/|_| |_|\__|_|  \___/|_|_|\___|_|   
                                                                    

Welcome to ATM Service!
        1. Create Account 
        2. Deposit 
        3. Withdraw 
        9. Admin Page
        0. Exit
```

## How to Start
- Make sure that you have C++ compiler on your environment. 
- Clone the remote repository. 

```
git clone https://github.com/freemjstudio/MinjeeWoo-Simple-ATM-Controller.git
```

## MacOS (VSCode Recommend)

```
cd "/YourDirectory/MinjeeWoo-Simple-ATM-Controller/" && g++ -std=c++14 atm.cpp -o atm && "/YourDirectory/MinjeeWoo-Simple-ATM-Controller/"atm
```

## Linux 
```
# move to directory 
cd /YourDirectory/MinjeeWoo-Simple-ATM-Controller/

# compile the c++ file with g++ 
g++ -std=c++14 atm.cpp -o atm

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

- Test User that is already created : ("bear", 1234)
- You can create test user following the test case below. 

A. User  
- create a new user 
```
1
<Create Account>
Enter name:test
Enter PIN number: 
1234
Enter initial balance: 
500
```

[user input]  
name = "test"   
password = 1234    
balance = 500    

B. deposit   
enter the amount to deposit   

```
2
<Deposit>
Enter Name:
bear
Enter Password:
1234
Login Succeeded!
Enter the amount to deposit:
5000
Total:15000
```

[user input]   
menu = 2   
name = "bear"   
password = 1234   
amount = 5000     

C. withdraw 

- withdraw fail test case : 

```
3
<Withdraw>
Enter Name:
test
Enter Password:
1234
Login Succeeded!
Enter the amount to withdraw:
1000
Not Enough Money!
```
[user input]    
menu = 3  
name = "test"   
password = 1234   
amount = 1000      

- withdraw success test case: 
```
3

<Withdraw>
Enter Name:
test
Enter Password:
1234
Welcome ,test
Enter the amount to withdraw:
100
Total:500
```
[user input]    
menu = 3  
name = "test"   
password = 1234   
amount = 100      


D. Admin   
- admin login success case
```
9
<Admin Page>
ADMIN USER ID:
admin
ADMIN PASSWORD:
1234
Welcome to Admin Page!
Login Successfully!
```
[user input]
menu = 9  
name = "admin"  
password = "1234"  

To view all of the users,   
menu = 1  

```
Admin Page Menu
1. See All Users
Enter Menu: 
1
Name:test
Total:500
```

- admin login fail case

```
9
<Admin Page>
ADMIN USER ID:
admin
ADMIN PASSWORD:
1111
Wrong ID or PASSWORD!
```
[user input]  
user id : "admin"
password : "1111"

E. Exit
```
Welcome to ATM Service!
        1. Create Account 
        2. Deposit 
        3. Withdraw 
        9. Admin Page
        0. Exit
0
Thank You for using our ATM Service!
```

[user input]    
menu = 0
