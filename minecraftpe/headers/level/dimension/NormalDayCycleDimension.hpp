#pragma once
#include <level/dimension/Dimension.hpp>

struct NormalDayCycleDimension : Dimension{
	int8_t field_54;
	char align, align2, align3;


	virtual ~NormalDayCycleDimension(){}
	virtual float getTimeOfDay(long, float); //long
};
