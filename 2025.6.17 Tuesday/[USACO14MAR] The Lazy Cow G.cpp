#ifndef ONLINE_JUDGE
#pragma GCC optimize(2,3,"Ofast")
#endif
#include <cstdio>
#include <algorithm>
using namespace std;
#ifdef _WIN64
#define getchar_unlocked() _getchar_nolock()
#define putchar_unlocked(_c) _putchar_nolock(_c)
#endif
template <typename type>
inline void read(type &x) {
	x = 0;
	bool f = 0;
	char a = getchar_unlocked();
	while(!(a >= 48 && a <= 57)) {
		if(a == 45) {
			f = 1;
		}
		a=getchar_unlocked();
	}
	while(a >= 48 && a <= 57) {
		x = (x << 1) + (x << 3) + (a ^ 48);
		a = getchar_unlocked();
	}
	f ? x = -x : 0;
}
template <typename type>
inline void write(type x) {
	if(x < 0) {
		x = -x;
		putchar_unlocked(45);
	}
	if(x > 9) {
		write(x / 10);
	}
	putchar_unlocked(x % 10 + 48);
}
template <typename type,typename ...T>
inline void read(type &x, T&...y) {
	read(x);
	read(y...);
}
int n, k, g[100010], x[100010], y[100010], tmp[200010], len, l, r, ans;
struct tree{
	int mx[1 << 19], lz[1 << 19];
	void pushdown(int k) {
		mx[k << 1] += lz[k];
		lz[k << 1] += lz[k];
		mx[k << 1 | 1] += lz[k];
		lz[k << 1 | 1] += lz[k];
		lz[k] = 0;
	}
	void Add(int l, int r, int a, int L, int R, int k) {
		if(l <= L && R <= r) {
			mx[k] += a;
			lz[k] += a;
			return;
		}
		pushdown(k);
		int M = (L + R) >> 1;
		if(l <= M) {
			Add(l, r, a, L, M, k << 1);
		}
		if(r > M) {
			Add(l, r, a, M + 1, R, k << 1 | 1);
		}
		mx[k] = max(mx[k << 1], mx[k << 1 | 1]);
	}
	int Max(){
		return mx[1];
	}
}t;
void rotate(int &x, int &y) {
	int tmpx = x, tmpy = y;
	x = tmpx + tmpy;
	y = tmpy - tmpx;
}
struct segp{
	int l, r, y, f;
}p[200010];
bool cmp(segp a,segp b){return a.y==b.y?a.f>b.f:a.y<b.y;}
int main() {
	#ifndef ONLINE_JUDGE
	#ifndef _WIN64
	freopen("lazy.in","r",stdin);
	freopen("lazy.out","w",stdout);
	#endif
	#endif
	read(n, k);
	k<<=1;
	for(int i = 1; i <= n; ++i) {
		read(g[i], x[i], y[i]);
		rotate(x[i], y[i]);
		tmp[i]=x[i];
		tmp[i+n]=x[i]+k;
	}
	stable_sort(tmp + 1, tmp + 1 + (n << 1));
	tmp[0]=-1;
	for(int i = 1; i <= (n << 1); ++i) {
		if(tmp[i] != tmp[i - 1]) {
			tmp[++len] = tmp[i];
		}
	}
	for(int i = 1; i <= n; ++i) {
		l = lower_bound(tmp + 1, tmp + 1 + len, x[i]) - tmp;
		r = lower_bound(tmp + 1, tmp + 1 + len, x[i] + k) - tmp;
		p[i] = (segp){l, r, y[i], g[i]};
		p[i + n] = (segp){l, r, y[i] + k, -g[i]};
	}
	stable_sort(p + 1, p + 1 + (n << 1), cmp);
	for(int i = 1; i <= (n << 1); ++i) {
		t.Add(p[i].l, p[i].r, p[i].f, 1, (n << 1), 1);
		ans = max(ans, t.Max());
	}
	write(ans);
}
