//
//  main.cpp
//  what_is_explicit
//
//  Created by H.Seo on 2015/06/08.
//  Copyright (c) 2015年 H.Seo. All rights reserved.
//

#include <iostream>

/** クラスメソッドの定義などで見かける explicit とはなにか、どういうときに使うモノなのかテスト */


class MonoInt
{
	int *intPtr;
public:
	MonoInt(int i):intPtr(new int(i)){}
	~MonoInt()
	{
		delete intPtr;
		intPtr = nullptr;
	}
	
	int intValue(void)
	{
		return *intPtr;
	}
};

int main(int argc, const char * argv[])
{
	MonoInt obj1(1);
	MonoInt obj2 = 2;
	
	std::cout << "obj1.intValue = " << obj1.intValue() << std::endl;
	std::cout << "obj2.intValue = " << obj2.intValue() << std::endl;
	
    return 0;
}
