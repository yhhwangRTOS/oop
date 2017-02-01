#pragma once

#include "Account.h"
#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
	int specialRate;
public:
	HighCreditAccount(int ID, int money, char* name, int rate, int special)
		: NormalAccount(ID, money, name, rate), specialRate(special)
	{}
	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money);
		Account::Deposit(money*(specialRate / 100.0));
	}
};