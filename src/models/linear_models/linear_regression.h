#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

#include <stddef.h>
#include <model.h>

// LinearRegression structure extending BaseModel
typedef struct
{
    BaseModel base; // Inherit from BaseModel
    // Additional attributes for LinearRegressor
} LinearRegression;

#endif