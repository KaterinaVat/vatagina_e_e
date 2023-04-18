#pragma once
#include <cstddef>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include <sstream>

class MatrixS {
    using SizeType = std::tuple <ptrdiff_t, ptrdiff_t>;
public:
    explicit MatrixS() {
        m_ = 0;
        n_ = 0;
    }

    MatrixS(const ptrdiff_t row, const ptrdiff_t col) {
        if (m_ < 0 and n_ < 0) {
            throw std::invalid_argument("Size must be positive")
        }
        m_ = row; //количество столбцов
        n_ = col; //количество строк
        int* data_ = new int[m_ * n_];
        for (int i = 0; i < (m_ * n_); ++i) {
            data[i] = 0;
        }
    }


    ~MatrixS() {
        delete[] data_;
    }

    MatrixS(const MatrixS& other) {
        m_ = other.m_;
        n_ = other.n_;
        data_ = new int [m_*n_];
        std::copy(other.data_, other.data_ + n_ * m_, data_);
    }

    MatrixS& operator=(const MatrixS& other) {
        if (this != &other) {
            if (n_ != other.n_ || m_ != other.m_) {
                delete[] data_;
                n_ = other.n_;
                m_ = other.m_;
                data_ = new int[m_ * n_];
            }
            std::copy(other.data_, other.data_ + n_ * m_, data_);
        }
        return *this;
    }


    [[nodiscard]] int& at(const MatrixS& elem) {
        return data_[elem.m_][elem.n_];
    }
    [[nodiscard]] const int& at(const MatrixS& elem) const {
        return data_[elem.m_][elem.n_];
    }
    [[nodiscard]] int& at(const std::ptrdiff_t i, const std::ptrdiff_t j) {
        return data_[i][j];
    }
    [[nodiscard]] const int& at(const std::ptrdiff_t i, const std::ptrdiff_t j) const {
        return data_[i][j];
    }


    [[nodiscard]] const SizeType& ssize() const noexcept {
        return size;
    }


    void resize(const MatrixS& new_size);

    [[nodiscard]] auto getRows() const noexcept {
        return m_;
    }

    [[nodiscard]] auto getCols() const noexcept {
        return n_;
    }
    SizeType size = std::make_pair(m_, n_);
   

private:
    ptrdiff_t m_ = 0;
    ptrdiff_t n_ = 0;
    int** data_ = nullptr;

};