
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stack>
#include <bitset>
using namespace std;

//Math operations
#define NOP		0b0000
#define ADD		0b0001
#define SUB		0b0010
//Bit operations
#define AND		0b0100
#define OR		0b0101
#define SHL		0b0110
#define SHR		0b0111
//Stack operations
#define PUSH1	0b1000
#define POP1	0b1001
#define PUSH2	0b1010
#define POP2	0b1011
//Input output
#define OUT		0b1100

class Processor {
	public:
		Processor();
		Processor(int pc);
		getPC();
	private:
		stack<uint8_t>		stack1;
		stack<uint8_t>		stack2;
		int					pc;
};

void printByte(uint8_t byte);
void printIntAsByte(int num);