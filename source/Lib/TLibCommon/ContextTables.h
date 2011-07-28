/* The copyright in this software is being made available under the BSD
 * License, included below. This software may be subject to other third party
 * and contributor rights, including patent rights, and no such rights are
 * granted under this license.  
 *
 * Copyright (c) 2010-2011, ITU/ISO/IEC
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *  * Neither the name of the ITU/ISO/IEC nor the names of its contributors may
 *    be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/** \file     ContextTables.h
    \brief    Defines constants and tables for SBAC
    \todo     number of context models is not matched to actual use, should be fixed
*/

#ifndef __CONTEXTTABLES__
#define __CONTEXTTABLES__

// ====================================================================================================================
// Constants
// ====================================================================================================================

#define NUM_SPLIT_FLAG_CTX            3       ///< number of context models for split flag
#define NUM_SKIP_FLAG_CTX             3       ///< number of context models for skip flag

#if DNB_MERGE_FLAG
#define NUM_MERGE_FLAG_EXT_CTX        1       ///< number of context models for merge flag of merge extended
#else
#define NUM_MERGE_FLAG_EXT_CTX        3       ///< number of context models for merge flag of merge extended
#endif
#define NUM_MERGE_IDX_EXT_CTX         4       ///< number of context models for merge index of merge extended

#if DNB_ALF_CTRL_FLAG
#define NUM_ALF_CTRL_FLAG_CTX         1       ///< number of context models for ALF control flag
#else
#define NUM_ALF_CTRL_FLAG_CTX         3       ///< number of context models for ALF control flag
#endif
#define NUM_PART_SIZE_CTX             5       ///< number of context models for partition size
#define NUM_PRED_MODE_CTX             2       ///< number of context models for prediction mode
#if MTK_DCM_MPM
#define NUM_ADI_CTX                   3       ///< number of context models for intra prediction
#else
#define NUM_ADI_CTX                   2
#endif
#if ADD_PLANAR_MODE
#define NUM_PLANARFLAG_CTX            2       ///< number of context models for planar mode flag (intra prediction)
#endif

#if DNB_INTRA_CHR_PRED_MODE
#define NUM_CHROMA_PRED_CTX           2       ///< number of context models for intra prediction (chroma)
#else
#define NUM_CHROMA_PRED_CTX           4       ///< number of context models for intra prediction (chroma)
#endif
#define NUM_INTER_DIR_CTX             4       ///< number of context models for inter prediction direction
#if MODIFIED_MVD_CODING
#define NUM_MV_RES_CTX                2       ///< number of context models for motion vector difference
#else
#define NUM_MV_RES_CTX                7       ///< number of context models for motion vector difference
#endif

#if DNB_REF_FRAME_IDX
#define NUM_REF_NO_CTX                4       ///< number of context models for reference index
#else
#define NUM_REF_NO_CTX                6       ///< number of context models for reference index
#endif
#define NUM_TRANS_SUBDIV_FLAG_CTX     10      ///< number of context models for transform subdivision flags
#define NUM_QT_CBF_CTX                5       ///< number of context models for QT CBF
#define NUM_QT_ROOT_CBF_CTX           4       ///< number of context models for QT ROOT CBF
#define NUM_DELTA_QP_CTX              4       ///< number of context models for dQP

#define NUM_SIG_FLAG_CTX              50      ///< number of context models for sig flag
#if MODIFIED_LAST_CODING
#define NUM_CTX_LAST_FLAG_XY          19      ///< number of context models for PCP last flag
#else
#define NUM_CTX_LAST_FLAG_XY          26      ///< number of context models for PCP last flag
#endif
#define NUM_ONE_FLAG_CTX              30      ///< number of context models for greater than one
#define NUM_ABS_FLAG_CTX              30      ///< number of context models for magnitude

#define NUM_MVP_IDX_CTX               2       ///< number of context models for MVP index

#define NUM_ALF_FLAG_CTX              1       ///< number of context models for ALF flag
#define NUM_ALF_UVLC_CTX              2       ///< number of context models for ALF UVLC (filter length)
#define NUM_ALF_SVLC_CTX              3       ///< number of context models for ALF SVLC (filter coeff.)

#if MTK_SAO
#define NUM_AO_FLAG_CTX              1       ///< number of context models for AO flag
#define NUM_AO_UVLC_CTX              2       ///< number of context models for AO UVLC (filter length)
#define NUM_AO_SVLC_CTX              3       ///< number of context models for AO SVLC (filter coeff.)
#endif

// ====================================================================================================================
// Tables
// ====================================================================================================================

// initial probability for split flag
static const Short
INIT_SPLIT_FLAG[3][NUM_SPLIT_FLAG_CTX][2] =
{
  {
    {   -7,   68 }, {  -10,   87 }, {  -10,  105 }
  },
  {
    {  -14,   71 }, {   -6,   73 }, {   -6,   91 }
  },
  {
    {  -14,   71 }, {   -7,   74 }, {  -10,   92 }
  }
};

// initial probability for skip flag
static const Short
INIT_SKIP_FLAG[3][NUM_SKIP_FLAG_CTX][2] =
{
  {
    {    0,   64 }, {    0,   64 }, {    0,   64 }
  },
  {
    {    0,   64 }, {    0,   64 }, {    0,   64 }
  },
  {
    {    0,   64 }, {    0,   64 }, {    0,   64 }
  }
};

// initial probability for skip flag
#if DNB_ALF_CTRL_FLAG
static const Short
INIT_ALF_CTRL_FLAG[3][NUM_ALF_CTRL_FLAG_CTX][2] =
{
  {
    {    0,   64 }
  },
  {
    {    0,   64 }
  },
  {
    {    0,   64 }
  }
};
#else
static const Short
INIT_ALF_CTRL_FLAG[3][NUM_ALF_CTRL_FLAG_CTX][2] =
{
  {
    {    0,   64 }, {    0,   64 }, {    0,   64 }
  },
  {
    {    0,   64 }, {    0,   64 }, {    0,   64 }
  },
  {
    {    0,   64 }, {    0,   64 }, {    0,   64 }
  }
};
#endif

