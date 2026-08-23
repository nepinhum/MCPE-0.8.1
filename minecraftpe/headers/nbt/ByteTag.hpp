#pragma once
#include <_types.h>
#include <nbt/Tag.hpp>
#include <util/input/IDataInput.hpp>
#include <util/output/IDataOutput.hpp>

struct ByteTag : public Tag{
	int8_t value;

	ByteTag(const std::string&, int8_t);

	virtual void write(IDataOutput* out){
		out->writeByte(this->value);
	}
	virtual void load(IDataInput* in){
		this->value = in->readByte();
	}
	virtual int32_t getId(void) const{
		return 1;
	}
	virtual std::string toString(void);
	virtual Tag* copy(void);
	bool_t equals(const Tag&);
};
