 
            #include<iostream>
#include<math.h>
#include<stack>
using namespace std;
int main()
{
    int n=0,i=0,temp1=0,temp2=0,temp3=0,temp4=0,sum=0,flag=0;
    char str[5]={0};
    stack<int>s;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>str;
        if(str[0]=='I')
        {
            cin>>temp1;
            s.push(temp1);
            temp1=0;
        }
        else if(str[0]=='P')
        {
            if(s.empty())
            {
                continue;
            }
            else
            {
                s.pop();
            }
        }
        else if(str[0]=='A')
        {
            if(s.size()<2)
            {
                continue;
            }
            else
            {
                temp2=s.top();
                s.pop();
                temp3=s.top();
                s.pop();
                s.push(abs(temp2-temp3));
                temp2=0;
                temp3=0;
            }
        }
        else if(str[0]=='C')
        {
            if(s.empty())
            {
                continue;
            }
            else
            {
                temp4=s.top();
                s.push(temp4);
                temp4=0;
            }
        }
        else
        continue;
    }
    flag=s.size();
    for(i=0;i<flag;i++)
    {
        sum+=s.top();
        s.pop();
    }
    cout<<sum<<endl;
    return 0;
} 
        