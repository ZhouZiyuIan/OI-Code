#include<bits/stdc++.h>
using namespace std;
void fre()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
}
struct asd{
	int name;
	int num;
}g[37];
string a;
int k,n,cnt;
map<char,int> d;
int cmp(asd xx,asd yy)
{
	return xx.num>yy.num;
}
int main()
{
	fre();
	cin>>a>>k,n=a.size()-1;
	for(int i=0;i<=n;i++) d[a[i]]++;
	for(char i='a';i<='z';i++) g[int(i-'a'+1)].name=int(i-'a'+1);
	for(char i='a';i<='z';i++) g[int(i-'a'+1)].num=d[i],cnt+=(d[i]!=0);
	sort(g+1,g+27,cmp);
	int m=26;
	while(k-g[m].num>0&&cnt>0) k-=g[m].num,cnt-=(d[char(g[m].name-1+'a')]!=0),d[char(g[m].name-1+'a')]=0,m--;
	cout<<cnt<<endl;
	d[char(g[m].name-1+'a')]-=k;
	for(int i=0;i<=n;i++) if(d[a[i]]) d[a[i]]--,cout<<a[i];
	return 0;
}
