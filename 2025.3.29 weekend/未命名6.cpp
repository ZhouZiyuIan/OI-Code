#include<stdio.h>
#include<algorithm>
using namespace std;
struct aa{
	int a,b;
}aaa[100001];
bool cmp(aa a,aa b){
	if(a.a!=b.a)return a.a<b.a;
	return a.b<b.b;
}
int x;
main(){
	freopen("out.txt","r",stdin);
//	freopen("ccc.txt","w",stdout);
	while(scanf("%d%d",&aaa[x].a,&aaa[x++].b)!=EOF);
	sort(aaa,aaa+x,cmp);
	for(int i=0;i<x;i++)printf("%d %d\n",aaa[i].a,aaa[i].b);
}
