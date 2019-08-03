#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<set>
#define INF 1e10
using namespace std;

map<char, string> map1;
map<string, string> wordMap;
vector<string> word;
vector<string> morseCode;

void wordToMorseCode()
{
	int size = word.size();
	for (int i = 0; i < size; i++)
	{
		string temp;
		int len = word[i].size();
		for (int j = 0; j < len; j++)
		{
			temp += map1[word[i][j]];
		}
		wordMap[word[i]] = temp;
	}
}

//返回值 1 index 代表精确匹配一个
//返回值 >1 index 代表精确匹配多个 加!
//返回值 =0 index 为-1 代表没法匹配
//返回值 =0 index 有值 代表模糊匹配到一个
int matchString(string s, int& index)
{
	index = -1;
	int size = word.size();
	int cnt = 0;
	for (int i = 0; i < size; i++)
	{
		if (wordMap[word[i]] == s)
		{
			if(cnt==0)
			index = i;
			cnt++;
		}
	}
	if (cnt == 0)
	{
		int min = INF;
		for (int i = 0; i < size; i++)
		{
			if (wordMap[word[i]].find(s) == 0 || s.find(wordMap[word[i]]) == 0)
			{
				int lenD = abs((int)wordMap[word[i]].size() - (int)s.size());
				if (lenD < min)
				{
					min = lenD;
					index = i;
				}
			}
		}
	}
	return cnt;
}


void output()
{
	int size = word.size();
	for (int i = 0; i < size; i++)
		cout << word[i] << " : " << wordMap[word[i]] << endl;
}


int main()
{
	char ch;
	string s;
	int cnt = 0;
	while (cin >> ch)
	{
		if (ch == '*')
			break;
		cin >> s;
		map1[ch] = s;
	}
	while (cin >> s)
	{
		if (s == "*")
			break;
		word.push_back(s);
	}
	while (cin >> s)
	{
		if(s == "*")
			break;
		morseCode.push_back(s);
	}
	//word 排序
	sort(word.begin(), word.end());
	wordToMorseCode();
	for (int i = 0; i < morseCode.size(); i++)
	{
		int index;
		int a = matchString(morseCode[i], index);
		if (a == 1 && index != -1)
		{
			cout << word[index] << endl;
		}
		else if (a >= 2)
		{
			cout << word[index] << "!" << endl;
		}
		else if (a == 0 && index != -1)
		{
			cout << word[index] << "?" << endl;
		}
		else
		{
			cout << word[0] << "?" << endl;
		}
	}
	return 0;
}
