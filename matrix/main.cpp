#include "matrix.h"
#include <iostream>

int main(){
    auto m1 = Matrix::Random(4, 4);
    auto m2 = Matrix::Random(4, 4);
    std::cout << m1.ToString();
    std::cout << "+++++\n";
    std::cout << m2.ToString();
    std::cout << "=====\n";
    auto m3 = m1 + m2;
    std::cout << m3.ToString();
    return 0;
}
