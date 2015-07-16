//
//  main.cpp
//  smart_ptr_derive_and_cast_and_virtual
//
//  Created by H.Seo on 2015/05/14.
//  Copyright (c) 2015年 H.Seo. All rights reserved.
//

#include <iostream>
#include <memory>
#include <vector>

/**
 
 派生クラスからスーパークラスへのキャストと virtual なメソッドの挙動テストのためのテストコード
 
 */

class MyBaseClass
{
public:
	virtual std::string myName(void)
	{
		return std::string("BaseClass");
	}
};

class MyDerivedClass : public MyBaseClass
{
public:
	virtual std::string myName(void)
	{
		return std::string("MyDerivedClass");
	}
};

void showNameProperty( const std::shared_ptr<MyBaseClass> obj )
{
	std::cout << obj->myName() << std::endl;
}


int main(int argc, const char * argv[])
{
	std::shared_ptr<MyBaseClass> base = std::make_shared<MyBaseClass>();
	std::shared_ptr<MyDerivedClass> derived = std::make_shared<MyDerivedClass>();
	std::shared_ptr<MyBaseClass> casted = std::dynamic_pointer_cast<MyBaseClass>(derived);
	
	std::vector<std::shared_ptr<MyBaseClass>> list;
	list.push_back(base);
	list.push_back(derived);
	list.push_back(casted);
	
	for(auto ite = list.begin();ite != list.end(); ite ++)
	{
		showNameProperty(*ite);
	}
	
    return 0;
}










