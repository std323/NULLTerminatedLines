#include<Windows.h>
#include<iostream>
using namespace std;

int StringLength(const char* str);
char* to_upper(char str[]);
char* to_lower(char str[]);
char* shrink(char str[]);
bool is_palindrome(const char str[]);
bool is_int_number(const char str[]);
int  to_int_number(const char str[]);

void main()
{
	setlocale(LC_ALL, "");
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };
	//cout << str << endl;
	//str[2] = 0;
	/*char str[] = "Hello";
	cout << str << endl;
	cout << sizeof(str) << endl;*/

	//cout << 'a' - 'A' << endl;
	const int n = 256;
	char str[n] = "Аргентина манит негра";
	cout << "Введите строку: "; 
	//cin >> str;
	SetConsoleCP(1251);
	cin.getline(str, n);
	SetConsoleCP(866);
	cout << str << endl;
	cout << "Размер строки: " << StringLength(str) << endl;
	cout << to_upper(str) << endl;
	cout << to_lower(str) << endl;
	cout << shrink(str) << endl;
	cout << "Строка " << (is_palindrome(str)?"":"НЕ ") << "палиндром" << endl;
	cout << "Стока " << (is_int_number(str) ? "" : "НЕ ") << "является числом" << endl;
	cout << to_int_number(str)*2 << endl;
}
int StringLength(const char* str)
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}
char* to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if(str[i]>= 'a' && str[i] <= 'z')str[i] -= ' ';
		if(str[i]>= 'а' && str[i] <= 'я')str[i] -= ' ';

	}
	return str;
}
char* to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')str[i] += ' ';
		if (str[i] >= 'А' && str[i] <= 'Я')str[i] += ' ';

	}
	return str;
}
char* shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i+1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
	return str;
}
char* remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)str[j] = str[j + 1];
		}
	}
	return str;
}

bool is_palindrome(const char str[])
{
	int n = StringLength(str);
	char* buffer = new char[n+1] {};
	for (int i = 0; i < n; i++)buffer[i] = str[i];
	to_lower(buffer);
	remove_symbol(buffer, ' ');
	n = StringLength(buffer);
	for (int i = 0; i < n / 2; i++)
	{
		if (buffer[i] != buffer[n - 1 - i])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}
bool is_int_number(const char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))return false;
	}
	return true;
}
int  to_int_number(const char str[])
{
	int weight = 1;
	int number = 0;
	int n = StringLength(str);
	for (int i = n - 1; i >= 0; i--)
	{
		number += (str[i] - '0') * weight;
		weight *= 10;
	}
	return number;
}