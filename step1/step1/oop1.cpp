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
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "����: ";
}
void openAccount(void)
{
	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> cusAcc[cusNum].ID;
	cout << "�̸�: ";
	cin >> cusAcc[cusNum].cusName;
	cout << "�Աݾ�: ";
	cin >> cusAcc[cusNum].balance;
	
	cusNum++;
}
void inputMoney(void)
{
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
}
void getMoney(void)
{
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
}
void getAccountAll(void)
{
	int cnt = cusNum;
	for (int i = 0; i < cnt; i++) {
		cout << "����ID: " << cusAcc[i].ID << endl;
		cout << "�̸�: " << cusAcc[i].cusName << endl;
		cout << "�ܾ�" << cusAcc[i].balance << endl;
	}
}