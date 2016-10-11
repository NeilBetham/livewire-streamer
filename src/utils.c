#include "utils.h"

void* lws_check_malloc(void* pointer){
  if(pointer != NULL){ return pointer; }
  lws_fail_with_message("Failed to allocate require memory");
  return NULL;
}

void lws_fail_with_message(char* message){
  perror(message);
  exit(FAILURE_EXIT_CODE);
}

int lws_s_length(char* string){
  int length = 0;
  while(string[length] != '\0') { ++length; }
  return length;
}
