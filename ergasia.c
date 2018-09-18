#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>

int current_client_number;
int current_alerts_number;
int client_reg(int client_number);
int client_login(int client_username, int client_password, int client_number);
int client_view(int client_number);
int client_notification(int client_number);
int client_notifications(int client_number);
int client_modify(int client_number);
int admin_view(int current_client_number);
int admin_search();
int admin_delete();
int admin_notify();
int admin_gift();
int admin_sort();



struct alerts
{
	char notification[5];
	char surname[50];	
	int alert_id;
	int client_id;
	char date[150];
}client_notify[10];



struct client
{
	int  client_id;
	char client_name[50];
	char client_surname[50];
	int	 birth_year;
	int afm;
	int  initial_deposit;
	int  after_tax_deposit;
	char date[150];
}client[5], temp;

struct  client 	client[5];

int main() {


	int i = 0;
	int client_number = 0 ;
	int quarter_align, third_align, center_align, len;
	char sign_in_choice[6];
	char start_screen_title[] = "Start Screen";
	// ALIGN TEXT IN TERMINAL
	HANDLE Output = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Coordinates = {120, 100};
    SetConsoleScreenBufferSize(Output, Coordinates);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int ret;
	ret = GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE ),&csbi);
	int cols=csbi.dwSize.X;
	len = strlen(start_screen_title);
	quarter_align = ((len+cols)/4);
	third_align = ((len+cols)/3);
	center_align = ((len+cols)/2);	
	char sign_in[] = "Log In As";
	len = strlen(sign_in);
	center_align = ((len+cols)/2);	
	char choice[] = "Admin Client";
	len = strlen(choice);
	center_align = ((len+cols)/2);
	// ALIGN TEXT IN TERMINAL	
	int admin_result, client_result, number_of_clients;
	int x = 0;
	int c = 0; 
	int a = 0;
	int l = 0;
	char client_choice[10];
	int client_username, client_password;
	int temp;
	int client_choice_log_in, client_choice_register, client_choice_exit;
	int client_choice_view, client_choice_notification ,client_choice_modify;
	char admin_username[5], admin_password[4], admin_choice[10];
	int admin_username_input, admin_password_input, admin_choice_view, admin_choice_search;
	int admin_choice_delete, admin_choice_notify, admin_choice_gift, admin_choice_sort;
	int admin_choice_exit;
	char search_char[2];
	char client_delete_surname[50]; 
	char client_notify_surname[50];
	int gift_afm, client_initial_deposit, client_birth_year;

while(x == 0)
{	
	printf("%*s\n", center_align, "Start Screen");
	printf("%*s\n", center_align, "Log In As");
	printf("%*s\n", center_align, "Admin Client");
	printf("\n");	
	scanf("%s",sign_in_choice);
	admin_result = strcmp(sign_in_choice,"Admin");
	client_result = strcmp(sign_in_choice,"Client");
		if(admin_result == 0)
		{

				c = 0;
				printf("Username:\n");
				scanf("%s", admin_username);
				printf("Password: \n");
				scanf("%s", admin_password);
				admin_username_input = strcmp(admin_username,"trap");
				admin_password_input = strcmp(admin_password,"22t");
				if(admin_username_input == 0 && admin_password_input == 0)
				{//START OF ADMIN PAGE
					a = 0;
					while(a == 0)
					{
						printf("Welcome to Admin Page\n");
						printf("View\tSearch\tDelete\t");
						printf("Notify\tGift\tSort\tExit\n");
						scanf("%s",admin_choice);
						admin_choice_view 	= strcmp(admin_choice,"View");
						admin_choice_search = strcmp(admin_choice,"Search");
						admin_choice_delete = strcmp(admin_choice,"Delete");
						admin_choice_notify = strcmp(admin_choice,"Notify");
						admin_choice_gift   = strcmp(admin_choice, "Gift");
						admin_choice_sort	= strcmp(admin_choice, "Sort");
						admin_choice_exit	= strcmp(admin_choice, "Exit");
		
						if(admin_choice_view == 0)
						{
							admin_view(current_client_number);					
						}
						if(admin_choice_search == 0)
						{
							admin_search();
						}
						if(admin_choice_delete == 0)
						{
							admin_delete();
						}
						if(admin_choice_notify == 0)
						{
							current_alerts_number++;
							admin_notify();		
										
						}
						if(admin_choice_gift == 0)
						{
							admin_gift();
						}
						if(admin_choice_sort == 0)
						{
							admin_sort();							
						}	
						
						if(admin_choice_exit == 0)
						{
						a++;
						}	
					}
						
					}
		}//END OF ADMIN PAGE
		if(client_result == 0)
		{	
			c = 0;
			a = 0;
			while(c == 0)
			{
			//START OF CLIENT PAGE
					printf("Welcome to Client Page\n");
					printf("Register Log in or Exit?\n");
					scanf("%s",client_choice);
					client_choice_log_in = strcmp(client_choice,"Login");
					client_choice_register	= strcmp(client_choice,"Register");	
					client_choice_exit		= strcmp(client_choice, "Exit");				
					if(client_choice_register == 0)
					{
					// REGISTER
						while(client_number < 5)
						{							

							if(client_choice_log_in == 0){
								break;
							}
							if(client_choice_register == 0){
								client_reg(client_number);	
								client_number++;
								current_client_number++;
								break;						
							}
							if(client_choice_log_in !=0 && client_choice_register != 0){
								printf("Invalid Input.Try again.\n");
								break;
							}						
						}
					}// END OF REGISTER
					if(client_choice_log_in == 0)
					{
					//LOG IN
						printf("Please enter your credentials\n");
						printf("Enter your afm:\n");
						scanf("%d", &client_username);
						printf("Enter your year of birth:\n");
						scanf("%d", &client_password);
						l = client_login(client_username, client_password, client_number);
							if(l != -1)
							{					
							// PERSONAL CLIENT PAGE
							printf("View Profile\t Notifications\t");
							printf("Modify \t Exit\n");
							scanf("%s",client_choice);
							client_choice_view = strcmp(client_choice,"View");
							client_choice_notification = strcmp(client_choice,"Notifications");
							client_choice_modify = strcmp(client_choice,"Modify");
								if(client_choice_view == 0)
								{
									client_view(l);					
								}
								if(client_choice_notification == 0)
								{
									client_notifications(l);
								}
								if(client_choice_modify == 0)
								{
									client_modify(l);
								}

							}
							else
							{
							 printf("No record found\n");
							}
					}//END OF LOG IN RETURN TO CLIENT PAGE	
					if(client_choice_exit == 0){
						c++;
					}			

			}//END OF WHILE C LOOP
			
		}// END OF CLIENT PAGE

}//END OF WHILE X LOOP

