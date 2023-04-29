#pragma once
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

	ArrayT(const ArrayT<T>&);

	ArrayT(const std::ptrdiff_t size);

	ArrayT<T>& operator=(const ArrayT<T>&);

	T& operator[] (const std::ptrdiff_t index);

	const T& operator[] (const std::ptrdiff_t index) const;

	std::ptrdiff_t ssize() const noexcept;

	void change_capasity(const std::ptrdiff_t other);

	void resize(const std::ptrdiff_t new_size);

	void remove(const std::ptrdiff_t i);

	void insert(const std::ptrdiff_t i, const T value);

private:
	std::ptrdiff_t ssize_ = 0;
	std::ptrdiff_t capasity_ = 0;
	T* data_ = nullptr;
};



template<typename T>
ArrayT<T>::~ArrayT() {
	delete[] data_;
}

template<typename T>
ArrayT<T>::ArrayT(const ArrayT<T>& other) {
	ssize_ = other.ssize_;
	capasity_ = other.capasity_;
	data_ = new T[capasity_];
	for (std::ptrdiff_t i = 0; i < ssize_; ++i) {
		data_[i] = other.data_[i];
	}
}
template<typename T>
ArrayT<T>::ArrayT(const std::ptrdiff_t size) {
	if (size < 0) {
		throw std::invalid_argument("Get size > 0");
	}
	else {
		ssize_ = size;
		capasity_ = size;
		data_ = new T[capasity_];
		std::fill(data_, data_ + ssize_, 0);
		//std::cout << "Array is built" << std::endl;
	}
}

template<typename T>
void ArrayT<T>::change_capasity(const std::ptrdiff_t new_cap) {
	capasity_ = new_cap;
	T* temp = new T[capasity_];
	std::copy(data_, data_ + ssize(), temp);
	std::fill(data_ + ssize_, data_ + capasity_, 0);
	delete[] data_;
	data_ = temp;
}

template<typename T>
T& ArrayT<T>::operator[] (const std::ptrdiff_t index) {
	if ((index < 0) || (index >= capasity_)) {
		throw std::invalid_argument("Index is out of acceptable area");
	}
	else {
		return data_[index];
	}
}
template<typename T>
const T& ArrayT<T>::operator[] (const std::ptrdiff_t index) const {
	if ((index < 0) || (index >= ssize())) {
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
void ArrayT<T>::resize(const std::ptrdiff_t new_size) {
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


template<typename T>
void ArrayT<T>::remove(const std::ptrdiff_t i) {
	if ((i < 0) || (i >ssize())) {
		throw std::invalid_argument("uncorrect index");
	}
	else {
		for (std::ptrdiff_t t = i + 1; t < ssize_; ++t) {
			data_[t - 1] = data_[t];
		}
		resize(ssize_ - 1);
	}
}

template<typename T>
void ArrayT<T>::insert(const std::ptrdiff_t i, const T value) {
	if (i < 0) {
		throw std::invalid_argument("index must be larger 0");
	}
	else {
		resize(ssize_ + 1);
		for (std::ptrdiff_t index = ssize_ - 1; index > i; --index) {
			data_[index] = data_[index - 1];
		}
		data_[i] = value;
		//std::cout << "element was inserted" << std::endl;
	}
}

template<typename T>
ArrayT<T>& ArrayT<T>::operator=(const ArrayT<T>& other) {
	if (this == &other) {
		return *this;
	}
	ssize_ = other.ssize_;
	capasity_ = other.capasity_;
	delete[] data_;
	data_ = new T[capasity_];
	for (std::ptrdiff_t i = 0; i < ssize(); ++i) {
		new (data_ + i) T(other.data_[i]);
	}
	return *this;
}

#endif 
