#pragma once

#include <stdlib.h>

typedef void obj;
typedef void(*function1_t)(obj *);

void set_queue_to_null(); 

void retain(obj *);

void release(obj *);

unsigned short rc(obj *);

obj *allocate(size_t bytes, function1_t destructor);

obj *allocate_array(size_t elements, size_t elem_size, function1_t destructor);

void deallocate(obj *);

void set_cascade_limit(size_t new);

size_t get_cascade_limit();

void cleanup();

void shutdown();
