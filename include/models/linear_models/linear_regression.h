// include/models/linear_regression.h

#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

#include "model.h"

// LinearRegression structure extending BaseModel
typedef struct
{
    BaseModel base; // Inherit from BaseModel
    // Additional attributes for LinearRegressor
} LinearRegression;

// Function prototype
void linear_regression_init(LinearRegression *model, size_t input_size);
void lienar_regression_predict(LinearRegression *model, float *input, float *output);
void linear_regression_free(LinearRegression *model);

#endif // LINEAR_REGRESSION_H