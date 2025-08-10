#include <stdio.h>
#include "file.h"
//This function is used to load contacts rom structure to file
void saveContactsToFile(AddressBook *addressBook) {
FILE *fp=fopen("contacts.txt","w+");
for(int i=0;i<addressBook->contactCount;i++)
{
fprintf(fp,"%d,%s,%s,%s",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
putc('\n',fp);
}
fclose(fp);
}

//This function is used in retrieving the contact details from the file.
//It is reading the contacts file till end of the file.Selective fscanf function is used.It takes characters till it encounters ','
void loadContactsFromFile(AddressBook *addressBook) {
    FILE *fp=fopen("contacts.txt","r");
    if(fp==NULL)
    {
    perror(" ");
    return;
    }
fseek(fp,0,SEEK_END);
long long int size=ftell(fp);char ch;
//printf("size=%lld",size);
int i,c;
rewind(fp);
//fscanf(fp,"%d",&addressBook->contactCount);
for(i=0;!feof(fp);i++)
{
//	fscanf(fp,"%d",&addressBook->contactCount);
fscanf(fp,"%d,%[^,],%[^,],%s",&c,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
}
addressBook->contactCount=c;
//putc('\n',fp);}
fclose(fp);
//printf("name=%s",addressBook->contacts[i].name);
}
