//
//  main.cpp
//  return_is_const_vector_char_ref_the_copy
//
//  Created by H.Seo on 2015/07/03.
//  Copyright (c) 2015年 H.Seo. All rights reserved.
//

#include <iostream>
#include <memory>
#include <vector>

/** あるクラスの vector<char> メンバーアクセサを read_only で提供するには
 
 const vector<char>& hogehoge();
 
 で良いのかテスト
 
 */


class MyClass
{
	std::vector<char> bytes_;
public:
	MyClass(const char* bytes ,size_t size)
	{
		for (uint offset=0; offset<size; offset++)
		{
			bytes_.push_back(*(bytes + offset));
		}
	}
	
	void appendByte( const char byte )
	{
		bytes_.push_back( byte );
	}
	unsigned long appendBytes( std::vector<char>& bytes )
	{
		unsigned long count = 0;
		for (auto ite = bytes.begin(); ite<bytes.end(); ite++)
		{
			bytes_.push_back(*ite);
			count++;
		}
		
		return count;
	}
	
	const std::vector<char>& getBytes()
	{
		return bytes_;
	}
};

int main(int argc, const char * argv[])
{
	const char defaultBytes[] = {0x61,0x62,0x63};
	std::unique_ptr<MyClass> byteBuffer(new MyClass( defaultBytes, sizeof(defaultBytes) ));
	
//	std::vector<char> current = byteBuffer->getBytes();// この時点でコピーになる。const std::vector<char>& で受ければ実際にリファレンスになると思われる。
	const std::vector<char>& current = byteBuffer->getBytes();
	
	byteBuffer->appendByte(0x64);
	
	for(auto ite=current.begin();ite<current.end();ite++)
	{
		std::cout << std::hex << (unsigned short)*ite << " ";
	}
	std::cout << std::endl;
	
    return 0;
}
