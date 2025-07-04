#include <iostream>
#include <algorithm>

#include<stdio.h>
using namespace std ;
int n , al , a[50005] ;
bool flag = true ;
struct node {
	int x , y ;
}q[105];
bool cmp(node a , node b){return a . x < b . x ;}
int main() {
	freopen("test.in","r",stdin);
	cin >> n ;
	for(int i = 1 ; i <= n ; i++) {
		cin >> q[i] . x >> q[i] . y ;
	}
	sort(q + 1 , q + 1 + n , cmp) ;
	if(q[1] . x == 0 && q[1] . y != 0 && q[2] . y != 0) {
		cout << -1 ;
		return 0 ;
	}
	if(q[1] . x != 1 && q[1] . x != 0){
		bool t = false ;
		for(int i = 1 ; i <= n ; i++) {
			if(q[i] . y != 0)t = true ;
		}
		if(t)al = 1 , a[al] = 0 ;
	}
	for(int j = 1 ; j <= n ; j++) {
		if(q[j] . y == 0 && q[j + 1] . y != 0 && q[j] . x != 0) {
			flag = false ;
			break ;
		}
		if(q[j] . x == 0)for(int i = 1 ; i <= q[1] . y ; i++)a[++ al] = 1 ;
		else if(q[j] . y > 0){
			if(al == 0)a[1] = 0 , al = 1 ;
			while(a[al] < q[j] . x - 2)a[al + 1] = a[al] + 1 , al ++ ;
			for(int i = 1 ; i <= q[j] . y ; i++)a[++ al] = q[j] . x - 1 ;
		}
	}
	if(flag) {
		cout << al << endl ;
		for(int i = 1 ; i <= al ; i++) {
			cout << a[i] << ' ' ;
		}
	}
	else cout << -1 ;
	return 0 ;
	
}
