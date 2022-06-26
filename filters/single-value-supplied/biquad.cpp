#include <iostream>

class BiquadFilter {
    private:
        float a0, a1, a2, b1, b2;
        float xnm1, xnm2, ynm1, ynm2;

    public:
        BiquadFilter(float a0, float a1, float a2, float b1, float b2) : 
        a0{a0}, a1{a1}, a2{a2}, b1{b1}, b2{b2}, xnm1{0}, xnm2{0}, ynm1{0}, ynm2{0}
        { }

        float in(float sample){
            float out = sample * a0 + xnm1 * a1 + xnm2 * a2 + ynm1 * b1 + ynm2 * b2;
            xnm2 = xnm1;
            ynm2 = ynm1;
            xnm1 = sample;
            ynm1 = out;
            return out;
        }
};

int main(){
    BiquadFilter bf{0.2, 0.2, 0.2, 0.2, 0.2};
    float samples[8] = {1, 6, 2, 3, 7, 4, 8, 4};
    for (size_t i = 0; i < 8; i++) {
        std::cout << bf.in(samples[i]) << ", ";
    }
}