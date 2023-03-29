#pragma once

#ifndef ARRAYT_ARRAYT_HPP_20230322
#define ARRAYT_ARRAYT_HPP_20230322

#include <iostream>
#include <cstddef>
#include <exception>
#include <sstream>
#include <algorithm>
#include <cmath>

template<typename T>
class ArrayT {
public:
	ArrayT() = default;
	
	~ArrayT();

	ArrayT(const ArrayT<T>& other);

	ArrayT(const ptrdiff_t size);
	
	ArrayT<T>& operator=(const ArrayT<T>&);

	 T& operator[] (const ptrdiff_t index);
	
	 const T& operator[] (const ptrdiff_t index) const;
	
	ptrdiff_t ssize() const noexcept;


	void resize(const ptrdiff_t new_size);

	void remove(const ptrdiff_t i);

	void insert(const ptrdiff_t i, const T value);

private:
	ptrdiff_t ssize_ = 0;
	ptrdiff_t capasity_ = 0;
	T* data_ = nullptr;
};



template<typename T>
ArrayT<T>::~ArrayT() {
	delete[] data_;
}

template<typename T>
ArrayT<T>::ArrayT(const ArrayT<T>& other ) {
	ssize_ = other.ssize_;
	capasity_ = other.ssize_;
	for (ptrdiff_t i = 0; i < ssize_; ++i) {
		data_[i] = other.data_[i];
	}
}
template<typename T>
ArrayT<T>::ArrayT(const ptrdiff_t size) {
	if (size < 0) {
		throw std::invalid_argument("Get size > 0");
	}
	else {
		ssize_ = size;
		capasity_ = size;
		if (ssize_ != 0) {
			data_ = new T[ssize_];
		}
		else {
			data_ = 0;
		}
		//std::cout << "Array is built" << std::endl;
	}
}
template<typename T>
	T& ArrayT<T>::operator[] (const ptrdiff_t index) {
	if ((index < 0) || (index >= capasity_)) {
		throw std::invalid_argument("Index is out of acceptable area");
	}
	else {
		return data_[index];
	}
}
template<typename T>
 const T& ArrayT<T>::operator[] (const ptrdiff_t index) const {
	if ((index < 0) || (index >= capasity_)) {
		throw std::invalid_argument("Index is out of acceptable area");
	}
	else {
		return data_[index];
	}
}

 template<typename T>
ptrdiff_t ArrayT<T>::ssize() const noexcept {
	return ssize_;
};

template<typename T>
void ArrayT<T>::resize(const ptrdiff_t new_size) {
	if (new_size < 0) {
		throw std::invalid_argument("size of array must be larger 0");
	}
	else {
		if (new_size > capasity_) {
			ptrdiff_t new_capacity = std::max(new_size, ssize_ * 2);
			T* temp = new T[new_capacity];
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
			T* temp = new T[new_size];
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


template<typename T>
void ArrayT<T>::remove(const ptrdiff_t i) {
	if ((i < 0) || (i > capasity_)) {
		throw std::invalid_argument("uncorrect index");
	}
	else {
		ssize_ -= 1;
		T* temp = new T[ssize_];
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

template<typename T>
void ArrayT<T>::insert(const ptrdiff_t i, const T value) {
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

#endif 
