#include "mem_allocator.h"

int main(){
	int bytes = 1024;
	MemoryAllocator test = MemoryAllocator(1024);
	
	int* addr = (int*)test.allocate_mem(8);
	int* addr2 = (int*)test.allocate_mem(16);

	test.monitor_mem(true);
	test.free_mem(addr2);
	test.monitor_mem(true);

	addr = (int*)test.allocate_mem(32);
	test.monitor_mem(true);
	test.reallocate_mem(addr2, 24);
	test.monitor_mem(true);
	int* addr3 = (int*)test.allocate_mem(72);
	test.monitor_mem(true);
}