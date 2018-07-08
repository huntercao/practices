#include <stdio.h>
#include <string.h>

#include "prog.h"

char * hello(char *name){
	char * value = new char[9 + strlen(name)];
	sprintf(value, "Hello, %s.\n", name);
	return value;
}
