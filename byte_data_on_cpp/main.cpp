//
//  main.cpp
//  byte_data_on_cpp
//
//  Created by H.Seo on 2015/06/08.
//  Copyright (c) 2015年 H.Seo. All rights reserved.
//

#include <iostream>
#include <string>
#include <array>

//typedef struct byte
//{
//	unsigned char* data;
//	size_t size;
//} byte;

class ByteData
{
	char * data_;
	size_t size_;
protected:
	ByteData();
public:
	
	ByteData(const char * dataPtr , size_t size)
	{
		data_ = new char[size];
		size_ = size;
		
		memcpy(data_, dataPtr, size);
	}
	
	~ByteData()
	{
		std::cout << "Destructor of " << __PRETTY_FUNCTION__ << std::endl;
		delete[] data_;
		data_ = nullptr;
	}
	
	const char * data(void)
	{
		return data_;
	}
	
	size_t size(void)
	{
		return size_;
	}
};

class MyClass
{
	std::string str_;
protected:
	MyClass():str_(""){}
public:
	MyClass(std::string inStr)
	:str_(inStr){}
	
	const ByteData getBytes()
	{
		ByteData bytes(str_.data() ,str_.size());
		
		return bytes;
	}
	
	const char* getBytePtr()
	{
		return str_.data();
	}
	
	const std::string& string()
	{
		return str_;
	}
};

void testFunc()
{
	
	MyClass myStr("hogehogehoge");
	
	ByteData bytes = myStr.getBytes();
	
	std::cout << "myStr.bytes.data = " << bytes.data() << std::endl;
	
	std::cout << "sizeof(myStr.getBytePtr()) = " << sizeof(myStr.getBytePtr()) << std::endl;
	
	std::cout << "myStr = " << myStr.string() << std::endl;
}

int main(int argc, const char * argv[]) {
	
	testFunc();
	
    return 0;
}
