#include<bits/stdc++.h>
using namespace std;
struct node{
	int y,x;
};
queue<node> q;
char a[2000010][20];
int n,m,sum=0,ans=0,t,h,k;
int main()
{
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	cin>>k;
	while(k--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]=='s') q.push({j,i});
		}
		while(q.size())
		{
			node q1=q.front();
			if(q1.y>=n){
				cout<<"YES\n";
				break;
			}
			q1.y++;
			if(a[q1.y][q1.x]=='X'){
				q.pop();
				continue;
			}
			//cout<<"Man!";
			if(a[q1.y][q1.x+1]=='.'&&a[q1.y+1][q1.x+1]=='.') q.push({q1.y+2,q1.x+1});
			if(a[q1.y][q1.x-1]=='.'&&a[q1.y+1][q1.x-1]=='.') q.push({q1.y+2,q1.x-1});
			if(a[q1.y+1][q1.x]=='.') q.push({q1.y+2,q1.x});
			if(q.size()==1) cout<<"NO\n";
			q.pop();
		}
	}
	return 0;
}
