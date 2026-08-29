#pragma once
#include <_types.h>
#include <string>

struct LevelSummary
{
	std::string worldName, field_4;
	int32_t field_8, gamemode, field_10, field_14;

	LevelSummary() {
		this->worldName = "";
		this->field_4 = "";
	}
	LevelSummary(const LevelSummary&);
	LevelSummary(LevelSummary&&);
	LevelSummary& operator=(const LevelSummary&);
	LevelSummary& operator=(LevelSummary&&);


	bool operator<(const LevelSummary& a2) const;
};
