#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
double test(double x){
	return (x-3.14159)*(x-3.14159);
}
int main(){
	double l = 0,r = 10;
	int cnt = 0;
	double mid;
	while(1){
		mid = (l + r ) / 2;
		if(test(l)<test(r))	r = mid;
		else l = mid;
		cnt++;
		if(cnt>=15)break;
	}
	printf("%lf\n",mid);
} 
