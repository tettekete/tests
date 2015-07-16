//
//  main.cpp
//  byte_data_with_vector_and_string
//
//  Created by H.Seo on 2015/06/10.
//  Copyright (c) 2015年 H.Seo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

/** 文字列(string)やバイト(char)を vector<char>に格納してバイト列として扱うテスト
 
 - UTF-8 なバイト列 char[] はどうやって string につっこむんだ？
 */

std::vector<char> joinVector(const std::vector<std::string> &sourceList,const std::string& delimiter)
{
	std::vector<char> joind;
	for(auto ite=sourceList.begin(); ite<sourceList.end(); ite++)
	{
		for(auto inValueIte=(*ite).begin();inValueIte < (*ite).end();inValueIte ++)
		{
//			char byte = *inValueIte;
			joind.push_back(*inValueIte);
		}
		
		// デリミタ挿入
		if( ite != sourceList.end() - 1 )
		{
			for(auto dIte = delimiter.begin();dIte<delimiter.end();dIte++)
			{
//				char byte = *dIte;
				joind.push_back(*dIte);
			}
		}
	}
	
	return std::move(joind);
}



int main(int argc, const char * argv[]) {
	// 各種タイプのデータセットアップ
	char delimiter = 0x20;
	std::string commandStr("MyCommand");
	std::vector<std::string> paramList = {"param1","param2","param3"};
	char byteSharp = 0x23;	//"#"
	char utf8char[] = u8"ほげほげ";
	
	
	// バイト列作る？
	std::vector<std::string> fieldValues;
	fieldValues.push_back(commandStr);
	fieldValues.push_back(std::string(&byteSharp,sizeof(byteSharp)));
	
	for(auto ite=paramList.begin();ite<paramList.end();ite++)
	{
		fieldValues.push_back(*ite);
	}
	
	fieldValues.push_back(std::string(utf8char));
	std::string delimiterString(&delimiter ,sizeof(delimiter));
	std::vector<char> joined = joinVector(fieldValues , delimiterString);
	
	char * ptr = joined.data();
	size_t len = joined.size();
	for(int i=0;i<len;i++)
	{
//		unsigned char hexValue = *ptr;
//		printf("%02X ",hexValue);
		
		printf("%02X ",(unsigned char)*ptr);
		
		ptr ++;
	}
	
	
    return 0;
}
