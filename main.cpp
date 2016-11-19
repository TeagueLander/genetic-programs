

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
#define DATA_LEN 10000

int main(int argc, char *argv[]) {
	
	Processor cpu;
	
	uint8_t input[3] = {
		0b00000011,
		0b00000001,
		0b00000011
	};
	
	//Generate random starting bits
	uint8_t data[DATA_LEN];
	srand(0);//srand(time(0));
	for (int i = 0; i < DATA_LEN; i++) {
		data[i] = (rand()%256);
	}
	
	cpu.loadInput(input);
	cpu.loadOperations(data,DATA_LEN);
	cpu.runOperations();
	
	//uint8_t *next = new uint8_t[3];
	//cpu.getOutput(next);
	printf("done operations\n");
	
	
	ofstream myfile;
	myfile.open("example.txt");
	myfile << "Writing this to a file.\n";
	myfile.close();
	
	
	return 0;
}