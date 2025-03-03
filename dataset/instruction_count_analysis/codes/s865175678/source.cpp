#include <vector> 

#include <list> 

#include <map> 

#include <set> 

#include <deque> 

#include <queue> 

#include <stack> 

#include <bitset> 

#include <algorithm> 

#include <functional> 

#include <numeric> 

#include <utility> 

#include <sstream> 

#include <iostream> 

#include <iomanip> 

#include <cstdio> 

#include <cmath> 

#include <cstdlib> 

#include <cctype> 

#include <string> 

#include <cstring> 

#include <ctime> 

using namespace std;



#define _int64 long long



char s[600000];

int dp[600000][3];

vector<int> a;



int main()

{

  int i,j,n,cnt,tmp;

  cin >> n >> s;

  cnt=0;

  a.clear();

  for (i=0;i<n;i++)

  {

    if (s[i]=='1') cnt++;

    else

    {

      if (cnt>0) a.push_back(cnt);

      a.push_back(0);

      cnt=0;

    }

  }

  if (cnt>0) a.push_back(cnt);

  memset(dp,-1,sizeof(dp));

  dp[0][0]=0;

  for (i=0;i<a.size();i++)

  {

    for (j=0;j<3;j++)

      if (dp[i][j]!=-1)

      {

        if (dp[i+1][0]<dp[i][j])

          dp[i+1][0]=dp[i][j];

        if ((i+2<a.size())&&(a[i]>0)&&(a[i+1]==0)&&(a[i+2]>0))

        {

          if (j==0)

          {

            tmp=dp[i][j]+a[i]+1-1;

            if (a[i+2]>1)

            {

              if (tmp>dp[i+2][1]) dp[i+2][1]=tmp;

            }

            else

            {

              if (tmp>dp[i+3][0]) dp[i+3][0]=tmp;

            }

            tmp=dp[i][j]+1+a[i+2]-1;

            if (tmp>dp[i+3][0]) dp[i+3][0]=tmp;

            if (a[i+2]>1)

            {

              tmp=dp[i][j]+1+a[i+2]-1-1;

              if (tmp>dp[i+2][2]) dp[i+2][2]=tmp;

            }

          }

          if (j==1)

          {

            tmp=dp[i][j]+a[i]-1+1-1;

            if (a[i+2]>1)

            {

              if (tmp>dp[i+2][1]) dp[i+2][1]=tmp;

            }

            else

            {

              if (tmp>dp[i+3][0]) dp[i+3][0]=tmp;

            }

            tmp=dp[i][j]+1+a[i+2]-1;

            if (tmp>dp[i+3][0]) dp[i+3][0]=tmp;

            if (a[i+2]>1)

            {

              tmp=dp[i][j]+1+a[i+2]-1-1;

              if (tmp>dp[i+2][2]) dp[i+2][2]=tmp;

            }

          }

          if (j==2)

          {

            tmp=dp[i][j]+1+1-1;

            if (a[i+2]>1)

            {

              if (tmp>dp[i+2][1]) dp[i+2][1]=tmp;

            }

            else

            {

              if (tmp>dp[i+3][0]) dp[i+3][0]=tmp;

            }

            tmp=dp[i][j]+1+a[i+2]-1;

            if (tmp>dp[i+3][0]) dp[i+3][0]=tmp;

            if (a[i+2]>1)

            {

              tmp=dp[i][j]+1+a[i+2]-1-1;

              if (tmp>dp[i+2][2]) dp[i+2][2]=tmp;

            }

          }

        }

      }

  }

  printf("%d\n",dp[a.size()][0]);

  return 0;

}