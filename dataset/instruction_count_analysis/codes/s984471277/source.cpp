#include "stdc++.h"

#include <algorithm>

using namespace std;

int main() {

int N; 

cin >> N; 

int X[110], Y[110], H[110]; 

for(int i = 0; i < N; i++){

cin >> X[i] >> Y[i] >> H[i]; 

}



int minheight = H[0]; 

for(int i = 0; i < N; i++){

minheight = min(minheight, H[i]); 

}



int A[110][110][110] = {}, M[110][110] = {}, m[110][110] = {}; 



for(int x = 0; x <= 100; x++){

  for(int y = 0; y <= 100; y++){

    for(int i = 0; i < N; i++){

A[x][y][i] = H[i] + abs(x - X[i]) + abs(y - Y[i]); 

}

}

}



int ansx = 0, ansy = 0, ansh = 0; 



if(minheight > 0){

for(int x = 0; x <= 100; x++){

  for(int y = 0; y <= 100; y++){

M[x][y] = A[x][y][0], m[x][y] = A[x][y][0]; 

}

}



for(int x = 0; x <= 100; x++){

  for(int y = 0; y <= 100; y++){

    for(int i = 1; i < N; i++){

M[x][y] = max(M[x][y], A[x][y][i]); 

m[x][y] = min(m[x][y], A[x][y][i]); 

}

}

}

for(int x = 0; x <= 100; x++){

  for(int y = 0; y <= 100; y++){

    if(M[x][y] == m[x][y]){

ansx = x, ansy = y, ansh = M[x][y]; 

}

}

}

cout  << ansx << " " << ansy << " " << ansh << endl; 

}



else if(minheight == 0){

int ansx = 0, ansy = 0, ansh = 0; 

for(int x = 0; x <= 100; x++){

for(int y = 0; y <= 100; y++){

for(int h = 1; h <= 200; h++){

for(int i = 0; i < N; i++){

if(max(h - abs(x-X[i]) - abs(y-Y[i]), 0) != H[i]){

break; 

}

if(i == N-1 && max(h - abs(x-X[i]) - abs(y-Y[i]), 0) == H[i]){

ansx = x, ansy = y, ansh = h; 

}

}

}

}

}



cout  << ansx << " " << ansy << " " << ansh << endl; 

}

}