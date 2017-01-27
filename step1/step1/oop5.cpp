#include <iostream>
#include <cstring>

#pragma warning(disable:4996)

using namespace std;
const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account
{
private:
	int accID;
	int balance;
	char* cusName;

public:
	Account(int ID, int money, char* name)
		: accID(ID), balance(money)				//member value initializer
	{
		cusName = new char[strlen(name) + 1];	//���̸�ŭ �迭 ����, +1�� �ι��� ����
		strcpy(cusName, name);					//����..���⼭ strcpy
												//strcpy_s(cusName, sizeof(cusName), name);
	}
	Account(const  Account& copy) : accID(copy.accID), balance(copy.balance)
	{
		cusName = new char[strlen(copy.cusName) + 1];
		strcpy(cusName, copy.cusName);
	}
	int GetAccID() const
	{
		return accID;
	}
	void Deposit(int money)
	{
		balance += money;
	}
	int Withdraw(int money)
	{
		if (balance < money) {
			return 0;
		}
		balance -= money;
		return money;						//�� money�� return?
	}
	void ShowAccInfo(void) const
	{
		cout << "����ID: " << accID << endl;
		cout << "�̸�: " << cusName << endl;
		cout << "�ܾ�" << balance << endl;
	}
	~Account()
	{
		delete[]cusName;
	}
};
class AccountHandler
{
private:
	Account* accArr[100];
	int accNum;
public:
	AccountHandler();
	void ShowMenu(void);
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void);
	~AccountHandler();
};


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
void AccountHandler::ShowMenu(void)
{
	cout << "------Menu------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "����: ";
}
AccountHandler::AccountHandler()
	:accNum(0)
{}
void AccountHandler::MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�̸�: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name);
}
void AccountHandler::DepositMoney(void)
{
	int id;
	int balance;

	cout << "[�Ա�]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�Աݾ�: ";
	cin >> balance;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id)
			accArr[i]->Deposit(balance);
		cout << "�ԱݿϷ�" << endl << endl;
		return;
	}
	cout << "��ȿ���� ���� id" << endl;
}
void AccountHandler::WithdrawMoney(void)
{
	int id;
	int balance;

	cout << "[���]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "��ݾ�: ";
	cin >> balance;
	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			if (accArr[i]->Withdraw(balance) == 0) {
				cout << "�ܾ׺���" << endl;
				return;
			}
			cout << "��� �Ϸ�" << endl;
			return;
		}
		cout << "�ԱݿϷ�" << endl << endl;
		return;
	}
	cout << "��ȿ���� ���� id" << endl;
}
void AccountHandler::ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
	}
}
AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}