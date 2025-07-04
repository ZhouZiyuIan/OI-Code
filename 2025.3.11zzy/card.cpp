#include<stdio.h>
#include<queue>
using namespace std;
priority_queue<long long>a;
long long n,b,c;
main(){
	scanf("%lld",&n);
	while(n--){
		scanf("%lld",&b);
		if(b!=0ll)a.push(b);
		else if(!a.empty())c+=a.top(),a.pop();
	}
	printf("%lld",c);
}
