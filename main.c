#include "myBank.h"
#include <stdio.h>

/*
~In every double input im confirming that the user enters,
only a double number.
 */

int main(){
	char ch;
	double amount;
	int account;
	double ribit;
	printf("Transaction type?: ");
	scanf(" %c", &ch);
	switch (ch)
	{
	case 'O':
		printf("Intial deposit?: ");
		if(scanf("%lf", &amount)==1){
			open(amount);
		}
		else {
			printf("Illegal input please try again.\n");
		}
		break;

	case 'B':
		printf("Account number?: ");
		if(scanf("%d", &account)==1){
			myBalance(account);
		}
		else {
			printf("Illegal input please try again.\n");
		}
		break;

	case 'D':
		printf("Account number?: ");
		int x=scanf("%d", &account);
		printf("Amount?: ");
		int y=scanf("%lf", &amount);
		if(y==1 && x==1){
			inTransaction(amount,account);
		}
		else {
			printf("Illegal input please try again.\n");
		}
		break;

	case 'W':
		printf("Account number?: ");
		int a=scanf("%d", &account);
		printf("Amount?: ");
		int b=scanf("%lf", &amount);
		if(a==1 && b==1){
			outTransaction(amount,account);
		}
		else {
			printf("Illegal input please try again.\n");
		}
		break;

	case 'C':
		printf("Account number?: ");
		if(scanf("%d", &account)==1){
			close(account);
		}
		else {
			printf("Illegal input please try again.\n");
		}
		break;

	case 'I':
		printf("Interest rate?: ");
		if(scanf("%lf", &ribit)==1){
			allRibit(ribit);
		}
		else {
			printf("Illegal input please try again.\n");
		}
		break;

	case 'P':
		printAcounts();
		break;

	case 'E':
		Exit();
		return 0;

	default:
		//If its not one of the chars iteration, then its illegal input so print it.
		printf("Illegal input, please try again.\n");
		break;
	}
	main();
}

