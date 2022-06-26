#include <vector>
#include <iostream>

std::vector<float>* convolve(std::vector<float>* sig1, std::vector<float>*sig2){
    auto outsig = new std::vector<float>();
    size_t len = sig1->size() + sig2->size() - 1;
    for (size_t i = 0; i < len; i++){
        outsig->push_back(0);
    }

    for (size_t sig2_n = 0; sig2_n < sig2->size(); sig2_n++){
        for (size_t sig1_n = 0; sig1_n < sig1->size(); sig1_n++){
            (*outsig)[sig2_n + sig1_n] += (*sig1)[sig1_n] * (*sig2)[sig2_n];
        }
    }

    return outsig;
}

int main(){
    auto sig1 = new std::vector<float>{0.5, 0, 1.0, 0.5};
    auto sig2 = new std::vector<float>{1.0, 0.75, 0.5, 0.25};
    auto convolved = convolve(sig1, sig2);

    for (size_t i = 0; i < convolved->size(); i++){
        std::cout << (*convolved)[i] << "\n";
    }

    return 0;
}