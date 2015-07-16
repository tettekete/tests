//
//  main.cpp
//  what_is_std_wstring_encoding
//
//  Created by H.Seo on 2015/06/24.
//  Copyright (c) 2015年 H.Seo. All rights reserved.
//

#include <iostream>
#include <string>

int main(int argc, const char * argv[])
{
//	// insert code here...
//	std::cout << "Hello, World!\n";
	wchar_t wc[] = L"ほげほげ";
	std::string utf8Str(u8"もげもげ");
	
	// とりあえず utf8 な string の中身を表示
	std::cout << utf8Str << " - utf8Str" << std::endl;
	for (auto ite=utf8Str.begin() ; ite<utf8Str.end(); ite++)
	{
		printf("%02X ",*ite & 0xFF);// printf は32bitと見なす模様
	}
	std::cout << std::endl;
	std::cout << std::endl;

	
	// utf8 な string から wstring
	std::wstring wstrFromStr(utf8Str.begin(),utf8Str.end());
	std::cout << utf8Str << " - wstrFromStr" << std::endl;
	for (auto ite=wstrFromStr.begin() ; ite<wstrFromStr.end(); ite++)
	{
//		size_t iteSize = sizeof(*ite);// 4byte
		printf("%02X ",*ite & 0xffffffff);
	}
	std::cout << std::endl;
	std::cout << std::endl;
	
	/* 中身は
	 FFFFFFE3 FFFFFF82 FFFFFF82 FFFFFFE3 FFFFFF81 FFFFFF92 FFFFFFE3 FFFFFF82 FFFFFF82 FFFFFFE3 FFFFFF81 FFFFFF92
	 という感じになってしまう。これをもう一度 string にするとどうなるか
	 */
	
	std::string strFromWstrUtf8(wstrFromStr.begin(),wstrFromStr.end());
	std::cout << strFromWstrUtf8 << " - strFromWstrUtf8" << std::endl;
	for (auto ite=strFromWstrUtf8.begin() ; ite<strFromWstrUtf8.end(); ite++)
	{
//		size_t iteSize = sizeof(*ite);// 1byte
		printf("%02X ",(*ite) & 0xff);
	}
	std::cout << std::endl;
	std::cout << std::endl;
	
	/* E3 82 82 E3 81 92 E3 82 82 E3 81 92 
	 戻る。
	 */
	
	// んじゃ最初から wstring なのを str にするとどうなるか
	
//	std::string strFromWChar(wc ,sizeof(wc));	// wchar から string は簡単に作れないっぽい
	std::wstring wstrFromWChar(wc);
	
	std::cout << wc << " - wstrFromWChar" << std::endl;
	for (auto ite=wstrFromWChar.begin() ; ite<wstrFromWChar.end(); ite++)
	{
//		size_t iteSize = sizeof(*ite);// = 4
		printf("%02X ",*ite & 0xffffffff);
	}
	std::cout << std::endl;
	std::cout << std::endl;
	
	/*
	 307B 3052 307B 3052
	 */
	// これを string にする
	std::string strFromWstr(wstrFromWChar.begin(),wstrFromWChar.end());
	std::cout << strFromWstr << " - strFromWstr" << std::endl;
	for (auto ite=strFromWstr.begin() ; ite<strFromWstr.end(); ite++)
	{
//		size_t iteSize = sizeof(*ite);	// = 1
		printf("%02X ",*ite);
	}
	std::cout << std::endl;
	std::cout << std::endl;
	
	/* ↑この方法だと *ite が 1byte なのでアウト
	 そもそも wstring の begin()/end() で string 作っている時点で上位8bit が切り落とされる。
	 */
	const char* ptr = strFromWstr.data();
	std::cout << "strFromWstr.data() = " << strFromWstr.data() << std::endl;
	std::cout << "strFromWstr.size() = " << strFromWstr.size() << std::endl;
	
	
	
	
//	std::wstring wstr(L"ほげほげ");
//	std::wstring wstr(utf8Str.begin(),utf8Str.end());
//	
//	std::cout << &wstr << std::endl;
//	for (auto ite=wstr.begin() ; ite<wstr.end(); ite++)
//	{
//		printf("%02X ",*ite);
//	}
	
	std::cout << std::endl;
    return 0;
}
