#include "matrix.h"
#include <iostream>
#include <memory>

int main(){
    auto m1 = std::make_unique<Matrix::Matrix>(4, 4, 'r');
    auto m2 = std::make_unique<Matrix::Matrix>(4, 4, 'r');
    std::cout << m1->ToString();
    std::cout << "+++++====\n";
    std::cout << m2->ToString();
    std::cout << "=====\n";
    //auto m3 = *m1 + *m2;
    m1 = *m1 + *m2;
    std::cout << m1->ToString();
    return 0;
}
