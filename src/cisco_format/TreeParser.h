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
#include "ConfigureParser/SentenceTree.h"
#include <json/value.h>

/*
 *	���ѷ�����ɵ������SentenceTree�н�����Json��ʽ����
 */
class ITreeParser
{
public:
	typedef ITreeParser* ITreeParserPtr;
	/** 
	 * @brief �����ӿ�
	 * @param const SentenceTree & tree��[in],�������ȷ��˵�Ǵ�Config�ļ���������Ϊ��׼����������״�����ṹ
	 *
	 * @return ���������JSon��ʽ
	 * @exeption ��ʽ������׳�std::exeption
	 *			
	 */
	virtual Json::Value Parse(const SentenceTree & tree) = 0;
	/**
	* @brief ����������ƥ��ȼ�⣬�����жϸö����Ƿ��ʺϽ�����SentenceTree�������ڽ���������ɸѡ����ʵĽ�������һ�㷵��ƥ�䵽�Ĺؼ����ַ�������
	* @param const std::string & strSentence��[in],����������䣬һ����SentenceTree��Data���ݡ�
	*
	* @return int ƥ��ȣ�һ����ڵ�������Ϊ����������������ֵӦ��ֱ��pass����
	*
	*/
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

