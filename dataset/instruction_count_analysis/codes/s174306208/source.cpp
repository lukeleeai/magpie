#include"stdc++.h"

using namespace std;



int main()

{

    char a[15];

    int n;

    cin >> n;

    int b = 0,c = 0,d = 0,e = 0;

    while(n -- )

    {

        memset(a,'\0',sizeof(a));

        cin >> a;

        if(a[0] == 'B')

            b ++ ;

        if(a[strlen(a) - 1] == 'A')

            c ++ ;

        if(a[strlen(a) - 1] == 'A' && a[0] == 'B')

            d ++ ;

        for(int i = 0 ; i < strlen(a) ; i ++ )

        {

            if(a[i] == 'A' && a[i + 1] == 'B')

                e ++ ;

        }

    }

    int aa = min(b,c);

    if(b == d && c == d && d != 0)

        e -- ;

    cout << e + aa << endl;

    return 0;

}