#include "stdc++.h"

#define ll long long 

#define maxn 500005

#define INF 0x3f3f3f3f

using namespace std;



int n;

int a[maxn];

struct Node{

    int x, y;

    Node():x(0), y(0){}

    Node(int xx, int yy): x(xx), y(yy){}

};

vector<Node> ans;

bool vis[maxn];

int main(){

    scanf("%d", &n);

    int da = 0, xiao = 0;

    for(int i = 1; i <= n; i++){

        scanf("%d", &a[i]);

        if(a[i] >= 0) da++;

        else

            xiao++;

    }

    if(!xiao){

        sort(a + 1, a + 1 + n);

        int p = a[1];

        for(int i = 2; i <= n - 1; i++){

            ans.push_back(Node(p, a[i]));

            p -= a[i];

        }

        ans.push_back(Node(a[n], p));

        printf("%d\n", a[n] - p);

    }

    else if(!da){

        sort(a + 1, a + 1 + n);

        int p = a[n];

        for(int i = n - 1; i >= 2; i--){

            ans.push_back(Node(p, a[i]));

            p -= a[i];

        }

        ans.push_back(Node(p, a[1]));

        printf("%d\n", p - a[1]);

    }

    else{

        int fu = INF, z = INF;

        sort(a + 1, a + 1 + n);

        memset(vis, false, sizeof(vis));

        for(int i = 1; i <= n; i++){

            if(a[i] < 0 && fu == INF){

                fu = a[i];

                vis[i] = true;

                break;

            }

        }

        for(int i = n; i >= 1; i--){

            if(a[i] >= 0 && z == INF){

                z = a[i];

                vis[i] = true;

                break;

            }

        }

        for(int i = 1; i <= n; i++){

            if(!vis[i]){

                if(a[i] >= 0){

                    ans.push_back(Node(fu, a[i]));

                    fu -= a[i];

                }

                else{

                    ans.push_back(Node(z, a[i]));

                    z -= a[i];

                }

            }

        }

        ans.push_back(Node(z, fu));

        printf("%d\n", z - fu);       

    }

    for (int i = 0; i < ans.size(); i++) {

        printf("%d %d\n", ans[i].x, ans[i].y);

    }

    return 0;

}