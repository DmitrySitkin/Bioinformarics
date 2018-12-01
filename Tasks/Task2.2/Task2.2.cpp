//task 2.2
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string ch, tmp;
	string input;// = "ATGGCCATGGCCCCCAGAACTGAGATCAATAGTACCCGTATTAACGGGTGA";
	string input2;// = "NS";
	string output1 = "";
	string output2 = "";
	string keys;
	vector<string> vs;
	int count = 0, size;
	cin >> input;
	cin >> input2;
	size = input.length();
	keys = "AAA K AAC N AAG K AAU N ACA T ACC T ACG T ACU T AGA R AGC S AGG R AGU S AUA I AUC I AUG M AUU I CAA Q CAC H CAG Q CAU H CCA P CCC P CCG P CCU P CGA R CGC R CGG R CGU R CUA L CUC L CUG L CUU L GAA E GAC D GAG E GAU D GCA A GCC A GCG A GCU A GGA G GGC G GGG G GGU G GUA V GUC V GUG V GUU V UAA UAC Y UAG UAU Y UCA S UCC S UCG S UCU S UGA UGC C UGG W UGU C UUA L UUC F UUG L UUU F";
	for (int i = 0; i < size; i++)
	{
		if (input[i] == 'T') {
			output1 += 'U'; continue;
		}
		output1 += input[i];
	}
	for (int i = 0; i < size; i++)
	{
		if (input[i] == 'T') {
			output2 += 'U'; continue;
		}
		output2 += input[i];
	}
	for (int l = 0; l < size / 2; l++)
	{
		char tmp;
		tmp = output2[l];
		output2[l] = output2[size - l - 1];
		output2[size - l - 1] = tmp;
	}
	for (int l = 0; l <size; l++)
	{
		char ch2;
		ch2 = output2[l];
		switch (ch2)
		{
		case 'A': {output2[l] = 'U'; break; }
		case 'U': {output2[l] = 'A'; break; }
		case 'C': {output2[l] = 'G'; break; }
		case 'G': {output2[l] = 'C'; break; }
		}
	}
	for (int i = 0; i < size - 6; i++)
	{
		int count2 = 0;
		string str = "";
		string str2 = "";
		string str3 = "";
		string ch = "";
		for (int l = 0; l < 6; l++)
		{
			str += output1[i + l];
			str3 += input[i+l];
		}
		ch = str[0];
		ch += str[1];
		ch += str[2];
		count2 = keys.find(ch);
		str2 = keys[count2 + 4];
		ch = str[3];
		ch += str[4];
		ch += str[5];
		count2 = keys.find(ch);
		str2 += keys[count2 + 4];
		if (str2 == input2)
		{

			vs.push_back(str3);
		}
	}
	for (int i = 0; i < size-6; i++)
	{
		int count2 = 0;
		string str = "";
		string str2 = "";
		string str3 = "";
		string ch = "";
		for (int l = 0; l < 6; l++)
		{
			str += output2[i + l];
			str3 += input[size-i+l-6];
		}
		ch = str[0];
		ch += str[1];
		ch += str[2];
		count2 = keys.find(ch);
		str2 = keys[count2 + 4];
		ch = str[3];
		ch += str[4];
		ch += str[5];
		count2 = keys.find(ch);
		str2 += keys[count2 + 4];
		if (str2 == input2)
		{

			vs.push_back(str3);
		}
	}
	for (int i = 0; i < vs.size(); i++)
	{
		cout << vs[i] << endl;
	}
	return 0;
}