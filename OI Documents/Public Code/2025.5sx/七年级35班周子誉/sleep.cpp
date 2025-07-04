#include<stdio.h>
#include<ctype.h>
template<typename T>
void read(T &n){
	n=0;
	T f=1;
	char s=getchar();
	while(!isdigit(s)){
		if(s=='-')f*=-1;
		s=getchar();
	}
	do{
		n=(n<<1)+(n<<3)+(s^48);
		s=getchar();
	}while(isdigit(s));
	n*=f;
}
template<typename T>
void write(T x){
	if(x<0)putchar(45),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+48);
}
long long n,x[100001],t,sum;
main(){
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	read(n);
	read(t);
	for(int i=0;i<n;i++){
		read(x[i]);
		sum+=x[i];
	}
	t%=sum;
	sum=0;
	for(int i=0;i<n;i++){
		sum+=x[i];
		if(sum>=t){
			write(i+1);
			putchar(10);
			write(sum-t);
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
