#pragma GCC optimize(3,"Ofast","inline")
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
template <typename type>
inline void read(type &x) {
	x = 0;
	bool f = 0;
	char a = getchar();
	while(!(a >= 48 && a <= 57)) {
		if(a == 45) {
            f = 1;
        }
		a = getchar();
	}
	while(a >= 48 && a <= 57) {
		x = (x << 1) + (x << 3) + (a ^ 48);
		a = getchar();
	}
	f ? x = -x : 0;
}
template <typename type>
inline void write(type x) {
	if(x < 0) {
        x = -x;
        putchar(45);
    }
	if(x > 9) {
        write(x / 10);
    }
	putchar(x % 10 + 48);
}
inline string read(string &s){
    string x;
    char a = getchar();
    while(!(a != 32 && a != 10 && a != 13)) {
        a = getchar();
    }
    while(a != 32 && a != 10 && a != 13) {
        x += a;
        a = getchar();
    }
    return s=x;
}
unordered_map<string,long long>cnt;
string a[10],tmp;
long long n, c, ans;
int main() {
    freopen("patibility.in", "r", stdin);
    freopen("patibility.out", "w", stdout);
    read(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 5; j++) {
            read(a[j]);
        }
        sort(a, a + 5);
        for(int j = 1; j < 32; j++) {
            c = 0;
            tmp = "";
            for(int k = 0; k < 5; k++) {
                if(j & (1 << k)) {
                    c++;
                    tmp += a[k] + " ";
                }
            }
            if(c & 1) {
                ans += cnt[tmp];
            } else {
                ans -= cnt[tmp];
            }
            cnt[tmp]++;
        }
    }
    write((n * (n - 1ll) >> 1ll) - ans);
}