#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<cstdio>
using namespace std;

void parseAddress(const string& s, string& user, string& mta) {
    int k = s.find('@');
    user = s.substr(0, k);
    mta = s.substr(k + 1);
}

int main() {
    int k;
    string s, t, user1, mta1, user2, mta2;
    set<string> addr;

    // freopen("5-11.in", "r", stdin);
    // freopen("5-11.out", "w", stdout);

    while(cin >> s && s != "*") {
        cin >> s >> k;
        while(k--) {
            cin >> t;
            addr.insert(t + "@" + s);
        }
    }

    while(cin >> s && s != "*") {
        parseAddress(s, user1, mta1);

        vector<string> mta;
        map<string, vector<string>> dest;
        set<string> vis;
        while(cin >> t && t != "*") {
            parseAddress(t, user2, mta2);
            if(vis.count(t)) continue;
            vis.insert(t);
            if(!dest.count(mta2)) {
                mta.push_back(mta2);
                dest[mta2] = vector<string>();
            }
            dest[mta2].push_back(t);
        }
        getline(cin, t);
        string data;
        while(getline(cin, t) && t[0] != '*') 
            data += "     " + t + "\n";
        
        for(int i = 0; i < mta.size(); i++) {
            string mta2 = mta[i];
            vector<string> users = dest[mta2];
            cout << "Connection between " << mta1 << " and " << mta2 << endl;
            cout << "     HELO " << mta1 << endl;
            cout << "     250" << endl;
            cout << "     MAIL FROM:<" << s << ">" << endl;
            cout << "     250" << endl;
            bool ok = false;
            for(int i = 0; i < users.size(); i++) {
                cout << "     RCPT TO:<" << users[i] << ">" << endl;
                if(addr.count(users[i])) {
                    ok = true; cout << "     250" << endl;
                }
                else {
                    cout << "     550" << endl;
                }
            }
            if(ok) {
                cout << "     DATA" << endl;
                cout << "     354" << endl;
                cout << data;
                cout << "     ." << endl <<"     250" << endl;
            }
            cout << "     QUIT" << endl;
            cout << "     221" << endl;
        }
    }

    return 0;
}