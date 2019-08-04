#include<string>
#include<vector>
#include<list>
#include<cctype>
#include<iostream>
#include<iomanip>
#include<regex>
using namespace std;

class HugeInt
{
public:
	HugeInt(long int);
	HugeInt(string);
	HugeInt(const HugeInt& h);
	HugeInt();

	friend HugeInt operator + (HugeInt h1, HugeInt h2);
	friend HugeInt operator + (HugeInt h, long l);
	friend HugeInt operator + (HugeInt h, string s);
	friend HugeInt operator + (long l, HugeInt h);
	friend HugeInt operator + (string s, HugeInt h);
	friend HugeInt operator - (HugeInt h1, HugeInt h2);
	friend HugeInt operator - (HugeInt h, long l);
	friend HugeInt operator - (HugeInt h, string s);
	friend HugeInt operator - (long l, HugeInt h);
	friend HugeInt operator - (string s, HugeInt h);
	friend HugeInt operator * (HugeInt h1, HugeInt h2);
	friend HugeInt operator * (HugeInt h, long l);
	friend HugeInt operator * (HugeInt h, string s);
	friend HugeInt operator * (long l, HugeInt h);
	friend HugeInt operator * (string s, HugeInt h);
	friend HugeInt operator / (HugeInt h1, HugeInt h2);
	friend HugeInt operator / (HugeInt h, long l);
	friend HugeInt operator / (HugeInt h, string s);
	friend HugeInt operator / (long l, HugeInt h);
	friend HugeInt operator / (string s, HugeInt h);
	friend HugeInt operator % (HugeInt h1, HugeInt h2);
	friend HugeInt operator % (HugeInt h, long l);
	friend HugeInt operator % (HugeInt h, string s);
	friend HugeInt operator % (long l, HugeInt h);
	friend HugeInt operator % (string s, HugeInt h);
	friend bool operator > (HugeInt h1, HugeInt h2);
	friend bool operator > (HugeInt h, long l);
	friend bool operator > (HugeInt h, string s);
	friend bool operator > (long l, HugeInt h);
	friend bool operator > (string s, HugeInt h);
	friend bool operator >= (HugeInt h1, HugeInt h2);
	friend bool operator >= (HugeInt h, long l);
	friend bool operator >= (HugeInt h, string s);
	friend bool operator >= (long l, HugeInt h);
	friend bool operator >= (string s, HugeInt h);
	friend bool operator < (HugeInt h1, HugeInt h2);
	friend bool operator < (HugeInt h, long l);
	friend bool operator < (HugeInt h, string s);
	friend bool operator < (long l, HugeInt h);
	friend bool operator < (string s, HugeInt h);
	friend bool operator <= (HugeInt h1, HugeInt h2);
	friend bool operator <= (HugeInt h, long l);
	friend bool operator <= (HugeInt h, string s);
	friend bool operator <= (long l, HugeInt h);
	friend bool operator <= (string s, HugeInt h);
	friend bool operator != (HugeInt h1, HugeInt h2);
	friend bool operator != (HugeInt h, long l);
	friend bool operator != (HugeInt h, string s);
	friend bool operator != (long l, HugeInt h);
	friend bool operator != (string s, HugeInt h);
	friend bool operator == (HugeInt h1, HugeInt h2);
	friend bool operator == (HugeInt h, long l);
	friend bool operator == (HugeInt h, string s);
	friend bool operator == (long l, HugeInt h);
	friend bool operator == (string s, HugeInt h);
	void operator = (const HugeInt& h);
	void operator += (HugeInt h);
	void operator += (long l);
	void operator += (string s);
	void operator -= (HugeInt h);
	void operator -= (long l);
	void operator -= (string s);
	void operator *= (HugeInt h);
	void operator *= (long l);
	void operator *= (string s);
	void operator /= (HugeInt h);
	void operator /= (long l);
	void operator /= (string s);
	void operator %= (HugeInt h);
	void operator %= (long l);
	void operator %= (string s);
	HugeInt operator -();
	HugeInt operator ++();
	HugeInt operator ++(int);
	HugeInt operator --();
	HugeInt operator --(int);
	friend ostream& operator << (ostream& out, HugeInt h);
	friend istream& operator >> (istream& in, HugeInt& h);
	void outputByHex();
	void outputByOct();
	string returnString();
	
	~HugeInt();
private:

	string StringMultiplyString(string, string);
	string StringAddString(string, string);
	string StringMinusString(string, string);
	string stringDevisionString(string, string);
	string longIntegerToString(long int);
	string octStringToDecString(string);
	string hexStringToDecString(string);
	int SubStract(int *p1, int len1, int *p2, int len2);
	int Division(const char num1[], const char num2[], char sum[]);
	void removeSymbol(string &);
	void addMinusSign(string &);
	bool isZeroString(const string&);
	bool isOctString(const string&);
	bool isHexString(const string&);
	bool isDecString(const string&);
	bool isEmptyString(const string&);
	bool isPositiveString(const string&);


	string m_sData;
};


/***************************
* �������ƣ�HugeInt
* �������ܣ�HugeInt����?�Ϲ��캯��
* �����б�����
* �������ݣ���
***************************/
HugeInt::HugeInt()
{
	m_sData = "0";
}

/***************************
* �������ƣ�HugeInt
* �������ܣ�HugeInt��Ĵ��ι���?��
* �����б���������
* �������ݣ���
***************************/
HugeInt::HugeInt(long int num)
{
	m_sData = longIntegerToString(num);
}

/***************************
* �������ƣ�HugeInt
* �������ܣ�HugeInt��Ĵ��ι���?��
* �����б����ַ���
* �������ݣ���
***************************/
HugeInt::HugeInt(string s)
{
	try {
		if (isHexString(s))
			m_sData = hexStringToDecString(s);
		else if (isOctString(s))
			m_sData = octStringToDecString(s);
		else if (isDecString(s))
			m_sData = s;
		else
			throw s;
	}
	catch (string)
	{
		cout << "�Ƿ��ַ�������" << endl;
	}
}

