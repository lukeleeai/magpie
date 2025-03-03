#include <iostream>

#include <string>

#include <cstring>

using namespace std;



int a[100010];

int main()

{

    int n; cin>>n;

    string s; cin>>s;



    if (s[0]=='o') {

        memset(a, 0, sizeof(a));

        a[0]=1; // S

        // SSS

        a[1]=a[n-1]=1;

        for(int i=1; i+2<n; ++i) {

            if (s[i]=='o')

                a[i+1]=a[i] ? a[i-1] : !a[i-1];

            else

                a[i+1]=!a[i] ? a[i-1] : !a[i-1];

        }

        bool ok=true;

        if (s[n-2]=='o') {

            if (a[n-2] and a[n-3]!=a[n-1] or !a[n-2] and a[n-3]==a[n-1])

                ok=false;

        }

        else {

            if (a[n-2] and a[n-3]==a[n-1] or !a[n-2] and a[n-3]!=a[n-1])

                ok=false;

        }

        if (ok) {

            if (s[n-1]=='o') {

                if (a[n-1] and a[n-2]==a[0] or !a[n-1] and a[n-2]!=a[0]) {

                    for(int i=0; i<n; ++i) cout<<(a[i]?'S':'W');

                    cout<<endl;

                    return 0;

                }

            }

            else {

                if (a[n-1] and a[n-2]!=a[0] or !a[n-1] and a[n-2]==a[0]) {

                    for(int i=0; i<n; ++i) cout<<(a[i]?'S':'W');

                    cout<<endl;

                    return 0;

                }

            }

        }

        memset(a, 0, sizeof(a));

        a[0]=1;

        // WSW

        a[1]=a[n-1]=0;

        for(int i=1; i+2<n; ++i) {

            if (s[i]=='o')

                a[i+1]=a[i] ? a[i-1] : !a[i-1];

            else

                a[i+1]=!a[i] ? a[i-1] : !a[i-1];

        }

        ok=true;

        if (s[n-2]=='o') {

            if (a[n-2] and a[n-3]!=a[n-1] or !a[n-2] and a[n-3]==a[n-1])

                ok=false;

        }

        else {

            if (a[n-2] and a[n-3]==a[n-1] or !a[n-2] and a[n-3]!=a[n-1])

                ok=false;

        }

        if (ok) {

            if (s[n-1]=='o') {

                if (a[n-1] and a[n-2]==a[0] or !a[n-1] and a[n-2]!=a[0]) {

                    for(int i=0; i<n; ++i) cout<<(a[i]?'S':'W');

                    cout<<endl;

                    return 0;

                }

            }

            else {

                if (a[n-1] and a[n-2]!=a[0] or !a[n-1] and a[n-2]==a[0]) {

                    for(int i=0; i<n; ++i) cout<<(a[i]?'S':'W');

                    cout<<endl;

                    return 0;

                }

            }

        }

        memset(a, 0, sizeof(a));

        a[0]=0; // W

        // WWS

        a[1]=1, a[n-1]=0;

        for(int i=1; i+2<n; ++i) {

            if (s[i]=='o')

                a[i+1]=a[i] ? a[i-1] : !a[i-1];

            else

                a[i+1]=!a[i] ? a[i-1] : !a[i-1];

        }

        ok=true;

        if (s[n-2]=='o') {

            if (a[n-2] and a[n-3]!=a[n-1] or !a[n-2] and a[n-3]==a[n-1])

                ok=false;

        }

        else {

            if (a[n-2] and a[n-3]==a[n-1] or !a[n-2] and a[n-3]!=a[n-1])

                ok=false;

        }

        if (ok) {

            if (s[n-1]=='o') {

                if (a[n-1] and a[n-2]==a[0] or !a[n-1] and a[n-2]!=a[0]) {

                    for(int i=0; i<n; ++i) cout<<(a[i]?'S':'W');

                    cout<<endl;

                    return 0;

                }

            }

            else {

                if (a[n-1] and a[n-2]!=a[0] or !a[n-1] and a[n-2]==a[0]) {

                    for(int i=0; i<n; ++i) cout<<(a[i]?'S':'W');

                    cout<<endl;

                    return 0;

                }

            }

        }

        memset(a, 0, sizeof(a));

        a[0]=0;

        // SWW

        a[1]=0, a[n-1]=1;

        for(int i=1; i+2<n; ++i) {

            if (s[i]=='o')

                a[i+1]=a[i] ? a[i-1] : !a[i-1];

            else

                a[i+1]=!a[i] ? a[i-1] : !a[i-1];

        }

        ok=true;

        if (s[n-2]=='o') {

            if (a[n-2] and a[n-3]!=a[n-1] or !a[n-2] and a[n-3]==a[n-1])

                ok=false;

        }

        else {

            if (a[n-2] and a[n-3]==a[n-1] or !a[n-2] and a[n-3]!=a[n-1])

                ok=false;

        }

        if (ok) {

            if (s[n-1]=='o') {

                if (a[n-1] and a[n-2]==a[0] or !a[n-1] and a[n-2]!=a[0]) {

                    for(int i=0; i<n; ++i) cout<<(a[i]?'S':'W');

                    cout<<endl;

                    return 0;

                }

            }

            else {

                if (a[n-1] and a[n-2]!=a[0] or !a[n-1] and a[n-2]==a[0]) {

                    for(int i=0; i<n; ++i) cout<<(a[i]?'S':'W');

                    cout<<endl;

                    return 0;

                }

            }

        }

    }

    else {

        memset(a, 0, sizeof(a));

        a[0]=1; // S

        // SSW

        a[1]=0, a[n-1]=1;

        for(int i=1; i+2<n; ++i) {

            if (s[i]=='o')

                a[i+1]=a[i] ? a[i-1] : !a[i-1];

            else

                a[i+1]=!a[i] ? a[i-1] : !a[i-1];

        }

        bool ok=true;

        if (s[n-2]=='o') {

            if (a[n-2] and a[n-3]!=a[n-1] or !a[n-2] and a[n-3]==a[n-1])

                ok=false;

        }

        else {

            if (a[n-2] and a[n-3]==a[n-1] or !a[n-2] and a[n-3]!=a[n-1])

                ok=false;

        }

        if (ok) {

            if (s[n-1]=='o') {

                if (a[n-1] and a[n-2]==a[0] or !a[n-1] and a[n-2]!=a[0]) {

                    for(int i=0; i<n; ++i) cout<<(a[i]?'S':'W');

                    cout<<endl;

                    return 0;

                }

            }

            else {

                if (a[n-1] and a[n-2]!=a[0] or !a[n-1] and a[n-2]==a[0]) {

                    for(int i=0; i<n; ++i) cout<<(a[i]?'S':'W');

                    cout<<endl;

                    return 0;

                }

            }

        }

        memset(a, 0, sizeof(a));

        a[0]=1;

        // WSS

        a[1]=1, a[n-1]=0;

        for(int i=1; i+2<n; ++i) {

            if (s[i]=='o')

                a[i+1]=a[i] ? a[i-1] : !a[i-1];

            else

                a[i+1]=!a[i] ? a[i-1] : !a[i-1];

        }

        ok=true;

        if (s[n-2]=='o') {

            if (a[n-2] and a[n-3]!=a[n-1] or !a[n-2] and a[n-3]==a[n-1])

                ok=false;

        }

        else {

            if (a[n-2] and a[n-3]==a[n-1] or !a[n-2] and a[n-3]!=a[n-1])

                ok=false;

        }

        if (ok) {

            if (s[n-1]=='o') {

                if (a[n-1] and a[n-2]==a[0] or !a[n-1] and a[n-2]!=a[0]) {

                    for(int i=0; i<n; ++i) cout<<(a[i]?'S':'W');

                    cout<<endl;

                    return 0;

                }

            }

            else {

                if (a[n-1] and a[n-2]!=a[0] or !a[n-1] and a[n-2]==a[0]) {

                    for(int i=0; i<n; ++i) cout<<(a[i]?'S':'W');

                    cout<<endl;

                    return 0;

                }

            }

        }

        memset(a, 0, sizeof(a));

        a[0]=0; // W

        // SWS

        a[1]=1, a[n-1]=1;

        for(int i=1; i+2<n; ++i) {

            if (s[i]=='o')

                a[i+1]=a[i] ? a[i-1] : !a[i-1];

            else

                a[i+1]=!a[i] ? a[i-1] : !a[i-1];

        }

        ok=true;

        if (s[n-2]=='o') {

            if (a[n-2] and a[n-3]!=a[n-1] or !a[n-2] and a[n-3]==a[n-1])

                ok=false;

        }

        else {

            if (a[n-2] and a[n-3]==a[n-1] or !a[n-2] and a[n-3]!=a[n-1])

                ok=false;

        }

        if (ok) {

            if (s[n-1]=='o') {

                if (a[n-1] and a[n-2]==a[0] or !a[n-1] and a[n-2]!=a[0]) {

                    for(int i=0; i<n; ++i) cout<<(a[i]?'S':'W');

                    cout<<endl;

                    return 0;

                }

            }

            else {

                if (a[n-1] and a[n-2]!=a[0] or !a[n-1] and a[n-2]==a[0]) {

                    for(int i=0; i<n; ++i) cout<<(a[i]?'S':'W');

                    cout<<endl;

                    return 0;

                }

            }

        }

        memset(a, 0, sizeof(a));

        a[0]=0;

        // WWW

        a[1]=0, a[n-1]=0;

        for(int i=1; i+2<n; ++i) {

            if (s[i]=='o')

                a[i+1]=a[i] ? a[i-1] : !a[i-1];

            else

                a[i+1]=!a[i] ? a[i-1] : !a[i-1];

        }

        ok=true;

        if (s[n-2]=='o') {

            if (a[n-2] and a[n-3]!=a[n-1] or !a[n-2] and a[n-3]==a[n-1])

                ok=false;

        }

        else {

            if (a[n-2] and a[n-3]==a[n-1] or !a[n-2] and a[n-3]!=a[n-1])

                ok=false;

        }

        if (ok) {

            if (s[n-1]=='o') {

                if (a[n-1] and a[n-2]==a[0] or !a[n-1] and a[n-2]!=a[0]) {

                    for(int i=0; i<n; ++i) cout<<(a[i]?'S':'W');

                    cout<<endl;

                    return 0;

                }

            }

            else {

                if (a[n-1] and a[n-2]!=a[0] or !a[n-1] and a[n-2]==a[0]) {

                    for(int i=0; i<n; ++i) cout<<(a[i]?'S':'W');

                    cout<<endl;

                    return 0;

                }

            }

        }

    }

    cout<<-1<<endl;

}
