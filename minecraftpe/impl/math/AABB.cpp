#include <math/AABB.hpp>

float AABB::clipXCollide(const AABB& a2, float a3) {
	float v4;	// s15
	float maxX; // s15
	float v6;	// s13

	if(a2.maxY > this->minY && a2.minY < this->maxY && a2.maxZ > this->minZ && a2.minZ < this->maxZ) {
		if(a3 <= 0.0 || (maxX = a2.maxX, maxX > this->minX) || (v4 = this->minX - maxX, v4 >= a3)) {
			v4 = a3;
		}
		if(v4 < 0.0) {
			v6 = this->maxX;
			if(a2.minX >= v6 && (float)(v6 - a2.minX) > v4) {
				return v6 - a2.minX;
			}
		}
		return v4;
	}
	return a3;
}
float AABB::clipYCollide(const AABB& a2, float a3) {
	float v3;	// s14
	float v4;	// s15
	float maxY; // s15
	float minY; // s13
	float v7;	// s14
	float v8;	// s13
	float v9;	// s14

	v3 = a3;
	if(a2.maxX > this->minX && a2.minX < this->maxX && a2.maxZ > this->minZ && a2.minZ < this->maxZ) {
		if(a3 <= 0.0 || (maxY = a2.maxY, minY = this->minY, maxY > minY) || (v4 = minY - maxY, v4 >= a3)) {
			v4 = a3;
		}
		if(v4 < 0.0) {
			v7 = a2.minY;
			v8 = this->maxY;
			if(v7 >= v8) {
				v9 = v8 - v7;
				if(v9 > v4) {
					return v9;
				}
			}
		}
		return v4;
	}
	return v3;
}
float AABB::clipZCollide(const AABB& a2, float a3) {
	float v3;	// s14
	float v4;	// s15
	float maxZ; // s15
	float minZ; // s13
	float v7;	// s14
	float v8;	// s13
	float v9;	// s14

	v3 = a3;
	if(a2.maxX > this->minX && a2.minX < this->maxX && a2.maxY > this->minY && a2.minY < this->maxY) {
		if(a3 <= 0.0 || (maxZ = a2.maxZ, minZ = this->minZ, maxZ > minZ) || (v4 = minZ - maxZ, v4 >= a3)) {
			v4 = a3;
		}
		if(v4 < 0.0) {
			v7 = a2.minZ;
			v8 = this->maxZ;
			if(v7 >= v8) {
				v9 = v8 - v7;
				if(v9 > v4) {
					return v9;
				}
			}
		}
		return v4;
	}
	return v3;
}
AABB AABB::merge(const AABB& bb) {
	AABB result;
	float minX, minY, minZ;
	float maxX, maxY, maxZ;

	if(bb.minX >= this->minX) minX = this->minX;
	else minX = bb.minX;

	if(bb.minY < this->minY) minY = bb.minY;
	else minY = this->minY;

	if(bb.minZ < this->minZ) minZ = bb.minZ;
	else minZ = this->minZ;

	if(this->maxX < bb.maxX) maxX = bb.maxX;
	else maxX = this->maxX;

	if(this->maxY < bb.maxY) maxY = bb.maxY;
	else maxY = this->maxY;

	if(this->maxX >= bb.maxZ) maxZ = this->maxZ;
	else maxZ = bb.maxZ;

	result.minX = minX;
	result.minY = minY;
	result.minZ = minZ;
	result.maxX = maxX;
	result.maxY = maxY;
	result.maxZ = maxZ;

	return result;
}
