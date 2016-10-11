#include "utils.h"
#include <string.h>

#define LIVEWIRE_SOURCE_PORT 5004

struct lws_lw_ip_t {
  int oct_one;
  int oct_two;
  int oct_three;
  int oct_four;
};

typedef struct {
  struct lws_lw_ip_t src;
  int channel;
  struct lws_lw_ip_t dst;
} lws_src_dst_t;


lws_src_dst_t* lws_build_src_dst_struct(char *ip_string, int channel);
void lws_free_src_dst_struct(lws_src_dst_t* struct_to_free);
void lws_calc_dst_addr(lws_src_dst_t*);
