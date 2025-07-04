#include<stdio.h>
#include<unordered_map>
using namespace std;
unordered_map<int,bool>all;
unordered_map<int,unordered_map<int,bool> >sin;
int n,m,q,op,x,y;
main(){
	scanf("%d%d%d",&n,&m,&q);
	while(q--){
		scanf("%d%d",&op,&x);
		if(op==1){
			scanf("%d",&y);
			sin[x][y]=1;
		}
		if(op==2)all[x]=1;
		if(op==3){
			scanf("%d",&y);
			if(sin[x][y]||all[x])puts("Yes");
			else puts("No");
		}
	}
}