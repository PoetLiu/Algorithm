/*
 *
 * Authored by Liu Peng on: 2016年 10月 20日 星期四 16:52:02 CST
 *
 * @desc: 冒泡排序 O(N^2)
 *
 * @func:
**/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mylib.h"

#define NUM	10

int main(void) 
{
	int data[NUM] = {0}, i = 0, j = 0, tmp = 0;

	DEBUG("Generating %d random int to sort:\n", NUM);
	for (i = 0; i < ARRAY_SIZE_GET(data); i++)  {
		data[i]	= my_rand(0, NUM);
		printf("%d ", data[i]);
	}
	printf("\n");

	for (i = 0; i < ARRAY_SIZE_GET(data); i++) {
		for (j = i; j < ARRAY_SIZE_GET(data); j++) {
			if (data[i] > data[j]) {
				tmp	= data[i];
				data[i]	= data[j];
				data[j]	= tmp;
			}
		}
	}
	DEBUG("After sort:\n");
	for (i = 0; i < ARRAY_SIZE_GET(data); i++)  {
		printf("%d ", data[i]);
	}
	printf("\n");
	return 0;
}
