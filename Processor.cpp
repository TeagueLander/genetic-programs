

#include "Processor.h"





//Processor
Processor::Processor() {
	pc = 0;
}
//remove this
Processor::Processor(int pc) {
	this->pc = pc;
}
Processor::getPC() {
	return pc;
}
void Processor::performOperation(uint8_t *seq) {
	printByte(seq[0]);
	printByte(seq[1]);
	printByte(seq[2]);
	printByte(seq[3]);
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

//For testing
int main(int argc, char *argv[]) {
	Processor processor;
	
	uint8_t *seq = new uint8_t[4];
	uint8_t *point;
	point = seq;
	*point = ADD;
	point++;
	*point = ADD;
	point++;
	*point = ADD;
	point++;
	*point = ADD;
	point++;
	processor.performOperation(seq);

}