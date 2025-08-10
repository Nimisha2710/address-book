
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

//This function is used to list contacts in sorted manner either based on name/email/phonenumber.It uses sorting method to sort contacts and strcasecmp to compare the data either uppercaser or lowercase letters and strcpy to copy the date

void listContacts(AddressBook *addressBook, int sortCriteria) 
{
	// Sort contacts based on the chosen criteria
	char temp1[50],temp2[50],temp3[50];int i,j,c=0;
	switch(sortCriteria)
	{
		//   while((addressBook->contacts[0].name[c])!='\0')
		case 1:

			{
				for(i=0;i<addressBook->contactCount;i++)
				{
					for(j=0;j<addressBook->contactCount;j++)
					{


						if(strcasecmp(addressBook->contacts[i].name,addressBook->contacts[j].name)<0)
						{
							strcpy(temp1,addressBook->contacts[i].name);
							strcpy(temp2,addressBook->contacts[i].phone);
							strcpy(temp3,addressBook->contacts[i].email);
							strcpy(addressBook->contacts[i].name,addressBook->contacts[j].name);
							strcpy(addressBook->contacts[i].phone,addressBook->contacts[j].phone);
							strcpy(addressBook->contacts[i].email,addressBook->contacts[j].email);
							strcpy(addressBook->contacts[j].name,temp1);
							strcpy(addressBook->contacts[j].phone,temp2);
							strcpy(addressBook->contacts[j].email,temp3);

						}
					}
				}




				printf("\nSorted list based on name is\n");
				printf("Name\t\t\tPhone number\t\tEmail\n");
				for(int i=0;i<(addressBook->contactCount);i++)
				{
					printf("\n%d. %-20s%s\t\t%s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
				}
				//)printf("\n%d.  name=%s\t\tphone number=%s\t\tEmailID=%s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
				//printf("phone number=%s\n",addressBook->contacts[i].phone);
				//printf("EmailID=%s\n",addressBook->contacts[i].email);
				printf("\n\n");
				break;
			}
		case 2:
			{
				for(i=0;i<addressBook->contactCount;i++)
				{
					for(j=0;j<addressBook->contactCount;j++)
					{
						if(strcmp(addressBook->contacts[i].phone,addressBook->contacts[j].phone)<0)
						{
							strcpy(temp1,addressBook->contacts[i].name);
							strcpy(temp2,addressBook->contacts[i].phone);
							strcpy(temp3,addressBook->contacts[i].email);
							strcpy(addressBook->contacts[i].name,addressBook->contacts[j].name);
							strcpy(addressBook->contacts[i].phone,addressBook->contacts[j].phone);
							strcpy(addressBook->contacts[i].email,addressBook->contacts[j].email);
							strcpy(addressBook->contacts[j].name,temp1);
							strcpy(addressBook->contacts[j].phone,temp2);
							strcpy(addressBook->contacts[j].email,temp3);

						}
					}
				}
				printf("\nSorted list based on phone number is\n");
				printf("Name\t\t\tPhone number\t\tEmail\n");
				for(int i=0;i<(addressBook->contactCount);i++)
				{
					printf("\n%d. %-20s%s\t\t%s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
					//printf("\n\n");
				}
				break;
			}
		case 3:
			{
				for(i=0;i<addressBook->contactCount;i++)
				{
					for(j=0;j<addressBook->contactCount;j++)
					{


						if(strcmp(addressBook->contacts[i].email,addressBook->contacts[j].email)<0)
						{
							strcpy(temp1,addressBook->contacts[i].name);
							strcpy(temp2,addressBook->contacts[i].phone);
							strcpy(temp3,addressBook->contacts[i].email);
							strcpy(addressBook->contacts[i].name,addressBook->contacts[j].name);
							strcpy(addressBook->contacts[i].phone,addressBook->contacts[j].phone);
							strcpy(addressBook->contacts[i].email,addressBook->contacts[j].email);
							strcpy(addressBook->contacts[j].name,temp1);
							strcpy(addressBook->contacts[j].phone,temp2);
							strcpy(addressBook->contacts[j].email,temp3);

						}
					}
				}

				printf("\nSorted list based on mailID is\n");
				printf("Name\t\t\tPhone number\t\tEmail\n");
				for(int i=0;i<(addressBook->contactCount);i++)
				{
					printf("\n%d. %-20s%s\t\t%s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
					//printf("\n\n");
				}
				break;
			}
		default:
			{
				printf("Please enter a valid choice\n");
				break;
			}
	}
}
//In this function,we initialise contact count to zero and load contacts from file contacts.txt
void initialize(AddressBook *addressBook) 
{
	char str[50];
	addressBook->contactCount = 0;
	loadContactsFromFile(addressBook);
	//` populateAddressBook(addressBook);


}
//In this function,we are saving the contacts to file from the structure
void saveAndExit(AddressBook *addressBook) {
	saveContactsToFile(addressBook); // Save contacts to file
									 //loadContactsFromFile(addressBook);
	exit(EXIT_SUCCESS); // Exit the program
}


//Taking input from the user:Name,mobile number and email.validating them and loading them to structure.
void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
	char str[50],mno[15],mailid[80];int res1,res2,res3,d,a;
label1:printf("Enter the name of the person\n");
	   scanf(" %[^\n]",str);//taking name of the person into str variable
	   res1=validate_name(str);//validating the name
	   if(res1)
	   {
		   strcpy(addressBook->contacts[addressBook->contactCount].name,str);//loading the into a structure variable
		   printf("\nEntered name is %s",addressBook->contacts[addressBook->contactCount].name);



	   }
	   else
		   goto label1;
label2:printf("\nEnter the phone number\n");//taking phone number from user
	   scanf(" %[^\n]",mno);
	   res2=validate_Mno(mno,addressBook);
	   if(res2)
	   {

		   strcpy(addressBook->contacts[addressBook->contactCount].phone,mno);
		   printf("\nEntered phone number is %s",addressBook->contacts[addressBook->contactCount].phone);

	   }
	   else
		   goto label2;
	   if(addressBook->contactCount)
	   {
		   d=duplicate_mnum(mno,addressBook);
		   if(d==0)
		   {
			   //printf("Not a valid mail ID!!!Please Try again\n");
			   printf("Do you wish to continue?\n1.Try with another phone number\n2.Return to main menu\n");
			   scanf("%d",&a);
			   if(a==1)
			   {
				   goto label2;
			   }
			   else return;
		   }
	   }

label3:printf("\nEnter the Email address\n");
	   scanf(" %[^\n]",mailid);
	   //printf("MailID=%s",mailid);
	   res3=validate_mailid(mailid,addressBook);
	   d=duplicate_mail(mailid,addressBook);
	   if(res3==1)
	   {
		   d=duplicate_mail(mailid,addressBook);
		   if(d==0)
		   {
			   printf("Do you wish to continue?\n1.Try with another mailID\n2.Return to main menu\n");
			   scanf("%d",&a);
			   if(a==1)
			   {
				   goto label3;
			   }
			   else 
			   {
				   return;



			   }
		   }
		   strcpy(addressBook->contacts[addressBook->contactCount].email,mailid);
		   printf("\nEntered maild ID is %s",addressBook->contacts[addressBook->contactCount].email);
	   }
	   else goto label3;
	   //d=duplicate_mail(mailid,addressBook);
	   /*if(d==0)
		 {
	   //printf("Not a valid mail ID!!!Please Try again\n");
	   printf("Do you wish to continue?\n1.Try with another mailID\n2.Return to main menu\n");
	   scanf("%d",&a);
	   if(a==1)
	   {
	   goto label3;
	   }

	   }*/
	   printf("\nContact details are successfully created\n");
	   printf("name=%s\nphone number=%s\nemail ID=%s\n",addressBook->contacts[addressBook->contactCount].name,addressBook->contacts[addressBook->contactCount].phone,addressBook->contacts[addressBook->contactCount].email);
	   addressBook->contactCount=addressBook->contactCount+1;
}

//In this function we search the contact either by name or mobile number or mail ID based on the user input and displaying the contact details.In this function also we are validating the details entered

void searchContact(AddressBook *addressBook) 
{
	int ch=0;char name[50],res;char *cptr;int c=0;
	/* Define the logic for search */
	printf("\nPlease enter your choice for searching contact\n1.Name\n2.Mobile number\n3.MailID\n");

	//getchar();
	scanf("%d",&ch);
	getchar();
	switch(ch)
	{
		case 1:
			{
				int c=0,res,a;
label:printf("\nEnter name to be searched\n");
	  //getchar();
	  scanf(" %[^\n]",name);
	  int v=validate_name(name);
	  if(v==0)
	  {
		  //	printf("\nEnter a valid Name\n");
		  goto label;
	  }
	  res=search_name(addressBook,name);
	  if(res==-1)
	  {
		  printf("Entered name is not in database.\nPlease try again!!\n");
		  printf("Do you wish to continue?If yes please enter \n1.Try with another name\n2.Return to main menu\n");
		  scanf("%d",&a);
		  if(a==1)
		  {
			  goto label;
		  }
		  else
			  break;
	  }
	  else
	  {
		  if(strcmp(addressBook->contacts[res].name,name)==0)
		  {
			  printf("\nname=%s",addressBook->contacts[res].name);
			  printf("\nMobile number=%s",addressBook->contacts[res].phone);
			  printf("\nEmail ID=%s",addressBook->contacts[res].email);
			  printf("\n");
		  }
		  else
		  {
			  printf("Entered name with corresponding phone number is not present\n");
			  break;
		  }

	  }
	  break;

			}
		case 2:
			{
				char mno[15];int res,c=0,a;
label1:printf("Enter mobile number\n");
	   scanf(" %[^\n]",mno);
	   //printf("%s",mno);				
	   char *str=mno;
	   while(*str!='\0')
	   {
		   if(*str>='0'&&*str<='9')
		   {
			   //str++;
			   c++;
		   }
		   else
		   {printf("Invalid phone number!!Please try again\n");
			   printf("Do you wish to continue?If yes please enter \n1.Try with another mobile number\n2.Return to main menu\n");
			   scanf("%d",&a);
			   if(a==1)
			   {
				   goto label1;
			   }
			   else
				   break;
		   }
		   //goto label1;}
		   str++;
			}
			if(strlen(mno)>10||c<10)
			{

				printf("Invalid phone number!!\n");
				printf("Do you wish to continue?Please enter your choice\n1.Try with another mobile number\n2.Return to main menu\n");
				scanf("%d",&a);
				if(a==1)
				{
					goto label1;
				}
				else
					break;
			}
			res=search_mnum(addressBook,mno);
			//for(int i=0;i<addressBook->contactCount;i++)
			if(res==-1)
				printf("Entered phone number doesnt exist in the database.Please try with different entry\n");
			else
			{
				printf("\nname=%s",addressBook->contacts[res].name);
				printf("\nMobile number=%s",addressBook->contacts[res].phone);
				printf("\nEmail ID=%s",addressBook->contacts[res].email);
				printf("\n");c++;

			}

			break;
	}
	case 3:
	{
		char mail[50];c=0;int res,a;
label2:printf("Enter emailID\n");
	   //getchar();
	   scanf(" %[^\n]",mail);
	   int v=validate_mailid(mail,addressBook);
	   if(v==0)
	   {
		   printf("Not a valid mail ID\n");
		   printf("Do you wish to continue?\n1.Try with another emailID\n2.Return to main menu\n");
		   scanf("%d",&a);
		   if(a==1)
		   {
			   goto label2;
		   }
		   else
			   break;
	   }
	   res=search_email(addressBook,mail);
	   if(res==-1)
	   {
		   printf("Entered Email doesnt exist in the database.Please try with different entry\n");
		   printf("Do you wish to continue?\n1.Try with another emailID\n2.Return to main menu\n");
		   scanf("%d",&a);
		   if(a==1)
		   {
			   goto label2;
		   }
		   else
			   break;

	   }

	   {
		   printf("\nname=%s",addressBook->contacts[res].name);
		   printf("\nMobile number=%s",addressBook->contacts[res].phone);
		   printf("\nEmail ID=%s",addressBook->contacts[res].email);
		   printf("\n");

	   }


	   break;
	}
	default:
	{
		printf("\nEntered choice is not valid\n");
		break;
	}
}
}

//In this function,on the basis of user input,contact details are edited.If multiple contacts with same name are found,it asks for mobile number and if mobile number is found it updates the contact details based on the user input.Either name or mobile number or phone number.
void editContact(AddressBook *addressBook)
{
	int ch,a,c;
	char name[50], name1[50],mnum[50],mnum1[50],mail[50],mail1[50];int res;
	printf("\nEnter the contact to be edited\n1.Name\n2.MobileNumber\n3.EmailID\n");
	scanf("%d",&ch);
	getchar();
	switch(ch)
	{
		case 1:
			{do{
				   printf("\nEnter the name to be searched\n");
				   scanf(" %[^\n]",name);
				   res=search_name(addressBook,name);
				   if(res==-1){
					   printf("Entered name is not in database.\n");
					   printf("Do you wish to continue?\n1.Try with another name\n2.Return to main menu\n");
					   scanf("%d",&a);
					   if(a!=1)
						   break;
				   }
				   if(res!=-1)
				   {
					   if(strcmp(addressBook->contacts[res].name,name)==0)
					   {
						   printf("\nEnter the contact to be edited\n1.Name\n2.MobileNumber\n3.EmailID\n");
						   scanf("%d",&c);
						   break;
					   }
					   else
					   {
						   printf("There is no entry with coreesponding mobile number and name\n");
						   return;
					   }
				   }

			   }while(a==1);
				   break;

			}
		case 2:
			{
				do{
					printf("\nEnter the phonenumber to be searched\n");
					scanf(" %[^\n]",mnum);
					res=search_mnum(addressBook,mnum);
					if(res==-1){
						printf("Entered phonenumber is not in database.\n");
						printf("Do you wish to continue?\n1.Try with another mobile number\n2.Return to main menu\n");
						scanf("%d",&a);
						if(a!=1)
							break;
					}
					if(res!=-1)
					{
						printf("\nEnter the contact to be edited\n1.Name\n2.MobileNumber\n3.EmailID\n");
						scanf("%d",&c);
						break;
					}

				}while(a==1);
				break;


			}
		case 3:
			{
				do{
					printf("\nEnter the mailID to be searched\n");
					scanf(" %[^\n]",mail);
					res=search_email(addressBook,mail);
					if(res==-1){
						printf("Entered email is not in database.\n");
						printf("Do you wish to continue?\n1.Try with another mailID\n2.Return to main menu\n");
						scanf("%d",&a);
						if(a!=1)
							break;
					}
					if(res!=-1)
					{
						printf("\nEnter the contact to be edited\n1.Name\n2.MobileNumber\n3.EmailID\n");
						scanf("%d",&c);
						break;
					}

				}while(a==1);
				break;
			}
		default:
			{
				printf("Please Enter a valid choice\n");
				return;
				break;
			}
	}
	//char name[50], name1[50],mnum[50],mnum1[50],mail[50],mail1[50];int res;
	switch(c)
	{
		case 1:
			{
label6:printf("Please Enter the name you want to replace in database\n");
	   scanf(" %[^\n]",name1);
	   //		printf("\nreplacement is %s",name1);
	   int v=validate_name(name1);
	   if(v==0)
	   {
		   //printf("\nEnter a valid Name\n");
		   printf("Do you wish to continue?\n1.Try with another name\n2.Return to main menu\n");
		   scanf("%d",&a);
		   if(a==1)
		   {
			   goto label6;
		   }
		   else
			   break;
	   }
	   strcpy(addressBook->contacts[res].name,name1);
	   printf("\nUpdated values of cotact are:\n");
	   printf("\nname=%s",addressBook->contacts[res].name);
	   printf("\nMobile number=%s",addressBook->contacts[res].phone);
	   printf("\nEmail ID=%s",addressBook->contacts[res].email);
	   printf("\n");


	   break;
			}

		case 2:
			{
label4:printf("Please Enter the phone number you want to replace in database\n");
	   scanf(" %[^\n]",mnum);
	   int v=validate_Mno(mnum,addressBook);
	   if(v==0)
	   {
		   printf("Not a valid Phonenumber!!\n");
		   printf("Do you wish to continue?\n1.Try with another phonenumber\n2.Return to main menu\n");
		   scanf("%d",&a);
		   if(a==1)
		   {
			   goto label4;
		   }
		   else
			   break;
	   }
	   int d=duplicate_mnum(mnum,addressBook);
	   if(d==0)
	   {
		   printf("Not a valid Phonenumber!!\n");
		   printf("Do you wish to continue?\n1.Try with another phonenumber\n2.Return to main menu\n");
		   scanf("%d",&a);
		   if(a==1)
		   {
			   goto label4;
		   }
		   else
			   break;
	   }
	   strcpy(addressBook->contacts[res].phone,mnum);
	   printf("\nUpdated values of cotact are:\n");
	   printf("\nname=%s",addressBook->contacts[res].name);
	   printf("\nMobile number=%s",addressBook->contacts[res].phone);
	   printf("\nEmail ID=%s",addressBook->contacts[res].email);
	   printf("\n");

	   break;
			}
		case 3:
			{
label5:printf("Please Enter the emailID you want to replace in database\n");
	   scanf(" %[^\n]",mail);
	   int v=validate_mailid(mail,addressBook);
	   if(v==0)
	   {
		   //printf("Not a valid mail ID!!!Please Try again\n");
		   printf("Do you wish to continue?\n1.Try with another mailID\n2.Return to main menu\n");
		   scanf("%d",&a);
		   if(a==1)
		   {
			   goto label5;
		   }
		   else
			   break;
	   }
	   int d=duplicate_mail(mail,addressBook);
	   if(d==0)
	   {
		   printf("Do you wish to continue?\n1.Try with another mailID\n2.Return to main menu\n");
		   scanf("%d",&a);
		   if(a==1)
		   {
			   goto label5;
		   }
		   else
			   break;
	   }

	   strcpy(addressBook->contacts[res].email,mail);
	   printf("\nUpdated values of cotact are:\n");
	   printf("\nname=%s",addressBook->contacts[res].name);
	   printf("\nMobile number=%s",addressBook->contacts[res].phone);
	   printf("\nEmail ID=%s",addressBook->contacts[res].email);
	   printf("\n");

	   break;

			}

		default:
			{
				printf("Please Enter valid option\n");
				break;
			}
	}
}
//This function is used to delete the contact based on the user input.It takes the input from the user.either name or mobile number or mail ID.search for the contact based on the user input.If it is found,it deletes the contact.If not it prints appropriate error message.

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
	int ch,i,res;char c;
	printf("\nEnter the contact to be deleted\n1.Name\n2.MobileNumber\n3.EmailID\n");
	scanf("%d",&ch);
	getchar();
	char name[50],mnum[50],mail[50];
	switch(ch)
	{
		case 1:
			{
				printf("\nEnter the name to be deleted\n");
				scanf(" %[^\n]",name);
				res= search_name(addressBook,name);
				if(res==-1)
					printf("Entered name is not in database\n.Please try again!!\n");
				else
				{
					if(strcmp(addressBook->contacts[res].name,name)==0)
					{
						printf("\nAre you sure to delete the contact.Please Enter y for Yes and n for No(y/n)");
						getchar();
						scanf("%c",&c);
						printf("%c",c);
						if(c=='n'||c=='N')
						{
							printf("\nYou have opted for not deleting the contact entry.We are returning to main menu\n");
							break;
						}
						if(c=='y'||c=='Y')
						{

							// if(strcmp(addressBook->contacts[res].name,name)==0)
							{

								if(res==addressBook->contactCount)
								{
									addressBook->contactCount=(addressBook->contactCount)-1;
								}
								else
								{
									for(i=res;i<addressBook->contactCount;i++)
									{
										strcpy(addressBook->contacts[i].name,addressBook->contacts[i+1].name);
										strcpy(addressBook->contacts[i].phone,addressBook->contacts[i+1].phone);

										strcpy(addressBook->contacts[i].email,addressBook->contacts[i+1].email);
									}
									addressBook->contactCount=(addressBook->contactCount)-1;
								}
								printf("\nContact successfully Deleted\n");
							}}}
					else 
					{
						printf("There is no matching entry with entered phonenumber\n");
						return;
					}


				}


				break;
			}

		case 2:
			{
				printf("\nEnter the Phone number to be deleted\n");
				scanf(" %[^\n]",mnum);
				res=search_mnum(addressBook,mnum);
				if(res==-1)
					printf("Entered name is not in database.\nPlease try again!!\n");
				else
				{
					printf("\nAre you sure to delete the contact.Please Enter y for Yes and n for No(y/n)\n");
					getchar();                
					scanf("%c",&c);

					if(c=='n'||c=='N')
					{
						printf("\nYou have opted for not deleting the contact entry.We are returning to main menu\n");
						break;
					}
					else{
						if(res==addressBook->contactCount)
						{
							addressBook->contactCount=(addressBook->contactCount)-1;
						}
						else
						{
							for(i=res;i<addressBook->contactCount;i++)
							{
								strcpy(addressBook->contacts[i].name,addressBook->contacts[i+1].name);
								strcpy(addressBook->contacts[i].phone,addressBook->contacts[i+1].phone);
								strcpy(addressBook->contacts[i].email,addressBook->contacts[i+1].email);
							}
							addressBook->contactCount=(addressBook->contactCount)-1;

						}
						printf("\nContact successfully Deleted\n");
					}


				}
				break;
			}
		case 3:
			{
				printf("\nEnter the email to be deleted\n");
				scanf(" %[^\n]",mail);
				res=search_email(addressBook,mail);
				if(res==-1)
					printf("Entered name is not in database.\nPlease try again!!\n");
				else
				{
					printf("\nAre you sure to delete the contact.Please Enter y for Yes and n for No(y/n)\n");
					getchar();
					scanf("%c",&c);
					if(c=='n'||c=='N')
					{
						printf("\nYou have opted for not deleting the contact entry.We are returning to main menu\n");
						break;
					}
					else
					{
						if(res==addressBook->contactCount)
						{
							addressBook->contactCount=addressBook->contactCount-1;
						}
						else
						{
							for(i=res;i<addressBook->contactCount;i++)
							{
								strcpy(addressBook->contacts[i].name,addressBook->contacts[i+1].name);
								strcpy(addressBook->contacts[i].phone,addressBook->contacts[i+1].phone);
								strcpy(addressBook->contacts[i].email,addressBook->contacts[i+1].email);
							}
							addressBook->contactCount=addressBook->contactCount-1;
						}
						printf("\nContact successfully deleted\n");
					}
				}
				break;
			}
		default:
			{
				printf("Please enter a valid option\n");
				break;
			}
	}
}

//This function validates the name given by the user.It takes only uppercase,lowercase,space and dot.It not it returns 0 which indicates invalid name.
int validate_name(char *str)
{
	//printf("%s",str);
	while(*str!='\0')
	{
		if((*str>='a'&&*str<='z')||(*str>='A'&&*str<='Z')||(*str=='.'||*str==' ')){}
		else 
		{
			printf("\nEntered name is invalid.Please Enter a valid Name\n");
			return 0;
		}
		str++;
	}

	//printf("\nEntered name is valid\n");
	return 1;
}
//This function validates the phone number given by the user.It takes only numbers and only 10 digits.It not it returns 0 which indicates invalid mobile number
int validate_Mno(char *str,AddressBook *addressBook)
{
	int c=0,i,res;char *dstr=str;
	//printf("count is %d",addressBook->contactCount);
	if(addressBook->contactCount!=0)
	{
label: while(*str!='\0')
	   {
		   if(*str>='0'&&*str<='9')
			   c++;
		   str++;
	   }
	   if(c>10||c<10)
	   {
		   printf("\nPhone number should contain 10 digits!!\n");
		   return 0;

	   }
	   return 1;
	}
	goto label;
}
int duplicate_mnum(char *dstr,AddressBook *addressBook)
{
	for(int i=0;i<addressBook->contactCount;i++)
	{
		//	printf("\nphone=%s",addressBook->contacts[i].phone);
		if(strcmp(dstr,addressBook->contacts[i].phone)==0)
		{
			printf("\nYou have entered a mobile number which already exists in database.\n");
			return 0;
		}
	}
	//goto label;
}
//This function validates the mailID given by the user.It should contain only one @ and first character should not be @.ALso it validates if .com ,domain is present in mail ID or not .If not it returns 0 which indicates invalid mail.It also validates if any consecutive . or - are present in mail.
int validate_mailid(char *str,AddressBook *addressBook)
{
	int c=0;char *cptr;char *dstr=str;
	if(*str==64)
	{
		printf("Mail should not start with @");
		return 0;
	}
	cptr=strstr(str,".com");
	if(cptr==NULL)
	{
		printf("\nThere is no .com in entered mail-id!!\n");
		return 0;
	}
	else if(strcmp(cptr,".com")!=0)
	{
		printf("\nInvalid mail-id!!\n");
		return 0;
	}
	while(*str!='\0')
	{
		if((*str>='a'&&*str<='z')||(*str>='A'&&*str<='Z')||(*str=='.')||(*str>='0'&&*str<='9')||(*str=='_')||(*str==64)||(*str==92))
		{
			if((*str=='.')&&(*(str+1)=='.'))
			{
				printf("\nThere are consecutive '.' in entered mail ID. \n");
				return 0;}
			if((*str=='_')&&(*(str+1)=='_'))
			{printf("\nThere are consecutive '_'s in entered mail ID.\n");
				return 0;}
			if((*str==92)&&(*(str+1)==92))
			{return 0;}
			if(*str==64)
			{
				if(*(str+1)=='.')
				{
					printf("\nThere is no domain name in entered mail-id.\n");
					return 0;
				}
				c++;
			}
		}
		else return 0;
		str++;
	}
	if(c!=1)
	{
		printf("\nThere should be one @ in mail ID and not more than that.\n");
		return 0;
	}

	return 1;
}

//This function validates if any duplicate mailID is present in database.
int duplicate_mail(char *dstr,AddressBook *addressBook)
{int c=0;
	for(int i=0;i<addressBook->contactCount;i++)
	{
		//        printf("\nphone=%s",addressBook->contacts[i].email);
		if(strcmp(dstr,addressBook->contacts[i].email)==0)
		{
			printf("\nDuplicate entry found.Please check\n");
			return 0;
		}
	}
	return 1;
}

//This function searches for name present in database or not.It also validates if multiple entries are present with same name.If yes,it displays the contacts and asks for validation with phone number.
int search_name(AddressBook *addressBook,char *name)
{
	char *cptr;int c=0,res,st;char mnum[20];Contact temp[addressBook->contactCount];int i,j=0;
	for(int i=0;i<addressBook->contactCount;i++)
	{
		cptr=strcasestr(addressBook->contacts[i].name,name);
		if(cptr==NULL)
		{
			continue;
		}
		//printf("\ncptr=%s",cptr);
		//printf("\nname=%s",name);
		//return i;
		if(strcasecmp(addressBook->contacts[i].name,cptr)==0)
		{
			c++;
			st=i;
		}
	}if(c==1)
	{
		return st;

	}
	else if(c==0)
	{
		return -1;
	}
	else if(c>1) 
	{
		printf("There are multiple entries with same name\n");
		for(int i=0;i<addressBook->contactCount;i++)
		{
			cptr=strcasestr(addressBook->contacts[i].name,name);
			if(cptr==NULL)
			{
				continue;
			}
			//printf("\ncptr=%s",cptr);
			//printf("\nname=%s",name);
			//return i;
			if(strcasecmp(addressBook->contacts[i].name,cptr)==0)
			{
				temp[j]=addressBook->contacts[i];
				j++;
				printf("%s\n",addressBook->contacts[i].name);
				printf("%s\n",addressBook->contacts[i].phone);
				printf("%s\n",addressBook->contacts[i].email);

			}
		}
		printf("\n\n");
		//for(i=0;i<j;i++)

		//	printf("%s\n",temp[i].phone);

		//		printf("");
		printf("Please enter mobile number to be searched\n");
		scanf(" %[^\n]",mnum);
		int v=validate_Mno(mnum,addressBook);
		if(v==0)
		{
			printf("Not a valid Phonenumber!!\n");
			return 0;
		}
		int k=0;
		for(i=0;i<j;i++)
		{
			if((strcmp(mnum,temp[i].phone))==0);
			//res=search_mnum(addressBook,mnum);
			{
				k++;
			}
		}
		if(k==0)
		{
			printf("\nThe entered mobile number is not from the above list\n");
			return -1;
		}
		else 
		{
			res=search_mnum(addressBook,mnum);
			if(res==-1)
				return -1;
			else return res;
		}
		return -1;
	}
}

//This function searches the database with entered mobile number.It is used in searching,editing and deleting the contact.
int search_mnum(AddressBook *addressBook,char *mno)
{
	for(int i=0;i<addressBook->contactCount;i++)
	{
		if(strcmp(mno,addressBook->contacts[i].phone)==0)
			return i;
	}
	return -1;
}
//This function searches the database with entered mailID.It is used in searching,editing and deleting the contact.
int search_email(AddressBook *addressBook,char *email)
{
	 for(int i=0;i<addressBook->contactCount;i++)
        {
        if(strcmp(email,addressBook->contacts[i].email)==0)
                return i;
        }
       return -1;
}
