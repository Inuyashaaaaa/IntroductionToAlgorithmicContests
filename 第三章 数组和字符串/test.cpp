#include<stdio.h>
#include<string.h>
int main(void)
{
    int n,stlen,i,j;
    char carr[1000];
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            scanf("%s",carr);
            stlen=strlen(carr);
            for(i=1; i<=stlen; i++)
            {
                if(stlen%i==0)
                {
                    for(j=i; j<stlen; ++j)
                        if(carr[j]!=carr[j%i])break;
                    if(j==stlen)
                    {
                        printf("%d\n",i);
                        break;
                    }
                }
            }
            if(n)printf("\n");
        }
    }
    return 0;
}
