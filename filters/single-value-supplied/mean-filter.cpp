#include <deque>
#include <iostream>


class MeanFilter {
    private:
        float _sum;
        size_t _n;
        std::deque<float>* queue = new std::deque<float>();

    public:
        MeanFilter(size_t n): _n{n} {

        }
        float in(float sample){
            _sum += sample;
            queue->push_back(sample);
            if (queue->size() > _n) {
                _sum -= (*queue)[0];
            }

            return _sum / queue->size();
        }

};


int main() {
    float vals [6] = {1, 4, 2, 6, 9, 3};
    std::cout << "TESTING VALS\n";
    MeanFilter filter(3);
    for (size_t i = 0; i < 6; i++)
    {
        std::cout << i << " : " << filter.in(vals[i]) << "\n";
    }
}