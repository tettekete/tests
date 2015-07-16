//
//  main.cpp
//  test_smartPointer
//
//  Created by H.Seo on 2015/04/15.
//  Copyright (c) 2015年 H.Seo. All rights reserved.
//

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>	// std::copy
#include <iterator>     // std::back_inserter

using std::shared_ptr;
using std::unique_ptr;
using std::weak_ptr;

class MyObject;

class MyManagerClass
{
private:
	std::vector<std::shared_ptr<MyObject>> objList;
	
public:
	MyManagerClass()
	:objList(std::vector<std::shared_ptr<MyObject>>())
	{
	}
	
	~MyManagerClass()
	{
		objList.clear();
	}
	
	void addObject(std::shared_ptr<MyObject>& myObj)
	{
		objList.push_back( myObj );
	}
	
	std::vector<std::shared_ptr<MyObject>> getSharedList()
	{
		std::vector<std::shared_ptr<MyObject>> duplicate;
		std::copy(objList.begin(), objList.end(), std::back_inserter(duplicate) );
		return duplicate;
	}
	
};

class MyBaseObject
{
	
};

class MyObject :public MyBaseObject
{
private:
	unsigned int _getIndex()
	{
		static unsigned int counter = 0;
		return ++counter;
	}
	
	unsigned int _myIndex;
	
public:
	std::string name;
	MyObject()
	:name("no-name")
	,_myIndex(_getIndex())
	{}
	
	MyObject(const char* name_)
	:name(name_)
	{}
	
	~MyObject(){};
	
};


void basicVectorSample()
{
	std::vector<int> nsList{1,3,5,7,9};	// C++11 以降可能な初期化書式
	for(std::vector<int>::iterator ite = nsList.begin(); ite != nsList.end(); ++ite)
	{
		int value = *ite;
		std::cout <<  value << std::endl;
	}
}

void otherSample()
{
	
	std::unique_ptr<MyManagerClass> man(new MyManagerClass());
	
	std::shared_ptr<MyObject> obj = std::make_shared<MyObject>();
	
	MyBaseObject *isInheritedBase = dynamic_cast<MyBaseObject*>(obj.get());
	if( isInheritedBase )
	{
		// obj は MyBaseObject を継承している
	}
	
	
//	MyClass instance;
//	
//	instance.addIndex(1);
//	instance.addIndex(3);
//	instance.addIndex(5);
//	instance.addIndex(7);
//	instance.addIndex(11);
//	
//	std::shared_ptr<std::vector<int>> sharedList = instance.getSharedList();
//	for(auto ite = sharedList->begin(); ite != sharedList->end(); ++ite)
//	{
//		std::cout << *ite << std::endl;
//	}

}

int main(int argc, const char * argv[])
{
	//	basicVectorSample();
	
	
    return 0;
}
