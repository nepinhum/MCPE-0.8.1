#include <math/Vec3.hpp>

Vec3 Vec3::ZERO(0, 0, 0);
Vec3 Vec3::ONE(1, 1, 1);

Vec3 Vec3::UNIT_X(1, 0, 0);
Vec3 Vec3::NEG_UNIT_X(-1, 0, 0);

Vec3 Vec3::UNIT_Y(0, 1, 0);
Vec3 Vec3::NEG_UNIT_Y(0, -1, 0);

Vec3 Vec3::UNIT_Z(0, 0, 1);
Vec3 Vec3::NEG_UNIT_Z(0, 0, -1);

float Vec3::distanceTo(const Vec3& v){
	float dy = v.y - this->y;
	float dz = v.z - this->z;
	float dx = v.x - this->x;

	return sqrt(dy*dy + dx*dx + dz*dz);
}
Vec3 Vec3::normalized(void){
	float length;

	length = sqrt((this->y*this->y)+(this->x*this->x)+(this->z*this->z));

	if(length >= 0.0001){
		return Vec3(this->x / length, this->y / length, this->z / length);
	}
	return Vec3::ZERO;
}
