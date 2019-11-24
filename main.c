#include "myBank.h"
#include <stdio.h>

/*
~When we the command "while((getchar()) != '\n')",
we clearing the buffer, inorder not to have unused digits.

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
	if(getchar()!='\n'){
		printf("Illegal input please try again.\n");
		while((getchar()) != '\n');
		main();
	} //Checking if its single char

	switch (ch)
	{
	case 'O':
		printf("Intial deposit?: ");
		if(scanf("%lf", &amount)==1){
			open(amount);
			while((getchar()) != '\n');
		}
		else {
			while((getchar()) != '\n');
			printf("Illegal input please try again.\n");
		}
		break;

	case 'B':
		printf("Account number?: ");
		if(scanf("%d", &account)==1){
			myBalance(account);
			while((getchar()) != '\n');
		}
		else {
			while((getchar()) != '\n');
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
			while((getchar()) != '\n');
		}
		else {
			while((getchar()) != '\n');
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
			while((getchar()) != '\n');
		}
		else {
			while((getchar()) != '\n');
			printf("Illegal input please try again.\n");
		}
		break;

	case 'C':
		printf("Account number?: ");
		if(scanf("%d", &account)==1){
			close(account);
			while((getchar()) != '\n');
		}
		else {
			while((getchar()) != '\n');
			printf("Illegal input please try again.\n");
		}
		break;

	case 'I':
		printf("Interest rate?: ");
		if(scanf("%lf", &ribit)==1){
			allRibit(ribit);
		while((getchar()) != '\n');
		}
		else {
			while((getchar()) != '\n');
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

