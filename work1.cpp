#include<cstdio>
#include<iostream>
using namespace std; 
typedef int TElemType;
int k;
 typedef struct BiTNode /* �����ṹ */

   {

      TElemType data;

      struct BiTNode *lchild,*rchild; /* ���Һ���ָ�� */

   }BiTNode,*BiTree;
int cnt = 0;//����
TElemType ans;
void get_ans(BiTNode a){
	cnt++;
	if(cnt==k){
	ans = a.data;
	return ;
	}
	get_ans(*a.lchild);
	get_ans(*a.rchild);	
}
int main(){
	
	return 0;
} 
