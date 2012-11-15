#include "base.h"
#include <stdio.h>
#include <stdlib.h>

typedef void (*frobnicate_callback)(base_t* base);
typedef void (*destructor_callback)(base_t* base);

struct base {
	int foo;

	frobnicate_callback frobnicate;
	destructor_callback destructor;
};

void base_frobnicate(base_t* ptr){
	if ( ptr->frobnicate ){
		return ptr->frobnicate(ptr);
	} else {
		printf("Base::frobnicate\n");
	}
};

void base_free(base_t* ptr){
	if ( ptr->destructor ){
		ptr->destructor(ptr);
	}
	printf("Base::destructor\n");
	free(ptr);
}

struct fred {
	base_t base;
	int a;
};

struct barney {
	base_t base;
	int b;
};

static void fred_frobnicate(struct fred* ptr){
	printf("Fred::frobnicate\n");
}

static void fred_destructor(struct fred* ptr){
	printf("Fred::destructor\n");
}

base_t* fred_alloc(){
	base_t* ptr = malloc(sizeof(struct fred));
	ptr->frobnicate = (frobnicate_callback)fred_frobnicate;
	ptr->destructor = (frobnicate_callback)fred_destructor;
	return ptr;
}

static void barney_frobnicate(struct barney* ptr){
	printf("Barney::frobnicate\n");
}

static void barney_destructor(struct fred* ptr){
	printf("Barney::destructor\n");
}

base_t* barney_alloc(){
	base_t* ptr = malloc(sizeof(struct barney));
	ptr->frobnicate = (frobnicate_callback)barney_frobnicate;
	ptr->destructor = (frobnicate_callback)barney_destructor;
	return ptr;
}

base_t* wilma_alloc(){
	base_t* ptr = malloc(sizeof(struct base));
	ptr->frobnicate = NULL;
	ptr->destructor = NULL;
	return ptr;
}
