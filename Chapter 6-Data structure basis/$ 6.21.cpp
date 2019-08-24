#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int num = 0;
unordered_map<string, int> mapId;
unordered_map<int, string> idMap;
vector<int> status;     //组件是显式还是隐式安装的
vector<vector<int>> depend1;    //组件x依赖的
vector<vector<int>> depend2;    //依赖于x组件的
vector<int> installed;

int getId(string s) {
    if(!mapId.count(s)) {
        idMap[num] = s;
        mapId[s] = num++;
    }    
    return mapId[s];
}

void install(int id, bool isExplicit) {
    if(!status[id]) {
        for(int i = 0 ; i < depend1[id].size(); i++) {
            install(depend1[id][i], false);
        }
        cout << "   Installing " << idMap[id] << endl;
        status[id] = isExplicit ? 2 : 1; //2显示
        installed.push_back(id);
    }
}

bool isNeeded(int id) {
    for(int i = 0; i < depend2[id].size(); i++) {
        if(status[depend2[id][i]]) return true;
    }
    return false;
}

void remove(int id, bool isExplicit) {
   if((isExplicit || status[id] == 1) && !isNeeded(id)) {
       status[id] = 0;
       installed.erase(remove(installed.begin(), installed.end(), id), installed.end());
       cout << "   Removing " << idMap[id] << endl;
       for(int i = 0; i < depend1[id].size(); i++) {
           remove(depend1[id][i], false);
       }
   }
}

void listItem() {
    for(auto& id: installed) {
        cout << "   " << idMap[id] << endl;
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    depend1.resize(maxn);
    depend2.resize(maxn);
    status.resize(maxn);
    string s;
    while(getline(cin, s)) {
        cout << s << endl;
        if(s == "END")
        break;
        stringstream ss(s);
        ss >> s;
        string temp;
        switch (s[0])
        {
        case 'D':
            ss >> temp;
            while(ss >> s) {
            depend1[getId(temp)].push_back(getId(s));
            depend2[getId(s)].push_back(getId(temp));
        }
            break;
        case 'I':
            ss >> temp;
            if(status[getId(temp)])
            cout << "   " << temp << " is already installed." << endl;
            else 
            install(getId(temp), true);
            break;
        case 'R':
            ss >> temp;
            if(!status[getId(temp)])
                cout << "   " << temp << " is not installed." << endl;
            else if(isNeeded(getId(temp))) 
                cout << "   " << temp << " is still needed." << endl;
            else
            remove(getId(temp), true);
            break;
        case 'L':
            listItem();
            break;
        default:
            cerr << "unexpected value" << endl;
            break;
        }
    }
}