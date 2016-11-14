

#include "Processor.h"

class Processor {
	public:
		Process(int pc) {
			this -> pc = pc;
		}
		int getPC() {
			return pc;
		}
	private:
		std::stack<uint8_t>		stack1;
		std::stack<uint8_t>		stack2;
		int						pc; //Program Counter
};

int main(int argc, char *argv[]) {
	//Processor process (32);
	
	printByte(OUT);
}

void printByte(uint8_t byte) {
	bitset<8> x(byte);
	cout << x;
}