/***************************
* �������ƣ�HugeInt
* �������ܣ�HugeInt��Ŀ�������?��
* �����б���HugeInt��
* �������ݣ���
***************************/
HugeInt::HugeInt(const HugeInt& h)
{
	this->m_sData = h.m_sData;
}

/***************************
* �������ƣ�HugeInt
* �������ܣ�HugeInt�����������?
* �����б�����
* �������ݣ���
***************************/
HugeInt::~HugeInt()
{
}

/***************************
* �������ƣ�longIntegerToString
* �������ܣ���������ת��Ϊ�ַ�������
* �����б�������������
* �������ݣ��ַ���
***************************/
string HugeInt::longIntegerToString(long int num)
{
	if (num == 0)
		return "0";
	string temp;
	vector<int> nums;
	//�ж��Ƿ�Ϊ����
	if (num < 0)
	{
		num = -num;
		temp.append("-");
	}
	//��ȡ����λ
	while (num)
	{
		nums.push_back(num % 10);
		num /= 10;
	}
	//�õ�������temp
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		temp += nums[i] + '0';
	}
	return temp;
}

/***************************
* �������ƣ�octStringToDecString
* �������ܣ��˽����ַ���תʮ�����ַ���
* �����б����˽����ַ���
* �������ݣ�ʮ�����ַ���
***************************/
string HugeInt::octStringToDecString(string octString)
{
	string ret;
	if (!isPositiveString(octString))
		ret += '-';
	removeSymbol(octString);
	try {
		string tempStr = "0";
		char temp;
		for (size_t i = 1; i < octString.size(); i++)
		{
			tempStr = StringMultiplyString(tempStr, "8");
			temp = octString.at(i);
			string octTemp;
			octTemp = temp;
			tempStr = StringAddString(tempStr, octTemp);
		}
		ret += tempStr;
	}
	catch (const exception&)
	{
		cerr << "����Խ��" << endl;
		cerr << "������ַ����?�Ƿ��˽����ַ���" << endl;
		return "";
	}
	catch (...)
	{
		cerr << "δ֪����" << endl;
		return "";
	}

	return ret;
}

/***************************
* �������ƣ�hexStringToDecString
* �������ܣ�ʮ�������ַ���תʮ�����ַ���
* �����б���ʮ�������ַ���
* �������ݣ�ʮ�����ַ���
***************************/
string HugeInt::hexStringToDecString(string hexString)
{
	string hex[6] = { "10","11","12","13","14","15" };
	string ret;
	try {
		if (hexString.at(0) == '-')
		{
			ret += '-';
			removeSymbol(hexString);
		}

		string tempStr = "0";
		char temp;
		for (size_t i = 2; i < hexString.size(); i++)
		{
		
			tempStr = StringMultiplyString(tempStr, "16");
			temp = toupper(hexString.at(i));
			string hexTemp;
			if (temp >= 'A' && temp <= 'F')
				hexTemp = hex[temp - 'A'];
			else
				hexTemp = temp;
			tempStr = StringAddString(tempStr, hexTemp);
		}
		ret += tempStr;
	}
	catch (const exception&)
	{
		cerr << "����Խ��" << endl;
		cerr << "������ַ����?�Ƿ�ʮ�������ַ���" << endl;
		return "";
	}
	catch (...)
	{
		cerr << "δ֪����" << endl;
		return "";
	}

	return ret;
}

/***************************
* �������ƣ�isOctString
* �������ܣ��ж��Ƿ�Ϊ�˽����ַ���
* �����б����ַ���
* �������ݣ��ǰ˽����ַ���(true),���򷵻�(false)
***************************/
bool HugeInt::isOctString(const string& s)
{
	regex reg("[-]?0[0-7]+");

	if (regex_match(s, reg))
		return true;
	return false;
}

/***************************
* �������ƣ�isHexString
* �������ܣ��ж��Ƿ�Ϊʮ�������ַ���
* �����б����ַ���
* �������ݣ���ʮ�������ַ���(true),���򷵻�(false)
***************************/
bool HugeInt::isHexString(const string& s)
{
	regex reg("[-]?0[xX][A-Fa-f0-9]+");
	if (regex_match(s, reg))
		return true;
	return false;
}

/***************************
* �������ƣ�isDecString
* �������ܣ��ж��Ƿ�Ϊʮ�����ַ���
* �����б����ַ���
* �������ݣ���ʮ�����ַ���(true),���򷵻�(false)
***************************/
bool HugeInt::isDecString(const string& s)
{
	regex reg("[-]?[0-9]+");
	if (regex_match(s, reg))
		return true;
	return false;
}

/***************************
* �������ƣ�isZeroString
* �������ܣ��ж��ַ����Ƿ�Ϊ��
* �����б����ַ���
* �������ݣ������ַ���(true),���򷵻�(false)
***************************/
bool HugeInt::isZeroString(const string& s)
{
	regex reg("[-]?[0]+");
	if (regex_match(s,reg))
		return true;
	return false;
}

/***************************
* �������ƣ�removeSymbol
* �������ܣ�ȥ���ַ���������
* �����б�����
* �������ݣ���
***************************/
void HugeInt::removeSymbol(string & s)
{
	if (isEmptyString(s))
		return;
	if (s[0] != '-' && s[0] != '+')
		return;
	int size = s.size();
	for (int i = 1; i < size; i++)
	{
		s[i - 1] = s[i];
	}
	s[size - 1] = 0;
	s.resize(size - 1);
}

