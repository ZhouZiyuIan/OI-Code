#include<bits/stdc++.h>
using namespace std;
int k,len,g[100010],ans;
char s[1000010],a[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int main()
{
	//freopen("goof.in","r",stdin);
	//freopen("goof.out","w",stdout);
	gets(s);
	len=strlen(s);
	cin>>k;
	if(k>=len)
	{
		cout<<0<<endl;
		return 0;
	}
	else
	{
		for(int i=0;i<=len-1;i++)
	    {
		    int f=s[i];
	    	g[f-96]++;
        }
        for(int i=1;i<=k;i++)
        {
        	int sa=1000010,pa;
    	    for(int j=0;j<=25;j++)
        	{
        		if(g[j]<sa&&g[j]>0)
        		{
        			sa=g[j];
        			pa=j;
				}
	    	}
	    	g[pa]--;
	    	int y=a[pa-1];
	    	for(int j=0;j<=len-1;j++)
	    	if(s[j]==y)
	    	{
	    		s[j]=' ';
	    		break;
			}
    	}
    	for(int i=0;i<=25;i++)
    	{
    		if(g[i]>0)
    		ans++;
		}
		cout<<ans<<endl;
		for(int i=0;i<=len-1;i++)
		if(s[i]!=' ')
		cout<<s[i];
	}
}
