//
//  main.cpp
//  constructor_on_smart_ptr
//
//  Created by H.Seo on 2015/05/13.
//  Copyright (c) 2015年 H.Seo. All rights reserved.
//

#include <iostream>
#include <memory>
using std::shared_ptr;
using std::unique_ptr;


/** スマートポインタ変数の宣言式だけでコンストラクタは呼ばれるのかどうかテスト
 
 */

class MyClass
{
private:
	int* intPtr;
public:
	MyClass():intPtr(new int(0))
	{
		std::cout << "MyClass()" << std::endl;
	}
	MyClass(int intVal ):intPtr(new int( intVal ))
	{
		std::cout << "MyClass("<< intVal << ")" << std::endl;
	}
	~MyClass()
	{
		std::cout << "MyClass("<< *intPtr << ")" << std::endl;
		delete intPtr;
		intPtr = nullptr;
	}
	
	int intValue(void)
	{
		return intPtr ? *intPtr : -1;
	}
};


int main(int argc, const char * argv[])
{
	std::shared_ptr<MyClass> sharedMyclass;// MyClass のコンストラクタは呼ばれない。恐らく`std::shared_ptr`のデフォルトコンストラクタが呼び出されるのみ。
	std::unique_ptr<MyClass> uniqueMyclass;
	
    return 0;
}




