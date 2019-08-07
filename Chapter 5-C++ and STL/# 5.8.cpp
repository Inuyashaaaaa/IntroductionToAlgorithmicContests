#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct Book {
	string title, author;
	int pos; // 0表示在书架上，1表示借走，2表示归还
	int index;
	Book(string title, string author, int pos) :title(title), author(author), pos(pos) {}
	friend bool operator < (Book& b1, Book& b2) {
		if (b1.author < b2.author) return true;
		if (b1.author > b2.author) return false;
		return b1.title < b2.title;
	}
};

int main() {
	string s;
	vector<Book> shelvesBooks;
	vector<Book> borrowBooks;
	vector<Book> returnBooks;
	while (getline(cin, s) && s != "END") {
		int k = s.find("\" by");
		string title = s.substr(0, k + 1);
		string author = s.substr(k + 5);
		shelvesBooks.push_back(Book(title, author, 0));
	}
	sort(shelvesBooks.begin(), shelvesBooks.end());
	for (int i = 0; i < shelvesBooks.size(); i++) {
		shelvesBooks[i].index = i;
	}

	while (cin >> s && s != "END") {
		string title, author;
		if (s[0] != 'S') {
			getchar();
			getline(cin, title);
		}
		if (s[0] == 'B') {
			for (auto& book : shelvesBooks) {
				if (book.title == title && book.pos == 0) {
					book.pos = 1;
					borrowBooks.push_back(book);
					break;
				}
			}
		}
		if (s[0] == 'R') {
			for (auto iter = borrowBooks.begin(); iter != borrowBooks.end(); iter++) {
				if (iter->title == title) {
					iter->pos = 2;
					returnBooks.push_back(*iter);
					borrowBooks.erase(iter);
					break;
				}
			}
		}
		if (s[0] == 'S') {
			sort(returnBooks.begin(), returnBooks.end());
			for (auto& book : returnBooks) {
				int pos = -1;
				int index = book.index;
				for (int i = 0; i < index; i++) {
					if (shelvesBooks[i].pos == 0)
						pos = i;
				}
				shelvesBooks[index].pos = 0;
				if (pos == -1)
					cout << "Put " << shelvesBooks[index].title << " first" << endl;
				else
					cout << "Put " << shelvesBooks[index].title << " after " << shelvesBooks[pos].title << endl;
			}
			cout << "END" << endl;
			returnBooks.clear();
		}
	}
	return 0;
}