#ifndef RANDOMWALKS_BIASLATTICE_HPP
#define RANDOMWALKS_BIASLATTICE_HPP

#include <cmath>
#include <vector>

#include "random.hpp"
#include "vectorops.hpp"

using namespace std;

class BiasLattice { // 3-space lattice
    int x; // x coordinate
    int y; // y coordinate
    int z; // z coordinate
    int a; // step size
    double p; // bias in +x direction
    vector<vector<int>> path;

public:
    BiasLattice(int x, int y, int z, int a, double p);
    BiasLattice(double p);
    void push();
    void step();
    void walk(int N);
    vector<double> getCenterMass();
    double getRee();
    double getRg();
    void print();
};

BiasLattice::BiasLattice(int x, int y, int z, int a, double p) : x(x), y(y), z(z), a(a), p(p) {
    push();
}

BiasLattice::BiasLattice(double p) : BiasLattice(0, 0, 0, 1, p) { }

void BiasLattice::push() {
    int pos[] = {x, y, z};
    vector<int> v(pos, pos + sizeof(pos) / sizeof(int));
    path.push_back(v);
    //print();
}

void BiasLattice::step() {
    int pad = round((3600 * p) / (5 - 6 * p));

    switch (RandomInt(0, 599 + pad) / 100) {
        case 0:
            x -= a;
            break;
        case 1:
            y += a;
            break;
        case 2:
            y -= a;
            break;
        case 3:
            z += a;
            break;
        case 4:
            z -= a;
            break;
        default:
            x += a;
            break;
    }

    push();
}

void BiasLattice::walk(int N) {
    for (int i = 0; i < N; i++) {
        step();
    }
}

vector<double> BiasLattice::getCenterMass() {
    double cm[3] = {0};

    for (auto i : path) {
        cm[0] += i[0];
        cm[1] += i[1];
        cm[2] += i[2];
    }

    for (int i = 0; i < 3; i++) {
        cm[i] /= path.size();
    }

    vector<double> v(cm, cm + sizeof(cm) / sizeof(int));

    return v;
}

double BiasLattice::getRee() {
    return magnitude(difference(path[path.size() - 1], path[0]));
}

double BiasLattice::getRg() {
    double sum = 0;
    vector<double> cm = getCenterMass();
    for (auto i : path) {
        sum += pow(magnitude(difference(i, cm)),2);
    }
    sum /= path.size();
    return sqrt(sum);
}

void BiasLattice::print() {
    cout << "{" << x << ", " << y << ", " << z << "}," << endl;
}



#endif //RANDOMWALKS_BIASLATTICE_HPP
