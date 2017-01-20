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
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: ";
}
void Account::openAccount(void)
{
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> account[index].id;
	cout << "이름: ";
	cin >> account[index].name;
	cout << "입금액: ";
	cin >> account[index].balance;
}
void Account::inputMoney(void)
{/*
	int id, money, cnt;
	cnt = cusNum;
	cout << "[입금]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "입금액: ";
	cin >> money;
	for (int i = 0; i < cnt; i++) {
		if (cusAcc[i].ID == id)
			cusAcc[i].balance += money;
	}
	cout << "입금완료" << endl;
	*/
}
void Account::getMoney(void)
{/*
	int id, money, cnt;
	cnt = cusNum;
	cout << "[출금]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "출금액: ";
	cin >> money;
	for (int i = 0; i < cnt; i++) {
		if (cusAcc[i].ID == id)
			cusAcc[i].balance -= money;
	}
	cout << "출금완료" << endl;
	*/
}
void Account::getAccountAll(void)
{/*
	int cnt = cusNum;
	for (int i = 0; i < cnt; i++) {
		cout << "계좌ID: " << cusAcc[i].ID << endl;
		cout << "이름: " << cusAcc[i].cusName << endl;
		cout << "잔액" << cusAcc[i].balance << endl;
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