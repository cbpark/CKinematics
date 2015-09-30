#include "kinematics.h"
#include <cmath>

double pseudoRapidity(const Px& px, const Py& py, const Pz& pz) {
    ThreeMomentum p(px, py, pz);
    double costheta = p.cosTheta();
    if (costheta * costheta < 1.0)
        return -0.5 * std::log((1.0 - costheta) / (1.0 + costheta));

    if (pz.value == 0.0)
        return 0.0;
    else if (pz.value > 0.0)
        return 10.0e+10;
    else
        return -10.0e+10;
}

double invariantMass(const Energy& e, const Px& px, const Py& py,
                     const Pz& pz) {
    return std::sqrt(e.value * e.value - px.value * px.value -
                     py.value * py.value - pz.value * pz.value);
}

double mPi2Pi(double x) {
    const double TWOPI = 2.0 * PI;
    while (x >= PI) x -= TWOPI;
    while (x < -PI) x += TWOPI;
    return x;
}

double deltaPhi(const FourMomentum& p1, const FourMomentum& p2) {
    return mPi2Pi(p1.phi() - p2.phi());
}

double deltaR(const FourMomentum& p1, const FourMomentum& p2) {
    double deta = p1.eta() - p2.eta();
    double dphi = deltaPhi(p1, p2);
    return std::sqrt(deta * deta + dphi * dphi);
}
