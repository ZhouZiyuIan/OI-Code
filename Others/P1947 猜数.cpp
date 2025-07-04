extern "C" int Seniorious(int);
extern "C" int Chtholly(int n,int c){
	int l=1,r=n,mid,ans;
	while(l<=r){
		mid=(l+r)>>1;
		ans=Seniorious(mid);
		if(ans==0)return mid;
		if(ans==-1)l=mid+1;
		else r=mid-1;
	}
}
