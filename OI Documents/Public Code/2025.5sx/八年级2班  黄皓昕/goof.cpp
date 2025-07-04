#include<bits/stdc++.h>
using namespace std;
int s,k,ans,now;bool v[26];char c[100005];
struct stu
{
	int count;char name;
}q[27];
bool cmp(stu x,stu y)
{
	return x.count<y.count;
}
int main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin>>c>>k;
	s=strlen(c);
	if(s<k)
	{
		cout<<"0\n ";return 0;
	}
	for(int i=0;i<26;i++)
	{
		q[i].name=i+'a';
	}
	for(int i=0;i<s;i++)
	{
		q[c[i]-'a'].count++;
	}
	sort(q,q+26,cmp);
	for(int i=0;i<26;i++)
	{
		if(now+q[i].count>k)break;
		now+=q[i].count;
		v[q[i].name-'a']=true;
		ans++;
	}
	cout<<26-ans<<"\n";
	for(int i=0;i<s;i++)
	{
		if(!v[c[i]-'a'])
		{
			cout<<c[i];
		}
	}
}

