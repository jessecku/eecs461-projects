/******************************************************************************
 *
 * Freescale Semiconductor Inc.
 * (c) Copyright 2004-2011 Freescale Semiconductor
 * ALL RIGHTS RESERVED.
 *
 ****************************************************************************/
  /*!
   *
   * @file   freemaster_protocol.c
   *
   * @brief  FreeMASTER protocol handler
   *
   * @version 1.0.29.0
   *
   * @date Aug-25-2011
   *
   *******************************************************************************
   *
   * This file contains the FreeMASTER protocol decoder and also the handlers
   * of basic protocol commands (read/write memory etc).
   *
   *******************************************************************************/


#include "freemaster.h"
#include "freemaster_private.h"
#include "freemaster_protocol.h"
#if !FMSTR_DISABLE

/**************************************************************************/
/*!
 *
 * @brief    FreeMASTER driver initialization
 *
 ******************************************************************************/
FMSTR_BOOL FMSTR_Init(void)
{

#if FMSTR_USE_TSA

  /* initialize TSA */
  FMSTR_InitTsa();

#endif

#if FMSTR_USE_SCOPE

  /* initialize Scope */
  FMSTR_InitScope();

#endif

#if FMSTR_USE_RECORDER

  /* initialize Recorder */
  FMSTR_InitRec();

#endif

#if FMSTR_USE_APPCMD

  /* initialize application commands */
  FMSTR_InitAppCmds();

#endif

#if FMSTR_USE_SFIO

  /* initialize SFIO encapsulation layer */
  FMSTR_InitSfio();

#endif

#if FMSTR_USE_PIPES

  /* initialize PIPES interface */
  FMSTR_InitPipes();

#endif

#if FMSTR_USE_CAN

  /* initialize CAN communication */
  FMSTR_InitCan();

#endif

#if FMSTR_USE_PDBDM

  /* initialize Packet Driven BDM communication */
  FMSTR_InitPDBdm();

#endif

#if FMSTR_USE_SERIAL

  /* initialize communication and start listening for commands */
  if (!FMSTR_InitSerial())
    return FMSTR_FALSE;

#endif

  return FMSTR_TRUE;
}

/**************************************************************************/

/*!
 *
 * @brief    Decodes the FreeMASTER protocol and calls appropriate handlers
 *
 * @param    pMessageIO - message in/out buffer
 *
 * @return   TRUE if frame was valid and any output was generated to IO buffer
 *
 * This Function decodes given message and invokes proper command handler
 * which fills in the response. The response transmission is initiated
 * in this call as well.
 *
 ******************************************************************************/
