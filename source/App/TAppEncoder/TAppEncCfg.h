/* The copyright in this software is being made available under the BSD
 * License, included below. This software may be subject to other third party
 * and contributor rights, including patent rights, and no such rights are
 * granted under this license.  
 *
 * Copyright (c) 2010-2012, ITU/ISO/IEC
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

/** \file     TAppEncCfg.h
    \brief    Handle encoder configuration parameters (header)
*/

#ifndef __TAPPENCCFG__
#define __TAPPENCCFG__

#include "TLibCommon/CommonDef.h"

#if G1002_RPS
#include "TLibEncoder/TEncCfg.h"
#include <sstream>
#endif
//! \ingroup TAppEncoder
//! \{

// ====================================================================================================================
// Class definition
// ====================================================================================================================

/// encoder configuration class
class TAppEncCfg
{
protected:
  // file I/O
  char*     m_pchInputFile;                                   ///< source file name
  char*     m_pchBitstreamFile;                               ///< output bitstream file
  char*     m_pchReconFile;                                   ///< output reconstruction file
#if G678_LAMBDA_ADJUSTMENT  
  Double    m_adLambdaModifier[ MAX_TLAYER ];                 ///< Lambda modifier array for each temporal layer
#endif
  // source specification
  Int       m_iFrameRate;                                     ///< source frame-rates (Hz)
  unsigned int m_FrameSkip;                                   ///< number of skipped frames from the beginning
  Int       m_iSourceWidth;                                   ///< source width in pixel
  Int       m_iSourceHeight;                                  ///< source height in pixel
  Int       m_iFrameToBeEncoded;                              ///< number of encoded frames
  
  // coding structure
  Int       m_iIntraPeriod;                                   ///< period of I-slice (random access period)
  Int       m_iDecodingRefreshType;                           ///< random access type
#if G1002_RPS
#else
  Bool      m_bHierarchicalCoding;                            ///< flag for specifying hierarchical B structure
  Bool      m_bUseLDC;                                        ///< flag for using low-delay coding mode
  Bool      m_bUseNRF;                                        ///< flag for using non-referenced frame in hierarchical structure
  Bool      m_bUseGPB;                                        ///< flag for using generalized P & B structure
#endif
  Bool      m_bUseLComb;                                      ///< flag for using combined reference list for uni-prediction in B-slices (JCTVC-D421)
  Bool      m_bLCMod;                                         ///< flag for specifying whether the combined reference list for uni-prediction in B-slices is uploaded explicitly
  Bool      m_bDisInter4x4;
#if NSQT
  Bool      m_enableNSQT;                                     ///< flag for enabling NSQT
#endif
#if AMP
  Bool      m_enableAMP;
#endif
  // coding quality
  Double    m_fQP;                                            ///< QP value of key-picture (floating point)
  Int       m_iQP;                                            ///< QP value of key-picture (integer)
  Int       m_aiTLayerQPOffset[MAX_TLAYER];                   ///< QP offset corresponding to temporal layer depth

  Bool      m_bTLayering;                                     ///< indicates whether temporal IDs are set based on the hierarchical coding structure
  Bool      m_abTLayerSwitchingFlag[MAX_TLAYER];              ///< temporal layer switching flags corresponding to each temporal layer

  // coding unit (CU) definition
  UInt      m_uiMaxCUWidth;                                   ///< max. CU width in pixel
  UInt      m_uiMaxCUHeight;                                  ///< max. CU height in pixel
  UInt      m_uiMaxCUDepth;                                   ///< max. CU depth
  
  // transfom unit (TU) definition
  UInt      m_uiQuadtreeTULog2MaxSize;
  UInt      m_uiQuadtreeTULog2MinSize;
  
  UInt      m_uiQuadtreeTUMaxDepthInter;
  UInt      m_uiQuadtreeTUMaxDepthIntra;
  
  // coding tools (inter - merge motion partitions)
  Bool      m_bUseMRG;                                        ///< SOPH: flag for using motion partition Merge Mode

  // coding tools (encoder-only parameters)
  Bool      m_bUseSBACRD;                                     ///< flag for using RD optimization based on SBAC
  Bool      m_bUseHADME;                                      ///< flag for using HAD in sub-pel ME
#if !G1002_RPS
  Bool      m_bUseBQP;                                        ///< flag for using B-slice based QP assignment in low-delay hier. structure
#endif
  Int       m_iFastSearch;                                    ///< ME mode, 0 = full, 1 = diamond, 2 = PMVFAST
  Int       m_iSearchRange;                                   ///< ME search range
  Int       m_bipredSearchRange;                              ///< ME search range for bipred refinement
  Bool      m_bUseFastEnc;                                    ///< flag for using fast encoder setting
#if EARLY_CU_DETERMINATION
  Bool      m_bUseEarlyCU;                                    ///< flag for using Early CU setting
#endif  
#if CBF_FAST_MODE
  Bool      m_bUseCbfFastMode;                              ///< flag for using Cbf Fast PU Mode Decision
#endif  
  bool m_pictureDigestEnabled; ///< enable(1)/disable(0) md5 computation and SEI signalling

#if !G1002_RPS
#if REF_SETTING_FOR_LD
  Bool      m_bUseNewRefSetting;
#endif
#endif

#if NO_TMVP_MARKING
  Bool      m_enableTMVP;
#endif

  // internal member functions
  Void  xSetGlobal      ();                                   ///< set global variables
  Void  xCheckParameter ();                                   ///< check validity of configuration values
  Void  xPrintParameter ();                                   ///< print configuration values
  Void  xPrintUsage     ();                                   ///< print usage
  
public:
  TAppEncCfg();
  virtual ~TAppEncCfg();
  
public:
  Void  create    ();                                         ///< create option handling class
  Void  destroy   ();                                         ///< destroy option handling class
  Bool  parseCfg  ( Int argc, Char* argv[] );                 ///< parse configuration file to fill member variables
  
};// END CLASS DEFINITION TAppEncCfg

//! \}

#endif // __TAPPENCCFG__

