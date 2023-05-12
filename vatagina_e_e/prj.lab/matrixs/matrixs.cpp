#include <iosfwd>
#include "matrixs/matrixs.hpp"
#include <algorithm>

MatrixS::MatrixS() {
    row_ = 0;
    col_ = 0;
    size_ = 0;
    data_ = nullptr;
}


MatrixS::MatrixS(const std::ptrdiff_t m, const std::ptrdiff_t n) {
    row_ = m;
    col_ = n;
    size_ = row_ * col_;
    if (row_ <= 0 and col_ <= 0) {
        throw std::invalid_argument("Size must be positive");
    }
    data_ = new int[size_];
    for (int i = 0; i < size_; ++i) {
        data_[i] = 0;
    }
}


MatrixS::~MatrixS() {
    delete[] data_;
}

MatrixS::MatrixS(const MatrixS& other) {
    row_ = other.row_;
    col_ = other.col_;
    size_ = row_ * col_;
    data_ = new int[size_];
    std::copy(other.data_, other.data_ + size_, data_);
}

MatrixS& MatrixS::operator=(const MatrixS& other) {
    row_ = other.row_;
    col_ = other.col_;
    size_ = other.size_;
    delete[] data_;
    data_ = new int[size_];
    for (std::ptrdiff_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
    return *this;
    }


int& MatrixS::at(const SizeType& elem) {
    const ptrdiff_t first_elem = std::get<0>(elem);
    const ptrdiff_t second_elem = std::get<1>(elem);
    if (first_elem >= row_ and second_elem >= col_) {
        throw std::invalid_argument("Index is out of range");
    }
    std::ptrdiff_t index = (first_elem - 1) * col_ + second_elem;
    return data_[index];
}


const int& MatrixS::at(const SizeType& elem) const {
    const ptrdiff_t first_elem = std::get<0>(elem);
    const ptrdiff_t second_elem = std::get<1>(elem);
    if (first_elem >= row_ and second_elem >= col_) {
        throw std::invalid_argument("Index is out of range");
    }
    std::ptrdiff_t index = (first_elem - 1) * col_ + second_elem;
    return data_[index];
}

int& MatrixS::at(const std::ptrdiff_t i, const std::ptrdiff_t j) {
    if (i >= row_ and j >= col_) {
        throw std::invalid_argument("Index is out of range");
    }
    std::ptrdiff_t index = (i - 1) * col_ + j;
    return data_[index];
}

const int& MatrixS::at(const std::ptrdiff_t i, const std::ptrdiff_t j) const {
    if (i >= row_ and j >= col_) {
        throw std::invalid_argument("Index is out of range");
    }
    std::ptrdiff_t index = (i - 1) * col_ + j;
    return data_[index];
}


void MatrixS::resize(const SizeType& new_size) {
    ptrdiff_t new_row_ = std::get<0>(new_size);
    ptrdiff_t new_col_ = std::get<1>(new_size);
    if (new_row_ <= 0 || new_col_ <= 0) {
        throw std::invalid_argument("invalid new size");
    }

    MatrixS new_data_(new_row_, new_col_);
    for (std::ptrdiff_t i = 0; i < new_row_; ++i) {
        for (std::ptrdiff_t j = 0; j < new_col_; ++j) {
            new_data_.at(i, j) = at(i, j);
        }
    }
    *this = new_data_;
}

void MatrixS::resize(const std::ptrdiff_t i, const std::ptrdiff_t j) {
    if (i <= 0 || j <= 0) {
        throw std::invalid_argument("Invalid arguments");
    }

    MatrixS new_data_(i, j);
    for (std::ptrdiff_t I = 0; I < i; I++) {
        for (std::ptrdiff_t J = 0; J < j; J++) {
            new_data_.at(I, J) = at(I, J);
        }
    }
    *this = new_data_;
}

const MatrixS::SizeType& MatrixS::ssize() const noexcept {
    return SizeType(row_, col_);
}


std::ptrdiff_t MatrixS::nRows() const noexcept {
    return row_;
}

std::ptrdiff_t MatrixS::nCols() const noexcept {
    return col_;
}



