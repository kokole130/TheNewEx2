#include "myBank.h"
#include <stdio.h>


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
		scanf("%lf", &amount);
		open(amount);
		break;
	case 'B':
		printf("Account number?: ");
		scanf("%d", &account);
		myBalance(account);
		break;
	case 'D':
		printf("Account number?: ");
		scanf("%d", &account);
		printf("Amount?: ");
		scanf("%lf", &amount);
		inTransaction(amount,account);
		break;	
	case 'W':
		printf("Account number?: ");
		scanf("%d", &account);
		printf("Amount?: ");
		scanf("%lf", &amount);
		outTransaction(amount,account);
		break;
	case 'C':
		printf("Account number?: ");
		scanf("%d", &account);
		close(account);
		break;
	case 'I':
		printf("Interest rate?: ");
		scanf("%lf", &ribit);
		allRibit(ribit);
		break;
	case 'P':
		printAcounts();
		break;
	case 'E':
		Exit();
		return 0;
	}
	main();
}

