#pragma once

#include <_types.h>
#include <string>

struct KeyMapping{
	std::string name;
	int32_t keyCode;

	KeyMapping() {
		this->keyCode = 0;
	}
	~KeyMapping();
	KeyMapping(const std::string&, int32_t);
	void operator=(KeyMapping&&);
};
