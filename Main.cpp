#include "PartialFunctionProcessor.h"

int main(){
    PartialFunctionProcessor processor;
    processor.invokeWithRange(0, 10);
    processor.findDefinedPoints();
}