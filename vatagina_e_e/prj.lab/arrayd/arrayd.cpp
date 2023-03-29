#include "arrayd.hpp"
#include <iostream>
#include <cstddef>
#include <exception>
#include <algorithm>
#include <cmath>


ArrayD::~ArrayD() {
	delete[] data_;
}

ArrayD::ArrayD(const ArrayD& other) {
	ssize_ = other.ssize_;
	capasity_ = other.ssize_;
	for (ptrdiff_t i = 0; i < ssize_; ++i) {
		data_[i] = other.data_[i];
	}
}

ArrayD::ArrayD(const ptrdiff_t size) {
	if (size < 0) {
		throw std::invalid_argument("Get size > 0");
	}
	else {
		ssize_ = size;
		capasity_ = size;
		if (ssize_ != 0) {
			data_ = new double[ssize_];
		}
		else {
			data_ = 0;
		}
		//std::cout << "Array is built" << std::endl;
	}
}

double& ArrayD::operator[] (const ptrdiff_t index) {
	if ((index < 0) || (index >= capasity_)) {
		throw std::invalid_argument("Index is out of acceptable area");
	}
	else {
		return data_[index];
	}
}

const double& ArrayD::operator[] (const ptrdiff_t index) const {
	if ((index < 0) || (index >= capasity_)) {
		throw std::invalid_argument("Index is out of acceptable area");
	}
	else {
		return data_[index];
	}
}


ptrdiff_t ArrayD::ssize() const noexcept {
	return ssize_;
};


void ArrayD::resize(const ptrdiff_t new_size) {
	if (new_size < 0) {
		throw std::invalid_argument("size of array must be larger 0");
	}
	else {
		if (new_size > capasity_) {
			ptrdiff_t new_capacity = std::max(new_size, ssize_ * 2);
			double* temp = new double[new_capacity];
			for (ptrdiff_t i = 0; i < ssize_; ++i) {
				temp[i] = data_[i];
			}
			delete[] data_;
			data_ = temp;
			capasity_ = new_capacity;
		}
		else {
			//new_size<capasity;
			ptrdiff_t new_capacity = new_size;
			double* temp = new double[new_size];
			for (ptrdiff_t i = 0; i < new_size; ++i) {
				temp[i] = data_[i];
			}
			delete[] data_;
			data_ = temp;
			capasity_ = new_capacity;
		}
		ssize_ = new_size;
		//std::cout << "We changed size of array by " << ssize_ << std::endl;
	}
}

void ArrayD::remove(const ptrdiff_t i) {
	if ((i < 0) || (i > capasity_)) {
		throw std::invalid_argument("uncorrect index");
	}
	else {
		ssize_ -= 1;
		double* temp = new double[ssize_];
		for (ptrdiff_t index = 0; index < i; ++index) {
			temp[index] = data_[index];
		}
		for (ptrdiff_t index = i; index < (ssize_ + 1); ++index) {
			temp[index] = data_[index + 1];
		}
		delete[] data_;
		data_ = temp;
		capasity_ -= 1;
		//std::cout << i << " index was delated" << std::endl;
	}
}


void ArrayD::insert(const ptrdiff_t i, const double value) {
	if (i < 0) {
		throw std::invalid_argument("index must be larger 0");
	}
	else {
		resize(ssize_ + 1);
		for (ptrdiff_t index = ssize_ - 1; index > i; --index) {
			data_[index] = data_[index - 1];
		}
		data_[i] = value;
		//std::cout << "element was inserted" << std::endl;
	}
}
