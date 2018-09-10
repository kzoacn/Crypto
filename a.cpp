#include<bits/stdc++.h>
using namespace std;


vector<vector<int> >mp;
vector<int>vec;
bool push(){
	int prod=1;
	for(auto p:vec)prod*=p;
	for(int i=1;i<prod;i++){
		int cnt=0;
		int sign=1,pos=-1;
		for(int j=0;j<vec.size();j++){
			int v=mp[j][i%vec[j]];
			cnt+=abs(v);
			if(v){
				sign*=v;
			}else pos=j;
		}
		if(cnt+1==vec.size()){
			if(i<prod/2){
				mp[pos][i%vec[pos]]=sign;
			}else{
				mp[pos][i%vec[pos]]=-sign;
			}
		}
		if(cnt==vec.size()){
			if(i<prod/2){
				if(sign==-1){
	//				cerr<<"fail "<<i<<" "<<endl;
					return false;
				}
			}else{
				if(sign==1){
	//				cerr<<"fail "<<i<<" "<<endl;
					return false;
				}
			}
		}
	}
	return true;
}
void out(){
	for(int j=0;j<vec.size();j++){
		for(auto &x:mp[j])cout<<x<<" ";
		cout<<endl;
	}
}
void test(){
	int sz=vec.size();
	mp.resize(sz);
	for(int i=0;i<sz;i++){
		mp[i].resize(vec[i]);
		for(auto &x:mp[i])x=0;
	}
	for(int i=0;i<(1<<sz);i++){
		for(int j=0;j<sz;j++)
			mp[j][0]=(i>>j&1)?1:-1;
		int t=200;
		int ok=1;
		while(t-->0 && ok){
			ok&=push();
			if(!ok){
	//			out();
			}
		}
		if(ok){
			puts("yes!");
			out();	
			break;
		}
		for(int j=0;j<sz;j++){
			mp[j].resize(vec[j]);
			for(auto &x:mp[j])x=0;
		}
	}	
}
int main(){
	vector<int>prim=vector<int>{2,3,5,7,11,13,17,19,23,29};


	for(int k=1;k<prim.size();k++){
		int sum=0;
		for(int i=0;i<k;i++){
			sum+=((int)k-i-1)*prim[i];
		}
		cout<<sum<<",";
	}
	return 0;
}
