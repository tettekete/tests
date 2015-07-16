//
//  main.cpp
//  bit_test
//
//  Created by H.Seo on 2015/04/22.
//  Copyright (c) 2015年 H.Seo. All rights reserved.
//

#include <iostream>
#include <arpa/inet.h>		// inet_addr


int main(int argc, const char * argv[]) {
	// insert code here...
	
	int bits = 1 << 2;
	
	std::cout << "bits:" << bits << std::endl;
	
	const char* ip_addr = "192.168.1.134";
	in_addr_t packedAddr = inet_addr(ip_addr);
	
//	in_addr_t intFromHex = 0xc0a80186;
	
	std::cout << packedAddr << std::endl;
	
	std::cout << (int)((unsigned char)(packedAddr >> 24)) << std::endl;
	std::cout << (int)((unsigned char)(packedAddr >> 16)) << std::endl;
	std::cout << (int)((unsigned char)(packedAddr >> 8)) << std::endl;
	std::cout << (int)((unsigned char)(packedAddr)) << std::endl;
	
    return 0;
}