FMSTR_BOOL FMSTR_ProtocolDecoder(FMSTR_BPTR pMessageIO)
{
  FMSTR_BPTR pResponseEnd;
  FMSTR_U8 nCmd;

  /* no EX access by default */
  FMSTR_SetExAddr(FMSTR_FALSE);

  /* command code comes first in the message */
  /*lint -e{534} return value is not used */
  FMSTR_ValueFromBuffer8(&nCmd, pMessageIO);

  /* process command   */
  switch (nCmd)
  {

#if FMSTR_USE_READVAR

    /* read byte */
#if FMSTR_USE_EX_CMDS

   case FMSTR_CMD_READVAR8_EX:
    FMSTR_SetExAddr(FMSTR_TRUE);

#endif

#if FMSTR_USE_NOEX_CMDS

    /*lint -fallthrough */
   case FMSTR_CMD_READVAR8:

#endif

    pResponseEnd = FMSTR_ReadVar(pMessageIO, 1U);
    break;

    /* read word */
#if FMSTR_USE_EX_CMDS

   case FMSTR_CMD_READVAR16_EX:
    FMSTR_SetExAddr(FMSTR_TRUE);

#endif

#if FMSTR_USE_NOEX_CMDS

    /*lint -fallthrough */
   case FMSTR_CMD_READVAR16:

#endif

    pResponseEnd = FMSTR_ReadVar(pMessageIO, 2U);
    break;

    /* read dword */
#if FMSTR_USE_EX_CMDS

   case FMSTR_CMD_READVAR32_EX:
    FMSTR_SetExAddr(FMSTR_TRUE);

#endif

#if FMSTR_USE_NOEX_CMDS

    /*lint -fallthrough */
   case FMSTR_CMD_READVAR32:

#endif

    pResponseEnd = FMSTR_ReadVar(pMessageIO, 4U);
    break;

#endif                                 /* FMSTR_USE_READVAR */

#if FMSTR_USE_READMEM

    /* read a block of memory */
#if FMSTR_USE_EX_CMDS

   case FMSTR_CMD_READMEM_EX:
    FMSTR_SetExAddr(FMSTR_TRUE);

#endif

#if FMSTR_USE_NOEX_CMDS

    /*lint -fallthrough */
   case FMSTR_CMD_READMEM:

#endif

    pResponseEnd = FMSTR_ReadMem(pMessageIO);
    break;

#endif                                 /* FMSTR_USE_READMEM */

#if FMSTR_USE_SCOPE

    /* prepare scope variables */
#if FMSTR_USE_EX_CMDS

   case FMSTR_CMD_SETUPSCOPE_EX:
    FMSTR_SetExAddr(FMSTR_TRUE);

#endif

#if FMSTR_USE_NOEX_CMDS

    /*lint -fallthrough */
   case FMSTR_CMD_SETUPSCOPE:

#endif

    pResponseEnd = FMSTR_SetUpScope(pMessageIO);
    break;

   case FMSTR_CMD_READSCOPE:
    pResponseEnd = FMSTR_ReadScope(pMessageIO);
    break;

#endif                                 /* FMSTR_USE_SCOPE */

#if FMSTR_USE_RECORDER

    /* get recorder status */
   case FMSTR_CMD_GETRECSTS:
    pResponseEnd = FMSTR_GetRecStatus(pMessageIO);
    break;

    /* start recorder */
   case FMSTR_CMD_STARTREC:
    pResponseEnd = FMSTR_StartRec(pMessageIO);
    break;

    /* stop recorder */
   case FMSTR_CMD_STOPREC:
    pResponseEnd = FMSTR_StopRec(pMessageIO);
    break;

    /* setup recorder */
#if FMSTR_USE_EX_CMDS

   case FMSTR_CMD_SETUPREC_EX:
    FMSTR_SetExAddr(FMSTR_TRUE);

#endif

#if FMSTR_USE_NOEX_CMDS

    /*lint -fallthrough */
   case FMSTR_CMD_SETUPREC:

#endif

    pResponseEnd = FMSTR_SetUpRec(pMessageIO);
    break;

    /* get recorder buffer information (force EX instead of non-EX) */
#if FMSTR_USE_EX_CMDS

   case FMSTR_CMD_GETRECBUFF_EX:
    FMSTR_SetExAddr(FMSTR_TRUE);

#elif FMSTR_USE_NOEX_CMDS

    /*lint -fallthrough */
   case FMSTR_CMD_GETRECBUFF:

#endif

    pResponseEnd = FMSTR_GetRecBuff(pMessageIO);
    break;

#endif                                 /* FMSTR_USE_RECORDER */

#if FMSTR_USE_APPCMD

    /* accept the application command */
   case FMSTR_CMD_SENDAPPCMD:
    pResponseEnd = FMSTR_StoreAppCmd(pMessageIO);
    break;

    /* get the application command status */
   case FMSTR_CMD_GETAPPCMDSTS:
    pResponseEnd = FMSTR_GetAppCmdStatus(pMessageIO);
    break;

    /* get the application command data */
   case FMSTR_CMD_GETAPPCMDDATA:
    pResponseEnd = FMSTR_GetAppCmdRespData(pMessageIO);
    break;

#endif                                 /* FMSTR_USE_APPCMD */

#if FMSTR_USE_WRITEMEM

    /* write a block of memory */
#if FMSTR_USE_EX_CMDS

   case FMSTR_CMD_WRITEMEM_EX:
    FMSTR_SetExAddr(FMSTR_TRUE);

#endif

#if FMSTR_USE_NOEX_CMDS

    /*lint -fallthrough */
   case FMSTR_CMD_WRITEMEM:

#endif

    pResponseEnd = FMSTR_WriteMem(pMessageIO);
    break;

#endif                                 /* FMSTR_USE_WRITEMEM */

#if FMSTR_USE_WRITEMEMMASK

    /* write block of memory with a bit mask */
#if FMSTR_USE_EX_CMDS

   case FMSTR_CMD_WRITEMEMMASK_EX:
    FMSTR_SetExAddr(FMSTR_TRUE);

#endif

#if FMSTR_USE_NOEX_CMDS

    /*lint -fallthrough */
   case FMSTR_CMD_WRITEMEMMASK:

#endif

    pResponseEnd = FMSTR_WriteMemMask(pMessageIO);
    break;

#endif                                 /* FMSTR_USE_WRITEMEMMASK */

#if FMSTR_USE_WRITEVAR && FMSTR_USE_NOEX_CMDS

    /* write byte */
   case FMSTR_CMD_WRITEVAR8:
    pResponseEnd = FMSTR_WriteVar(pMessageIO, 1U);
    break;

    /* write word */
   case FMSTR_CMD_WRITEVAR16:
    pResponseEnd = FMSTR_WriteVar(pMessageIO, 2U);
    break;

    /* write dword */
   case FMSTR_CMD_WRITEVAR32:
    pResponseEnd = FMSTR_WriteVar(pMessageIO, 4U);
    break;

#endif                                 /* FMSTR_USE_WRITEVAR && FMSTR_USE_NOEX_CMDS */

#if FMSTR_USE_WRITEVARMASK && FMSTR_USE_NOEX_CMDS

    /* write byte with mask */
   case FMSTR_CMD_WRITEVAR8MASK:
    pResponseEnd = FMSTR_WriteVarMask(pMessageIO, 1U);
    break;

    /* write word with mask */
   case FMSTR_CMD_WRITEVAR16MASK:
    pResponseEnd = FMSTR_WriteVarMask(pMessageIO, 2U);
    break;

#endif                                 /* FMSTR_USE_WRITEVARMASK && FMSTR_USE_NOEX_CMDS */

#if FMSTR_USE_TSA

    /* get TSA table (force EX instead of non-EX) */
#if FMSTR_USE_EX_CMDS

   case FMSTR_CMD_GETTSAINFO_EX:
    FMSTR_SetExAddr(FMSTR_TRUE);

#elif FMSTR_USE_NOEX_CMDS

    /*lint -fallthrough */
   case FMSTR_CMD_GETTSAINFO:

#endif

    pResponseEnd = FMSTR_GetTsaInfo(pMessageIO);
    break;

#if FMSTR_USE_EX_CMDS

   case FMSTR_CMD_GETSTRLEN_EX:
    FMSTR_SetExAddr(FMSTR_TRUE);

#endif

#if FMSTR_USE_NOEX_CMDS

    /*lint -fallthrough */
   case FMSTR_CMD_GETSTRLEN:

#endif

    pResponseEnd = FMSTR_GetStringLen(pMessageIO);
    break;

#endif                                 /* FMSTR_USE_TSA */

#if FMSTR_USE_BRIEFINFO

    /* retrieve a subset of board information structure */
   case FMSTR_CMD_GETINFOBRIEF:

#else

    /* retrieve board information structure */
   case FMSTR_CMD_GETINFO:

#endif

    pResponseEnd = FMSTR_GetBoardInfo(pMessageIO);
    break;

#if FMSTR_USE_SFIO

   case FMSTR_CMD_SFIOFRAME_0:
   case FMSTR_CMD_SFIOFRAME_1:
    pResponseEnd = FMSTR_SfioFrame(pMessageIO);
    break;

   case FMSTR_CMD_SFIOGETRESP_0:
   case FMSTR_CMD_SFIOGETRESP_1:
    pResponseEnd = FMSTR_SfioGetResp(pMessageIO);
    break;

#endif                                 /* FMSTR_USE_SFIO */

#if FMSTR_USE_PIPES

   case FMSTR_CMD_PIPE:
    pResponseEnd = FMSTR_PipeFrame(pMessageIO);
    break;

#endif                                 /* FMSTR_USE_PIPES */

    /* unknown command */
   default:
    pResponseEnd = FMSTR_ConstToBuffer8(pMessageIO, FMSTR_STC_INVCMD);
    break;
  }

  /* anything to send back? */
  if (pResponseEnd != pMessageIO) {
    /*lint -e{946,960} subtracting pointers is appropriate here */
    FMSTR_SIZE8 nSize = (FMSTR_SIZE8)(pResponseEnd - pMessageIO);
    FMSTR_SendResponse(pMessageIO, nSize);
    return FMSTR_TRUE;
  } else {
    /* nothing sent out */
    return FMSTR_FALSE;
  }
}

