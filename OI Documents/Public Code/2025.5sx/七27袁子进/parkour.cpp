#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define For(i,x,y) for(int i=x;i<=y;i++)
const int M=10101;
const int N=11;
const int inf=1e9+7;
bool tmp;
int n,m;
int x,y;
int l,r;
char a[N][M];
vector <pair <int,int> > c[N];
int tame;
signed main()
{
	scanf("%d%d",&m,&n);
	For(i,1,n) For(j,1,m) cin>>a[i][j];
	For(i,1,n)
	{
		For(j,1,m)
		{
			if(a[i][j]=='s')
			{
				x=i;
				y=j;
				i=n;
				break;
			}
		}
	}
	For(i,1,n)
	{
		tmp=0;
		l=0;
		r=0;
		For(j,1,m)
		{
			if(!tmp)
			{
				if(a[i][j]=='X')
				{
					tmp=1;
					l=j;
					r=j;
				}
			}
			else
			{
				if(a[i][j]=='X') r++;
				else
				{
					tmp=0;
					c[i].push_back({l,r});
					l=0;
					r=0;
				}
			}
		}
		if(l!=0) c[i].push_back({l,r});
	}
	
	return 0;
}
/*
16 3
...XXXXX........
s.XXX......XXXXX
........XXXXX...
*/
