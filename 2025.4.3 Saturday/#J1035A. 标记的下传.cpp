#include<stdio.h>
struct node{
	int ls,rs,fa;
	double lzt;
}dot[100001];
int n,m,x,y,op;
double res,tmp;
inline void searchup(int cur){
	if(!dot[cur].fa){
		tmp+=dot[cur].lzt;
		return;
	}
	searchup(dot[cur].fa);
	if(tmp)res*=1-(1/(tmp+1));
	tmp+=dot[cur].lzt;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		dot[x].fa=i;
		dot[y].fa=i;
		dot[i].ls=x;
		dot[i].rs=y;
	}
	while(m--){
		scanf("%d%d",&op,&x);
		if(op==1){
			scanf("%d",&y);
			dot[x].lzt+=y;
		}
		if(op==2){
			dot[dot[x].ls].lzt+=dot[x].lzt;
			dot[dot[x].rs].lzt+=dot[x].lzt;
			dot[x].lzt=0;
		}
		if(op==3){
			res=1;
			tmp=0;
			searchup(x);
			printf("%.6lf\n",res);
		}
	}
}
