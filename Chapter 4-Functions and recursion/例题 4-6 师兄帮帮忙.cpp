#include<iostream>
#include<iomanip>
#include<list>
#include<string>
#include<cstdio>
#define EPS 1e-5

using namespace std;

class Student {
public:
	int rank;
	int enter;
	string SID;
	string CID;
	string name;
	int chineseScore;
	int mathScore;
	int EnglishScore;
	int programScore;
	double sum;
	double ave;
};

list<Student> lst;
int size1 = 0;

void printMenu()
{
	cout << "Welcome to Student Performance Management System (SPMS)." << endl;
	cout << endl;
	cout << "1 - Add" << endl;
	cout << "2 - Remove" << endl;
	cout << "3 - Query" << endl;
	cout << "4 - Show ranking" << endl;
	cout << "5 - Show Statistics" << endl;
	cout << "0 - Exit" << endl;
	cout << endl;
}

void add()
{
	while (1)
	{
		cout << "Please enter the SID, CID, name and four scores. Enter 0 to finish." << endl;
		Student s;
		cin >> s.SID;
		if (s.SID == "0")
			break;
		cin >> s.CID >> s.name >> s.chineseScore >> s.mathScore >> s.EnglishScore >> s.programScore;
		int judge = 0;
		for (auto &stu : lst)
		{
			if (stu.SID == s.SID)
			{
				cout << "Duplicated SID." << endl;
				judge = 1;
			}
		}
		if (judge)
			continue;
		s.sum = s.chineseScore + s.mathScore + s.EnglishScore + s.programScore;
		s.ave = s.sum / 4;
		s.enter = ++size1;
		lst.push_back(s);
	}
}

bool cmp1(Student s1, Student s2)
{
	return s1.sum > s2.sum;
}

bool cmp2(Student s1, Student s2)
{
	return s1.enter < s2.enter;
}

void sortByRank()
{
	lst.sort(cmp1);
	int i = 1;
	int size = lst.size();
	if (size == 0)
	{
		return;
	}
	lst.front().rank = 1;
	int first = 1;
	if (size == 1)
		return;
	for (auto iter = lst.begin(); iter != lst.end(); iter++)
	{
		if (first)
			iter++;
		first = 0;
		auto temp = --iter;
		iter++;
		i++;
		if (iter->sum == temp->sum)
			iter->rank = temp->rank;
		else
			iter->rank = i;
	}
}





void query()
{
	sortByRank();
	while (1)
	{
		list<Student> ans;
		cout << "Please enter SID or name. Enter 0 to finish." << endl;
		string s1;
		cin >> s1;
		if (s1 == "0")
			break;
		for (auto &s : lst)
		{
			if (s.SID == s1 || s.name == s1)
				ans.push_back(s);
		}
		ans.sort(cmp2);
		for (auto &s : ans)
		{
			cout << s.rank << " " << s.SID << " " << s.CID << " " << s.name << " " <<
				s.chineseScore << " " << s.mathScore << " " << s.EnglishScore << " " <<
				s.programScore << " " << fixed << setprecision(0) << s.sum << " " << fixed << setprecision(2) << s.ave + EPS << endl;

		}
	}
	lst.sort(cmp2);
}

void statical()
{
	cout << "Please enter class ID, 0 for the whole statistics." << endl;
	double sum[4] = { 0 };
	int size = 0;
	int pass[4] = { 0 };
	int fail[4] = { 0 };
	int passNum[5] = { 0 };//0 means 0 pass
	string s1;
	cin >> s1;

	for (auto& s : lst)
	{
		int passnum = 0;
		if (s1 == "0" || s1 == s.CID)
		{
			size++;
			sum[0] += s.chineseScore;
			if (s.chineseScore >= 60)
			{
				passnum++;
				pass[0]++;
			}
			else
				fail[0]++;
			sum[1] += s.mathScore;
			if (s.mathScore >= 60)
			{
				passnum++;
				pass[1]++;
			}
			else
				fail[1]++;
			sum[2] += s.EnglishScore;
			if (s.EnglishScore >= 60)
			{
				passnum++;
				pass[2]++;
			}
			else
				fail[2]++;
			sum[3] += s.programScore;
			if (s.programScore >= 60)
			{
				passnum++;
				pass[3]++;
			}
			else
				fail[3]++;
			passNum[passnum]++;
			if (passnum == 4)
			{
				passNum[1]++;
				passNum[2]++;
				passNum[3]++;
			}
			if (passnum == 3)
			{
				passNum[1]++;
				passNum[2]++;
			}
			else if (passnum == 2)
			{
				passNum[1]++;
			}
		}
	}

	const char* str[] = { "Chinese","Mathematics","English","Programming" };
	for (int i = 0; i < 4; i++)
	{
		cout << str[i] << endl;
		cout << "Average Score: " << fixed << setprecision(2) << sum[i] / size + EPS << endl;
		cout << "Number of passed students: " << pass[i] << endl;
		cout << "Number of failed students: " << fail[i] << endl;
		cout << endl;
	}
	cout << "Overall:" << endl;
	cout << "Number of students who passed all subjects: " << passNum[4] << endl;
	cout << "Number of students who passed 3 or more subjects: " << passNum[3] << endl;
	cout << "Number of students who passed 2 or more subjects: " << passNum[2] << endl;
	cout << "Number of students who passed 1 or more subjects: " << passNum[1] << endl;
	cout << "Number of students who failed all subjects: " << passNum[0] << endl;
	cout << endl;
}

void remove()
{
	while (1)
	{
		cout << "Please enter SID or name. Enter 0 to finish." << endl;
		int size = 0;
		string s;
		cin >> s;
		if (s == "0")
			break;
		for (auto iter = lst.begin(); iter != lst.end(); iter++)
		{
			while (iter != lst.end() && (iter->SID == s || iter->name == s) )
			{
				iter = lst.erase(iter);
				size++;
			}
			if (iter == lst.end())
				break;
		}
		cout << size << " student(s) removed." << endl;
	}
}

int main()
{
//		freopen("data.in","r",stdin);
//		freopen("data.out","w",stdout);
	while (1)
	{
		printMenu();
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 0:
			return 0;
			break;
		case 1:
			add();
			break;
		case 2:
			remove();
			break;
		case 3:
			query();
			break;
		case 4:
			cout << "Showing the ranklist hurts students' self-esteem. Don't do that." << endl;
			break;
		case 5:
			statical();
		default:
			break;
		}
	}
	return 0;
}
