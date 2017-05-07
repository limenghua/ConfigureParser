/*******************************************************************
*  Copyright(c) 2010-2017 Netbrain
*  All rights reserved.
*
*  �ļ�����: TestUtil.h
*  ��Ҫ����:
*
*  ��ǰ�汾:
*  ����: limenghua
*  ����: 2017/05/07
*  ˵��:
*
******************************************************************/
#pragma once

#include <json/json.h>

inline Json::Value CreateJsonFromString(const std::string & strJson)
{
	Json::Value value;
	Json::Reader reader;
	reader.parse(strJson, value);
	return value;
}

inline std::string Stringfy(const Json::Value & value)
{
	Json::FastWriter writer;
	return writer.write(value);
}