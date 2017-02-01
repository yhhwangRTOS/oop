#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int ID, int money, char* name)
	: accID(ID), balance(money)				//member value initializer
{
	cusName = new char[strlen(name) + 1];	//길이만큼 배열 선언, +1은 널문자 공간
	strcpy(cusName, name);					//질문..여기서 strcpy
											//strcpy_s(cusName, sizeof(cusName), name);
}
Account::Account(const  Account& copy) : accID(copy.accID), balance(copy.balance)
{
	cusName = new char[strlen(copy.cusName) + 1];
	strcpy(cusName, copy.cusName);
}
int Account::GetAccID() const
{
	return accID;
}
void Account::Deposit(int money)		//virtual is key
{
	balance += money;
}
int Account::Withdraw(int money)
{
	if (balance < money) {
		return 0;
	}
	balance -= money;
	return money;						//왜 money를 return? 잔액 부족 판단할 때 사용
}
void Account::ShowAccInfo(void) const
{
	cout << "계좌ID: " << accID << endl;
	cout << "이름: " << cusName << endl;
	cout << "잔액" << balance << endl;
}
Account::~Account()
{
	delete[]cusName;
}