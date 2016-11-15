

#include "Processor.h"





//Processor
Processor::Processor() {
	pc = 0;
}
//remove this
/* Processor::Processor(int pc) {
	this->pc = pc;
} */
Processor::getPC() {
	return pc;
}

//Operations
void Processor::performOperation(uint8_t *&seq) {
	uint8_t operation = *seq++;
	
	switch (operation) {
		case ADD:
			this->opADD(seq); break;
		// case SUB:
			// this->opSUB(seq); break;
		default:
			this->opNOP(seq); break;
	}
	
}
void Processor::opNOP(uint8_t *&seq) {
	uint8_t data = *seq++;
	printf("NOP \n");
}
void Processor::opADD(uint8_t *&seq) {
	uint8_t data = *seq++;
	uint8_t regL = getLeftBits(data);
	uint8_t regR = getRightBits(data);
	
	uint8_t val0 = getRegisterValue(regL);
	uint8_t val1 = getRegisterValue(regR);
	
	setRegisterValue(regL, val0 + val1);
	
	printf("ADD \n");
}
void Processor::opSUB(uint8_t *&seq) {
	uint8_t data = *seq++;
	uint8_t regL = getLeftBits(data);
	uint8_t regR = getRightBits(data);
	
	uint8_t val0 = getRegisterValue(regL);
	uint8_t val1 = getRegisterValue(regR);
	
	setRegisterValue(regL, val0 - val1);
	
	printf("SUB \n");
}
void Processor::opAND(uint8_t *&seq) {
	uint8_t data = *seq++;
	uint8_t regL = getLeftBits(data);
	uint8_t regR = getRightBits(data);
	
	uint8_t val0 = getRegisterValue(regL);
	uint8_t val1 = getRegisterValue(regR);
	
	setRegisterValue(regL, val0&val1);
	
	printf("AND \n");
}
void Processor::opOR(uint8_t *&seq) {
	uint8_t data = *seq++;
	uint8_t regL = getLeftBits(data);
	uint8_t regR = getRightBits(data);
	
	uint8_t val0 = getRegisterValue(regL);
	uint8_t val1 = getRegisterValue(regR);
	
	setRegisterValue(regL, val0^val1);
	
	printf("OR \n");
}
void Processor::opSHL(uint8_t *&seq) {
	uint8_t data = *seq++;
	uint8_t regL = getLeftBits(data);
	
	uint8_t val0 = getRegisterValue(regL);
	
	setRegisterValue(regL, val0<<1);
	
	printf("SHL \n");
}
void Processor::opSHR(uint8_t *&seq) {
	uint8_t data = *seq++;
	uint8_t regL = getLeftBits(data);
	
	uint8_t val0 = getRegisterValue(regL);
	
	setRegisterValue(regL, val0>>1);
	
	printf("SHL \n");
}
void Processor::opPUSH1(uint8_t *&seq) {
	uint8_t data = *seq++;
	uint8_t regL = getLeftBits(data);
	
	uint8_t val0 = getRegisterValue(regL);
	
	pushStack1(regL);
	
	printf("PUSH1 \n");
}
void Processor::opPUSH2(uint8_t *&seq) {
	uint8_t data = *seq++;
	uint8_t regL = getLeftBits(data);
	
	uint8_t val0 = getRegisterValue(regL);
	
	pushStack2(regL);
	
	printf("PUSH2 \n");
}
void Processor::opPOP1(uint8_t *&seq) {
	uint8_t data = *seq++;
	uint8_t regL = getLeftBits(data);
	
	setRegisterValue(regL,popStack1());
	
	printf("POP1 \n");
}
void Processor::opPOP2(uint8_t *&seq) {
	uint8_t data = *seq++;
	uint8_t regL = getLeftBits(data);
	
	setRegisterValue(regL,popStack2());
	
	printf("POP2 \n");
}
void Processor::opMOV(uint8_t *&seq) {
	uint8_t data = *seq++;
	uint8_t regL = getLeftBits(data);
	uint8_t regR = getRightBits(data);
	
	uint8_t val1 = getRegisterValue(regR);
	
	setRegisterValue(regL, val1);
	
	printf("MOV \n");
}
void Processor::opSAV2(uint8_t *&seq) {
	uint8_t data = *seq++;
	uint8_t regL = R2;
	
	setRegisterValue(regL, data);
	
	printf("SAV2 \n");
}
void Processor::opSAV3(uint8_t *&seq) {
	uint8_t data = *seq++;
	uint8_t regL = R3;
	
	setRegisterValue(regL, data);
	
	printf("SAV3 \n");
}

uint8_t Processor::getRegisterValue(uint8_t reg) {
	if (reg == R0) {
		return r0;
	}else if (reg == R1) {
		return r1;
	}else if (reg == R2) {
		return r2;
	}else if (reg == R3) {
		return r3;
	}
	printf("get invalid register \n");
	return (uint8_t)0; //should be error
}
void Processor::setRegisterValue(uint8_t reg, uint8_t seq) {
	if (reg == R0) {
		r0 = seq;
	}else if (reg == R1) {
		r1 = seq;
	}else if (reg == R2) {
		r2 = seq;
	}else if (reg == R3) {
		r3 = seq;
	}else {
		printf("set invalid register \n"); //should give error
	}
}

void Processor::pushStack1(uint8_t byte) {
	stack1.push(byte);
}
uint8_t Processor::popStack1() {
	if (stack1.size() > 0) {
		uint8_t x = stack1.top();
		stack1.pop();
		return x;
	}
	return 0; //should throw exception instead
}
void Processor::emptyStack1() {
	stack<uint8_t> empty;
	swap(stack1, empty);
}
void Processor::pushStack2(uint8_t byte) {
	stack2.push(byte);
}
uint8_t Processor::popStack2() {
	if (stack1.size() > 0) {
		uint8_t x = stack2.top();
		stack2.pop();
		return x;
	}
	return 0; //should throw exception instead
}
void Processor::emptyStack2() {
	stack<uint8_t> empty;
	swap(stack2, empty);
}

void printByte(uint8_t byte) {
	bitset<8> x(byte);
	cout << x << endl;
}
void printIntAsByte(int num) {
	bitset<8> a(num>>24);
	bitset<8> b(num>>16);
	bitset<8> c(num>>8);
	bitset<8> d(num);
	cout << a << " " << b << " " << c << " " << d << endl;
}
uint8_t getLeftBits(uint8_t seq) {
	return seq>>4;
}
uint8_t getRightBits(uint8_t seq) {
	return seq&0b1111;
}
uint8_t joinHalfBytes(uint8_t half1, uint8_t half2) {
	return (half1<<4) + half2;
}

//For testing
int main(int argc, char *argv[]) {
	Processor processor;
	processor.setRegisterValue(R0,(uint8_t)0b0001);
	processor.setRegisterValue(R1,(uint8_t)0b11010001);
	
	uint8_t *seq = new uint8_t[4];
	
	uint8_t *point;
	point = seq;
	*point++ = ADD;
	*point++ = ADD;
	*point++ = SUB;
	*point++ = AND;
	*point++ = OUT;
	
	printByte(joinHalfBytes(R1,R1));
	
	//processor.performOperation(seq);
	//processor.performOperation(seq);
	printByte(processor.getRegisterValue(R0));
	printByte(processor.getRegisterValue(R1));

}