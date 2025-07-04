#include<stdio.h>
#include<queue>
using namespace std;
priority_queue<long long>a;
long long t,n,b,c;
main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		while(n--){
			scanf("%lld",&b);
			if(b!=0ll)a.push(b);
			else{
				if(a.empty())
				{
					continue;
				}
				c+=a.top();
				a.pop();
			}
		}
		printf("%lld\n",c);
		while(!a.empty())a.pop();
		c=0;
	}
}
