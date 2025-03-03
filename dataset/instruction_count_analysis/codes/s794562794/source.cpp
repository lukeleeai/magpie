//先从左边先行扫描一遍，再从右边扫描一遍，两边加起来直接用总人数相减

    #include <iostream>

    #include <cstring>

    #include <cstdio>

    #include <string>



    using namespace std;



    const int maxn=1e6+10;



    int n;

    int l[maxn],r[maxn];

    char str[maxn];

    int maxx=0;



    int main()

    {

        scanf("%d",&n);

        scanf("%s",str);



        memset(l,0,sizeof(l));

        memset(r,0,sizeof(r));



        for(int i=0;i<n;i++)

        {

            l[i]=l[i-1];

            if(str[i]=='E') {

                    l[i]++;

            }

        }



        for(int i=n-1;i>=0;i--)

        {

            r[i]=r[i+1];

            if(str[i]=='W') {

                    r[i]++;

            }

        }





         for(int i=0;i<n;i++) {

            r[i]=r[i]+l[i];

            maxx=max(r[i],maxx);

         }



         cout<<n-maxx<<endl;









        return 0;

    }
