#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main(void)
{
	int choice;
	AccountHandler manager;

	while (1) {
		manager.ShowMenu();
		cin >> choice;
		switch (choice)
		{
		case MAKE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}