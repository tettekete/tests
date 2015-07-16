//
//  main.cpp
//  shared_ptr_after_new_and_delete
//
//  Created by H.Seo on 2015/05/11.
//  Copyright (c) 2015年 H.Seo. All rights reserved.
//

#include <iostream>
#include <memory>
using std::shared_ptr;

/** 後から std::shared_ptr したポインタのオリジナルを delete したらどうなるのテスト
 
 */

class MyClass
{
	int *_intPtr;
	float _flotValue;
public:
	MyClass()
	:_intPtr(nullptr)
	,_flotValue( 3.14 )
	{
		_intPtr = new int(0);
	}
	
	MyClass(int intVal )
	:_intPtr(nullptr)
	,_flotValue( 3.14 )
	{
		_intPtr = new int(intVal);
	}
	
	~MyClass()
	{
		if( _intPtr )
		{
			delete _intPtr;
			_intPtr = nullptr;
		}
	}
	
	/** コピーコンストラクタ */
	MyClass(const MyClass &myClass )
	:_intPtr(nullptr)
	{
		_intPtr = new int( *myClass._intPtr );
		_flotValue = myClass._flotValue;
	}
	
	/* 各メンバーアクセサ */
	int intValue(void)
	{
		return *_intPtr;
	}
	
	int intValue( int intVal )
	{
		*_intPtr = intVal;
		return intValue();
	}
	
	float floatValue(void)
	{
		return _flotValue;
	}
	
	float floatValue( float floatVal )
	{
		_flotValue = floatVal;
		return _flotValue;
	}
};

int main(int argc, const char * argv[])
{
	MyClass *ptr = new MyClass();
	
	std::shared_ptr<MyClass> shared_myClass(ptr);
	
	delete ptr;							// この時点でデストラクタがコールされるため MyClass._intPtr == nullptr になる。
	
	shared_myClass->intValue(65535);	// そうするとこのセッターメソッド内で代入先のポインタは nullptr になっているのでアウト
	
	std::cout << "shared_myClass->intValue() = "
	<< shared_myClass->intValue() << std::endl;
	
										/* ~MyClass で `delete _intPtr` しかしていない場合、この場所まで到達する。
										 しかし、このブロックを抜けようとした時にスマートポインタのデストラクタで
										 alloc されていないメモリを解放しようとするのでエラーとなる
										 */
	
    return 0;
}
