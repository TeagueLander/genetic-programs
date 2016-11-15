
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stack>
#include <bitset>
using namespace std;

/* LANGUAGE (maybe add NOT and JMPIF) */
//Math operations
#define NOP		(uint8_t)0b0000
#define ADD		(uint8_t)0b0001
#define SUB		(uint8_t)0b0010
//Bit operations
#define AND		(uint8_t)0b0100
#define OR		(uint8_t)0b0101
#define SHL		(uint8_t)0b0110
#define SHR		(uint8_t)0b0111
//Stack operations
#define PUSH1	(uint8_t)0b1000
#define POP1	(uint8_t)0b1001
#define PUSH2	(uint8_t)0b1010
#define POP2	(uint8_t)0b1011
//Move
#define MOV		(uint8_t)0b1100
#define OUT		(uint8_t)0b1101

//Registers
#define R1		(uint8_t)0b0001
#define R2		(uint8_t)0b0010
#define R3		(uint8_t)0b0011
#define R4		(uint8_t)0b0100

class Processor {
	public:
		Processor();
		//Processor(int pc); //remove
		int				getPC();
		void			performOperation(uint8_t *&seq);
		uint8_t*		getRegisterValue(uint8_t seq);
		void			setRegisterValue(uint8_t seq);
		
		//Operations
		void			opNOP(uint8_t *&seq);
		void			opADD(uint8_t *&seq);
		
		void			pushStack1(uint8_t byte);
		uint8_t			popStack1();
		void			emptyStack1();
		void			pushStack2(uint8_t byte);
		uint8_t			popStack2();
		void 			emptyStack2();
	private:
		stack<uint8_t>	stack1;
		stack<uint8_t>	stack2;
		int				pc;
		uint8_t			r1;
		uint8_t			r2;
		uint8_t			r3;
		uint8_t			r4;
};

void printByte(uint8_t byte);
void printIntAsByte(int num);
uint8_t getLeftBits(uint8_t seq);
uint8_t getRightBits(uint8_t seq);
