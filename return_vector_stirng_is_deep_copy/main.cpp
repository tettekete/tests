//
//  main.cpp
//  return_vector_stirng_is_deep_copy
//
//  Created by H.Seo on 2015/06/19.
//  Copyright (c) 2015年 H.Seo. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

class MyClass
{
	std::vector<std::string> stringList;
public:
	MyClass(const std::vector<std::string>& _stringList)
	{
		stringList = _stringList;
	}
	
	const std::vector<std::string>& getStringList() const
	{
		return stringList;
	}
	
	void description()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		for(auto ite = stringList.begin();ite<stringList.end();ite++)
		{
			std::cout << *ite << std::endl;
		}
	}
};

int main(int argc, const char * argv[]) {
	// insert code here...
	
	std::vector<std::string> source({"q","w","e","r","t","y","u","i","o","p"});
	MyClass theStringList( source );
	
	theStringList.description();
	
	std::vector<std::string> strList = theStringList.getStringList();
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	for(auto ite = strList.begin();ite<strList.end();ite++)
	{
		(*ite).append("a");
		std::cout << *ite << std::endl;
	}
	
	theStringList.description();
	
    return 0;
	
	/** 結果
	 void MyClass::description()
	 q
	 w
	 e
	 r
	 t
	 y
	 u
	 i
	 o
	 p
	 int main(int, const char **)
	 qa
	 wa
	 ea
	 ra
	 ta
	 ya
	 ua
	 ia
	 oa
	 pa
	 void MyClass::description()
	 q
	 w
	 e
	 r
	 t
	 y
	 u
	 i
	 o
	 p
	 Program ended with exit code: 0	 */
}
