#include <vector>
#include "matrix.h"
#include <stdlib.h>

namespace Matrix
{
    typedef std::vector<std::vector<float> > vecOfVecs;

    Matrix::Matrix(vecOfVecs const& vecs){
        _matrix = vecs;
        y = vecs.size();
        x = vecs[0].size();
    }

    Matrix Matrix::operator + (Matrix &otherMatrix){
        vecOfVecs newVecOfVecs = _matrix;
        for (int i = 0; i < y; i++){
            for (int j = 0; j < x; j++){
                newVecOfVecs[i][j] += otherMatrix[i][j];
            }
        }

        return newVecOfVecs;
    }

    Matrix Matrix::T(){
        return Matrix(_t);
    }

    std::vector<float>& Matrix::operator[] (const int index) {
        return _matrix[index];
    }

    std::string Matrix::ToString(){
        std::string output = "";
        for (int i = 0; i < y; i++){
            for (int j = 0; j < x; j++){

                std::string stringVal = std::to_string((*this)[j][i]);
                output.insert(output.end(), stringVal.begin(), stringVal.end());
                output.push_back(',');
            }
            output.push_back('\n');
        }
        return output;
    }

    Matrix& Random(int x, int y){
        vecOfVecs newVec;

        for (int i = 0; i < y; i++){
            std::vector<float> vec;
            for (int j = 0; j < x; j++){
                vec.push_back(1.0 / (rand() % 100 + 1));
            }
            newVec.push_back(vec);
        }
        Matrix* newMat = new Matrix(newVec);
        return (*newMat);
    }
}