/******************************************************************* 
 *  Copyright(c) 2010-2017 Netbrain
 *  All rights reserved. 
 *   
 *  �ļ�����: ParseConfigToSentenceTree.cpp
 *  ��Ҫ����: 
 *   
 *  ��ǰ�汾: 
 *  ����: limenghua
 *  ����: 4/26/2017
 *  ˵��:  
 *
 ******************************************************************/

#include "ParserUtil.h"
#include "SentenceTree.h"
#include <stack>
#include <sstream>

/** 
* @brief ���������н�����SentenceTree�ṹ
* @param in  ������
* @param tree  �����tree �ṹ
*
* @ �����ʽʾ��:

!
hostname ASA-3
domain-name wr
enable password eiy0l2ZClzJ5k8ZD encrypted
passwd eiy0l2ZClzJ5k8ZD encrypted
names
!
interface out
	nameif outside
	security-level 0
	ip address 172.26.10.10 255.255.255.0 standby 172.26.10.20
!
interface inside
	nameif inside
	security-level 0
	ip address 172.26.7.10 255.255.255.0 standby 172.26.7.20
!
interface manage
	management-only
	nameif mgt
	security-level 100
	ip address 172.24.101.47 255.255.255.0 standby 172.24.101.41
!
* 
*/

void ParseConfigToSentenceTree(std::istream & in, SentenceTree & tree)
{
	typedef std::pair<std::string, SentenceTree*> ParseStackItem;
	std::stack<ParseStackItem> stack;

	stack.push(ParseStackItem("", &tree));

	while (!in.eof())
	{
		std::string strLine;
		std::getline(in, strLine);

		strLine = EraseCommentUseExclamatory(strLine);
		if (strLine.empty())continue;

		std::string strPrefix;
		std::string strCmd;

		SplitPrefixSpaces(strLine, strPrefix, strCmd);

		if (strCmd.empty())continue;

		//because root prefix is empty string,his child at least has one charact.
		strPrefix = " " + strPrefix;

		while (!stack.empty())
		{
			std::string & strLastPrefix = stack.top().first;
			int comparseRes = PrefixCompare(strPrefix, strLastPrefix);

			//it is child of last object
			if (comparseRes > 0) break;

			stack.pop();
		}

		SentenceTree * lastTree = stack.top().second;
		SentenceTree & nextTree = lastTree->AddChild(strCmd);

		stack.push(ParseStackItem(strPrefix, &nextTree));
	}
}

void ParseConfigToSentenceTree(const std::string & strContent, SentenceTree & tree)
{
	std::stringstream ss(strContent);
	ParseConfigToSentenceTree(ss, tree);
}