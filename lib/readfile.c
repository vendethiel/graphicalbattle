#include <stdio.h>
#include <stdlib.h>
#include "../main.h"

char *readfile(char *filename) {
  char *buffer;
  int strl, readl;
  FILE *handler;

  handler = fopen(filename, "r");
  if (handler) {
    fseek(handler, 0, SEEK_END);
    strl = ftell(handler);
    rewind(handler);

    buffer = (char *)xmalloc(sizeof(char) * (strl + 1));
    readl = fread(buffer, sizeof(char), strl, handler);
    buffer[strl + 1] = '\0';

    if (strl != readl) {
      printf("unable to read file");
      free(buffer);
      exit(1);
    }
    return buffer;
  }
  return NULL;
}
