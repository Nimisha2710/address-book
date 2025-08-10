#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook, int sortCriteria);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);
int validate_name(char *str);
//int validate_Mno(char *str);
int validate_Mno(char *str,AddressBook *addressBook);
int validate_mailid(char *str,AddressBook *addressBook);
int search_name(AddressBook *addressBook,char *name);
int search_mnum(AddressBook *addressBook,char *mno);
int search_email(AddressBook *addressBook,char *mail);
int duplicate_mnum(char *dstr,AddressBook *addressBook);
int duplicate_mail(char *dstr,AddressBook *addressbook);
#endif
