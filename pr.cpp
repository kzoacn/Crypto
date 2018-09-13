#include<bits/stdc++.h>
using namespace std;
const int maxn=1e8+6;

int p[maxn],tot;
bool notp[maxn];
void sieve(){
	for(int i=2;i<maxn;i++){
		if(!notp[i]){
			for(int j=i+i;j<maxn;j+=i)
				notp[j]=1;
		}
	}
	for(int i=2;i<maxn;i++)
		if(!notp[i])
			p[++tot]=i;
}

double f(int n){
	double ans=0;
	for(int i=1;i<=n;i++)
		ans+=1.0*(n-i)*p[i];
	return ans;
}
double g(int n){
	double ans=0;
	for(int i=1;i<=n;i++)
		ans+=1.0*n*p[i];
	return ans;
}

vector<int>anss,cur;
long long target;
int ans=1e9;
void dfs(int x,int sum,long long prod){
	if(prod*p[x]>=target){
		if(sum+p[x]<ans){
			ans=sum+p[x];
			anss=cur;
			anss.push_back(p[x]);
			cout<<sum<<endl;
			for(auto e:anss){
				cout<<e<<",";
			}
			cout<<endl;
		}
		return ;
	}
	cur.push_back(p[x]);
	dfs(x+1,sum+p[x],prod*p[x]);
	cur.pop_back();
	dfs(x+1,sum+p[x],prod*p[x]);
}

int main(){
	sieve();
	target=1LL<<62;
	dfs(1,0,1);
	return 0;
}
