/* *****************************************************************************************************************************************************************************************************************PROJECT DOCUMENTATION*******************************************************************************
 
Author:NIMISHA U
Date:15-04-2025
NAME OF THE PROJECT:ADDRESS BOOK
DESCRIPTION OF THE PROJECT:This project is a command-line based Address Book application developed in C.
It allows users to manage contact details including Name, Mobile Number, and
Email ID. The application performs input validation to ensure that only correct
data is stored.
It uses C structures to represent individual contacts and file handling to store
data persistently in a text file named 'contacts.txt'.
The key functionalities include:
• Adding new contacts with validation for name (alphabetic), mobile number
(10 digits), and email ID (standard format).(example@gmail.com)
• Editing existing contact information.
• Deleting a contact.
• Searching for contacts using name, mobile number, or email ID.
• Listing all contacts sorted either by Name or Mobile Number, or Email ID.
This project demonstrates concepts such as structures, file I/O, input validation,
and sorting in C.
This C program reads user input for an address book, including name, mobile number, and
email ID. It validates each input and stores valid entries into a file named 'contacts.txt'.
Invalid inputs are rejected with appropriate error messages.

SAMPLE INPUT AND OUTPUTS:
=========================

1.For Creating the contact:
-------------------------


Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice: 1
Enter the name of the person
nimisha

Entered name is nimisha
Enter the phone number
7894561230

Entered phone number is 7894561230
Enter the Email address
nimishau@gmail.com

Entered maild ID is nimishau@gmail.com
Contact details are successfully created
name=nimisha
phone number=7894561230
email ID=nimishau@gmail.com

2.For Searching a contact:
--------------------------

Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice: 2

Please enter your choice for searching contact
1.Name
2.Mobile number
3.MailID
1

Enter name to be searched
nimisha
There are multiple entries with same name
nimisha
8585858585
nni@gmail.com
nimisha
9638527410
nimisha@gmail.com
nimisha
8888888888
n@gmail.com
nimisha
7894561230
nimishau@gmail.com


Please enter mobile number to be searched
7894561230

name=nimisha
Mobile number=7894561230
Email ID=nimishau@gmail.com

3.For Editing a contact:
------------------------

Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice: 3

Enter the contact to be edited
1.Name
2.MobileNumber
3.EmailID
1

Enter the name to be searched
nimisha
There are multiple entries with same name
nimisha
8585858585
nni@gmail.com
nimisha
9638527410
nimisha@gmail.com
nimisha
8888888888
n@gmail.com
nimisha
7894561230
nimishau@gmail.com


Please enter mobile number to be searched
7894561230

Enter the contact to be edited
1.Name
2.MobileNumber
3.EmailID
1
Please Enter the name you want to replace in database
nimishau

Updated values of cotact are:

name=nimishau
Mobile number=7894561230
Email ID=nimishau@gmail.com

4.Deleting the contact
-----------------------

nimisha@DESKTOP-EQ0MDSN:~/emertxe/25002B/Adv_c/project1/AddressBook-NewDesign$ ./a.out

Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice: 4

Enter the contact to be deleted
1.Name
2.MobileNumber
3.EmailID
1

Enter the name to be deleted
nimishau

Are you sure to delete the contact.Please Enter y for Yes and n for No(y/n)y
y
Contact successfully Deleted

5.LIST ALL CONTACTS:
--------------------
Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice: 5
Select sort criteria:
1. Sort by name
2. Sort by phone
3. Sort by email
Enter your choice: 1

Sorted list based on name is
Name                    Phone number            Email

1. abc                 1111111111               aa@gmail.com

2. ai                  7894561233               hh@gmail.com

3. Alice Smith         0987654321               alice@example.com

4. bc                  8527419630               bc@gmail.com

5. Bob Johnson         1112223333               bob@company.com

6. Carol White         4445556666               carol@company.com

7. David Brown         7778889999               david@example.com

8. Demo                3456789012               d1@g.com

9. Frank Miller        3334445555               frank@example.com

10. Grace Wilson        2223334444              grace@example.com

11. Hannah Clark        5556667777              hannah@example.com

12. Ian Lewis           8889990000              ian@example.com

13. jhgfcvb             5432123456              dfghj@gmail.com

14. nimisha             9638527410              nimisha@gmail.com

15. nimisha             8888888888              n@gmail.com

16. nimisha             8585858585              nni@gmail.com

17. xyz                 2222222222              xyz@gmail.com

6.Exit:
-------

Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice: 6
Saving and Exiting...

VALIDATIONS:
===========

Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice: 1
Enter the name of the person
nim123

Entered name is invalid.Please Enter a valid Name
Enter the name of the person
nimi#$@

Entered name is invalid.Please Enter a valid Name
Enter the name of the person
_nimi

Entered name is invalid.Please Enter a valid Name
Enter the name of the person
nimisha u

Entered name is nimisha u
Enter the phone number
ertyy

Phone number should contain 10 digits!!

Enter the phone number
124ydzx

Phone number should contain 10 digits!!

Enter the phone number
8527419630

Entered phone number is 8527419630
You have entered a mobile number which already exists in database.
Do you wish to continue?
1.Try with another phone number
2.Return to main menu
1

Enter the phone number
6666666666

Entered phone number is 6666666666
Enter the Email address
nimi.com

There should be one @ in mail ID and not more than that.

Enter the Email address
nimi@.com

There is no domain name in entered mail-id.

Enter the Email address
nimishau@gmail.com

Entered maild ID is nimishau@gmail.com
Contact details are successfully created
name=nimisha u
phone number=6666666666
email ID=nimishau@gmail.com

Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice: 5
Select sort criteria:
1. Sort by name
2. Sort by phone
3. Sort by email
Enter your choice: 1

Sorted list based on name is
Name                    Phone number            Email

1. abc                 1111111111               aa@gmail.com

2. ai                  7894561233               hh@gmail.com

3. Alice Smith         0987654321               alice@example.com

4. bc                  8527419630               bc@gmail.com

5. Bob Johnson         1112223333               bob@company.com

6. Carol White         4445556666               carol@company.com

7. David Brown         7778889999               david@example.com

8. Demo                3456789012               d1@g.com

9. Frank Miller        3334445555               frank@example.com

10. Grace Wilson        2223334444              grace@example.com

11. Hannah Clark        5556667777              hannah@example.com

12. Ian Lewis           8889990000              ian@example.com

13. jhgfcvb             5432123456              dfghj@gmail.com

14. nimisha             8888888888              n@gmail.com

15. nimisha             8585858585              nni@gmail.com

16. nimisha             9638527410              nimisha@gmail.com

17. nimisha u           6666666666              nimishau@gmail.com

18. xyz                 2222222222              xyz@gmail.com



************************************************************************************************************************************************************************************************************************************************************************************************************************/

#include <stdio.h>
#include<string.h>
#include "contact.h"

int main() {
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
       getchar(); 
        switch (choice) {
            case 1:
                createContact(&addressBook);
		choice=0;
                break;
            case 2:
                searchContact(&addressBook);
		choice=0;
                break;
            case 3:
                editContact(&addressBook);
		choice=0;
                break;
            case 4:
                deleteContact(&addressBook);
		choice=0;
                break;
            case 5:
                printf("Select sort criteria:\n");
                printf("1. Sort by name\n");
                printf("2. Sort by phone\n");
                printf("3. Sort by email\n");
                printf("Enter your choice: ");
                int sortChoice;
                scanf("%d", &sortChoice);
                listContacts(&addressBook, sortChoice);
		choice=0;
                break;
            case 6:
                printf("Saving and Exiting...\n");
                saveContactsToFile(&addressBook);
		//loadContactsFromFile(addressBook);
	//	choice=0;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
       return 0;
}