/**************************************************************************/

/*!
 *
 * @brief    Handling GETINFO or GETINFO_BRIEF
 *
 * @param    pMessageIO - original command (in) and response buffer (out)
 *
 * @return   As all command handlers, the return value should be the buffer
 *           pointer where the response output finished (except checksum)
 *
 ******************************************************************************/
FMSTR_BPTR FMSTR_GetBoardInfo(FMSTR_BPTR pMessageIO)
{
  FMSTR_BPTR pResponse = pMessageIO;
  FMSTR_U16 wTmp;
  FMSTR_U8 *pStr;
  pResponse = FMSTR_ConstToBuffer8(pResponse, FMSTR_STS_OK);
  pResponse = FMSTR_ConstToBuffer8(pResponse, (FMSTR_U8)(FMSTR_PROT_VER));/* protVer */
  pResponse = FMSTR_ConstToBuffer8(pResponse, (FMSTR_U8)(FMSTR_CFG_FLAGS));/* cfgFlags */
  pResponse = FMSTR_ConstToBuffer8(pResponse, (FMSTR_U8)(FMSTR_CFG_BUS_WIDTH));/* dataBusWdt */
  pResponse = FMSTR_ConstToBuffer8(pResponse, (FMSTR_U8)
    (FMSTR_GLOB_VERSION_MAJOR));       /* globVerMajor */
  pResponse = FMSTR_ConstToBuffer8(pResponse, (FMSTR_U8)
    (FMSTR_GLOB_VERSION_MINOR));       /* globVerMinor */
  pResponse = FMSTR_ConstToBuffer8(pResponse, (FMSTR_U8)(FMSTR_COMM_BUFFER_SIZE));/* cmdBuffSize  */

  /* that is all for brief info */
#if FMSTR_USE_BRIEFINFO

  FMSTR_UNUSED(pStr);
  FMSTR_UNUSED(wTmp);

#else                                  /* FMSTR_USE_BRIEFINFO */
#if FMSTR_USE_RECORDER

  /* recorder buffer size is always measured in bytes */
  wTmp = FMSTR_GetRecBuffSize();
  wTmp *= FMSTR_CFG_BUS_WIDTH;

  /* send size and timebase    */
  pResponse = FMSTR_ValueToBuffer16(pResponse, wTmp);
  pResponse = FMSTR_ConstToBuffer16(pResponse, (FMSTR_U16) FMSTR_REC_TIMEBASE);

#else                                  /* FMSTR_USE_RECORDER */

  FMSTR_UNUSED(wTmp);

  /* recorder info zeroed */
  pResponse = FMSTR_ConstToBuffer16(pResponse, 0);
  pResponse = FMSTR_ConstToBuffer16(pResponse, 0);

#endif                                 /* FMSTR_USE_RECORDER */

#if FMSTR_LIGHT_VERSION

  FMSTR_UNUSED(pStr);
  pResponse = FMSTR_SkipInBuffer(pResponse, (FMSTR_U8)FMSTR_DESCR_SIZE);

#else

  /* description string */
  pStr = (FMSTR_U8*) FMSTR_IDT_STRING;
  for (wTmp = 0U; wTmp < (FMSTR_U8)(FMSTR_DESCR_SIZE); wTmp++) {
    pResponse = FMSTR_ValueToBuffer8(pResponse, *pStr);

    /* terminating zero used to clear the remainder of the buffer */
    if (*pStr) {
      pStr ++;
    }
  }

#endif                                 /* SEND_IDT_STRING */
#endif                                 /* FMSTR_USE_BRIEFINFO */

  return pResponse;
}

