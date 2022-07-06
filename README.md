#Library Management System 

##Limitations:
Database needs to be created everytime the program file is executed. The static database is initialised at first and can be dynamically updated.

##Assumptions:
An issued book can not be deleted.
All users have unique names and usernames.
All books have unique titles.
Used system("cls") which is functional only on Windows.
To show the proper functionality of calculate_fine() I am asking the user to input the issue date and then calculating the fine from current date.

##Steps to run:
Run the following command in terminal: 'g++ -o LMS LMS.cpp', followed by '.\LMS'.