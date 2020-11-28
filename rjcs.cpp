#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<stack>
using namespace std;
string Swh;
string Sfor;
string Swi;
string Sif;
stack<int > stk;
int main(){
	string s;
	int cnt = 0;
	while(getline(cin,s)){
		cnt++;
		for(int i = 0;i < s.size();i++){
			if(s[i]==' '){
				Swh = s.substr(i+1,6);
				Sfor = s.substr(i+1,4);
				Swi = s.substr(i+1,7);
				Sif = s.substr(i+1,3);
				if(Sif=="if("){
				}
				else if(Swh=="while("){
					
				}
				else if(Sfor == "for("){
					
				}
				else if(Swi == "switch("){
					
				}
			}
		}
	}
	return 0;
} 
