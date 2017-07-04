#include "header.h"


int main()
{
    FILE* stream = fopen("/Users/camille/Dropbox/test.csv", "r");
    
    char line[1024];
    while (fgets(line, 1024, stream))
    {
        char* tmp = strdup(line);
        printf("Field 3 would be %s\n", getfield(tmp, 4));
        // NOTE strtok clobbers tmp
        free(tmp);
    }
    
    return 0;
}
