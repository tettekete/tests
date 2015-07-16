//
//  main.cpp
//  constructorExpection_And_StackVar
//
//  Created by H.Seo on 2015/04/24.
//  Copyright (c) 2015年 H.Seo. All rights reserved.
//

#include <iostream>
#include <stdexcept>


/** コンストラクタに throw 宣言されている場合、スタック変数定義方式でコンストラクタ呼び出したときも try{}catch{}しないのとダメなの？
 & そしたら try{}スコープの中でしかスタック変数で使えないけどそういうモノなのか？
 
 */

class MyException : public std::exception
{
	
public:
	int code;
	
	MyException():code(0)
	{
		
	}
	MyException(int _type)
	:code(_type)
	{
	};
	~MyException(){};
};

class MyClass
{
public:
	MyClass() throw(MyException)
	{
		throw MyException(10);
	}
	
	~MyClass()
	{
		
	}
};

int main(int argc, const char * argv[])
{
	
	try
	{
		MyClass myClass;
	}
	catch (MyException me)
	{
		std::cout << "Catch exception " << me.code << std::endl;
	}
	
    return 0;
}
