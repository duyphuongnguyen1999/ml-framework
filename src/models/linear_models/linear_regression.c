// src/models/linear_regression/linear_regression.c

#include "linear_regression.h"
#include <stdlib.h>
#include <string.h>

void linear_regression_init(LinearRegression *model, size_t input_size)
{
    size_t layer_size[] = {input_size, 1};
    base_model_init(&(model->base), 2, layer_size);
}