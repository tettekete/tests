//
//  main.m
//  tests
//
//  Created by 瀬尾 広道 on 2013/02/27.
//  Copyright (c) 2013年 H.Seo. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[])
{

	@autoreleasepool
	{
	    // 符号付き(付かなくてみ良いけど）整数型が取れる最大値ってどうやって計算すんの？的な
		int algoType = 2;
		switch (algoType) {
			case 0:
			{
				// まじめに 1ビットずつ埋めてく方法
				SInt32 maxOfSint32 = 0x00;
				int bits = sizeof(SInt32) * 8 ;
				while (--bits)
				{
					maxOfSint32 = maxOfSint32 << 1 | 1;
				}
				
				NSLog(@"maxOfSint32 = %d",maxOfSint32);
				break;
			}
				
			case 1:
			{
				/* 大体 sizeof で取れるのがバイトなんだから memset で良くね？って方法*/
				SInt32 maxOfSint32 = 0x00;
				SInt32 *ptr = &maxOfSint32;
				int bytes = sizeof(SInt32);
				memset(ptr, 0xff, bytes);
				maxOfSint32 = maxOfSint32 >> 1;				// 右シフトはもしかしてローテイトするのか -1 になってしまう。デバッガでメモリ見ても 0x FF FF FF FF のまま
				NSLog(@"maxOfSint32 = %d",maxOfSint32);
				break;
			}
				
			case 2:
			{
				// ネットで拾ったコード
				SInt32 maxOfSint32;
				NSLog(@"sizeof(SInt32)*8-1 = %ld",sizeof(SInt32)*8-1);
				NSLog(@"1<<(sizeof(SInt32)*8-1) = %d [0x%x]",1<<(sizeof(SInt32)*8-1),1<<(sizeof(SInt32)*8-1));
				maxOfSint32 = (1<<(sizeof(SInt32)*8-1))-1;	// 0x7F を導き出すために 0x80 を作って 1 引いている。アリなのか？
				NSLog(@"maxOfSint32 = %d [0x%x]",maxOfSint32,maxOfSint32);
			}
				
			default:
				break;
		}
	}
    return 0;
}

