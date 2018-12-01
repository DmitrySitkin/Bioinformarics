//task 1.3
#include<iostream>
#include<string>
using namespace std;
int main()
{
	char ch;
	string input;
	int count=0,size;
	cin >> input;
	/*input = "AAAACCCGGT";*/
	size = input.length();
	for (int i = 0; i <size; i++)
	{
		ch = input[i];
		switch (ch)
		{
		case 'A': {input[i] = 'T'; break; }
		case 'T': {input[i] = 'A'; break; }
		case 'C': {input[i] = 'G'; break; }
		case 'G': {input[i] = 'C'; break; }
		}
	}
	cout << endl << input << endl;
	return 0;
}