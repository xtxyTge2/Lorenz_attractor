#include "lorenz_attractor_system.hpp"

Lorenz_Attractor_System::Lorenz_Attractor_System(double sigma, double rho, double beta)
: m_sigma(sigma),
  m_rho(rho),
  m_beta(beta)
{

}

void Lorenz_Attractor_System::evaluate(State_Vector<3, double>& dydt, State_Vector<3, double> value, double t) const {
	// t is unused, the system does not depend on the time.

	// Reference: https://en.wikipedia.org/wiki/Lorenz_system

	double x = value[0];
	double y = value[1];
	double z = value[2];

	dydt[0] = m_sigma * (y - x);
	dydt[1] = x * (m_rho - z) - y;
	dydt[2] = x * y - m_beta * z;
}