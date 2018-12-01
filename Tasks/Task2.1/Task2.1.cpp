//task 2.1
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string ch,tmp;
	string input,output="";
	string keys;
	int count = 0, size;
	cin >> input;
	keys = "AAA K AAC N AAG K AAU N ACA T ACC T ACG T ACU T AGA R AGC S AGG R AGU S AUA I AUC I AUG M AUU I CAA Q CAC H CAG Q CAU H CCA P CCC P CCG P CCU P CGA R CGC R CGG R CGU R CUA L CUC L CUG L CUU L GAA E GAC D GAG E GAU D GCA A GCC A GCG A GCU A GGA G GGC G GGG G GGU G GUA V GUC V GUG V GUU V UAA UAC Y UAG UAU Y UCA S UCC S UCG S UCU S UGA UGC C UGG W UGU C UUA L UUC F UUG L UUU F";
	//input = "AUGGCCAUGGCGCCCAGAACUGAGAUCAAUAGUACCCGUAUUAACGGGUGA";
	size = input.length();
	for (int i = 0; i <size-3;i+=3)
	{
		ch += input[i];
		ch += input[i + 1];
		ch += input[i + 2];
		count=keys.find(ch);
		output += keys[count + 4];
		ch = "";
	}
	cout << endl << input << endl << output << endl;
	return 0;
}