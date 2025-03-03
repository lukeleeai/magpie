#include <iostream>

#include <algorithm>

#include <vector>

#include <list>

#include <climits>

#include <queue>

#include <string>

#include <map>

#include <stack>

#include <cmath>

#include <regex>

#include<ctime>

#include<set>

using namespace std;

int main()

{

ios::sync_with_stdio(false);

int n;

int d[100000];

cin>>n;

int i1=0,i2=0;

for(int i=0;i<n;i++)

{

     cin>>d[i];

     if(d[i]%4==0)

        i1++;

     else if(d[i]%2!=0)

        i2++;

}

if(i1+i2==n&&i2==i1+1)

    cout<<"Yes"<<endl;

else if(i1>=i2)

    cout<<"Yes"<<endl;

else

    cout<<"No"<<endl;







}
