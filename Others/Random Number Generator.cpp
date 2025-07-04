#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
int a;
int l=1,r=50;
int seed=0;
main(){
	srand(seed?seed:time(0));
	if(l>r)a=l,l=r,r=a;
	while(1){
		printf("%d",rand()%(r-l+1)+l);
		if(_kbhit()){
			a=_getch();
			if(a==' ')a=_getch();
			if(a==27){
				system("cls");
				break;
			}
		}
		system("cls");
	}
}