getch();
return 0;
}

int client_reg(client_number)// DONE
{
	int i = client_number;
	if(i<5){
	printf("Please fill the form below\n");
	client[i].client_id = i ;
    printf("Enter your name: \n");
    scanf("%s", client[i].client_name);
    printf("Enter your surname: \n");
    scanf("%s", client[i].client_surname);
    printf("Enter your year of birth: \n");
    scanf("%*[^0-9] %d", &client[i].birth_year);
    printf("Enter your 5 digit afm: \n");
	scanf("%*[^0-9] %d", &client[i].afm);
	while(client[i].afm <= 9999 || client[i].afm >= 100000 )
	{
		printf("Invalid afm.Please renter 5 digit afm: \n");
		scanf("%*[^0-9] %d", &client[i].afm);
		
	}
    printf("Initial Deposit: \n");
    scanf("%*[^0-9] %d", &client[i].initial_deposit);
    client[i].after_tax_deposit = client[i].initial_deposit - 0.05*client[i].initial_deposit;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(client[i].date, sizeof(client[i].date), "%A %d %B %Y %H:%M:%S %p %Z", tm);
	}else{
	printf("Maximum number of clients registered!");
	}
return 0;
}


int client_login(client_username, client_password, client_number)// DONE
{
	int z = client_number;
	int x ;
	int username = client_username;
	int password = client_password;


	for(x=0; x<5; x++)
		{
	     if(client[x].afm ==  username && client[x].birth_year == password  )
	     {
			printf("Successful Login!\n");
			return x;
	     }
		}

return -1;
}


int client_view(int client_number)// DONE
{
	int	i = client_number;
	printf("\nName: %s\t Surname: %s\t Afm: %d\t Birth Year: %d \t", client[i].client_name,client[i].client_surname,client[i].afm,client[i].birth_year);
	printf("\nInitial Deposit: %d",client[i].initial_deposit);
	printf("\nAfter Tax Deposit: %d",client[i].after_tax_deposit);
	printf("\nDate of registration:");
	printf("%s\n", client[i].date);
	return 0;
}

