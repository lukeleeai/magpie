#include"stdc++.h"

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

typedef pair<double,int> pdi;

const int N = 50005;

string str[N];

int main()

{

    string a;

    cin >> a;

    int k, cnt = 0;

    scanf("%d",&k);

    int siz = a.size();

    int mini;

    for(int i= 0; i < siz;i++)

    {

        str[++cnt] = a[i];

        mini =min(k,siz-i);

        for(int j = 1 + i; j < mini + i; j ++,cnt++)

            str[cnt + 1] = str[cnt] + a[j];

    }

    sort(str + 1, str + cnt + 1);

    unique(str + 1, str + cnt + 1);

    cout<< str[k] <<endl;

    return 0;

}














