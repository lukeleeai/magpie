#include <vector>

#include <algorithm>

#include <stdio.h>

#include <iostream>

#include <queue>

#include <string>

#include <set>

#include <map>

#include <unordered_set>

#include <unordered_map>

using namespace std;

int main(){

    int a,b,c,x,y;

    scanf("%d %d %d %d %d\n",&a,&b,&c,&x,&y);

    int sum=a*x+b*y;

    int d=min(x,y);

    //cout<<sum<<endl;

    sum=min(sum,d*2*c+(x-d)*a+(y-d)*b);

    //cout<<sum<<endl;

    d=max(x,y);

    sum=min(sum,d*2*c);

    printf("%d\n",sum);

	return 0;

}