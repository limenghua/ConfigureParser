/******************************************************************* 
 *  Copyright(c) 2010-2017 Nethead
 *  All rights reserved. 
 *   
 *  �ļ�����: DefaultTreeParser.h
 *  ��Ҫ����: 
 *   
 *  ��ǰ�汾: 
 *  ����: limenghua
 *  ����: 4/27/2017
 *  ˵��:  
 *
 ******************************************************************/
#pragma once

#include "CompoundTreeParser.h"
#include <json/value.h>

class DefaultTreeParser :public CompoundTreeParser
{
public:
	DefaultTreeParser()
	{
		AddSubParser(this);
	}

	virtual Json::Value ParserSentence(const std::string & strSentence)override
	{
		Json::Value value;
		value["key"] = "origin";
		value["origin"] = strSentence;
		return value;
	}

	virtual int ScoreMatchSentence(const std::string & strSentence)override
	{
		return 0;
	}
};