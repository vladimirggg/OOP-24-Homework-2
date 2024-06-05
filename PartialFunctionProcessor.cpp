#include "PartialFunctionProcessor.h"

void PartialFunctionProcessor::invokeWithRange(int a, int b) const{
    for(int i = a; i < b; ++i)
        try{
            std::cout<<"f("<<i<<") = "<<functor->invoke(i)<<'\n';
        }
        catch(const std::invalid_argument& e){
            std::cerr<<"Undefined!\n";
        }
}

PartialFunction *PartialFunctionProcessor::readFunctionFromFile(const char *fileName) {
    std::ifstream inputFile(fileName, std::ios::binary);
    if(!inputFile.is_open())
        throw std::runtime_error("Error opening the file!");

    short n, t;
    inputFile.read((char*) &n, sizeof(short));
    inputFile.read((char*) &t, sizeof(short));

    if(t == 0) {
        int args[32];
        int results[32];
        inputFile.read((char *) args, sizeof(int) * n);
        inputFile.read((char *) results, sizeof(int) * n);
        return new CriteriaPartialFunction<Criteria1Func>(Criteria1Func(args, results, n));
    }
    else if(t == 1) {
        int args[32];
        inputFile.read((char *) args, sizeof(int) * n);
        return new CriteriaPartialFunction<Criteria2Func>(Criteria2Func(args, n));
    }
    else if(t == 2) {
        int args[32];
        inputFile.read((char *) args, sizeof(int) * n);
        return new CriteriaPartialFunction<Criteria3Func>(Criteria3Func(args, n));
    }
    else if(t == 3) {
        char buff[256];
        PartialFunction *maxFunctors[MAX_SIZE];
        for (size_t i = 0; i < n; i++) {
            readStringFromFile(inputFile, buff);
            maxFunctors[i] = readFunctionFromFile(buff);
        }
        return new MaxPartialFunction(maxFunctors, n);
    }
    else if(t == 4) {
        char buff[256];
        PartialFunction *minFunctors[MAX_SIZE];
        for (size_t i = 0; i < n; i++) {
            minFunctors[i] = readFunctionFromFile(buff);
        }
        return new MinPartialFunction(minFunctors, n);
    }
    else
        throw std::runtime_error("Unknown function type!");
}

void PartialFunctionProcessor::readStringFromFile(std::ifstream &in, char *buff) {
    char ch;
    size_t index = 0;
    while(index < 255 && in.get(ch) && ch != '\0')
        buff[index++] = ch;

    buff[index] = '\0';
}

PartialFunctionProcessor::PartialFunctionProcessor() : functor(readFunctionFromFile()) {}

void PartialFunctionProcessor::findDefinedPoints() const {
    for (int i = INT32_MIN; i < INT32_MAX; ++i) {
        if(functor->isDefined(i)){

            std::cout<<"f("<<i<<") = "<<functor->invoke(i)<<'\n';
            std::cin.get();
        }
    }
    std::cout<<"No more defined points!\n";
}

