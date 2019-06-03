#include "doubleutils.h"

bool zerodouble(double d)
{
    return d > -0.0001 && d < 0.0001;
}

bool equaldouble(double d1, double d2, int accuracy)
{
    int i1 = static_cast<int>(d1 * accuracy);
    int i2 = static_cast<int>(d2 * accuracy);
    return i1 == i2;
}
