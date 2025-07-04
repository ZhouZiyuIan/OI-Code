#include<stdio.h>
#include<ctype.h>
#include<unordered_map>
using namespace std;
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
template<typename T>
T abs1(T a){return a<0?-a:a;}
unordered_map<long long,bool>vis;
long long n,y,x[1001],ans;
void dfs(long long pos,long long pos1,long long pos2){
	if(pos1&&pos2){
		if(vis[abs1(pos1-pos2)]==0){
			++ans;
			vis[abs1(pos1-pos2)]=1;
		}
		return;
	}
	if(pos==n)return;
	if(pos1==0)dfs(pos+1,x[pos],0);
	else dfs(pos+1,pos1,x[pos]);
	dfs(pos+1,pos1,pos2);
}
main(){
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	read(n);
	read(y);
	for(register int i=0;i<n;++i)read(x[i]);
	dfs(0,0,0);
	write(ans);
	fclose(stdin);
	fclose(stdout);
}
