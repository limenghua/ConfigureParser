/*******************************************************************
*  Copyright(c) 2010-2017 Netbrain
*  All rights reserved.
*
*  �ļ�����: configure_parser.h
*  ��Ҫ����:
*
*  ��ǰ�汾:
*  ����: limenghua
*  ����: 2017/05/07
*  ˵��:
*
******************************************************************/
#pragma once

#include <iostream>
#include "ConfigureParser/SentenceTree.h"

void ParseConfigToSentenceTree(std::istream & in, SentenceTree & tree);
void ParseConfigToSentenceTree(const std::string & strContent, SentenceTree & tree);


void ParseConfigToJson(std::istream & in, std::ostream & out);
void ParseConfigToJson(const std::string & strContent, std::string & strOutput);