/**************************************************************************/

/*!
 *
 * @brief    Handling READMEM and READMEM_EX commands
 *
 * @param    pMessageIO - original command (in) and response buffer (out)
 *
 * @return   As all command handlers, the return value should be the buffer
 *           pointer where the response output finished (except checksum)
 *
 ******************************************************************************/
FMSTR_BPTR FMSTR_ReadMem(FMSTR_BPTR pMessageIO)
{
  FMSTR_BPTR pResponse = pMessageIO;
  FMSTR_ADDR nAddr;
  FMSTR_U8 nSize;
  pMessageIO = FMSTR_SkipInBuffer(pMessageIO, 2U);
  pMessageIO = FMSTR_ValueFromBuffer8(&nSize, pMessageIO);
  pMessageIO = FMSTR_AddressFromBuffer(&nAddr, pMessageIO);

#if FMSTR_USE_TSA && FMSTR_USE_TSA_SAFETY

  if (!FMSTR_CheckTsaSpace(nAddr, (FMSTR_SIZE8) nSize, FMSTR_FALSE)) {
    return FMSTR_ConstToBuffer8(pResponse, FMSTR_STC_EACCESS);
  }

#endif

  /* check the response will safely fit into comm buffer */
  if (nSize > (FMSTR_U8)FMSTR_COMM_BUFFER_SIZE) {
    return FMSTR_ConstToBuffer8(pResponse, FMSTR_STC_RSPBUFFOVF);
  }

  /* success  */
  pResponse = FMSTR_ConstToBuffer8(pResponse, FMSTR_STS_OK);
  return FMSTR_CopyToBuffer(pResponse, nAddr, (FMSTR_SIZE8) nSize);
}