// initial probability for merge flag
#if DNB_MERGE_FLAG
static const Short
INIT_MERGE_FLAG_EXT[3][NUM_MERGE_FLAG_EXT_CTX][2] =
{
  {
    {    0,   64 }
  },
  {
    {    0,   64 }
  },
  {
    {    0,   64 }
  }
};
#else
static const Short
INIT_MERGE_FLAG_EXT[3][NUM_MERGE_FLAG_EXT_CTX][2] =
{
  {
    {    0,   64 }, {    0,   64 }, {    0,   64 }
  },
  {
    {    0,   64 }, {    0,   64 }, {    0,   64 }
  },
  {
    {    0,   64 }, {    0,   64 }, {    0,   64 }
  }
};
#endif

static const Short
INIT_MERGE_IDX_EXT[3][NUM_MERGE_IDX_EXT_CTX][2] =
{
  {
    {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }
  },
  {
    {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }
  },
  {
    {    1,   65 }, {    6,   42 }, {   -7,   75 }, {   -4,   72 }
  }
};

// initial probability for PU size
static const Short
INIT_PART_SIZE[3][NUM_PART_SIZE_CTX][2] =
{
  {
    {    0,   73 }, {    0,   64 }, {    0,   64 }, {    0,   64 }, 
    {    0,   64 }
  },
  {
    {   -1,   64 }, {   -3,   63 }, {    6,   78 }, {    0,   64 }, 
    {    0,   64 }
  },
  {
    {    6,   50 }, {   -1,   56 }, {   13,   53 }, {  -11,   76 }, 
    {  -11,   70 }
  }
};

// initial probability for prediction mode
static const Short
INIT_PRED_MODE[3][NUM_PRED_MODE_CTX][2] =
{
  {
    {    0,   64 }, {    0,   64 }
  },
  {
    {    0,   64 }, {  -25,   89 }
  },
  {
    {    0,   64 }, {    0,   64 }
  }
};

// initial probability for intra direction of luma
#if MTK_DCM_MPM
static const Short
INIT_INTRA_PRED_MODE[3][NUM_ADI_CTX][2] =
{
  {
    {    2,   54 }, {  -3,   65  }, {   -3,   65 }
  },
  {
    {    0,   50 }, {  -2,   61  }, {   -2,   61 }
  },
  {
    {    0,   51 }, {  1,   55   }, {    1,   55 }
  }
};
#else
static const Short
INIT_INTRA_PRED_MODE[3][NUM_ADI_CTX][2] =
{
  {
    {    2,   54 }, {   -3,   65 }
  },
  {
    {    0,   50 }, {   -2,   61 }
  },
  {
    {    0,   51 }, {    1,   55 }
  }
};
#endif

#if ADD_PLANAR_MODE
// initial probability for planar mode flag
static const Short
INIT_PLANARFLAG[3][NUM_PLANARFLAG_CTX][2] =
{
  {
    {    0,   64 }, {    0,   64 }
  },
  {
    {    0,   64 }, {    0,   64 }
  },
  {
    {    0,   64 }, {    0,   64 }
  }
};
#endif

// initial probability for intra direction of chroma
#if DNB_INTRA_CHR_PRED_MODE
static const Short
INIT_CHROMA_PRED_MODE[3][NUM_CHROMA_PRED_CTX][2] =
{
  {
    {  0,   64 }, {   0,   64 }
  },
  {
    {  0,   64 }, {   0,   64 }
  },
  {
    {  0,   64 }, {   0,   64 }
  }
};
#else
static const Short
INIT_CHROMA_PRED_MODE[3][4][2] =
{
  {
    {  0,   64 }, {   0,   64 }, {  0,  64 }, {  0,  64 }
  },
  {
    {  0,   64 }, {   0,   64 }, {  0,  64 }, {  0,  64 }
  },
  {
    {  0,   64 }, {   0,   64 }, {  0,  64 }, {  0,  64 }
  }
};
#endif

// initial probability for temporal direction
static const Short
INIT_INTER_DIR[3][4][2] =
{
  {
    {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }
  },
  {
    {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }
  },
  {
    {   -2,   58 }, {   -5,   70 }, {   -9,   85 }, {    1,   61 }
  }
};

// initial probability for motion vector difference
#if MODIFIED_MVD_CODING
static const
Short INIT_MVD[3][NUM_MV_RES_CTX][2] =
{
  {
    {    0,   64 }, {    0,   64 }
  },
  {
    {    0,   64 }, {    0,   64 }
  },
  {
    {    0,   64 }, {    0,   64 }
  }
};
#else
static const Short INIT_MVD[3][14][2] =
{
  {
    {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }, 
    {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }, 
    {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }, 
    {    0,   64 }, {    0,   64 }
  },
  {
    {   -6,   80 }, {   -6,   84 }, {   -9,   90 }, {    4,   62 }, 
    {   13,   55 }, {    2,   70 }, {    8,   74 }, {   -6,   77 }, 
    {   -7,   84 }, {   -9,   89 }, {    5,   59 }, {   10,   62 }, 
    {    4,   68 }, {    7,   75 }
  },
  {
    {   -4,   75 }, {   -5,   82 }, {  -12,   94 }, {    7,   55 }, 
    {   11,   59 }, {    6,   63 }, {    8,   71 }, {   -2,   71 }, 
    {   -5,   81 }, {  -21,  111 }, {    6,   58 }, {   10,   60 }, 
    {    5,   64 }, {   10,   67 }
  }
};
#endif

