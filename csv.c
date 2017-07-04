//
//  csv.c
//  Projet_C
//
//  Created by Camille LAURENT on 22/05/2017.
//  Copyright © 2017 Camille LAURENT. All rights reserved.
//

#include "header.h"


const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ";");
         tok && *tok;
         tok = strtok(NULL, ";\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}
