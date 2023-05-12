cmake_minimum_required(VERSION 3.16.0)

project(lorenz_attractor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory("3rd-party/sfml")

add_executable(
	${PROJECT_NAME}
	"src/main.cpp"
	"src/Lorenz_Attractor/State_Vector.hpp"
	"src/Lorenz_Attractor/abstract_ode_solver.hpp"
	"src/Lorenz_Attractor/abstract_ode_system.cpp"
	"src/Lorenz_Attractor/lorenz_attractor_system.cpp"
	"src/Lorenz_Attractor/runge_kutta_r4_solver.hpp"
)

target_include_directories(
   ${PROJECT_NAME}
   PUBLIC
	  "${CMAKE_SOURCE_DIR}/3rd-party/SFML/include"
)

target_link_libraries(
	${PROJECT_NAME} 
	PUBLIC
	sfml-graphics sfml-window sfml-system 
	
	# other unused sfml components, dont forget to add copy .dll commands below for them
	# sfml-audio sfml-network sfml-main
)

# copy the .dll file to the same folder as the executable
if (WIN32)
	add_custom_command(
		TARGET ${PROJECT_NAME}  POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
		$<TARGET_FILE:sfml-graphics>
		$<TARGET_FILE_DIR:${PROJECT_NAME}>
		VERBATIM)
	add_custom_command(
		TARGET ${PROJECT_NAME}  POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
		$<TARGET_FILE:sfml-window>
		$<TARGET_FILE_DIR:${PROJECT_NAME}>
		VERBATIM)
	add_custom_command(
		TARGET ${PROJECT_NAME}  POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
		$<TARGET_FILE:sfml-system>
		$<TARGET_FILE_DIR:${PROJECT_NAME}>
		VERBATIM)
endif()