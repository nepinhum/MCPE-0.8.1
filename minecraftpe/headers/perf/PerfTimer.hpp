#pragma once
#include <_types.h>
#include <string>
#include <vector>
#include <map>

struct PerfTimer
{
	struct ResultField
	{
		float field_0;
		float field_4;
		std::string field_8;

		ResultField(PerfTimer::ResultField&&);
		ResultField(const PerfTimer::ResultField& a2) {
			this->field_0 = a2.field_0;
			this->field_4 = a2.field_4;
			this->field_8 = a2.field_8;
		}

		int32_t getColor();
		bool_t operator<(const PerfTimer::ResultField&);

		ResultField& operator=(PerfTimer::ResultField&&);
		~ResultField();
	};

	static std::map<std::string, float> times;
	static std::string path;
	static std::vector<double> startTimes;
	static std::vector<std::string> paths;
	static bool_t enabled;


	static std::vector<PerfTimer::ResultField> getLog(const std::string&);
	static void pop();
	static void popPush(const std::string&);
	static void push(const std::string&);
	static void reset();
};
