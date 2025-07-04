#include<bits/stdc++.h>
#define ll long long
using namespace std;
char a[100010];
int ss[1000000];
int k;
int zl=0;
int op=0;
int main(){
	freopen("goof.in","w",stdin);
	freopen("goof.out","r",stdout);
	cin>>a>>k;
	int l=strlen(a);
	if(k>=l)
	{
		cout<<"0"<<"\n"; 
	}
	int t=0;
	for(int i=0;i<l;i++)
	{
		ss[a[i]-96]++;
		if(ss[a[i]-96]>t)
		{
			t=a[i]-96;	
		}
	}
	//cout<<char(t+96);
	int hh=l;
	for(int i=0;i<l;i++)
	{
		if(a[i]!=char(a[i]+96)&&op<k){
			ss[a[i]-96]--;
			a[i]='0';
			op++;
		}
	}
	for(int i=0;i<l;i++)
	{
		if(ss[a[i]-96]>0){
			zl++;
		}
	}
	cout<<zl<<"\n";
	for(int i=0;i<l;i++)
	{
		if(a[i]!='0')
		{
			cout<<a[i];
		}
	}	
	
	
}
