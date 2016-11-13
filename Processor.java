
public class Processor {
	
	//maybe add NOT?
	public static final int NOP		= 0b0000;
	public static final int ADD		= 0b0001;
	public static final int SUB		= 0b0010;
	
	public static final int AND		= 0b0100;
	public static final int OR		= 0b0101;
	public static final int SHL		= 0b0110;
	public static final int SHR		= 0b0111;
	
	public static final int PUSH1	= 0b1000;
	public static final int POP1	= 0b1001;
	public static final int PUSH2	= 0b1010;
	public static final int POP2	= 0b1011;
	
	public static final int OUT		= 0b1100;
	
	
	public Processor() {
		
	}
	
}