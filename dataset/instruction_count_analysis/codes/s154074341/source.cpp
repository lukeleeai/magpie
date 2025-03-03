#include <iostream> 



#include <stdio.h>

using namespace std; 

typedef long ll;



 int main(){



    int length;

    ll arr[200000];

    ll res[200000]={0};

    ll temp = 0;

    ll m = 2147483647;

    scanf("%d",&length);

   	for(int i=0;i<length;++i){

   		scanf("%ld",&arr[i]);

   	}

   	res[0] = arr[0];

    for(int i=1;i<length;++i){

    	res[i] += res[i-1] + arr[i];

    }

    for(int i=1;i<length;++i){

    	temp = abs(res[length-1]-res[i-1]*2);

    	m = min(temp,m);

    }

    printf("%ld\n", m);





 	return 0;

 }
