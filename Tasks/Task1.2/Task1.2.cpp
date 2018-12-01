//task 1.2
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string output, str,tmp, *mas;
	int k = 0,count=0,count2=0,size=0;
	cin >> str;
	cin >> k;
	/*str = "ACGTTGCATGTCGCATGATGCATGAGAGCT";
	k = 4;*/
	mas = new string[str.length()];
	for (int i = 0; i < str.length() - 1-k; i++)
	{
		tmp = "";
		count = 0;
		for (int j = 0; j < k; j++)
		{
			tmp += str[i + j];
		}
		for (int l = str.find(tmp,i); l < str.length(); l = str.find(tmp, l + 1)) count++;
		
		if (count > count2)
		{
			count2 = count;
			mas[0] = tmp;
			size = 1;
		}
		else if (count == count2)
		{
			mas[size] = tmp;
			size++;
		}
	}
	cout << endl;
	for (int i = 0; i < size; i++) cout << mas[i] << "   ";
	cout << endl;
} 