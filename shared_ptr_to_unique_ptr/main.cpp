//
//  main.cpp
//  shared_ptr_to_unique_ptr
//
//  Created by H.Seo on 2015/07/14.
//  Copyright (c) 2015年 H.Seo. All rights reserved.
//

#include <iostream>
#include <memory>

/** shared_ptr から unique_ptr への move に問題は無いのか。
 
 */

using namespace std;

class MyClass
{
	int i;
public:
	MyClass():i(0){}
	~MyClass()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

int main(int argc, const char * argv[])
{
	unique_ptr<MyClass> uniqueMyClass;
	{
		shared_ptr<MyClass> myClass = make_shared<MyClass>();
		cout << "Inner block." << endl;
		uniqueMyClass = move(myClass);
	}
	cout << "Outer block." << endl;
	
    return 0;
}
