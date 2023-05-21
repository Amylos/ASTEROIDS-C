/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <app.h>

int main(void) {
	printf("==================ENTER ASTEROIDS BASE=================\n");
	t_app*pApp=AppNew();
	int ret=AppRun(pApp);
	AppDel(pApp);
	printf("==================EXIT  ASTEROIDS BASE=================\n");
	return ret;
}