// initial probability for reference frame index
#if DNB_REF_FRAME_IDX
static const Short
INIT_REF_PIC[3][NUM_REF_NO_CTX][2] =
{
  {
    {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }
  },
  {
    {   -6,   59 }, {  -17,   96 }, {    1,   59 }, {    0,   64 }
  },
  {
    {   -9,   55 }, {  -12,   86 }, {  -18,   55 }, {    0,   64 }
  }
};
#else
static const Short
INIT_REF_PIC[3][NUM_REF_NO_CTX][2] =
{
  {
    {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }, 
    {    0,   64 }, {    0,   64 }
  },
  {
    {   -6,   59 }, {  -10,   75 }, {   -8,   75 }, {  -17,   96 }, 
    {    1,   59 }, {    0,   64 }
  },
  {
    {   -9,   55 }, {   -9,   71 }, {   -9,   76 }, {  -12,   86 }, 
    {  -18,   55 }, {    0,   64 }
  }
};
#endif

// initial probability for dQP
static const Short
INIT_DQP[3][NUM_DELTA_QP_CTX][2] =
{
  {
    {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }
  },
  {
    {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }
  },
  {
    {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }
  }
};

static const Short
INIT_QT_CBF[3][3*NUM_QT_CBF_CTX][2] =
{
  {
    {  -22,  116 }, {   -5,   75 }, {  -16,  112 }, {  -16,  111 }, {  -32,  165 },
    {  -35,  116 }, {  -12,   61 }, {   -9,   73 }, {  -10,   75 }, {  -14,   96 }, 
    {  -29,  104 }, {  -12,   59 }, {   -5,   65 }, {   -6,   67 }, {  -11,   90 }
  },
  {
    {  -18,   98 }, {  -41,  120 }, {  -29,  117 }, {  -23,  108 }, {  -35,  143 },
    {  -46,  114 }, {  -42,  119 }, {  -11,   74 }, {  -19,   90 }, {  -42,  139 }, 
    {  -43,  107 }, {  -41,  118 }, {  -17,   86 }, {  -25,  101 }, {  -14,   91 }
  },
  {
    {  -11,   80 }, {  -32,   83 }, {  -19,   89 }, {  -16,   85 }, {  -19,  102 },
    {  -22,   52 }, {  -48,  123 }, {   -7,   68 }, {  -37,  121 }, {  -58,  164 }, 
    {  -19,   45 }, {  -48,  123 }, {  -21,   94 }, {   -9,   73 }, {  -42,  138 }
  }
};

static const Short
INIT_QT_ROOT_CBF[3][NUM_QT_ROOT_CBF_CTX][2] =
{
  {
    {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 },
  },
  {
    {  -22,   85 }, {  -15,   86 }, {  -13,   84 }, {  -23,  116 },
  },
  {
    {  -36,  103 }, {  -21,   95 }, {  -21,   97 }, {  -24,  114 },
  }
};

