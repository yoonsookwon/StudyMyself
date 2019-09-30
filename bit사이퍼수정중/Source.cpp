/* Start Header --------------------------------------------------------------
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: cipher.cpp
Purpose: Source file for bit cipher assignment
Project:  CS225/ bitciper
Author: yoonsoo.kwon
Creation date: 18/SEP/2019
- End Header ----------------------------------------------------------------
*/
#include <vector> //To use vector
#include <string> //To use string
#include  "cipher.h" //To define the functions

namespace {
	const char make_1bit = 7;
	const char make_2bit = 6;
	const char make_3bit = 5;
	const char make_4bit = 4;
	const char make_5bit = 3;
	const char make_6bit = 2;
	
	const char bit_size8 = 8;
	const int GROUP_1 = 0;
	const int GROUP_2 = 1;
	const int GROUP_3 = 2;
	const int GROUP_4 = 3;
	
	const int USED_GROUP_1 = 1;
	const int USED_GROUP_2 = 2;
	const int USED_GROUP_3 = 3;
	const int USED_GROUP_4 = 4;
	
	const int NUMGROUPS = 4;
	std::string groups[NUMGROUPS] = { " e", "taoi", "nshrdlcu", "mwfgypbvkjxqz" };
}
//Helper
void Make_ResultBit_By_Case(int theCase, int& remainBit, unsigned char& resultBit,
	unsigned char group_letterBit , unsigned char& saveBit,std::vector<char>& encodeText)
{
	if (remainBit <= 0) {
		resultBit = char((group_letterBit) >> (bit_size8 - (remainBit + theCase)));
		resultBit = saveBit | resultBit;
		encodeText.push_back(resultBit);
		saveBit = char((group_letterBit) << (remainBit + theCase));
		remainBit += bit_size8;
	}
	else {
		resultBit = char((group_letterBit) >> (bit_size8 - (remainBit + theCase)));
		saveBit = saveBit | resultBit;
	}
}
//Helper
void EncryptHelper(const int _groupCount, const unsigned char _letterCount, const int uncompressedNum, int& remainBit, unsigned char& saveBit, std::vector<char>& encodeText, std::string uncompressed)
{
	unsigned char groupBit = char(_groupCount);
	unsigned char letterBit = _letterCount;
	unsigned char resultBit = 0;

	switch (_groupCount)
	{
	case GROUP_1:
		groupBit = char(groupBit << make_2bit);
		letterBit = char(letterBit << make_3bit);
		remainBit -= make_5bit;
		Make_ResultBit_By_Case(make_5bit, remainBit, resultBit, groupBit | letterBit, saveBit, encodeText);
		break;
	case GROUP_2:
		groupBit = char(groupBit << make_2bit);
		letterBit = char(letterBit << make_4bit);
		remainBit -= make_4bit;
		Make_ResultBit_By_Case(make_4bit, remainBit, resultBit, groupBit | letterBit, saveBit, encodeText);
		break;
	case GROUP_3:
		groupBit = char(groupBit << make_2bit);
		letterBit = char(letterBit << make_5bit);
		remainBit -= make_3bit;
		Make_ResultBit_By_Case(make_3bit, remainBit, resultBit, groupBit | letterBit, saveBit, encodeText);
		break;
	case GROUP_4:
		groupBit = char(groupBit << make_2bit);
		letterBit = char(letterBit << make_6bit);
		remainBit -= make_2bit;
		Make_ResultBit_By_Case(make_2bit, remainBit, resultBit, groupBit | letterBit, saveBit, encodeText);
		break;
	}
	if (uncompressed.size() - uncompressedNum == 1) {
		encodeText.push_back(saveBit);
	}
}
std::vector<char> encode(std::string uncompressed)
{
	std::vector<char> encodeText;
	int remainBit = bit_size8;
	unsigned char resultBit = 0;

	for (unsigned int uncompressedNum = 0; uncompressedNum < uncompressed.size(); uncompressedNum++)
	{
		for (int groupCount = 0; groupCount < NUMGROUPS; groupCount++)
		{
			//unsigned int groupIndexNum = 
			for (unsigned int letterCount = 0; letterCount < groups[groupCount].size(); letterCount++)
			{
				
				if (uncompressed.at(uncompressedNum) == groups[groupCount].at(letterCount))
				{
					EncryptHelper(groupCount, char(letterCount), uncompressedNum, remainBit, resultBit, encodeText, uncompressed);
				}
			}
		}
	}
	return encodeText;
}

