#include<iostream>

#include<algorithm>

#include<cstring>

using namespace std;

int a[100005],f[100005];

int main()

  {int n,k;

    cin >> n >> k;

   int i,Min = 0x7fffffff,num = 0;

   memset(a,0,sizeof(a));

   memset(f,0,sizeof(f));

   for(i = 1;i <= n;i ++)

          {cin >>a[i];Min = min(a[i],Min);

          }

   for(i = 1;i <= n;i ++)

   {  if(a[i] != Min)f[num]++;

      else num++;

   }

   int cnt = 0;

   if(a[n] == Min)num--;

   for(i = 0;i <= num;i ++)

   {

    while(f[i] > 0)

        {   cnt ++;

            f[i] -= k-1;

        }

    if(f[i] < 0)

       f[i+1] += f[i];

   }

   cout<<cnt<<endl;

  }
