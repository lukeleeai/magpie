#include<iostream>

#include<algorithm>

#include<string>

//#include<Hatsune_Miku>

using namespace std;

 long long f[420001]={2};

int n,ans=0;

int main()

{

	std::ios::sync_with_stdio(false);

	cin>>n;

	for(int i=1;i<=n;i++)

	{

		f[i]=f[i-1]*2+2;

	}

	cout<<f[n]<<endl;

    return 0;

}