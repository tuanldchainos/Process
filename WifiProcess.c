#include "WifiProcess.h"
#include <stdlib.h>

void read_wifi_info_from_file(FILE * f, int nb_of_line, size_t* nb_of_cha_per_line){
    char *b = (char *)malloc(1);
    size_t characters;
    int i;
    while(!feof(f)){
        for(i = 0; i< nb_of_line; i++){
            characters = getline(&b, nb_of_cha_per_line, f);
            b[characters-1] = NULL;
            characters = characters - 1;
            /*
                context of line in "b"
                number of char of line in "characters"
                user code define here
            */
            if(feof(f)) break;
        }
    }
    fclose(f);
    return;
}
