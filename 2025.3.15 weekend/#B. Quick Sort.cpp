#include<stdio.h>
#include<stdlib.h>
int T,n,a[500001],b[500001],c[500001],blen,clen,bbl;
char s[500001];
int cmp(const void*a,const void*b){return(*(int*)a-*(int*)b);}
main(){
	freopen("qsort.in","r",stdin);
	freopen("qsort.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		blen=0;
		bbl=0;
		clen=0; 
		for(int i=0;i<n;i++){
			scanf("%s",s);
			if(s[0]!='n'){
				sscanf(s,"%d",a+i);
				b[blen++]=a[i];
			}
			else a[i]=-1;
		}
		qsort(b,blen,sizeof(int),cmp);b[blen]=2147483647;
		for(int i=0;i<n;i++){
			if(~a[i]){
				if(b[bbl]>a[i])continue;
				while(b[bbl]<a[i])c[clen++]=b[bbl++];
				c[clen++]=b[bbl++];
			}
			else c[clen++]=-1;
		}
		for(int i=0;i<clen;i++){~c[i]?printf("%d ",c[i]):printf("nan ");}
		putchar('\n');
	}
}