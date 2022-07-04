#include <vector>
#include "matrix.h"
#include <stdlib.h>
#include <memory>
#include <iostream>

namespace Matrix
{
    typedef std::vector<std::vector<float> > vecOfVecs;

    Matrix::Matrix(vecOfVecs const& vecs){
        _matrix = vecs;
        y = vecs.size();
        x = vecs[0].size();
    }

    Matrix::~Matrix(){
	    std::cout << "Deleting matrix" << std::endl;
    }

    Matrix::Matrix(int y, int x, char mode) {
	this->x = x;
	this->y = y;
        for (int i = 0; i < y; i++){
            std::vector<float> vec;
            for (int j = 0; j < x; j++){
		if (mode == 'r')
                	vec.push_back((float) rand()/RAND_MAX);
		else if (mode == '0')
			vec.push_back(0);
		else if (mode == '1')
			vec.push_back(1);
            }
            _matrix.push_back(vec);
        }
   

    }

    std::unique_ptr<Matrix> Matrix::operator + (Matrix &otherMatrix){
        vecOfVecs newVecOfVecs = _matrix;
        for (int i = 0; i < y; i++){
            for (int j = 0; j < x; j++){
                newVecOfVecs[i][j] += otherMatrix[i][j];
            }
        }

        return std::make_unique<Matrix>(newVecOfVecs);
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
}
