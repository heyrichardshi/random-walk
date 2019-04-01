#ifndef RANDOM_WALK_WALK_HPP
#define RANDOM_WALK_WALK_HPP

#include <cmath>
#include <vector>

#include "random.hpp"
#include "vectorops.hpp"

using namespace std;

const double PI = 3.141592653589793238463;

class Walk {    // 3-space
    double _x;   // _x coordinate
    double _y;   // _y coordinate
    double _z;   // _z coordinate
    double _a;   // step size
    vector<vector<double>> path;
    bool _lattice;

public:
    Walk(double x, double y, double z, double a, bool lattice);
    Walk(double x, double y, double z, double a);
    Walk(bool lattice);
    Walk();
    void push();
    void step();
    void walk(int N);
    vector<double> getCenterMass();
    double getRee();
    double getRg();
    void print();
};

Walk::Walk(double x, double y, double z, double a, bool lattice) : _x(x), _y(y), _z(z), _a(a), _lattice(lattice) {
    push();
}

Walk::Walk(double x, double y, double z, double a) : Walk(x, y, z, a, false) {}

Walk::Walk(bool lattice) : Walk(0, 0, 0, 1, lattice) {}

Walk::Walk() : Walk(0, 0, 0, 1, false) {}

void Walk::push() {
    double pos[] = {_x, _y, _z};
    vector<double> v(pos, pos + sizeof(pos) / sizeof(double));
    path.push_back(v);
}

void Walk::step() {
    if (_lattice) {
        switch (RandomInt(1, 6)) {
            case 1:
                _x += a;
                break;
            case 2:
                _x -= a;
                break;
            case 3:
                _y += a;
                break;
            case 4:
                _y -= a;
                break;
            case 5:
                _z += a;
                break;
            case 6:
                _z -= a;
        }
    }
    else {
        double theta = RandomDouble(0, 2 * PI); // azimuthal angle
        double phi = RandomDouble(0, PI); // polar angle

        _x += _a * cos(theta) * sin(phi);
        _y += _a * sin(theta) * sin(phi);
        _z += _a * cos(phi);
    }

    push();
}

void Walk::walk(int N) {
    for (int i = 0; i < N; i++) {
        step();
    }
}

vector<double> Walk::getCenterMass() {
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

double Walk::getRee() {
    return magnitude(difference(path[path.size() - 1], path[0]));
}

double Walk::getRg() {
    double sum = 0;
    vector<double> cm = getCenterMass();
    for (auto i : path) {
        sum += pow(magnitude(difference(i, cm)),2);
    }
    sum /= path.size();
    return sqrt(sum);
}

void Walk::print() {
    cout << "{" << _x << ", " << _y << ", " << _z << "}," << endl;
}

#endif //RANDOM_WALK_WALK_HPP
