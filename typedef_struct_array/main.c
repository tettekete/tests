//
//  main.c
//  typedef_struct_array
//
//  Created by H.Seo on 2015/05/25.
//  Copyright (c) 2015年 H.Seo. All rights reserved.
//

#include <stdio.h>

#define TARGET_ARRAY_SIZE 16
#define FILTER_ARRAY_SIZE 16

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


typedef struct conmon_info conmon_info_t;

struct conmon_info
{
	// conmon connectivity
	struct conmon_target
	{
		const char * name;
	} targets [TARGET_ARRAY_SIZE];
	
	struct message_filter
	{
		int mtype;
	} filter [FILTER_ARRAY_SIZE];
	
	struct conmon_info_raw
	{
		unsigned n_filters;
		struct message_filter filter[FILTER_ARRAY_SIZE];
	} raw;
};

typedef struct conmon_target cm_target_t;

int main(int argc, const char * argv[]) {
	
	struct conmon_target * cnmTarget;
	conmon_info_t foo;
	conmon_info_t *fooPtr = &foo;
	
	
	cnmTarget = fooPtr->targets + 3;
	
	
    return 0;
}

#ifdef __cplusplus
}
#endif /* __cplusplus */
