#include<stdio.h>
#include<algorithm>
using namespace std;
int k,i,len,lstl,array[200012],j,fl,fl2;
struct limit{
	int x,y;
}l[1001];
bool cmp(limit a,limit b){
	return a.x<b.x;
}
int main(){
//	freopen("test.in","r",stdin);
	scanf("%d",&k);
	for(i=0;i<k;i++){
		scanf("%d%d",&l[i].x,&l[i].y);
		if(l[i].y)fl2=1;
	}
	if(!fl2){
		puts("0");
		exit(0);
	}
	if(l[0].x==0&&l[0].y){
		puts("-1");
		exit(0);
	}
	sort(l,l+k,cmp);
	if(l[0].x&&l[0].y==0){
		puts("-1");
		exit(0);
	}
	for(i=0;i<l[0].x-1;i++)array[++len]=i;
	for(i=0;i<l[0].y;i++)array[++len]=l[0].x-1;
	for(i=1;i<k;i++){
		if(len>2e5){
			puts("-1");
			exit(0);
		}
		if(fl&&l[i].y){
			puts("-1");
			exit(0);
		}
		if(!l[i].y)fl=1;
		if(l[i].x&&l[i].y==0){
			puts("-1");
			exit(0);
		}
		lstl=len;
		for(j=array[lstl]+1;j<l[i].x-1;j++)array[++len]=j;
		for(j=0;j<l[i].y;j++)array[++len]=l[i].x-1;
	}
	printf("%d\n",len);
	for(i=1;i<=len;i++)printf("%d ",array[i]);
}
