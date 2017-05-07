/*******************************************************************
*  Copyright(c) 2010-2017 Netbrain
*  All rights reserved.
*
*  �ļ�����: RootTransformer.h
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
#include "InterfaceTransformer.h"
#include <map>


class RootTransformer :public DefualtTransformer
{
public:
	RootTransformer()
	{
		_subTransforms["origin"] = new OriginTransformer();
		_subTransforms["interface"] = new InterfaceTransformer();
	}
	virtual ~RootTransformer()override
	{
		for (auto & item : _subTransforms)
		{
			delete item.second;
		}
		_subTransforms.clear();
	}

	virtual ITransformerPtr GetSubTransformer(const std::string & key)override
	{
		auto it = _subTransforms.find(key);
		if (it != _subTransforms.end())
		{
			return it->second;
		}
		else
		{
			return & _subTransformsDefualt;
		}
	}

	virtual Json::Value TransformSelf(const Json::Value & input)override
	{
		return Json::Value();
	}

private:
	std::map<std::string, ITransformerPtr> _subTransforms;
	DefualtTransformer _subTransformsDefualt;
};