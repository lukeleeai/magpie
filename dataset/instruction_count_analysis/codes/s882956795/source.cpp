#include<iostream>

#include<cstdio>

#include<cstring>

using namespace std;

const int inf = 0x3f3f3f3f;

int mp[30][30];

char str[20][122];

int dp[1<<15][15];

int st[122];

int getval(char *a,char *b)

{

    int la,lb,len;

    la = strlen(a),lb = strlen(b);



    for (int i = 0;i < la;i++)

        if (memcmp( &a[i],b,lb ) == 0) return 0;



    for (len = min(la,lb);len > 0;len--)

    {

        int i,j;

        for (i = la - len,j = 0;j < len;i++,j++)

            if (a[i] != b[j]) break;

        if (j == len) break;

    }

    return lb-len;

}



//int getval(int x,int y ){

//    int l1 = strlen(str[x]);

//    int l2 = strlen(str[y]);

//    if(l1 > l2)

//        for(int i = 0; i < l1; i++){

//            if(i + l2 > l1) break;

//            int h  = 0;

//            for(int j = 0; j < l2; j++){

//                if(str[x][i+j] == str[y][j]){

//                     h++;

//                }

//            }

//            if(h == l2) return 0;

//        }

//    int l = min(l1,l2),id = 0;

//    for(int i = l; i >= 1; i--){

//        bool flag = true;

//        for(int j = 0; j < i; j++){

//            if(str[x][l1 - (i - j)] == str[y][j] ) continue;

//            else {flag = false;break;}

//        }

//        if(flag) {id = i;break;}

//    }

//    //cout<<id<<endl;

//    return l2 - id;

//}

int main(){

    int N;

    while(cin>>N && N){

        memset(st,0,sizeof(st));

        for(int i  = 0; i < N; i++){

            scanf("%s",str[i]);

            st[i] = 1<<i;

        }

        for(int i = 0; i < N; i++){

            for(int j = 0; j < N; j++){

                int t = getval(str[i],str[j]);

                if(t == 0) {

                    st[i] |= 1<<j;

                    mp[i][j] = 0;

                }

                else mp[i][j] = t;

               // cout<<i<<" "<<j<<" "<<mp[i][j]<<endl;

            }





        }

         memset(dp,-1,sizeof(dp));

         for (int i = 0;i < N;i++)

            dp[st[i]][i] = strlen(str[i]);



        for (int s = 0;s < (1<<N);s++)

            for (int i = 0;i < N;i++) if (dp[s][i] != -1)

            {

                for (int j = 0;j < N;j++) if (  !(s&1<<j)  )

                {

                    int tmp = s|st[j];//s|1<<j;

                    if (dp[tmp][j] == -1) dp[tmp][j] = dp[s][i]+mp[i][j];

                    else dp[tmp][j] = min(dp[tmp][j],dp[s][i]+mp[i][j]);

                }

            }



//        memset(dp,0x3f,sizeof(dp));

//        for(int i = 0; i < N; i++){

//                //cout<<s[i]<<endl;

//                dp[1<<i][i] = strlen(str[i]);

//        }

//

//        for(int i = 0; i < 1 << N; i++)

//            for(int j = 0; j < N; j++){

//                if(dp[i][j] == inf) continue;

//               // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;

//                for(int k = 0; k < N; k++) if(!(i & 1 << k))

//                    dp[i|s[k]][k] = min(dp[i|s[k]][k],dp[i][j] + mp[j][k]);

//            }

        int ans = inf;

        for(int i = 0; i < N; i++)if(dp[(1<<N)-1][i]!=-1)

            ans = min(dp[(1<<N)-1][i],ans);

        cout<<ans<<endl;

    }

    return 0;

}