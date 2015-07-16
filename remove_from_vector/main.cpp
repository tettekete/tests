//
//  main.cpp
//  remove_from_vector
//
//  Created by H.Seo on 2015/04/21.
//  Copyright (c) 2015年 H.Seo. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class MyClass
{
	int * intPtr;
public:
	MyClass():intPtr(new int(0)){}
	MyClass(int intValue):intPtr(new int(intValue)){}
	~MyClass()
	{
		std::cout << "~MyClass(" << *intPtr <<")" << std::endl;
		delete intPtr;
		intPtr = nullptr;
	}
	
	int intValue(void)
	{
		if( intPtr )
		{
			return *intPtr;
		}
		else
		{
			return -1;
		}
		
	}
};

/** vector::erase はデストラクタをコールするのかテスト 
 
 ポインタリスト版
 */

void doesVectorEraseCallDestructor_ptr()
{
	std::vector<MyClass*> list;
	for (int i = 0; i<10; i++)
	{
		list.push_back(new MyClass(i));
	}
	
	std::cout << "** Default list." << std::endl;
	for( auto ite = list.begin();ite != list.end();ite ++ )
	{
		MyClass *ptr = *ite;
		std::cout << ptr->intValue() << ",";
	}
	
	std::cout << std::endl;
	
	std::vector<MyClass*>::iterator it = list.begin();
	
	std::cout << "delete (*it) " << std::endl;
	delete (MyClass*)(*it);// erase はデストラクタを呼ばない & erase 後イテレータはインクリメントされてしまうので、erase 前に delete
	std::cout << "** vector.erase(begin)" << std::endl;
	list.erase(it);
	
	std::cout << "manual delete(erased from vector)" << std::endl;
	
	
	for( it = list.begin();it != list.end();it ++ )
	{
		MyClass *ptr = *it;
		std::cout << ptr->intValue() << std::endl;
	}
	
	std::cout << "vector.clear" << std::endl;
	list.clear();	// clear も特にデストラクタをコールしないので、メモリリークになる
}

/** vector::erase はデストラクタをコールするのかテスト
 
 スタック版
 */

void doesVectorEraseCallDestructor_stack()
{
	std::vector<MyClass> list;
	for (int i = 0; i<10; i++)
	{
		MyClass myclass(i);
		list.push_back(myclass);
		
		/* このブロックを抜ける時点で myclass のデストラクタがコールされる。
		 ので、次回以降の`list.push_back()`に vector 内部のイテレーションで
		 解放済みのオブジェクトに触ってしまい致命的エラーになる。
		*/
	}
	
	list.erase(list.begin());
	
	for(auto it = list.begin();it != list.end();it ++ )
	{
		std::cout << (*it).intValue() << std::endl;
	}
}


/** vector のリストから複数項目を削除するパターンのテスト */

void deleteListFromList()
{
	std::vector<std::string> strList =
	{
		"a", "b", "c","d","e","f","g","h","i","j","k","l","m","n"
	};
	
	std::vector<std::string> deleteTarget =
	{
		"b","d","f","h","j","l","n"
	};
	
	auto newEndIte = std::remove_if (strList.begin(), strList.end(), [=](std::string str)->bool
									 {
										 auto foundIte = std::find(deleteTarget.begin(), deleteTarget.end(), str);
										 if( foundIte != deleteTarget.end() )
										 {
											 return true;
										 }
										 return false;
									 });
	
	strList.erase(newEndIte,strList.end());// remove_if は実際に削除はせず、削除対象をリストの後方に移動する。削除処理は自分でやる
	
	for (auto ite = strList.begin(); ite != strList.end(); ++ ite)
	{
		std::cout << *ite << std::endl;
	}
	
	/** 結果
	 a
	 c
	 e
	 g
	 i
	 k
	 m
	 */
}


void trapOfRemoveIf()
{
	std::vector<MyClass*> list = {new MyClass(1),new MyClass(5),new MyClass(6),new MyClass(4),new MyClass(3),new MyClass(8)};
 
	auto invalidIt = std::remove_if(list.begin(),list.end(),[](MyClass* n)
	{
		return (*n).intValue() > 3;
	});// {1,3,6,4,3,8}
	
	for(auto it = invalidIt; it<list.end(); it++)
	{
		delete *it;// 後半に`3`があるので list[1] の指すポインタは無効なポインタになる。`5`は delete していないのでメモリリークになる。
		*it = nullptr;// この nullptr 代入はあくまでも vevtor 上の該当インデックス値を NULL にするだけなので list[1] のポインタ値自体は null にならない（解放済みメモリへのポインタだけど）。
	}
 
	list.erase(invalidIt,list.end());
	
	for(auto it = list.begin();it != list.end(); it ++)
	{
		std::cout << *it << ":" << (*it)->intValue() << std::endl;
	}
	
	/* 結果
	 ~MyClass(6)
	 ~MyClass(4)
	 ~MyClass(3)
	 ~MyClass(8)
	 0x1001042d0:1
	 0x100104350:-1		// << ここで解放済みポインタへのアクセスでエラーになりそうなんだけどならない。
	 Program ended with exit code: 0
	 */
}

void avoidTrapOfRemoveIf()
{
	std::vector<MyClass*> list = {new MyClass(1),new MyClass(5),new MyClass(6),new MyClass(4),new MyClass(3),new MyClass(8)};
	
	std::vector<MyClass*> actualDeleted;// 発見した削除対象を格納するための vector
	auto invalidIt = std::remove_if(list.begin(),list.end(),[&actualDeleted](MyClass* n)->bool
									{
										if( n->intValue() > 3 )
										{
											actualDeleted.push_back( n );
											return true;
										}
										else
										{
											return false;
										}
									});
	
	list.erase(invalidIt,list.end());
	
	for( auto it = actualDeleted.begin(); it != actualDeleted.end(); it ++)
	{
		delete *it;
		*it = nullptr;
	}
	
	for(auto it = list.begin();it != list.end(); it ++)
	{
		std::cout << *it << ":" << (*it)->intValue() << std::endl;
	}
	
	/* 結果
	 ~MyClass(5)
	 ~MyClass(6)
	 ~MyClass(4)
	 ~MyClass(8)
	 0x100104290:1
	 0x100104310:3
	 Program ended with exit code: 0
	 */
}


int main(int argc, const char * argv[])
{
//	while(1)
//	{
//		doesVectorEraseCallDestructor_ptr();
//	}
	
//	doesVectorEraseCallDestructor_stack();
	
//	trapOfRemoveIf();
	avoidTrapOfRemoveIf();
	
    return 0;
}

