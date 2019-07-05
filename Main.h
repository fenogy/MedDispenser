/*********************************************************************
 * Microchip Graphic Library Demo Application
 * The header file joins all header files used in the project.
 *********************************************************************
 * FileName:        MainDemo.h
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC24F, PIC24H, dsPIC, PIC32
 * Compiler:        C30/C32
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * Copyright © 2008 Microchip Technology Inc.  All rights reserved.
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
 * Author               Date        Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Anton Alkhimenok		05/29/2007
 * Sean Justice         02/07/2008  PIC32 support
 ********************************************************************/
#ifndef _MAINDEMO_H
    #define _MAINDEMO_H

////////////////////////////// INCLUDES //////////////////////////////
    #include "Compiler.h"
    #include "GenericTypeDefs.h"
    #include "Graphics/Graphics.h"
    #include "drv_spi.h"
    #include "MCHP25LC256.h"
    #include "SST25VF016.h"
    #include "TouchScreen.h"
    #include "Potentiometer.h"
    #include "Beep.h"
    #include "SideButtons.h"
    #include "rtcc.h"
    #include "HardwareProfile.h"
    #include "CustomControlDemo.h"
    #include "Graphics/mchpGfxDrv.h"
    #include <cpld.h>

/*****************************************************************************
 * SECTION:  BITMAPS
 *****************************************************************************/

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

/*********************************
 * Bitmap Structure
 * Label: bell_button_n
 * Description:  50x64 pixels, 16-bits per pixel
 ***********************************/
extern const IMAGE_FLASH bell_button_n;
#define bell_button_n_WIDTH     (50)
#define bell_button_n_HEIGHT    (64)
#define bell_button_n_SIZE      (6406)

/*********************************
 * Bitmap Structure
 * Label: compsel_button_n
 * Description:  72x35 pixels, 16-bits per pixel
 ***********************************/
extern const IMAGE_FLASH compsel_button_n;
#define compsel_button_n_WIDTH     (72)
#define compsel_button_n_HEIGHT    (35)
#define compsel_button_n_SIZE      (5046)
/*********************************
 * Bitmap Structure
 * Label: compsel_button_p
 * Description:  72x35 pixels, 16-bits per pixel
 ***********************************/
extern const IMAGE_FLASH compsel_button_p;
#define compsel_button_p_WIDTH     (72)
#define compsel_button_p_HEIGHT    (35)
#define compsel_button_p_SIZE      (5046)

/*********************************
 * Bitmap Structure
 * Label: dwnarrow_button_n
 * Description:  23x13 pixels, 16-bits per pixel
 ***********************************/
extern const IMAGE_FLASH dwnarrow_button_n;
#define dwnarrow_button_n_WIDTH     (23)
#define dwnarrow_button_n_HEIGHT    (13)
#define dwnarrow_button_n_SIZE      (604)
/*********************************
 * Bitmap Structure
 * Label: dwnarrow_button_p
 * Description:  23x13 pixels, 16-bits per pixel
 ***********************************/
extern const IMAGE_FLASH dwnarrow_button_p;
#define dwnarrow_button_p_WIDTH     (23)
#define dwnarrow_button_p_HEIGHT    (13)
#define dwnarrow_button_p_SIZE      (604)
/*********************************
 * Bitmap Structure
 * Label: uparrow_button_n
 * Description:  23x13 pixels, 16-bits per pixel
 ***********************************/
extern const IMAGE_FLASH uparrow_button_n;
#define uparrow_button_n_WIDTH     (23)
#define uparrow_button_n_HEIGHT    (13)
#define uparrow_button_n_SIZE      (604)
/*********************************
 * Bitmap Structure
 * Label: uparrow_button_p
 * Description:  23x13 pixels, 16-bits per pixel
 ***********************************/
extern const IMAGE_FLASH uparrow_button_p;
#define uparrow_button_p_WIDTH     (23)
#define uparrow_button_p_HEIGHT    (13)
#define uparrow_button_p_SIZE      (604)

/*********************************
 * Bitmap Structure
 * Label: keypad_button_n
 * Description:  62x35 pixels, 16-bits per pixel
 ***********************************/
extern const IMAGE_FLASH keypad_button_n;
#define keypad_button_n_WIDTH     (62)
#define keypad_button_n_HEIGHT    (35)
#define keypad_button_n_SIZE      (4346)
/*********************************
 * Bitmap Structure
 * Label: keypad_button_p
 * Description:  62x35 pixels, 16-bits per pixel
 ***********************************/
