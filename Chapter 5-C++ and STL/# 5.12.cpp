#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

const int maxn = 10000 + 50;

map<string,pair<double,double>> location;

struct Map{
    double x1, y1;
    double x2, y2;
    double area;
    double rate;
    int SearchLevel;
    string mapName;
    friend bool operator < (Map& m1, Map& m2) {
        return m1.area > m2.area;
    }
}maps[maxn];

pair<double,double> p;

bool cmp(Map& m1,Map& m2) {
    // 距离地图中心最近的一张
    double midX1 = (m1.x2 + m1.x1) / 2;
    double midY1 = (m1.y2 + m1.y1) / 2;
    double disCen1 = hypot(midX1 - p.first,midY1 - p.second);
    double midX2 = (m2.x2 + m2.x1) / 2;
    double midY2 = (m2.y2 + m2.y1) / 2;
    double disCen2 = hypot(midX2 - p.first,midY2 - p.second);
    if(disCen1 < disCen2) return true;
    if(disCen1 > disCen2) return false;

    // 地图长宽比尽量接近0.75
    double rate1D = abs(m1.rate - 0.75);
    double rate2D = abs(m2.rate - 0.75);
    if(rate1D < rate2D) return true;
    if(rate1D > rate2D) return false;

    //查询地名和右下角的坐标要尽量远
    double disRight1 = hypot(m1.x2 - p.first, m1.y2 - p.second);
    double disRight2 = hypot(m2.x2 - p.first, m2.y2 - p.second);
    if(disRight1 < disRight2) return true;
    if(disRight1 < disRight2) return false;

    //输出x坐标最小的一个
    return m1.x1 < m2.x2;
}

int main() {
    string s;
    cin >> s;
    int cnt = 0;
    while(cin >> s && s != "LOCATIONS"){
        maps[cnt].mapName = s;
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        maps[cnt].x1 = min(x1, x2);
        maps[cnt].y1 = min(y1, y2);
        maps[cnt].x2 = max(x1, x2);
        maps[cnt].y2 = max(y1, y2);
        maps[cnt].area = (maps[cnt].x2 - maps[cnt].x1) * (maps[cnt].y2 - maps[cnt].y1);
        maps[cnt].rate = (maps[cnt].y2 - maps[cnt].y1) / (maps[cnt].x2 - maps[cnt].x1);
        cnt ++;
    }
    sort(maps, maps + cnt);
    while(cin >> s && s != "REQUESTS") {
        double x, y;
        cin >> x >> y;
        location[s] = make_pair(x, y);
    }
    while(cin >> s && s != "END") {
        int num;
        cin >> num;
        bool flag  = true;

        //查询地名不存在
        int mapCnt = 0;
        if(location.count(s) == 0) {    
            flag = false;
            cout << s << " at detail level " << num << " unknown location" << endl;
            continue;
        }

        vector<Map> v;
        //得到包含他的地图总数
        for(int i = 0; i < cnt; i++) {
            if(maps[i].x1 <= location[s].first && location[s].first <= maps[i].x2
            && maps[i].y1 <= location[s].second && location[s].second <= maps[i].y2) {
                mapCnt ++;
                v.push_back(maps[i]);
            }
        }
        sort(v.begin(), v.end());
        //没有地图包含它
        if(!mapCnt){
            cout << s << " at detail level " << num << " no map contains that location" << endl;
            continue;
        }

        v[0].SearchLevel = 1;
        int pos = 1;
        for(int i = 1; i < v.size(); i++){
            if(v[i].area == v[i-1].area) {
                v[i].SearchLevel = pos;
            }
            else{
                v[i].SearchLevel = ++pos;
            }
        }
        p = location[s];
        vector<Map> vec1;
        for(int i = 0; i <v.size(); i++) {
            if(v[i].x1 <= location[s].first && location[s].first <= v[i].x2
            && v[i].y1 <= location[s].second && location[s].second <= v[i].y2
            && v[i].SearchLevel == num) {
                vec1.push_back(v[i]);
            }
        }
        if(vec1.size() != 0) {
            sort(vec1.begin(), vec1.end(), cmp);
            cout << s << " at detail level " << num << " using " << vec1[0].mapName << endl;
            continue;
        }
        if(mapCnt > num || vec1.size() == 0){
            vector<Map> vec;
            for(int i = cnt - 1; i >= 0; i--) {
                if( v[i].x1 <= location[s].first && location[s].first <= v[i].x2
                && v[i].y1 <= location[s].second && location[s].second <= v[i].y2){
                    pos = v[i].SearchLevel;
                    break;
                } 
            }
            for(int i = cnt - 1; i >= 0; i--) {
                if( v[i].x1 <= location[s].first && location[s].first <= v[i].x2
                && v[i].y1 <= location[s].second && location[s].second <= v[i].y2
                && v[i].SearchLevel == pos){
                    vec.push_back(v[i]);
                } 
            }
            sort(vec.begin(), vec.end(), cmp);
            cout << s << " at detail level " << num << " no map at that detail level; using " << vec[0].mapName << endl;
            continue;
        } 
    }
}