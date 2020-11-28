#include<cstdio>
#include<iostream>
using namespace std; 
typedef int TElemType;
int k;
 typedef struct BiTNode /* 树结点结构 */

   {

      TElemType data;

      struct BiTNode *lchild,*rchild; /* 左右孩子指针 */

   }BiTNode,*BiTree;
int cnt = 0;//计数
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
