#include <bits/stdc++.h>
#define  ll long long
using namespace std;
const int MAXN=2e5+5;
int vis[27]={0};
int main(){
    int n,t;
    string s;
    cin>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        cin>>s;
        char key[100];
        for(int i=0;i<100;i++) key[i]='A';
        key[50]=s[0];
        int index=50;
        vis[s[0]-'a']=1;
        int flag=0;
        for(int i=1;i<s.length();i++){
            if(s[i]==key[index]){
                flag=1;
                break;
            }
            if(key[index+1]==s[i]){
                index++;
                continue;
            }
            if(key[index-1]==s[i]){
                index--;
                continue;
            }
            if(key[index+1]=='A'){
                if(vis[s[i]-'a']==1){
                    flag=1;
                    break;
                }
                key[index+1]=s[i];
                vis[s[i]-'a']=1;
                index++;
            }else if(key[index-1]=='A'){
                if(vis[s[i]-'a']==1){
                    flag=1;
                    break;
                }
                key[index-1]=s[i];
                vis[s[i]-'a']=1;
                index--;
            }
        }
        if(flag) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            for(int i=0;i<100;i++){
                if(key[i]!='A') cout<<key[i];
            }
            for(int i=0;i<26;i++){
                if(vis[i]==0) cout<<char(i+'a');
            }
            cout<<endl;
        }
    }
    return 0;
}