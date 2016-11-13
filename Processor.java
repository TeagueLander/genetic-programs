
import java.util.Stack;

public class Processor {
	
	//Math operations (add NOT?)
	public static final byte NOP	= 0b0000;
	public static final byte ADD	= 0b0001;
	public static final byte SUB	= 0b0010;
	//Bit operations
	public static final byte AND	= 0b0100;
	public static final byte OR		= 0b0101;
	public static final byte SHL	= 0b0110;
	public static final byte SHR	= 0b0111;
	//Stack operations
	public static final byte PUSH1	= 0b1000;
	public static final byte POP1	= 0b1001;
	public static final byte PUSH2	= 0b1010;
	public static final byte POP2	= 0b1011;
	//Input output
	public static final byte OUT	= 0b1100;
	
	
	
	public Processor() {
		
	}
	
	public static void main(String[] args) {
		Processor processor = new Processor();
	}
	
}