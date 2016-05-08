#ifndef CONV_LAYER_H
#define CONV_LAYER_H

#include "layers.h"
#include "Halide.h"

class Convolutional : public Layer {
public:
  Halide::Var x, y, z, n;

  // number of channels, height and width of the input to the layer
  int num_samples, in_ch, in_h, in_w;

  // number of filters, filter height, filter width, padding and stride
  int num_f, f_h, f_w, pad, stride;

  float reg;

  Halide::Func forward_clamp;

  // parameters for scheduling
  Halide::Var y_t, z_t, par;

  int o_block_size;
  int y_block_size;
  int vec_len;

  Convolutional(int _num_f, int _f_w, int _f_h, int _pad, int _stride,
                Layer *in, int schedule = true);

  void back_propagate(Halide::Func dout);

  int out_dims();

  int out_dim_size(int i);
};

#endif