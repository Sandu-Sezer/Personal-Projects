#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef struct Vector {
    double x1;
    double x2;
    double x3;
} Vector;

void citeste_vector(Vector* p) {
    cin >> p -> x1;
    cin >> p -> x2;
    cin >> p -> x3;
    return;
}

double produs_scalar(Vector v1, Vector v2){
    double produs = v1.x1 * v2.x1 + v1.x2 * v2.x2 + v1.x3 * v2.x3;
    return produs;
}

double calculeaza_norma(Vector v){
    double norma = sqrt(v.x1 * v.x1 + v.x2 * v.x2 + v.x3 * v.x3);
    return norma;
}

vector<Vector> gram_schmidt(const vector<Vector>& A, int n) {
    vector<Vector> F(n); // Vectorii ortogonali
    vector<Vector> E(n); // Vectorii ortonormati

    F[0] = A[0];

    for (int j = 1; j < n; j++){
        double sum_x1 = 0.0;
        double sum_x2 = 0.0;
        double sum_x3 = 0.0;

        for (int i = 0; i < j; i++){
            sum_x1 += (produs_scalar(A[j], F[i]) / produs_scalar(F[i], F[i])) * F[i].x1;
            sum_x2 += (produs_scalar(A[j], F[i]) / produs_scalar(F[i], F[i])) * F[i].x2;
            sum_x3 += (produs_scalar(A[j], F[i]) / produs_scalar(F[i], F[i])) * F[i].x3;
        }

        F[j].x1 = A[j].x1 - sum_x1;
        F[j].x2 = A[j].x2 - sum_x2;
        F[j].x3 = A[j].x3 - sum_x3;
    }

    for (int k = 0; k < n; k++){
        double norma = calculeaza_norma(F[k]);
        E[k].x1 = F[k].x1 / norma;
        E[k].x2 = F[k].x2 / norma;
        E[k].x3 = F[k].x3 / norma;
    }

    return E;
}

int main() {
    int n;

    cout << "Introduceti numarul de vectori: ";
    cin >> n;
    cout << endl;

    vector<Vector> vectoriInitiali(n);

    cout << "Introduceti vectorii:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Intorduceti componentele vectorilor (x1, x2, x3): ";
        citeste_vector(&vectoriInitiali[i]);
    }

    vector<Vector> rezultat = gram_schmidt(vectoriInitiali, n);
    cout << endl;
 
    cout << "Vectori ortonormati:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "(" << rezultat[i].x1 << ", " << rezultat[i].x2 << ", " << rezultat[i].x3 << ")" << endl;
    }

    system("pause");
    return 0;
}
