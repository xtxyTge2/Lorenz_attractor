#pragma once

#include "State_Vector.hpp"

template<unsigned int N, typename real_number_type>
class Abstract_ODE_System {
public:
	Abstract_ODE_System() = default;

	Abstract_ODE_System(State_Vector<N, real_number_type> initial_values);

	virtual void evaluate(State_Vector<N, real_number_type>& dydt, State_Vector<N, real_number_type> values, double t)  const = 0;

// data
	State_Vector<N, real_number_type> m_initial_values;
};