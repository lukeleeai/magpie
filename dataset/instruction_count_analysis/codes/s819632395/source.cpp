#include <iostream>



using namespace std;



int main(void)

{

    int a, b; cin >> a >> b;



    int mais, menos, multiplicacao;



    mais = a + b;

    menos = a - b;

    multiplicacao = a * b;



    if(mais > menos and mais > multiplicacao)

        cout << mais << endl;

    else if (menos > mais and menos > multiplicacao)

        cout << menos << endl;

    else if (multiplicacao > mais and multiplicacao > menos)

        cout << multiplicacao << endl;



    else

        cout << mais << endl;

    

    return 0;

}