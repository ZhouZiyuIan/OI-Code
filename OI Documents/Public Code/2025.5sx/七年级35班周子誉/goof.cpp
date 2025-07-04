#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<algorithm>
using namespace std;
template<typename T>
void read(T &n){
	n=0;
	T f=1;
	char s=getchar();
	while(!isdigit(s)){
		if(s=='-')f*=-1;
		s=getchar();
	}
	do{
		n=(n<<1)+(n<<3)+(s^48);
		s=getchar();
	}while(isdigit(s));
	n*=f;
}
template<typename T>
void write(T x){
	if(x<0)putchar(45),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+48);
}
struct chars{
	int times,org;
}types[26];
bool cmp(chars a,chars b){
	if(a.times==0&&b.times==0)return 0;
	else if(a.times==0)return 0;
	else if(b.times==0)return 1;
	else return a.times<b.times;
}
char s[100010];
int k,lens,ct,del[26],bab;
main(){
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	scanf("%s",s);
	read(k);
	lens=strlen(s);
	for(int i=0;i<26;i++)types[i].org=i;
	for(int i=0;i<lens;i++){
		if(types[s[i]-'a'].times==0)bab++;
		types[s[i]-'a'].times++;
	}
	sort(types,types+26,cmp);
	for(int i=0;i<26;i++){
		if(k==0||types[i].times==0)break;
		if(k>=types[i].times){
			ct++;
			k-=types[i].times;
			del[types[i].org]=1;
		}
		else break;
	}
	write(bab-ct);putchar(10);
	for(int i=0;i<lens;i++)del[s[i]-'a']?0:putchar(s[i]);
}
