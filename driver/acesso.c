#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define DEVICE_NAME "/dev/submarino"
#define BUF_MSG 1

int writeDriver(char word[BUF_MSG])
{
  int file;
  file = open(DEVICE_NAME, O_WRONLY);

  if (file > 0) {
    write(file, word, BUF_MSG);
    close(file);
  }

  return 1;
}

char* readDriver()
{
  int file;
  char word = (char) malloc(BUF_MSG);
  file = open(DEVICE_NAME, O_RDONLY);

  if (file > 0) {
    read(file, &word, BUF_MSG);
    close(file);
  }

  return word;
}