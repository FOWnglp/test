#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<ctime>
#include<cstdlib>
#define pi 3.1415926535897 
using namespace std;
typedef double db;
db ans = 0x3f3f3f;
db pos = -100;
db pos1 = -100;
db pos2 = -100;
db pos3 = -100;
db l,r,x1l,x2l,x3l,x1r,x2r,x3r;
struct A{
	db index;
	db val;
}; 
struct B{
	db index1;
	db index2;
	db val;
}; 
struct C{
	db index1;
	db index2;
	db index3;
	db val;
}; 
struct A pso[20];//粒子
struct B pso2[20];
struct C pso3[20];
bool cmp(A a,A b){
	return a.val<b.val;
}
bool cmp2(B a,B b){
	return a.val<b.val;
}
bool cmp3(C a,C b){
	return a.val<b.val;
}
db fun1(db x){
	return -20*exp(-0.2*(x>0?x:-x))-exp(cos(2*pi*x))+20;
} 
db fun2(db x1,db x2){
	return -20*exp(-0.2*sqrt(0.5*(x1*x1+x2*x2)))-exp(0.5*( cos(2*pi*x1) + cos(2*pi*x2) ))+20;
}
db fun3(db x1,db x2,db x3){
	return -20*exp( -0.2*sqrt( (x1*x1+x2*x2) / 3 ) )-exp( ( cos(2*pi*x1) + cos(2*pi*x2) + cos(2*pi*x3) ) /3 )+20;
}

db Rand1(){
	db R = rand()%((int)(r*100-l*100));
	return l + R / 100;
}
db Rand2(){
	db R = rand()%((int)(x2r*100-x2l*100));
	return x2l + R / 100;
}
db Rand3(){
	db R = rand()%((int)(x3r*100-x3l*100));
	return x3l + R / 100;
}
 
void init1(){
	for(int i = 0;i < 20;i++){
		pso[i].index=Rand1();
		pso[i].val=fun1(pso[i].index);
		if(ans > pso[i].val){
		ans = pso[i].val;
		pos = pso[i].index;
		}
	}
}
void init2(){
	for(int i = 0;i < 20;i++){
		pso2[i].index1=Rand1();
		pso2[i].index2=Rand2();
		pso2[i].val=fun2(pso2[i].index1,pso2[i].index2);
		if(ans > pso2[i].val){
		ans = pso2[i].val;
		pos1 = pso2[i].index1;
		pos2 = pso2[i].index2;
		}
	}
}
void init3(){
	for(int i = 0;i < 20;i++){
		pso3[i].index1=Rand1();
		pso3[i].index2=Rand2();
		pso3[i].index3=Rand3();
		pso3[i].val=fun3(pso3[i].index1,pso3[i].index2,pso3[i].index3);
		if(ans > pso3[i].val){
		ans = pso3[i].val;
		pos1 = pso3[i].index1;
		pos2 = pso3[i].index2;
		pos3 = pso3[i].index3;
		}
	}
}
void rnew1(){
	db L = 100,R = -100;
	for(int i = 0;i < 10;i++){
		if(pso[i].index>R)R = pso[i].index;
		if(pso[i].index<L)L = pso[i].index;
	}
	l = L,r = R;
}
void rnew2(){
	db L = 100,R = -100;
	db L2 = 100,R2 = -100;
	for(int i = 0;i < 10;i++){
		if(pso2[i].index1>R)R = pso2[i].index1;
		if(pso2[i].index1<L)L = pso2[i].index1;
		if(pso2[i].index2>R2)R2 = pso2[i].index2;
		if(pso2[i].index2<L2)L2 = pso2[i].index2;
	}
	l = L,r = R;
	x2l = L2,x2r = R2;
}
void rnew3(){
	db L = 100,R = -100;
	db L2 = 100,R2 = -100,L3 = 100,R3 = -100;
	for(int i = 0;i < 10;i++){
		if(pso3[i].index1>R)R = pso3[i].index1;
		if(pso3[i].index1<L)L = pso3[i].index1;
		if(pso3[i].index2>R2)R2 = pso3[i].index2;
		if(pso3[i].index2<L2)L2 = pso3[i].index2;
		if(pso3[i].index3>R3)R3 = pso3[i].index3;
		if(pso3[i].index3<L3)L3 = pso3[i].index3;
	}
	l = L,r = R;
	x2l = L2,x2r = R2;
	x3l = L3,x3r = R3;
}
int main(){
	srand(time(0)); //随机数种子 	
	l = -32.77,r=32.77,x1l=x2l=x3l=-32.77,x1r=x2r=x3r=32.77;//初始化

	int cnt = 16;//设置迭代次数 
		while(cnt--){
		init2();
		sort(pso2,pso2+20,cmp2);
		rnew2();
	}
	 //一维函数测试： 
	/*
		while(cnt--) {
			init1();
			sort(pso,pso+20,cmp);
			rnew1();
		}
		*/
	//二维函数测试： 
	
	/*三维函数测试 
	while(cnt--){
		init3();
		sort(pso3,pso3+20,cmp3);
		rnew3();
	}
	*/ 
	//一维函数遍历结果 
	/*
	for(db i = -32.77;i <= 32.77;i+=0.01){
		db ck = fun1(i);
		if(ck<ans)	{
			ans = ck;
			pos = i;	
		}	
	}
	*/
	//二维函数遍历结果 
	/*
	for(db i = -32.77;i <= 32.77;i+=0.01){
		for(db j = -32.77;j <= 32.77;j+=0.01){
			db ck = fun2(i,j);
			if(ck<ans)	{
				ans = ck;
				pos1 = i;
				pos2 = j;	
			}	
		}
	}
	*/
	//三维函数遍历结果 
	/*
	for(db i = -32.77;i <= 32.77;i+=0.01){
		for(db j = -32.77;j <= 32.77;j+=0.01){
			for(db k = -32.77;k <= 32.77;k+=0.01){
			db ck = fun3(i,j,k);
			if(ck<ans)	{
				ans = ck;
				pos1 = i;
				pos2 = j;
				pos3 = k;	
			}	
		}
		}
	}
	*/
	if(pos>-0.001&&pos<0.001)pos=0;
	if(pos1>-0.001&&pos1<0.001)pos1=0;
	if(pos2>-0.001&&pos2<0.001)pos2=0;
	if(pos3>-0.001&&pos3<0.001)pos3=0;
	//结果输出： 
	cout << ans <<endl;
//	cout << pos <<endl;
	cout << pos1 <<" " << pos2 <<endl;
//	cout << pos1 << "  " << pos2 << " " << pos3 <<endl;
	return 0;
} 