#if MODIFIED_LAST_CODING
static const Short
INIT_LAST[3][2*NUM_CTX_LAST_FLAG_XY][2] =
{
  {
    {   14,   25 }, {   10,   38 }, {   12,   41 },
    {   22,   25 }, {   10,   37 }, {    9,   40 },
    {   17,   19 }, {   15,   21 }, {   16,   18 }, {   17,   16 }, {   18,   13 }, {   16,   18 },
    {   23,   -2 }, {   20,   -2 }, {   24,   -9 }, {   24,   -7 }, {   18,   10 }, {    9,   24 }, {   22,   -7 },
    {   37,    9 }, {   35,   14 }, {   53,   -5 },
    {   31,   21 }, {   13,   39 }, {   21,   28 },
    {   35,    2 }, {   22,   17 }, {   18,   23 }, {    9,   40 }, {   14,   32 }, {    7,   44 },
    {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }
  },
  {
    {   12,   35 }, {   12,   40 }, {   13,   47 },
    {   21,   16 }, {   24,   10 }, {   23,   15 },
    {   13,   34 }, {   22,   10 }, {   29,   10 }, {   29,   -8 }, {   27,   -5 }, {   20,    7 },
    {   25,   13 }, {   30,   -8 }, {   35,  -20 }, {   37,  -29 }, {   42,  -41 }, {   42,  -45 }, {   43,  -46 },

    {   21,   36 }, {   22,   37 }, {   35,   27 },
    {   11,   53 }, {   22,   27 }, {   27,   18 },
    {   -3,   83 }, {   14,   35 }, {   23,   18 }, {   27,    3 }, {   32,  -11 }, {   17,   11 },
    {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }
  },
  {
    {   12,   35 }, {   12,   40 }, {   13,   47 },
    {   21,   16 }, {   24,   10 }, {   23,   15 },
    {   13,   34 }, {   22,   10 }, {   29,   10 }, {   29,   -8 }, {   27,   -5 }, {   20,    7 },
    {   25,   13 }, {   30,   -8 }, {   35,  -20 }, {   37,  -29 }, {   42,  -41 }, {   42,  -45 }, {   43,  -46 },

    {   21,   36 }, {   22,   37 }, {   35,   27 },
    {   11,   53 }, {   22,   27 }, {   27,   18 },
    {   -3,   83 }, {   14,   35 }, {   23,   18 }, {   27,    3 }, {   32,  -11 }, {   17,   11 },
    {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }
  }
};
#else
static const Short
INIT_LAST_X[3][2*NUM_CTX_LAST_FLAG_XY][2] =
{
  {
    {   8,  31 }, {   8,  39 }, {   8,  48 }, {  12,  31 },
    {   8,  38 }, {   6,  45 }, {   3,  46 }, {  -1,  56 },
    {  18,  16 }, {  14,  22 }, {  15,  22 }, {  16,  17 },
    {  16,  16 }, {  12,  24 }, {  -4,  59 }, {  33, -26 },
    {  18,   1 }, {  20,   2 }, {  22,  -1 }, {  17,  14 },
    {  11,  21 }, {  31, -24 }, {  38, -38 }, {  12,  11 },
    {  -4,  47 }, { -13,  69 }, {  32,  11 }, {  25,  27 },
    {  50,  -1 }, {  32,  20 }, {  12,  38 }, {  18,  32 },
    {  12,  41 }, {   5,  70 }, {  40,  -6 }, {  14,  29 },
    {  17,  26 }, {   7,  43 }, {  15,  26 }, {  15,  27 },
    {   9,  51 }, {   0,  64 }, {   0,  64 }, {   0,  64 },
    {   0,  64 }, {   0,  64 }, {   0,  64 }, {   0,  64 },
    {   0,  64 }, {   0,  64 }, {   0,  64 }, {   0,  64 }
  },
  {
    {   9,  40 }, {   9,  44 }, {  10,  52 }, {  17,  24 },
    {  21,  15 }, {  20,  20 }, {  14,  29 }, {   8,  46 },
    {   7,  46 }, {  18,  18 }, {  26,   3 }, {  26,   0 },
    {  25,   2 }, {  15,  18 }, {   9,  27 }, {  23,  20 },
    {  19,  16 }, {  27,  -1 }, {  33, -19 }, {  38, -30 },
    {  41, -39 }, {  40, -36 }, {  26, -12 }, {   3,  20 },
    {  -7,  33 }, {  -4,  20 }, {  16,  42 }, {  16,  45 },
    {  49,   7 }, {   6,  61 }, {  17,  36 }, {  24,  24 },
    {  24,  21 }, {  61, -22 }, { -11, 101 }, {   6,  53 },
    {  14,  40 }, {  17,  30 }, {  20,  22 }, { -10,  67 },
    {  -6,  68 }, {   0,  64 }, {   0,  64 }, {   0,  64 },
    {   0,  64 }, {   0,  64 }, {   0,  64 }, {   0,  64 },
    {   0,  64 }, {   0,  64 }, {   0,  64 }, {   0,  64 }
  },
  {
    {   9,  40 }, {   9,  44 }, {  10,  52 }, {  17,  24 },
    {  21,  15 }, {  20,  20 }, {  14,  29 }, {   8,  46 },
    {   7,  46 }, {  18,  18 }, {  26,   3 }, {  26,   0 },
    {  25,   2 }, {  15,  18 }, {   9,  27 }, {  23,  20 },
    {  19,  16 }, {  27,  -1 }, {  33, -19 }, {  38, -30 },
    {  41, -39 }, {  40, -36 }, {  26, -12 }, {   3,  20 },
    {  -7,  33 }, {  -4,  20 }, {  16,  42 }, {  16,  45 },
    {  49,   7 }, {   6,  61 }, {  17,  36 }, {  24,  24 },
    {  24,  21 }, {  61, -22 }, { -11, 101 }, {   6,  53 },
    {  14,  40 }, {  17,  30 }, {  20,  22 }, { -10,  67 },
    {  -6,  68 }, {   0,  64 }, {   0,  64 }, {   0,  64 },
    {   0,  64 }, {   0,  64 }, {   0,  64 }, {   0,  64 },
    {   0,  64 }, {   0,  64 }, {   0,  64 }, {   0,  64 }
  }
};

static const Short
INIT_LAST_Y[3][2*NUM_CTX_LAST_FLAG_XY][2] =
{
  {
    {  19,  19 }, {  12,  36 }, {  16,  34 }, {  22,  18 },
    {  12,  35 }, {  12,  35 }, {  12,  32 }, {   5,  46 },
    {  16,  21 }, {  15,  20 }, {  17,  13 }, {  17,  14 },
    {  19,  10 }, {  19,  12 }, {   4,  37 }, {  13,  22 },
    {  22,  -4 }, {  27, -19 }, {  26, -12 }, {  18,   6 },
    {   6,  27 }, {  12,  10 }, {  34, -33 }, {  38, -42 },
    {  24, -15 }, {  14,   7 }, {  41,   7 }, {  45,   1 },
    {  56,  -9 }, {  30,  22 }, {  14,  40 }, {  23,  24 },
    {  19,  32 }, {  25,  26 }, {  29,  10 }, {  29,   4 },
    {  19,  20 }, {  10,  37 }, {  12,  38 }, {  -2,  60 },
    { -37, 114 }, {   0,  64 }, {   0,  64 }, {   0,  64 },
    {   0,  64 }, {   0,  64 }, {   0,  64 }, {   0,  64 },
    {   0,  64 }, {   0,  64 }, {   0,  64 }, {   0,  64 }
  },
  {
    {  15,  29 }, {  14,  36 }, {  15,  41 }, {  25,   8 },
    {  26,   4 }, {  25,  10 }, {  21,  16 }, {  12,  34 },
    {  18,  21 }, {  25,   1 }, {  32, -12 }, {  32, -15 },
    {  29, -11 }, {  24,  -5 }, {  13,  12 }, {  27,   6 },
    {  40, -32 }, {  42, -39 }, {  40, -39 }, {  45, -51 },
    {  43, -51 }, {  45, -56 }, {  38, -46 }, {  15,  -6 },
    {  11,  -4 }, {  11,  -4 }, {  26,  29 }, {  28,  29 },
    {  21,  46 }, {  15,  45 }, {  27,  17 }, {  29,  12 },
    {  23,  15 }, {  -1,  57 }, {   6,  65 }, {  22,  17 },
    {  31,  -4 }, {  37, -25 }, {  43, -44 }, {  43, -46 },
    {  48, -44 }, {   0,  64 }, {   0,  64 }, {   0,  64 },
    {   0,  64 }, {   0,  64 }, {   0,  64 }, {   0,  64 },
    {   0,  64 }, {   0,  64 }, {   0,  64 }, {   0,  64 }
  },
  {
    {  15,  29 }, {  14,  36 }, {  15,  41 }, {  25,   8 },
    {  26,   4 }, {  25,  10 }, {  21,  16 }, {  12,  34 },
    {  18,  21 }, {  25,   1 }, {  32, -12 }, {  32, -15 },
    {  29, -11 }, {  24,  -5 }, {  13,  12 }, {  27,   6 },
    {  40, -32 }, {  42, -39 }, {  40, -39 }, {  45, -51 },
    {  43, -51 }, {  45, -56 }, {  38, -46 }, {  15,  -6 },
    {  11,  -4 }, {  11,  -4 }, {  26,  29 }, {  28,  29 },
    {  21,  46 }, {  15,  45 }, {  27,  17 }, {  29,  12 },
    {  23,  15 }, {  -1,  57 }, {   6,  65 }, {  22,  17 },
    {  31,  -4 }, {  37, -25 }, {  43, -44 }, {  43, -46 },
    {  48, -44 }, {   0,  64 }, {   0,  64 }, {   0,  64 },
    {   0,  64 }, {   0,  64 }, {   0,  64 }, {   0,  64 },
    {   0,  64 }, {   0,  64 }, {   0,  64 }, {   0,  64 }
  }
};
#endif

