#include "ALMOST_ALL_OR_NOTHING_PUT.h"
#include "careful.h"
#include "sector.h"
int almost_all_or_nothing_put(char *data,Sector sector){

CAREFUL_PUT(data, sector.S1);
CAREFUL_PUT(data, sector.S2);
CAREFUL_PUT(data, sector.S3);



}
