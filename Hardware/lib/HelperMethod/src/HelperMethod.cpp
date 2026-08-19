#include "HelperMethod.h"


void wait(unsigned long ms)
{
    unsigned long startTime = millis();
    while (millis() - startTime < ms)
    {
        // Just wait
        yield();
    }
}