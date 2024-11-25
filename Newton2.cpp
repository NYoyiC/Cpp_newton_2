#include <iostream>
#include <cmath>
#include <iomanip> // Para formato de salida

using namespace std;

// Constantes de la Ley de Planck
const double h = 6.626e-34;  // Constante de Planck (J·s)
const double c = 3e8;        // Velocidad de la luz (m/s)
const double k_B = 1.38e-23; // Constante de Boltzmann (J/K)
const double T = 3.5e3;       // Temperatura constante (K)

// Función B'(\nu) para encontrar el máximo
double f(double nu) {
    double exp_term = exp(h * nu / (k_B * T));
    double numerator = 6 * h * pow(nu, 2) / pow(c, 2) * (exp_term - 1) - 2 * h * pow(nu, 3) / pow(c, 2) * h / (k_B * T) * exp_term;
    double denominator = pow(exp_term - 1, 2);
    if (denominator <= 0) {
        return NAN; // Retorna NaN si el denominador es cero o negativo
    }
    return numerator / denominator;
}

// Derivada de f(\nu), f''(\nu)
double fp(double nu) {
    double exp_term = exp(h * nu / (k_B * T));
    double numerator1 = 12 * h * nu / pow(c, 2) * (exp_term - 1);
    double numerator2 = 6 * h * pow(nu, 2) / pow(c, 2) * h / (k_B * T) * exp_term;
    double numerator3 = 4 * h * pow(nu, 3) / pow(c, 2) * pow(h / (k_B * T), 2) * exp_term;
    double numerator = numerator1 - numerator2 + numerator3;
    double denominator = pow(exp_term - 1, 3);
    if (denominator <= 0) {
        return NAN; // Retorna NaN si el denominador es cero o negativo
    }
    return numerator / denominator;
}

int main() {
    int n = 0;
    int maxiteraciones = 1000;
    double nu0 = 1e14; // Valor inicial razonable para frecuencia (Hz)
    double nu1;
    
    while (n < maxiteraciones) {
        double fnu0 = f(nu0);
        double fpnu0 = fp(nu0);
        
        if (isnan(fnu0) || isnan(fpnu0)) {
            cout << "Se produjo un valor NaN en la iteracion " << n << ". Verifica los calculos." << endl;
            break;
        }
        
        nu1 = nu0 - fnu0 / fpnu0;
        
        // Si la diferencia entre iteraciones es pequeña, consideramos que hemos convergido
        if (abs(nu1 - nu0) < 1e-6) {
            break;
        }
        
        // Evitar valores negativos
        if (nu1 < 0) {
            cout << "Se alcanzo un valor negativo en la iteracion " << n << ". nu = " << nu1 << endl;
            break;
        }
        
        nu0 = nu1;
        cout << "Iteracion " << n << ": nu = " << nu1 << endl;
        n++;
    }

    cout << "Frecuencia encontrada: " << nu1 << " Hz" << endl;

    return 0;
}
