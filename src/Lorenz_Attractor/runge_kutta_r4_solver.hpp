#pragma once

#include "abstract_ode_solver.hpp"

template<unsigned int N, typename real_number_type>
class Runge_Kutta_R4_ODE_Solver : public Abstract_ODE_Solver<N, real_number_type> {
public:
	Runge_Kutta_R4_ODE_Solver(double start_time, double end_time, double time_step_size);
	
	bool solve(const Abstract_ODE_System<N, real_number_type>& ode_system, std::vector<State_Vector<N, real_number_type>>& solution_trajectory) override;
};


template<unsigned int N, typename real_number_type>
Runge_Kutta_R4_ODE_Solver<N, real_number_type>::Runge_Kutta_R4_ODE_Solver(double start_time, double end_time, double time_step_size)
: Abstract_ODE_Solver<N, real_number_type>(start_time, end_time, time_step_size)
{
		
}

template<unsigned int N, typename real_number_type>
bool Runge_Kutta_R4_ODE_Solver<N, real_number_type>::solve(const Abstract_ODE_System<N, real_number_type>& ode_system, std::vector<State_Vector<N, real_number_type>>& solution_trajectory) {
	const int number_of_time_steps = static_cast<int>(std::round((m_end_time - m_start_time) / m_time_step_size));
	solution_trajectory.reserve(number_of_time_steps);

	State_Vector<N, real_number_type> k1, k2, k3, k4; 

	solution_trajectory.push_back(ode_system.m_initial_values);
	State_Vector<N, real_number_type> y = ode_system.m_initial_values;

	double t = m_start_time;
	double dt = m_time_step_size;
	for (int i = 0; i < number_of_time_steps; i++) {
		ode_system.evaluate(k1, y, t); // saves result in k1
		k1 *= dt;

		ode_system.evaluate(k2, y + k1 / 2.0, t + dt / 2.0); // saves result in k2
		k2 *= dt;

		ode_system.evaluate(k3, y + k2 / 2.0, t + dt / 2.0); // saves result in k3
		k3 *= dt;

		ode_system.evaluate(k4, y + k3, t + dt); // saves result in k4
		k4 *= dt; 
		
		y += (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
		solution_trajectory.push_back(y);

		t += m_time_step_size;
	}

	return true;
}