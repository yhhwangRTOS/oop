#include <iostream>
#include <cstdio>

void showMenu(void);
void openAccount(void);
void inputMoney(void);
void getMoney(void);
void getAccountAll(void);

using namespace std;
const int NAME_LEN = 20;

typedef struct {
	int ID;
	char cusName[NAME_LEN];
	int balance;
}Account;

Account cusAcc[100];
int cusNum = 0;

int main(void)
{
	int choice = 0;
	
	while (1) {
		showMenu();
		cin >> choice;
		switch (choice) {
		case 1:
			openAccount();
			break;
		case 2:
			inputMoney();
			break;
		case 3:
			getMoney();
			break;
		case 4:
			getAccountAll();
			break;
		case 5:
			return 0;
		default:
			break;
		}
	}
	return 0;
}
void showMenu(void)
{
	cout << "------Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: ";
}
void openAccount(void)
{
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> cusAcc[cusNum].ID;
	cout << "이름: ";
	cin >> cusAcc[cusNum].cusName;
	cout << "입금액: ";
	cin >> cusAcc[cusNum].balance;
	
	cusNum++;
}
void inputMoney(void)
{
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
}
void getMoney(void)
{
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
}
void getAccountAll(void)
{
	int cnt = cusNum;
	for (int i = 0; i < cnt; i++) {
		cout << "계좌ID: " << cusAcc[i].ID << endl;
		cout << "이름: " << cusAcc[i].cusName << endl;
		cout << "잔액" << cusAcc[i].balance << endl;
	}
}