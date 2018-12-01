// task 1.1
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string input, str;
	int count=0;
	cin >> input;
	cin >> str;
	
	for (int i = str.find(input); i < str.length(); i = str.find(input, i + 1)) count++;
	cout << endl << count << endl;
	return 0;
}