#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

class MedianFilter {
    private:
        std::vector<float>* _cache = new std::vector<float>();
        size_t _n;
        float _find_median(){
            auto temp_arr = *_cache;

            
            std::sort(temp_arr.begin(), temp_arr.end());
            std::cout << "sorted cache : ";
            for (size_t i = 0; i < temp_arr.size(); i++){
                std::cout << temp_arr[i] << ",";
            }
            std::cout << "\n";

            int center = floor(_n / 2);
            if (_n % 2 == 0) {
                return (temp_arr[center] + temp_arr[center - 1]) / 2;
            } 
            else {
                return temp_arr[center];
            }
        }

    public:
        MedianFilter(size_t n){
            _n = n;
        }
        float in(float input) {
            _cache->push_back(input);
            if (_cache->size() > _n){
                _cache->erase(_cache->begin());
            }
            return _find_median();
        }
};

int main() {
    float vals [6] = {1, 4, 2, 6, 9, 3};
    std::cout << "TESTING VALS\n";
    MedianFilter filter(3);
    for (size_t i = 0; i < 6; i++)
    {
        std::cout << i << " : " << filter.in(vals[i]) << "\n";
    }
}