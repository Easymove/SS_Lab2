#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

struct mem_info{
	int addr;
	int length;
};

class MemPage{
public:
	MemPage(int len, int pid, int offs);
	~MemPage(){};

	int id;
	int length;
	int offset;
	bool not_full;
	bool splitted;
	
	void print();
	int get_max_free_len();
	int allocate_mem(int size);
	void free_mem(int addr);

private:
	map<int, mem_info> mem_map;
	map<int, mem_info> free_map;

	void merge_free();
};


class MemoryAllocator
{
public:
	MemoryAllocator(int sz);
	~MemoryAllocator(){};

	void monitor_mem(bool detailed);
	void* allocate_mem(int bytes);
	void* reallocate_mem(int *addr, int new_size);
	void free_mem(int *addr);

private:
	int offset;
	int uid;
	int mem_size;
	list<MemPage> mem_pages;
	char* memory;

	int get_index(int *addr);
	void copy_bytes(int *addr);
};