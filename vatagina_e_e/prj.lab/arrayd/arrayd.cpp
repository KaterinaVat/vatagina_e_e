#include "arrayd/arrayd.hpp"
#include <iostream>
#include <cstddef>
#include <exception>
#include <algorithm>
#include <cmath>

ArrayD::ArrayD() {
	ssize_ = 0;
	capasity_ = 0;
	data_ = nullptr;
}


ArrayD::~ArrayD() {
	delete[] data_;
}

ArrayD::ArrayD(const ArrayD& other) {
	ssize_ = other.ssize_;
	capasity_ = other.ssize_;
	data_ = new double[capasity_];
	std::copy(other.data_, other.data_ + other.ssize_, data_);

}

ArrayD::ArrayD(const std::ptrdiff_t size) {
	if (size < 0) {
		throw std::invalid_argument("Get size > 0");
	}
	else {
		ssize_ = size;
		capasity_ = size;
		data_ = new double[ssize_];
		std::fill(data_, data_ + ssize_, 0);
	}
}

ArrayD& ArrayD::operator=(const ArrayD& other) {
	ssize_ = other.ssize_;
	capasity_ = other.capasity_;
	delete[] data_;
	data_ = new double[capasity_];
	for (std::ptrdiff_t i = 0; i < ssize(); ++i) {
		new (data_ + i) double(other.data_[i]);
	}
	return *this;
}
double& ArrayD::operator[] (const std::ptrdiff_t index) {
	if ((index < 0) || (index >= ssize())) {
		throw std::invalid_argument("Index is out of acceptable area");
	}
	return data_[index];
}

const double& ArrayD::operator[] (const std::ptrdiff_t index) const {
	if ((index < 0) || (index >= ssize())) {
		throw std::invalid_argument("Index is out of acceptable area");
	}
	return data_[index];
}


std::ptrdiff_t ArrayD::ssize() const noexcept {
	return ssize_;
};

void ArrayD::change_capasity(const std::ptrdiff_t new_cap) {
	capasity_ = new_cap;
	double* temp = new double[capasity_];
	std::copy(data_, data_ + ssize(), temp);
	std::fill(data_ + ssize_, data_ + capasity_, 0);
	delete[] data_;
	data_ = temp;
}

void ArrayD::resize(const std::ptrdiff_t new_size) {
	if (new_size <= 0) {
		throw std::invalid_argument("size of array must be larger 0");
	}

	if (new_size > capasity_) {
		change_capasity(new_size);
	}
	if (new_size > ssize_) {
		std::fill(data_ + ssize_, data_ + new_size, 0);
	}
	ssize_ = new_size;
}


void ArrayD::remove(const std::ptrdiff_t i) {
	if ((i < 0) || (i > capasity_)) {
		throw std::invalid_argument("uncorrect index");
	}
	double* temp = new double[ssize_ - 1];
	for (std::ptrdiff_t bgn = 0; bgn < i; ++bgn) {	
	temp[bgn] = data_[bgn];
	}
	for (std::ptrdiff_t end = i; end < ssize_ - 2; ++end) {
	temp[end] = data_[end + 1];
	}
	delete[] data_;
	data_ = temp;
	ssize_ = ssize_ - 1;
}


	void ArrayD::insert(const std::ptrdiff_t i, const double value) {
		if (i < 0 || i>ssize()) {
			throw std::invalid_argument("index must be larger 0");
		}
		double* temp = new double[ssize_ + 1];
		for (std::ptrdiff_t bgn = 0; bgn < i; ++bgn) {
			temp[bgn] = data_[bgn];
		}
		temp[i] = value;
		for (std::ptrdiff_t end = i+1; end < ssize_ +1; ++end) {
			temp[end] = data_[end + 1];
		}
		delete[] data_;
		data_ = temp;
		ssize_ = ssize_ + 1;
	
	}
