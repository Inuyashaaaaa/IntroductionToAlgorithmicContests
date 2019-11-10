#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;


struct info
{
	int m_iId;
	char m_sName[30];
	double m_dSlove;
	double m_dSubmit;
	double m_dRate;
};

bool cmp(info s1, info s2)
{
	if (s1.m_dSlove > s2.m_dSlove) return 1;
	if (s1.m_dSlove < s2.m_dSlove) return 0;
	if (s1.m_dRate > s2.m_dRate) return 1;
	if (s1.m_dRate < s2.m_dRate) return 0;
	return s1.m_iId < s2.m_iId;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n,i;
	info a[170];
	scanf("%d", &n);
	if (n == 0)
		return 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d%s%lf%lf", &a[i].m_iId, a[i].m_sName, &a[i].m_dSlove, &a[i].m_dSubmit);
		a[i].m_dRate = a[i].m_dSlove / a[i].m_dSubmit;
	}	
	sort(a, a + n, cmp);
	int count = 1;
	printf("%-4d%-12d%-11s%6.0lf%6.0lf%8.2lf%%\n", count, a[0].m_iId, a[0].m_sName, a[0].m_dSlove, a[0].m_dSubmit, a[0].m_dRate*100);
	for (i = 1; i < n; i++)
	{
		if (a[i - 1].m_dRate == a[i].m_dRate)
		{
			printf("%-4d%-12d%-11s%6.0lf%6.0lf%8.2lf%%\n", i+1-count, a[i].m_iId, a[i].m_sName, a[i].m_dSlove, a[i].m_dSubmit, a[i].m_dRate*100);
			count++;
		}
		else
		{
			count = 0;
			printf("%-4d%-12d%-11s%6.0lf%6.0lf%8.2lf%%\n", i+1, a[i].m_iId, a[i].m_sName, a[i].m_dSlove, a[i].m_dSubmit, a[i].m_dRate*100);
			count = 1;
		}
	} 
    return 0;
}