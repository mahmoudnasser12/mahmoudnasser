#include <stdint.h>



class Led
{
	
	public:
		
	typedef uint32_t port_type;
	typedef uint32_t bval_type; 				//bit value 
	
	Led(const port_type p, bval_type b): port(p) , bval(b)
	{
		
			*reinterpret_cast <volatile port_type *>(port) 
				&= bval;
	
	}
	
	
		
	private:
		
	port_type port;
	bval_type bval;
	
};

int main(){
	
	
	
}