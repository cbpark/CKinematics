#ifndef SRC_KINEMATICS_H_
#define SRC_KINEMATICS_H_

#include <cmath>

const double PI = 3.14159265358979323846;

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

double pseudoRapidity(const Px& px, const Py& py, const Pz& pz);

struct Eta {
    double value;
    Eta() : value(0.0) {}
    explicit Eta(double v) : value(v) {}
    Eta(const Px& px, const Py& py, const Pz& pz)
        : value(pseudoRapidity(px, py, pz)) {}
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

struct FourMomentum {
    Px px;
    Py py;
    Pz pz;
    Energy e;

    FourMomentum() : px(0.0), py(0.0), pz(0.0), e(0.0) {}
    FourMomentum(const Energy& _e, const Px& _px, const Py& _py, const Pz& _pz)
        : px(_px), py(_py), pz(_pz), e(_e) {}

    double pt() const {
        return std::sqrt(px.value * px.value + py.value * py.value);
    }
    double phi() const { return PI + std::atan2(-py.value, -px.value); }
    double eta() const { return pseudoRapidity(px, py, pz); }
    double mass() const { return invariantMass(e, px, py, pz); }
};

double deltaPhi(const FourMomentum& p1, const FourMomentum& p2);

double deltaR(const FourMomentum& p1, const FourMomentum& p2);

struct ThreeMomentum {
    Px px;
    Py py;
    Pz pz;

    ThreeMomentum() : px(0.0), py(0.0), pz(0.0) {}
    ThreeMomentum(const Px& _px, const Py& _py, const Pz& _pz)
        : px(_px), py(_py), pz(_pz) {}

    double pt() const {
        return std::sqrt(px.value * px.value + py.value * py.value);
    }
    double cosTheta() const {
        double ptot = std::sqrt(px.value * px.value + py.value * py.value +
                                pz.value * pz.value);
        return ptot == 0.0 ? 1.0 : pz.value / ptot;
    }
};

struct TransverseMomentum {
    Px px;
    Py py;

    TransverseMomentum() : px(0.0), py(0.0) {}
    TransverseMomentum(const Px& _px, const Py& _py) : px(_px), py(_py) {}
};

#endif  // SRC_KINEMATICS_H_
