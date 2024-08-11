// Base model class implementation

#include "model.h"
#include <stdlib.h>
#include <string.h>

// Initialize the BaseModel
void base_model_init(BaseModel *model, size_t num_layers, size_t *layer_sizes)
{
    model->num_layers = num_layers;
    // Allocate memory for layer_sizes pointer
    model->layer_sizes = (size_t *)malloc(num_layers * sizeof(size_t));
    // Memory copy (memcpy()) `layer_sizes` array to `model->layer_sizes` array
    memcpy(model->layer_sizes, layer_sizes, num_layers * sizeof(size_t));

    /* Allocate memory for weights
    Each weight matrix connects one layer to the next. There for, if there are
    `num_layers` layers, there are `num_layers - 1` sets of weight (one for each
    pair of adjacent layers)
    */
    model->weights = (float **)malloc((num_layers - 1) * sizeof(size_t));

    /* Allocate memory for biases
    Each layer excpet the input layer has a bias vector. Thus, there are also
    `num_layers - 1` bias vectors
    */
    model->biases = (float **)malloc((num_layers - 1) * sizeof(size_t));

    for (size_t i = 0; i < num_layers - 1; i++)
    {
        model->weights = (float *)malloc(layer_sizes[i] * layer_sizes[i + 1] * sizeof(float));
        model->biases = (float *)malloc(layer_sizes[i + 1] * sizeof(float));
    }

    // Set function pointers to default implementations
    model->forward = base_model_forward;
    model->baclward = base_model_backward;
    model->update = base_model_update;
    model->free = base_model_free;
}

// Forward Propagation
void base_model_forward(void *self, float *input, float *output)
{
    BaseModel *model = (BaseModel *)self;
    memcpy(output, input, model->layer_sizes[0] * sizeof(float));
    // Implement the forward pass for a basic model
    // This is a placeholder and should be customized for each derived model
}

// Backward Propagation
void base_model_backward(void *self, float *input, float *output, float *grad_input, float *grad_output)
{
    BaseModel *model = (BaseModel *)self;
    // Implement the backward pass (this is a placeholder)
    // Should be customized for each derived model
}

// Weights and Biases Update
void base_model_update(void *self, float learning_rate)
{
    BaseModel *model = (BaseModel *)self;
    // Implement weight and bias updates (placeholder)
    for (size_t i = 0; i < model->num_layers - 1; i++)
    {
        for (size_t j = 0; j < model->layer_sizes[i] * model->layer_sizes[i + 1]; j++)
        {
            model->weights[i][j] -= learning_rate * 0.01f; // Placeholder gradient
        }
        for (size_t j = 0; j < model->layer_sizes[i + 1]; j++)
        {
            model->biases[i][j] -= learning_rate * 0.01f; // Placeholder gradient
        }
    }
}

// Memory Management and Resource Cleanup
// BaseModel Free
void base_model_free(void *self)
{
    BaseModel *model = (BaseModel *)self;
    for (size_t i = 0; i < model->num_layers - 1; i++)
    {
        free(model->weights[i]);
        free(model->biases[i]);
    }
    free(model->weights);
    free(model->biases);
    free(model->layer_sizes);
    free(model);
}