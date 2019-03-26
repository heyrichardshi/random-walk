#ifndef RANDOMWALKS_LATTICE_HPP
#define RANDOMWALKS_LATTICE_HPP

#include <cmath>
#include <vector>

#include "random.hpp"
#include "vectorops.hpp"

using namespace std;

class Lattice { // 3-space lattice
    int x; // x coordinate
    int y; // y coordinate
    int z; // z coordinate
    int a; // step size
    vector<vector<int>> path;

public:
    Lattice(int x, int y, int z, int a);
    Lattice();
    void push();
    void step();
    void walk(int N);
    vector<double> getCenterMass();
    double getRee();
    double getRg();
    void print();
};

Lattice::Lattice(int x, int y, int z, int a) : x(x), y(y), z(z), a(a) {
    push();
}

Lattice::Lattice() : Lattice(0, 0, 0, 1) { }

void Lattice::push() {
    int pos[] = {x, y, z};
    vector<int> v(pos, pos + sizeof(pos) / sizeof(int));
    path.push_back(v);
    //print();
}

void Lattice::step() {
    switch (RandomInt(1, 6)) {
        case 1:
            x += a;
            break;
        case 2:
            x -= a;
            break;
        case 3:
            y += a;
            break;
        case 4:
            y -= a;
            break;
        case 5:
            z += a;
            break;
        case 6:
            z -= a;
            break;
        default:
            cout << "YA DONE FUCKED UP" << endl;
    }
    push();
}

void Lattice::walk(int N) {
    for (int i = 0; i < N; i++) {
        step();
    }
}

vector<double> Lattice::getCenterMass() {
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

double Lattice::getRee() {
    return magnitude(difference(path[path.size() - 1], path[0]));
}

double Lattice::getRg() {
    double sum = 0;
    vector<double> cm = getCenterMass();
    for (auto i : path) {
        sum += pow(magnitude(difference(i, cm)),2);
    }
    sum /= path.size();
    return sqrt(sum);
}

void Lattice::print() {
    cout << "{" << x << ", " << y << ", " << z << "}," << endl;
}


#endif //RANDOMWALKS_LATTICE_HPP
