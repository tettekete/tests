//
//  main.cpp
//  std_string_copy_or_assign
//
//  Created by H.Seo on 2015/04/21.
//  Copyright (c) 2015年 H.Seo. All rights reserved.
//

#include <iostream>
#include <string>

/** std::string のコピー渡しになるのかどうかテスト
 基本的にコピーコンストラクタが働くパターンでコピーされるはずだが、実際の所どうなのか
 
 */



int main(int argc, const char * argv[])
{
	// insert code here...
//	std::cout << "Hello, World!\n";
	
	std::string a;// デフォルトコンストラクタ呼び出し
	std::cout << "a:" << a << std::endl;
	
	a += "a";
	std::cout << "a+='a':" << a << std::endl;
	std::string b = a;// これはコピーコンストラクタ
	a += "b";
	std::cout << "b:" << b << std::endl;
	
	std::string c;
	c = a;	// 代入、つまり `operator=`
	
	a += "c";
	std::cout << "c:" << c << std::endl;
	std::cout << "a:" << a << std::endl;
	
    return 0;
}

/* 結果
 a:
 a+='a':a
 b:a
 c:ab
 a:abc
 */
