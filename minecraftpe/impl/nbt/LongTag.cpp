#include <nbt/LongTag.hpp>
#include <sstream>

std::string LongTag::toString(void){
	std::stringstream ss;
	ss << this->value;
	return ss.str();
}
Tag* LongTag::copy(void){
	return new LongTag(this->getName(), this->value);
}
bool_t LongTag::equals(const Tag& v){
	const LongTag* tg = (const LongTag*) &v;
	bool_t eq = Tag::equals(v);
	if(eq) return this->value == tg->value;
	return eq;
}
