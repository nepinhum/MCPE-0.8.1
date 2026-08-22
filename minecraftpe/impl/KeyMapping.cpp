#include <KeyMapping.hpp>

KeyMapping::KeyMapping(const std::string& name, int32_t code) : name(name){
	this->keyCode = code;
}
void KeyMapping::operator=(KeyMapping&& key){
	this->name = key.name;
	this->keyCode = key.keyCode;
}

KeyMapping::~KeyMapping(){}
