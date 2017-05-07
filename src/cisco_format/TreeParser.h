/******************************************************************* 
 *  Copyright(c) 2010-2017 Netbrain
 *  All rights reserved. 
 *   
 *  �ļ�����: ConfigureParser.h
 *  ��Ҫ����: 
 *   
 *  ��ǰ�汾: 
 *  ����: limenghua
 *  ����: 4/26/2017
 *  ˵��:  
 *
 ******************************************************************/
#pragma once

#include "ParserUtil.h"
#include "SentenceTree.h"
#include <json/value.h>


class ITreeParser
{
public:
	typedef ITreeParser* ITreeParserPtr;
	virtual Json::Value Parse(const SentenceTree & tree) = 0;
	virtual int  ScoreMatchSentence(const std::string & strSentence) = 0;
	virtual ~ITreeParser(){};
};

class TreeParser :public ITreeParser
{
public:
	virtual Json::Value ParserSentence(const std::string & strSentence) = 0;

	virtual Json::Value Parse(const SentenceTree & tree) override
	{
		return ParserSentence(Trim(tree.GetData()));
	}
};

