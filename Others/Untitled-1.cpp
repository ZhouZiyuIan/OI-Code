#include<stdio.h>
int n,v[6],cnt,stat,tot;
main(){
    scanf("%d",&n);
    for(int i=0;i<6;i++)scanf("%d",&v[i]);
    while(n--){
        scanf("%d",&stat);
        if(stat){
            cnt++;
            if(1<=cnt&&cnt<3)tot+=v[0];
            else if(3<=cnt&&cnt<7)tot+=v[1];
            else if(7<=cnt&&cnt<30)tot+=v[2];
            else if(30<=cnt&&cnt<120)tot+=v[3];
            else if(120<=cnt&&cnt<365)tot+=v[4];
            else tot+=v[5];
        }
        else cnt=0;
    }
    printf("%d",tot);
}