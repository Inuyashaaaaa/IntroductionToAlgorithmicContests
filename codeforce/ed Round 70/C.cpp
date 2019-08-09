#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        int posX = 0, posY = 0;
        int WMax = 0, SMax = 0, AMax = 0, Dmax =0;
        int WMaxd = 0 ,SMaxd = 0, AMaxd = 0, Dmaxd = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'W') posY ++;
            if(s[i] == 'S') posY --;
            if(s[i] == 'A') posX --;
            if(s[i] == 'D') posX ++;
            WMax = max(posY, WMax);
            SMax = min(posY, SMax);
            AMax = min(posX, AMax);
            Dmax = max(posX, Dmax);
            WMaxd = max(WMaxd, posY - SMax);
            SMaxd = max(SMaxd, WMax - posY);
            AMaxd = max(AMaxd, Dmax - posX);
            Dmaxd = max(Dmaxd, posX - AMax);
        }
        long long x[2], y[2];
        x[0] = max(WMaxd, SMaxd);
        x[1] = max((long long)(WMaxd || SMaxd), x[0] - !(WMaxd == SMaxd));
        y[0] = max(AMaxd, Dmaxd); 
        y[1] = max((long long)(AMaxd || Dmaxd), y[0] - !(AMaxd == Dmaxd));
        long long ans = min((x[0] + 1) * (y[1] + 1) , (y[0] + 1) * (x[1] + 1));
        cout << ans << endl;
    }
}