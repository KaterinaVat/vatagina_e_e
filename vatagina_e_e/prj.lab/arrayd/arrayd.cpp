#include "arrayd/arrayd.hpp"
#include <iostream>
#include <cstddef>
#include <exception>
#include <algorithm>
#include <cmath>



ArrayD::ArrayD() {
    data_ = nullptr;
    ssize_ = 0;
    capacity_ = 0;
}

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
	ssize_ = size;
	capasity_ = size;
	data_ = new double[ssize_];
	}
	for (std::ptrdiff_t i=0; i<size; ++i){
		data_[i]=0;
	}
}
ArrayD& ArrayD::operator=(const ArrayD& other) {
   	 if(this == &other){
        return *this;
   	 }
    	size_ = other.ssize_;
    	capacity_ = other.capacity_;
    	delete[] data_;
    	data_ = new double[capacity_];
    	for (std::ptrdiff_t i = 0; i < ssize(); ++i) {
        	new (data_ + i) double (other.data_[i]);
    	}
   	return *this;
}

double& ArrayD::operator[] (const ptrdiff_t index) {
	if ((index < 0) || (index >= capasity_)) {
		throw std::invalid_argument("Index is out of range");
	}
	else {
		return data_[index];
	}
}

const double& ArrayD::operator[] (const ptrdiff_t index) const {
	if ((index < 0) || (index >= capasity_)) {
		throw std::invalid_argument("Index is out of range");
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
		if (new_size > capacity_) {
			capacity_=new_size;
			if (capasity_<ssize()){
				ssize_=capacity_;
				return;
		}
		double* tmpM_=new double[capacity_];
		if (data_!=nullptr){
		std::copy(data_, data_+ssize_, tmpM_);
		} else {
			data_=nullptr;
			}
		std::fill(data_,data_+ssize(), 0);
		}
		delete[] data_;
		data_=tmpM_;
		}
		
		if (new_size>ssize())
			for (std::ptrdiff_t i=ssize(); i<ssize(); ++i){
			data_[i]=0;
			}
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
		for (ptrdiff_t index = i; index < ssize(); ++index) {
			temp[index] = data_[index + 1];
		}
		resize(ssize()-1);
	}
}


void ArrayD::insert(const ptrdiff_t i, const double value) {
	if (i < 0 || i>ssize()) {
		throw std::invalid_argument("invalidal index");
	}
		resize(ssize_ + 1);
		for (ptrdiff_t index = ssize_ - 1; index > i; --index) {
			data_[index] = data_[index - 1];
		}
		data_[i] = value;
		//std::cout << "element was inserted" << std::endl;
}
