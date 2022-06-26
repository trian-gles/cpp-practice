#include <iostream>

class SimpleHighpass {
	private:
		float _coef;
		float _prev;

	public:
		SimpleHighpass(float coef){
			_coef = coef;
			_prev = 0;
		}
		float in(float sample){
			float out = (sample * _coef) + (_prev * _coef);
			_prev = sample;

			return out;
		}

};

int main(){
	float stream[8] = {1, 6, 3, 6, 8, 3, 4, 9};
	SimpleHighpass hp(0.5);
	for (size_t i = 0; i < 8; i++){
		std::cout << hp.in(stream[i]) << "\n";
	}

	return 0;

}
