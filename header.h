//
//  csv.h
//  Projet_C
//
//  Created by Camille LAURENT on 22/05/2017.
//  Copyright © 2017 Camille LAURENT. All rights reserved.
//

#ifndef csv_h
#define csv_h

#define _GNU_SOURCE
#define bool int

#include <stdio.h>
#include <stdlib.h> /* malloc...*/
#include <string.h> /* strtok...*/
#include <ctype.h>
#include <errno.h>

const char* getfield(char* line, int num);


#endif /* csv_h */
