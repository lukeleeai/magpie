#include<iostream>



int main() {

    int X, Y;

    scanf("%d%d", &X, &Y);

    puts(Y >= X * 2 && Y <= X * 4 && Y % 2 == 0 ? "Yes" : "No");

}