extern const IMAGE_FLASH keypad_button_p;
#define keypad_button_p_WIDTH     (62)
#define keypad_button_p_HEIGHT    (35)
#define keypad_button_p_SIZE      (4346)
/*********************************
 * Bitmap Structure
 * Label: bell_button_disabled
 * Description:  50x64 pixels, 16-bits per pixel
 ***********************************/
extern const IMAGE_FLASH bell_button_disabled;
#define bell_button_disabled_WIDTH     (50)
#define bell_button_disabled_HEIGHT    (64)
#define bell_button_disabled_SIZE      (6406)
/*********************************
 * Bitmap Structure
 * Label: bell_button_missed
 * Description:  50x64 pixels, 16-bits per pixel
 ***********************************/
extern const IMAGE_FLASH bell_button_missed;
#define bell_button_missed_WIDTH     (50)
#define bell_button_missed_HEIGHT    (64)
#define bell_button_missed_SIZE      (6406)
/*********************************
 * Bitmap Structure
 * Label: bell_button_p
 * Description:  50x64 pixels, 16-bits per pixel
 ***********************************/
extern const IMAGE_FLASH bell_button_p;
#define bell_button_p_WIDTH     (50)
#define bell_button_p_HEIGHT    (64)
#define bell_button_p_SIZE      (6406)
/*********************************
 * Installed Font Structure
 * Label: Calibri_Bold_36
 * Description:  Height: 44 pixels, 1 bit per pixel, Range: '0' to ':'
 ***********************************/
extern const FONT_FLASH Calibri_Bold_36;
#define Calibri_Bold_36_SIZE    (1460)

/*********************************
 * Installed Font Structure
 * Label: Calibri_42
 * Description:  Height: 53 pixels, 1 bit per pixel, Range: '0' to ':'
 ***********************************/
extern const FONT_FLASH Calibri_42;
#define Calibri_42_SIZE    (1748)

/*********************************
 * Installed Font Structure
 * Label: Calibri_48
 * Description:  Height: 60 pixels, 1 bit per pixel, Range: '0' to ':'
 ***********************************/
extern const FONT_FLASH Calibri_48;
#define Calibri_48_SIZE    (1972)

///*********************************
// * Installed Font Structure
// * Label: Arial_74
// * Description:  Height: 86 pixels, 1 bit per pixel, Range: '0' to ':'
// ***********************************/
//extern const FONT_FLASH Arial_74;
//#define Arial_74_SIZE    (5470)

/*********************************
 * Installed Font Structure
 * Label: Arial_Narrow_88
 * Description:  Height: 102 pixels, 1 bit per pixel, Range: '0' to ':'
 ***********************************/
extern const FONT_FLASH Arial_Narrow_88;
#define Arial_Narrow_88_SIZE    (5458)

/*********************************
 * Installed Font Structure
 * Label: Arial_Narrow_48
 * Description:  Height: 56 pixels, 1 bit per pixel, Range: 'a' to 'p'
 ***********************************/
extern const FONT_FLASH Arial_Narrow_48;
#define Arial_Narrow_48_SIZE    (2648)

/*********************************
 * Installed Font Structure
 * Label: Arial_24
 * Description:  Height: 29 pixels, 1 bit per pixel, Range: '0' to 'z'
 ***********************************/
extern const FONT_FLASH Arial_24;
#define Arial_24_SIZE    (4687)

/*********************************
 * Installed Font Structure
 * Label: Arial_Bold_14
 * Description:  Height: 17 pixels, 1 bit per pixel, Range: ' ' to 'z'
 ***********************************/
extern const FONT_FLASH Arial_Bold_14;
#define Arial_Bold_14_SIZE    (2565)

/*********************************
 * Installed Font Structure
 * Label: Arial_10
 * Description:  Height: 13 pixels, 1 bit per pixel, Range: ' ' to '~'
 ***********************************/
extern const FONT_FLASH Arial_10;
#define Arial_10_SIZE    (1688)
/*****************************************************************************
 * SECTION:  Fonts
 *****************************************************************************/

/*********************************
 * TTF Font File Structure
 * Label: NeoSans_12
 * Description:  Height: 16 pixels, 1 bit per pixel, Range: '.' to 'z'
 ***********************************/
extern const FONT_FLASH NeoSans_12;
#define NeoSans_12_SIZE    (1628)
#endif // _MAINDEMO_H
