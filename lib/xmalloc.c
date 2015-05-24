#include <stdlib.h>
#include <stdio.h>

void *xmalloc(size_t size) {
  void *res;

  res = malloc(size);
  if (!res) {
    printf("Unable to allocate memory\n");
    exit(1);
  }
  return (res);
}

void *xcalloc(size_t count, size_t size) {
  void *res;

  res = calloc(count, size);
  if (!res) {
    printf("Unable to allocate memory\n");
    exit(1);
  }
  return (res);
}
