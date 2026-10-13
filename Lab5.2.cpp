// Лабораторна робота № 5.2

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void S(const double x, const double eps, int& n, double& s);
void A(const double x, const int n, double& a);

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;
    const double PI = acos(-1.0);

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    if (xp <= 1 || dx <= 0)
    {
        cout << "Error: x > 1 and dx > 0 are required" << endl;
        return 1;
    }

    cout << fixed;
    cout << "Table of values of arctg(x)" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "| " << setw(7) << "x"
        << " | " << setw(10) << "arctg(x)"
        << " | " << setw(10) << "S"
        << " | " << setw(5) << "n" << " |" << endl;
    cout << "---------------------------------------------" << endl;

    x = xp;
    while (x <= xk + 1e-9)
    {
        S(x, eps, n, s);

        cout << "| " << setw(7) << setprecision(2) << x
            << " | " << setw(10) << setprecision(5) << atan(x)
            << " | " << setw(10) << setprecision(5) << PI / 2 + s
            << " | " << setw(5) << n << " |" << endl;
        x += dx;
    }
    cout << "---------------------------------------------" << endl;

    return 0;
}

// сума ряду (без доданка pi/2) з точністю eps та кількість доданків n
void S(const double x, const double eps, int& n, double& s)
{
    n = 0;
    double a = -1 / x;      // перший доданок (n = 0)
    s = a;
    do {
        n++;
        A(x, n, a);
        s += a;
    } while (fabs(a) >= eps);
}

// наступний доданок за попереднім: a(n) = a(n-1) * R
void A(const double x, const int n, double& a)
{
    double R = -(2. * n - 1) / ((2. * n + 1) * x * x);
    a *= R;
}
