#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <libcurl/curl.h>
#include <libcurl/types.h>
#include <libcurl/easy.h>

/**
 * "data" contains all the response data posted by server.
 * "length" is sizeof the response data array.
 * "encoding" is the format of the text written in binary. (val: "ansi" | "unicode");
 */
typedef struct __pbuf {
  wchar_t *data;
  size_t length;
  char encoding[8];
} BUFFER;

 
static void *CURL_WRITE(void *ptr, size_t len, size_t nmemb, void *data) {
  size_t acsize = len * nmemb; /*** Getting actual size ***/
  BUFFER *mem = (BUFFER*) data; /*** Creating buffer ***/
  mem->data = realloc(mem->data, mem->length + (++acsize)); /*** Allocating memory ***/
  
  if(mem->data) {
    memcpy(&(mem->data[mem->length]), ptr, acsize); /*** Copying data ***/
    mem->length+= acsize; 
    mem->data[mem->length] = 0x0; /*** Modifying last element ***/
  }
}
