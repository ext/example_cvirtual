#include "base.h"

int main(int argc, const char* argv[]){
	base_t* a = fred_alloc();
	base_t* b = barney_alloc();
	base_t* c = wilma_alloc();

	base_frobnicate(a);
	base_frobnicate(b);
	base_frobnicate(c);

	base_free(a);
	base_free(b);
	base_free(c);
	return 0;
}
