#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
const int N=2e5+5;
struct node{
	int l,r;
}num[N];
struct cmp{
	inline bool operator () (const node&a,const node&b){
		return a.l<b.l;
	}
};
int T,n,tot[N];
long long s;
inline int check(long long mid){
	int cnt=0,cnt1=0,cnt2=0;//cnt为第三类薪水数，cnt1为第一类薪水数，cnt2位第二类薪水数
	long long sum=0;
	for (register int i=1;i<=n;++i)
		if (num[i].r<mid) sum+=num[i].l,++cnt1;//第一类
		else if (num[i].l>mid) sum+=num[i].l,++cnt2;//第二类
		else tot[++cnt]=i;//第三类薪水编号记录
	if (cnt1>(n>>1)||cnt2>(n>>1)) return 0;//如果第一类或第二类薪水数大于所有薪水数的一半，即大于或小于中位数的数大于一半，肯定不满足
	for (register int i=1;i<=(n>>1)-cnt1;++i) sum+=num[tot[i]].l;//对于num[i].l小的部分
	sum+=1ll*mid*((n>>1)+1-cnt2);//其他部分
	return sum<=s;
}
int main(){
    freopen("payday.in","r",stdin);
    freopen("payday.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d%lld",&n,&s);
		for (register int i=1;i<=n;++i) scanf("%d%d",&num[i].l,&num[i].r);
		sort(num+1,num+n+1,cmp());//将num[i].l从小到大排序
		long long l=num[(n>>1)+1].l,r=1ll*s/((n>>1)+1);//二分上下界自己极端估计一下
		while (l<=r){
			long long mid=l+r>>1;
			check(mid)?l=mid+1:r=mid-1;
		}
		printf("%lld\n",l-1);
	}
	return 0;
}