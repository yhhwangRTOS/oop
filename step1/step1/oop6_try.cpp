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
class NormalAccount : public Account
{
private:
	int rate;
public:
	NormalAccount(int ID, int money, char* name, int baseRate)
		:Account(ID, money, name), rate(baseRate){}
	~NormalAccount(){}
};
class HighCreditAccount : public Account
{
private:
	int rate;
	int grade;
public:
	HighCreditAccount(int ID, int money, char* name, int baseRate, int creditGrade)
		:Account(ID, money, name), rate(baseRate), grade(creditGrade) {}
	~HighCreditAccount() {}
};
class AccountHandler
{
private:
	Account* accArr[100];
	int accNum;
	int kindofAcc;
	int accessCnt;
public:
	AccountHandler();
	void ShowMenu(void);
	void MakeAccount(void);
	void MakeNormalAccount(void);
	void MakeHighCreditAccount(void);
	void DepositMoney(void);
	void NormalDeposit(void);
	void HighCreditDeposit(void);
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
	:accNum(0), kindofAcc(0), accessCnt(0)
{}
void AccountHandler::MakeAccount(void)
{
	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ���  2.�ſ�ŷڰ���" << endl;
	cin >> kindofAcc;

	switch (kindofAcc) {
	case 1:
		MakeNormalAccount();
		break;
	case 2:
		MakeHighCreditAccount();
		break;
	default:
		break;
	}
}
void AccountHandler::MakeNormalAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	int rate;

	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�̸�: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> balance;
	cout << "������: ";
	cin >> rate;
	cout << endl;

	accArr[accNum++] = new NormalAccount(id, balance, name, rate);
}
void AccountHandler::MakeHighCreditAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	int rate;
	int grade;

	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�̸�: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> balance;
	cout << "������: ";
	cin >> rate;
	cout << "�ſ���(1toA, 2toB, 3toC): ";
	cin >> grade;
	cout << endl;
	
	accArr[accNum++] = new HighCreditAccount(id, balance, name, rate, grade);
}
/*
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
*/
void AccountHandler::DepositMoney(void)
{
	switch (kindofAcc) {
	case 1:
		NormalDeposit();
		break;
	case 2:
		HighCreditDeposit();
		break;
	default:
		break;
	}
}
void AccountHandler::NormalDeposit(void)
{

}
void AccountHandler::HighCreditDeposit(void)
{

}
/*
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
*/
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