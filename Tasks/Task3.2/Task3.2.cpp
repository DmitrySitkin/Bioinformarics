#include <iostream>
#include <string>
#include <vector>
#include <map>
#include<list>
#include<algorithm>
using namespace std;
vector<string> aminoacids = { { 'G' },{ 'A' },{ 'S' },{ 'P' },{ 'V' },{ 'T' },{ 'C' },{ 'I' },{ 'L' },{ 'N' },{ 'D' },{ 'K' },{ 'Q' },{ 'E' },{ 'M' },{ 'H' },{ 'F' },{ 'R' },{ 'Y' },{ 'W' } };

map<char, int> spectr{ { 'G', 57 },{ 'A', 71 },{ 'S', 87 },{ 'P', 97 },{ 'V', 99 },
{ 'T', 101 },{ 'C', 103 },{ 'I', 113 },{ 'L', 113 },{ 'N', 114 },
{ 'D', 115 },{ 'K', 128 },{ 'Q', 128 },{ 'E', 129 },{ 'M', 131 },
{ 'H', 137 },{ 'F', 147 },{ 'R', 156 },{ 'Y', 163 },{ 'W', 186 } };

int massPept(string peptide)
{
	int mass = 0;
	for (int i = 0; i < peptide.size(); i++)
	{
		mass += spectr[peptide[i]];
	}
	return mass;
}
vector<string> expand(vector<string> peptides)
{
	vector<string> tmp;
	/*if (peptides.size() == 0)
	{
	tmp = aminoacids;
	return tmp;
	}*/
	for (int i = 0; i < peptides.size(); i++)
	{
		for (int j = 0; j < aminoacids.size(); j++)
		{
			string newpep = peptides[i];
			newpep += aminoacids[j];
			tmp.push_back(newpep);
		}
	}
	return tmp;
}
vector<int> cycloSpectrum(string peptide)
{
	vector<string> vs;
	vector<int> cycSpectrum;
	int size = peptide.size();
	vs.push_back("");
	for (int i = 1; i < size; i++)
	{
		for (int l = 0; l < size; l++)
		{
			if ((l + i) < size)
			{
				vs.push_back(peptide.substr(l, i));
			}
			else
			{
				int b = l + i - size;
				string tmp;
				tmp = peptide.substr(l, i);
				tmp += peptide.substr(0, b);
				vs.push_back(tmp);
			}
		}
	}
	vs.push_back(peptide);
	for (int i = 0; i < vs.size(); i++)
	{
		int tmpmass = 0;
		for (int j = 0; j < vs[i].size(); j++)
		{
			tmpmass += spectr[vs[i][j]];
		}
		cycSpectrum.push_back(tmpmass);
	}
	sort(cycSpectrum.begin(), cycSpectrum.end());
	return cycSpectrum;
}
vector<int> linarSpectrum(string peptide)
{
	vector<string> vs;
	vector<int> linSpectrum;
	int size = peptide.size();
	vs.push_back("");
	for (int i = 1; i < size; i++)
	{
		for (int l = 0; l < size; l++)
		{
			if ((l + i) <= size)
			{
				vs.push_back(peptide.substr(l, i));
			}
		}
	}
	vs.push_back(peptide);
	for (int i = 0; i < vs.size(); i++)
	{
		int tmpmass = 0;
		for (int j = 0; j < vs[i].size(); j++)
		{
			tmpmass += spectr[vs[i][j]];
		}
		linSpectrum.push_back(tmpmass);
	}
	sort(linSpectrum.begin(), linSpectrum.end());
	return linSpectrum;
}
vector<int> remove(vector<int> peptides, int pept)
{
	vector<int> res;
	int j = 0;
	int k = 1;
	for (int i = 0; i < peptides.size(); i++) {

		if (peptides[i] != pept || k == 0) {
			res.push_back(peptides[i]);

		}
		if (peptides[i] == pept && k == 1)
			k = 0;
	}
	return res;
}
bool isConsistedWithSpectrum(vector<int> spec, vector<int> pept)
{
	bool f = false;
	for (int i = 0; i < pept.size(); i++)
	{
		for (int j = 0; j<spec.size(); j++)
		{
			if (spec[j] == pept[i])
				f = true;
		}
		if (!f) return f;
		f = false;
	}
	return true;
}
//vector<string> cycloPeptideSequencing(vector<int> spec)
//{
//	int parMass = spec[spec.size() - 1];
//	vector<string> result;
//	vector<string> peptides = { "" };
//	while (peptides.size() > 0)
//	{
//		peptides = expand(peptides);
//		vector<string> tmp;
//		tmp = peptides;
//		for (int i = 0; i < tmp.size(); i++)
//		{
//			if (massPept(tmp[i]) == parMass)
//			{
//				if (cycloSpectrum(tmp[i]) == spec)
//				{
//					result.push_back(tmp[i]);
//				}
//				peptides = remove(peptides, tmp[i]);
//			}
//			else if (!isConsistedWithSpectrum(spec, linarSpectrum(tmp[i])))
//			{
//				peptides = remove(peptides, tmp[i]);
//			}
//		}
//	}
//	return result;
//}
vector<int> strToVec(string str)
{
	vector<int> res;
	string tmp = "";
	for (int i = 0; i < str.size(); i++)
	{
		while ((str[i] != ' ') && (i<str.size()))
		{
			tmp += str[i];
			i++;
		}
		char *p = &tmp[0];
		res.push_back(atoi(p));
		tmp = "";
	}
	return res;
}
int count(vector<int> spectr, string pept)
{
	vector<int> cycspec = cycloSpectrum(pept);
	int count = 0;
	for (int i = 0; i < spectr.size(); i++)
	{
		for (int j = 0; j<cycspec.size(); j++)
		{
			if (spectr[i] == cycspec[j])
			{
				count++;
				cycspec = remove(cycspec, cycspec[j]);
				break;
			}
		}
	}
	return count;
}
int main()
{
	string spec;// = "0 99 113 114 128 227 257 299 355 356 370 371 484";
	string pept;// = "NQEL";
	vector<int> spectrvec;
	int res = 0;
	getline(cin, pept);
	getline(cin, spec);

	spectrvec = strToVec(spec);
	res = count(spectrvec, pept);
	cout << res;
	return 0;
}