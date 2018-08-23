#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>

int reg(int client_number);
int login(int client_username, int client_password, int client_number, int client_verify);
int client_view(int client_number);
int client_notification(int client_number);
int client_modify(int client_number);
int client_notifications(int client_number);
int client_modify(int client_number);
//int check_isint(char input[], int client_number, int limit);
int admin_view(int client_number);
int admin_search(char search_char[2]);
int admin_delete(char client_delete_surname[50]);
int admin_notify(char client_notify_surname[50]);
int admin_gift(int gift_afm);
int admin_sort(int client_initial_deposit, int client_birth_year);



struct client
{
	int  client_id;
	char client_name[50];
	char client_surname[50];
	int	 birth_year;
	int afm;
	float  initial_deposit;
	float  after_tax_deposit;
	char date[150];
};

struct  client client_array[5];

int main() {



	int i = 0;
	int client_verify = 0 ;
	int client_number = 0 ;
	int quarter_align, third_align, center_align, len;
	char sign_in_choice[6];
	char start_screen_title[] = "Start Screen";
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
	int admin_result, client_result, number_of_clients;
	int x = 0;
	int c = 0; 
	int a = 0;
	int l = 0;
	char client_choice[10];
	int client_username, client_password;
	int temp;
	int client_choice_log_in, client_choice_register; 
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
				printf("Username:\n");
				scanf("%s", admin_username);
				printf("Password: \n");
				scanf("%s", admin_password);
				admin_username_input = strcmp(admin_username,"t");
				admin_password_input = strcmp(admin_password,"t");
				if(admin_username_input == 0 && admin_password_input == 0)
				{//START OF ADMIN PAGE
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
							admin_view(client_number);					
						}
						if(admin_choice_search == 0)
						{
							admin_search(search_char);
						}
						if(admin_choice_delete == 0)
						{
							admin_delete(client_delete_surname);
						}
						if(admin_choice_notify == 0)
						{
							admin_notify(client_notify_surname);					
						}
						if(admin_choice_gift == 0)
						{
							admin_gift(gift_afm);
						}
						if(admin_choice_sort == 0)
						{
							admin_sort(client_initial_deposit, client_birth_year);
						}	
						
						}
					}
		}//END OF ADMIN PAGE
		if(client_result == 0)
		{	
			while(c == 0)
			{
			//START OF CLIENT PAGE
//				if(client_number <= 4)
//				{
					printf("Welcome to Client Page\n");
					printf("Register or Log in?\n");
					scanf("%s",client_choice);
					client_choice_log_in = strcmp(client_choice,"Login");
					client_choice_register = strcmp(client_choice,"Register");					
					if(client_choice_register == 0)
					{
					// REGISTER
						while(client_number < 5)
						{							

//							printf("Register or Login?\n");
//							scanf("%s",client_choice);
//							client_choice_log_in = strcmp(client_choice,"Login");
//							client_choice_register = strcmp(client_choice,"Register");
							if(client_choice_log_in == 0){
								break;
							}
							if(client_choice_register == 0){
								reg(client_number);	
								client_number++;
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
						l = login(client_username, client_password, client_number, client_verify);
							if(l != -1)
							{					
							// PERSONAL CLIENT PAGE
							printf("View Profile\t View Notifications\t");
							printf("Modify Information\t Exit\n");
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
//							int client_choice_view, client_choice_notification ,client_choice_modify;
//							client_view(l);
							// END OF PERSONAL CLIENT PAGE
//								c++;
							}
							else
							{
							 printf("No record found\n");
							}
					}//END OF LOG IN RETURN TO CLIENT PAGE				
//					else
//					{
//					printf("Invalid input.Please try again.\n");
//					scanf("%s",client_choice);
//					client_choice_log_in = strcmp(sign_in_choice,"Login");
//					client_choice_register = strcmp(sign_in_choice,"Register");
//					}
			}//END OF WHILE C LOOP
			
		}// END OF CLIENT PAGE
//x++;
}//END OF WHILE X LOOP

getch();
return 0;
}

int reg(client_number)
{
//	char *str;
//	char input[50];
	int i = client_number;
	if(i<5){
	printf("Please fill the form below\n");
	client_array[i].client_id = i ;
    printf("Enter your name: \n");
    scanf("%s", client_array[i].client_name);
    printf("Enter your surname: \n");
    scanf("%s", client_array[i].client_surname);
    printf("Enter your year of birth: \n");
    scanf("%d", &client_array[i].birth_year);
    printf("Enter your 5 digit afm: \n");
//    scanf("%s", input);
//	check_isint(input, i, 5);
	scanf("%d", &client_array[i].afm);
    printf("Initial Deposit: \n");
    scanf("%f", &client_array[i].initial_deposit);
    client_array[i].after_tax_deposit = client_array[i].initial_deposit - 0.05*client_array[i].initial_deposit;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(client_array[i].date, sizeof(client_array[i].date), "%A %d %B %Y %H:%M:%S %p %Z", tm);
	}else{
	printf("Maximum number of clients registered!");
	}
return 0;
}

