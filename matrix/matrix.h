#include <vector>
#include <iostream>
#include <string>
#include <memory>


namespace Matrix{
    typedef std::vector<std::vector<float> > vecOfVecs;

    class Matrix {
        public:
            Matrix(vecOfVecs const& vecs);

	    ~Matrix();

	    Matrix(int y, int x, char mode);

	    std::unique_ptr<Matrix> operator + (Matrix &otherMatrix);

            Matrix T();

            std::vector<float>& operator[] (const int index);

            std::string ToString();

        private:
            vecOfVecs _matrix;
            vecOfVecs _t;
            int x, y;
    };
}

