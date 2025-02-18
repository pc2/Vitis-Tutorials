//
// Copyright (C) 2023, Advanced Micro Devices, Inc. All rights reserved.
// SPDX-License-Identifier: X11
//

#include <ap_int.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>

#define WORD_SIZE 16

extern "C" {

  void s2mm_vadd_s(ap_int<WORD_SIZE>* mem, hls::stream<hls::axis<ap_int<WORD_SIZE>, 0, 0, 0>> &s, int size) {
    #pragma HLS INTERFACE m_axi port=mem offset=slave bundle=gmem

    #pragma HLS interface axis port=s

    #pragma HLS INTERFACE s_axilite port=mem bundle=control
    #pragma HLS INTERFACE s_axilite port=size bundle=control
    #pragma HLS interface s_axilite port=return bundle=control

    for(int i = 0; i < size; i++) {
      #pragma HLS PIPELINE II=1
      hls::axis<ap_int<WORD_SIZE>, 0, 0, 0> x = s.read();
      mem[i] = x.data;
    }
  }
}
