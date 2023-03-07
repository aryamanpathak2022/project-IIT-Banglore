# Airline Ticket Management System
The Airline Ticket Management System, developed in C language, offers customers a range of convenient features. Customers can book flights, cancel tickets, perform web check-ins, and view their ticket details with ease. In addition, the system employs dynamic pricing based on demand, ensuring that customers receive competitive prices. To further enhance customer convenience, the system includes a secure payment system and displays passenger details. Finally, the system prints the date and time of the ticket purchase for easy reference.

# Features

## Book  a Flight Ticket:
 Customers can book a ticket for their desired destination by selecting the departure and arrival locations, date, and number of passengers. Prices are dynamically adjusted based on your date of departure. Payment can be made using a credit or debit card.

## Cancellation: 
Customers can cancel their ticket by providing their PNR number.

## Web Check-In: 
Customers can check-in for their flight by providing their PNR number. Passenger details are displayed upon check-in.

## My Account: 
Customers can view their ticket details by providing their PNR number. The ticket details include passenger information, flight details, and the date and time of the flight.

# Requirements
C Compiler (e.g., GCC)

# Libraries used
-<stdlib.h>
-<stdio.h>
-<strings.h>
-<time.h>

# Modules

1.[book.c](https://github.com/aryamanpathak2022/project-IIT-Banglore/blob/main/book.c)  

2.[diff.c](https://github.com/aryamanpathak2022/project-IIT-Banglore/blob/main/diff.c) 

3.[dynamic_pricing.c](https://github.com/aryamanpathak2022/project-IIT-Banglore/blob/main/dynamic_pricing.c)  

4.[Passengerdetails.c](https://github.com/aryamanpathak2022/project-IIT-Banglore/blob/main/Passengerdetails.c)  

5.[payment_complete.c](https://github.com/aryamanpathak2022/project-IIT-Banglore/blob/main/payment_complete.c)  

6.[print_date1_time.c](https://github.com/aryamanpathak2022/project-IIT-Banglore/blob/main/print_date1_time.c) 

7.[web_check_in.c](https://github.com/aryamanpathak2022/project-IIT-Banglore/blob/main/web_check_in.c) 

8.[cancellation.c](https://github.com/aryamanpathak2022/project-IIT-Banglore/blob/main/cancellation.c) 

9.[mainfile.c](https://github.com/aryamanpathak2022/project-IIT-Banglore/blob/main/mainfile.c)  


# Header file

1.[combine.h](https://github.com/aryamanpathak2022/project-IIT-Banglore/blob/main/combine.h)


# Working
The program takes inputs from two  database files provided by the airlines or airport which are database.txt(this file contains all the flights and passengers information which regularly gets updated by the program whenever a customer books or cancels a flight) and seats.txt(this file contains details about the number of seats booked in each flight in the  database.txt file) 

When the program gets started it reads inputs from the database.txt and seats.txt files and make a array od struct passenger and seats and then it prints the menu for user showing 4 options-
 1. BOOK A FLIGHT TICKET
 2. CANCELLATION
 3. MY ACCOUNT
 4. Web check-in
 
 when the user enters 1 the program runs the book module and asks user about the information necessary to show the flights .After taking the necessary information (if all the infoormation entered is correct) the program shows the list of flghts available with prices changing dynamically according to the difference between current date and date selected(using dynamic_pricing module,prices can be also changed using number of seats available and other factors, the logic and implementation  will be same ) .After selecting the flights and putting in all the  personal details asked the user is the program runs the payment_complete module which asks the user to input the card number (16 digit card number) and cvv number(3 digit)
 If correct the thank you message is displayed along with pnr number for each customer(randomly generated)

 After the booking is completed and the array is updatd the backend files that is database.txt and seats.txt are updated with customer details and number of seats booked 

 When the user enter 2 as choice the program runs the cancellation modules which asks the user for pnr and checks that pnr exists or not if yes than user's details are removed from the database and number of seats booked are also reduced and the backend files are updated accordingly


 when user selects option 3 ,the user is asked to input the pnr and if pnr exist in the database the program shows user the details of his/her booked flight

 when user selecrts option 4 ,the user is asked to input the pnr and if pnr exist in the database the program prints a message of web check in successfull and a change can be shown in the files of airline just like the program did after booking and cancellation, since this is a program  to make the logic behing air ticket management system it does not contain any files other thann necessary files by airlines and other authorities. 


After each module completion the user is asked to go back to the main menu(1) or to exit the program(0)



# Usage

## To book a ticket, select the Book Ticket option from the menu, filing in the details, and submit the form. Prices are dynamically adjusted based on your date of departure, so prices may change based on availability and demand. Payment can be made using a credit or debit card.

## To cancel a ticket, select the Cancellation option from the menu, enter your PNR number, and submit the form. You will receive a confirmation message for the cancellation.

## To web check-in for your flight, select the Web Check-In option from the menu, enter your PNR number, and submit the form. Your confirmation for web check-in will be displayed.

## To view your ticket details, select the Account option from the menu, enter your PNR number, and submit the form. Your ticket details, including passenger information, flight details, and the date and time of the flight, will be displayed.


#Individual ContriBution

1. Sanchit Dogra -- print_date1_time.c,mainfile.c Modules
2. Rutul Patel-- Cancellation.c Module ,makemefile.mak
3. Vasu Aggarwal -- seats.txt using [logic.c](),diff.c 
4. Aryaman Pathak-- book.c ,dynamic_pricing.c Modules 
5. Rishi Patel-- Passengerdetail.c , payment_complete.c Modules database.txt using [logic.c]()
6. Siddhesh Deshpande--combine.h,Modularity,Readme file,web_check_in.c Module

# Constraints
1.user can only book for flights on a day within one week from booking
2.user have 5 time slots for flights and 4 airports to choose from

These all constraints are because this is a sample project for airport management and not a real one .
All these constraints can be changed according to the databse provided .The logic will be same.

