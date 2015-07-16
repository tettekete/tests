//
//  main.cpp
//  shared_ptr_nullptr_decrement
//
//  Created by H.Seo on 2015/07/07.
//  Copyright (c) 2015年 H.Seo. All rights reserved.
//

#include <iostream>
#include <memory>

/** shared_ptr な変数に nullptr 代入で参照カウントは減るのかどうか。
 
 */

int main(int argc, const char * argv[])
{
	std::shared_ptr<int> one = std::make_shared<int>(10);
	std::shared_ptr<int> two = one;
	
	std::cout << "use_count(one is not null):" << two.use_count() << std::endl;
	
	one = nullptr;
	
	std::cout << "use_count:" << two.use_count() << std::endl;
	
    return 0;
}

/** 結果
 use_count(one is not null):2
 use_count:1
 Program ended with exit code: 0
 */
