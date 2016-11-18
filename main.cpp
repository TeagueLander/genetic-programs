

#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stack>
#include <bitset>
#include "Processor.h"
using namespace std;

#define DATA_LEN 8

int main(int argc, char *argv[]) {
    
    Processor cpu;
    
    uint8_t data[DATA_LEN] = {
        0b00001101,
        0b11111111,
        0b00001000,
        0b00100000,
        0b00001001,
        0b00000000,
        0b00001111,
        0b00000000
    };
    
    cpu.loadOperations(data,DATA_LEN);
    cpu.runOperations();
    
}