int client_modify(int client_number)// DONE
{
	int i = client_number;
	int choice;
	printf("\nName: %s\t Surname: %s\t Afm: %d\t Birth Year: %d \t", client[i].client_name,client[i].client_surname,client[i].afm,client[i].birth_year);
	printf("Select which field to modify\n");
	printf("Press 1 to modify Surname\n");
	printf("Press 2 to modify Name\n");
	printf("Press 3 to modify Birth year\n");
	printf("Press 4 to modify afm\n");
	choice = 0;
	scanf("%d", &choice);
	printf("choice %d\n",choice);
		if(choice == 1)
		{
		printf("Your current Surname is : %s\n", client[i].client_surname);
		printf("Please enter your desired new surname\n");
		scanf("%s", client[i].client_surname);
		time_t t = time(NULL);
    	struct tm *tm = localtime(&t);
    	strftime(client[i].date, sizeof(client[i].date), "%A %d %B %Y %H:%M:%S %p %Z", tm);
		choice = 0;
		}
		else if(choice == 2)
		{
		printf("Your current Name is : %s\n", client[i].client_name);
		printf("Please enter your desired new name\n");
		scanf("%s", client[i].client_surname);
		time_t t = time(NULL);
    	struct tm *tm = localtime(&t);
    	strftime(client[i].date, sizeof(client[i].date), "%A %d %B %Y %H:%M:%S %p %Z", tm);
		choice = 0;
		}
		else if(choice == 3)
		{
		printf("Your current Birth year is : %d\n", client[i].birth_year);
		printf("Please enter your desired new birth year\n");
		scanf("%d", &client[i].birth_year);
		time_t t = time(NULL);
   		struct tm *tm = localtime(&t);
    	strftime(client[i].date, sizeof(client[i].date), "%A %d %B %Y %H:%M:%S %p %Z", tm);
		choice = 0;
		}
		else if(choice == 4)
		{
		printf("Your current Afm is : %d\n", client[i].afm);
		printf("Please enter your desired new afm\n");
		scanf("%d", &client[i].afm);
		while(client[i].afm <= 9999 || client[i].afm >= 100000 )
	    {
	    	printf("Invalid afm.Please renter 5 digit afm: \n");
	    	scanf("%*[^0-9] %d", &client[i].afm);
	    }
		time_t t = time(NULL);
    	struct tm *tm = localtime(&t);
    	strftime(client[i].date, sizeof(client[i].date), "%A %d %B %Y %H:%M:%S %p %Z", tm);
		choice = 0;
		}
		else
		{
		printf("Invalid Input");		
		}
return 0;
}


int client_notifications(int client_number)// DONE
{
	int i = client_number;
	int y = current_alerts_number;
	int x, s;

			for(x = 0; x < y; x++)
			{
				s = strcmp(client_notify[x].surname, client[i].client_surname);
//				if(s == 0 && client_notify[x].alert_id != 0)
				if(s == 0)
			{
			printf("Your notifications are : %s \n", client_notify[x].notification);	
			printf("client_notify date is : %s \n", client_notify[x].date);
			}
			}
}

int admin_view(int current_client_number)// DONE
{
	int	i = current_client_number;
	int x ;
	int y = 0;
	int z ;
	for(x=0; x < i; x++)
		{
			printf("\nName: %s\t Surname: %s\t Afm: %d\t", client[x].client_name,client[x].client_surname,client[x].afm);
			printf("\nBirth Year: %d",client[x].initial_deposit);
			printf("\nInitial Deposit: %d",client[x].initial_deposit);
			printf("\nAfter Tax Deposit: %d",client[x].after_tax_deposit);
			printf("\nDate of registration:");
			printf("%s\n", client[x].date);
			z = client[x].initial_deposit;
			if(z > 150 )
			{
				y = y + 1;
			}
		}
	
	printf("\nTotal Number of Clients is : %d\n", current_client_number);
	printf("Total Clients with more than 150 euros in deposit : %d\n", y);
	return 0;
}

int admin_search()// DONE
{

	int	i = current_client_number;
	int x = 0;
	int y = 0;
	printf("Enter character to search\n");

	char search_char[2];
	getchar();
	scanf("%c", &search_char);
	int s;

   for(x = 0; x < i; x++)
   {	
   		s = strncmp (search_char, client[x].client_surname, 1);

	    if (s == 0) 
		{
			printf("Found match\n");
			printf("Matched surname is: %s\n", client[x].client_surname);
			printf("Matched name is: %s\n", client[x].client_name);
			printf("Matched birth year is: %d\n", client[x].birth_year);
			printf("Matched afm  is: %d\n", client[x].afm);
	    }
	}
	

    return 0;	
}


int admin_delete()// DONE
{
	int i = current_client_number;
	int x = 0;
	int y = 0;
	char search_surname[50];
	int s;
	char delete_choice[4];
	int delete_input;
	while(y != 1)
	{
		printf("Enter surname to search\n");	
		scanf("%s", search_surname);
			
			for(x = 0; x < i; x++)
			{						
					s = strcmp(search_surname, client[x].client_surname);
					if (s == 0)
					{
						printf("Are you sure you want to delete?\n");
						printf("Yes or No?\n");
						scanf("%s", delete_choice);
						printf("%s\n", delete_choice);
						delete_input = strcmp(delete_choice,"Yes");
							if (delete_input == 0)
							{
			
								client[x].client_id = -1 ;
								strcpy(client[x].client_name, "-1");
								strcpy(client[x].client_surname, "-1");
								client[x].birth_year = -1;
								client[x].afm = -1 ;
							    client[x].initial_deposit = -1 ;
							    client[x].after_tax_deposit = -1 ;
							    strcpy(client[x].date, "-1");
							    y = 1;
							}
					
					}
	
			}
	}
return 0;
}

