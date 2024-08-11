// Base model class header

#ifndef MODEL_H // Check if MODEL_H is not defined
#define MODEL_H // Define MODEL_H

#include <stddef.h> // Standard Definitions header file

// Define a structure for the BaseModel
typedef struct
{
    // Model paramters (weights, biases)
    float **weights; // Pointer to an array of weight matrices
    float **biases;  // Pointer to an array of bias vectors

    // Model dimensions
    size_t num_layers;   // Number of layers in the model
    size_t *layer_sizes; // Array storing the size of each layer

    // Function pointers for model operations
    void (*forward)(void *self, float *input, float *output);
    void (*baclward)(void *self, float *input, float *output, float *grad_input, float *grad_output);
    void (*update)(void *self, float learning_rate);
    void (*free)(void *self);
} BaseModel;

// Function prototypes for Model
void base_model_init(BaseModel *model, size_t num_layers, size_t *layer_sizes);
void base_model_forward(void *self, float *input, float *output);
void base_model_backward(void *self, float *input, float *output, float *gradinput, float *grad_output);
void base_model_update(void *self, float learning_rate);
void base_model_free(void *self);

#endif // MODEL_H