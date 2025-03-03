#include <iostream>

#include <stdio.h>

#include <algorithm>

#include <math.h>

#include <vector>

#include <map>

#include <string.h>

#include <set>

#include <unordered_set>

#define mod 1000000007

#define maxn 100050

using namespace std;



int grid[110][110];









void move_cursor(int& i, int& j, int dir){

    if(dir == 1){

        i++;

    }else if(dir == 2){

        j++;

    }else if(dir == 3){

        i--;

    }else{

        j--;

    }

}



void change_dir(int& i, int& j, int& dir, int& r, int& c){

    if(i == r){

        i--;

        j++;

        dir = 2;

    }else if(j == c){

        j--;

        i--;

        dir = 3;

    }else{

        switch (dir) {

            case 1:

                i--;

                j++;

                dir = 2;

                break;

            case 2:

                j--;

                i--;

                dir = 3;

                break;

            case 3:

                i++;

                j--;

                dir = 4;

                break;

            default:

                j++;

                i++;

                dir = 1;

                break;

        }

    }

}



void paint(int& i_cursor, int& j_cursor, int& dir, int color, int r, int c, int& cnt){

    if(cnt == 0){

        return;

    }

    if(i_cursor == r || j_cursor == c || grid[i_cursor][j_cursor] != -1){

        change_dir(i_cursor, j_cursor, dir, r, c);

    }

    grid[i_cursor][j_cursor] = color;

    move_cursor(i_cursor, j_cursor, dir);

    paint(i_cursor, j_cursor, dir, color, r, c, --cnt);

}

int main(){

    int r, c, n;

    scanf("%d %d %d", &r, &c, &n);

    memset(grid, -1, sizeof(grid));

    

    vector<int> a(n);

    for(int i=0; i<n; i++){

        scanf("%d", &a[i]);

    }

    int x_cursor = 0, y_cursor = 0;

    int dir = 1;

    for(int i=0; i<n; i++){

        if(a[i]){

            paint(x_cursor, y_cursor, dir, i+1, r, c, a[i]);

        }

    }

    for(int i=0; i<r; i++){

        printf("%d", grid[i][0]);

        for(int j=1; j<c; j++){

            printf(" %d", grid[i][j]);

        }

        printf("\n");

    }

    return 0;

}


