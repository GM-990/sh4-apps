/*****************************************************************************/
/* COPYRIGHT (C) 2009 STMicroelectronics - All Rights Reserved               */
/* ST makes no warranty express or implied including but not limited to,     */
/* any warranty of                                                           */
/*                                                                           */
/*   (i)  merchantability or fitness for a particular purpose and/or         */
/*   (ii) requirements, for a particular purpose in relation to the LICENSED */
/*        MATERIALS, which is provided AS IS, WITH ALL FAULTS. ST does not   */
/*        represent or warrant that the LICENSED MATERIALS provided here     */
/*        under is free of infringement of any third party patents,          */
/*        copyrights, trade secrets or other intellectual property rights.   */
/*        ALL WARRANTIES, CONDITIONS OR OTHER TERMS IMPLIED BY LAW ARE       */
/*        EXCLUDED TO THE FULLEST EXTENT PERMITTED BY LAW                    */
/*                                                                           */
/*****************************************************************************/
/**
 * @file     stapp_mbx.h
 * @brief    This is the mailbox file header.
 *           It is used to communicate between all the CPUs available in the system by using
 *           multicom/stpcpd/stxcpu/stiprc components.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_MBX_H_
#define _STAPP_MBX_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(ST_5197)
#define MBX_MAX_NUMBER 0
#endif
#if defined(ST_5206)
#define MBX_MAX_NUMBER 2
#endif
#if defined(ST_7105)
#define MBX_MAX_NUMBER 2
#endif
#if defined(ST_7108)
#if defined(ST_RT)||defined(ST_HOSTONLY)||(!defined(DVD_STIPRC))
#define MBX_MAX_NUMBER 2
#endif
#endif
#if defined(ST_7111)
#define MBX_MAX_NUMBER 2
#endif
#if defined(ST_7141)
#define MBX_MAX_NUMBER 2
#endif
#if defined(ST_H205)
#define MBX_MAX_NUMBER 2
#endif
#if defined(ST_OSLINUX)
#if defined(MBX_MAX_NUMBER)
#undef MBX_MAX_NUMBER
#endif
#endif

/* Includes */
/* -------- */
#if defined(MBX_MAX_NUMBER)
#include "mme.h"
#if (MBX_MAX_NUMBER>=1)
#if defined(MULTICOM_VERSION_CODE)&&(MULTICOM_VERSION_CODE>=MULTICOM_VERSION(4,0,0))
#define MULTICOM_ICS_LAYER_MODE
#endif
#if defined(MULTICOM_ICS_LAYER_MODE)
#include <ics.h>
#else
#include <embx_types.h>
#include <embxmailbox.h>
#include <embx.h>
#include <embxshm.h>
#endif
#endif
#endif

/* External variables */
/* ------------------ */
#if defined(MBX_MAX_NUMBER)
#if (MBX_MAX_NUMBER>=1)
extern U8 LX_VIDEO_Revision[];
extern U8 LX_AUDIO_Revision[];
#endif
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t MBX_Init(void);
ST_ErrorCode_t MBX_Term(void);

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

