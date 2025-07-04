#include<bits/stdc++.h>
using namespace std;
char a[100003];
int k;
void pl(char a[100004])
{
	for(int i=0;i<strlen(a);i++)
	{
		for(int j=i;j<strlen(a);j++)
		{
			if(a[i]>a[i+1]) swap(a[i],a[i+1]);
		}
	}
}
int main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin>>a;
	cin>>k;
	int n=strlen(a);
	pl(a);
	if(k>=n)
	{
		cout<<"0"<<endl;
		return 0;
	}
	
}
