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
	explicit ArrayD() = default;

	~ArrayD();

	ArrayD(const ArrayD& other);

	ArrayD(const ptrdiff_t size);

	ArrayD& operator=(const ArrayD&);

	double& operator[] (const ptrdiff_t index);

	const double& operator[] (const ptrdiff_t index) const;

	ptrdiff_t ssize() const noexcept;


	void resize(const ptrdiff_t new_size);

	void remove(const ptrdiff_t i);

	void insert(const ptrdiff_t i, const double value);

private:
	ptrdiff_t ssize_ = 0;
	ptrdiff_t capasity_ = 0;
	double* data_ = nullptr;
};





#endif 
