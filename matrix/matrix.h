#include <vector>
#include <iostream>
#include <string>


namespace Matrix{
    typedef std::vector<std::vector<float> > vecOfVecs;

    class Matrix {
        public:
            Matrix(vecOfVecs const& vecs);

            Matrix operator + (Matrix &otherMatrix);

            Matrix T();

            std::vector<float>& operator[] (const int index);

            std::string ToString();

        private:
            vecOfVecs _matrix;
            vecOfVecs _t;
            int x, y;
    };

    Matrix& Random(int y, int x);
}

