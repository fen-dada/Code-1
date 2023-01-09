#include <bits/stdc++.h>
using namespace std;
#define echo(x) cout<<#x" = "<<(x)<<endl
#define cpp_fast_io cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

#define massert(E)	\
	if(not(E)){		\
		cerr<<"assert failed at line "<<__LINE__<<"\n\texpr: "#E<<endl;	\
		throw 0;	\
	}				\
//

int t(char x)
{
	if(x=='?') return 0;
	if(x==':') return 1;
	return -1;
}

[[noreturn]]
void NO()
{
	cout<<"No"<<endl;
	exit(0);
}

int main()
{
	int n;
	cin>>n;
	if(not(n&1)) NO();
	
	string a[n];
	for(int i=0;i<n;i++) cin>>a[i];
//	0?0?0
//	01234
	vector<bool> H;
	for(int i=0;i<n;i++)
	{
		int T=t(a[i][0]);
		if(T==-1)
		{
			if(i&1) NO();
		}
		else
		{
			if(not(i&1)) NO();
			H.push_back(T);
		}
	}
	massert(H.size()==n/2);
	
	int count=0;
	for(int i=0;i<H.size();i++)
	{
		if(H[i]==0) count++;
		else
		{
			if(count==0) NO();
			count--;
		}
	}
	if(count) NO();
	
	cout<<"Yes"<<endl; 
}


