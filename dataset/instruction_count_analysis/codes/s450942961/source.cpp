#include <stdio.h>

int main(){

    int a, b, c, k, y;

    int maior, v[3], soma=0;

    

    scanf("%d %d %d %d", &a, &b, &c, &k);

    

    maior=a;

    v[0]=a;

    v[1]=b;

    v[2]=c;

    

    for(int i=0; i<k; i++){

        soma=0;

        

        for(int j=0; j<3; j++){

            soma+=v[j];

            

            if(v[j]>maior){

                maior=v[j];

                y=j;

            }

        }

        

        v[y]=maior*2;

        soma=soma-maior+maior*2;

       

    }

    

    printf("%d\n", soma);

    return 0;

}
