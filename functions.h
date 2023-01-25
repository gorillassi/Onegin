#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

struct text
{
    char *buffer;
    int num_of_lines;
    size_t file_size;
    char** mas_lines;
};

size_t get_file_size(const char* file_path);
void swap(char** n1, char** n2);
char* file_buffer(const char* file_path, struct text *Onegin);
char** get_string_array(char* buffer, struct text *Onegin);
char* first_letter_start(char *pointer);
void sort_from_start(char** mas_lines, struct text *Onegin);
char* first_letter_end(char *pointer);
void sort_from_end(char** mas_lines, struct text *Onegin);