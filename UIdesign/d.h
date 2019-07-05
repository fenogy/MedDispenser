/*****************************************************************************
 * FileName:        d.h
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
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED �AS IS� WITHOUT WARRANTY OF ANY
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

#ifndef D_H_FILE
#define D_H_FILE
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
 * This is an error check for the color depth
 *****************************************************************************/
#if (COLOR_DEPTH > 16)
#error "Color Depth needs to be 16 to correctly use these resources"
#endif



/*****************************************************************************
 * SECTION:  BITMAPS
 *****************************************************************************/

/*********************************
 * Bitmap Structure
 * Label: medicine_button_n
 * Description:  72x27 pixels, 16-bits per pixel
 ***********************************/
extern const IMAGE_FLASH medicine_button_n;
#define medicine_button_n_WIDTH     (72)
#define medicine_button_n_HEIGHT    (27)
#define medicine_button_n_SIZE      (3894)
/*********************************
 * Bitmap Structure
 * Label: medicine_button_p
 * Description:  72x27 pixels, 16-bits per pixel
 ***********************************/
extern const IMAGE_FLASH medicine_button_p;
#define medicine_button_p_WIDTH     (72)
#define medicine_button_p_HEIGHT    (27)
#define medicine_button_p_SIZE      (3894)
/*********************************
 * Bitmap Structure
 * Label: medidisp_button_n
 * Description:  98x27 pixels, 16-bits per pixel
 ***********************************/
extern const IMAGE_FLASH medidisp_button_n;
#define medidisp_button_n_WIDTH     (98)
#define medidisp_button_n_HEIGHT    (27)
#define medidisp_button_n_SIZE      (5298)
/*********************************
 * Bitmap Structure
 * Label: medidisp_button_p
 * Description:  98x27 pixels, 16-bits per pixel
 ***********************************/
extern const IMAGE_FLASH medidisp_button_p;
#define medidisp_button_p_WIDTH     (98)
#define medidisp_button_p_HEIGHT    (27)
#define medidisp_button_p_SIZE      (5298)
/*********************************
 * Bitmap Structure
 * Label: prescrip_button_n
 * Description:  72x27 pixels, 16-bits per pixel
 ***********************************/
extern const IMAGE_FLASH prescrip_button_n;
#define prescrip_button_n_WIDTH     (72)
#define prescrip_button_n_HEIGHT    (27)
#define prescrip_button_n_SIZE      (3894)
/*********************************
 * Bitmap Structure
 * Label: prescrip_button_p
 * Description:  72x27 pixels, 16-bits per pixel
 ***********************************/
extern const IMAGE_FLASH prescrip_button_p;
#define prescrip_button_p_WIDTH     (72)
#define prescrip_button_p_HEIGHT    (27)
#define prescrip_button_p_SIZE      (3894)
/*********************************
 * Bitmap Structure
 * Label: settings_button_n
 * Description:  72x27 pixels, 16-bits per pixel
 ***********************************/
extern const IMAGE_FLASH settings_button_n;
#define settings_button_n_WIDTH     (72)
#define settings_button_n_HEIGHT    (27)
#define settings_button_n_SIZE      (3894)
/*********************************
 * Bitmap Structure
 * Label: settings_button_p
 * Description:  72x27 pixels, 16-bits per pixel
 ***********************************/
extern const IMAGE_FLASH settings_button_p;
#define settings_button_p_WIDTH     (72)
#define settings_button_p_HEIGHT    (27)
#define settings_button_p_SIZE      (3894)
#endif