/***************************
* �������ƣ�StringMultiplyString
* �������ܣ��߾��ȳ˷���ʮ���ƣ�
* �����б����ַ������ַ���
* �������ݣ�����ַ���?
***************************/
string HugeInt::StringMultiplyString(string s1, string s2)
{
	string ret;

	if (isPositiveString(s1) ^ isPositiveString(s2))
		ret += '-';

	//����ռ�?
	int *a, *b, *c;
	int lena = s1.size();
	int lenb = s2.size();


	a = new int[lena + 2];
	b = new int[lenb + 2];
	c = new int[lena + lenb + 4];
	
	int lenc, i, j, x;
	for (int i = 0; i <= lena + 1; i++)
		a[i] = 0;
	for (int i = 0; i <= lenb + 1; i++)
		b[i] = 0;
	for (int i = 0; i <= lena + lenb + 2; i++)
		c[i] = 0;

	//����
	for (i = 1; i <= lena; i++) 
		a[i] = s1[lena - i] - '0';
	for (i = 1; i <= lenb; i++) 
		b[i] = s2[lenb - i] - '0';

	//�߾��ȳ˷�
	for (i = 1; i <= lena; i++)
	{
		x = 0;
		for (j = 1; j <= lenb; j++)
		{
			c[i + j - 1] = c[i + j - 1] + x + a[i] * b[j];
			x = c[i + j - 1] / 10;
			c[i + j - 1] %= 10;
		}
		c[i + lenb] = x;
	}
	lenc = lena + lenb;
	while (c[lenc] == 0)
		lenc--;

	for (i = lenc; i >= 1; i--)
		ret += c[i] + '0';
	
	delete[] a;
	delete[] b;
	delete[] c;
	return ret == "" ? "0" : ret;
}

/***************************
* �������ƣ�isPositiveString
* �������ܣ��ж��ַ����Ƿ�Ϊ��(ʮ����)
* �����б����ַ���
* �������ݣ�����true��������false��
***************************/
bool HugeInt::isPositiveString(const string& s)
{
	regex reg("[-][0-9]+");
	if (regex_match(s, reg))
		return false;
	return true;
}

