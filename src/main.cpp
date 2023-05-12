#include <SFML/Graphics.hpp>

#include <chrono>
#include <iostream>

#include "Lorenz_Attractor/State_Vector.hpp"
#include "Lorenz_Attractor/lorenz_attractor_system.hpp"
#include "Lorenz_Attractor/runge_kutta_r4_solver.hpp"

int main(int argc, char** argv) {
	
	/*
	sf::VideoMode video_mode = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(video_mode, "Lorentz-Attractor");
	

	double dt = 0.0f;
	sf::Clock timer;
	int iteration = 0;
	bool simulate_physics = true;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			// toggle physics simulation with enter/space.
			if(event.type == sf::Event::KeyPressed) {
				if(event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::Space) {
					simulate_physics = !simulate_physics;
					dt = 0.000001f; // reset dt and set it to a small value, so we dont get weird physic artifacts, be the fact that dt is 0.
					timer.restart();
				}
			}
		}
		window.clear();
		if(simulate_physics) {
			particle_system.update(dt);		
		}
		particle_system.draw_all_particles(window);
		window.display();

		iteration++;
		dt = timer.restart().asSeconds();

		std::cout << "iteration: " << iteration << ", dt: " << dt << " in seconds.\n";
	}

	*/

	std::cout << "Hello, Sailor!" << "\n";
	constexpr double sigma = 10.0;
	constexpr double rho = 28.0;
	constexpr double beta = 8.0 / 3.0;

	Lorenz_Attractor_System lorenz_attractor(sigma, rho, beta);
	
	// @Todo: Fix this mess, we just want a sane way to set some initial values.
	std::array<double, 3> values = { 1.0, 1.0, 1.0 };
	State_Vector<3, double> initial_values(values);
	lorenz_attractor.m_initial_values = initial_values;
	
	
	Runge_Kutta_R4_ODE_Solver<3, double> runge_kutta_solver(0.0, 10.0, 0.01);
	
	std::vector<State_Vector<3, double>> solution_trajectory;
	runge_kutta_solver.solve(lorenz_attractor, solution_trajectory);

	for (const auto& point : solution_trajectory) {
		for (const auto& value : point.data()) {
			std::cout << value << " ";
		}
		std::cout << std::endl;
	}
	
	return 0;
}