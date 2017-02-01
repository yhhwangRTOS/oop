#pragma once
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