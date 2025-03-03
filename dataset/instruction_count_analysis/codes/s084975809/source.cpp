#include <iostream>

#include <cstring>

using namespace std;

int main()

{

    int ans,m,len,a,x[30],y[30];

    string s;

    cin >> len;

    cin >> s;

    ans = a= 0;

    m = 1;

    while(m<len)

    {

        memset(x,0,sizeof(x));

        memset(y,0,sizeof(y));

        for (int i = 0 ;i < m ;i++)

        {

            x[s[i]-'a']++;

        }

        for (int i = m ;i < len ;i++)

        {

            y[s[i]-'a']++;

        }

        for (int i = 0 ; i < 30;i++)

        {

            if(x[i]&&y[i])

                a++;

        }

        if(ans<a)

            ans=a;

        a = 0;

        m++;

    }

    cout << ans << endl;

    return 0;

}
