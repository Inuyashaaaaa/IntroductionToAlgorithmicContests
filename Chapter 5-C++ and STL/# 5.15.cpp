#include<map>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
class Trie {
public:
	class Node {
	public:
		int id;
		map<char, Node*> *next;
		Node(int id) {
			this->id = id;
			next = new map<char, Node*>;
		}
		Node() {
			this->id = -1;
			next = new map<char, Node*>;
		}

	};
	Node* root;
	Trie() {
		root = new Node();
	}
	void add(const string& word, int id) {
		add(root, word, 0, id);
	}

	void add(Node* node,const string& word, int index, int id)
	{
		if (word.length() == index) {
			if(node->id == -1)
			node->id = id;
			return;
		}

		char c = word.at(index);

		if (!node->next->count(c))
			node->next->emplace(make_pair(c, new Node(id)));

		add(node->next->at(c), word, index + 1, id);
	}

	bool isPrefix(const string& prefix, int& id) {
		return isPrefix(root, prefix, 0, id);
	}

	bool isPrefix(Node* node,const string& prefix, int index, int& id)
	{
		if (prefix.length() == index) {
			id = node->id;
			return true;
		}

		char c = prefix.at(index);

		if (!node->next->count(c))
			return false;

		return isPrefix(node->next->at(c), prefix, index + 1, id);
	}

};

string stringAddString(string s1, string s2) {
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	int len1 = s1.length();
	int len2 = s2.length();
	int maxn = max(len1, len2);
	int i = 0;
	int e = 0;
	string ret;
	while (i < maxn) {
		int ans = e;
		if (i < len1) ans += s1[i] - '0';
		if (i < len2) ans += s2[i] - '0';
		ret += (ans % 10) + '0';
		e = ans / 10;
		i++;
	}
	if (e)
		ret += e + '0';
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
    // freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	Trie trie;
	string s1 = "1";
	string s2 = "2";
	trie.add(s1, 0);
	trie.add(s1, 1);
	trie.add(s2, 2);
	for (int i = 3; i < 100000; i++) {
		string ret = stringAddString(s1, s2);
		s1 = s2;
		s2 = ret;
		if (ret.length() > 40)
			trie.add(ret.substr(0, 40), i);
		else
			trie.add(ret, i);
	}
	
	int n;
	cin >> n;
    int cnt = 0;
	while (n--) {
        cout << "Case #" << ++cnt  << ": ";
		string s;
		cin >> s;
		int id;
		if (trie.isPrefix(s, id))
			cout << id << endl;
		else
			cout << -1 << endl;
	}


	//system("pause");
	return 0;

}