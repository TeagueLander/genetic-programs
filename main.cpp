

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <bitset>
#include <ctime>
#include "Processor.h"
using namespace std;


//Set how long you want the length of the data to be
#define DATA_LEN 10

int main(int argc, char *argv[]) {
	
	Processor cpu;
	
	uint8_t input[3] = {
		0b00000000,
		0b00000000,
		0b00000000
	};
	
	//Generate random starting bits
	uint8_t data[DATA_LEN];
	srand(0);
	for (int i = 0; i < DATA_LEN; i++) {
		data[i] = (rand()%256);
		printByte(data[i]);
	}
	
	cpu.loadInput(input);
	cpu.loadOperations(data,DATA_LEN);
	cpu.runOperations();
	
}