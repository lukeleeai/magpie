/***

 *      百年修得同船渡，千年修得代码重.

 *      百年修得同船渡，千年修得代码重.

 *      百年修得同船渡，千年修得代码重.

 *      百年修得同船渡，千年修得代码重.

 *      百年修得同船渡，千年修得代码重.

 *      百年修得同船渡，千年修得代码重.

 *      百年修得同船渡，千年修得代码重.

 *      百年修得同船渡，千年修得代码重.

 *      百年修得同船渡，千年修得代码重.

 *      百年修得同船渡，千年修得代码重.

 *      百年修得同船渡，千年修得代码重.

 *      百年修得同船渡，千年修得代码重.

 *      百年修得同船渡，千年修得代码重.

 *      百年修得同船渡，千年修得代码重.

 *      百年修得同船渡，千年修得代码重.

 *      百年修得同船渡，千年修得代码重.

 *      百年修得同船渡，千年修得代码重.

 *      百年修得同船渡，千年修得代码重.

 *      百年修得同船渡，千年修得代码重.

 *      百年修得同船渡，千年修得代码重.

 *      百年修得同船渡，千年修得代码重.

 *      百年修得同船渡，千年修得代码重.

 *      百年修得同船渡，千年修得代码重.

 *      百年修得同船渡，千年修得代码重.

 *      百年修得同船渡，千年修得代码重.

 */

#include <iostream>

#include <queue>

#include <cstdio>

#include <cstdlib>

#include <algorithm>

#include <cstring>

#include <string>

#include <stack>

using namespace std;

//int n,m,x,y;

//char a[1010][1010];

//int vis[1010][1010];

//void dfs()

//{

//

//}

//int main()

//{

//    while(~scanf("%d%d",&n,&m))

//    {

//        for(int i=0;i<n;i++)

//        scanf("%s",a[i]);

//        for(int i=0;i<n;i++)

//            for(int j=0;j<m;j++)

//        {

//            if(a[i][j]=='*')

//                vis[i][j]=2;

//                if(a[i][j]=='+')

//                    vis[i][j]=1;

//                if(a[i][j]=='F')

//                    vis[i][j]=3;

//                if(a[i][j]=='G')

//                {

//                    x=i;

//                    y=j;

//                }

//                if(i==0&&a[i][j]=='+')

//                    vis[i][j]=4;

//                if(i==n&&a[i][j]=='+')

//                    vis[i][j]=4;

//                if(j==0&&a[i][j]=='+')

//                    vis[i][j]=4;

//                if(j==m&&a[i][j]=='+')

//                    vis[i][j]=4;

//

//        }

//

//     for(int i=0;i<n;i++)

//            {

//                for(int j=0;j<m;j++)

//                printf("%d ",vis[i][j]);

//                printf("\n");

//            }

// }

//    return 0;

//}

long long a[100000];

int main()

{

    long long n;

   for(int i=1;i<=100000;i++)

   a[i]=i*i;

   while(~scanf("%lld",&n))

   {int flag=0;

       for(int i=1;i<100000;i++)

       {

           if(a[i]==n)

           {

               printf("%lld\n",a[i]);

               break;

           }

           if(a[i]>n)

           {

               printf("%lld\n",a[i-1]);

               break;

           }

       }

   }



    return 0;

}