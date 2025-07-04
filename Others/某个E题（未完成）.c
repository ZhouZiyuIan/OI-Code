#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n,is_full=1,to[26],tmp[26];
char s[200001],t[200001];
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}
main(){
    scanf("%d%s%s",&n,s,t);
    if(strcmp(s,t)==0){
        puts("0");
        return 0;
    }
    for(int i=0;i<n;i++){
        if(to[s[i]]==0)tmp[s[i]-97]=to[s[i]-97]=t[i]-97;
        else if(to[s[i]-97]!=t[i]-97){
            puts("-1");
            return 0;
        }
    }
    qsort(tmp,26,sizeof(int),cmp);
    for(int i=0;i<26;i++)is_full&=(tmp[i]==i);
    if(is_full){
        puts("-1");
        return 0;
    }
}