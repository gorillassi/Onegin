#include "functions.h"


int main(){

    struct text Onegin = { 
        .buffer = nullptr,
        .num_of_lines = 0,
        .file_size = 0
    };
    
    const char* file_path = "/home/gorilla/Documents/GitHub/Onegin/Onegin.txt";
    
    get_file_size(file_path);
    
    char * buffer = file_buffer(file_path, &Onegin);
    Onegin.mas_lines = get_string_array(buffer, &Onegin);
    sort_from_start(Onegin.mas_lines, &Onegin);
    sort_from_end(Onegin.mas_lines, &Onegin);
    free(buffer);
    return 0;
}