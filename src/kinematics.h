#ifndef SRC_KINEMATICS_H_
#define SRC_KINEMATICS_H_

#include <cmath>

struct Px {
    double value;
    Px() : value(0.0) {}
    explicit Px(double v) : value(v) {}
};

struct Py {
    double value;
    Py() : value(0.0) {}
    explicit Py(double v) : value(v) {}
};

struct Pz {
    double value;
    Pz() : value(0.0) {}
    explicit Pz(double v) : value(v) {}
};

struct Energy {
    double value;
    Energy() : value(0.0) {}
    explicit Energy(double v) : value(v) {}
};

struct Pt {
    double value;
    Pt() : value(0.0) {}
    explicit Pt(double v) : value(v) {}
    Pt(const Px& px, const Py& py) {
        value = std::sqrt(px.value * px.value + py.value * py.value);
    }
};

double pseudoRapidity(double x, double y, double z);

struct Eta {
    double value;
    Eta() : value(0.0) {}
    explicit Eta(double v) : value(v) {}
    Eta(const Px& px, const Py& py, const Pz& pz)
        : value(pseudoRapidity(px.value, py.value, pz.value)) {}
};

struct Phi {
    double value;
    Phi() : value(0.0) {}
    explicit Phi(double v) : value(v) {}
    Phi(const Px& px, const Py& py) : value(std::atan2(py.value, px.value)) {}
};

struct Mass {
    double value;
    Mass() : value(0.0) {}
    explicit Mass(double v) : value(v) {}
};

double invariantMass(const Energy& e, const Px& px, const Py& py, const Pz& pz);

#endif  // SRC_KINEMATICS_H_
