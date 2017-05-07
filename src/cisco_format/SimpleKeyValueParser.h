/******************************************************************* 
 *  Copyright(c) 2010-2017 Netbrain
 *  All rights reserved. 
 *   
 *  �ļ�����: SimpleKeyValueParser.h
 *  ��Ҫ����: 
 *   
 *  ��ǰ�汾: 
 *  ����: limenghua
 *  ����: 4/27/2017
 *  ˵��:  
 *
 ******************************************************************/
#pragma once

#include <json/value.h>
#include "ConfigureParser/SentenceTree.h"
#include "CompoundTreeParser.h"
#include "ParserUtil.h"

/** 
* @brief �򵥶��������ʽ����������
* @describe ����һЩ�����ݣ������Կո��tab�ָ��key ��value��ɣ�������ʾ����ʾ:
*   1.version 15.2	key=version;value=15.2
*	2.hostname example key=hostname;value=example
* 
* ��������version 15.2 => {"version":"15.2"}
*			hostname example =>{"hostname":"example"
*			describe this is sample => {"describe":"this is sample"}
*/
class SimpleKeyValueTreeParser :public CompoundTreeParser
{
public:
	SimpleKeyValueTreeParser(const std::string & strKey,const std::string & defaultValue="") :
		_strKey(Trim(strKey)),
		_defaultValue(defaultValue)

	{
	}

	virtual Json::Value ParserSentence(const std::string & strSentence)override
	{
		Json::Value root;
		root["key"] = _strKey;

		size_t pos = strSentence.find(_strKey);

		if (pos == strSentence.npos)
		{
			throw std::exception("Sentence not has keywords");
		}
		else if (pos == 0)
		{
			pos = strSentence.find_first_not_of(" \t", _strKey.size());
			if (pos != strSentence.npos)
			{
				root[_strKey] = strSentence.substr(pos);
			}
			else
			{
				root[_strKey] = _defaultValue;
			}
		}
		else
		{
			std::string strPrefix = strSentence.substr(0, pos);
			if (Trim(strPrefix) == "no")
			{
				root[_strKey] = Json::Value::null;
			}
			else
			{
				throw std::exception("Sentence not start with keywords or 'no'");
			}
		}

		return root;
	}

	int ScoreMatchSentence(const std::string & strSentence)
	{
		size_t pos = strSentence.find(_strKey);
		if (pos == 0)return _strKey.size();

		if (pos == strSentence.npos)return -1;

		std::string strPrefix = strSentence.substr(0, pos);
		if (Trim(strPrefix) == "no")return _strKey.size() + 3;
		
		return -1;
	}
private:
	const std::string _strKey;
	const std::string _defaultValue;
};

