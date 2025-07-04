#include<stdio.h>
int x,y,jiz[2000001],bn[2000001];
char op[4];
main(){
	while(1){
		scanf("%s",op);
		if(op[0]=='E')break;
		else scanf("%d",&x);
		if(op[0]=='a'){
			scanf("%d",&y);
			if(bn[x]==y)puts("FULL");
			else jiz[bn[x]]--,bn[x]=y,jiz[y]++;
		}
		if(op[0]=='d'){
			if(bn[x]==0)puts("NULL");
			else jiz[bn[x]]--,bn[x]=0;
		}
		if(op[0]=='f'&&op[1]=='r'){
			if(bn[x]==0)puts("NULL");
			else printf("%d\n",bn[x]);
		}
		if(op[0]=='s')printf("%d\n",jiz[x]);
		if(op[0]=='f'&&op[1]=='i'){
			scanf("%d",&y);
			if(bn[x]==y)puts("Yes");
			else puts("No");
		}
	}
}