int admin_notify()// DONE
{
	int i = current_client_number;
	int y = current_alerts_number;
	int x, s, o, p;
	char message[5];
	char option_ok[5] = "OK";
	char option_prob[5] = "PROB";
	char search_surname[50];
	time_t t = time(NULL);
    struct tm *tm = localtime(&t);
	printf("Enter surname to notify:\n");
	scanf("%s", search_surname);
	
			for(x = 0; x < i; x++)
			{						
					s = strcmp(search_surname, client[x].client_surname);
					 
					if (s == 0)
					{
						printf("Select notify messsage:\n");
						scanf("%s", message);
						o = strcmp(message,option_ok);			
						if(o == 0)
						{
						strcpy(client_notify[x].surname, search_surname);
						strcpy(client_notify[x].notification,option_ok);						
						client_notify[x].client_id = client[x].client_id;	
						client_notify[x].alert_id = y;	
						strftime(client_notify[x].date, sizeof(client_notify[x].date), "%A %d %B %Y %H:%M:%S %p %Z", tm);						
						}
						p = strcmp(message,option_prob);
						if( p == 0)
						{
						strcpy(client_notify[x].surname, search_surname);
						strcpy(client_notify[x].notification,option_prob);
						client_notify[x].client_id = client[x].client_id;
						client_notify[x].alert_id = y;	
						strftime(client_notify[x].date, sizeof(client_notify[x].date), "%A %d %B %Y %H:%M:%S %p %Z", tm);
						}	
					
					}
	
			}
			for(x = 0; x < y; x++)
			{
				s = strcmp(client_notify[x].surname, client[x].client_surname);
				if(s == 0 && client_notify[x].alert_id != 0)
			{
			printf("client_notify notification is : %s \n", client_notify[x].notification);
			printf("client_notify surname is : %s \n", client_notify[x].surname);	
			}
			}
	return 0;
}
int admin_gift()// DONE
{

	int	i = current_client_number;
	int x = 0;
	int y = 0;
	
	printf("Enter a number from 0 to 9\n");
	scanf("%*[^0-9] %d", &y);
	char gift_afm[2];
	char temp[10];
	sprintf(gift_afm,"%d",y);
	int s;
	
	
   for(x = 0; x < i; x++)
   {	
   		sprintf(temp,"%d",client[x].afm);
   		s = strncmp (gift_afm, temp, 1);

	    if (s == 0) 
		{
		client[x].after_tax_deposit = client[x].after_tax_deposit + 50;
	    }
	}

}

int admin_sort()// DONE
{
	int i, j, n;
	n = current_client_number;
	char sort_by_choice[10];
	int  sort_by_deposit, sort_by_year;
	printf("Sort by Deposit or Year?");
	scanf("%s",sort_by_choice);
	sort_by_deposit = strcmp(sort_by_choice,"Deposit");
	sort_by_year	= strcmp(sort_by_choice,"Year");
	if(sort_by_deposit == 0)
	{
	printf("Descending order according deposit\n");
	for (i = 1; i < n; i++)
      for (j = 0; j < n - i; j++) 
	  {
         if (client[j].initial_deposit < client[j+1].initial_deposit)
		 {
            temp = client[j];
            client[j] = client[j+1];
            client[j+1] = temp;

         }
      }
	
	   for (i = 0; i < n; i++)
	   	{
			printf("Surname          : %s\n", client[i].client_surname);	
			printf("Name             :%s\n", client[i].client_name);
			printf("Birth year       : %d\n", client[i].birth_year);
			printf("Afm              :%d\n", client[i].afm);
			printf("Deposit          : %d\n", client[i].initial_deposit);
			printf("After tax deposit: %d\n", client[i].after_tax_deposit);
   		}

   }	
	
	
	if(sort_by_year == 0)
	{
	printf("Descending order according year\n");
	for (i = 1; i < n; i++)
      for (j = 0; j < n - i; j++) 
	  {
         if (client[j].birth_year < client[j+1].birth_year)
		 {
            temp = client[j];
            client[j] = client[j+1];
            client[j+1] = temp;

         }
      }
	
	   for (i = 0; i < n; i++)
	   	{
      		printf("Surname          : %s\n", client[i].client_surname);	
			printf("Name             :%s\n", client[i].client_name);
			printf("Birth year       : %d\n", client[i].birth_year);
			printf("Afm              :%d\n", client[i].afm);
			printf("Deposit          : %d\n", client[i].initial_deposit);
			printf("After tax deposit: %d\n", client[i].after_tax_deposit);
   		}

   }
}