static const Short
INIT_SIG_FLAG[3][2 * NUM_SIG_FLAG_CTX][2] =
{
  {
    // Luma 4x4
    {   -4,   94 }, {   -2,   84 }, {   -4,   83 }, {   16,   39 },
    {    0,   83 }, {   -1,   81 }, {   -4,   82 }, {  -16,   91 },
    {   -9,   86 }, {   -8,   89 }, {   -2,   82 }, {  -14,   92 },
    {  -16,   91 }, {   13,   44 }, {  -12,   91 },
    // Luma 8x8
    {  -10,   91 }, {   -9,   76 }, {   -3,   61 }, {    1,   46 },
    {  -13,   84 }, {  -13,   81 }, {   -2,   60 }, {   -5,   61 },
    {  -11,   77 }, {  -10,   76 }, {   -3,   65 }, {   -3,   63 },
    {   -4,   59 }, {  -14,   79 }, {    1,   61 }, {  -33,  126 },
    // Luma 16x16
    {   -5,   99 }, {   -9,   92 }, {   -5,   90 }, {   -7,   83 },
    {   -3,   37 }, {   -1,   62 }, {   -5,   81 }, {   -2,   41 },
    {    1,   64 }, {   -6,   82 }, {    0,   12 }, {    1,   43 },
    {    0,   57 }, {   -1,   66 }, {   -4,   79 },
    // Luma 32x32
    {   -3,  102 }, {  -17,  114 }, {   -7,   97 }, {  -12,   96 },
    // Chroma 4x4
    {   29,   42 }, {    1,   74 }, {   -6,   77 }, {   23,   41 },
    {   13,   63 }, {   -6,   88 }, {   -8,   80 }, {   35,   17 },
    {    0,   70 }, {  -17,  100 }, {  -25,  111 }, {  -39,  122 },
    {   26,   29 }, {  -36,  114 }, {  -41,  130 },
    // Chroma 8x8
    {   19,   45 }, {    8,   48 }, {    2,   40 }, {   -3,   40 },
    {    8,   46 }, {   16,   31 }, {  -10,   73 }, {  -51,  114 },
    {    2,   52 }, {   -9,   71 }, {  -37,  118 }, {   -8,   38 },
    {  -10,   64 }, {  -47,  113 }, { -105,  234 }, {  -32,  123 },
    // Chroma 16x16
    {   23,   51 }, {    0,   69 }, {   10,   54 }, {    0,   65 },
    {   -1,   42 }, {    4,   51 }, {   -3,   70 }, {  -12,   61 },
    {   -4,   50 }, {   -2,   68 }, {   -18,  57 }, {    5,   38 },
    {    1,   54 }, {   -3,   66 }, {   -9,   80 },
    // Chroma 32x32 (unused)
    {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }
  },
  {
    // Luma 4x4
    {    6,   67 }, {   -1,   72 }, {   -9,   84 }, {  -29,  100 },
    {    4,   65 }, {    0,   70 }, {   -7,   80 }, {  -34,  117 },
    {  -11,   79 }, {  -14,   91 }, {  -15,   93 }, {  -34,  119 },
    {   26,   26 }, {  -34,  111 }, {  -35,  126 },
    // Luma 8x8
    {    2,   69 }, {  -10,   82 }, {   -1,   57 }, {   -7,   59 },
    {   -5,   71 }, {  -13,   85 }, {  -28,  107 }, {  -29,  100 },
    {  -21,   93 }, {  -28,  108 }, {   -6,   71 }, {  -48,  136 },
    {  -35,  111 }, {  -10,   74 }, {    4,   56 }, {    5,   56 },
    // Luma 16x16
    {    0,   75 }, {    1,   59 }, {   -1,   67 }, {   -3,   67 },
    {    6,   29 }, {    2,   57 }, {   -5,   77 }, {   -5,   44 },
    {   -4,   64 }, {   -7,   78 }, {   -9,   34 }, {    2,   43 },
    {    2,   53 }, {    2,   60 }, {   -8,   83 },
    // Luma 32x32
    {   -7,   88 }, {    5,   52 }, {   -4,   74 }, {    5,   56 },
    // Chroma 4x4
    {  -15,  103 }, {   25,   19 }, {   23,   29 }, {  -65,  142 },
    {  -21,  108 }, {   27,   19 }, {  -34,  111 }, {  -71,  174 },
    {  -30,  104 }, {   34,   12 }, { -144,  285 }, { -168,  304 },
    {   43,    6 }, { -125,  248 }, { -129,  252 },
    // Chroma 8x8
    {   -3,   84 }, {  -35,  122 }, {  -42,  111 }, {  101, -147 },
    {  -14,   87 }, {  -70,  179 }, {    6,   30 }, {    0,   64 },
    {    8,   32 }, {  -64,  156 }, {    0,   64 }, {    0,   64 },
    {  -65,  144 }, {    0,   64 }, {    0,   64 }, {    0,   64 },
    // Chroma 16x16
    {   19,   22 }, {   11,   48 }, {    9,   51 }, {  -24,   95 },
    {  -27,   82 }, {  -22,   92 }, {  -20,   89 }, {  -25,   82 },
    {  -15,   77 }, {   24,   32 }, {  -31,   76 }, {  -19,   77 },
    {  -21,   84 }, {  -23,   95 }, {  -35,  112 },
    // Chroma 32x32 (unused)
    {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }
  },
  {
    // Luma 4x4
    {    6,   67 }, {   -1,   72 }, {   -9,   84 }, {  -29,  100 },
    {    4,   65 }, {    0,   70 }, {   -7,   80 }, {  -34,  117 },
    {  -11,   79 }, {  -14,   91 }, {  -15,   93 }, {  -34,  119 },
    {   26,   26 }, {  -34,  111 }, {  -35,  126 },
    // Luma 8x8
    {    2,   69 }, {  -10,   82 }, {   -1,   57 }, {   -7,   59 },
    {   -5,   71 }, {  -13,   85 }, {  -28,  107 }, {  -29,  100 },
    {  -21,   93 }, {  -28,  108 }, {   -6,   71 }, {  -48,  136 },
    {  -35,  111 }, {  -10,   74 }, {    4,   56 }, {    5,   56 },
    // Luma 16x16
    {    0,   75 }, {    1,   59 }, {   -1,   67 }, {   -3,   67 },
    {    6,   29 }, {    2,   57 }, {   -5,   77 }, {   -5,   44 },
    {   -4,   64 }, {   -7,   78 }, {   -9,   34 }, {    2,   43 },
    {    2,   53 }, {    2,   60 }, {   -8,   83 },
    // Luma 32x32
    {   -7,   88 }, {    5,   52 }, {   -4,   74 }, {    5,   56 },
    // Chroma 4x4
    {  -15,  103 }, {   25,   19 }, {   23,   29 }, {  -65,  142 },
    {  -21,  108 }, {   27,   19 }, {  -34,  111 }, {  -71,  174 },
    {  -30,  104 }, {   34,   12 }, { -144,  285 }, { -168,  304 },
    {   43,    6 }, { -125,  248 }, { -129,  252 },
    // Chroma 8x8
    {   -3,   84 }, {  -35,  122 }, {  -42,  111 }, {  101, -147 },
    {  -14,   87 }, {  -70,  179 }, {    6,   30 }, {    0,   64 },
    {    8,   32 }, {  -64,  156 }, {    0,   64 }, {    0,   64 },
    {  -65,  144 }, {    0,   64 }, {    0,   64 }, {    0,   64 },
    // Chroma 16x16
    {   19,   22 }, {   11,   48 }, {    9,   51 }, {  -24,   95 },
    {  -27,   82 }, {  -22,   92 }, {  -20,   89 }, {  -25,   82 },
    {  -15,   77 }, {   24,   32 }, {  -31,   76 }, {  -19,   77 },
    {  -21,   84 }, {  -23,   95 }, {  -35,  112 },
    // Chroma 32x32 (unused)
    {    0,   64 }, {    0,   64 }, {    0,   64 }, {    0,   64 }
  }
};