void DecodeHelper(const int _theCase,const int _bitCase ,unsigned char &_saveBit, unsigned char &_originalByte,int &_usedBit, int &_index,
	unsigned char& _letterBit, std::vector<char> _compressed)
{
	_saveBit = char(_originalByte << (_usedBit - _theCase));
	_index++;

	_originalByte = _compressed.at(_index);
	_saveBit = char(_saveBit | (_originalByte >> (bit_size8 - (_usedBit - _theCase))));
	_letterBit = char(_saveBit >> _bitCase);
	_usedBit -= bit_size8;
}

std::string decode(std::vector<char> compressed)
{
	std::string decodedStr;
	int usedBit = 0;
	unsigned char groupBit = 0;
	unsigned char letterBit = 0;
	unsigned char groupBit2 = 0;
	unsigned char letterBit2 = 0;
	unsigned char saveBit = 1;
	unsigned char originalByte = 0;

	int index = 0;
	originalByte = compressed.at(index);

	while (index != int(compressed.size()))
	{
		//Group bit
		groupBit = char(static_cast<unsigned char>(originalByte << usedBit) >> make_2bit);
		usedBit += make_6bit;
		
		if (usedBit >= bit_size8)
		{
			saveBit = char(originalByte << (usedBit - make_6bit));
			index++;
			originalByte = compressed.at(index);
			saveBit = char(saveBit | (originalByte >> (bit_size8 - (usedBit - make_6bit))));
			groupBit = char(saveBit >> make_2bit);
			usedBit -= bit_size8;
		}
		if (groupBit == GROUP_1) {
			letterBit = char(static_cast<unsigned char>(originalByte << usedBit) >> make_1bit);
			usedBit += USED_GROUP_1;
			if (usedBit > bit_size8)
			{
				DecodeHelper(USED_GROUP_1, make_1bit, saveBit, originalByte, usedBit, index, letterBit, compressed);
			}
		}
		else if (groupBit == GROUP_2)
		{
			letterBit = char(static_cast<unsigned char>(originalByte << usedBit) >> make_2bit);
			usedBit += USED_GROUP_2;
			if (usedBit > bit_size8)
			{
				DecodeHelper(USED_GROUP_2, make_2bit, saveBit, originalByte, usedBit, index, letterBit, compressed);
	
			}
		}
		else if (groupBit == GROUP_3)
		{
			letterBit = char(static_cast<unsigned char>(originalByte << usedBit) >> make_3bit);
			usedBit += USED_GROUP_3;
			if (usedBit > bit_size8)
			{
				DecodeHelper(USED_GROUP_3, make_3bit, saveBit, originalByte, usedBit, index, letterBit, compressed);
		    }
		}
		else if (groupBit == GROUP_4)
		{
			letterBit = char(static_cast<unsigned char>(originalByte << usedBit) >> make_4bit);
			usedBit += USED_GROUP_4;

			if (usedBit > bit_size8)
			{
				DecodeHelper(USED_GROUP_4, make_4bit, saveBit, originalByte, usedBit, index, letterBit, compressed);
			}
		}
		/*if (compressed.size() == 1) {
			decodedStr.push_back(groups[groupBit].at(letterBit));
			return decodedStr;
		}*/
		if (index + 1 == int(compressed.size()))
		{
			groupBit2 = char(static_cast<unsigned char>(originalByte << usedBit) >> make_2bit);
			usedBit += make_6bit;

			if (groupBit2 == GROUP_1) {
				letterBit2 = char(static_cast<unsigned char>(originalByte << usedBit) >> make_1bit);
				usedBit += USED_GROUP_1;
			}
			else if (groupBit2 == GROUP_2) {
				letterBit2 = char(static_cast<unsigned char>(originalByte << usedBit) >> make_2bit);
				usedBit += USED_GROUP_2;
			}
			else if (groupBit2 == GROUP_3) {
				letterBit2 = char(static_cast<unsigned char>(originalByte << usedBit) >> make_3bit);
				usedBit += USED_GROUP_3;
			}
			else if (groupBit2 == GROUP_4) {
				letterBit2 = char(static_cast<unsigned char>(originalByte << usedBit) >> make_4bit);
				usedBit += USED_GROUP_4;
			}
			decodedStr.push_back(groups[groupBit].at(letterBit));
			decodedStr.push_back(groups[groupBit2].at(letterBit2));
			return decodedStr;
			saveBit = char(static_cast<unsigned char>(saveBit << usedBit) >> usedBit);
		}
		decodedStr.push_back(groups[groupBit].at(letterBit));
	}
	return decodedStr;
}
