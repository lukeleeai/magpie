#include <iostream>

#include <algorithm>

#include <stdio.h>

#include <string.h>

#include <cstring>

#include <vector>

#include <cmath>

#include <queue>

#include <map>

using namespace std;

vector <string>ans;

vector <string>m[150];

map<string ,int >id;

int vis[1500];

int n;

char   s[150000];

char tmp[1500];

void gao(int now)

{

     vis[now]=1;

     for(int i=0;i<m[now].size();i++)

     {

         string haha  = m[now][i];

         //printf ("%d\n",id[haha]);

         if (id.count(haha))

         {

             if (vis[id[haha]])

                continue;

             else

                gao(id[haha]);

         }

         else{

            ans.push_back(haha);

         }

     }

}

int main()

{

    while(scanf("%d",&n),n)

    {

            id.clear();

            ans.clear();

            for(int i=0;i<=n;i++)

                m[i].clear();

            memset(vis,0,sizeof(vis));

       for(int i=1;i<=n;i++)

       {

            scanf("%s",s+1);

            int len = strlen(s+1);

            int now=0;

            for (int j=1;j<=len;j++)

            {

                 if (s[j]==':')

                 {

                     tmp[now]=0;

                     now=0;

                     id[string(tmp)] = i;

                     //printf ("%d",id[string(tmp)]);

                     //cout<<string(tmp)<<endl;

                     //cout<<string(tmp)<<endl;

                 }

                 else if (s[j]==',' || s[j]=='.')

                 {

                     tmp[now]=0;

                     now =0;

                     m[i].push_back(string(tmp));



                 }

                 else{

                    tmp[now++]=s[j];

                 }

            }

       }

        gao(1);

        sort(ans.begin(), ans.end());

        ans.resize(unique(ans.begin(), ans.end()) - ans.begin());

        printf ("%d\n", ans.size());

        //for(int i=0;i<ans.size();i++)

            //cout<<ans[i]<<endl;



    }

    return 0;

}