/*
**/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "mylib.h"

#define BUFFER_SIZE 4096
#define true 1
#define false 0

static char find_first_single_char(char *s, int _case)
{
	char map[128] = {0}, c = 0;
	int cnt = 0, i = 0;

	if (!s) {
		return 0;
	}

	// build map
	for (i = 0; s[i] != '\0'; i++) {
		c	= s[i];
		if (map[c] <= 2) {
			map[c]++;
		}
	}

	for (i = 0; s[i] != '\0'; i++) {
		c	= s[i];
		cnt	= 0;
		if (_case == false && isalpha(c)) {
			if (islower(c)) {
				cnt	+= map[c-'a'+'A'];
			} else {
				cnt	+= map[c-'A'+'a'];
			}
		}
		cnt	+= map[c];
		if (cnt == 1) {
			return c;
		}
	}

	return 0;
}

static char *read_one_line_stdin(void)
{
	char buffer[BUFFER_SIZE] = {0}, *s = calloc(1, 1);

	// read param
	while (fgets(buffer, BUFFER_SIZE, stdin)) {
		s	= realloc(s, strlen(s)+strlen(buffer)+1);
		if (!s) {
			return NULL;
		}
		strcat(s, buffer);
	}

	// trim \n
	if (s[strlen(s)-1] == '\n') {
		s[strlen(s)-1]	= '\0';
	}

	return s;
}

int main(void) 
{
	char *s = NULL, res = 0;
	int _case = false, i = 0;

	s	= read_one_line_stdin();
	if (!s) {
		return -1;
	}

	// split
	while (s[i] != '\0') {
		if (s[i] == ' ') {
			break;
		}
		i++;
	}
	if (!strcmp(&s[i+1], "true")) {
		_case	= true;
	}
	s[i]	= '\0';

	res	= find_first_single_char(s, _case);
	printf("res:%c\n", res);

	if (s) {
		free(s);	
	}
	return 0;
}
