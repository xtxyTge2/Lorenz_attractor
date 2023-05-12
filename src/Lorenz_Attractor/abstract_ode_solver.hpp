#pragma once

#include "abstract_ode_system.hpp"
#include "State_Vector.hpp"

#include <vector>

template<unsigned int N, typename real_number_type>
class Abstract_ODE_Solver {
public:
	Abstract_ODE_Solver(double start_time, double end_time, double time_step_size);

	// @Todo: parametrize the solution_trajectory, so that we can use something like std::vector<ODE_Solution<ode_dimension>> instead.
	virtual bool solve(const Abstract_ODE_System<N, real_number_type>& ode_system, std::vector<State_Vector<N, real_number_type>>& solution_trajectory) = 0;

protected:
	double m_start_time; 
	double m_end_time;
	double m_time_step_size;
};

template<unsigned int N, typename real_number_type>
Abstract_ODE_Solver<N, real_number_type>::Abstract_ODE_Solver(double start_time, double end_time, double time_step_size)
: m_start_time(start_time),
  m_end_time(end_time),
  m_time_step_size(time_step_size)
{
	
}