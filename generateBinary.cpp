#include <fstream>
#include <iostream>

int main(){
    // FUNC.DAT
    std::ofstream funcFile("func.dat", std::ios::out | std::ios::binary);
    if(!funcFile.is_open()){
        std::cout<<"Error opening funcFile!";
        return 0;
    }
    short a = 3;
    char output[] = "first.dat\0second.dat\0third.dat";
    funcFile.write((char*) &a, sizeof(short));
    funcFile.write((char*) &a, sizeof(short));
    funcFile.write(output, sizeof(output));
    funcFile.close();

    // FIRST.DAT
    std::ofstream firstFile("first.dat", std::ios::out | std::ios::binary);
    if(!firstFile.is_open()){
        std::cout<<"Error opening firstFile!";
        return 0;
    }

    short firstOuput[] = {7, 0};
    int firstNumbers[] = {1, 2, 3, 5, 6, 7, 3, 3, 3, 4, 4, 0};
    firstFile.write((char*) firstOuput, sizeof(short) * 2);
    firstFile.write((char*) firstNumbers, sizeof(int) * 12);
    firstFile.close();
    
    // SECOND.DAT
    std::ofstream secondFile("second.dat", std::ios::out | std::ios::binary);
    if(!secondFile.is_open()){
        std::cout<<"Error opening secondFile!";
        return 0;
    }
    short secondOutput[] = {2, 1};
    int secondNumbers[] = { 3, 5};
    secondFile.write((char*) secondOutput, sizeof(short) * 2);
    secondFile.write((char*) secondNumbers, sizeof(int) * 2);
    secondFile.close();

    // THIRD.DAT
    std::ofstream thirdFile("third.dat", std::ios::out | std::ios::binary);
    if(!thirdFile.is_open()){
        std::cout<<"Error opening thirdFile!";
        return 0;
    }
    short thirdOutput[] = {4, 2};
    int thirdNumbers[] = { 0, 5, 6, 7};
    thirdFile.write((char*) thirdOutput, sizeof(short) * 2);
    thirdFile.write((char*) thirdNumbers, sizeof(int) * 4);
    thirdFile.close();


    std::ifstream in("func.dat", std::ios::binary | std::ios::in);
    if(!in.is_open()){
        std::cout<<"Error: Couldn't open file!";
        return 0;
    }

    char ch;
    short b;
    in.read((char*) &b, sizeof(short));
    std::cout<<a;
    in.read((char*) &b, sizeof(short));
    std::cout<<a;
    while(in.get(ch)) std::cout<<ch;
    in.close();
}