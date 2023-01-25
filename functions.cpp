#include "functions.h"

size_t get_file_size(const char* file_path)
{
	size_t file_size = 0;
	struct stat file_stat_buff;
	FILE *source = fopen(file_path,"rb");

	if(source == nullptr)
    {
		file_size = -1;
	}
	else
    {
		if ((fstat(fileno(source), &file_stat_buff) != 0)) 
        {
			file_size = -1;
		}
		else
        {           
			file_size = file_stat_buff.st_size;
		}
		
	}
    fclose(source);
	return file_size;
}

void swap(char** n1, char** n2)
{
    char* tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;

}

char* file_buffer(const char* file_path, struct text *Onegin)
{
    FILE *source = fopen(file_path,"rb");
    FILE *output = fopen("/home/gorilla/Documents/GitHub/Onegin/OneginRhyme.txt","wb");

    if(source == nullptr)
    {
		return nullptr;
        exit(1);
	}
    if(output == nullptr)
    {
		return nullptr;
        exit(1);
	}

    size_t l_size = get_file_size(file_path);
    Onegin -> file_size = l_size;

    char * buffer = (char*) calloc(l_size, sizeof(char));

    if(buffer == nullptr)
    {
        return nullptr;
    }

    size_t result = fread(buffer, sizeof(char), l_size, source);

    if(result != l_size)
    {
        return nullptr;
    }

    Onegin->buffer = buffer;
    fclose(source);
    fclose(output);
    return buffer;
}

char** get_string_array(char* buffer, struct text *Onegin)
{
    size_t num_of_lines = 1;

    for (int i = 0; i < (Onegin->file_size); i++)
    {
        if(buffer[i] == '\n')
        {
            buffer[i] = '\0';
            num_of_lines += 1;
        }
    }
     
    Onegin->num_of_lines = num_of_lines;

    char** mas_lines = (char**) calloc(num_of_lines, sizeof(char*));

    mas_lines[0] = buffer;

    int j = 1;
    for (int i = 1; i < (Onegin->file_size); i++)
    {
        if (buffer[i] == '\0')
        {
            mas_lines[j] = buffer + i + 1;
            j++;
        }
    }
    return mas_lines;
}

char* first_letter_start(char *pointer)
{
    while ((!isalpha(*pointer)) && (*pointer != '\0'))
    {
        pointer++;
    }
    return pointer;   
}

void sort_from_start(char** mas_lines, struct text *Onegin)
{
    FILE *output = fopen("/home/gorilla/Documents/GitHub/Onegin/OneginRhyme.txt","wb");
    for (int i = 0; i < (Onegin->num_of_lines - 1); i++)
    {
        for (int j = 0; j < (Onegin->num_of_lines - i - 1); j++)
        {
            if(strcasecmp(first_letter_start(mas_lines[j]), first_letter_start(mas_lines[j+1])) > 0){
                swap(&mas_lines[j], &mas_lines[j+1]);
            }
        }       
    } 

    for (int i = 0; i < (Onegin->num_of_lines); i++)
    {
        fprintf(output ,"%s\n",mas_lines[i]);
    }    
    fclose(output);
}

char* first_letter_end(char *pointer)
{
    while (*pointer != '\0')
    {
        pointer++;
    }
    while ((!isalpha(*pointer)) && (*pointer != '\0'))
    {
        pointer--;
    }
    return pointer;   
}

int strcasecmp_from_end(const char* s1, const char* s2)
{
    

    return (*s1 - *s2);
}

void sort_from_end(char** mas_lines, struct text *Onegin)
{
    FILE *output = fopen("/home/gorilla/Documents/GitHub/Onegin/OneginRhyme.txt","wb");
    for (int i = 0; i < (Onegin->num_of_lines - 1); i++)
    {
        for (int j = 0; j < (Onegin->num_of_lines - i - 1); j++)
        {
            if(strcasecmp_from_end(first_letter_end(mas_lines[j]), first_letter_end(mas_lines[j+1])) > 0){
                swap(&mas_lines[j], &mas_lines[j+1]);
            }
        }       
    } 

    for (int i = (Onegin->num_of_lines-1); i > -1; i--)
    {
        fprintf(output ,"%s\n",mas_lines[i]);
    }    
    fclose(output);
}