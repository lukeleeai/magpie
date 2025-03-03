#include <iostream>

using namespace std;

int main()

{

	int N,i;

	cin>>N;

	long long str[N];

	str[0]=2;str[1]=1;

	for(i=2;i<=N;i++){

		str[i]=str[i-1]+str[i-2];

	}

	cout<<str[N]<<endl;

	return 0;

} 