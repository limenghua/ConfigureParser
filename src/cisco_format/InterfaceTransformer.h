/*******************************************************************
*  Copyright(c) 2010-2017 Netbrain
*  All rights reserved.
*
*  �ļ�����: InterfaceTransformer.h
*  ��Ҫ����:
*
*  ��ǰ�汾:
*  ����: limenghua
*  ����: 2017/05/07
*  ˵��:
*
******************************************************************/

#pragma once

#include "Transformer.h"

class InterfaceTransformer :public DefualtTransformer
{
public:
	Json::Value Transform(const Json::Value & input)override
	{
		Json::Value root;
		Json::Value item = _subTransformer.Transform(input);
		root["interfaces"].append(item);
		return root;
	}

private:
	DefualtTransformer _subTransformer;
};