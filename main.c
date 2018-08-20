#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int reg(int client_number);
int login(int client_username, int client_password, int client_number, int client_verify);
int personal_page(int client_number);



struct client
{
	int  client_id;
	char client_name[50];
	char client_surname[50];
	int	 birth_year;
	int  afm;
	float  initial_deposit;
	float  after_tax_deposit;
	char datep[50];
};

struct  client client_array[5];

int main() {

	int i;
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
	printf("%*s\n", center_align, "Start Screen");
	char sign_in[] = "Log in as";
	len = strlen(sign_in);
	center_align = ((len+cols)/2);
	printf("%*s\n", center_align, "Log in as");
	char choice[] = "Admin Client";
	len = strlen(choice);
	center_align = ((len+cols)/2);
	printf("%*s\n", center_align, "Admin Client");
	printf("\n");
	scanf("%s",sign_in_choice);
	int admin_result, client_result, number_of_clients;
	int x = 0;
	int c = 0; 
	admin_result = strcmp(sign_in_choice,"Admin");
	client_result = strcmp(sign_in_choice,"Client");
	char client_choice[10];
	int client_username;
	int client_password;
	int temp;
	int client_choice_log_in, client_choice_register;
while(x == 0)
{
		if(admin_result == 0 )
		{
		printf("Welcome to Admin Page\n");
	
		}
		else if(client_result == 0)
		{	
			while(c == 0)
			{
			//START OF CLIENT PAGE
				if(client_number <= 4)
				{
					printf("Welcome to Client Page\n");
					printf("Register or Log in?\n");
					scanf("%s",client_choice);
					client_choice_log_in = strcmp(client_choice,"Login");
					client_choice_register = strcmp(client_choice,"Register");
					
					if(client_choice_register == 0)
					{
					// REGISTER
						for(client_number = 0; client_number < 5; client_number ++)
						{
						reg(client_number);
						printf("Client number: %d", client_number);
						printf("\nWelcome to Client Page\n");
						printf("Register or Log in?\n");
						scanf("%s",client_choice);
						client_choice_log_in = strcmp(client_choice,"Login");
						client_choice_register = strcmp(client_choice,"Register");
						temp = client_number;
						if(client_choice_log_in == 0)
						{
							client_number = 5;
						}	
					}
				 	// END OF REGISTER
					}
					else if(client_choice_log_in == 0)
					{
				//LOG IN
			//		int test, testt, *p, array[10][10];
			//		test = 1513123123;
			//		testt = 200;
			//		array[0][0] = test;
			//		array[0][1] = testt;
			//		printf("%d\n", array[0][1]);
					printf("Please enter your credentials\n");
					printf("Enter your afm:\n");
					scanf("%d", &client_username);
					printf("Enter your year of birth:\n");
					scanf("%d", &client_password);
					client_number = temp;
							if(login(client_username, client_password, client_number, client_verify) == 1)
							{
					//END OF LOG IN
					// PERSONAL CLIENT PAGE
						i = client_number;
						printf("Welcome to your Personal Client Page: %s \n", client_array[i].client_name);
					// END OF PERSONAL CLIENT PAGE
								c = 1;	
							}
					}
					
					else
					{
					printf("Invalid input.Please try again.\n");
					scanf("%s",client_choice);
					client_choice_log_in = strcmp(sign_in_choice,"Login");
					client_choice_register = strcmp(sign_in_choice,"Register");
					}
				}
				else
				{
				printf("Welcome to Client Page\n");
				printf("Max Number of Clients\n");
				printf("Login or Exit\n");
				scanf("%s",client_choice);
				client_choice_log_in = strcmp(client_choice,"Login");
						if(client_choice_log_in == 0)
						{
					//LOG IN
						printf("Please enter your credentials\n");
						printf("Enter your afm:\n");
						scanf("%d", &client_username);
						printf("Enter your year of birth:\n");
						scanf("%d", &client_password);
						client_number = temp;
								if(login(client_username, client_password, client_number, client_verify) == 1)
								{
						//END OF LOG IN
						// PERSONAL CLIENT PAGE
							i = client_number;
							printf("Welcome to your Personal Client Page: %s \n", client_array[i].client_name);
						// END OF PERSONAL CLIENT PAGE
									c = 1;	
								}
							}

				}//END OF IF LOOP
			}//END OF WHILE C LOOP
			
		}// END OF CLIENT PAGE
		else
		{
		printf("Invalid input.Please try again.\n");
		scanf("%s",sign_in_choice);
		admin_result = strcmp(sign_in_choice,"Admin");
		client_result = strcmp(sign_in_choice,"Client");
		}
		x = 1;
}//END OF WHILE X LOOP

getch();
return 0;
}

int reg(client_number)
{
	int i = client_number;
	int loop = 0;
	if(i<5){
	printf("Please fill the form below\n");
	client_array[i].client_id = i ;
    printf("Enter your name: \n");
    scanf("%s", client_array[i].client_name);
    printf("Enter your surname: \n");
    scanf("%s", client_array[i].client_surname);
    printf("Enter your date of birth: \n");
    scanf("%d", &client_array[i].birth_year);
    printf("Enter your afm: \n");
    scanf("%d", &client_array[i].afm);
    printf("Initial Deposit: \n");
    scanf("%f", &client_array[i].initial_deposit);
    client_array[i].after_tax_deposit = client_array[i].initial_deposit - 0.05*client_array[i].initial_deposit;
	}else{
	printf("Maximum number of clients registered!");
	}
printf("\nClient id : %d", client_array[i].client_id);

return 0;
}

int login(client_username, client_password, client_number, client_verify)
{
	int z = client_number;
	int x = 0 ;
	int y = 0;
	int username = client_username;
	int password = client_password;
	int flag = 0;
	
		for(x=0; x<5; x++)
		{
	     if(client_array[x].afm ==  username && client_array[x].birth_year == password  )
	     {
			printf("Successful Login!\n");
			y = y +1;
			return y;
	     }

		}
//    printf("Enter your username:\n");
//    scanf("%s",&client_username);
//
//    printf("Enter your password:\n");
//    scanf("%s",&client_password);
//
//    if(strcmp(client_username,"chaitu")==0){
//        if(strcmp(client_password,"123")==0){
//
//        printf("\nWelcome.Login Success!");
//
//
//        }else{
//    printf("\nwrong password");
//}
//    }else{
//    printf("\nUser doesn't exist");
//
//
return 0;
}
