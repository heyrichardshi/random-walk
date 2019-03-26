#ifndef RANDOMWALKS_OFFLATTICE_HPP
#define RANDOMWALKS_OFFLATTICE_HPP

#include <cmath>
#include <vector>

#include "random.hpp"
#include "vectorops.hpp"

using namespace std;

const double PI = 3.141592653589793238463;

class OffLattice { // 3-space lattice
    double x; // x coordinate
    double y; // y coordinate
    double z; // z coordinate
    double a; // step size
    vector<vector<double>> path;

public:
    OffLattice(double x, double y, double z, double a);
    OffLattice();
    void push();
    void step();
    void walk(int N);
    vector<double> getCenterMass();
    double getRee();
    double getRg();
    void print();
};

OffLattice::OffLattice(double x, double y, double z, double a) : x(x), y(y), z(z), a(a) {
    push();
}

OffLattice::OffLattice() : OffLattice(0, 0, 0, 1) { }

void OffLattice::push() {
    double pos[] = {x, y, z};
    vector<double> v(pos, pos + sizeof(pos) / sizeof(double));
    path.push_back(v);
}

void OffLattice::step() {
    double theta = RandomDouble(0, 2*PI); // azimuthal angle
    double phi = RandomDouble(0, PI); // polar angle

    x += a * cos(theta) * sin(phi);
    y += a * sin(theta) * sin(phi);
    z += a * cos(phi);

    push();
}

void OffLattice::walk(int N) {
    for (int i = 0; i < N; i++) {
        step();
    }
}

vector<double> OffLattice::getCenterMass() {
    double cm[3] = {0};

    for (auto i : path) {
        cm[0] += i[0];
        cm[1] += i[1];
        cm[2] += i[2];
    }

    for (int i = 0; i < 3; i++) {
        cm[i] /= path.size();
    }

    vector<double> v(cm, cm + sizeof(cm) / sizeof(double));

    return v;
}

double OffLattice::getRee() {
    return magnitude(difference(path[path.size() - 1], path[0]));
}

double OffLattice::getRg() {
    double sum = 0;
    vector<double> cm = getCenterMass();
    for (auto i : path) {
        sum += pow(magnitude(difference(i, cm)),2);
    }
    sum /= path.size();
    return sqrt(sum);
}

void OffLattice::print() {
    cout << "{" << x << ", " << y << ", " << z << "}," << endl;
}

#endif //RANDOMWALKS_OFFLATTICE_HPP
