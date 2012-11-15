#ifndef BASE_H
#define BASE_H

/* encapsulation for actual implementation */
typedef struct base base_t;

/* public API for "class" */
void base_frobnicate(base_t* ptr);
void base_free(base_t* ptr);

/* constructors for "subclasses". */
base_t* fred_alloc();
base_t* barney_alloc();
base_t* wilma_alloc();

#endif /* BASE_H */