/**************************************************************************/

/*!
 *
 * @brief    Handling READVAR and READVAR_EX commands (for all sizes 1,2,4)
 *
 * @param    pMessageIO - original command (in) and response buffer (out)
 *
 * @return   As all command handlers, the return value should be the buffer
 *           pointer where the response output finished (except checksum)
 *
 ******************************************************************************/
FMSTR_BPTR FMSTR_ReadVar(FMSTR_BPTR pMessageIO, FMSTR_SIZE8 nSize)
{
  FMSTR_BPTR pResponse = pMessageIO;
  FMSTR_ADDR nAddr;
  pMessageIO = FMSTR_SkipInBuffer(pMessageIO, 1U);
  pMessageIO = FMSTR_AddressFromBuffer(&nAddr, pMessageIO);

#if FMSTR_USE_TSA && FMSTR_USE_TSA_SAFETY

  if (!FMSTR_CheckTsaSpace(nAddr, nSize, FMSTR_FALSE)) {
    return FMSTR_ConstToBuffer8(pResponse, FMSTR_STC_EACCESS);
  }

#endif

  /* success  */
  pResponse = FMSTR_ConstToBuffer8(pResponse, FMSTR_STS_OK);
  return FMSTR_CopyToBuffer(pResponse, nAddr, nSize);
}

/**************************************************************************/

/*!
 *
 * @brief    Handling WRITEMEM and WRITEMEM_EX commands
 *
 * @param    pMessageIO - original command (in) and response buffer (out)
 *
 * @return   As all command handlers, the return value should be the buffer
 *           pointer where the response output finished (except checksum)
 *
 ******************************************************************************/
