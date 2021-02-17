#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void to_merge(int *array, int *temp, int start, int end);
void merger(int *array, int *temp, int start, int mid, int end);
void merge_sort(int *array, size_t size);

#endif
