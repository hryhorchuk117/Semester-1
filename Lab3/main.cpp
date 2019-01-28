#include <iostream>
#include <vector>
#include <map>

#include "matrix.h"

using namespace std;

void Read(int& n, map<double, double>& point) {
    double x, y;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        point[x] = y;
    }
}

double In_Power(double a, int n) {
    double k = a;
    for (int i = 2; i <= n; ++i) {
        a *= k;
    }
    return a;
}

vector<double> Determinants_calculation(double val[1000], map<double, double> point, int n) {
    double *val_2 = new double[n*n];
    for (int i = 0; i < n*n; ++i) {
        val_2[i] = val[i];
    }
    double *val_y = new double[n];
    int j = 0;
    for (auto item : point) {
        val_y[j] = item.second;
        ++j;
    }
    vector<double> determinants;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            val_2[n*j + i] = val_y[j];
        }
        matrix mat;
        mat.set(n, n, val_2);
        determinants.push_back(mat.det());
        for (int i = 0; i < n*n; ++i) {
            val_2[i] = val[i];
        }
    }
    return determinants;
}

void Print_the_first_element(const vector<double>& coefficients, int n, bool& flag_2, bool& flag) {
    cout << "f(x)= ";
    if (coefficients[0] != 0) {
        cout << coefficients[0];
        flag = true;
        flag_2 = true;
    }
}

void Print_the_second_element(const vector<double>& coefficients, int n, bool& flag_2, bool flag) {
    if (coefficients[1] != 0 && !flag && coefficients[1] == 1) {
        cout << "x";
        flag_2 = true;
    }
    else if (coefficients[1] != 0 && !flag) {
        flag_2 = true;
        cout << coefficients[1] << "x";
    }
    else if (coefficients[1] != 0 && flag && coefficients[1] == 1) {
        cout << " + " << "x";
        flag_2 = true;
    }
    else if (coefficients[1] == 0) {

    }
    else {
        cout << " + " << coefficients[1] << "x";
        flag_2 = true;
    }
}

void Print_if_nothing (bool flag_2) {
    if (!flag_2) {
        cout << "0";
    }
}

void Print_cycle(const vector<double>& coefficients, int n, bool& flag_2){
    bool flag_3 = flag_2;
    for (int i = 2; i < n; ++i) {
        if (flag_3 && coefficients[i] != 0) {
            cout << " + ";
            flag_3 = false;
        }
        if (coefficients[i] != 0 && coefficients[i] != 1 && i != n - 1) {

            cout << coefficients[i] << "x^" << i << " + ";
            flag_2 = true;
        }
        else if (i == n - 1 && coefficients[i] != 0 && coefficients[i] != 1) {
            cout << coefficients[i] << "x^" << i;
            flag_2 = true;
        }
        else if (i == n - 1 && coefficients[i] == 1) {
            cout << "x^" << i;
        }
        else if (coefficients[i] == 1) {
            cout << " + " << "x^" << i;
        }
    }
}

void Print(const vector<double>& coefficients, int n) {
    bool flag = false;
    bool flag_2 = false;
    Print_the_first_element(coefficients, n, flag_2, flag);
    Print_the_second_element(coefficients, n, flag_2, flag);
    Print_cycle(coefficients, n, flag_2);
    Print_if_nothing(flag_2);
    cout << endl;
}

vector<double> Coefficients_calculation(vector<double> determinants, double det, int n) {
    vector <double> coefficients;
    for (int i = 0; i < n; ++i) {
        coefficients.push_back(determinants[i] / det);
    }
    return coefficients;
}

int main()
{
    int n;
    double x, y;
    map<double, double> point;
    Read(n, point);

    if (n == 1) {
        cout << "f(x)= " << point[x] << endl;
        system("pause");
        return 0;
    }

    double *val = new double[n*n];
    int j = 0;
    double a = 1;
    vector<matrix> matrixes;
    for (auto item : point) {
        a = 1;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                val[j] = 1;
            }
            else {
                a *= item.first;
                val[j] = a;
            }
            ++j;
        }
    }

    matrix mat;
    mat.set(n, n, val);
    double det = mat.det();

    vector<double> determinants = Determinants_calculation(val, point, n);
    vector<double> coefficients = Coefficients_calculation(determinants, det, n);
    Print(coefficients, n);
    return 0;
}