#ifndef GETLOCATION_H
#define GETLOCATION_H

int getlocation(int var_id);
int getlocationofid(int var_id,int aid);
int getlocationread(int var_id);
void checkresult(int c);
int my_init(void);

char *str_replace(char *str, char *orig, char *rep);
#endif
