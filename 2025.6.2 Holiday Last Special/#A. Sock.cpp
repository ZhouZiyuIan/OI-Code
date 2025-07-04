#include<stdio.h>
int n;
int main(){
    freopen("sock.in","r",stdin);
    freopen("sock.out","w",stdout);
	scanf("%d",&n);
	printf("%.10lf",(n*1.0)/((n<<1)-1.0));
}