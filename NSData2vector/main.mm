//
//  main.m
//  NSData2vector
//
//  Created by H.Seo on 2015/06/22.
//  Copyright (c) 2015年 H.Seo. All rights reserved.
//

#import <Foundation/Foundation.h>

#include <vector>

/** NSData から vector<char> を作成するテスト
 
 イテレータ使ったvector のコンストラクタ使う方式でやろうとしたがイマイチよく分からず断念。
 普通にポインタループで push_back した
 
 出来れば
 - vector<char> -> NSData
 - vector<char> -> NSString
 とかも。
 
 */

class NSDataCharVecIterator :public std::iterator<std::input_iterator_tag, char>
{
	char *ptr;
	unsigned long len;
	NSDataCharVecIterator();
public:
	NSDataCharVecIterator(char* x,unsigned long len)
	:ptr(x)
	,len(len)
	{}
	
	NSDataCharVecIterator(const NSDataCharVecIterator& mit)
	: ptr(mit.ptr)
	,len(mit.len)
	{}
	
	NSDataCharVecIterator& operator++()
	{
		++ptr;return *this;
	}
	
	NSDataCharVecIterator operator++(int)
	{
		NSDataCharVecIterator tmp(*this);
		operator++();
		return tmp;
	}
	
	bool operator==(const NSDataCharVecIterator& rhs)
	{
		return ptr == rhs.ptr;
	}
	bool operator!=(const NSDataCharVecIterator& rhs)
	{
		return ptr!=rhs.ptr;
	}
	
	char& operator*()
	{
		return *ptr;
	}
};

void test1()
{
	
	NSString* str = @"ほげほげはなもげら";
	NSData *data = [str dataUsingEncoding:NSUTF8StringEncoding];
	
	char *ptr = (char*)data.bytes;
	NSUInteger size = data.length;
	
	std::vector<char> charVec;
	for(char *p=ptr;p<(ptr+size);p++)
	{
		charVec.push_back(*p);
	}
	
	NSLog(@"hoge");
}

int main(int argc, const char * argv[]) {
	@autoreleasepool
	{
		test1();
	}
    return 0;
}
