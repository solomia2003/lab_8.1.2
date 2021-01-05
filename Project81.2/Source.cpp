//Щепітки Соломії
//Варіант 23
// lab-8.1.2

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

char* Insert(char* str, const char* substr, const char c1);
char Insert1(char* tmp, char* str, char c1, int i, int c);
char* Insert2(char* tmp, const char* substr, int& n, int j);
char* Insert3(char* tmp, const char* str, int i, int& n);


int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	char substr[] = "**";

	cout << Insert(str, substr, ',');

	return 0;

}

char* Insert(char* str, const char* substr, const char c1)
{
	char* tmp = new char[strlen(str) + strlen(substr)];
	int i = 0;
	int c = 0;
	int k = Insert1(tmp, str, ',', i, 0);

	int n = k;

	Insert2(tmp, substr, n, 0);

	Insert3(tmp, str, k + 1, n);

	tmp[n] = '\0';
	strcpy_s(str, 100, tmp);
	return tmp;
}


char Insert1(char* tmp, char* str, char c1, int i, int c)
{
	if (c == 3)
		return i - 1;

	tmp[i] = str[i];

	if (tmp[i] == c1)
		c++;

	return Insert1(tmp, str, c1, i + 1, c);
}

char* Insert2(char* tmp, const char* substr, int& n, int j)
{
	if (substr[j] == '\0')
		return tmp;

	tmp[n] = substr[j];
	n++;
	Insert2(tmp, substr, n, j + 1);
}

char* Insert3(char* tmp, const char* str, int i, int& n)
{
	if (str[i] == '\0')
		return tmp;

	tmp[n] = str[i];
	n++;
	Insert3(tmp, str, i + 1, n);
}