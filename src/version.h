/*struct Act{
int a_id;
char state[];
};*/
#include "action.h"
#include "sector.h"
struct Version_History {
Sector sector[100];
//char value[100][20];
ActionId id[100];
int lock;
/*char array for outcome record char str[numofstrings][stringlen] Struct of action id */
};

extern struct Version_History v[10000];

//loop i 1 to 10 extern v[i].id.
