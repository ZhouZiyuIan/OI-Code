#include<cstdio>
#define ll long long
using namespace std;
const int N=1e5+5;
int n,ans1;
long long t,a[N],sum,ans2;
int main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	scanf("%d%lld",&n,&t);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	t%=sum;
	sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		if(sum>=t)
		{
			ans1=i;
			ans2=sum-t;
			break;
		}
	}
	printf("%d\n%lld",ans1,ans2);
	return 0;
}