static const Short
INIT_ONE_FLAG[3][2*NUM_ONE_FLAG_CTX][2] =
{
  {
    {  -11,   87 }, {  -20,   64 }, {  -16,   68 }, {  -13,   71 }, 
    {  -10,   73 }, {   -5,   67 }, {   -8,   26 }, {   -8,   37 }, 
    {   -3,   36 }, {   -9,   56 }, {    0,   63 }, {   -5,   39 }, 
    {  -12,   56 }, {   -9,   57 }, {   -1,   52 }, {   -4,   72 }, 
    {  -19,   73 }, {  -28,   88 }, {  -23,   85 }, {   -3,   59 }, 
    {   -2,   72 }, {  -27,   97 }, {  -22,   89 }, {  -14,   77 }, 
    {   -1,   58 }, {  -10,   86 }, {  -22,   74 }, {  -13,   63 }, 
    {   -6,   57 }, {   -5,   63 }, 
    {   -4,   70 }, {   16,   -2 }, {    9,   23 }, {    5,   41 }, 
    {   -7,   67 }, {   -6,   63 }, {   13,   -5 }, {  -12,   42 }, 
    {  -18,   53 }, {  -14,   59 }, {   -5,   65 }, {   -8,   36 }, 
    {  -22,   67 }, {  -35,   89 }, {   -3,   47 }, {  -12,   77 }, 
    {  -20,   66 }, {  -51,  113 }, {  -44,  109 }, {  -23,   84 }, 
    {   -1,   64 }, {  -58,  127 }, {  -71,  143 }, {  -67,  134 }, 
    {  -91,  187 }, {   -1,   64 }, {   20,   -3 }, {   13,   21 }, 
    {    2,   46 }, {    5,   48 } 
  },
  {
    {   -4,   71 }, {   29,   -5 }, {    1,   45 }, {   -6,   58 }, 
    {   -9,   67 }, {   -6,   66 }, {   23,   -7 }, {    3,   26 }, 
    {   -5,   42 }, {    5,   31 }, {  -12,   79 }, {   -2,   45 }, 
    {  -15,   67 }, {  -11,   62 }, {   -3,   54 }, {   -4,   70 }, 
    {  -13,   68 }, {  -31,  100 }, {  -26,   91 }, {  -18,   84 }, 
    {   -9,   83 }, {  -30,  103 }, {  -24,   90 }, {  -43,  122 }, 
    {   -6,   66 }, {    4,   59 }, {   34,  -11 }, {   21,   10 }, 
    {   14,   25 }, {    5,   44 }, 
    {   -4,   69 }, {   40,  -33 }, {   19,    8 }, {  -11,   65 }, 
    {   -6,   59 }, {  -11,   68 }, {   12,   -2 }, {   17,  -10 }, 
    {   -6,   34 }, {   11,   14 }, {  -11,   70 }, {    1,   27 }, 
    {  -26,   71 }, {  -28,   79 }, {   -2,   47 }, {    6,   47 }, 
    {  -23,   67 }, {  -47,  107 }, {  -55,  117 }, {  -21,   83 }, 
    {    1,   59 }, {  -38,   82 }, {  -34,   77 }, {  -45,   95 }, 
    {   10,   25 }, {    9,   46 }, {   41,  -31 }, {   32,  -17 }, 
    {   14,   19 }, {   17,   18 } 
  },
  {
    {   -2,   65 }, {   18,   22 }, {   10,   33 }, {   -2,   55 }, 
    {   -7,   64 }, {   -6,   67 }, {   19,   11 }, {   -5,   50 }, 
    {   -7,   53 }, {   -4,   54 }, {  -23,   99 }, {   -3,   51 }, 
    {    2,   41 }, {  -32,  102 }, {  -16,   79 }, {   -8,   77 }, 
    {  -21,   84 }, {  -26,   91 }, {  -33,  104 }, {   -4,   61 }, 
    {  -31,  122 }, {  -34,  110 }, {  -25,   96 }, {  -43,  124 }, 
    {   -6,   70 }, {    3,   60 }, {   23,   12 }, {   12,   30 }, 
    {   11,   33 }, {    8,   40 }, 
    {   -2,   66 }, {   40,  -20 }, {    0,   46 }, {   -5,   54 }, 
    {    7,   37 }, {  -39,  116 }, {   31,  -27 }, {    1,   22 }, 
    {  -35,   82 }, {  -32,   85 }, {  -15,   72 }, {   16,    0 }, 
    {  -43,  102 }, {  -75,  152 }, {   -8,   55 }, {   -9,   68 }, 
    {  -12,   54 }, {  -84,  171 }, {  -93,  186 }, {   25,   12 }, 
    { -104,  222 }, {  -40,   92 }, {  -51,   93 }, {  110, -169 }, 
    {    3,   52 }, {   17,   33 }, {   55,  -45 }, {   28,    1 }, 
    {   -5,   55 }, {   29,   -4 } 
  }
};

