#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	long long n;
	for(cin>>T;T>0;T--)
	{
		cin>>n;
		if(n%2==1||n==2)
		{
			cout<<"-1\n";
			continue;
		}
		n/=2;
		cout<<(n+2)/3<<' '<<n/2<<'\n';
	}
	return 0;
}