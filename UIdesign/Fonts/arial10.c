/*****************************************************************************
 * FileName:        arial10.c
 * Processor:       PIC32MX
 * Compiler:        MPLAB C32/XC32 (see release notes for tested revision)
 * Linker:          MPLAB LINK32/XC32
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * Copyright(c) 2012 Microchip Technology Inc.  All rights reserved.
 * Microchip licenses to you the right to use, modify, copy and distribute
 * Software only when embedded on a Microchip microcontroller or digital
 * signal controller, which is integrated into your product or third party
 * product (pursuant to the sublicense terms in the accompanying license
 * agreement).
 *
 * You should refer to the license agreement accompanying this Software
 * for additional information regarding your rights and obligations.
 *
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED “AS IS” WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY
 * OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR
 * PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR
 * OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,
 * BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT
 * DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL,
 * INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA,
 * COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY
 * CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
 * OR OTHER SIMILAR COSTS.
 *
 *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * AUTO-GENERATED CODE:  Graphics Resource Converter version: 3.28.15
 *****************************************************************************/

/*****************************************************************************
 * SECTION:  Includes
 *****************************************************************************/
#include <Graphics/Graphics.h>
#include "HardwareProfile.h"

/*****************************************************************************
 * SECTION:  Graphics Library Firmware Check
 *****************************************************************************/
#if(GRAPHICS_LIBRARY_VERSION != 0x0306)
#warning "It is suggested to use Graphics Library version 3.06 with this version of GRC."
#endif


/*****************************************************************************
 * Converted Resources
 * -------------------
 *
 *
 * Fonts
 * -----
 * Arial_10 - Height: 13 pixels, 1 bit per pixel, Range: ' ' to '~'
 *****************************************************************************/

/*****************************************************************************
 * SECTION:  Fonts
 *****************************************************************************/

/*********************************
 * Installed Font Structure
 * Label: Arial_10
 * Description:  Height: 13 pixels, 1 bit per pixel, Range: ' ' to '~'
 ***********************************/

extern const char __Arial_10[] __attribute__((aligned(2)));

const FONT_FLASH Arial_10 =
{
    (FLASH | COMP_NONE),
    (GFX_FONT_SPACE char *)__Arial_10
};

