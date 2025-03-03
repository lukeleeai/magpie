#include <iostream>

#include <cstdio>

#include <algorithm>



int a[5], b[5], c[5][5];

using namespace std;

int main(){

	for(int i = 0; i < 3; i++)

		for(int j = 0; j < 3; j++)

			cin>>c[i][j];

	for(int a1 = 0; a1 < 101; a1++)

		for(int a2 = 0; a2 < 101; a2++)

			for(int a3 = 0; a3 < 101; a3++){

        int b1 = c[0][0] - a1;

        int b2 = c[0][1] - a1;

        int b3 = c[0][2] - a1;

 

        a[0] = a1;

        a[1] = a2;

        a[2] = a3;

        b[0] = b1;

        b[1] = b2;

        b[2] = b3;

 

        bool flag = true;

    	for(int i = 0; i < 3; i++)    	

			for(int j = 0; j < 3; j++)

				if (a[i] + b[j] != c[i][j])

					flag = false;

        if (flag) {

            printf("Yes\n");

            return 0;

        }

    }

 

    printf("No\n");

    return 0;

}

	