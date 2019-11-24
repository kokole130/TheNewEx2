#include <stdio.h>
#include "myBank.h"
double twoDigitAfterDot(double num);

double bank[2][50]={0};

void open(double money){
	for(int i=0;i<50;i++){
		if(bank[1][i]==0){
			bank[0][i]=twoDigitAfterDot(money);
			bank[1][i]=1;
			printf("The account number is: %d\n",(901+i));
			return;
		}
	}
	printf("There is no unopen acounts, Transaction fail !\n");
}

void myBalance(int account){
	if(account<901||account>950){
		printf("Invalid account number, theres is not such as this account number.\n");
		return;
	}
	int accountindex = account-901;
	if(bank[1][accountindex]==1){
		printf("Your balanced: %f\n",(bank[0][accountindex]));
	}
	else {
		printf("This account is close\n");
	}
}

void inTransaction(double money, int account){
	if(account<901||account>950){
		printf("Invalid account number, theres is not such as this account number.\n");
		return;
	}
	int accountindex = account-901;
	if(bank[1][accountindex]==1){
		bank[0][accountindex]=twoDigitAfterDot(bank[0][accountindex]+money);
		printf("Your new balanced: %f\n",bank[0][accountindex]);
	}
	else {
		printf("This account is close, Transaction fail !\n");
	}
}

void outTransaction(double money, int account){
	if(account<901||account>950){
		printf("Invalid account number, theres is not such as this account number.\n");
		return;
	}
	int accountindex = account-901;
	if(bank[1][accountindex]==1){
		if(bank[0][accountindex]>money){
			bank[0][accountindex]=twoDigitAfterDot(bank[0][accountindex]-money);
			printf("Your new balanced: %f\n",bank[0][accountindex]);
		}
		else{
			printf("No enough money, Transaction fail !\n");
		}
	}
	else {
		printf("This account is close, Transaction fail !\n");
	}
}

void close(int account){
	if(account<901||account>950){
		printf("Invalid account number, theres is not such as this account number.\n");
		return;
	}
	int accountindex = account-901;
	if(bank[1][accountindex]==1){
	bank[0][accountindex]=0;
	bank[1][accountindex]=0;
	printf("Account %d has been closed.\n",account);
	}	
}

void allRibit(double ribit){
	ribit=1+(ribit/100);
	for(int i=0;i<50;i++){
		if(bank[1][i]==1){
			bank[0][i]=twoDigitAfterDot(bank[0][i]*ribit);
		}
	}
}

void printAcounts(){
	for(int i=0;i<50;i++){
		if(bank[1][i]==1){
			printf("To account number %d the amount is %f.\n",i+901 , bank[0][i]);
		}
	}
}

void Exit(){
	for(int i=0;i<50;i++){
		close(i+901);
	}
}

double twoDigitAfterDot(double num){
		int tmp=num*100;
		num=tmp;
		num/=100;
		return num;
}
