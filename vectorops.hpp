#ifndef RANDOMWALKS_VECTOROPS_HPP
#define RANDOMWALKS_VECTOROPS_HPP

#include <cmath>
#include <vector>

using namespace std;

double magnitude(vector<int> v) {
    return sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
}

double magnitude(vector<double> v) {
    return sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
}

vector<int> difference(vector<int> a, vector<int> b) {
    int c[3] = {0};

    c[0] = a[0] - b[0];
    c[1] = a[1] - b[1];
    c[2] = a[2] - b[2];

    vector<int> v(c, c + sizeof(c) / sizeof(double));

    return v;
}

vector<double> difference(vector<int> a, vector<double> b) {
    double c[3] = {0};

    c[0] = a[0] - b[0];
    c[1] = a[1] - b[1];
    c[2] = a[2] - b[2];

    vector<double> v(c, c + sizeof(c) / sizeof(double));

    return v;
}

vector<double> difference(vector<double> a, vector<double> b) {
    double c[3] = {0};

    c[0] = a[0] - b[0];
    c[1] = a[1] - b[1];
    c[2] = a[2] - b[2];

    vector<double> v(c, c + sizeof(c) / sizeof(double));

    return v;
}

double rms(vector<double> v) {
    double total = 0;
    for (auto i : v) {
        total += i * i;
    }
    total = sqrt(total / v.size());
    return total;
}

#endif //RANDOMWALKS_VECTOROPS_HPP
