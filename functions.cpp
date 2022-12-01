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
    *n2 = tmp;printf("OK2");

}

char* file_buffer(const char* file_path)
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
    fseek(source,0, SEEK_END);
    size_t l_size = ftell(source);
    rewind(source);

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

    size_t num_of_lines = 1;


    for (int i = 0; i < l_size; i++)
    {
        if(buffer[i] == '\n')
        {
            buffer[i] = '\0';
            num_of_lines += 1;
        }
    }
    printf("%ld", num_of_lines);
    
    char** mas_lines = (char**) calloc(num_of_lines, sizeof(char*));

    mas_lines[0] = &buffer[0];

    int j = 1;
    for (int i = 1; i < l_size; i++)
    {
        if (buffer[i] == '\0')
        {
            mas_lines[j] = &buffer[i + 1];
            j++;
        }
    }

    //buble sort

    for (int i = 0; i < num_of_lines - 1; i++)
    {
        for (j = 0; j < num_of_lines - i -1; j++)
        {
            if(strcmp(mas_lines[j], mas_lines[j+1]) > 0){
                swap(&mas_lines[j], &mas_lines[j+1]);
            }
        }       
    } 

    for (int i = 0; i < num_of_lines; i++)
    {
        fprintf(output ,"%s\n",mas_lines[i]);
    }
    
    free(buffer);
    free(mas_lines);
    fclose(source);
    fclose(output);
    return buffer;
}