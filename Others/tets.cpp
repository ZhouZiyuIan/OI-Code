#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
map<int,int> f;
int T,n,k,cnt;
int a[1000005],b[1005];
int main()
{
	freopen("testout.txt","w",stdout); 
	scanf("%d",&T);
	while(T--)
	{
	  f.clear();cnt=0;
	  scanf("%d%d",&n,&k);
	  for(int i=1;i<=sqrt(k);i++)
	   if(k%i==0)
	   {
	   	 a[++cnt]=i;
	   	 if(i*i!=k) a[++cnt]=k/i;
	   }
	  sort(a+1,a+1+cnt);
	  for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	  for(int i=1;i<=n;i++)
	  {
	  	for(int j=cnt;j>=1;j--)
	  	 if(a[j]%b[i]==0)
	  	 {
	  	   (f[a[j]]+=f[a[j]/b[i]])%=M;	
	  	   if(a[j]==b[i]) (f[a[j]]+=1)%=M;
		 }
	  }
	  cout<<f[a[cnt]]<<endl;  
	}
}
