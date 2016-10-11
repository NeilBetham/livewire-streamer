#include <stdlib.h>
#include <stdio.h>

#define FAILURE_EXIT_CODE 1

void* lws_check_malloc(void*);
void lws_fail_with_message(char*);
int lws_s_length(char*);
