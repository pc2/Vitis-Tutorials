/*
Copyright (C) 2023, Advanced Micro Devices, Inc. All rights reserved.
SPDX-License-Identifier: X11
*/

/********************************************* Disclaimer *********************************************/
/* This file is generated by aiecompiler 2022.1. */
/* Changes to this file may cause incorrect behavior and will be lost if aiecompiler is invoked again.*/

#include <iostream>
#include "adf/adf_api/AIEControlConfig.h"


/************************** Graph Configurations  *****************************/

  adf::GraphConfig GraphConfigurations[] = {
  //{id, name, graphLoadElfFunc, graphInitFunc, graphDebugHalt, coreColumns, coreRows, iterMemColumns, iterMemRows, iterMemAddrs, triggered, plKernelInstanceNames, plAxiLiteModes, plDriverStartFuncs, plDriverCheckIPDoneFuncs}
    {0, "dut", nullptr, nullptr, nullptr, {6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13, 14, 14, 14, 14, 15, 15, 15, 15, 16, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 18, 19, 19, 19, 19, 20, 20, 20, 20, 21, 21, 21, 21}, {0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3}, {6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13, 14, 14, 14, 14, 15, 15, 15, 15, 16, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 18, 19, 19, 19, 19, 20, 20, 20, 20, 21, 21, 21, 21}, {0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3}, {0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4, 0x17e4}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {}, {}, {}, {},  }, 
  };
  const int NUM_GRAPH = 1;

/************************** PLIO Configurations  *****************************/

  adf::PLIOConfig PLIOConfigurations[] = {
  //{id, name, loginal_name, shim_column, slaveOrMaster, streamId}
    {0, "dut.dldin[0]", "dlbfid0", 10, 0, 5},
    {1, "dut.dldin[1]", "dlbfid1", 10, 0, 6},
    {2, "dut.dldin[2]", "dlbfid2", 8, 0, 4},
    {3, "dut.dldin[3]", "dlbfid3", 13, 0, 4},
    {4, "dut.dlcin[0]", "dlbfic00", 6, 0, 0},
    {5, "dut.dlcin[1]", "dlbfic01", 7, 0, 0},
    {6, "dut.dlcin[2]", "dlbfic02", 8, 0, 2},
    {7, "dut.dlcin[3]", "dlbfic03", 9, 0, 0},
    {8, "dut.dlcin[4]", "dlbfic10", 6, 0, 6},
    {9, "dut.dlcin[5]", "dlbfic11", 7, 0, 6},
    {10, "dut.dlcin[6]", "dlbfic12", 8, 0, 0},
    {11, "dut.dlcin[7]", "dlbfic13", 9, 0, 6},
    {12, "dut.dlcin[8]", "dlbfic20", 6, 0, 1},
    {13, "dut.dlcin[9]", "dlbfic21", 7, 0, 1},
    {14, "dut.dlcin[10]", "dlbfic22", 8, 0, 6},
    {15, "dut.dlcin[11]", "dlbfic23", 9, 0, 1},
    {16, "dut.dlcin[12]", "dlbfic30", 6, 0, 4},
    {17, "dut.dlcin[13]", "dlbfic31", 7, 0, 4},
    {18, "dut.dlcin[14]", "dlbfic32", 8, 0, 1},
    {19, "dut.dlcin[15]", "dlbfic33", 9, 0, 4},
    {20, "dut.dlcin[16]", "dlbfic40", 10, 0, 0},
    {21, "dut.dlcin[17]", "dlbfic41", 11, 0, 0},
    {22, "dut.dlcin[18]", "dlbfic42", 12, 0, 0},
    {23, "dut.dlcin[19]", "dlbfic43", 13, 0, 2},
    {24, "dut.dlcin[20]", "dlbfic50", 10, 0, 1},
    {25, "dut.dlcin[21]", "dlbfic51", 11, 0, 6},
    {26, "dut.dlcin[22]", "dlbfic52", 12, 0, 6},
    {27, "dut.dlcin[23]", "dlbfic53", 13, 0, 0},
    {28, "dut.dlcin[24]", "dlbfic60", 10, 0, 2},
    {29, "dut.dlcin[25]", "dlbfic61", 11, 0, 1},
    {30, "dut.dlcin[26]", "dlbfic62", 12, 0, 1},
    {31, "dut.dlcin[27]", "dlbfic63", 13, 0, 6},
    {32, "dut.dlcin[28]", "dlbfic70", 10, 0, 4},
    {33, "dut.dlcin[29]", "dlbfic71", 11, 0, 4},
    {34, "dut.dlcin[30]", "dlbfic72", 12, 0, 4},
    {35, "dut.dlcin[31]", "dlbfic73", 13, 0, 1},
    {36, "dut.dlout[0]", "dlbfo0", 9, 1, 1},
    {37, "dut.dlout[1]", "dlbfo1", 6, 1, 1},
    {38, "dut.dlout[2]", "dlbfo2", 9, 1, 3},
    {39, "dut.dlout[3]", "dlbfo3", 6, 1, 3},
    {40, "dut.dlout[4]", "dlbfo4", 13, 1, 1},
    {41, "dut.dlout[5]", "dlbfo5", 10, 1, 1},
    {42, "dut.dlout[6]", "dlbfo6", 13, 1, 3},
    {43, "dut.dlout[7]", "dlbfo7", 10, 1, 3},
    {44, "dut.uldin[0]", "ulbfid0", 14, 0, 4},
    {45, "dut.uldin[1]", "ulbfid1", 15, 0, 4},
    {46, "dut.uldin[2]", "ulbfid2", 16, 0, 4},
    {47, "dut.uldin[3]", "ulbfid3", 17, 0, 4},
    {48, "dut.uldin[4]", "ulbfid4", 18, 0, 4},
    {49, "dut.uldin[5]", "ulbfid5", 19, 0, 4},
    {50, "dut.uldin[6]", "ulbfid6", 20, 0, 4},
    {51, "dut.uldin[7]", "ulbfid7", 21, 0, 4},
    {52, "dut.ulcin[0]", "ulbfic00", 14, 0, 2},
    {53, "dut.ulcin[1]", "ulbfic01", 15, 0, 2},
    {54, "dut.ulcin[2]", "ulbfic02", 16, 0, 2},
    {55, "dut.ulcin[3]", "ulbfic03", 17, 0, 2},
    {56, "dut.ulcin[4]", "ulbfic04", 18, 0, 2},
    {57, "dut.ulcin[5]", "ulbfic05", 19, 0, 2},
    {58, "dut.ulcin[6]", "ulbfic06", 20, 0, 2},
    {59, "dut.ulcin[7]", "ulbfic07", 21, 0, 2},
    {60, "dut.ulcin[8]", "ulbfic10", 14, 0, 0},
    {61, "dut.ulcin[9]", "ulbfic11", 15, 0, 0},
    {62, "dut.ulcin[10]", "ulbfic12", 16, 0, 0},
    {63, "dut.ulcin[11]", "ulbfic13", 17, 0, 0},
    {64, "dut.ulcin[12]", "ulbfic14", 18, 0, 0},
    {65, "dut.ulcin[13]", "ulbfic15", 19, 0, 0},
    {66, "dut.ulcin[14]", "ulbfic16", 20, 0, 0},
    {67, "dut.ulcin[15]", "ulbfic17", 21, 0, 0},
    {68, "dut.ulcin[16]", "ulbfic20", 14, 0, 6},
    {69, "dut.ulcin[17]", "ulbfic21", 15, 0, 6},
    {70, "dut.ulcin[18]", "ulbfic22", 16, 0, 6},
    {71, "dut.ulcin[19]", "ulbfic23", 17, 0, 6},
    {72, "dut.ulcin[20]", "ulbfic24", 18, 0, 6},
    {73, "dut.ulcin[21]", "ulbfic25", 19, 0, 6},
    {74, "dut.ulcin[22]", "ulbfic26", 20, 0, 6},
    {75, "dut.ulcin[23]", "ulbfic27", 21, 0, 6},
    {76, "dut.ulcin[24]", "ulbfic30", 14, 0, 1},
    {77, "dut.ulcin[25]", "ulbfic31", 15, 0, 1},
    {78, "dut.ulcin[26]", "ulbfic32", 16, 0, 1},
    {79, "dut.ulcin[27]", "ulbfic33", 17, 0, 1},
    {80, "dut.ulcin[28]", "ulbfic34", 18, 0, 1},
    {81, "dut.ulcin[29]", "ulbfic35", 19, 0, 1},
    {82, "dut.ulcin[30]", "ulbfic36", 20, 0, 1},
    {83, "dut.ulcin[31]", "ulbfic37", 21, 0, 1},
    {84, "dut.ulout[0]", "ulbfo0", 21, 1, 1},
    {85, "dut.ulout[1]", "ulbfo1", 14, 1, 1},
    {86, "dut.ulout[2]", "ulbfo2", 21, 1, 3},
    {87, "dut.ulout[3]", "ulbfo3", 14, 1, 3},
  };
  const int NUM_PLIO = 88;


