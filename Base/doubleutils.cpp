#include "doubleutils.h"

bool zerodouble(double d)
{
    return d > -0.0001 && d < 0.0001;
}
