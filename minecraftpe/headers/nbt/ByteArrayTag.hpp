#pragma once
#include <_types.h>
#include <nbt/Tag.hpp>
#include <util/input/IDataInput.hpp>
#include <util/output/IDataOutput.hpp>

struct ByteArrayTag : public Tag{
	int8_t* value;
	int32_t count;

	ByteArrayTag(const std::string&, int8_t*, int32_t);
	virtual void write(IDataOutput* out){
		out->writeInt(this->count);
		out->writeBytes(this->value, this->count);
	}
	virtual void load(IDataInput* in){
		int32_t n = in->readInt();
		int8_t* arr = new int8_t[n];
		this->value = arr;
		//XXX doesnt change count for some reason

		in->readBytes(this->value, n);
	}
	virtual int32_t getId(void) const{
		return 7;
	}
	virtual std::string toString(void);
	virtual Tag* copy(void);
	bool_t equals(const Tag&);
};
