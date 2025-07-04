#include<bits/stdc++.h>
using namespace std;
map<int, int> cnt, vis;
char a[50];
char s[100005];
int k, ans, len;
bool cmp(int x, int y) {
    if(cnt[x] == cnt[y]) return x > y;
    return cnt[x] < cnt[y];
}
int main() {
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
    scanf("%s" ,s+1);
    scanf("%d", &k);
    len = strlen(s+1);
    for(int i = 1; i <= len; i++) {
        if(!cnt[s[i]]) ans++;
        cnt[s[i]]++;
    }
    for(char i = 1; i <= 26; i++)
        a[i] = 'a'+i-1;
    sort(a+1, a+27, cmp);
    for(int i = 1; i <= 26; i++)
    {
        if(k < cnt[a[i]]) {
            cnt[a[i]] -= k;
            break;
        } else if(cnt[a[i]]) {
            k -= cnt[a[i]];
            cnt[a[i]] = 0;
            ans--;
        }
    }
	printf("%d\n", ans);
    if(ans) {
        for(int i = len; i; i--)
            if(cnt[s[i]]) {
                vis[i] = 1;
                cnt[s[i]]--;
            }
        for(int i = 1; i <= len; i++)
            if(vis[i]) printf("%c", s[i]);
    }
}