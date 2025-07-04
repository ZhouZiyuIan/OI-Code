#include<stdio.h>
int t,sx,sy,ex,ey,s;
char c;
main(){
	scanf("%d%d%d%d%d\n",&t,&sx,&sy,&ex,&ey);
	while(t--){
//		printf("%d (%d,%d)\n",t,sx,sy);
		if(sx==ex&&sy==ey)break;
		scanf("%c",&c);
		if(c=='E'&&sx<ex)sx++;
		if(c=='W'&&sx>ex)sx--;
		if(c=='N'&&sy<ey)sy++;
		if(c=='S'&&sy>ey)sy--;
		s++;
	}
	if(sx!=ex||sy!=ey)puts("serious?");
	else printf("%d",s);
}
