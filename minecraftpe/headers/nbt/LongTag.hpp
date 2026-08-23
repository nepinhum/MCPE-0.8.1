#pragma once
#include <_types.h>
#include <nbt/Tag.hpp>
#include <util/input/IDataInput.hpp>
#include <util/output/IDataOutput.hpp>

struct LongTag : public Tag{
	int32_t field_C;
	int64_t value;

	LongTag(const std::string& n, int64_t v) : Tag(n){
		this->value = v;
	}
	virtual void write(IDataOutput* out){
		out->writeLongLong(this->value);
	}
	virtual void load(IDataInput* in){
		this->value = in->readLongLong();
	}
	virtual int32_t getId(void) const{
		return 4;
	}
	virtual std::string toString(void);
	virtual Tag* copy(void);
	bool_t equals(const Tag&);
};
