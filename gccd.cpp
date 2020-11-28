#include<cstdio>
#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL;
int main(){
	LL n,a[1005],m,l,r,k,b[1005];
	cin >> n;
	for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
	cin >> m;
	for(int i = 1;i <= m;i++){
		cin >> l >> r >> k;
		k = r - l + 1 - k;
		for(int j = 1;j <= n;j++){
			b[j] = a[j];
			}
		sort(b+l,b+r);
		cout << b[l+k] << endl;
		}
	return 0;
	}
