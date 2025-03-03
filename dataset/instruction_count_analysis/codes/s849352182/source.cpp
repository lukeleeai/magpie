#include "stdc++.h"

using namespace std;



int main(){

	vector<int> v(3);

    int a;

    scanf("%d%d%d",&v[0],&v[1],&v[2]);

    scanf("%d",&a);

    sort(v.begin(),v.end());

    printf("%lld\n",(long long int)(v[0]+v[1]+v[2]*pow(2,a)));

	

	return 0;

}