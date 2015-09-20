#include "kinematics.h"

double pseudoRapidity(const double& x, const double& y, const double& z) {
    double ptot = std::sqrt(x * x + y * y + z * z);
    double cos_theta = ptot == 0.0 ? 1.0 : z / ptot;
    if (cos_theta * cos_theta < 1) {
        return -0.5 * std::log((1.0 - cos_theta) / (1.0 + cos_theta));
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
