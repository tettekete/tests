//
//  main.cpp
//  std_unique_ptr
//
//  Created by H.Seo on 2015/04/22.
//  Copyright (c) 2015年 H.Seo. All rights reserved.
//

#include <iostream>
#include <memory>


/** std::unique_ptr の性質と使いどころがイマイチ分からないためテスト
 */

class MyClass
{
private:
	std::unique_ptr<int> ptr;
public:
	MyClass()
	:ptr(new int(0))
	{
		
	}
	MyClass(int val_)
	:ptr(new int(val_)){}
	int getValue() const
	{
		return *ptr;
	}
};

void func(MyClass &myclass)
{
	std::cout << "In function " << myclass.getValue() << std::endl;
}

void func2(MyClass *myclass )
{
	MyClass* hogePtr;
	hogePtr = myclass;
}

int main(int argc, const char * argv[])
{
	// insert code here...
//	std::cout << "Hello, World!\n";
	
	MyClass hoge(10);
	
//	MyClass hoge2(hoge); // コピーコンストラクタなのでコンパイラエラー
//	hoge2 = hoge;		// operator= は禁止なのでコンパイルエラー
	
	func(hoge);// 参照渡しなので問題ない。がこれはポインタ使った場合に比べ特別メリットがあるようには感じない。
	
	std::cout << hoge.getValue() << std::endl;
	
	func2(&hoge);
	
    return 0;
}
