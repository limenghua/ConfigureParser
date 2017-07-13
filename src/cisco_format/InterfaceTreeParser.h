/******************************************************************* 
 *  Copyright(c) 2010-2017 Nethead
 *  All rights reserved. 
 *   
 *  �ļ�����: InterfaceTreeParser.h
 *  ��Ҫ����: 
 *   
 *  ��ǰ�汾: 
 *  ����: limenghua
 *  ����: 5/2/2017
 *  ˵��: ����configure��interface���ݶ�
 *	Example��
 *
 *	!
 *	interface Serial1/1
 *		ip address 158.4.255.66 255.255.255.252
 *		serial restart-delay 0
 *	!
 ******************************************************************/
#pragma once

#include "SimpleKeyValueParser.h"

class InterfaceTreeParser :public SimpleKeyValueTreeParser
{
public:
	InterfaceTreeParser() :
		SimpleKeyValueTreeParser("interface")
	{
		AddSubParser(new SimpleKeyValueTreeParser("ip address"));
		AddSubParser(new SimpleKeyValueTreeParser("serial restart-delay"));
		AddSubParser(new SimpleKeyValueTreeParser("security-level"));
		AddSubParser(new SimpleKeyValueTreeParser("nameif"));
		AddSubParser(new SimpleKeyValueTreeParser("management-only","true"));
		AddSubParser(new SimpleKeyValueTreeParser("encapsulation"));
		AddSubParser(new SimpleKeyValueTreeParser("shutdown", "true"));
	}

	~InterfaceTreeParser()
	{
		for (auto & parser : _subParsers)
		{
			delete parser;
		}
		_subParsers.clear();
	}

};