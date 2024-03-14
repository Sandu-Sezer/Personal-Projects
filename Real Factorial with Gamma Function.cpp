#include <iostream>
#include <cmath>
using namespace std;

long double gamma_function(long double n){
    long double p = 1.0;
    for (int i = 1; i <= 500000; i++){
        p *= ((long double) pow((1 + (long double)(1.0 / i)), n) / (1.0 + (long double) n / i));
    }
    return (1 / n) * p;
}

long double real_factorial(long double n){
    return gamma_function(n + 1);
}

int main(){
    long double n;
    cout << "Introduceti un numar real: ";
    cin >> n;
    cout << endl;

    long double f = real_factorial(n);
    cout << "Factorialul lui " << n << " este: " << f << endl;

    system("pause");
    return 0;
}
