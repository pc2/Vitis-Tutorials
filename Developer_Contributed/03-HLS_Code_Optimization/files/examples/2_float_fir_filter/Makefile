# Copyright © 2023 Advanced Micro Devices, Inc. All rights reserved.
# SPDX-License-Identifier: MIT


.PHONY: help kernels clean all

clean:
			rm -rf *_prj *.log *~

kernels:
			vitis_hls ./float_fir_script.tcl


all:	kernels
