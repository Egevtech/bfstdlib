#include <stdlib.h>
#include <stdio.h>

#include "runtime.h"

typedef struct Vector {
    int *data;
    int len;
    int current_cell;
} vec_t;

vec_t *vector_init() {
    vec_t *vector = malloc(sizeof(vec_t));

    vector->data = malloc(sizeof(int));
    vector->len = 1;
    vector->current_cell = 0;

    return vector;
}

void realloc_vector(vec_t *vector, int size) {
    vector->len = size;
    vector->data = realloc(vector->data, size);

    if (vector->data == NULL) {
        runtime_panic(-1, "Failed to reallocate array to %d", size);
    }
}

int vector_get(vec_t *vector) {
    return vector->data[vector->current_cell];
}

void vector_put(vec_t *vector, int value) {
    vector->data[vector->current_cell] += value;
}

void move_forward(vec_t *vector, int delta) {
    int new_pos;

    new_pos = vector->current_cell + delta;

    if (new_pos < 0)
        runtime_panic(-2, "Vector address is less than 0: %d", new_pos);

    if (new_pos > vector->len)
        realloc_vector(vector, new_pos);

    vector->current_cell = new_pos;
}

void move_backward(vec_t *vector, int delta) {
    int new_pos;

    new_pos = vector->current_cell + delta;

    if (new_pos < 0)
        runtime_panic(-2, "Vector address is less than 0: %d", new_pos);

    vector->current_cell = new_pos;
}

void print_cell_num(vec_t *vector) {
    printf("%d", vector_get(vector));
}

void print_cell(vec_t *vector) {
    printf("%c", vector_get(vector));
}

void add_to_cell(vec_t *vector, int x) {
    vector_put(vector, x);
}

void sub_from_cell(vec_t *vector, int x) {
    vector_put(vector, -x);
}