static const Short
INIT_ABS_FLAG[3][2*NUM_ABS_FLAG_CTX][2] =
{
  {
    {  -12,   72 }, {  -10,   79 }, {  -11,   87 }, {  -14,   94 }, 
    {  -35,  136 }, {  -10,   58 }, {   -1,   54 }, {  -17,   86 }, 
    {   -5,   70 }, {  -22,  105 }, {  -13,   70 }, {   -2,   59 }, 
    {  -13,   81 }, {  -21,   96 }, {   -3,   73 }, {  -24,   90 }, 
    {  -19,   88 }, {   -1,   63 }, {    1,   60 }, {  -17,   97 }, 
    {   -7,   69 }, {  -20,   95 }, {  -11,   84 }, {  -27,  110 }, 
    {  -12,   96 }, {   -9,   72 }, {   -8,   76 }, {   -4,   75 }, 
    {   -3,   76 }, {   -9,   94 }, 
    {  -11,   65 }, {   -4,   66 }, {   -9,   82 }, {  -24,  107 }, 
    {  -24,  111 }, {  -18,   58 }, {  -10,   61 }, {  -19,   82 }, 
    {  -28,   97 }, {    6,   47 }, {  -12,   50 }, {  -17,   73 }, 
    {   -8,   66 }, {  -44,  115 }, {  -17,   86 }, {  -26,   74 }, 
    {   -4,   48 }, {  -43,  115 }, {  -58,  141 }, {  -51,  137 }, 
    {  -51,  117 }, {  -85,  176 }, {  -47,  120 }, {  -95,  202 }, 
    {  -65,  159 }, {   -2,   53 }, {    7,   43 }, {   -2,   67 }, 
    {    3,   62 }, {    4,   67 } 
  },
  {
    {   -2,   49 }, {  -13,   81 }, {  -11,   82 }, {  -13,   88 }, 
    {  -24,  112 }, {   -4,   44 }, {  -17,   77 }, {  -16,   82 }, 
    {  -19,   89 }, {  -28,  110 }, {  -12,   64 }, {  -11,   70 }, 
    {  -18,   88 }, {   -6,   67 }, {  -19,   97 }, {  -17,   76 }, 
    {  -27,  100 }, {  -18,   88 }, {  -13,   84 }, {  -17,   94 }, 
    {  -11,   73 }, {  -15,   83 }, {  -10,   77 }, {  -10,   80 }, 
    {  -12,   91 }, {   -8,   63 }, {   -7,   71 }, {   -6,   73 }, 
    {   -8,   80 }, {   -9,   90 }, 
    {   14,   20 }, {   -7,   68 }, {   -4,   66 }, {   -8,   76 }, 
    {  -50,  148 }, {    2,   22 }, {   11,   15 }, {   -4,   49 }, 
    {  -41,  117 }, {  -60,  149 }, {  -12,   49 }, {   -6,   55 }, 
    {    1,   44 }, {   -5,   58 }, {  -12,   73 }, {   13,    9 }, 
    {    5,   26 }, {  -29,  101 }, {    0,   46 }, {  -23,   92 }, 
    {  -12,   57 }, {    6,   30 }, {   35,   -4 }, {   42,  -24 }, 
    {   22,   24 }, {   24,    0 }, {   11,   34 }, {    2,   61 }, 
    {   -5,   75 }, {    4,   62 } 
  },
  {
    {    0,   43 }, {   -6,   65 }, {   -7,   71 }, {  -31,  117 }, 
    {  -25,  109 }, {  -20,   76 }, {  -14,   73 }, {  -20,   88 }, 
    {  -21,   92 }, {   -6,   71 }, {  -19,   73 }, {  -34,  108 }, 
    {  -27,  101 }, {   -7,   69 }, {   -7,   75 }, {  -18,   77 }, 
    {   -7,   64 }, {  -20,   91 }, {   -9,   75 }, {   -7,   78 }, 
    {  -26,   98 }, {  -13,   81 }, {   -6,   69 }, {  -12,   83 }, 
    {   -2,   70 }, {   -3,   50 }, {   -6,   66 }, {   -7,   73 }, 
    {   -6,   75 }, {  -11,   91 }, 
    {   19,   10 }, {    2,   49 }, {    4,   52 }, {   -4,   69 }, 
    {  -32,  114 }, {   13,   -1 }, {  -29,   85 }, {  -64,  143 }, 
    {  -90,  186 }, {   26,    4 }, {  -24,   68 }, {    8,   30 }, 
    {  -10,   61 }, {  -16,   78 }, {  -27,   96 }, {   31,  -16 }, 
    {  -12,   54 }, {  -15,   70 }, {  -68,  158 }, {   31,   12 }, 
    {   -8,   44 }, {  -32,   63 }, {  -36,   81 }, {  -53,  106 }, 
    {   36,   12 }, {   26,   -5 }, {   19,   17 }, {  -22,  101 }, 
    {    5,   54 }, {    8,   53 } 
  }
};

