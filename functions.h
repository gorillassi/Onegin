#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

size_t get_file_size(const char* file_path);
void swap(char** n1, char** n2);
char* file_buffer(const char* file_path);