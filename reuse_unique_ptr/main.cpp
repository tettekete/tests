//
//  main.cpp
//  reuse_unique_ptr
//
//  Created by H.Seo on 2015/07/14.
//  Copyright (c) 2015年 H.Seo. All rights reserved.
//

#include <iostream>
#include <memory>

/** 他のプロジェクトで unque_ptr 変数の宣言後に代入するやり方がコンパイラエラーになる
 ため、どう使うのが良いのかテストコード
 
 */

using namespace std;

class MyClass
{
	class Impl;
	unique_ptr<Impl> pimpl;
	
public:
	MyClass():pimpl(new Impl()){}
	
};


class MyClass::Impl
{
public:
	Impl(){}
};


int main(int argc, const char * argv[]) {
	
	unique_ptr<MyClass> myClass;
	if( myClass )
	{
		myClass.release();
	}
	
	myClass = unique_ptr<MyClass>(new MyClass());
	
    return 0;
}
