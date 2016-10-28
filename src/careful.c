#include "careful.h"
#include <string.h>
#include <stdio.h>
void CAREFUL_GET(char *data, char *s){
printf(" %s both %s .",data,s);
strcpy(data,s);

printf(" %s both %s .",data,s);
}


void CAREFUL_PUT(char *data, char *s){

strcpy(s,data);
//printf(" %s both %s .",data,s);

}

