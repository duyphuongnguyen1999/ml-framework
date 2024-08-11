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
