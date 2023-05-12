#pragma once

#include <array>

template<unsigned int N, typename real_number_type>
class State_Vector {
public:
	State_Vector() = default;

	State_Vector(std::array<real_number_type, N> data) 
	: m_data(data)
	{
		
	}

	// no range checking
	double& operator[](size_t idx) { 
		return m_data[idx]; 
	}

	const double& operator[](size_t idx) const { 
		return m_data[idx];
	}

	State_Vector<N, real_number_type> operator+(State_Vector<N, real_number_type>& other) const {
		State_Vector<N, real_number_type> result;
		for (size_t i = 0; i < N; i++) {
			result[i] = m_data[i] + other[i];
		}
		return result;
	}

	State_Vector<N, real_number_type> operator-(State_Vector<N, real_number_type>& other) const {
		State_Vector<N, real_number_type> result;
		for (size_t i = 0; i < N; i++) {
			result[i] = m_data[i] - other[i];
		}
		return result;
	}

	State_Vector<N, real_number_type> operator*(real_number_type scalar) const {
		State_Vector<N, real_number_type> result;
		for (size_t i = 0; i < N; i++) {
			result[i] = scalar * m_data[i];
		}
		return result;
	}

	State_Vector<N, real_number_type> operator/(real_number_type scalar) const {
		State_Vector<N, real_number_type> result;
		for (size_t i = 0; i < N; i++) {
			result[i] = m_data[i] / scalar;
		}
		return result;
	}

	State_Vector<N, real_number_type>& operator*=(real_number_type scalar) {;
		for (size_t i = 0; i < N; i++) {
			m_data[i] *= scalar;
		}
		return *this;
	}

	State_Vector<N, real_number_type>& operator/=(real_number_type scalar) {
		for (size_t i = 0; i < N; i++) {
			m_data[i] /= scalar;
		}
		return *this;
	}

	State_Vector<N, real_number_type>& operator+=(const State_Vector<N, real_number_type>& other) {
		for (size_t i = 0; i < N; ++i) {
			m_data[i] += other[i];
		}
		return *this;
	}

	State_Vector<N, real_number_type>& operator-=(const State_Vector<N, real_number_type>& other) {
		for (size_t i = 0; i < N; ++i) {
			m_data[i] -= other[i];
		}
		return *this;
	}

	std::array<real_number_type, N> data() const {
		return m_data;
	}
private:
	std::array<real_number_type, N> m_data;
};


template<unsigned int N, typename real_number_type>
State_Vector<N, real_number_type> operator*(real_number_type scalar, const State_Vector<N, real_number_type>& vector) {
	return vector * scalar;
}