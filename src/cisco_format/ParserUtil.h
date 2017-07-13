/******************************************************************* 
 *  Copyright(c) 2010-2017 Nethead
 *  All rights reserved. 
 *   
 *  �ļ�����: ParserUtil.h
 *  ��Ҫ����: 
 *   
 *  ��ǰ�汾: 
 *  ����: limenghua
 *  ����: 4/25/2017
 *  ˵��:  
 *
 ******************************************************************/
#pragma once

#include <string>
#include <vector>

/** 
* @brief :��һ��Cisco configure�����в��Ϊ�ո�ǰ׺��ʵ������������
* @param :content [in] ��Ҫ��ֵ�ԭʼ���ݣ����룬ֻ�� 
* @param :prefix [out] ��ֺ��ǰ���ո񣨰���Table"\t"�� 
* @param :cmd [out] ��ֺ��ȥǰ���ո��ʣ�ಿ���ַ�
*
* @example :
* 	const std::string content = "  no ip domain lookup";
*   std::string strPrefix;
*   std::string strCmd;
*   SplitPrefixSpaces(content, strPrefix, strCmd);
*   //result: strPrefix shoud be "  ",strCmd should be "no ip domain lookup"
*/
void SplitPrefixSpaces(const std::string & content, std::string & prefix, std::string & cmd);

/** 
* @brief �Ƚ�����ֻ�����ո����ַ�ǰ׺���Ĵ�С������ȷ������ʱ���ĸ��Ӱ�����ϵ
* @param strSource �Ƚϵ�Դ�ַ���
* @param strDes �Ƚϵ�Ŀ���ַ���
*
* @return 1��strSource����strDest, -1:strDest����strSource, 0:����ǰ׺��ȫ���
* @throw std::exeption ,when ����ǰ׺�˴˲������ֲ����
* 
*/
int PrefixCompare(const std::string & strSource, const std::string & strDest);

/** 
* @brief ȥ��ע���ı���ע����!�ſ�ʼ�������з�����
* @param strContent �������ı� 
*
* @return ȥ��ע�ͺ���ı�
* 
* @example:
*   string strRes = EraseCommentUseExclamatory("!this is comment");
*	assert(strRes == "");
*	strRes = EraseCommentUseExclamatory("version 15.2!this is comment");
*	assert(strRes == "version 15.2");
*	strRes = EraseCommentUseExclamatory("version 15.2");
*	assert(strRes == "version 15.2");
*/
std::string EraseCommentUseExclamatory(const std::string & strContent);

/** 
* @brief ȥ���ַ���ǰ�󵼿ո��tab
* @param str �����ַ���
*
* @return ȥ��ǰ�󵼿ո����ַ���
* 
* 
*/
std::string Trim(const std::string & str);

/** 
* @brief ʹ�ÿո�ָ��
* @param str �����ַ���
* @param words �ָ����������.
*
*  
* 
*/
void SplitWords(const std::string & str, std::vector<std::string> & words);