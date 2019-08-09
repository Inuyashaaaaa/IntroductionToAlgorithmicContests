#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
#include<string>
using namespace std;

//此处或许浪费了价格的存储空间
struct Order {
	int num, price;
	Order() {}
	Order(int price, int num) :price(price), num(num) {}
};

// buy的订单 从价格大到价格小排序
map<int, unordered_map<int, Order>, greater<int>> Bmap; //价格对应 maps （maps的id） 对应order
map<int, unordered_map<int, Order>> Smap;

unordered_map<int, int> Map; // id 对应价格

//初始化
void init() {
	cout << endl;
	Bmap.clear();
	Smap.clear();
	Map.clear();
}

//删除订单 (亦或是 cancel订单) 
void del(const int& id, const int& price, const char& type) {
	if (type != 'B') {
		if (Smap.count(price) && Smap[price].count(id)) {
			Smap[price].erase(id);
			if (Smap[price].empty())
				Smap.erase(price);
		}
	}
	if (type != 'S') {
		if (Bmap.count(price) && Bmap[price].count(id)) {
			Bmap[price].erase(id);
			if (Bmap[price].empty())
				Bmap.erase(price);
		}
	}
	Map.erase(id);
}

// 买
void buy(const int &i) {
	int num, price;
	cin >> num >> price;
	vector<pair<int, int >> delV; //删除
	for (auto iter = Smap.begin(); iter != Smap.end() && num; iter++) {
		for (auto& pair : iter->second) {
			if (pair.second.price <= price) {
				if (pair.second.num > num) {
					cout << "TRADE " << num << " " << pair.second.price << endl;
					pair.second.num -= num;
					num = 0;
				}
				else {
					cout << "TRADE " << pair.second.num << " " << pair.second.price << endl;
					num -= pair.second.num;
					int idD = pair.first;
					int priceD = iter->first;
					delV.push_back(make_pair(idD, priceD));
				}
			}
			else {
				goto Part1;
			}
			if (!num)
				goto Part1;
		}
	}
	Part1:
	for (auto& pair : delV) {
		del(pair.first, pair.second, 'S');
	}
	if (num) {
		Map[i] = price;
		Order order(price, num);
		Bmap[price][i] = order;
	}
}

//卖
void sell(const int& i) {
	int num, price;
	cin >> num >> price;
	vector<pair<int, int >> delV; //删除
	for (auto iter = Bmap.begin(); iter != Bmap.end(); iter++) {
		for (auto& pair : iter->second) {
			if (pair.second.price >= price) {
				if (pair.second.num > num) {
					cout << "TRADE " << num << " " << pair.second.price << endl;
					pair.second.num -= num;
					num = 0;
				}
				else {
					cout << "TRADE " << pair.second.num << " " << pair.second.price << endl;
					num -= pair.second.num;
					pair.second.num = 0;
					int idD = pair.first;
					int priceD = iter->first;
					delV.push_back(make_pair(idD, priceD));
				}
			}
			else {
				goto PART2;
			}
			if (!num)
				goto PART2;
		}
	}
	PART2:
	for (auto& pair : delV) {
		del(pair.first, pair.second, 'B');
	}
	if (num) {
		Map[i] = price;
		Order order(price, num);
		Smap[price][i] = order;
	}
}

void QUOTE() {
	cout << "QUOTE";
	if (Bmap.empty()) {
		cout << " 0 0 -";
	}
	else {
		auto iter = Bmap.begin();
		int num = 0;
		for (auto pair : iter->second) {
			num += pair.second.num;
		}
		cout << " " << num;
		cout << " " << iter->first << " -";
	}
	if (Smap.empty()) {
		cout << " 0 99999" << endl;
	}
	else {
		auto iter = Smap.begin();
		int num = 0;
		for (auto pair : iter->second) {
			num += pair.second.num;
		}
		cout << " " << num;
		cout << " " << iter->first << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int n;
	int kase = 0;
	while (cin >> n) {
		if (kase++)
			init();
		for (int i = 1; i <= n; i++) {
			string s;
			cin >> s;
			if (s[0] == 'B') buy(i);
			if (s[0] == 'S') sell(i);
			if (s[0] == 'C') {
				int id;
				cin >> id;
				if (Map.count(id))
					del(id, Map[id], 'C');
			}
			QUOTE();
		}
	}

	return 0;
}