//task 2.4
#include<iostream>
#include<string>
#include<vector>
#include <cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	string input;
	string spectr;
	vector<string> vs;
	vector<int> vi;
	int size;
	cin >> input;
	spectr = "G 57 A 71 S 87 P 97 V 99 T 101 C 103 I 113 L 113 N 114 D 115 K 128 Q 128 E 129 M 131 H 137 F 147 R 156 Y 163 W 186";
	size = input.length();
	vi.push_back(0);
	for (int i = 1; i < size; i++)
	{
		for (int l = 0; l < size; l++)
		{
			if ((l + i) < size)
			{
				vs.push_back(input.substr(l, i));
			}
			else
			{
				int b = l + i - size;
				string tmp;
				tmp = input.substr(l, i);
				tmp += input.substr(0, b);
				vs.push_back(tmp);
			}
		}
	}
	vs.push_back(input);
	for (int i = 0; i < vs.size(); i++)
	{
		int mas=0;
		string tmp = vs[i];
		for (int l = 0; l < tmp.length(); l++)
		{
			string tmp2="";
			int count=0;
			int k = 2;
			count = spectr.find(tmp[l]);
			while (spectr[count + k] != ' ')
			{
				tmp2 += spectr[count + k];
				k++;
			}
			char *p = &tmp2[0];
			mas += atoi(p);
		}
		vi.push_back(mas);
	}
	sort(vi.begin(), vi.end());
	for (int i = 0; i < vi.size; i++)
	{
		cout << vi[0] << " ";
	}
	cout << endl;
	return 0;
}