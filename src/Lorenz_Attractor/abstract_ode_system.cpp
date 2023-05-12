#include "abstract_ode_system.hpp"

template<unsigned int N, typename real_number_type>
Abstract_ODE_System<N, real_number_type>::Abstract_ODE_System(State_Vector<N, real_number_type> initial_values) 
: m_initial_values(initial_values) 
{

}