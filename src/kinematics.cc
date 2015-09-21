#include "kinematics.h"
#include <cmath>

double pseudoRapidity(double x, double y, double z) {
    double ptot = std::sqrt(x * x + y * y + z * z);
    double costheta = ptot == 0.0 ? 1.0 : z / ptot;
    if (costheta * costheta < 1) {
        return -0.5 * std::log((1.0 - costheta) / (1.0 + costheta));
    }
    if (z == 0) {
        return 0.0;
    } else if (z > 0) {
        return 10.0e+10;
    } else {
        return -10.0e+10;
    }
}

double invariantMass(const Energy& e, const Px& px, const Py& py,
                     const Pz& pz) {
    return std::sqrt(e.value * e.value - px.value * px.value -
                     py.value * py.value - pz.value * pz.value);
}
