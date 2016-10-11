#include "livewire.h"


int lws_validate_ip_string(char* string){
  int num_chars = lws_s_length(string);
  int dot_count = 0;
  for(int i = 0; i < num_chars; i++){
    if(string[i] == '.'){
      dot_count++;
    }
  }
  return(dot_count == 3);
}

lws_src_dst_t* lws_build_src_dst_struct(char *ip_string, int channel){
  if(!lws_validate_ip_string(ip_string)) {
    lws_fail_with_message("Source IP is invalid");
  }

  lws_src_dst_t* ip_struct = lws_check_malloc(malloc(sizeof(lws_src_dst_t)));

  // Parse the input source IP
  sscanf(
    ip_string,
    "%i.%i.%i.%i",
    &(ip_struct->src.oct_one),
    &(ip_struct->src.oct_two),
    &(ip_struct->src.oct_three),
    &(ip_struct->src.oct_four)
  );

  // Init the dst fields
  ip_struct->dst.oct_one = 0;
  ip_struct->dst.oct_two = 0;
  ip_struct->dst.oct_three = 0;
  ip_struct->dst.oct_four = 0;

  // Set the channel
  ip_struct->channel = channel;

  return ip_struct;
}

void lws_free_src_dst_struct(lws_src_dst_t* struct_to_free){
  if(struct_to_free != NULL){
    free(struct_to_free);
  }
}

void lws_calc_dst_addr(lws_src_dst_t* src_dst){
  // First two octets are multicast defined
  src_dst->dst.oct_one = 239;
  src_dst->dst.oct_two = 192;

  // Calculate the lower two octets
  int oct3 = src_dst->channel / 256;
  int oct4 = src_dst->channel - (oct3 * 256);

  src_dst->dst.oct_three = oct3;
  src_dst->dst.oct_four = oct4;
}
