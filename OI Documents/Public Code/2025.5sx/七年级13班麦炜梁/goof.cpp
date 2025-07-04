#include<bits/stdc++.h>
using namespace std;
char a[1000000];
int k,q[1000000],small=999;
int main()
{
    freopen("goof.in","r",stdin);
    freopen("goof.out","w",stdout);
    scanf("%s",a);
    cin>>k;
    for(int i=0;i<strlen(a);i++)
    {
    	q[a[i]-97]++;
	}
	for(int i=0;i<strlen(a);i++)
    {
    	if(q[i]<small&&q[i]!=0)
    	{
    		small=q[i];
		}
	}
	cout<<"0"<<endl;
	cout<<"";


	return 0;
}