// initial probability for motion vector predictor index
static const Short
INIT_MVP_IDX[3][NUM_MVP_IDX_CTX][2] =
{
  {
    {    0,   64 }, {    0,   64 }
  },
  {
    {    0,   64 }, {    0,   64 }
  },
  {
    {    0,   64 }, {    0,   64 }
  }
};

// initial probability for ALF flag
static const Short
INIT_ALF_FLAG[3][NUM_ALF_FLAG_CTX][2] =
{
  {
    {   50,  -48 }
  },
  {
    {   27,  -20 }
  },
  {
    {  -12,   68 }
  }
};

// initial probability for ALF side information (unsigned)
static const Short
INIT_ALF_UVLC[3][NUM_ALF_UVLC_CTX][2] =
{
  {
    {    1,   66 }, {   -3,   77 }
  },
  {
    {   -5,   75 }, {  -14,   94 }
  },
  {
    {   -5,   72 }, {  -30,  122 }
  }
};

// initial probability for ALF side information (signed)
static const Short
INIT_ALF_SVLC[3][NUM_ALF_SVLC_CTX][2] =
{
  {
    {   11,   57 }, {   -1,   62 }, {    0,   64 }
  },
  {
    {    6,   66 }, {   -1,   64 }, {    0,   64 }
  },
  {
    {    1,   73 }, {    2,   61 }, {    0,   64 }
  }
};
#if MTK_SAO
// initial probability for ALF flag
static const Short
INIT_AO_FLAG[3][NUM_AO_FLAG_CTX][2] =
{
  {
    {   50,  -48 }
  },
  {
    {   27,  -20 }
  },
  {
    {  -12,   68 }
  }
};

// initial probability for ALF side information (unsigned)
static const Short
INIT_AO_UVLC[3][NUM_AO_UVLC_CTX][2] =
{
  {
    {    1,   66 }, {   -3,   77 }
  },
  {
    {   -5,   75 }, {  -14,   94 }
  },
  {
    {   -5,   72 }, {  -30,  122 }
  }
};

// initial probability for ALF side information (signed)
static const Short
INIT_AO_SVLC[3][NUM_AO_SVLC_CTX][2] =
{
  {
    {   11,   57 }, {   -1,   62 }, {    0,   64 }
  },
  {
    {    6,   66 }, {   -1,   64 }, {    0,   64 }
  },
  {
    {    1,   73 }, {    2,   61 }, {    0,   64 }
  }
};
#endif

static const Short
INIT_TRANS_SUBDIV_FLAG[3][NUM_TRANS_SUBDIV_FLAG_CTX][2] =
{
  {
    {    0,    0 }, {   12,   12 }, {   22,    4 }, {   -2,   49 }, 
    {    4,   46 }, {    0,   64 }, {    0,   64 }, {    0,   64 }, 
    {    0,   64 }, {    0,   64 }
  },
  {
    {    0,   13 }, {  -28,   89 }, {  -30,   99 }, {  -34,  106 }, 
    {  -19,   76 }, {    0,   64 }, {    0,   64 }, {    0,   64 }, 
    {    0,   64 }, {    0,   64 }
  },
  {
    {  -11,   38 }, {  -31,   88 }, {  -42,  118 }, {  -47,  130 }, 
    {  -21,   73 }, {    0,   64 }, {    0,   64 }, {    0,   64 }, 
    {    0,   64 }, {    0,   64 }
  }
};

#endif

