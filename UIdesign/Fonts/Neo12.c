/*****************************************************************************
 * FileName:        Neo12.c
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
 * NeoSans_12 - Height: 16 pixels, 1 bit per pixel, Range: '.' to 'z'
 *****************************************************************************/

/*****************************************************************************
 * SECTION:  Fonts
 *****************************************************************************/

/*********************************
 * TTF Font File Structure
 * Label: NeoSans_12
 * Description:  Height: 16 pixels, 1 bit per pixel, Range: '.' to 'z'
 ***********************************/

extern const char __NeoSans_12[] __attribute__((aligned(2)));

const FONT_FLASH NeoSans_12 =
{
    (FLASH | COMP_NONE),
    (GFX_FONT_SPACE char *)__NeoSans_12
};

const char __NeoSans_12[] __attribute__((aligned(2))) =
{
/****************************************
 * Font header
 ****************************************/
    0x00,           // Font ID
    0x00,           // Font information:  1 bit per pixel, Characters zero degress rotation
    0x2E, 0x00,     // First Character
    0x7A, 0x00,     // Last Character
    0x10, 0x00,     // Height
/****************************************
 * Font Glyph Table
 ****************************************/
    0x03,              // width of the glyph
    0x3C, 0x01, 0x00,       // Character - 46, offset (0x0000013C)
    0x04,              // width of the glyph
    0x4C, 0x01, 0x00,       // Character - 47, offset (0x0000014C)
    0x07,              // width of the glyph
    0x5C, 0x01, 0x00,       // Character - 48, offset (0x0000015C)
    0x07,              // width of the glyph
    0x6C, 0x01, 0x00,       // Character - 49, offset (0x0000016C)
    0x07,              // width of the glyph
    0x7C, 0x01, 0x00,       // Character - 50, offset (0x0000017C)
    0x07,              // width of the glyph
    0x8C, 0x01, 0x00,       // Character - 51, offset (0x0000018C)
    0x07,              // width of the glyph
    0x9C, 0x01, 0x00,       // Character - 52, offset (0x0000019C)
    0x07,              // width of the glyph
    0xAC, 0x01, 0x00,       // Character - 53, offset (0x000001AC)
    0x07,              // width of the glyph
    0xBC, 0x01, 0x00,       // Character - 54, offset (0x000001BC)
    0x07,              // width of the glyph
    0xCC, 0x01, 0x00,       // Character - 55, offset (0x000001CC)
    0x07,              // width of the glyph
    0xDC, 0x01, 0x00,       // Character - 56, offset (0x000001DC)
    0x08,              // width of the glyph
    0xEC, 0x01, 0x00,       // Character - 57, offset (0x000001EC)
    0x03,              // width of the glyph
    0xFC, 0x01, 0x00,       // Character - 58, offset (0x000001FC)
    0x03,              // width of the glyph
    0x0C, 0x02, 0x00,       // Character - 59, offset (0x0000020C)
    0x07,              // width of the glyph
    0x1C, 0x02, 0x00,       // Character - 60, offset (0x0000021C)
    0x07,              // width of the glyph
    0x2C, 0x02, 0x00,       // Character - 61, offset (0x0000022C)
    0x07,              // width of the glyph
    0x3C, 0x02, 0x00,       // Character - 62, offset (0x0000023C)
    0x05,              // width of the glyph
    0x4C, 0x02, 0x00,       // Character - 63, offset (0x0000024C)
    0x09,              // width of the glyph
    0x5C, 0x02, 0x00,       // Character - 64, offset (0x0000025C)
    0x08,              // width of the glyph
    0x7C, 0x02, 0x00,       // Character - 65, offset (0x0000027C)
    0x07,              // width of the glyph
    0x8C, 0x02, 0x00,       // Character - 66, offset (0x0000028C)
    0x07,              // width of the glyph
    0x9C, 0x02, 0x00,       // Character - 67, offset (0x0000029C)
    0x08,              // width of the glyph
    0xAC, 0x02, 0x00,       // Character - 68, offset (0x000002AC)
    0x07,              // width of the glyph
    0xBC, 0x02, 0x00,       // Character - 69, offset (0x000002BC)
    0x07,              // width of the glyph
    0xCC, 0x02, 0x00,       // Character - 70, offset (0x000002CC)
    0x07,              // width of the glyph
    0xDC, 0x02, 0x00,       // Character - 71, offset (0x000002DC)
    0x08,              // width of the glyph
    0xEC, 0x02, 0x00,       // Character - 72, offset (0x000002EC)
    0x03,              // width of the glyph
    0xFC, 0x02, 0x00,       // Character - 73, offset (0x000002FC)
    0x04,              // width of the glyph
    0x0C, 0x03, 0x00,       // Character - 74, offset (0x0000030C)
    0x07,              // width of the glyph
    0x1C, 0x03, 0x00,       // Character - 75, offset (0x0000031C)
    0x06,              // width of the glyph
    0x2C, 0x03, 0x00,       // Character - 76, offset (0x0000032C)
    0x09,              // width of the glyph
    0x3C, 0x03, 0x00,       // Character - 77, offset (0x0000033C)
    0x08,              // width of the glyph
    0x5C, 0x03, 0x00,       // Character - 78, offset (0x0000035C)
    0x08,              // width of the glyph
    0x6C, 0x03, 0x00,       // Character - 79, offset (0x0000036C)
    0x07,              // width of the glyph
    0x7C, 0x03, 0x00,       // Character - 80, offset (0x0000037C)
    0x08,              // width of the glyph
    0x8C, 0x03, 0x00,       // Character - 81, offset (0x0000038C)
    0x08,              // width of the glyph
    0x9C, 0x03, 0x00,       // Character - 82, offset (0x0000039C)
    0x07,              // width of the glyph
    0xAC, 0x03, 0x00,       // Character - 83, offset (0x000003AC)
    0x07,              // width of the glyph
    0xBC, 0x03, 0x00,       // Character - 84, offset (0x000003BC)
    0x08,              // width of the glyph
    0xCC, 0x03, 0x00,       // Character - 85, offset (0x000003CC)
    0x08,              // width of the glyph
    0xDC, 0x03, 0x00,       // Character - 86, offset (0x000003DC)
    0x0A,              // width of the glyph
    0xEC, 0x03, 0x00,       // Character - 87, offset (0x000003EC)
    0x08,              // width of the glyph
    0x0C, 0x04, 0x00,       // Character - 88, offset (0x0000040C)
    0x07,              // width of the glyph
    0x1C, 0x04, 0x00,       // Character - 89, offset (0x0000041C)
    0x07,              // width of the glyph
    0x2C, 0x04, 0x00,       // Character - 90, offset (0x0000042C)
    0x04,              // width of the glyph
    0x3C, 0x04, 0x00,       // Character - 91, offset (0x0000043C)
    0x04,              // width of the glyph
    0x4C, 0x04, 0x00,       // Character - 92, offset (0x0000044C)
    0x04,              // width of the glyph
    0x5C, 0x04, 0x00,       // Character - 93, offset (0x0000045C)
    0x07,              // width of the glyph
    0x6C, 0x04, 0x00,       // Character - 94, offset (0x0000046C)
    0x08,              // width of the glyph
    0x7C, 0x04, 0x00,       // Character - 95, offset (0x0000047C)
    0x04,              // width of the glyph
    0x8C, 0x04, 0x00,       // Character - 96, offset (0x0000048C)
    0x06,              // width of the glyph
    0x9C, 0x04, 0x00,       // Character - 97, offset (0x0000049C)
    0x07,              // width of the glyph
    0xAC, 0x04, 0x00,       // Character - 98, offset (0x000004AC)
    0x05,              // width of the glyph
    0xBC, 0x04, 0x00,       // Character - 99, offset (0x000004BC)
    0x07,              // width of the glyph
    0xCC, 0x04, 0x00,       // Character - 100, offset (0x000004CC)
    0x07,              // width of the glyph
    0xDC, 0x04, 0x00,       // Character - 101, offset (0x000004DC)
    0x06,              // width of the glyph
    0xEC, 0x04, 0x00,       // Character - 102, offset (0x000004EC)
    0x07,              // width of the glyph
    0xFC, 0x04, 0x00,       // Character - 103, offset (0x000004FC)
    0x07,              // width of the glyph
    0x0C, 0x05, 0x00,       // Character - 104, offset (0x0000050C)
    0x03,              // width of the glyph
    0x1C, 0x05, 0x00,       // Character - 105, offset (0x0000051C)
    0x04,              // width of the glyph
    0x2C, 0x05, 0x00,       // Character - 106, offset (0x0000052C)
    0x06,              // width of the glyph
    0x3C, 0x05, 0x00,       // Character - 107, offset (0x0000053C)
    0x03,              // width of the glyph
    0x4C, 0x05, 0x00,       // Character - 108, offset (0x0000054C)
    0x0A,              // width of the glyph
    0x5C, 0x05, 0x00,       // Character - 109, offset (0x0000055C)
    0x07,              // width of the glyph
    0x7C, 0x05, 0x00,       // Character - 110, offset (0x0000057C)
    0x07,              // width of the glyph
    0x8C, 0x05, 0x00,       // Character - 111, offset (0x0000058C)
    0x07,              // width of the glyph
    0x9C, 0x05, 0x00,       // Character - 112, offset (0x0000059C)
    0x07,              // width of the glyph
    0xAC, 0x05, 0x00,       // Character - 113, offset (0x000005AC)
    0x05,              // width of the glyph
    0xBC, 0x05, 0x00,       // Character - 114, offset (0x000005BC)
    0x06,              // width of the glyph
    0xCC, 0x05, 0x00,       // Character - 115, offset (0x000005CC)
    0x06,              // width of the glyph
    0xDC, 0x05, 0x00,       // Character - 116, offset (0x000005DC)
    0x07,              // width of the glyph
    0xEC, 0x05, 0x00,       // Character - 117, offset (0x000005EC)
    0x08,              // width of the glyph
    0xFC, 0x05, 0x00,       // Character - 118, offset (0x000005FC)
    0x09,              // width of the glyph
    0x0C, 0x06, 0x00,       // Character - 119, offset (0x0000060C)
    0x07,              // width of the glyph
    0x2C, 0x06, 0x00,       // Character - 120, offset (0x0000062C)
    0x06,              // width of the glyph
    0x3C, 0x06, 0x00,       // Character - 121, offset (0x0000063C)
    0x06,              // width of the glyph
    0x4C, 0x06, 0x00,       // Character - 122, offset (0x0000064C)
/***********************************
 * Font Characters
 ***********************************/
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
    0x00,         //         
    0x00,         //         
    0x02,         //  *      
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 47
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x08,         //    *    
    0x08,         //    *    
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x01,         // *       
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 48
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x3C,         //   ****  
    0x66,         //  **  ** 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x66,         //  **  ** 
    0x3C,         //   ****  
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 49
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0C,         //   **    
    0x0A,         //  * *    
    0x08,         //    *    
    0x08,         //    *    
    0x08,         //    *    
    0x08,         //    *    
    0x08,         //    *    
    0x08,         //    *    
    0x08,         //    *    
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 50
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x1E,         //  ****   
    0x20,         //      *  
    0x20,         //      *  
    0x30,         //     **  
    0x18,         //    **   
    0x04,         //   *     
    0x02,         //  *      
    0x02,         //  *      
    0x3E,         //  *****  
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 51
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x1E,         //  ****   
    0x20,         //      *  
    0x20,         //      *  
    0x20,         //      *  
    0x1E,         //  ****   
    0x20,         //      *  
    0x20,         //      *  
    0x20,         //      *  
    0x1E,         //  ****   
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 52
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x10,         //     *   
    0x18,         //    **   
    0x1C,         //   ***   
    0x14,         //   * *   
    0x12,         //  *  *   
    0x11,         // *   *   
    0x3F,         // ******  
    0x10,         //     *   
    0x10,         //     *   
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 53
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x3E,         //  *****  
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x1E,         //  ****   
    0x20,         //      *  
    0x20,         //      *  
    0x20,         //      *  
    0x1E,         //  ****   
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 54
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x7C,         //   ***** 
    0x02,         //  *      
    0x02,         //  *      
    0x3E,         //  *****  
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x66,         //  **  ** 
    0x3C,         //   ****  
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 55
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x3E,         //  *****  
    0x20,         //      *  
    0x20,         //      *  
    0x10,         //     *   
    0x10,         //     *   
    0x08,         //    *    
    0x08,         //    *    
    0x04,         //   *     
    0x04,         //   *     
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 56
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x3C,         //   ****  
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x3C,         //   ****  
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x3C,         //   ****  
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 57
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
    0x7C,         //   ***** 
    0x40,         //       * 
    0x40,         //       * 
    0x3C,         //   ****  
    0x00,         //         
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
    0x00,         //         
    0x00,         //         
    0x02,         //  *      
    0x00,         //         
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
    0x00,         //         
    0x02,         //  *      
    0x02,         //  *      
    0x01,         // *       
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 60
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x30,         //     **  
    0x08,         //    *    
    0x04,         //   *     
    0x06,         //  **     
    0x08,         //    *    
    0x30,         //     **  
    0x00,         //         
    0x00,         //         
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
    0x3E,         //  *****  
    0x00,         //         
    0x00,         //         
    0x3E,         //  *****  
    0x00,         //         
    0x00,         //         
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
    0x06,         //  **     
    0x08,         //    *    
    0x10,         //     *   
    0x30,         //     **  
    0x08,         //    *    
    0x06,         //  **     
    0x00,         //         
    0x00,         //         
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
    0x0F,         // ****    
    0x10,         //     *   
    0x10,         //     *   
    0x18,         //    **   
    0x0C,         //   **    
    0x06,         //  **     
    0x02,         //  *      
    0x00,         //         
    0x02,         //  *      
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 64
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x7C, 0x00,         //   *****         
    0x86, 0x00,         //  **    *        
    0x3B, 0x01,         // ** ***  *       
    0x25, 0x01,         // * *  *  *       
    0x25, 0x01,         // * *  *  *       
    0xA5, 0x00,         // * *  * *        
    0x7D, 0x00,         // * *****         
    0x02, 0x00,         //  *              
    0x3C, 0x00,         //   ****          
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 65
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x18,         //    **   
    0x14,         //   * *   
    0x14,         //   * *   
    0x24,         //   *  *  
    0x24,         //   *  *  
    0x3E,         //  *****  
    0x62,         //  *   ** 
    0x42,         //  *    * 
    0x43,         // **    * 
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 66
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x3E,         //  *****  
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x3E,         //  *****  
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x3E,         //  *****  
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 67
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x3C,         //   ****  
    0x06,         //  **     
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x06,         //  **     
    0x3C,         //   ****  
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 68
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x3E,         //  *****  
    0x22,         //  *   *  
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x22,         //  *   *  
    0x1E,         //  ****   
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 69
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x3C,         //   ****  
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x3E,         //  *****  
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x3C,         //   ****  
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 70
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x3C,         //   ****  
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x3E,         //  *****  
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 71
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x3C,         //   ****  
    0x06,         //  **     
    0x02,         //  *      
    0x02,         //  *      
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x26,         //  **  *  
    0x3C,         //   ****  
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 72
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x7E,         //  ****** 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x00,         //         
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
    0x02,         //  *      
    0x02,         //  *      
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 74
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x06,         //  **     
    0x00,         //         

/***********************************
 * Character - 75
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x62,         //  *   ** 
    0x32,         //  *  **  
    0x1A,         //  * **   
    0x0E,         //  ***    
    0x06,         //  **     
    0x0E,         //  ***    
    0x1A,         //  * **   
    0x32,         //  *  **  
    0x62,         //  *   ** 
    0x00,         //         
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
    0x02,         //  *      
    0x02,         //  *      
    0x3C,         //   ****  
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 77
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0xC6, 0x00,         //  **   **        
    0xC6, 0x00,         //  **   **        
    0xC6, 0x00,         //  **   **        
    0xAA, 0x00,         //  * * * *        
    0xAA, 0x00,         //  * * * *        
    0x92, 0x00,         //  *  *  *        
    0x82, 0x00,         //  *     *        
    0x82, 0x00,         //  *     *        
    0x82, 0x00,         //  *     *        
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 78
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x46,         //  **   * 
    0x46,         //  **   * 
    0x4E,         //  ***  * 
    0x4A,         //  * *  * 
    0x5A,         //  * ** * 
    0x52,         //  *  * * 
    0x72,         //  *  *** 
    0x62,         //  *   ** 
    0x62,         //  *   ** 
    0x00,         //         
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
    0x66,         //  **  ** 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x66,         //  **  ** 
    0x3C,         //   ****  
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 80
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x3E,         //  *****  
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x3E,         //  *****  
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x00,         //         
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
    0x66,         //  **  ** 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x26,         //  **  *  
    0x3C,         //   ****  
    0x08,         //    *    
    0x38,         //    ***  
    0x00,         //         

/***********************************
 * Character - 82
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x3E,         //  *****  
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x3E,         //  *****  
    0x12,         //  *  *   
    0x22,         //  *   *  
    0x62,         //  *   ** 
    0x42,         //  *    * 
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 83
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x3C,         //   ****  
    0x02,         //  *      
    0x02,         //  *      
    0x04,         //   *     
    0x18,         //    **   
    0x30,         //     **  
    0x20,         //      *  
    0x20,         //      *  
    0x1E,         //  ****   
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 84
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x7F,         // ******* 
    0x08,         //    *    
    0x08,         //    *    
    0x08,         //    *    
    0x08,         //    *    
    0x08,         //    *    
    0x08,         //    *    
    0x08,         //    *    
    0x08,         //    *    
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 85
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x66,         //  **  ** 
    0x3C,         //   ****  
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 86
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x43,         // **    * 
    0x42,         //  *    * 
    0x42,         //  *    * 
    0x22,         //  *   *  
    0x24,         //   *  *  
    0x24,         //   *  *  
    0x34,         //   * **  
    0x1C,         //   ***   
    0x18,         //    **   
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 87
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x03, 0x03,         // **      **      
    0x02, 0x01,         //  *      *       
    0x02, 0x01,         //  *      *       
    0x32, 0x01,         //  *  **  *       
    0x32, 0x01,         //  *  **  *       
    0x2A, 0x01,         //  * * *  *       
    0xCA, 0x00,         //  * *  **        
    0xCC, 0x00,         //   **  **        
    0xCC, 0x00,         //   **  **        
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 88
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x42,         //  *    * 
    0x26,         //  **  *  
    0x24,         //   *  *  
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x24,         //   *  *  
    0x22,         //  *   *  
    0x42,         //  *    * 
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 89
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x63,         // **   ** 
    0x22,         //  *   *  
    0x36,         //  ** **  
    0x14,         //   * *   
    0x1C,         //   ***   
    0x08,         //    *    
    0x08,         //    *    
    0x08,         //    *    
    0x08,         //    *    
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 90
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x3E,         //  *****  
    0x60,         //      ** 
    0x20,         //      *  
    0x10,         //     *   
    0x08,         //    *    
    0x08,         //    *    
    0x04,         //   *     
    0x02,         //  *      
    0x7E,         //  ****** 
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 91
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0E,         //  ***    
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x0E,         //  ***    
    0x00,         //         

/***********************************
 * Character - 92
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x01,         // *       
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x08,         //    *    
    0x08,         //    *    
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 93
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x07,         // ***     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x07,         // ***     
    0x00,         //         

/***********************************
 * Character - 94
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x1C,         //   ***   
    0x36,         //  ** **  
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
    0x00,         //         
    0x7E,         //  ****** 
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 96
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x03,         // **      
    0x04,         //   *     
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
 * Character - 97
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0E,         //  ***    
    0x10,         //     *   
    0x10,         //     *   
    0x1E,         //  ****   
    0x12,         //  *  *   
    0x12,         //  *  *   
    0x1E,         //  ****   
    0x00,         //         
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
    0x1E,         //  ****   
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x1E,         //  ****   
    0x00,         //         
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
    0x1C,         //   ***   
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x1C,         //   ***   
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 100
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x20,         //      *  
    0x20,         //      *  
    0x3C,         //   ****  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x3C,         //   ****  
    0x00,         //         
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
    0x1C,         //   ***   
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x3E,         //  *****  
    0x02,         //  *      
    0x02,         //  *      
    0x3C,         //   ****  
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 102
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x1C,         //   ***   
    0x04,         //   *     
    0x0E,         //  ***    
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x00,         //         
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
    0x3C,         //   ****  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x1E,         //  ****   
    0x06,         //  **     
    0x3A,         //  * ***  
    0x22,         //  *   *  
    0x3C,         //   ****  
    0x00,         //         

/***********************************
 * Character - 104
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x02,         //  *      
    0x02,         //  *      
    0x1E,         //  ****   
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x00,         //         
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
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 106
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x04,         //   *     
    0x00,         //         
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x06,         //  **     
    0x00,         //         

/***********************************
 * Character - 107
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x02,         //  *      
    0x02,         //  *      
    0x32,         //  *  **  
    0x1A,         //  * **   
    0x0E,         //  ***    
    0x06,         //  **     
    0x0E,         //  ***    
    0x1A,         //  * **   
    0x32,         //  *  **  
    0x00,         //         
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
    0x02,         //  *      
    0x02,         //  *      
    0x00,         //         
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
    0xFE, 0x00,         //  *******        
    0x12, 0x01,         //  *  *   *       
    0x12, 0x01,         //  *  *   *       
    0x12, 0x01,         //  *  *   *       
    0x12, 0x01,         //  *  *   *       
    0x12, 0x01,         //  *  *   *       
    0x12, 0x01,         //  *  *   *       
    0x00, 0x00,         //                 
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
    0x1E,         //  ****   
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x00,         //         
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
    0x1C,         //   ***   
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x1C,         //   ***   
    0x00,         //         
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
    0x1E,         //  ****   
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x1E,         //  ****   
    0x02,         //  *      
    0x02,         //  *      
    0x00,         //         

/***********************************
 * Character - 113
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x3C,         //   ****  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x3C,         //   ****  
    0x20,         //      *  
    0x20,         //      *  
    0x00,         //         

/***********************************
 * Character - 114
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x0E,         //  ***    
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x02,         //  *      
    0x00,         //         
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
    0x1E,         //  ****   
    0x02,         //  *      
    0x06,         //  **     
    0x0C,         //   **    
    0x10,         //     *   
    0x10,         //     *   
    0x0E,         //  ***    
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 116
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x04,         //   *     
    0x0E,         //  ***    
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x04,         //   *     
    0x0C,         //   **    
    0x00,         //         
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
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x22,         //  *   *  
    0x3C,         //   ****  
    0x00,         //         
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
    0x42,         //  *    * 
    0x24,         //   *  *  
    0x24,         //   *  *  
    0x24,         //   *  *  
    0x18,         //    **   
    0x18,         //    **   
    0x18,         //    **   
    0x00,         //         
    0x00,         //         
    0x00,         //         

/***********************************
 * Character - 119
 ***********************************/
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x03, 0x01,         // **      *       
    0x32, 0x01,         //  *  **  *       
    0xB2, 0x01,         //  *  ** **       
    0xAA, 0x00,         //  * * * *        
    0xAA, 0x00,         //  * * * *        
    0xCA, 0x00,         //  * *  **        
    0xC4, 0x00,         //   *   **        
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 
    0x00, 0x00,         //                 

/***********************************
 * Character - 120
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x22,         //  *   *  
    0x16,         //  ** *   
    0x0C,         //   **    
    0x08,         //    *    
    0x14,         //   * *   
    0x12,         //  *  *   
    0x23,         // **   *  
    0x00,         //         
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
    0x23,         // **   *  
    0x22,         //  *   *  
    0x12,         //  *  *   
    0x12,         //  *  *   
    0x14,         //   * *   
    0x0C,         //   **    
    0x0C,         //   **    
    0x08,         //    *    
    0x07,         // ***     
    0x00,         //         

/***********************************
 * Character - 122
 ***********************************/
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x00,         //         
    0x1E,         //  ****   
    0x10,         //     *   
    0x08,         //    *    
    0x0C,         //   **    
    0x04,         //   *     
    0x02,         //  *      
    0x1E,         //  ****   
    0x00,         //         
    0x00,         //         
    0x00,         //         

};

