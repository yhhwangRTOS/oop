#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

class Account {
private:
	int id;
	char* name = new char;
	int balance;
	
public:
	Account() 
	{
		this->id = 0;
		//this->name = NULL;
		this->balance = 0;
	}
	void showMenu(void);
	void openAccount(void);
	void inputMoney(void);
	void getMoney(void);
	void getAccountAll(void);
};

Account* account = new Account[100];
int index = 0;

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

void Account::showMenu(void)
{
	cout << "------Menu------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "����: ";
}
void Account::openAccount(void)
{
	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> account[index].id;
	cout << "�̸�: ";
	cin >> account[index].name;
	cout << "�Աݾ�: ";
	cin >> account[index].balance;
}
void Account::inputMoney(void)
{/*
	int id, money, cnt;
	cnt = cusNum;
	cout << "[�Ա�]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�Աݾ�: ";
	cin >> money;
	for (int i = 0; i < cnt; i++) {
		if (cusAcc[i].ID == id)
			cusAcc[i].balance += money;
	}
	cout << "�ԱݿϷ�" << endl;
	*/
}
void Account::getMoney(void)
{/*
	int id, money, cnt;
	cnt = cusNum;
	cout << "[���]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "��ݾ�: ";
	cin >> money;
	for (int i = 0; i < cnt; i++) {
		if (cusAcc[i].ID == id)
			cusAcc[i].balance -= money;
	}
	cout << "��ݿϷ�" << endl;
	*/
}
void Account::getAccountAll(void)
{/*
	int cnt = cusNum;
	for (int i = 0; i < cnt; i++) {
		cout << "����ID: " << cusAcc[i].ID << endl;
		cout << "�̸�: " << cusAcc[i].cusName << endl;
		cout << "�ܾ�" << cusAcc[i].balance << endl;
	}
	*/
}
int main(void)
{
	int choice = 0;

	while (1) {
		account[index].showMenu;
		cin >> choice;
		switch (choice) {
		case MAKE:
			account[index].openAccount();
			break;
		case DEPOSIT:
			account[index].inputMoney();
			break;
		case WITHDRAW:
			account[index].getMoney();
			break;
		case INQUIRE:
			account[index].getAccountAll();
			break;
		case EXIT:
			return 0;
		default:
			break;
		}
	}
	return 0;
}