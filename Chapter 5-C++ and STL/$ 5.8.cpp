#include<cstdlib>
#include<vector>
#include<algorithm>
#include<assert.h>
using std::vector;

void fillRandomInt(vector<int> &v, int cnt) {
    v.clear();
    for(int i = 0; i < cnt; i++) {
        v.push_back(rand());
    }
}

void testSort(vector<int>& v) {
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size() - 1; i++) {
        assert(v[i] <= v[i+1]);
    }
}

int main() {
    vector<int> v;
    fillRandomInt(v, 1e6);
    testSort(v);
    system("pause");
    return 0;
}