/************************** ADF API initializer *****************************/

  class InitializeAIEControlXRT
  {
  public:
    InitializeAIEControlXRT()
    {
      std::cout<<"Initializing ADF API..."<<std::endl;
#ifdef __EXCLUDE_PL_CONTROL__
      bool exclude_pl_control = true;
#else
      bool exclude_pl_control = false;
#endif
      adf::initializeConfigurations(nullptr, 0, 0, 0,
                                    GraphConfigurations, NUM_GRAPH,
                                    nullptr, 0,
                                    nullptr, 0,
                                    nullptr, 0,
                                    nullptr, 0,
                                    nullptr, 0,
                                    nullptr, 0,
                                    PLIOConfigurations, NUM_PLIO,
                                    nullptr, 0, 0, nullptr,
                                    false, exclude_pl_control, false, nullptr,
                                    true, 2);

    }
  } initAIEControlXRT;



#if !defined(__CDO__)

// Kernel Stub Definition
  void bf8x8_fst_api(input_window<cint16> *,input_window<cint16> *,output_stream<cacc48_t> *) { /* Stub */ } 
  void bf8x8_lst_api(input_window<cint16> *,input_window<cint16> *,input_stream<cacc48_t> *,output_window<cint16> *) { /* Stub */ } 
  void bf8x8_mid_api(input_window<cint16> *,input_window<cint16> *,input_stream<cacc48_t> *,output_stream<cacc48_t> *) { /* Stub */ } 
#endif