FMSTR_BPTR FMSTR_WriteMem(FMSTR_BPTR pMessageIO)
{
  FMSTR_BPTR pResponse = pMessageIO;
  FMSTR_ADDR nAddr;
  FMSTR_U8 nSize,nResponseCode;
  pMessageIO = FMSTR_SkipInBuffer(pMessageIO, 2U);
  pMessageIO = FMSTR_ValueFromBuffer8(&nSize, pMessageIO);
  pMessageIO = FMSTR_AddressFromBuffer(&nAddr, pMessageIO);

#if FMSTR_USE_TSA && FMSTR_USE_TSA_SAFETY

  if (!FMSTR_CheckTsaSpace(nAddr, (FMSTR_SIZE8) nSize, FMSTR_TRUE)) {
    nResponseCode = FMSTR_STC_EACCESS;
    goto FMSTR_WriteMem_exit;
  }

#endif

  /*lint -e{534} ignoring function return value */
  FMSTR_CopyFromBuffer(nAddr, pMessageIO, (FMSTR_SIZE8) nSize);
  nResponseCode = FMSTR_STS_OK;

#if FMSTR_USE_TSA && FMSTR_USE_TSA_SAFETY

 FMSTR_WriteMem_exit:

#endif

  return FMSTR_ConstToBuffer8(pResponse, nResponseCode);
}

/**************************************************************************/

/*!
 *
 * @brief    Handling WRITEVAR command
 *
 * @param    pMessageIO - original command (in) and response buffer (out)
 * @param    nSize - variable size
 *
 * @return   As all command handlers, the return value should be the buffer
 *           pointer where the response output finished (except checksum)
 *
 ******************************************************************************/
FMSTR_BPTR FMSTR_WriteVar(FMSTR_BPTR pMessageIO, FMSTR_SIZE8 nSize)
{
  FMSTR_BPTR pResponse = pMessageIO;
  FMSTR_ADDR nAddr;
  FMSTR_U8 nResponseCode;
  pMessageIO = FMSTR_SkipInBuffer(pMessageIO, 1U);
  pMessageIO = FMSTR_AddressFromBuffer(&nAddr, pMessageIO);

#if FMSTR_USE_TSA && FMSTR_USE_TSA_SAFETY

  if (!FMSTR_CheckTsaSpace(nAddr, nSize, FMSTR_TRUE)) {
    nResponseCode = FMSTR_STC_EACCESS;
    goto FMSTR_WriteVar_exit;
  }

#endif

  /*lint -e{534} ignoring function return value */
  FMSTR_CopyFromBuffer(nAddr, pMessageIO, nSize);
  nResponseCode = FMSTR_STS_OK;

#if FMSTR_USE_TSA && FMSTR_USE_TSA_SAFETY

 FMSTR_WriteVar_exit:

#endif

  return FMSTR_ConstToBuffer8(pResponse, nResponseCode);
}

/**************************************************************************/

/*!
 *
 * @brief    Handling WRITEMEMMASK and WRITEMEMMASK_EX commands
 *
 * @param    pMessageIO - original command (in) and response buffer (out)
 *
 * @return   As all command handlers, the return value should be the buffer
 *           pointer where the response output finished (except checksum)
 *
 ******************************************************************************/
FMSTR_BPTR FMSTR_WriteMemMask(FMSTR_BPTR pMessageIO)
{
  FMSTR_BPTR pResponse = pMessageIO;
  FMSTR_ADDR nAddr;
  FMSTR_U8 nSize,nResponseCode;
  pMessageIO = FMSTR_SkipInBuffer(pMessageIO, 2U);
  pMessageIO = FMSTR_ValueFromBuffer8(&nSize, pMessageIO);
  pMessageIO = FMSTR_AddressFromBuffer(&nAddr, pMessageIO);

#if FMSTR_USE_TSA && FMSTR_USE_TSA_SAFETY

  if (!FMSTR_CheckTsaSpace(nAddr, (FMSTR_SIZE8)nSize, FMSTR_TRUE)) {
    nResponseCode = FMSTR_STC_EACCESS;
    goto FMSTR_WriteMemMask_exit;
  }

#endif

#if FMSTR_CFG_BUS_WIDTH > 1U

  /* size must be divisible by bus width (mask must not begin in half of memory word) */
  if (nSize % FMSTR_CFG_BUS_WIDTH) {
    nResponseCode = FMSTR_STC_INVSIZE;
    goto FMSTR_WriteMemMask_exit;
  }

#endif

  /* put the data */
  FMSTR_CopyFromBufferWithMask(nAddr, pMessageIO, (FMSTR_SIZE8)nSize);
  nResponseCode = FMSTR_STS_OK;

#if (FMSTR_USE_TSA && FMSTR_USE_TSA_SAFETY) || (FMSTR_CFG_BUS_WIDTH > 1U)

 FMSTR_WriteMemMask_exit:

#endif

  return FMSTR_ConstToBuffer8(pResponse, nResponseCode);
}

