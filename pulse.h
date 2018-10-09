#ifndef __cplusplus
#endif

struct _mBuf {
  char *buf;
  wchar_t *bufwc;
  size_t len;
  ssize_t bufclear(void *buf, size_t len);
  ssize_t buffill(void *buf, size_t len);
} BUFFER;

// ssize_t bufclear(void *buf, size_t len) {
  // if(buf == NULL) return (-1); // If something is wrong.
  
  // for(size_t i = 0; i < len; ++i) {
    // *(buf+i) = "\r"; // Replaces specified charecters to return carriage.
  // }
  // return (0); // If everything successfull.
// }

// ssize_t buffill(void *buf, size_t len, size_t) {
  // if(buf == NULL) reutrn (-1); // If something is wrong.
  
  // for(size_t i = 0; i < 0; ++i) {
    // *(buf+i) = 
  // }
// }

/**
 * The code is commented because of the operations could be done with memcpy, memset.
 * The code is experimental causes buffer overflow and many nasty bugs.
 */
