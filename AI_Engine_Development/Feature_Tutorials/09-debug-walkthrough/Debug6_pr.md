﻿<table class="sphinxhide" width="100%">
 <tr>
   <td align="center"><img src="https://raw.githubusercontent.com/Xilinx/Image-Collateral/main/xilinx-logo.png" width="30%"/><h1>AI Engine Debug Walkthrough Tutorial - From Simulation to Hardware</h1>
   </td>
 </tr>
 <tr>
 <td align="center"><h2>AI Engine Debug with Hardware Profiling Features</h1>
 </td>
 </tr>
</table>

## Overview

In this tutorial, you will learn how to:

* Use the hardware profiling features to inspect design.

## Hardware Profiling Features

Two flows, XSDB and XRT flow, are supported profiling features with the AIE design. The profiling feature requires no design source code change to collect profiling data. No special options required to build the design. You can use the [XRT Flow](#xrt-flow) or [XSDB Flow](#xsdb-flow) for this tutorial.

### XRT Flow

### Step 1.1: Prepare the Boot Image and Boot the Board

After the design is built correctly without error, you are ready to run on the hardware board.

* Flash the SD card with the built `sd_card.img`.
* Plug the flashed SD card into the SD card slot of the VCK190 board.
* Connect the USB type C cable to the board and computer that supports the serial port connection.
* Set the serial port configuration with Speed=115200, Data=8 bit, Parity=none, Stop bits=1 bit, and flow control=none.
* Power up the VCK190 board to see the boot messages from the serial connection.

### Step 1.2: Generate the Profiling Data

Create an `xrt.ini` file on the SD card using the following lines.

```bash
[Debug]
aie_profile = true
aie_profile_interval_us = 1000
aie_profile_core_metrics = heat_map
aie_profile_memory_metrics = conflicts
aie_profile_interface_metrics = input_bandwidths:0
```

Supported predefined metrics can be found from [UG1076, Profiling the AI Engine in Hardware section](https://docs.xilinx.com/r/en-US/ug1076-ai-engine-environment/Profiling-the-AI-Engine-in-Hardware).
<!--
Available predefined metrics:
1. Supported aie_profile_core_metrics: heap_map, stalls, execution, floating_point, stream_put_get, aie_trace, write_bandwidth, and read_bandwidth.
2. Supported aie_profile_memory_metrics: conflicts, dma_locks, dma_stalls_s2mm, dma_stalls_mm2s, write_bandwidths and read_bandwidths.
3. aie_profile_interface_metrics: input_bandwidths, output_bandwidths, input_stalls_idle and output_stalls_idle.
-->

### Step 1.3: Run the Application After Petalinux Boots Up on the Board

```bash
cd /run/media/mmcblk0p1
./host.exe a.xclbin
```

### Step 1.4: Collect the Profiling Files

After the design run completes on the hardware, the generated profiling files and run_summary files need to be collected and are ready to be examined.

#### Step 1.4.1

Make sure the `aie_profile_edge_[core_metrics]_[memory_metrics]_[interface_metrics].csv`, `summary.csv`, and `xrt.run_summary` files are created on the SD card.

#### Step 1.4.2

Power off the board, and take out the SD card from the board and plug in the SD card to the host's SD card reader.

#### Step 1.4.3

Copy the `aie_profile_edge_[core_metrics]_[memory_metrics]_[interface_metrics].csv`, `summary.csv`, and `xrt.run_summary` files from the SD card back to where the design is.

### Step 1.5: Launch Vitis Analyzer to Examine the Profiling Files

```bash
vitis_analyzer xrt.run_summary
```

After issuing the above command, expect to see the result from [Step 3 Expected Result with Vitis_Analyzer](#step-3-expected-result-with-vitis_analyzer), and continue this tutorial.

### XSDB Flow

### Step 2.1: Prepare the Boot Image and Boot the Board

Same as Step 1.1 of the XRT flow.

### Step 2.2: Generate Profiling Data

#### Step 2.2.1: Target Connection Setup

Run the hardware server from computer that connects to the target board. To do so, launch the hw_server from the computer that has JTAG connection to the VCK190 board.
![alt text](images/hw_ta_hw.png)

#### Step 2.2.2: Connect the XSDB to the Board

Launch xsdb from your host computer at the same level of the design's Work directory. Issue this commands from the XSDB prompt:

```bash
xsdb
%xsdb connect -url TCP:${COMPUTER NAME/IP}:3121
%xsdb ta
%xsdb ta 1
%xsdb source ${XILINX_VITIS)/scripts/vitis/util/aie_profile.tcl
%xsdb aieprofile start -graphs dut -work-dir ./Work -core-metrics heat_map -memory-metrics conflicts -interface-metrics input_bandwidths:0 -interval 20 -samples 100
```

>**NOTE:**
>
>1. `-graph`: The graph profile data to be captured.
>2. `-core-metrics`: The core metrics to be captured.
>3. `-memory-metrics`: The memory metrics to be captured.
>4. `-interface-metrics`: The interface metrics to be captured.
>5. `-interval`: The sample interval in milliseconds (Default: 20).
>6. `-samples`: The number of counter samples (Default: 100).

>**IMPORTANT:** After the above command is run, wait until `Count: 10, Count: 20, ...` is displayed from the XSDB console. This indicates XSDB is ready to collect design profiling data.

### Step 2.3: Run the Application After Petalinux Boots Up on the Board

```bash
cd /run/media/mmcblk0p1
./host.exe a.xclbin
```

### Step 2.4: Inspect the Generated Files

After XSDB complete, expect to see the `aie_profile.csv`, `summary.csv` and `aie_trace_profile.run_summary` files created on the host computer at the location where XSDB is launched.

### Step 2.5: Launch Vitis Analyzer to Examine the Profiling Files

```bash
vitis_analyzer aie_trace_profile.run_summary
```

After issuing the above command, expect to see results from [Step 3 Expected Result with Vitis_Analyzer](#step-3-expected-result-with-vitis_analyzer), and continue this tutorial.

### Step 3: Expected Result with Vitis_Analyzer

The Vitis Analyzer GUI is launched, select **Profile Summary**, then **AI Engine & Memory** or **Interface Channels**.
![alt text](images/pr_hw_perf_va.png)

### Step 4: Open Multiple Profiling Runs with Vitis Analyzer\

You can run the application as many times as you would like with your preferences. However, some of these metrics' sets are interconnected because some use group events and others use individual events. For example, the heat_map metric set contains a metric that groups all kinds of stall events in a single metric along with other metrics that group data transfer events (load/store, streams, cascade, etc.) and vector instructions. To get a better view of which stall type(s) are prevalent, re-run with the stalls metric set. To better understand execution, re-run with the execution metric set.

### Step 4.1: Generate the First Profiling Data

Apply `heat_map` for `core-metrics`, `conflicts` for `memory-metrics`, and `input_bandwidths` for `interface-metrics` to collect the first profiling data.

Follow Step 1.1 to 1.4 if using the XRT flow, or follow Step 2.1 to 2.4 if using the XSDB flow. Save the profiling data to a directory, for example, `profile_0`.

### Step 4.2: Generate the Second Profiling Data

Apply `execution` for `core-metrics`, `dma_locks` for `memory-metrics`, and `output_bandwidths` for `interface-metrics` to collect the second profiling data.

Follow Step 1.1 to 1.4 if using the XRT flow, or follow Step 2.1 to 2.4 if using the XSDB flow. Save the profiling data to a directory, for example, `profile_1`.

### Step 4.3: Open the First Profiling Data

Follow Step 1.5 for the XRT flow, or follow Step 2.5 for the XSDB flow to open the first profiling `run_summary` file with vitis_analyzer.

### Step 4.4: Open the Second Profiling Data

Click **+** from GUI to browse and select the second profiling `run_summary` file. Two runs of profiling data are combined.

![Missing Image](images/pr_hw_perf_va_1.png)

This example combines the first run with the `heat_map`, `conflicts`, and `input_bandwidths` metrics and the second run with the `execution`, `dma_locks`, and `output_bandwidth` metrics.

Click **%** to toggle between absolute and percentage values of the collected design metrics.

![Missing Image](images/pr_hw_perf_va_2.png)

Click the column header to sort the data within those rows. Click once to display the selected row data in ascending order. Click twice to display the selected row data in descending order. Click three times to disable the sorting function.

![Missing Image](images/pr_hw_perf_va_4.png)

### Profiling Data Explanation

An easy way to know the definition of the profile data category by moving the cursor to the column title. For example, `Active Time (ms)` is "Amount of time (in ms) AI Engine was active when it was enabled."

#### AI Engine Core Profiling Data

1. `Active Time (ms)` = `Stall Time (ms)` + `Active Utilization Time (ms)`.
2. Take `tile(6,0)` as an example; `tile(6,0)` is active for a period of 1.401 milliseconds, where 1.333 milliseconds is stalled and 0.069 milliseconds is actively executing instructions. During the 0.069 milliseconds active period, 0.061 milliseconds is executing vector instructions. There are 0.008 milliseconds spent on other instructions such as load/store instructions.
3. There are 76800 `Vector instructions`, 79303 `Load Instructions`, and 1135 `Store Instructions` during `Active Utilization Time (ms)`.

#### AI Engine Memory Profiling Data

1. `Memory Conflict Time (ms)` indicates the memory access conflicts time running AI Engine execution. AMD recommends rerunning `aiesimulator` with the `-enable-memory-check` option to check the design memory access conflicts.
2. `Cumulative Memory Errors Time (ms)` indicates the time taken due to error-correction code (ECC) errors in any of the data memory banks as well as MM2S and S2MM DMAs.

#### Interface Profiling Data

1. Select `Profile Summary`, then `Interface Channels`.

    ![image missing](images/pr_hw_perf_va_3.png)

2. `PLIO Bandwidth` displays the design ran with PLIO bandwidth in the unit of MB/s. This info is a good indication that the design is an I/O bound or compute bound design and provides guidance to optimize design performance.

### Profiling Data Analysis

1. From the AI Engine core profiling data, `tile(6,1), tile(6,3),...` have much larger number of `Store Instructions`. An indication check tile source code if lowering number of `Store Instructions` can be done to improve performance.
2. From the AI Engine Memory profiling data, `tile(6,1), tile(9,0),...` have non-zero `Memory Conflict Time` value. Suggest running AIE simulator to check for memory access violations and clear those violations if any.
3. From the AI Engine Memory profiling data, `tile(6,1), tile(6,3),...` have longer `Cumulative DMA Lock Stalls Time`. This leads to check input/output PLIO area to see if PLIO frequency or PLIO width is implemented properly. Suggest using Integrated Logic Analyzer (ILA) to check PLIO input/output states during run time.
4. From the AI Engine Interface profiling data, the hardware profiling data shows design `PLIO Bandwidth`. Apply sorting function by click on `PLIO Bandwidth (MB/s)` to examine highest and lowest PLIO bandwidth.  The highest is 289.741 MB/s vs. lowest 254.709 MB/s is over 13% difference. This difference suggests that you check PLIO input/output implementation and use ILA checking PLIO input/output during run time.

# Support

GitHub issues will be used for tracking requests and bugs. For questions, go to [support.xilinx.com](https://support.xilinx.com/).

<p class="sphinxhide" align="center"><sub>Copyright © 2020–2023 Advanced Micro Devices, Inc</sub></p>

<p class="sphinxhide" align="center"><sup><a href="https://www.amd.com/en/corporate/copyright">Terms and Conditions</a></sup></p>
