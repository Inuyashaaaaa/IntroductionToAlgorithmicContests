#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 100000 + 5;
int pos, last, next[MAXN];

char s[MAXN];


int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    while(scanf("%s", s + 1) == 1) {
        next[0] = 0;
        pos = last = 0;
        int len = strlen(s + 1); 
        for(int i = 1; i <= len; i ++) {
            if(s[i] == '[') pos = 0;
            else if(s[i] == ']') pos = last;
            else{
                next[i] = next[pos];
                next[pos] = i;
                if(pos == last) last = i;
                pos = i;
            }
        }
        for(int i = next[0]; i != 0; i = next[i]) {
            printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}