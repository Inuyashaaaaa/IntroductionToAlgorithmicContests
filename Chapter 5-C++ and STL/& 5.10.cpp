#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
#include<sstream>
#include<algorithm>
using namespace std;

const int maxP = 200;
const int maxC = 100;

struct Player {
	string name;
	bool amateur;
	int rd[4];
	int rnds;
	int sum1, sum2;
	int rank;
}player[maxP];

int n;
double pluse, p[100];

bool cmp1(const Player& p1, const Player& p2) {
	if (p1.sum1 < 0 && p2.sum1 < 0) return false;
	if (p1.sum1 < 0) return false;
	if (p2.sum1 < 0) return true;
	return p1.sum1 < p2.sum1;
}

bool cmp2(const Player& p1, const Player& p2) {
	if (p1.rnds != 0 && p2.rnds != 0) {
		if (p1.rnds != p2.rnds) return p2.rnds < p1.rnds;
		if (p1.sum2 != p2.sum2) return p1.sum2 < p2.sum2;
		return p1.name < p2.name;
	}
	if (p1.rnds != 0) return false;
	if (p2.rnds != 0) return true;
	if (p1.sum2 != p2.sum2) return p1.sum2 < p2.sum2;
	return p1.name < p2.name;
}

void print() {

	//头头
	cout << "Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money Won" << endl;
	cout << "-----------------------------------------------------------------------" << endl;

	int i = 0, pos = 0;
	while (i < n) {
		if (player[i].rnds != 0) {
			cout << player[i].name;
			cout << "           ";
			for (int j = 0; j < player[i].rnds - 1; j++) {
				cout << left << setw(5) << player[i].rd[j];
			}
			for (int j = 0; j <= 4 - player[i].rnds; j++) {
				cout << "     ";
			}
			cout << "DQ" << endl;
			i++;
			continue;
		}
		int j = i;
		int cnt = 0;
		bool haveMoney = false;
		double tot = 0.0;
		while (j < n && player[i].sum2 == player[j].sum2) {
			if (!player[j].amateur) {
				cnt++;
				if (pos < 70) {
					haveMoney = true;
					tot += p[pos++];
				}
			}
			j++;
		}

		int rank = i + 1;
		double amout = pluse * tot / cnt;
		while (i < j) {
			cout << player[i].name << " ";
			char t[5];
			sprintf(t, "%d%c", rank, cnt > 1 && haveMoney && !player[i].amateur ? 'T' : ' ');
			cout << left << setw(10) << t;
			for (int e = 0; e < 4; e++) {
				cout << left << setw(5) << player[i].rd[e];
			}
			if (!player[i].amateur && haveMoney) {
				cout << left << setw(10) << player[i].sum2;
				cout << right << "$" << setw(9) << fixed << setprecision(2) << amout / 100.0 << endl;
			}
			else {
				cout << left << player[i].sum2 << endl;
			}
			i++;
		}
	}
}

int main() {
    // freopen("5-10.in","r",stdin);
    // freopen("5-10.out","w",stdout);
	int T;
	cin >> T;
	while (T--) {
        cin >> pluse;
		for (int i = 0; i < 70; i++) {
			cin >> p[i];
		}

		cin >> n;
		getchar();
		for (int i = 0; i < n; i++) {
			player[i].sum1 = player[i].sum2 = player[i].rnds = 0;
			memset(player[i].rd, -1, sizeof(player[i].rd));
			char buf[100];
			cin.getline(buf, 100);
			string s = buf;
			player[i].name = s.substr(0, 20);
			if (player[i].name.find('*') != string::npos)
				player[i].amateur = true;
            else 
                player[i].amateur = false;
			stringstream ss(s.substr(21, 100));

			for (int j = 0; j < 4; j++) {
				ss >> s;
				if (s == "DQ") {
					player[i].rnds = j + 1;
					if (j < 2)
						player[i].sum1 = -1;
					break;
				}
				player[i].rd[j] = stoi(s);
                player[i].sum2 += player[i].rd[j];
				if (j == 1)
					player[i].sum1 = player[i].rd[0] + player[i].rd[1];
				if (j == 3)
					player[i].sum2 = player[i].sum1 + player[i].rd[2] + player[i].rd[3];
			}
		}
		sort(player, player + n, cmp1);
		for (int i = 69; i < n; i++) {
			if (i == n - 1 || player[i].sum1 != player[i + 1].sum1) {
				n = i + 1;
				break;
			}
		}
		sort(player, player + n, cmp2);
		print();
		// for (int i = 0; i < n; i++) {
		// 	cout << player[i].name << " " <<
		// 		player[i].rd[0] << " " <<
		// 		player[i].rd[1] << " " <<
		// 		player[i].rd[2] << " " <<
		// 		player[i].rd[3] << " " <<
		// 		player[i].sum2 << endl;
		// }
        if(T)
        cout << endl;
	}
	//system("pause");
	return 0;
}