const char __Arial_10[] __attribute__((aligned(2))) =
{
/****************************************
 * Font header
 ****************************************/
    0x00,           // Font ID
    0x00,           // Font information:  1 bit per pixel, Characters zero degress rotation
    0x20, 0x00,     // First Character
    0x7E, 0x00,     // Last Character
    0x0D, 0x00,     // Height
/****************************************
 * Font Glyph Table
 ****************************************/
    0x03,              // width of the glyph
    0x84, 0x01, 0x00,       // Character - 32, offset (0x00000184)
    0x03,              // width of the glyph
    0x91, 0x01, 0x00,       // Character - 33, offset (0x00000191)
    0x04,              // width of the glyph
    0x9E, 0x01, 0x00,       // Character - 34, offset (0x0000019E)
    0x06,              // width of the glyph
    0xAB, 0x01, 0x00,       // Character - 35, offset (0x000001AB)
    0x06,              // width of the glyph
    0xB8, 0x01, 0x00,       // Character - 36, offset (0x000001B8)
    0x09,              // width of the glyph
    0xC5, 0x01, 0x00,       // Character - 37, offset (0x000001C5)
    0x07,              // width of the glyph
    0xDF, 0x01, 0x00,       // Character - 38, offset (0x000001DF)
    0x02,              // width of the glyph
    0xEC, 0x01, 0x00,       // Character - 39, offset (0x000001EC)
    0x03,              // width of the glyph
    0xF9, 0x01, 0x00,       // Character - 40, offset (0x000001F9)
    0x03,              // width of the glyph
    0x06, 0x02, 0x00,       // Character - 41, offset (0x00000206)
    0x04,              // width of the glyph
    0x13, 0x02, 0x00,       // Character - 42, offset (0x00000213)
    0x06,              // width of the glyph
    0x20, 0x02, 0x00,       // Character - 43, offset (0x00000220)
    0x03,              // width of the glyph
    0x2D, 0x02, 0x00,       // Character - 44, offset (0x0000022D)
    0x03,              // width of the glyph
    0x3A, 0x02, 0x00,       // Character - 45, offset (0x0000023A)
    0x03,              // width of the glyph
    0x47, 0x02, 0x00,       // Character - 46, offset (0x00000247)
    0x03,              // width of the glyph
    0x54, 0x02, 0x00,       // Character - 47, offset (0x00000254)
    0x06,              // width of the glyph
    0x61, 0x02, 0x00,       // Character - 48, offset (0x00000261)
    0x06,              // width of the glyph
    0x6E, 0x02, 0x00,       // Character - 49, offset (0x0000026E)
    0x06,              // width of the glyph
    0x7B, 0x02, 0x00,       // Character - 50, offset (0x0000027B)
    0x06,              // width of the glyph
    0x88, 0x02, 0x00,       // Character - 51, offset (0x00000288)
    0x06,              // width of the glyph
    0x95, 0x02, 0x00,       // Character - 52, offset (0x00000295)
    0x06,              // width of the glyph
    0xA2, 0x02, 0x00,       // Character - 53, offset (0x000002A2)
    0x06,              // width of the glyph
    0xAF, 0x02, 0x00,       // Character - 54, offset (0x000002AF)
    0x06,              // width of the glyph
    0xBC, 0x02, 0x00,       // Character - 55, offset (0x000002BC)
    0x06,              // width of the glyph
    0xC9, 0x02, 0x00,       // Character - 56, offset (0x000002C9)
    0x06,              // width of the glyph
    0xD6, 0x02, 0x00,       // Character - 57, offset (0x000002D6)
    0x03,              // width of the glyph
    0xE3, 0x02, 0x00,       // Character - 58, offset (0x000002E3)
    0x03,              // width of the glyph
    0xF0, 0x02, 0x00,       // Character - 59, offset (0x000002F0)
    0x06,              // width of the glyph
    0xFD, 0x02, 0x00,       // Character - 60, offset (0x000002FD)
    0x06,              // width of the glyph
    0x0A, 0x03, 0x00,       // Character - 61, offset (0x0000030A)
    0x06,              // width of the glyph
    0x17, 0x03, 0x00,       // Character - 62, offset (0x00000317)
    0x06,              // width of the glyph
    0x24, 0x03, 0x00,       // Character - 63, offset (0x00000324)
    0x0A,              // width of the glyph
    0x31, 0x03, 0x00,       // Character - 64, offset (0x00000331)
    0x07,              // width of the glyph
    0x4B, 0x03, 0x00,       // Character - 65, offset (0x0000034B)
    0x07,              // width of the glyph
    0x58, 0x03, 0x00,       // Character - 66, offset (0x00000358)
    0x07,              // width of the glyph
    0x65, 0x03, 0x00,       // Character - 67, offset (0x00000365)
    0x07,              // width of the glyph
    0x72, 0x03, 0x00,       // Character - 68, offset (0x00000372)
    0x07,              // width of the glyph
    0x7F, 0x03, 0x00,       // Character - 69, offset (0x0000037F)
    0x06,              // width of the glyph
    0x8C, 0x03, 0x00,       // Character - 70, offset (0x0000038C)
    0x08,              // width of the glyph
    0x99, 0x03, 0x00,       // Character - 71, offset (0x00000399)
    0x07,              // width of the glyph
    0xA6, 0x03, 0x00,       // Character - 72, offset (0x000003A6)
    0x03,              // width of the glyph
    0xB3, 0x03, 0x00,       // Character - 73, offset (0x000003B3)
    0x05,              // width of the glyph
    0xC0, 0x03, 0x00,       // Character - 74, offset (0x000003C0)
    0x07,              // width of the glyph
    0xCD, 0x03, 0x00,       // Character - 75, offset (0x000003CD)
    0x06,              // width of the glyph
    0xDA, 0x03, 0x00,       // Character - 76, offset (0x000003DA)
    0x09,              // width of the glyph
    0xE7, 0x03, 0x00,       // Character - 77, offset (0x000003E7)
    0x07,              // width of the glyph
    0x01, 0x04, 0x00,       // Character - 78, offset (0x00000401)
    0x08,              // width of the glyph
    0x0E, 0x04, 0x00,       // Character - 79, offset (0x0000040E)
    0x07,              // width of the glyph
    0x1B, 0x04, 0x00,       // Character - 80, offset (0x0000041B)
    0x08,              // width of the glyph
    0x28, 0x04, 0x00,       // Character - 81, offset (0x00000428)
    0x07,              // width of the glyph
    0x35, 0x04, 0x00,       // Character - 82, offset (0x00000435)
    0x07,              // width of the glyph
    0x42, 0x04, 0x00,       // Character - 83, offset (0x00000442)
    0x07,              // width of the glyph
    0x4F, 0x04, 0x00,       // Character - 84, offset (0x0000044F)
    0x07,              // width of the glyph
    0x5C, 0x04, 0x00,       // Character - 85, offset (0x0000045C)
    0x07,              // width of the glyph
    0x69, 0x04, 0x00,       // Character - 86, offset (0x00000469)
    0x09,              // width of the glyph
    0x76, 0x04, 0x00,       // Character - 87, offset (0x00000476)
    0x07,              // width of the glyph
    0x90, 0x04, 0x00,       // Character - 88, offset (0x00000490)
    0x07,              // width of the glyph
    0x9D, 0x04, 0x00,       // Character - 89, offset (0x0000049D)
    0x06,              // width of the glyph
    0xAA, 0x04, 0x00,       // Character - 90, offset (0x000004AA)
    0x03,              // width of the glyph
    0xB7, 0x04, 0x00,       // Character - 91, offset (0x000004B7)
    0x03,              // width of the glyph
    0xC4, 0x04, 0x00,       // Character - 92, offset (0x000004C4)
    0x03,              // width of the glyph
    0xD1, 0x04, 0x00,       // Character - 93, offset (0x000004D1)
    0x05,              // width of the glyph
    0xDE, 0x04, 0x00,       // Character - 94, offset (0x000004DE)
    0x06,              // width of the glyph
    0xEB, 0x04, 0x00,       // Character - 95, offset (0x000004EB)
    0x03,              // width of the glyph
    0xF8, 0x04, 0x00,       // Character - 96, offset (0x000004F8)
    0x06,              // width of the glyph
    0x05, 0x05, 0x00,       // Character - 97, offset (0x00000505)
    0x06,              // width of the glyph
    0x12, 0x05, 0x00,       // Character - 98, offset (0x00000512)
    0x06,              // width of the glyph
    0x1F, 0x05, 0x00,       // Character - 99, offset (0x0000051F)
    0x06,              // width of the glyph
    0x2C, 0x05, 0x00,       // Character - 100, offset (0x0000052C)
    0x06,              // width of the glyph
    0x39, 0x05, 0x00,       // Character - 101, offset (0x00000539)
    0x03,              // width of the glyph
    0x46, 0x05, 0x00,       // Character - 102, offset (0x00000546)
    0x06,              // width of the glyph
    0x53, 0x05, 0x00,       // Character - 103, offset (0x00000553)
    0x06,              // width of the glyph
    0x60, 0x05, 0x00,       // Character - 104, offset (0x00000560)
    0x03,              // width of the glyph
    0x6D, 0x05, 0x00,       // Character - 105, offset (0x0000056D)
    0x03,              // width of the glyph
    0x7A, 0x05, 0x00,       // Character - 106, offset (0x0000057A)
    0x04,              // width of the glyph
    0x87, 0x05, 0x00,       // Character - 107, offset (0x00000587)
    0x03,              // width of the glyph
    0x94, 0x05, 0x00,       // Character - 108, offset (0x00000594)
    0x09,              // width of the glyph
    0xA1, 0x05, 0x00,       // Character - 109, offset (0x000005A1)
    0x06,              // width of the glyph
    0xBB, 0x05, 0x00,       // Character - 110, offset (0x000005BB)
    0x06,              // width of the glyph
    0xC8, 0x05, 0x00,       // Character - 111, offset (0x000005C8)
    0x06,              // width of the glyph
    0xD5, 0x05, 0x00,       // Character - 112, offset (0x000005D5)
    0x06,              // width of the glyph
    0xE2, 0x05, 0x00,       // Character - 113, offset (0x000005E2)
    0x03,              // width of the glyph
    0xEF, 0x05, 0x00,       // Character - 114, offset (0x000005EF)
    0x04,              // width of the glyph
    0xFC, 0x05, 0x00,       // Character - 115, offset (0x000005FC)
    0x03,              // width of the glyph
    0x09, 0x06, 0x00,       // Character - 116, offset (0x00000609)
    0x06,              // width of the glyph
    0x16, 0x06, 0x00,       // Character - 117, offset (0x00000616)
    0x05,              // width of the glyph
    0x23, 0x06, 0x00,       // Character - 118, offset (0x00000623)
    0x07,              // width of the glyph
    0x30, 0x06, 0x00,       // Character - 119, offset (0x00000630)
    0x05,              // width of the glyph
    0x3D, 0x06, 0x00,       // Character - 120, offset (0x0000063D)
    0x05,              // width of the glyph
    0x4A, 0x06, 0x00,       // Character - 121, offset (0x0000064A)
    0x05,              // width of the glyph
    0x57, 0x06, 0x00,       // Character - 122, offset (0x00000657)
    0x03,              // width of the glyph
    0x64, 0x06, 0x00,       // Character - 123, offset (0x00000664)
    0x03,              // width of the glyph
    0x71, 0x06, 0x00,       // Character - 124, offset (0x00000671)
    0x03,              // width of the glyph
    0x7E, 0x06, 0x00,       // Character - 125, offset (0x0000067E)
    0x06,              // width of the glyph
    0x8B, 0x06, 0x00,       // Character - 126, offset (0x0000068B)
/***********************************
 * Font Characters
 ***********************************/
/***********************************
 * Character - 32
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 33
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x00,         //         
    0x02,         //  *      
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 34
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x05,         // * *     
    0x05,         // * *     
    0x05,         // * *     
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 35
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x14,         //   * *   
    0x0A,         //  * *    
    0x1F,         // *****   
    0x0A,         //  * *    
    0x1F,         // *****   
    0x05,         // * *     
    0x05,         // * *     
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 36
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0E,         //  ***    
    0x15,         // * * *   
    0x07,         // ***     
    0x0E,         //  ***    
    0x14,         //   * *   
    0x15,         // * * *   
    0x0E,         //  ***    
    0x04,         //   *     
    0x00,         //         

/***********************************
 * Character - 37
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x44, 0x00,         //   *   *         
    0x2A, 0x00,         //  * * *          
    0x2A, 0x00,         //  * * *          
    0x54, 0x00,         //   * * *         
    0xB0, 0x00,         //     ** *        
    0xA8, 0x00,         //    * * *        
    0x48, 0x00,         //    *  *         
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 38
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x1C,         //   ***   
    0x12,         //  *  *   
    0x0C,         //   **    
    0x06,         //  **     
    0x69,         // *  * ** 
    0x31,         // *   **  
    0x6E,         //  *** ** 
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 39
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x01,         // *       
    0x01,         // *       
    0x01,         // *       
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 40
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x04,         //   *     
    0x02,         //  *      
    0x01,         // *       
    0x01,         // *       
    0x01,         // *       
    0x01,         // *       
    0x01,         // *       
    0x02,         //  *      
    0x04,         //   *     

/***********************************
 * Character - 41
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x01,         // *       
    0x02,         //  *      
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x02,         //  *      
    0x01,         // *       

/***********************************
 * Character - 42
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x07,         // ***     
    0x02,         //  *      
    0x05,         // * *     
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 43
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x04,         //   *     
    0x04,         //   *     
    0x1F,         // *****   
    0x04,         //   *     
    0x04,         //   *     
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 44
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x02,         //  *      
    0x02,         //  *      
    0x00,         //         

/***********************************
 * Character - 45
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x03,         // **      
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 46
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x02,         //  *      
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 47
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x04,         //   *     
    0x04,         //   *     
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x01,         // *       
    0x01,         // *       
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 48
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0E,         //  ***    
    0x11,         // *   *   
    0x11,         // *   *   
    0x11,         // *   *   
    0x11,         // *   *   
    0x11,         // *   *   
    0x0E,         //  ***    
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 49
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x08,         //    *    
    0x0C,         //   **    
    0x0A,         //  * *    
    0x08,         //    *    
    0x08,         //    *    
    0x08,         //    *    
    0x08,         //    *    
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 50
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0E,         //  ***    
    0x11,         // *   *   
    0x10,         //     *   
    0x08,         //    *    
    0x04,         //   *     
    0x02,         //  *      
    0x1F,         // *****   
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 51
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0E,         //  ***    
    0x11,         // *   *   
    0x10,         //     *   
    0x0C,         //   **    
    0x10,         //     *   
    0x11,         // *   *   
    0x0E,         //  ***    
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 52
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x18,         //    **   
    0x14,         //   * *   
    0x12,         //  *  *   
    0x11,         // *   *   
    0x3F,         // ******  
    0x10,         //     *   
    0x10,         //     *   
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 53
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x1E,         //  ****   
    0x02,         //  *      
    0x0F,         // ****    
    0x11,         // *   *   
    0x10,         //     *   
    0x11,         // *   *   
    0x0E,         //  ***    
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 54
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0E,         //  ***    
    0x11,         // *   *   
    0x0F,         // ****    
    0x11,         // *   *   
    0x11,         // *   *   
    0x11,         // *   *   
    0x0E,         //  ***    
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 55
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x1F,         // *****   
    0x08,         //    *    
    0x08,         //    *    
    0x04,         //   *     
    0x04,         //   *     
    0x02,         //  *      
    0x02,         //  *      
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 56
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0E,         //  ***    
    0x11,         // *   *   
    0x11,         // *   *   
    0x0E,         //  ***    
    0x11,         // *   *   
    0x11,         // *   *   
    0x0E,         //  ***    
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 57
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0E,         //  ***    
    0x11,         // *   *   
    0x11,         // *   *   
    0x11,         // *   *   
    0x1E,         //  ****   
    0x11,         // *   *   
    0x0E,         //  ***    
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 58
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x02,         //  *      
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x02,         //  *      
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 59
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x02,         //  *      
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x02,         //  *      
    0x02,         //  *      
    0x00,         //         

/***********************************
 * Character - 60
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x10,         //     *   
    0x0C,         //   **    
    0x02,         //  *      
    0x0C,         //   **    
    0x10,         //     *   
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 61
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x1F,         // *****   
    0x00,         //         
    0x1F,         // *****   
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 62
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x02,         //  *      
    0x0C,         //   **    
    0x10,         //     *   
    0x0C,         //   **    
    0x02,         //  *      
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 63
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x1E,         //  ****   
    0x21,         // *    *  
    0x20,         //      *  
    0x18,         //    **   
    0x08,         //    *    
    0x00,         //         
    0x08,         //    *    
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 64
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xF0, 0x00,         //     ****        
    0x0C, 0x01,         //   **    *       
    0xB4, 0x02,         //   * ** * *      
    0xCA, 0x02,         //  * *  ** *      
    0x4A, 0x02,         //  * *  *  *      
    0x4A, 0x01,         //  * *  * *       
    0xF2, 0x00,         //  *  ****        
    0x04, 0x03,         //   *     **      
    0xF8, 0x00,         //    *****        

/***********************************
 * Character - 65
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x08,         //    *    
    0x14,         //   * *   
    0x14,         //   * *   
    0x22,         //  *   *  
    0x3E,         //  *****  
    0x22,         //  *   *  
    0x41,         // *     * 
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 66
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x1E,         //  ****   
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x3E,         //  *****  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x1E,         //  ****   
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 67
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x1C,         //   ***   
    0x22,         //  *   *  
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x22,         //  *   *  
    0x1C,         //   ***   
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 68
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0E,         //  ***    
    0x12,         //  *  *   
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x12,         //  *  *   
    0x0E,         //  ***    
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 69
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x3E,         //  *****  
    0x02,         //  *      
    0x02,         //  *      
    0x3E,         //  *****  
    0x02,         //  *      
    0x02,         //  *      
    0x3E,         //  *****  
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 70
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x1E,         //  ****   
    0x02,         //  *      
    0x02,         //  *      
    0x0E,         //  ***    
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 71
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x18,         //    **   
    0x24,         //   *  *  
    0x02,         //  *      
    0x72,         //  *  *** 
    0x42,         //  *    * 
    0x24,         //   *  *  
    0x18,         //    **   
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 72
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x3E,         //  *****  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 73
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 74
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x08,         //    *    
    0x08,         //    *    
    0x08,         //    *    
    0x08,         //    *    
    0x08,         //    *    
    0x09,         // *  *    
    0x07,         // ***     
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 75
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x42,         //  *    * 
    0x22,         //  *   *  
    0x12,         //  *  *   
    0x0A,         //  * *    
    0x16,         //  ** *   
    0x22,         //  *   *  
    0x42,         //  *    * 
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 76
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x3E,         //  *****  
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 77
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x82, 0x00,         //  *     *        
    0xC6, 0x00,         //  **   **        
    0xC6, 0x00,         //  **   **        
    0xAA, 0x00,         //  * * * *        
    0xAA, 0x00,         //  * * * *        
    0xAA, 0x00,         //  * * * *        
    0x92, 0x00,         //  *  *  *        
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 78
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x22,         //  *   *  
    0x26,         //  **  *  
    0x26,         //  **  *  
    0x2A,         //  * * *  
    0x32,         //  *  **  
    0x32,         //  *  **  
    0x22,         //  *   *  
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 79
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x3C,         //   ****  
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x3C,         //   ****  
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 80
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x1E,         //  ****   
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x1E,         //  ****   
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 81
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x3C,         //   ****  
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x32,         //  *  **  
    0x7C,         //   ***** 
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 82
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x1E,         //  ****   
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x1E,         //  ****   
    0x12,         //  *  *   
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 83
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x1C,         //   ***   
    0x22,         //  *   *  
    0x02,         //  *      
    0x1C,         //   ***   
    0x20,         //      *  
    0x22,         //  *   *  
    0x1C,         //   ***   
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 84
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x3E,         //  *****  
    0x08,         //    *    
    0x08,         //    *    
    0x08,         //    *    
    0x08,         //    *    
    0x08,         //    *    
    0x08,         //    *    
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 85
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x1C,         //   ***   
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 86
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x41,         // *     * 
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x14,         //   * *   
    0x14,         //   * *   
    0x08,         //    *    
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 87
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x11, 0x01,         // *   *   *       
    0x29, 0x01,         // *  * *  *       
    0xAA, 0x00,         //  * * * *        
    0xAA, 0x00,         //  * * * *        
    0xAA, 0x00,         //  * * * *        
    0xAA, 0x00,         //  * * * *        
    0x44, 0x00,         //   *   *         
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 88
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x22,         //  *   *  
    0x14,         //   * *   
    0x08,         //    *    
    0x08,         //    *    
    0x14,         //   * *   
    0x22,         //  *   *  
    0x41,         // *     * 
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 89
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x41,         // *     * 
    0x22,         //  *   *  
    0x14,         //   * *   
    0x08,         //    *    
    0x08,         //    *    
    0x08,         //    *    
    0x08,         //    *    
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 90
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x3F,         // ******  
    0x10,         //     *   
    0x08,         //    *    
    0x04,         //   *     
    0x02,         //  *      
    0x01,         // *       
    0x3F,         // ******  
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 91
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x06,         //  **     
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x06,         //  **     

/***********************************
 * Character - 92
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x01,         // *       
    0x01,         // *       
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x04,         //   *     
    0x04,         //   *     
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 93
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x03,         // **      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x03,         // **      

/***********************************
 * Character - 94
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x04,         //   *     
    0x0A,         //  * *    
    0x0A,         //  * *    
    0x11,         // *   *   
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 95
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x3F,         // ******  

/***********************************
 * Character - 96
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x01,         // *       
    0x02,         //  *      
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 97
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x1C,         //   ***   
    0x10,         //     *   
    0x1C,         //   ***   
    0x12,         //  *  *   
    0x1E,         //  ****   
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 98
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x02,         //  *      
    0x02,         //  *      
    0x0E,         //  ***    
    0x12,         //  *  *   
    0x12,         //  *  *   
    0x12,         //  *  *   
    0x0E,         //  ***    
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 99
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0C,         //   **    
    0x12,         //  *  *   
    0x02,         //  *      
    0x12,         //  *  *   
    0x0C,         //   **    
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 100
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x10,         //     *   
    0x10,         //     *   
    0x1C,         //   ***   
    0x12,         //  *  *   
    0x12,         //  *  *   
    0x12,         //  *  *   
    0x1C,         //   ***   
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 101
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0C,         //   **    
    0x12,         //  *  *   
    0x1E,         //  ****   
    0x02,         //  *      
    0x1C,         //   ***   
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 102
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x04,         //   *     
    0x02,         //  *      
    0x07,         // ***     
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 103
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x1C,         //   ***   
    0x12,         //  *  *   
    0x12,         //  *  *   
    0x12,         //  *  *   
    0x1C,         //   ***   
    0x12,         //  *  *   
    0x0C,         //   **    

/***********************************
 * Character - 104
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x02,         //  *      
    0x02,         //  *      
    0x0E,         //  ***    
    0x12,         //  *  *   
    0x12,         //  *  *   
    0x12,         //  *  *   
    0x12,         //  *  *   
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 105
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x02,         //  *      
    0x00,         //         
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 106
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x02,         //  *      
    0x00,         //         
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x01,         // *       

/***********************************
 * Character - 107
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x01,         // *       
    0x01,         // *       
    0x09,         // *  *    
    0x05,         // * *     
    0x07,         // ***     
    0x05,         // * *     
    0x09,         // *  *    
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 108
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 109
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x7E, 0x00,         //  ******         
    0x92, 0x00,         //  *  *  *        
    0x92, 0x00,         //  *  *  *        
    0x92, 0x00,         //  *  *  *        
    0x92, 0x00,         //  *  *  *        
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 110
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0E,         //  ***    
    0x12,         //  *  *   
    0x12,         //  *  *   
    0x12,         //  *  *   
    0x12,         //  *  *   
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 111
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0C,         //   **    
    0x12,         //  *  *   
    0x12,         //  *  *   
    0x12,         //  *  *   
    0x0C,         //   **    
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 112
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0E,         //  ***    
    0x12,         //  *  *   
    0x12,         //  *  *   
    0x12,         //  *  *   
    0x0E,         //  ***    
    0x02,         //  *      
    0x02,         //  *      

/***********************************
 * Character - 113
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x1C,         //   ***   
    0x12,         //  *  *   
    0x12,         //  *  *   
    0x12,         //  *  *   
    0x1C,         //   ***   
    0x10,         //     *   
    0x10,         //     *   

/***********************************
 * Character - 114
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x06,         //  **     
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 115
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0E,         //  ***    
    0x01,         // *       
    0x06,         //  **     
    0x08,         //    *    
    0x07,         // ***     
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 116
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x02,         //  *      
    0x02,         //  *      
    0x07,         // ***     
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x06,         //  **     
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 117
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x12,         //  *  *   
    0x12,         //  *  *   
    0x12,         //  *  *   
    0x12,         //  *  *   
    0x1C,         //   ***   
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 118
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x11,         // *   *   
    0x0A,         //  * *    
    0x0A,         //  * *    
    0x0A,         //  * *    
    0x04,         //   *     
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 119
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x49,         // *  *  * 
    0x55,         // * * * * 
    0x55,         // * * * * 
    0x55,         // * * * * 
    0x22,         //  *   *  
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 120
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x11,         // *   *   
    0x0A,         //  * *    
    0x04,         //   *     
    0x0A,         //  * *    
    0x11,         // *   *   
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 121
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x11,         // *   *   
    0x0A,         //  * *    
    0x0A,         //  * *    
    0x0A,         //  * *    
    0x04,         //   *     
    0x04,         //   *     
    0x02,         //  *      

/***********************************
 * Character - 122
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x1F,         // *****   
    0x08,         //    *    
    0x04,         //   *     
    0x02,         //  *      
    0x1F,         // *****   
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 123
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x06,         //  **     
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x01,         // *       
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x06,         //  **     

/***********************************
 * Character - 124
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      

/***********************************
 * Character - 125
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x03,         // **      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x04,         //   *     
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x03,         // **      

/***********************************
 * Character - 126
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x17,         // *** *   
    0x1D,         // * ***   
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         

};

