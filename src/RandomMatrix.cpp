#include "RandomMatrix.h"

#include <random>

namespace meltrix {

    RandomMatrix::RandomMatrix(int rows, int cols, meltrix::DISTRIBUTION_TYPE type) {
        m_Rows = rows;
        m_Cols = cols;
        m_Data.resize(rows * cols);

        std::random_device rd;
        std::mt19937 gen(rd());

        switch (type) {
            case UNIFORM: {
                std::uniform_real_distribution<double> uniform_dist(0, 1);
                std::generate(m_Data.begin(), m_Data.end(), [&]() { return uniform_dist(gen); });
            }
                break;
            case BINOMIAL: {
                std::binomial_distribution<int> binomial_dist(50, 0.5);
                std::generate(m_Data.begin(), m_Data.end(), [&]() { return (float) binomial_dist(gen); });
            }
                break;
            case NORMAL: {
                std::normal_distribution<double> normal_dist(5, 2);
                std::generate(m_Data.begin(), m_Data.end(), [&]() { return normal_dist(gen); });
            }
                break;
        }
    }

    RandomMatrix::RandomMatrix(int rows, int cols, meltrix::DISTRIBUTION_TYPE type, double param1, double param2) {
        m_Rows = rows;
        m_Cols = cols;
        m_Data.resize(rows * cols);

        std::random_device rd;
        std::mt19937 gen(rd());

        switch (type) {
            case UNIFORM: {
                std::uniform_real_distribution<double> uniform_dist(param1, param2);
                std::generate(m_Data.begin(), m_Data.end(), [&]() { return uniform_dist(gen); });
            }
                break;
            case BINOMIAL: {
                std::binomial_distribution<int> binomial_dist(param1, param2);
                std::generate(m_Data.begin(), m_Data.end(), [&]() { return binomial_dist(gen); });
            }
                break;
            case NORMAL: {
                std::normal_distribution<double> normal_dist(param1, param2);
                std::generate(m_Data.begin(), m_Data.end(), [&]() { return normal_dist(gen); });
            }
                break;
        }
    }

} // meltrix
