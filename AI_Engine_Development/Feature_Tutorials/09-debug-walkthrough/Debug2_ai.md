﻿<table class="sphinxhide" width="100%">
 <tr>
   <td align="center"><img src="https://raw.githubusercontent.com/Xilinx/Image-Collateral/main/xilinx-logo.png" width="30%"/><h1>AI Engine Debug Walkthrough Tutorial - From Simulation to Hardware</h1>
   </td>
 </tr>
 <tr>
 <td align="center"><h2>AI Engine Debug with AI Engine Emulator</h2>
 </td>
 </tr>
</table>

The AI Engine emulator provides the following features:

* Cycle approximate simulation.
* Hardware constraints check such as AI Engine heap/stack/program memory size.
* Functional verification of the kernel code via `printf()` and value change dump (VCD) file generation.
* Performance verification of the kernel code using the VCD file generation and generating profile reports.
* Out-of-bound memory access checks of the kernel code.

The following steps showcase the AI Engine Emulator features:

[1. AI Engine Emulator Source Code Debug](#1-ai-engine-emulator-source-code-debug)

* [AI Engine Emulator Source Code Debug Limitations](#ai-engine-emulator-source-code-debug-limitations)

[2. AI Engine Emulator Trace and Profile Data Generation](#2-ai-engine-emulator-trace-and-profile-data-generation)

[3. AI Engine Emulator printf support](#3-ai-engine-emulator-printf-support)

* [printf Limitations](#printf-limitations)

[4. AI Engine Emulator --enable-memory-check option](#4-ai-engine-emulator---enable-memory-check-option)

[5. Command-Line Project Source Code Debug with AI Engine emulator](#5-command-line-project-source-code-debug-with-ai-engine-emulator)

## 1. AI Engine Emulator Source Code Debug

### Step 1: Select the AI Engine Configuration

From the top menu, select **Emulation-AIE** as the current active configuration.

![alt text](images/aie_sim_config.png)

### Step 2: Build with the AI Engine Emulator

Right-click the AI Engine project, and select **Build Project** to build.

![alt text](images/aie_sim_build.png)

### Step 3: Debug with the AI Engine Emulator

Right-click the AI Engine project, select **Debug As**, and **Launch AIE Emulator** to debug AI Engine project.

![alt text](images/he_debug_aie0.png)

### Step 4: Source Code Debug with the AI Engine Emulator

After the debugger is launched, the resume, disconnect, step into, step over, and step return buttons can be used to examine the source code execution flow. Placing the cursor on each available button pops up information about that button's functionality.
![alt text](images/he_debug.png)

From the source code view, double-click a line number to set up a breakpoint. The breakpoint view will show the newly added breakpoint.

![alt text](images/he_debug_breakpoint.png)

During debug, highlighted areas indicate changes in values since the last step.
![alt text](images/he_run_aie.png)

### Step 5: Verify the Result

The AI Engine emulator output files from the design are located at `${PROJECT}/Emulation-AIE/aiesimulator_output/data`. Verify the output files `${PROJECT}/Emulation-AIE/aiesimulation_output/data/dlbf_out[0-7].txt` and `${PROJECT}/Emulation-AIE/aiesimulation_output/data/ulbf_out[0-3].txt` against the golden files `${PROJECT}/data/dlbf_gold[0-7].txt` and `${PROJECT}/data/ulbf_gold[0-3].txt` to ensure that the design's I/O functionalities are correct. Vitis IDE supports the compare with feature to compare two files; highlight the files to be compared, then right-click one of highlighted files, and select `compare with` > `each other with transformation` > `Predefined filters` > `Remove timestamp`. Selecting `each other with transformation` is required because AI Engine emulation inserts a timestamp for each output data.

## AI Engine Emulator Source Code Debug Limitations

1. There are maximum four breakpoints available for each tile. The program under debug is stopped at first line of `main()`. This does not impact those available breakpoints.
2. Because the compiler `-O0` option is not supported, non-sequential execution when stepping through the source code is expected.
3. If an individual kernel is highlighted, select the resume button to continue execution until next the breakpoint or blocked to wait for I/O. If highlight the beamformer design, select the resume button to resume all kernels execution until meet each kernel's breakpoint or blocked  waiting for each kernel's I/O operation.
4. Due to compiler optimization, some variables' values are stored in registers. "N/A" is shown in variables view for those optimized variables' values.

## 2. AI Engine Emulator Trace and Profile Data Generation

### Step 1: Configuration Before Launching AI Engine Simulator

Highlight the beamformer sub-project, and right-click to select **Run As** > **Run configurations...** to enter into a configuration that allows trace and profile selection.

![alt text](images/aie_sim_init.png)

>**NOTE:** Enable VCD generation for event trace and enable profile generation for selected/all tiles.

![alt text](images/aie_sim_init1.png)

>**NOTE:** The `--simulation-cycle-timeout` shown in the previous image is OPTIONAL. In case of long run time, this option helps to control execution period so that trace and profile can be generated properly. Clear this option for other tests especially for source code debug to avoid a shorter run time.

### Step 2: Launch AI Engine Emulator

After run configuration is completed, right-click the beamformer sub-project to select **Run As** and **Launch AIE Emulator**.
![alt text](images/aie_sim_run.png)
The Vitis IDE console displays `[Warning] : Sim result: 0`, which indicates this simulation run is completed.

### Step 3: Launch Vitis Analyzer

Double-click **${AIE_PROJECT}/Emulation-AIE/aiesimulator_output/default.aierun_summary** to launch Vitis_analyzer for event trace and profile information.
![alt text](images/aie_sim_va_launch.png)

![alt text](images/aie_sim_va.png)
![alt text](images/aie_sim_profile.png)

>**NOTE:**
>
>1. Click **Trace** for the generated event trace info. Click **Profile** for the selected AI Engine tiles' profile report files. These events are timing approximately accurate and can be a good reference for how the design runs.
>2. The trace view supports data visualization feature that displays input/output data along with time line to help visualize I/O data of a kernel at given time.

## 3. AI Engine Emulator `printf` Support

The simplest form of tracing is to use a formatted `printf()` statement in the code for printing debug messages. Visual inspection of intermediate values and addresses can help you understand the progress of program execution. No additional include files are necessary for using `printf()` other than standard C/C++ includes (`stdio.h`). You can add `printf()` statements to your code to be processed during simulation, or hardware emulation, and remove them or comment them out for hardware builds.

### Step 1: Add the `printf` Statement in Source Code

Select the `bf8x8_fst_api.cpp` file in Vitis IDE to be edited. Add a `printf("prbcnt=%d\n", prbcnt);` statement at line 42 of the `bf8x8_fst_api.cpp` file.

>**NOTE:** Adding `printf()` statements to your AI Engine kernel code will increase the compiled size of the AI Engine program. Be careful that the compiled size of your kernel code does not exceed the per-AI Engine processor memory limit of 16 KB.

### Step 2: Build the Project

Highlight the beamformer sub-project, right-click to enable pull-down menu, and select **Build Project** to build the beamformer project.

### Step 3: Enable `printf` in Run Configuration

To enable `printf()` function, it is required to specify `--profile` in run configuration.

![alt text](images/aie_sim_printf0.png)

### Step 4: Run the Project

Highlight the beamformer sub-project, right-click to enable pull-down menu, and select **Run As** and **Launch AIE Emulator** to run the project in Vitis IDE.

### Step 5: Expected Result

Output of `printf()` statements displays on the console window.
![alt text](images/aie_sim_printf.png)

### `printf` Limitations

Adding `printf()` statements increases program memory size. Make sure not to exceed program memory size when using `printf()` statements to debug.

## 4. AI Engine Emulator `--enable-memory-check` Option

This option helps to find out-of-range memory access from each tile during AI Engine emulation run time; however, this option impacts run time performance negatively. The 'out of range' memory access indicates valid address assignment within each section. There could be certain addresses that are not assigned between sections. Hence, this option is useful to debug the design.

### Step 1. Identify an Invalid Address from Design

From a Linux terminal that points to a valid Vitis IDE installation/setup, issue this command to list a specific tile's valid memory addresses and sizes assigned by the AI Engine compiler. Flag "A" indicates this section will be loaded into tile memory.

```bash
# For Vitis IDE project
cd ${PROJECT_PATH}/Emulation-AIE/Work/aie/6_0/Release
# For command line project
cd ${PROJECT_PATH}/Work/aie/6_0/Release
readelf -S 6_0
```

![alt text](images/aie_sim_mem-check1.png)

### Step 2: Add Access to an Invalid Memory Address

Add these seven lines at line 35 of `bf8x8_fst_api.cpp` file to access invalid memory address access, for example, `0x00039900`.

```bash
#if 1
    // demo
//  volatile int *loc = (volatile int *)0xdeadbeef;
    volatile int *loc = (volatile int *)0x00039900;
    int test = *loc;
#endif
```

### Step 3: Build the Application

Highlight the beamformer sub-project, right-click to enable pull-down menu, and select **Build Project** to build the project.

### Step 4: Add the `--enable-memory-check` Option in Build Configuration

Highlight beamformer sub-project, and right-click to select **Run As** > **Run configurations...**. Add **--enable-memory-check** option to run configuration.

### Step 5: Run the Application

Highlight the beamformer sub-project, right-click to enable pull-down menu, and select **Run As** > **Launch AIE Emulator** to run the project in Vitis IDE.

### Step 6. Expected Result

Access location at address 0x00039900 that is between sections and is not allowed to access. This triggers the memory check error(s) and displays at Vitis IDE console.

![alt text](images/aie_sim_mem-check3.png)

>**NOTE:** The error messages might be rolled out of visible area, so scroll up from console window to inspect the expected error messages.

### Step 7: Additional Test

For invalid memory access that is out of kernel program memory range, for example, `0xdeadbeef`, a segfault error will be thrown regardless of whether the `--enable-memory-check` option is enabled/disabled. Comment out line 38 and uncomment line 37 from the previous source code update. Repeat Step 3 and 4 to build and run the updated code. Expect to see the segfault error from Vitis IDE console.
![alt text](images/aie_sim_mem-check4.png)

### Step 8: Clean Up

Remove those added seven lines of the `bf8x8_fst_api.cpp` file from Step 2 to maintain source code sanity.

## 5. Command Line Project Source Code Debug with the AI Engine Emulator

Use cases that involve using Vitis IDE functionalities without migrating to Vitis IDE are permitted.

### Step 1: Download the Project

Clone the project source from git repository, and unzip the zip file.

### Step 2. Build the Command-Line Project with Debug Capabilities

Use this tutorial's `Makefile.emu`  that has the `--package.enable_aie_debug`  option in the packaging step. This option inserts configuration data object (CDO) that generates stop requests for the AI Engine cores, so that they stop at the reset vector. This option is required to add debug capabilities. Issue command `make package_dbg` with this tutorial's `Makefile.emu` to package binaries that can be debugged.

```bash
cp Makefile.emu Makefile
make
make package_dbg
```

>**NOTE:**
>
>1. The packaged binaries that have debug capabilities require to run with the debugger. Run without the debugger will see the execution hang due to the wait for debugger invocation. Issue command `make package` to package binaries back without debugging capabilities.
>2. Beamformer design takes about 60 minutes or more to build. It depends on the build computer's spec.

### Step 3. Launch Hardware Emulator and Boot Petalinux

There are two Linux terminals required. Both terminals are required to point to a valid Vitis IDE installation/setup area to use Vitis software platform. From terminal 1, set up the tool path properly, and issue this command to launch hardware emulator and boot up Petalinux.

```bash
./launch_hw_emu.sh -add-env ENABLE_RDWR_DEBUG=true -add-env RDWR_DEBUG_PORT=10100 -pid-file emulation.pid -no-reboot -forward-port 1440 1534
```

Command option explanation:

1. `-add-env RDWR_DEBUG_PORT=${aie_mem_sock_port}` defines the port for communicating with the AI Engine domain. In the previous example, it is 10100.
2. `-forward-port ${linux_tcf_agent_port}` 1534 defines the port for the Linux TCF agent. In the previous example, it is 1440, which is the default.

>**NOTE**
>
>1. `launch_hw_emu.sh` is generated properly when the project under debug is built and packaged with the hardware emulator correctly. Update the repository's Makefile line 3 from `TARGET = hw` to `TARGET = hw_emu`.
>2. This command takes a few minutes to run because both hardware emulator and Petalinux are required to boot up properly.
>3. Wait until both hardware server and Petalinux boot up before moving to the next step.

### Step 4: Run the Host Application from Emulation Console

After the emulator and Petalinux boot up, issue these commands from the emulator console (terminal 1 from step 3).

```bash
cd /run/media/mmcblk0p1
./host.exe a.xclbin
```

>**NOTE:** This step is required to initialize and debug the AI Engine tiles because this design has the `--package.defer_aie_run` option.

### Step 5. Launch Vitis IDE and XRT Server

From terminal 2, set up the tool path properly, and issue this command to launch the XRT server and Vitis IDE.

```bash
vitis -debug -flow embedded -os baremetal -port 4352 -launch-script ${PROJECT_PATH}/aie_app_debug_em.tcl
xrt_server -I30000 -S -s tcp::4352
```

Command options:

1. `vitis -debug`: Launches the Vitis IDE in standalone debug mode.
2. `-flow embedded`: Specifies the embedded processor flow for the AI Engine processor.
3. `-os baremetal`: For bare-metal OS of the AI Engine domain.
4. `-port 4352`: Specifies the `xrt_server` port as discussed in Step 3.
5. `-launch_script ${aie_project}/aie_app_debug_em.tcl`: Specifies the Tcl script which sets up the AI Engine debug environment.
6. `-I30000`: Defines an idle timeout in seconds, in which the server will quit if there is no response.
7. `-S`: Specifies print server properties in JSON format to stdout.
8. `-s tcp::${xrt_server_port}`: Defines the agent listening protocol and port. It is 4352 in example, but can be any free port.

>**NOTE:** The Debugger could be blocked from PS execution initially. Run the PS application from the simulator shell so the debugger stops at first line of the main function (default) from the AI Engine tiles.

### Step 6: Expected Vitis IDE

![alt text](images/aie_cl_run.png)

### Step 7. Clean up Launched Processes

```bash
killall -9 pllauncher; killall -9 qemu-system-aarch64; killall -9 xrt_server
```

# Support

GitHub issues will be used for tracking requests and bugs. For questions, go to [support.xilinx.com](https://support.xilinx.com/).

<p class="sphinxhide" align="center"><sub>Copyright © 2020–2023 Advanced Micro Devices, Inc</sub></p>

<p class="sphinxhide" align="center"><sup><a href="https://www.amd.com/en/corporate/copyright">Terms and Conditions</a></sup></p>
