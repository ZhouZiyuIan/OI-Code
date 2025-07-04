#include<iostream>
#define ll long long
using namespace std;
ll M=1000000007;//模数
ll fac[2010];//阶乘
ll facinv[2010];//阶乘逆元
ll ext[2010];//某元素是否已经在排列中
ll a[2010];//排列
ll num,cnt;//分别记录缺失元素个数和可能有a[i]==i的元素个数
ll qpow(ll d,ll p)//快速幂
{
	ll ret=1;
	while(p)
	{
		if(p%2) ret=(ret*d)%M;
		d=(d*d)%M;
		p/=2;
	}
	return ret;
}
int main()
{
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==-1) num++;
		else ext[a[i]]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==-1&&!(ext[i]))
			cnt++;
	}
	fac[0]=1;
	for(int i=1;i<=num;i++)//求阶乘
	{
		fac[i]=(fac[i-1]*i)%M;
	}
	facinv[num]=qpow(fac[num],M-2);
	for(int i=num-1;i;i--)//求逆元
	{
		facinv[i]=facinv[i+1]*(i+1)%M;
	}
	facinv[0]=1;
	ll ans=fac[num];
	for(int i=1;i<=cnt;i++)//计算答案
	{
		ans+=((((qpow(-1,i%2)*fac[cnt])%M)*facinv[cnt-i]%M)*facinv[i]%M)*fac[num-i]%M;
	}
	while(ans<0)//调整
	{
		ans+=M;
	}
	cout<<ans%M;
	return 0;
}