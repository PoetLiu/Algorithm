/*
 *
 * Authored by Liu Peng on: 2016年 10月 20日 星期四 16:12:32 CST
 *
 * @desc: 桶排序， 时间复杂度O（M+N）
 *
 * @func:
**/
#include <stdio.h>
#include "debug.h"
#include "mem.h"

#define INPUT_NUM	8

int main(void)
{
	int a[INPUT_NUM] = {0};
	int i = 0, j = 0, scannedNumber = 0;
	
	DEBUG("Please input %d nums to sort.!\n", INPUT_NUM);
	for (; j < INPUT_NUM; j++) {
		while (scanf("%d", &scannedNumber) != 1) {
			DEBUG("read num faild. please check input!\n");
		}
		a[scannedNumber] ++;
	}

	for (i = 0; i < ARRAY_SIZE_GET(a); i++) {
		for (j = 0; j < a[i]; j++) {
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}
