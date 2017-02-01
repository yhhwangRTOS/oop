#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int ID, int money, char* name)
	: accID(ID), balance(money)				//member value initializer
{
	cusName = new char[strlen(name) + 1];	//���̸�ŭ �迭 ����, +1�� �ι��� ����
	strcpy(cusName, name);					//����..���⼭ strcpy
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
	return money;						//�� money�� return? �ܾ� ���� �Ǵ��� �� ���
}
void Account::ShowAccInfo(void) const
{
	cout << "����ID: " << accID << endl;
	cout << "�̸�: " << cusName << endl;
	cout << "�ܾ�" << balance << endl;
}
Account::~Account()
{
	delete[]cusName;
}