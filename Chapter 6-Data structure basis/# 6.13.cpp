#include<bits/stdc++.h>
using namespace std;
const int maxr = 20 + 5;
const int maxc = 10 + 2;

struct Cell {
	bool isDigit;
	int v;
	vector<string> vVec;
	vector<bool> sign; //0 表示负
	set<pair<int,int>> ccc; //表示表达式子。
};

int G[maxr][maxc][maxr][maxc];
bool isdigit1[maxr][maxc];
int vis[maxr][maxc];
int n, m;
int kase = 0;

bool dfs(int i, int j) {
	vis[i][j] = -1;	
	for (int k = 0; k < n; k++) {
		for (int l = 0; l < m; l++) {
			if (G[i][j][k][l]) {
				if (vis[k][l] == -1) {
					return false;
				}
				if (!vis[k][l] &&  !dfs(k, l)) return false;
			}
		}
	}
	vis[i][j] = 1;
	return true;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (cin >> n >> m && (n || m)) {
		Cell c[maxr][maxc];
		memset(vis, 0, sizeof(vis));
		memset(G, 0, sizeof(G));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				string temp;
				cin >> temp;
				stringstream ss(temp);
				char ch;
				c[i][j].isDigit = false;
				bool first = true;
				while ((ch = ss.peek()) != EOF) {
					if (isalpha(ch)) {
						if (first)
							c[i][j].sign.push_back('+');
						char ch1, ch2;
						ss >> ch1 >> ch2;
						string s;
						s += ch1;
						s += ch2;
						c[i][j].vVec.push_back(s);
						G[ch1 - 'A'][ch2 - '0'][i][j] = 1;
						c[i][j].ccc.insert(make_pair(ch1 - 'A', ch2 - '0'));
					}
					else if (ch == '-' || ch == '+') {
						char ch1;
						ss >> ch1;
						c[i][j].sign.push_back(ch == '-' ? 0 : 1);
					}
					else {
						if (first)
							c[i][j].sign.push_back('+');
						int x;
						ss >> x;
						char buf[10];
						sprintf(buf, "%d", x);
						string s = buf;
						c[i][j].vVec.push_back(s);
					}
					first = false;
				}
			}
		}
		bool flag = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) 
				if (!vis[i][j])
					if (!dfs(i, j))
					{
						flag = false;
						break;
					}
			if (!flag)
				break;
		}	
		int ok = true;
		while (ok) {
			ok = false;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					bool flag = false;
					for (auto& pair : c[i][j].ccc) {
						if (!c[pair.first][pair.second].isDigit) {
							flag = true;
							break;
						}
					}
					if (!flag && c[i][j].isDigit == false) {
						int ans = 0;
						for (int k = 0; k < c[i][j].vVec.size(); k++) {
							string s = c[i][j].vVec[k];
							if (isalpha(s[0])) {
								if (c[i][j].sign[k] == 0)
									ans -= c[s[0] - 'A'][s[1] - '0'].v;
								else
									ans += c[s[0] - 'A'][s[1] - '0'].v;				
							}
							else {
								int x = stoi(s);
								if (c[i][j].sign[k] == 0)
									ans -= x;
								else
									ans += x;
							}
						}
						c[i][j].isDigit = true;
						c[i][j].v = ans;
						ok = true;
					}
				}
			}
		}
		if (flag) {
			cout << " ";
			for (int z = 0; z < m; z++) {
				cout <<" " << setw(5) << z;
			}
			cout << endl;
			for (int i = 0; i < n; i++) {
				cout << char(i + 'A');
				for (int j = 0; j < m; j++) {
					cout << " " << setw(5) << c[i][j].v;
				}
				cout << endl;
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (!c[i][j].isDigit){
						cout << char(i + 'A') << j << ": ";
						bool first = true;
						for (int k = 0; k < c[i][j].vVec.size(); k++) {
							if(first)cout << (c[i][j].sign[k] == 0 ? "-" : "");
							else
							cout << (c[i][j].sign[k] == 0 ? '-' : '+');
							cout << c[i][j].vVec[k];					
							first = false;
						}
						cout << endl;
					}
				}
			}
		}
		cout << endl;
	}
}