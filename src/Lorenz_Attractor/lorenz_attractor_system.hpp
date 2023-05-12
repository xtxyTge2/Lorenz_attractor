#pragma once

#include "abstract_ode_system.hpp"
#include "State_Vector.hpp"

class Lorenz_Attractor_System : public Abstract_ODE_System<3, double> {
public:
	Lorenz_Attractor_System(double sigma, double rho, double beta);

	void evaluate(State_Vector<3, double>& dydt, State_Vector<3, double> y, double t) const override;
private:
	double m_sigma;
	double m_rho;
	double m_beta; 
};