//int check_isint(char input[],int client_number, int limit)
//{	
//	int i = client_number;
//	int length = strlen(input);
//    int dig = 0;
//    printf("\nLimit is : %d", limit);
//    printf("\nLength is: %d", length);
//    while(length != 5)
//	{
//		printf("\nWrong number of digits.Please enter 5 digit afm\n");
//		scanf("%s", input);
//		length = strlen(input);
//    }
//
//	return 0;
//}

int login(client_username, client_password, client_number, client_verify)
{
	int z = client_number;
	int x ;
	int username = client_username;
	int password = client_password;


	for(x=0; x<5; x++)
		{
	     if(client_array[x].afm ==  username && client_array[x].birth_year == password  )
	     {
			printf("Successful Login!\n");
			return x;
	     }
		}

return -1;
}


int client_view(int client_number)
{
	int	i = client_number;
	printf("\nName:\t Surname:\t Afm:\t");
	printf("\n%s \t %s \t %d", client_array[i].client_name,client_array[i].client_surname,client_array[i].afm);
	printf("\nInitial Deposit: %0.1f",client_array[i].initial_deposit);
	printf("\nAfter Tax Deposit: %0.1f",client_array[i].after_tax_deposit);
	printf("\nDate of registration:");
	printf("%s\n", client_array[i].date);
	return 0;
}

int client_modify(int client_number)
{
	int i = client_number;
	int choice;
	printf("\nName:\t Surname:\t Afm:\t Birth Year:\t");
	printf("\n%s \t %s \t %d \t %d \t\n", client_array[i].client_name,client_array[i].client_surname,client_array[i].afm,client_array[i].birth_year);
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
		printf("Your current Surname is : %s\n", client_array[i].client_surname);
		printf("Please enter your desired new surname\n");
		scanf("%s", client_array[i].client_surname);
		time_t t = time(NULL);
    	struct tm *tm = localtime(&t);
    	strftime(client_array[i].date, sizeof(client_array[i].date), "%A %d %B %Y %H:%M:%S %p %Z", tm);
		choice = 0;
		}
		else if(choice == 2)
		{
		printf("Your current Name is : %s\n", client_array[i].client_name);
		printf("Please enter your desired new name\n");
		scanf("%s", client_array[i].client_surname);
		time_t t = time(NULL);
    	struct tm *tm = localtime(&t);
    	strftime(client_array[i].date, sizeof(client_array[i].date), "%A %d %B %Y %H:%M:%S %p %Z", tm);
		choice = 0;
		}
		else if(choice == 3)
		{
		printf("Your current Birth year is : %d\n", client_array[i].birth_year);
		printf("Please enter your desired new birth year\n");
		scanf("%d", &client_array[i].birth_year);
		time_t t = time(NULL);
   		 struct tm *tm = localtime(&t);
    	strftime(client_array[i].date, sizeof(client_array[i].date), "%A %d %B %Y %H:%M:%S %p %Z", tm);
		choice = 0;
		}
		else if(choice == 4)
		{
		printf("Your current Afm is : %d\n", client_array[i].afm);
		printf("Please enter your desired new afm\n");
		scanf("%d", &client_array[i].afm);
		time_t t = time(NULL);
    	struct tm *tm = localtime(&t);
    	strftime(client_array[i].date, sizeof(client_array[i].date), "%A %d %B %Y %H:%M:%S %p %Z", tm);
		choice = 0;
		}
		else
		{
		printf("Invalid Input");		
		}
return 0;
}


int client_notifications(int client_number)
{
	int i = client_number;
}

int admin_view(int client_number)
{
	int	i = client_number;
	int x ;
	for(x=0; x<5; x++)
		{
			printf("\nName:\t Surname:\t Afm:\t");
			printf("\n%s \t %s \t %d", client_array[x].client_name,client_array[x].client_surname,client_array[x].afm);
			printf("\nBirth Year: %0.1f",client_array[x].initial_deposit);
			printf("\nInitial Deposit: %0.1f",client_array[x].initial_deposit);
			printf("\nAfter Tax Deposit: %0.1f",client_array[x].after_tax_deposit);
			printf("\nDate of registration:");
			printf("%s\n", client_array[x].date);
//	     if(client_array[x].afm ==  username && client_array[x].birth_year == password  )
//	     {
//			printf("Successful Login!\n");
//			return x;
//	     }
		}

	return 0;
}

int admin_search(char search_char[2])
{
	
}
int admin_delete(char client_delete_surname[50])
{
	
}
int admin_notify(char client_notify_surname[50])
{
	
}
int admin_gift(int gift_afm)
{
	
}
int admin_sort(int client_initial_deposit, int client_birth_year)
{
	
}
