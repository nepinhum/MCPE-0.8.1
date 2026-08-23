#include <nbt/ByteArrayTag.hpp>
#include <util/input/IDataInput.hpp>
#include <util/output/IDataOutput.hpp>
#include <string.h>

//XXX also doesnt delete this->value ??
ByteArrayTag::ByteArrayTag(const std::string& n, int8_t* arr, int32_t length) : Tag(n){
	this->value = arr;
	this->count = length;
}
std::string ByteArrayTag::toString(){
	std::string result = "[";
	result += this->count;
	result += " bytes]";
	return result;
}
Tag* ByteArrayTag::copy(void){
	int8_t* arr = new int8_t[this->count];
	memcpy(arr, this->value, this->count);
	return new ByteArrayTag(this->getName(), arr, 0); //XXX count is 0??????
}
bool_t ByteArrayTag::equals(const Tag& t){
	const ByteArrayTag* tg = (const ByteArrayTag*) &t;
	bool_t eq = Tag::equals(t);

	if(eq){
		int32_t count = this->count;
		return count == tg->count && memcmp(this->value, tg->value, count) == 0;
	}
	return eq;
}
