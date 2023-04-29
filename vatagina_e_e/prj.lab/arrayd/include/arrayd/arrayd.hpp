#pragma once
#pragma once

#ifndef ARRAYD
#define ARRAYD

#include <iostream>
#include <cstddef>
#include <exception>
#include <algorithm>
#include <cmath>


class ArrayD {

public:
	explicit ArrayD();

	~ArrayD();

	ArrayD(const ArrayD& other);
	
	ArrayD& operator=(const ArrayD&);

	ArrayD(const std::ptrdiff_t size);

	double& operator[] (const std::ptrdiff_t index);

	const double& operator[] (const std::ptrdiff_t index) const;

	std::ptrdiff_t ssize() const noexcept;

	void change_capasity(const std::ptrdiff_t other);
	
	void resize(const std::ptrdiff_t new_size);

	void remove(const std::ptrdiff_t i);

	void insert(const std::ptrdiff_t i, const double value);

private:
	ptrdiff_t ssize_ = 0;
	ptrdiff_t capasity_ = 0;
	double* data_ = nullptr;
};





#endif 
