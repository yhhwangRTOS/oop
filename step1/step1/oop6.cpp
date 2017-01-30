#include <iostream>
#include <cstring>

#pragma warning(disable:4996)

using namespace std;
const int NAME_LEN = 20;

//user menu
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

//credit grade
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

//kind of Account
enum { NORMAL = 1, CREDIT = 2 };

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
		cusName = new char[strlen(name) + 1];	//길이만큼 배열 선언, +1은 널문자 공간
		strcpy(cusName, name);					//질문..여기서 strcpy
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
	virtual void Deposit(int money)		//virtual is key
	{
		balance += money;
	}
	int Withdraw(int money)
	{
		if (balance < money) {
			return 0;
		}
		balance -= money;
		return money;						//왜 money를 return? 잔액 부족 판단할 때 사용
	}
	void ShowAccInfo(void) const
	{
		cout << "계좌ID: " << accID << endl;
		cout << "이름: " << cusName << endl;
		cout << "잔액" << balance << endl;
	}
	~Account()
	{
		delete[]cusName;
	}
};
class NormalAccount : public Account
{
private:
	int interRate;
public:
	NormalAccount(int ID, int money, char* name, int rate)
		: Account(ID, money, name), interRate(rate)
	{}
	virtual void Deposit(int money)
	{
		Account::Deposit(money);		//origin
		Account::Deposit(money*(interRate / 100.0));		//add rate
	}
};
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

class AccountHandler
{
private:
	Account* accArr[100];
	int accNum;
public:
	AccountHandler();
	void ShowMenu(void) const;
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void) const;
	~AccountHandler();
protected:
	void MakeNormalAccount(void);
	void MakeCreditAccount(void);
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
void AccountHandler::ShowMenu(void) const
{
	cout << "------Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: ";
}
AccountHandler::AccountHandler()
	:accNum(0)
{}
void AccountHandler::MakeAccount(void)
{
	int sel;
	cout << "[계좌종류선택]" << endl;
	cout << "1. 보통예금계좌 ";
	cout << "2.신용신뢰계좌" << endl;
	cout << "선택: ";
	cin >> sel;
	
	if (sel == NORMAL)
		MakeNormalAccount();
	else
		MakeCreditAccount();
}
void AccountHandler::MakeNormalAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;

	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << "이자율: "; cin >> interRate;
	cout << endl;

	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}
void AccountHandler::MakeCreditAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;
	int creditLevel;

	cout << "[신용신뢰계좌 개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << "이자율: "; cin >> interRate;
	cout << "신용등급: "; cin >> creditLevel;
	cout << endl;

	switch (creditLevel){
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
		break;
	default:
		break;
	}
	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}
void AccountHandler::DepositMoney(void)
{
	int id;
	int balance;

	cout << "[입금]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "입금액: ";
	cin >> balance;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id)
			accArr[i]->Deposit(balance);
		cout << "입금완료" << endl << endl;
		return;
	}
	cout << "유효하지 않은 id" << endl;
}
void AccountHandler::WithdrawMoney(void)
{
	int id;
	int balance;

	cout << "[출금]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "출금액: ";
	cin >> balance;
	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			if (accArr[i]->Withdraw(balance) == 0) {
				cout << "잔액부족" << endl;
				return;
			}
			cout << "출금 완료" << endl;
			return;
		}
		cout << "입금완료" << endl << endl;
		return;
	}
	cout << "유효하지 않은 id" << endl;
}
void AccountHandler::ShowAllAccInfo(void) const
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