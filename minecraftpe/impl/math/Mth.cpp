#include <math/Mth.hpp>
float Mth::_sin[65536]; //XXX initialized in NinecraftApp::init
float Mth::_sinScale = 10430.0;
float Mth::RADDEG = 57.296;
float Mth::DEGRAD = 0.017453;
float Mth::TAU = 6.2832;
float Mth::PI = 3.1416;
static Random _random;

float Mth::random(void){
	return _random.genrand_int32() * 2.32830644e-10;
}

uint32_t Mth::random(int32_t bound){
	return _random.genrand_int32() % bound;
}
float Mth::clampRotate(float f, float f1, float f2){
	float f3, f4, f5;

	f3 = fmodf(f1 - f, 360.0);
	f4 = f3;
	if(f3 >= 180.0) f4 = f3 - 360.0;
	if(f4 < -180.0) f4 = f4 + 360.0;

	f5 = -f2;
	if(f4 > f2) f4 = f2;
	if(f4 >= f5) f5 = f4;
	return f + f5;
}
