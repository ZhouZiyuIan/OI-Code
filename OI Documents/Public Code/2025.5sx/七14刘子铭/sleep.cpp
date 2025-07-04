#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[1000000];
int n,t;
ll s=0;
int y=0;
int shou=1;
int main() {
	freopen("sleep.in","w",stdin);
	freopen("sleep.out","r",stdout);
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		//s+=a[i];
	}
	int j=1;
	while(y<t)
	{
		y+=a[j];
		
		j++;
		if(y>=t) break;
		if(j>n)
		{
			j=1;
		}
	}
	ll h=y;
	y-=a[j];
	cout<<j-1<<"\n"<<h-t;
	
	
	











}
