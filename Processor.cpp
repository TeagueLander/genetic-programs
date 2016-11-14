

#include "Processor.h"





//Processor
Processor::Processor() {
	pc = 0;
}
Processor::Processor(int pc) {
	this->pc = pc;
}
Processor::getPC() {
	return pc;
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

int main(int argc, char *argv[]) {
	Processor processor(257);
	
	printByte(processor.getPC());
	printIntAsByte(257);
}