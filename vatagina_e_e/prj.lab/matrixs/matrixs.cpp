#include <iosfwd>
#include <vector>
#include "matrixs/matrixs.hpp";
#include <algorithm>

MatrixS::MatrixS(const SizeType& size) {
    row_ = std::get<0>(size);
    col_ = std::get<1>(size);
    if (row_ <= 0 || col_ <= 0) {
        throw std::invalid_argument("Size must be positive");
    }
    data_ = new int[row_ * col_];
    for (int i = 0; i < (row_ * col_); ++i) {
        data_[i] = 0;
    }
}


MatrixS::MatrixS(const std::ptrdiff_t m, const std::ptrdiff_t n) {
    row_ = m;
    col_ = n;
    if (row_ <= 0 and col_ <= 0) {
        throw std::invalid_argument("Size must be positive");
    }
    data_ = new int[row_ * col_];
    for (int i = 0; i < (row_ * col_); ++i) {
        data_[i] = 0;
    }
}


MatrixS::~MatrixS() {
    delete[] data_;
}

MatrixS::MatrixS(const MatrixS& other) {
    row_ = other.row_;
    col_ = other.col_;
    data_ = new int[row_ * col_];
    std::copy(other.data_, other.data_ + (col_ * row_), data_);
}

MatrixS& MatrixS::operator=(const MatrixS& other) {
    if (this != &other) {
        if (row_ != other.row_ || col_ != other.col_) {
            delete[] data_;
            row_ = other.row_;
            col_ = other.col_;
            data_ = new int[row_ * col_];
        }
        std::copy(other.data_, other.data_ + (row_ * col_), data_);
    }
    return *this;
}

[[nodiscard]] int& MatrixS::at(const SizeType& elem) {
    const ptrdiff_t first_elem = std::get<0>(elem);
    const ptrdiff_t second_elem = std::get<1>(elem);
    if (first_elem >= row_ and second_elem >= col_) {
        throw std::invalid_argument("Index is out of range");
    }
    return data_[first_elem * col_ + second_elem];
}


[[nodiscard]] const int& MatrixS::at(const SizeType& elem) const {
    const ptrdiff_t first_elem = std::get<0>(elem);
    const ptrdiff_t second_elem = std::get<1>(elem);
    if (first_elem >= row_ and second_elem >= col_) {
        throw std::invalid_argument("Index is out of range");
    }
    return data_[first_elem * col_ + second_elem];
}

[[nodiscard]] int& MatrixS::at(const std::ptrdiff_t i, const std::ptrdiff_t j) {
    if (i >= row_ and j >= col_) {
        throw std::invalid_argument("Index is out of range");
    }
    return data_[i * col_ + j];
}

[[nodiscard]] const int& MatrixS::at(const std::ptrdiff_t i, const std::ptrdiff_t j) const {
    if (i >= row_ and j >= col_) {
        throw std::invalid_argument("Index is out of range");
    }
    return data_[i * col_ + j];
}

int& MatrixS::operator[](const SizeType& elem) {
    const ptrdiff_t first_elem = std::get<0>(elem);
    const ptrdiff_t second_elem = std::get<1>(elem);
    return data_[first_elem * col_ + second_elem];
}
void MatrixS::resize(const SizeType& new_size) {
    ptrdiff_t new_row_ = std::get<0>(new_size);
    ptrdiff_t new_col_ = std::get<1>(new_size);
    if (new_row_ <= 0 || new_col_ <= 0) {
        throw std::invalid_argument("invalid new size");
    }

    MatrixS new_data_(new_row_, new_col_);
    for (size_t i = 0; i < new_row_; i++) {
        for (size_t j = 0; j < new_col_; j++) {
            new_data_[ i*col_+j] = data_[i * col_ + j];
        }
    }
    data_ = new_data_.data_;
}

void MatrixS::resize(const std::ptrdiff_t i, const std::ptrdiff_t j) {
    if (i < 0 || j < 0) {
        throw std::invalid_argument("Invalid arguments");
    }
    if (i == 0 || j == 0) {
        delete[] data_;
        return;
    }
    MatrixS new_data_(i, j);
    for (size_t I = 0; I <i; I++) {
        for (size_t J = 0; J < j; J++) {
            new_data_[I * col_ + J] = data_[I * col_ + J];
        }
    }
    data_ = new_data_.data_;
}

[[nodiscard]] const MatrixS::SizeType& ssize() const noexcept {
    return size_;
}


[[nodiscard]] std::ptrdiff_t nRows() const noexcept {
    return this->row_;
}

[[nodiscard]] std::ptrdiff_t nCols() const noexcept {
    return this->col_;
}

