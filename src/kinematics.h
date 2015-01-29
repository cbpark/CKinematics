#ifndef SRC_KINEMATICS_H_
#define SRC_KINEMATICS_H_

#include <cmath>

struct Px {
    double value;
    explicit Px(double v) : value(v) { }
};

struct Py {
    double value;
    explicit Py(double v) : value(v) { }
};

struct Pz {
    double value;
    explicit Pz(double v) : value(v) { }
};

struct Energy {
    double value;
    explicit Energy(double v) : value(v) { }
};

struct Pt {
    double value;
    explicit Pt(double v) : value(v) { }
    Pt(const Px& px, const Py& py)  {
        value = std::sqrt(px.value * px.value + py.value * py.value);
    }
};

double PseudoRapidity(const double& x, const double& y, const double& z);

struct Eta {
    double value;
    explicit Eta(double v) : value(v) { }
    Eta(const Px& px, const Py& py, const Pz& pz)
        : value(PseudoRapidity(px.value, py.value, pz.value)) { }
};

struct Phi {
    double value;
    explicit Phi(double v) : value(v) { }
    Phi(const Px& px, const Py& py) : value(std::atan2(py.value, px.value)) { }
};

struct Mass {
    double value;
    explicit Mass(double v) : value(v) { }
};

double InvariantMass(const Energy& e, const Px& px, const Py& py, const Pz& pz);

#endif  // SRC_KINEMATICS_H_