/***************************
* �������ƣ�StringMultiplyString
* �������ܣ��߾��ȼӷ���ʮ���ƣ�
* �����б����ַ������ַ���
* �������ݣ�����ַ���?
***************************/
string HugeInt::StringAddString(string s1, string s2)
{
	string ret;
	if ((s1 == "0") && (s2 == "0"))
		return "0";

	try {
		if (s1.at(0) == '-' && s2.at(0) == '-')
		{
			ret += '-';
			removeSymbol(s1);
			removeSymbol(s2);
		}
		else if (s1.at(0) != '-' && s2.at(0) == '-')
		{
			removeSymbol(s2);
			return StringMinusString(s1,s2);
		}
		else if (s1.at(0) == '-' && s2.at(0) != '-')
		{
			removeSymbol(s1);
			return StringMinusString(s2, s1);
		}
	}
	catch (const exception&)
	{
		cerr << "����Խ��" << endl;
		cerr << "������ַ����?�Ƿ��˽����ַ���" << endl;
		return "";
	}
	catch (...)
	{
		cout << "δ֪����" << endl;
		return "";
	}

	int i, max;
	int *a, *b, *c;
	int lena = s1.size();
	int lenb = s2.size();
	
	max = lenb;
	if (lena > lenb)
		max = lena;

	a = new int[max + 1];
	b = new int[max + 1];
	c = new int[max + 2];

	for (int i = 0; i < max + 1; i++)
		a[i] = 0;
	for (int i = 0; i < max + 1; i++)
		b[i] = 0;
	for (int i = 0; i < max + 2; i++)
		c[i] = 0;
	
	
	for (int i = 1; i <= lena; i++) a[i] = s1[lena - i] - '0';
	for (int i = 1; i <= lenb; i++) b[i] = s2[lenb - i] - '0';

	for (i = 1; i <= max; i++)
	{
		c[i] += a[i] + b[i];
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	if (c[i + 1] > 0)
		max++;

	for (int i = max; i > 0; i--)
		ret += c[i] + '0';

	delete[] a, b, c;
	return ret;
}

/***************************
* �������ƣ�StringMinusString
* �������ܣ��߾��ȼ�����ʮ���ƣ�
* �����б����ַ������ַ���
* �������ݣ�����ַ���?
***************************/
string HugeInt::StringMinusString(string s1, string s2)
{
	string ret = "";
	string temp = "0";

	string s3;

	int size = s1.size();
	if (s2.size() > size)
	{
		size = s2.size();
	}
	size++;
	int* a, *b, *c;

	a = new int[size];
	b = new int[size];
	c = new int[size];

	for (int i = 0; i < size; i++)
	{
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
	}

	int lena, lenb, lenc, i;
	if (s1.size() < s2.size() || s1.size() == s2.size() && s1 < s2)
	{
		s3 = s1;
		s1 = s2;
		s2 = s3;
		ret += "-";
	}
	lena = s1.size();
	lenb = s2.size();
	for (i = 1; i <= lena; i++)
		a[i] = s1[lena - i] - '0';
	for (i = 1; i <= lenb; i++)
		b[i] = s2[lenb - i] - '0';
	for (i = 1; i <= lena; i++)
	{
		if (a[i] < b[i])
		{
			a[i] += 10;
			a[i + 1]--;
		}
		c[i] = a[i] - b[i];
	}
	while (c[lena] == 0)
		lena--;
	if (lena < 0)
	{
		delete[] a;
		delete[] b;
		delete[] c;
		return temp;
	}
	for (i = lena; i >= 1; i--)
	{
		ret += char(c[i]+ '0');
	}
	delete[] a;
	delete[] b;
	delete[] c;
	return ret;



}

/***************************
* �������ƣ�isEmptyString
* �������ܣ��ж��ַ����Ƿ�Ϊ��
* �����б����ַ���
* �������ݣ��գ�true������false��
***************************/
bool HugeInt::isEmptyString(const string& s)
{
	if (s.size() == 0)
		return true;
	return false;
}

/***************************
* �������ƣ�addMinusSign
* �������ܣ����ַ����Ӹ���
* �����б����ַ���
* �������ݣ���
***************************/
void HugeInt::addMinusSign(string & s)
{
	if (s == "0")
		return;
	string s1 = "-";
	s = s1 + s;
}

/***************************
* �������ƣ�operator +
* �������ܣ������������?
* �����б������������࣬����������
* �������ݣ�����������
***************************/
HugeInt operator + (HugeInt h1, HugeInt h2)
{
	return HugeInt(h1.StringAddString(h1.m_sData , h2.m_sData));
}

/***************************
* �������ƣ�operator +
* �������ܣ���������+������
* �����б������������࣬����������
* �������ݣ�����������
***************************/
HugeInt operator + (HugeInt h, long l)
{
	HugeInt longHugh = HugeInt(l);
	return HugeInt(h.StringAddString(h.m_sData, longHugh.m_sData));
}

/***************************
* �������ƣ�operator +
* �������ܣ���������+�ַ���
* �����б������������࣬�ַ���
* �������ݣ�����������
***************************/
HugeInt operator + (HugeInt h, string s)
{
	return HugeInt(h.StringAddString(h.m_sData, s));
}

/***************************
* �������ƣ�operator +
* �������ܣ������� + ��������
* �����б���������������������
* �������ݣ�����������
***************************/
HugeInt operator + (long l, HugeInt h)
{
	return h + l;
}

/***************************
* �������ƣ�operator +
* �������ܣ��ַ��� + ��������
* �����б����ַ��� ������������
* �������ݣ�����������
***************************/
HugeInt operator + (string s, HugeInt h)
{
	return h + s;
}

/***************************
* �������ƣ�operator -
* �������ܣ������������?
* �����б������������࣬����������
* �������ݣ�����������
***************************/
HugeInt operator - (HugeInt h1, HugeInt h2)
{
	if (h1.isPositiveString(h2.m_sData))
		h1.addMinusSign(h2.m_sData);
	else
		h1.removeSymbol(h2.m_sData);

	return h1 + h2;
}

/***************************
* �������ƣ�operator -
* �������ܣ��������� - ������
* �����б������������࣬������
* �������ݣ�����������
***************************/
HugeInt operator - (HugeInt h, long l)
{
	HugeInt longHuge = HugeInt(l);
	if (h.isPositiveString(longHuge.m_sData))
		h.addMinusSign(longHuge.m_sData);
	else
		h.removeSymbol(h.m_sData);

	return h + longHuge;
}

/***************************
* �������ƣ�operator -
* �������ܣ��������� - �ַ���
* �����б������������࣬�ַ���
* �������ݣ�����������
***************************/
HugeInt operator - (HugeInt h, string s)
{
	if (h.isPositiveString(s))
		h.addMinusSign(s);
	else
		h.removeSymbol(s);

	return h + s;
}

/***************************
* �������ƣ�operator -
* �������ܣ������� - ��������
* �����б���������������������
* �������ݣ�����������
***************************/
HugeInt operator - (long l, HugeInt h)
{
	if (h.isPositiveString(h.m_sData))
		h.addMinusSign(h.m_sData);
	else
		h.removeSymbol(h.m_sData);

	return l + h;
}

/***************************
* �������ƣ�operator -
* �������ܣ��ַ��� - ��������
* �����б����ַ��� ������������
* �������ݣ�����������
***************************/
HugeInt operator - (string s, HugeInt h)
{
	if (h.isPositiveString(h.m_sData))
		h.addMinusSign(h.m_sData);
	else
		h.removeSymbol(h.m_sData);

	return s + h;
}

/***************************
* �������ƣ�operator *
* �������ܣ��������� * ��������
* �����б������������� ������������
* �������ݣ�����������
***************************/
HugeInt operator * (HugeInt h1, HugeInt h2)
{
	return HugeInt(h1.StringMultiplyString(h1.m_sData, h2.m_sData));
}

/***************************
* �������ƣ�operator *
* �������ܣ��������� * ������
* �����б������������� ��������
* �������ݣ�����������
***************************/
HugeInt operator * (HugeInt h, long l)
{
	HugeInt longHuge = HugeInt(l);
	return HugeInt(h.StringMultiplyString(h.m_sData, longHuge.m_sData));
}

/***************************
* �������ƣ�operator *
* �������ܣ��������� * �ַ���
* �����б������������� ���ַ���
* �������ݣ�����������
***************************/
HugeInt operator * (HugeInt h, string s)
{
	return HugeInt(h.StringMultiplyString(h.m_sData, s));
}

/***************************
* �������ƣ�operator *
* �������ܣ������� * ����������
* �����б��������� ������������
* �������ݣ�����������
***************************/
HugeInt operator * (long l, HugeInt h)
{
	return h * l;
}

/***************************
* �������ƣ�operator *
* �������ܣ��ַ��� * ����������
* �����б����ַ��� ������������
* �������ݣ�����������
***************************/
HugeInt operator * (string s, HugeInt h)
{
	return h * s;
}

/***************************
* �������ƣ�stringDevisionString
* �������ܣ��ַ������?
* �����б����ַ��� ���ַ���
* �������ݣ��ַ���
***************************/
string HugeInt::stringDevisionString(string s1, string s2)
{

	string symbol = "";

	if (isPositiveString(s1) ^ isPositiveString(s2))
		symbol += "-";

	removeSymbol(s1);
	removeSymbol(s2);

	char* temp;
	int size = s1.size();
	temp = new char[size + 2];
	int a = Division(s1.c_str(), s2.c_str(), temp);
	
	if (strlen(temp) == 0 || a == -1)
		return "0";

	return symbol + string(temp);
}

/***************************
* �������ƣ�SubStract 
* �������ܣ��ж��Ƿ񹻼�
* �����б���ָ�룬����1��ָ�룬����2
* �������ݣ�������������ĳ���?
***************************/
int HugeInt::SubStract(int *p1, int len1, int *p2, int len2)
{
	int i;
	if (len1 < len2)
		return -1;
	if (len1 == len2)
	{                        // �ж�p1 > p2
		for (i = len1 - 1; i >= 0; i--)
		{
			if (p1[i] > p2[i])   // ������������������������
				break;
			else if (p1[i] < p2[i]) // ���򷵻�-1
				return -1;
		}
	}
	for (i = 0; i <= len1 - 1; i++)  // �ӵ�λ��ʼ������
	{
		p1[i] -= p2[i];         // ���? 
		if (p1[i] < 0)           // ���Ƿ���Ҫ��λ
		{   // ��λ 
			p1[i] += 10;
			p1[i + 1]--;
		}
	}
	for (i = len1 - 1; i >= 0; i--)  // ���ҽ�������λ
	{
		if (p1[i])             //���λ��һ�����?0
			return (i + 1);       //�õ�λ��������
	}
	return 0;                   //������ȵ�ʱ�򷵻�?0
}


/***************************
* �������ƣ�operator *
* �������ܣ��ַ��� * ����������
* �����б����ַ��� ������������
* �������ݣ�����������
***************************/
int HugeInt::Division(const char num1[], const char num2[], char sum[])
{
	int k, i, j;
	int len1, len2, len = 0;     //����λ��

	len1 = strlen(num1);       //��ô�����λ��?
	len2 = strlen(num2);

	const int MAX = 10000;

	int dValue;                //���������λ��?
	int nTemp;                 //Subtract��������ֵ
	int num_a[10000] = { 0 };      //������
	int num_b[10000] = { 0 };      //����
	int num_c[10000] = { 0 };      //�� 



	//�������ַ�ת�������������ҷ�ת���������������� 
	for (j = 0, i = len1 - 1; i >= 0; j++, i--)
		num_a[j] = num1[i] - '0';
	for (j = 0, i = len2 - 1; i >= 0; j++, i--)
		num_b[j] = num2[i] - '0';

	if (len1 < len2)          //���������С�ڳ�����ֱ�ӷ���?-1����ʾ����?0
	{
		return -1;
	}
	dValue = len1 - len2;      //���λ��?
	for (i = len1 - 1; i >= 0; i--)    //����������ʹ�ó����ͱ�����λ�����?
	{
		if (i >= dValue)
			num_b[i] = num_b[i - dValue];
		else                         //��λ��0
			num_b[i] = 0;
	}
	len2 = len1;
	for (j = 0; j <= dValue; j++)    //�ظ����ã�ͬʱ��¼���ɹ��Ĵ�������Ϊ��
	{
		while ((nTemp = SubStract(num_a, len1, num_b + j, len2 - j)) >= 0)
		{
			len1 = nTemp;            //�������?
			num_c[dValue - j]++;       //ÿ�ɹ���һ�Σ����̵���Ӧλ��1
		}
	}
	// �����̵�λ���������̷���sum�ַ������� 
	for (i = MAX - 1; num_c[i] == 0 && i >= 0; i--);  //������λ0����ȡ�̵�λ�� 
	if (i >= 0)
		len = i + 1; // ����λ�� 
	for (j = 0; i >= 0; i--, j++)     // ��������Ƶ�sum������ 
		sum[j] = num_c[i] + '0';
	sum[j] = '\0';   // sum�ַ������β��?0 
	return len;      // �����̵�λ�� 
}

/***************************
* �������ƣ�operator /
* �������ܣ����������� / ����������
* �����б������������� ������������
* �������ݣ�����������
***************************/
HugeInt operator / (HugeInt h1, HugeInt h2)
{
	return HugeInt(h1.stringDevisionString(h1.m_sData, h2.m_sData));

}

/***************************
* �������ƣ�operator /
* �������ܣ����������� / ������
* �����б������������� ��������
* �������ݣ�����������
***************************/
HugeInt operator / (HugeInt h, long l)
{
	return HugeInt(h.stringDevisionString(h.m_sData, HugeInt(l).m_sData));
}

/***************************
* �������ƣ�operator /
* �������ܣ����������� / �ַ���
* �����б������������� ���ַ���
* �������ݣ�����������
***************************/
HugeInt operator / (HugeInt h, string s)
{
	return HugeInt(h.stringDevisionString(h.m_sData, s));
}

/***************************
* �������ƣ�operator /
* �������ܣ����������� / ������
* �����б������������� ��������
* �������ݣ�����������
***************************/
HugeInt operator / (long l, HugeInt h)
{
	return HugeInt(h.stringDevisionString(HugeInt(l).m_sData, h.m_sData));
}


/***************************
* �������ƣ�operator /
* �������ܣ��ַ��� / ����������
* �����б����ַ��� ������������
* �������ݣ�����������
***************************/
HugeInt operator / (string s, HugeInt h)
{
	return HugeInt(h.stringDevisionString(s, h.m_sData));
}

/***************************
* �������ƣ�operator %
* �������ܣ����������� % ����������
* �����б������������� ������������
* �������ݣ�����������
***************************/
HugeInt operator % (HugeInt h1, HugeInt h2)
{
	return h1 - h1 / h2 * h2 ;
}

/***************************
* �������ƣ�operator %
* �������ܣ����������� % ������
* �����б������������� ��������
* �������ݣ�����������
***************************/
HugeInt operator % (HugeInt h, long l)
{
	return h - h / l * l;
}

/***************************
* �������ƣ�operator %
* �������ܣ����������� % �ַ���
* �����б������������� ���ַ���
* �������ݣ�����������
***************************/
HugeInt operator % (HugeInt h, string s)
{
	return h - h / s * s;
}

/***************************
* �������ƣ�operator %
* �������ܣ������� % ����������
* �����б��������� ������������
* �������ݣ�����������
***************************/
HugeInt operator % (long l, HugeInt h)
{
	return l - l / h * h;
}

/***************************
* �������ƣ�operator %
* �������ܣ��ַ��� % ����������
* �����б����ַ��� ������������
* �������ݣ�����������
***************************/
HugeInt operator % (string s, HugeInt h)
{
	return s - s / h * h;
}

/***************************
* �������ƣ�operator >
* �������ܣ����������� > ����������
* �����б������������� ������������
* �������ݣ�����������
***************************/
bool operator > (HugeInt h1, HugeInt h2)
{
	HugeInt h = h1 - h2;
	try {
		if (h.m_sData.at(0) == '-' || h.m_sData == "0")
			return false;
		return true;
	}
	catch (out_of_range&)
	{
		cerr << "����Խ��" << endl;
	}
	catch(...)
	{
		cerr << "δ֪����" << endl;
	}
	return false;	
}

/***************************
* �������ƣ�operator >
* �������ܣ����������� > ������
* �����б������������� ��������
* �������ݣ�bool
***************************/
bool operator > (HugeInt h, long l)
{
	HugeInt h1 = h - l;
	try {
		if (h1.m_sData.at(0) == '-' || h1.m_sData == "0")
			return false;
		return true;
	}
	catch (out_of_range&)
	{
		cerr << "����Խ��" << endl;
	}
	catch (...)
	{
		cerr << "δ֪����" << endl;
	}
	return false;
}

/***************************
* �������ƣ�operator >
* �������ܣ����������� > �ַ���
* �����б������������� ���ַ���
* �������ݣ�bool
***************************/
bool operator > (HugeInt h, string s)
{
	HugeInt h1 = h - s;
	try {
		if (h1.m_sData.at(0) == '-' || h1.m_sData == "0")
			return false;
		return true;
	}
	catch (out_of_range&)
	{
		cerr << "����Խ��" << endl;
	}
	catch (...)
	{
		cerr << "δ֪����" << endl;
	}
	return false;
}

/***************************
* �������ƣ�operator >
* �������ܣ������� > ����������
* �����б��������� ������������
* �������ݣ�����������
***************************/
bool operator > (long l, HugeInt h)
{
	HugeInt h1 = l - h;
	try {
		if (h1.m_sData.at(0) == '-' || h1.m_sData == "0")
			return false;
		return true;
	}
	catch (out_of_range&)
	{
		cerr << "����Խ��" << endl;
	}
	catch (...)
	{
		cerr << "δ֪����" << endl;
	}
	return false;
}

/***************************
* �������ƣ�operator >
* �������ܣ��ַ��� > ����������
* �����б����ַ��� ������������
* �������ݣ�����������
***************************/
bool operator > (string s, HugeInt h)
{
	HugeInt h1 = s - h;
	try {
		if (h1.m_sData.at(0) == '-' || h1.m_sData == "0")
			return false;
		return true;
	}
	catch (out_of_range&)
	{
		cerr << "����Խ��" << endl;
	}
	catch (...)
	{
		cerr << "δ֪����" << endl;
	}
	return false;
}

/***************************
* �������ƣ�operator >=
* �������ܣ����������� >= ����������
* �����б������������� ������������
* �������ݣ�bool
***************************/
bool operator >= (HugeInt h1, HugeInt h2)
{
	HugeInt h = h1 - h2;
	try {
		if (h.m_sData.at(0) == '-')
			return false;
		return true;
	}
	catch (out_of_range&)
	{
		cerr << "����Խ��" << endl;
	}
	catch (...)
	{
		cerr << "δ֪����" << endl;
	}
	return false;
}

/***************************
* �������ƣ�operator >=
* �������ܣ����������� >= ������
* �����б������������� ��������
* �������ݣ�bool
***************************/
bool operator >= (HugeInt h, long l)
{
	HugeInt h1 = h - l;
	try {
		if (h1.m_sData.at(0) == '-')
			return false;
		return true;
	}
	catch (out_of_range&)
	{
		cerr << "����Խ��" << endl;
	}
	catch (...)
	{
		cerr << "δ֪����" << endl;
	}
	return false;
}

/***************************
* �������ƣ�operator >=
* �������ܣ����������� >= �ַ���
* �����б������������� ���ַ���
* �������ݣ�bool
***************************/
bool operator >= (HugeInt h, string s)
{
	HugeInt h1 = h - s;
	try {
		if (h1.m_sData.at(0) == '-')
			return false;
		return true;
	}
	catch (out_of_range&)
	{
		cerr << "����Խ��" << endl;
	}
	catch (...)
	{
		cerr << "δ֪����" << endl;
	}
	return false;
}

/***************************
* �������ƣ�operator >=
* �������ܣ������� >= ����������
* �����б��������� ������������
* �������ݣ�bool
***************************/
bool operator >= (long l, HugeInt h)
{
	HugeInt h1 = l - h;
	try {
		if (h1.m_sData.at(0) == '-')
			return false;
		return true;
	}
	catch (out_of_range&)
	{
		cerr << "����Խ��" << endl;
	}
	catch (...)
	{
		cerr << "δ֪����" << endl;
	}
	return false;
}

/***************************
* �������ƣ�operator >=
* �������ܣ��ַ��� >= ����������
* �����б����ַ��� ������������
* �������ݣ�bool
***************************/
bool operator >= (string s, HugeInt h)
{
	HugeInt h1 = s - h;
	try {
		if (h1.m_sData.at(0) == '-')
			return false;
		return true;
	}
	catch (out_of_range&)
	{
		cerr << "����Խ��" << endl;
	}
	catch (...)
	{
		cerr << "δ֪����" << endl;
	}
	return false;
}
/***************************
* �������ƣ�operator <
* �������ܣ����������� < ����������
* �����б������������� ������������
* �������ݣ�bool
***************************/
bool operator < (HugeInt h1, HugeInt h2)
{
	return h2 >= h1;
}

/***************************
* �������ƣ�operator <
* �������ܣ����������� >= ������
* �����б������������� ��������
* �������ݣ�bool
***************************/
bool operator < (HugeInt h, long l)
{
	return l >= h;
}

/***************************
* �������ƣ�operator <
* �������ܣ����������� < �ַ���
* �����б������������� ���ַ���
* �������ݣ�bool
***************************/
bool operator < (HugeInt h, string s)
{
	return s >= h;
}

/***************************
* �������ƣ�operator <
* �������ܣ������� < ����������
* �����б��������� ������������
* �������ݣ�bool
***************************/
bool operator < (long l, HugeInt h)
{
	return h >= l;
}

/***************************
* �������ƣ�operator <
* �������ܣ��ַ��� < ����������
* �����б����ַ��� ������������
* �������ݣ�bool
***************************/
bool operator < (string s, HugeInt h)
{
	return h >= s;
}

/***************************
* �������ƣ�operator <=
* �������ܣ����������� <= ����������
* �����б������������� ������������
* �������ݣ�bool
***************************/
bool operator <= (HugeInt h1, HugeInt h2)
{
	return h2 > h1;
}

/***************************
* �������ƣ�operator <=
* �������ܣ����������� <= ������
* �����б������������� ��������
* �������ݣ�bool
***************************/
bool operator <= (HugeInt h, long l)
{
	return l > h;
}

/***************************
* �������ƣ�operator <=
* �������ܣ����������� <= �ַ���
* �����б������������� ���ַ���
* �������ݣ�bool
***************************/
bool operator <= (HugeInt h, string s)
{
	return s > h;
}

/***************************
* �������ƣ�operator <=
* �������ܣ������� <= ����������
* �����б��������� ������������
* �������ݣ�bool
***************************/
bool operator <= (long l, HugeInt h)
{
	return h > l;
}

/***************************
* �������ƣ�operator <=
* �������ܣ��ַ��� <= ����������
* �����б����ַ��� ������������
* �������ݣ�bool
***************************/
bool operator <= (string s, HugeInt h)
{
	return h > s;
}

/***************************
* �������ƣ�operator !=
* �������ܣ����������� != ����������
* �����б������������� ������������
* �������ݣ�bool
***************************/
bool operator != (HugeInt h1, HugeInt h2)
{
	return h1.m_sData != h2.m_sData;
}

/***************************
* �������ƣ�operator !=
* �������ܣ����������� != ������
* �����б������������� ��������
* �������ݣ�bool
***************************/
bool operator != (HugeInt h, long l)
{
	return h.m_sData != HugeInt(l).m_sData;
}

/***************************
* �������ƣ�operator !=
* �������ܣ����������� != �ַ���
* �����б������������� ���ַ���
* �������ݣ�bool
***************************/
bool operator != (HugeInt h, string s)
{
	return h.m_sData != s;
}

/***************************
* �������ƣ�operator !=
* �������ܣ������� != ����������
* �����б��������� ������������
* �������ݣ�bool
***************************/
bool operator != (long l, HugeInt h)
{
	return h != l;
}

/***************************
* �������ƣ�operator !=
* �������ܣ��ַ��� != ����������
* �����б����ַ��� ������������
* �������ݣ�bool
***************************/
bool operator != (string s, HugeInt h)
{
	return h != s;
}

/***************************
* �������ƣ�operator ==
* �������ܣ����������� == ����������
* �����б������������� ������������
* �������ݣ�bool
***************************/
bool operator == (HugeInt h1, HugeInt h2)
{
	return !(h1 != h2);
}

/***************************
* �������ƣ�operator ==
* �������ܣ����������� == ������
* �����б������������� ��������
* �������ݣ�bool
***************************/
bool operator == (HugeInt h, long l)
{
	return !(h != l);
}

/***************************
* �������ƣ�operator ==
* �������ܣ����������� == �ַ���
* �����б������������� ���ַ���
* �������ݣ�bool
***************************/
bool operator == (HugeInt h, string s)
{
	return !(h != s);
}

/***************************
* �������ƣ�operator ==
* �������ܣ������� == ����������
* �����б��������� ������������
* �������ݣ�bool
***************************/
bool operator == (long l, HugeInt h)
{
	return !(l != h);
}

/***************************
* �������ƣ�operator ==
* �������ܣ��ַ��� == ����������
* �����б����ַ��� ������������
* �������ݣ�bool
***************************/
bool operator == (string s, HugeInt h)
{
	return !(s != h);
}

/***************************
* �������ƣ�operator +=
* �������ܣ����������� += ����������
* �����б�������������
* �������ݣ�void
***************************/
void HugeInt::operator += (HugeInt h)
{
	*this = *this + h;
}

/***************************
* �������ƣ�operator +=
* �������ܣ����������� += ������
* �����б���������
* �������ݣ�void
***************************/
void HugeInt::operator += (long l)
{
	*this = *this + l;
}

/***************************
* �������ƣ�operator +=
* �������ܣ����������� += �ַ���
* �����б����ַ���
* �������ݣ�void
***************************/
void HugeInt::operator += (string s)
{
	*this = *this + s;
}

/***************************
* �������ƣ�operator -=
* �������ܣ����������� -= ����������
* �����б�������������
* �������ݣ�void
***************************/
void HugeInt::operator -= (HugeInt h)
{
	*this = *this - h;
}

/***************************
* �������ƣ�operator -=
* �������ܣ����������� -= ������
* �����б���������
* �������ݣ�void
***************************/
void HugeInt::operator -= (long l)
{
	*this = *this - l;
}

/***************************
* �������ƣ�operator -=
* �������ܣ����������� -= �ַ���
* �����б����ַ���
* �������ݣ�void
***************************/
void HugeInt::operator -= (string s)
{
	*this = *this - s;
}

/***************************
* �������ƣ�operator *=
* �������ܣ����������� *= ����������
* �����б�������������
* �������ݣ�void
***************************/
void HugeInt::operator *= (HugeInt h)
{
	*this = *this * h;
}

/***************************
* �������ƣ�operator *=
* �������ܣ����������� *= ������
* �����б���������
* �������ݣ�void
***************************/
void HugeInt::operator *= (long l)
{
	*this = *this * l;
}

/***************************
* �������ƣ�operator *=
* �������ܣ����������� *= �ַ���
* �����б����ַ��� 
* �������ݣ�void
***************************/
void HugeInt::operator *= (string s)
{
	*this = *this * s;
}

/***************************
* �������ƣ�operator /=
* �������ܣ����������� /= ����������
* �����б������������� 
* �������ݣ�void
***************************/
void HugeInt::operator /= (HugeInt h)
{
	*this = *this / h;
}

/***************************
* �������ƣ�operator /=
* �������ܣ����������� /= ������
* �����б���������
* �������ݣ�void
***************************/
void HugeInt::operator /= (long l)
{
	*this = *this / l;
}

/***************************
* �������ƣ�operator /=
* �������ܣ����������� /= �ַ���
* �����б����ַ��� 
* �������ݣ�void
***************************/
void HugeInt::operator /= (string s)
{
	*this = *this / s;
}

/***************************
* �������ƣ�operator %=
* �������ܣ����������� %= ����������
* �����б������������� 
* �������ݣ�void
***************************/
void HugeInt::operator %= (HugeInt h)
{
	*this = *this % h;
}

/***************************
* �������ƣ�operator %=
* �������ܣ����������� %= ������
* �����б���������
* �������ݣ�void
***************************/
void HugeInt::operator %= (long l)
{
	*this = *this % l;
}

/***************************
* �������ƣ�operator %=
* �������ܣ����������� %= �ַ���
* �����б����ַ��� 
* �������ݣ�void
***************************/
void HugeInt::operator %= (string s)
{
	*this = *this % s;
}

/***************************
* �������ƣ�operator -
* �������ܣ�-���������� 
* �����б�����
* �������ݣ�void
***************************/
HugeInt HugeInt::operator -()
{
	if (this->isPositiveString(this->m_sData))
	{
		this->addMinusSign(this->m_sData);
	}
	else
	{
		this->removeSymbol(this->m_sData);
	}
	return *this;
}

/***************************
* �������ƣ�operator ++
* �������ܣ�++����������
* �����б�����
* �������ݣ�void
***************************/
HugeInt HugeInt::operator ++()
{
	*this = *this + 1;
	return *this;
}

/***************************
* �������ƣ�operator ++
* �������ܣ�����������++
* �����б�����
* �������ݣ�void
***************************/
HugeInt HugeInt::operator ++(int)
{
	HugeInt temp = *this;
	++*this;
	return temp;
}

/***************************
* �������ƣ�operator --
* �������ܣ�--����������
* �����б�����
* �������ݣ�void
***************************/
HugeInt HugeInt::operator --()
{
	*this = *this - "1";
	return *this;
}

/***************************
* �������ƣ�operator --
* �������ܣ�����������--
* �����б�����
* �������ݣ�void
***************************/
HugeInt HugeInt::operator --(int)
{
	HugeInt temp = *this;
	--*this;
	return temp;
}

/***************************
* �������ƣ�operator <<
* �������ܣ�������������������
* �����б��������?����������
* �������ݣ������?
***************************/
ostream& operator << (ostream& out, HugeInt h)
{
	out << h.m_sData;
	return out;
}

/***************************
* �������ƣ�operator >>
* �������ܣ��������������������? >>
* �����б��������࣬����������
* �������ݣ�������
***************************/
istream& operator >> (istream& in, HugeInt& h)
{
	string s;
	in >> s;

	h = HugeInt(s);
	return in;
}

/***************************
* �������ƣ�outputByHex
* �������ܣ�ʮ���������?
* �����б�����
* �������ݣ�void
***************************/
void HugeInt::outputByHex()
{
	char temp[] = "0123456789ABCDEF";

	list<char> list1;
	string s = this->m_sData;
	HugeInt h = HugeInt(s);
	while (h.m_sData != "0")
	{
		list1.push_front(temp[stoi((h % "16").m_sData)]);
		h /= "16";
	}

	list<char>::reverse_iterator iter;

	cout << "0X";

	for (iter = list1.rbegin(); iter != list1.rend(); iter++)
	{
		cout << *iter;
	}
}

/***************************
* �������ƣ�outputByOct
* �������ܣ��˽������?
* �����б�����
* �������ݣ�void
***************************/
void HugeInt::outputByOct()
{
	char temp[] = "01234567";

	list<char> list1;
	string s = this->m_sData;
	HugeInt h = HugeInt(s);
	while (h.m_sData != "0")
	{
		list1.push_front(temp[stoi((h % "8").m_sData)]);
		h /= "8";
	}

	cout << "0";

	list<char>::reverse_iterator iter;
	for (iter = list1.rbegin(); iter != list1.rend(); iter++)
	{
		cout << *iter;
	}
}

/***************************
* �������ƣ�operator =
* �������ܣ�����������ĸ�ֵ�����
* �����б�����ֵ����
* �������ݣ���
***************************/
void HugeInt::operator = (const HugeInt& h)
{
	this->m_sData = h.m_sData;
}

string HugeInt::returnString() {
	return this->m_sData; 
}

int main()
{
	
}