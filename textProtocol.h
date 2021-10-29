/**
 * protocol.h
 *
 *  @date Created at:	11/03/2021 12:45:55
 *	@author:	Pedro Igor B. S.
 *	@email:		pibscontato@gmail.com
 * 	GitHub:		https://github.com/pedro-ibs
 * 	tabSize:	8
 *
 * ########################################################
 * 
 *   Copyright (C) Pedro Igor B. S 2019
 * -------------------------------------------------------------------
 *
 *   Licença: GNU GPL 2
 * -------------------------------------------------------------------
 *   This program is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU General Public License as
 *   published by the Free Software Foundation; version 2 of the
 *   License.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 * -------------------------------------------------------------------
 * 
 *  https://github.com/pedro-ibs/textProtocol
 * 
 * ########################################################
 *
 * Essa biblioteca foi desenvolvida para trabalhar com protocolos de
 * texto geralmente utilizados em comunicações serias como RS232
 * 
 * Com ela é possível traduzir e trabalhar com diverssos tipos de 
 * protocolos e textos padronizados como CSV
 *
 */

/* Includes ------------------------------------------------------------------*/
#include <stddef.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* modificação */

#ifndef protocol_H_
#define protocol_H_



/* macro ---------------------------------------------------------------------*/
#define TOKENS 		{',', ':', '=', ';', '&', '\n', '\r', '$', '{', '}', 0x00}
#define FALSE		( false )
#define TRUE		( true )
/* Definition ----------------------------------------------------------------*/

/**
 * Tipos de dados
 * 
 * Comente eles caso tenha conflito 
 */
typedef const char 		(CCHR);
typedef uint16_t		(u16);
typedef uint8_t			(u8);
typedef uint32_t 		(u32);
typedef uint64_t 		(u64);

typedef const uint16_t		(cu16);
typedef const uint8_t		(cu8);
typedef const uint32_t 		(cu32);
typedef const uint64_t 		(cu64);


bool textp_bFindString( CCHR *pcFindAt, CCHR *pcFindThis);
bool textp_bIsToken(CCHR pcTok);
bool textp_bIsHexNum(CCHR *pcStr);
bool textp_bIsDecNum(CCHR *pcStr);
bool textp_bIsCaractere(CCHR *pcStr);
bool textp_bGetLabelInfo(CCHR *pcStr, CCHR *pcLabel, const u16 cuArg , char *pcBff);
bool textp_bGetValueInCSV(CCHR *pcLine, const size_t cuWhere, char *pcSaveTo);
bool textp_bGetValueInStr(CCHR *pcStr, const size_t cuWhere, CCHR div, char *pcSaveTo);

u8 *textp_puCleanBlk(u8 *puBlk, u16 uLen);

char *textp_pcCleanStr(char *pcStr);
char *textp_pcZeroLeft(char *pcStr, const size_t cuSizeWithZeros);
char *textp_pcRmChr( char *pcStr, CCHR ccRemoveChar );
char *textp_pcCharToChar(char *pcStr, CCHR ccFind, CCHR ccReplaceTo);
char *textp_pcToUpperCase(char *pcStr);
char *textp_pcStrcpy(CCHR *pcStr, char *pcCopyTo,  u8 cuInit, u8 cuEnd);


bool textp_bCheckStringSize(CCHR *pcString, const size_t uMaxSize);
bool textp_bCheckStringValid(CCHR *pcString, const size_t uMaxSize, CCHR *pcIgnoreValue);

#endif /* protocol_H_ */