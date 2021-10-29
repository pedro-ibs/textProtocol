
# *textProtocol*

```
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
```

---

<br>
 
## **Resumo**
Essa biblioteca foi desenvolvida para auxiliar no trabalho com protocolos de texto, que são geralmente utilizados em comunicações serias como RS232. Com ela é possível traduzir e trabalhar com diversos tipos de protocolos e textos padronizados como CSV.

---

<br>

### **Tipos de dados**
Para facilitar essa biblioteca contem alguns tipos, porem estes podem conflitar com tipos já existentes, nesse caso basta comenta los  

```
typedef const char (CCHR);

typedef uint16_t (u16);
typedef uint8_t (u8);
typedef uint32_t (u32);
typedef uint64_t (u64);

typedef const uint16_t (cu16);
typedef const uint8_t (cu8);
typedef const uint32_t (cu32);
typedef const uint64_t (cu64);
```

<br>

### **Testes e verificações**
Há algumas funções que permitem verificar se um valor está dentro do esperado. 

```
bool textp_bIsToken(CCHR pcTok);
bool textp_bIsHexNum(CCHR *pcStr);
bool textp_bIsDecNum(CCHR *pcStr);
bool textp_bIsCaractere(CCHR *pcStr);
```
Também há funções que ajudam a verificar se o valor lido é valido, isso pode ser util quando o tamanho da array e o conteudo é importante.
```
bool textp_bCheckStringSize(CCHR *pcString, const size_t uMaxSize);
bool textp_bCheckStringValid(CCHR *pcString, const size_t uMaxSize, CCHR *pcIgnoreValue);
```


<br>

### **Funções Auxiliares** 
Funções apara auxiliar no trabalho, como limpar, procurar, copiar um valor especifico
```
bool textp_bFindString( CCHR *pcFindAt, CCHR *pcFindThis);
u8 *textp_puCleanBlk(u8 *puBlk, u16 uLen);
char *textp_pcStrcpy(CCHR *pcStr, char *pcCopyTo,  u8 cuInit, u8 cuEnd);
```

<br>

### **Formatação**
Funções de formatação permite que altere os valores, isso pode ser util para diversas coisas como limpar, readequar, ou regras de um protocolo para outras.  
```
char *textp_pcCleanStr(char *pcStr);
char *textp_pcZeroLeft(char *pcStr, const size_t cuSizeWithZeros);
char *textp_pcRmChr( char *pcStr, CCHR ccRemoveChar );
char *textp_pcCharToChar(char *pcStr, CCHR ccFind, CCHR ccReplaceTo);
char *textp_pcToUpperCase(char *pcStr);
```

<br>

### **Protocolos Basicos**
Funções para trabalhar com alguns protocolos simples.
```
bool textp_bGetLabelInfo(CCHR *pcStr, CCHR *pcLabel, const u16 cuArg , char *pcBff);
bool textp_bGetValueInCSV(CCHR *pcLine, const size_t cuWhere, char *pcSaveTo);
bool textp_bGetValueInStr(CCHR *pcStr, const size_t cuWhere, CCHR div, char *pcSaveTo);
```