/**************************************************************************/

/*!
 *
 * @brief    Handling WRITEVARMASK command
 *
 * @param    pMessageIO - original command (in) and response buffer (out)
 * @param    nSize - variable size
 *
 * @return   As all command handlers, the return value should be the buffer
 *           pointer where the response output finished (except checksum)
 *
 ******************************************************************************/
FMSTR_BPTR FMSTR_WriteVarMask(FMSTR_BPTR pMessageIO, FMSTR_SIZE8 nSize)
{
  FMSTR_BPTR pResponse = pMessageIO;
  FMSTR_ADDR nAddr;
  FMSTR_U8 nResponseCode;
  pMessageIO = FMSTR_SkipInBuffer(pMessageIO, 1U);
  pMessageIO = FMSTR_AddressFromBuffer(&nAddr, pMessageIO);

#if FMSTR_USE_TSA && FMSTR_USE_TSA_SAFETY

  if (!FMSTR_CheckTsaSpace(nAddr, nSize, FMSTR_TRUE)) {
    nResponseCode = FMSTR_STC_EACCESS;
    goto FMSTR_WriteVarMask_exit;
  }

#endif

  /* put the data */
  FMSTR_CopyFromBufferWithMask(nAddr, pMessageIO, nSize);
  nResponseCode = FMSTR_STS_OK;

#if FMSTR_USE_TSA && FMSTR_USE_TSA_SAFETY

 FMSTR_WriteVarMask_exit:

#endif

  return FMSTR_ConstToBuffer8(pResponse, nResponseCode);
}

/**************************************************************************/

/*!
 *
 * @brief    Private inline implementation of "strlen" used by TSA and Pipes
 *
 ******************************************************************************/
FMSTR_U16 FMSTR_StrLen(FMSTR_ADDR nAddr)
{
  const FMSTR_U8* pStr;
  FMSTR_U16 nLen = 0U;

#ifdef __HCS12X__

  /* convert from logical to global if needed */
  nAddr = FMSTR_FixHcs12xAddr(nAddr);

#endif

  /*lint -e{923} casting address value to pointer */
  pStr = (const FMSTR_U8*) nAddr;
  while (*pStr++) {
    nLen++;
  }

  return nLen;
}

#else                                  /* !FMSTR_DISABLE */

/**************************************************************************/
/*!
 *
 * @brief    FreeMASTER driver initialization is disabled
 *
 ******************************************************************************/
FMSTR_BOOL FMSTR_Init(void)
{
  return FMSTR_FALSE;
}

/*******************************************************************************
 *
 * @brief    API: Main "Polling" call from the application main loop
 *
 *******************************************************************************/
void FMSTR_Poll(void)
{
}

/* HC12 interrupt routine declaration, must be in non-paged code memory */
#if defined(FMSTR_PLATFORM_HC12)
#include "non_bank.sgm"
#endif

/*******************************************************************************
 *
 * @brief    API: API: Main SCI / CAN Interrupt handler call
 *
 *******************************************************************************/
#if !defined(FMSTR_PLATFORM_MQX)
#if defined(FMSTR_PLATFORM_MPC55xx)

void FMSTR_Isr(unsigned long vec)
{
  FMSTR_UNUSED(vec);
}

#else

void FMSTR_Isr(void)
{
}

#endif
#endif

#if defined(FMSTR_PLATFORM_HC12) || defined(FMSTR_PLATFORM_HC08) || defined(FMSTR_PLATFORM_MCF51xx)

/*******************************************************************************
 *
 * @brief    API: API: The 2nd FMSTR interrupt handler
 *
 *******************************************************************************/
void FMSTR_Isr2(void)
{
}

#endif

/* restore HC12 code segment */
#if defined(FMSTR_PLATFORM_HC12)
#include "default.sgm"
#endif
#endif                                 /* !FMSTR_DISABLE */
