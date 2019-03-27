#include <iostream>
#include <fstream>
#include <cmath>

#include "lattice.hpp"
#include "offlattice.hpp"
#include "biaslattice.hpp"
#include "walk.hpp"

using namespace std;

int main () {
    RandomInitialise(1802,9373);

    int N[] = {10, 20, 30, 60, 120};
    cout << "Cubic Lattice:" << endl;
    for (int j = 0; j < 5; j++) {
        double rg = 0;
        double ree = 0;
        for (int i = 0; i < N[j] * N[j]; i++) {
            Lattice lattice;
            lattice.walk(N[j]);
            ree += pow(lattice.getRee(), 2);
            rg += pow(lattice.getRg(), 2);
        }
        ree /= (N[j] * N[j]);
        ree = sqrt(ree);
        rg /= (N[j] * N[j]);
        rg = sqrt(rg);
        cout << N[j] << " " << ree << " " << rg << endl;
    }
    cout << "\nOff-Lattice:" << endl;
    for (int j = 0; j < 5; j++) {
        double rg = 0;
        double ree = 0;
        for (int i = 0; i < N[j] * N[j]; i++) {
            OffLattice lattice;
            lattice.walk(N[j]);
            ree += pow(lattice.getRee(), 2);
            rg += pow(lattice.getRg(), 2);
        }
        ree /= (N[j] * N[j]);
        ree = sqrt(ree);
        rg /= (N[j] * N[j]);
        rg = sqrt(rg);
        cout << N[j] << " " << ree << " " << rg << endl;
    }
    cout << "\nCubic Lattice with +x Bias p = 0.1:" << endl;
    for (int j = 0; j < 5; j++) {
        double rg = 0;
        double ree = 0;
        for (int i = 0; i < N[j] * N[j]; i++) {
            BiasLattice lattice(0.1);
            lattice.walk(N[j]);
            ree += pow(lattice.getRee(), 2);
            rg += pow(lattice.getRg(), 2);
        }
        ree /= (N[j] * N[j]);
        ree = sqrt(ree);
        rg /= (N[j] * N[j]);
        rg = sqrt(rg);
        cout << N[j] << " " << ree << " " << rg << endl;
    }
    cout << "\nCubic Lattice with +x Bias p = 0.2:" << endl;
    for (int j = 0; j < 5; j++) {
        double rg = 0;
        double ree = 0;
        for (int i = 0; i < N[j] * N[j]; i++) {
            BiasLattice lattice(0.2);
            lattice.walk(N[j]);
            ree += pow(lattice.getRee(), 2);
            rg += pow(lattice.getRg(), 2);
        }
        ree /= (N[j] * N[j]);
        ree = sqrt(ree);
        rg /= (N[j] * N[j]);
        rg = sqrt(rg);
        cout << N[j] << " " << ree << " " << rg << endl;
    }
    cout << "\nCubic Lattice with +x Bias p = 0.3:" << endl;
    for (int j = 0; j < 5; j++) {
        double rg = 0;
        double ree = 0;
        for (int i = 0; i < N[j] * N[j]; i++) {
            BiasLattice lattice(0.3);
            lattice.walk(N[j]);
            ree += pow(lattice.getRee(), 2);
            rg += pow(lattice.getRg(), 2);
        }
        ree /= (N[j] * N[j]);
        ree = sqrt(ree);
        rg /= (N[j] * N[j]);
        rg = sqrt(rg);
        cout << N[j] << " " << ree << " " << rg << endl;
    }
}