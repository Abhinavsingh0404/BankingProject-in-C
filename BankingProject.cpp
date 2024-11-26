#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user {
	char name [100];
	char gender;
	char addhhar_no[20];
	char Pan_no[10];
	char address[100];
	char account_no[20];
	char Username[20];
	char password[20];
	float balance;
} usr; 
int main(){
	struct user usr;
	FILE *fp;
	char filename[50];
	char Username[50];
	char Password[50];
	int opt;
	printf("Welcome to our bank");
	printf("\n what would you like to do sir/mam");
	printf("\n 1.create a new account:");
	printf("\n 2.Login to your account:");
	printf("\n 3.Know your Acoount status");
	printf("\n 4. Change your password");
	printf("\n 5.Payee management");
	printf("\n 6.View Statement");
	printf("\n 7.Exit");
	printf("Enter your choice: \t");// \t is used for the horizontal tab;
	scanf("%d",&opt);
	
	if(opt ==1){ // Module 1 ACCOUNT CREATION................................................
		printf("Enter your name: \t");
		scanf("%s",&usr.name);
		printf("Enter your gender: \t" );
		scanf("%s",&usr.gender);
		printf("Enter your Addhar number: \t");
		scanf("%s",&usr.addhhar_no);
		printf("enter your Pan Number: \t");
		scanf("%s",&usr.Pan_no);
		printf("Enter your Address: \t");
		scanf("%s",&usr.address);
		printf("enter your user name: \t");
		scanf("%s",usr.Username);
		printf("Enter your new password: \t");
		scanf("%s",&usr.password);
		usr.balance = 0;
		
		strcpy(filename,usr.Username);
		fp = fopen(strcat(filename,".dat"),"w");
		fwrite(&usr,sizeof(struct user),1,fp);
		if(fwrite != 0){
			printf("\n\n Account created succesfully");	
		}
		else {
			printf("\n\n Somwthing went wrong please try again later");
		}
		fclose(fp);//used for closing the previous opened file
	}
	if(opt==2){
		printf("\n Enter your Username: ");
		scanf("%d",&Username);
		fflush(stdin);
		printf("\n Enter your Password: ");
		scanf("%d",&Password);
		strcpy(filename,Username);
		fp = fopen(strcat(filename,".dat"),"w");
		fread(&usr,sizeof(struct user),1,fp);
		fclose(fp);
		if(fp=NULL){
			printf("\n Account Number not registred");
	}
		else{
			if (strcmp(Password,usr.password)){
			printf("\n password matched");
			}//
			else{
			printf("\n Invalid Password");
			}	
		}
	}
	
	
	return 0;
}
