
/*******************************************************************/

#pragma config FPLLODIV = DIV_2, FPLLMUL = MUL_20, FPLLIDIV = DIV_1, FWDTEN = OFF, FCKSM = CSECME, FPBDIV = DIV_1
#pragma config OSCIOFNC = ON, POSCMOD = XT, FSOSCEN = ON, FNOSC = PRIPLL
#pragma config CP = OFF, BWP = OFF, PWP = OFF

#define ID_BTN1 20
#define ID_BTN2 21
#define ID_BTN3 22
#define ID_BTN4 23

#define ID_BELL_BTN1 24
#define ID_BELL_BTN2 25
#define ID_BELL_BTN3 26
#define ID_BELL_BTN4 27
#define ID_BELL_BTN5 28

#define ID_MEDICINE_BTN1 30
#define ID_MEDICINE_BTN2 31
#define ID_MEDICINE_BTN3 32
#define ID_MEDICINE_BTN4 33
#define ID_MEDICINE_BTN5 34
#define ID_MEDICINE_BTN6 35
#define ID_MEDICINE_BTN7 36
#define ID_MEDICINE_BTN8 37

#define ID_PRESCRIP_BTN1 40
#define ID_PRESCRIP_BTN2 41
#define ID_PRESCRIP_BTN3 42
#define ID_PRESCRIP_BTN4 43
#define ID_PRESCRIP_BTN5 44

#define ID_PRESCRIP_TEXT1 45
#define ID_PRESCRIP_TEXT2 46
#define ID_PRESCRIP_TEXT3 47
#define ID_PRESCRIP_TEXT4 48

#define ID_PRESCRIP_C1_R1 100
#define ID_PRESCRIP_C1_R2 101
#define ID_PRESCRIP_C1_R3 102
#define ID_PRESCRIP_C1_R4 103
#define ID_PRESCRIP_C1_R5 104


#define ID_PRESCRIP_C2_R1 110
#define ID_PRESCRIP_C2_R2 111
#define ID_PRESCRIP_C2_R3 112
#define ID_PRESCRIP_C2_R4 113
#define ID_PRESCRIP_C2_R5 114


#define ID_PRESCRIP_C3_R1 120
#define ID_PRESCRIP_C3_R2 121
#define ID_PRESCRIP_C3_R3 122
#define ID_PRESCRIP_C3_R4 123
#define ID_PRESCRIP_C3_R5 124


#define ID_PRESCRIP_C4_R1 130
#define ID_PRESCRIP_C4_R2 131
#define ID_PRESCRIP_C4_R3 132
#define ID_PRESCRIP_C4_R4 133
#define ID_PRESCRIP_C4_R5 134



#define ID_SETTINGS_YEAR 50
#define ID_SETTINGS_MNTH 51
#define ID_SETTINGS_DATE 52
#define ID_SETTINGS_TIME 53
#define ID_SETTINGS_ALRM 54
#define ID_SETTINGS_YEAR_VALUE 55
#define ID_SETTINGS_MNTH_VALUE 56
#define ID_SETTINGS_DATE_VALUE 57
#define ID_SETTINGS_TIME_HR_VALUE 58
#define ID_SETTINGS_TIME_MN_VALUE 59
#define ID_SETTINGS_ALRM_VALUE 60

#define ID_SETTINGS_YEAR_UP     61
#define ID_SETTINGS_YEAR_DOWN   62
#define ID_SETTINGS_MNTH_UP     63
#define ID_SETTINGS_MNTH_DOWN   64
#define ID_SETTINGS_DATE_UP     65
#define ID_SETTINGS_DATE_DOWN   66
#define ID_SETTINGS_TIME_HR_UP  67
#define ID_SETTINGS_TIME_HR_DOWN 68
#define ID_SETTINGS_TIME_MN_UP  69
#define ID_SETTINGS_TIME_MN_DOWN 70
#define ID_SETTINGS_ALRM_UP     71
#define ID_SETTINGS_ALRM_DOWN   72

#define ID_SLD1 12
#define ID_PICTURE1 13
#define ID_TIME_TEXT  14
#define ID_AMPM_TEXT  15
#define ID_YEAR_TEXT  16
#define ID_MONTH_TEXT  17
#define ID_DATE_TEXT  18
#define EB5STARTX       125
#define SELECTBTNWIDTH  25
#define EBSTARTY2       110

#define ID_TIME_HR_TEXT  500
#define ID_TIME_MIN_TEXT  501
#define ID_TIME_COLON_TEXT  502

#define ID_KEYPAD_1     200
#define ID_KEYPAD_2ABC  201
#define ID_KEYPAD_3DEF  202
#define ID_KEYPAD_4GHI  203
#define ID_KEYPAD_5JKL  204
#define ID_KEYPAD_6MNO  205
#define ID_KEYPAD_7PQRS 206
#define ID_KEYPAD_8TUV   207
#define ID_KEYPAD_9WXYZ  208
#define ID_KEYPAD_0SP    209
#define ID_KEYPAD_OK    210
#define ID_KEYPAD_CANCEL    211
#define ID_KEYPAD_EDITBOX 212
#define ID_KEYPAD_DEL 213
#define ID_KEYPAD_COLON 214
#define ID_KEYPAD_VARIABLE 215

#define ID_ALARM_OK     300
#define ID_ALARM_ABORT     301
#define ID_ALARM_DESCRIPTION1     302
#define ID_ALARM_DESCRIPTION2     303
#define ID_ALARM_DESCRIPTION3     307
#define ID_ALARM_QTY     304
#define ID_ALARM_IMAGE     305
#define ID_ALARM_SKIP     306

/////////////////////////////////////////////////////////////////////////////
#define GRAY20      RGBConvert(51, 51, 51)
#define RED4        RGBConvert(139, 0, 0)
#define FIREBRICK1  RGBConvert(255, 48, 48)
#define DARKGREEN   RGBConvert(0, 100, 0)
#define PALEGREEN   RGBConvert(152, 251, 152)
#define GRAY230   RGBConvert(230, 230, 230)
#define GRAY200   RGBConvert(200, 200, 200)
#define ORANGE   RGBConvert(255, 255, 0)
#define GREEN   RGBConvert(0, 255, 0)

#define FillCircle(x1, y1, rad) FillBevel(x1, y1, x1, y1, rad)
#define Rectangle(left, top, right, bottom) Bevel(left, top, right, bottom, 0)

#include "Main.h"
#include "TimeDelay.h"
#include "StringConversion.h"
#include "InternalResourceXC32.h"
#include <string.h>
#include <stdlib.h>

#define NVM_PROGRAM_PAGE 0xbd008000
#define NVM_PAGE_SIZE    4096

unsigned int readbuff[128];
unsigned int writebuff[128];

XCHAR dateTimeStr[32];
int updateTime = 1;
int updateColon = 1;
int updateMin = 1;
volatile DWORD  tick = 0;

void InitializeBoard(void);
void Init_UART1(int baudRate);
void CreateMenu(void);
void CreateMainPage(void);
void CreateMedicinePage(void);
void CreatePrescriptionPage(void);
void CreateSettingsPage(void);
void CreateKeyPad(void);
void CreateNotificationPage(void);
void CreateKeyPadPage(XCHAR *str);
void CreateAlarmPage(int ID);

WORD MsgMenu(WORD objMsg, OBJ_HEADER* pObj, GOL_MSG* pMsg);
WORD MsgMainPage(WORD objMsg, OBJ_HEADER* pObj, GOL_MSG* pMsg);
WORD MsgPrescriptionPage(WORD objMsg, OBJ_HEADER* pObj, GOL_MSG* pMsg);
WORD MsgMedicinePage(WORD objMsg, OBJ_HEADER* pObj, GOL_MSG* pMsg);
WORD MsgSettingsPage(WORD objMsg, OBJ_HEADER* pObj, GOL_MSG* pMsg);
WORD MsgKeyPadPage(WORD objMsg, OBJ_HEADER* pObj, GOL_MSG* pMsg);

typedef enum
{
    CREATE_MAINPAGE          = 0,
    DISPLAY_MAINPAGE,
    CREATE_PRESCRIPTIONPAGE,
    DISPLAY_PRESCRIPTIONPAGE,
    CREATE_MEDICINEPAGE,
    DISPLAY_MEDICINEPAGE,
    CREATE_SETTINGSPAGE,
    DISPLAY_SETTINGSPAGE,
    CREATE_KEYPAGE,
    DISPLAY_KEYPAGE,
    CREATE_ALARMPAGE,
    DISPLAY_ALARMPAGE,
    // these states are for time and date settings 0xF3xx is used here as a
    // state ID to check when date and time are to be updated or not.
    CREATE_DATETIME         = 0xF300,                       // creates the date and time setting menu
    DISPLAY_DATETIME        = 0xF301,                       // displays the menu for the date and time setting
    DISPLAY_DATE_PDMENU     = 0xF302,                       // displays the pulldown menu to set one of the date items (month, day or year)
    SHOW_DATE_PDMENU        = 0xF303,                       // creates the pulldown menu to set one of the date items (month, day or year)
    HIDE_DATE_PDMENU        = 0xF304,                       // hides the pulldown menu to set one of the date items (month, day or year)
} SCREEN_STATES;

typedef enum
{
    ERROR         = 0,
    WAIT,
    OK,

} COMPARTMENT_STATES;
/////////////////////////////////////////////////////////////////////////////
// SPI Device Initialization Function
/////////////////////////////////////////////////////////////////////////////
#if defined (USE_SST25VF016)
    // initialize GFX3 SST25 flash SPI
    #define FlashInit(pInitData) SST25Init((DRV_SPI_INIT_DATA*)pInitData)
#elif defined (USE_MCHP25LC256)
    // initialize EEPROM on Explorer 16
    #define FlashInit(pInitData) MCHP25LC256Init((DRV_SPI_INIT_DATA*)pInitData)
#elif defined (USE_M25P80)
    #define FlashInit(pInitData) SST25Init((DRV_SPI_INIT_DATA*)pInitData)
#endif

/////////////////////////////////////////////////////////////////////////////
// SPI Channel settings
/////////////////////////////////////////////////////////////////////////////
#if defined SPI_CHANNEL_2_ENABLE || defined SPI_CHANNEL_1_ENABLE || defined SPI_CHANNEL_3_ENABLE || defined SPI_CHANNEL_4_ENABLE
    #if defined (USE_SST25VF016)
        #ifdef __PIC32MX
            const DRV_SPI_INIT_DATA SPI_Init_Data = {SST25_SPI_CHANNEL, 1, 0, 0, 1, 1, 0};
        #else
            const DRV_SPI_INIT_DATA SPI_Init_Data = {SST25_SPI_CHANNEL, 3, 6, 0, 1, 1, 0};
        #endif
    #elif defined (USE_MCHP25LC256)
        const DRV_SPI_INIT_DATA SPI_Init_Data = {MCHP25LC256_SPI_CHANNEL, 6, 3, 0, 1, 1, 0};
    #elif defined (USE_M25P80)
            const DRV_SPI_INIT_DATA SPI_Init_Data = {SST25_SPI_CHANNEL, 3, 6, 0, 1, 1, 0};
    #endif
#endif

#define WAIT_UNTIL_FINISH(x)    while(!x)
#define MIN(x,y)                ((x > y)? y: x)
#define DEMODELAY				1000

            // Variables for date and time
SCREEN_STATES   screenState = CREATE_MAINPAGE;
SCREEN_STATES   prevState = CREATE_MAINPAGE; // used to mark state where time setting was called
SCREEN_STATES   prevRefreshState = CREATE_MAINPAGE; // used to mark the start of the previous screen

COMPARTMENT_STATES   compartmentState = ERROR;

OBJ_HEADER      *pListSaved;
WORD    textWidth, textHeight, tempStrWidth;
XCHAR       DTPlusSym[] = {'+',0};
XCHAR           TimeStr[6];            // string variable for date and time display
XCHAR           AmpmStr[3];            // string variable for date and time display
XCHAR           YearStr[5];            // string variable for date and time display
XCHAR           MonthStr[5];            // string variable for date and time display
XCHAR           DateStr[3];            // string variable for date and time display
XCHAR           HourStr[3] = {'1','2',0};
XCHAR           MinStr[3] = {'5','5',0};
XCHAR           ColonStr[2] = {':',0};
XCHAR           Bell1Str[]={'H','E','L','L','O'};            // string variable for date and time display
XCHAR           Time[] = {'T','i','m','e',0};
XCHAR           Medicine[] = {'M','e','d','i','c','i','n','e',0};
XCHAR           Qty[] = {'Q','t','y',0};
XCHAR           Comp[] = {'C','o','m','p',0};
XCHAR           PrescripIdStr[5][10]= {
                                        {'P','r','e','s','c','r','p','1',0},            // string variable for date and time display
                                        {'P','r','e','s','c','r','p','2',0},
                                        {'P','r','e','s','c','r','p','3',0},
                                        {'P','r','e','s','c','r','p','4',0},
                                        {'P','r','e','s','c','r','p','5',0}
};
//XCHAR           PrescripIdStr[5][10]= {'P','r','e','s','c','r','p','1',0};            // string variable for date and time display
//XCHAR           PrescripId2Str[] = {'P','r','e','s','c','r','p','2',0};
//XCHAR           PrescripId3Str[] = {'P','r','e','s','c','r','p','3',0};
//XCHAR           PrescripId4Str[] = {'P','r','e','s','c','r','p','4',0};
//XCHAR           PrescripId5Str[] = {'P','r','e','s','c','r','p','5',0};
XCHAR           SettingsYearStr[]= {'Y','e','a','r',0};            // string variable for date and time display
XCHAR           SettingsMonthStr[] = {'M','o','n','t','h',0};
XCHAR           SettingsDateStr[] = {'D','a','t','e',0};
XCHAR           SettingsTimeStr[] = {'T','i','m','e',0};
XCHAR           SettingsAlarmStr[] = {'A','l','a','r','m',0};

XCHAR           strTimeR1[6] = {'-',0};
XCHAR           keyPadArgs[][9] = {
    {'P','R','E','S','C','R','I','P',0},
    {'T','I','M','E',0},
    {'M','E','D','I','C','I','N','E',0},
    {'Q','T','Y',0},
    {'C','O','M','P',0},
    {}

};
XCHAR           strMedicines[8][10]  = { {'?',0},{'?',0},{'?',0},{'?',0},{'?',0},{'?',0},{'?',0},{'?',0}};

#define ADDRESS_PRESCRIPTION_AVAILABLE 0x200
#define ADDRESS_PRESCRIPTION_START     0x50000
#define ADDRESS_MEDICINE_START         0xC0000

#define ADDRESS_MEDICINE_NAMES_1        2100
#define ADDRESS_MEDICINE_NAMES_2        2120
#define ADDRESS_MEDICINE_NAMES_3        2140
#define ADDRESS_MEDICINE_NAMES_4        2160
#define ADDRESS_MEDICINE_NAMES_5        2180
#define ADDRESS_MEDICINE_NAMES_6        2200
#define ADDRESS_MEDICINE_NAMES_7        2220
#define ADDRESS_MEDICINE_NAMES_8        2240

BYTE savePrescription = 0;
void savePrescriptionToFlash(int prescriptionID);
char loadPrescriptionToRam(int prescriptionID);
void loadMedicineNamesToRam();
void loadAlarmTriggers();

union uPRESCRIPTION{

    char Data[260];

    struct _PRESCRIPTION{

    XCHAR Name[10];
    XCHAR Times[5][6];
    XCHAR Medicines[5][11];
    XCHAR Qty[5][5];
    XCHAR Comp[5][2];

    }PRESCRIPTION;
};


union uPRESCRIPTION Prescriptions[6];

struct sTrigger{

    int time_hr;
    int time_min;
    int compartment;
};
struct sTrigger alarmTriggeringTimes[5][5];


//Prescription1.Name = {'M','E','D','I','C','I','N','E',0};

int keyPadArgID = 0;
int keyPadEditBoxMaxLength = 0;
DWORD keyPadOriginObjID = 0xFFFF;
DWORD prescriptionOriginObjID = 0xFFFF;

GOL_SCHEME  *altScheme; // declare the alternative
GOL_SCHEME  *timeScheme;
GOL_SCHEME  *ampmScheme;
GOL_SCHEME  *dateScheme;
GOL_SCHEME  *bellScheme;
GOL_SCHEME  *prescripScheme;
GOL_SCHEME  *btnScheme;

int targetCompartment = 0xFF;
int selectedPrescriptionID = 0xFF; // for UI handling
int currentPrescriptionID = 0;
int currentCompartment = 0xFF;
int selectButtonDraw = 0;

int longPress = 0;
DWORD   savedTick = 0;
DWORD   keyRepeatTick = 0;
WORD settingsPressedArrowBtnID = 0xFFFF;
int updateSettings = 0;
WORD currentKeyBtnID = 0xFFFF;
WORD prevKeyBtnID = 0xFFFF;
int updateKeyPad = 0;


int iYear = 0;
int iDate = 0;
int iMonth = 0;
int iAlarm = 0;
int iHour = 0;
int iMinute = 0;
// style scheme
int loopI = 0;
int loopJ = 0;
int loopK = 0;

char presStatus = 0;

int main(void){

    unsigned int x;

    GOL_MSG msg; // GOL message structure to
    // interact with GOL
    InitializeBoard();
    //TouchInit(); // Initialize touch screen
    //GOLInit(); // Initialize graphics library &
    // create default style scheme for GOL
    altScheme = GOLCreateScheme(); // Create alternative style
    timeScheme = GOLCreateScheme(); // Create alternative style
    ampmScheme = GOLCreateScheme(); // Create alternative style
    dateScheme = GOLCreateScheme(); // Create alternative style
    bellScheme = GOLCreateScheme(); // Create alternative style
    prescripScheme = GOLCreateScheme(); // Create alternative style
    // scheme
    altScheme->TextColor0 = WHITE; // set text color 0
    altScheme->TextColor1 = WHITE; // set text color 1
    altScheme->pFont = (void *) &GOLSmallFont;

    timeScheme->Color0 = BLACK;
    timeScheme->Color1 = BLACK;
    timeScheme->TextColor0 = GRAY230;
    timeScheme->TextColor1 = GRAY230;
    timeScheme->EmbossDkColor = BLACK;
    timeScheme->EmbossLtColor = BLACK;
    timeScheme->pFont = (void *) &Arial_Narrow_88;
    timeScheme->CommonBkColor = BLACK;

    ampmScheme->Color0 = BLACK;
    ampmScheme->Color1 = BLACK;
    ampmScheme->TextColor0 = GRAY230;
    ampmScheme->TextColor1 = GRAY230;
    ampmScheme->EmbossDkColor = BLACK;
    ampmScheme->EmbossLtColor = BLACK;
    ampmScheme->pFont = (void *) &Arial_Narrow_48;
    ampmScheme->CommonBkColor = BLACK;

    dateScheme->Color0 = BLACK;
    dateScheme->Color1 = BLACK;
    dateScheme->TextColor0 = GRAY230;
    dateScheme->TextColor1 = GRAY230;
    dateScheme->EmbossDkColor = BLACK;
    dateScheme->EmbossLtColor = BLACK;
    dateScheme->pFont = (void *) &Arial_24;
    dateScheme->CommonBkColor = BLACK;

    bellScheme->Color0 = BLACK;
    bellScheme->Color1 = BLACK;
    bellScheme->TextColor0 = GRAY230;
    bellScheme->TextColor1 = GRAY230;
    bellScheme->EmbossDkColor = BLACK;
    bellScheme->EmbossLtColor = BLACK;
    bellScheme->pFont = (void *) &NeoSans_12;
    bellScheme->CommonBkColor = BLACK;

    prescripScheme->Color0 = BLACK;
    prescripScheme->Color1 = BLACK;
    prescripScheme->TextColor0 = GRAY230;
    prescripScheme->TextColor1 = GRAY230;
    prescripScheme->EmbossDkColor = BLACK;
    prescripScheme->EmbossLtColor = BLACK;
    prescripScheme->pFont = (void *) &Arial_10;
    prescripScheme->CommonBkColor = BLACK;

//    btnScheme->Color0 = BLACK;
//    btnScheme->Color1 = BLACK;
//    btnScheme->TextColor0 = GRAY230;
//    btnScheme->TextColor1 = GRAY230;
//    btnScheme->EmbossDkColor = BLACK;
//    btnScheme->EmbossLtColor = BLACK;
//    //btnScheme->pFont = (void *) &NeoSans_12;
//    btnScheme->CommonBkColor = BLACK;

    screenState = CREATE_ALARMPAGE;
    prevState= CREATE_ALARMPAGE;
    prevRefreshState = CREATE_ALARMPAGE;
    for(loopK = 0; loopK < 6; loopK ++){

        for(loopI = 0; loopI < 10; loopI ++){

            Prescriptions[loopK].PRESCRIPTION.Name[loopI] = PrescripIdStr[loopK][loopI];


                for(loopJ = 0; loopJ < 5; loopJ ++){

                    if(loopI < 5)
                    Prescriptions[loopK].PRESCRIPTION.Times[loopJ][loopI] = strTimeR1[loopI];

                    Prescriptions[loopK].PRESCRIPTION.Medicines[loopJ][loopI]= strTimeR1[loopI];
                    if(loopI < 4)
                    Prescriptions[loopK].PRESCRIPTION.Qty[loopJ][loopI]= strTimeR1[loopI];
                    if(loopI < 2)
                    Prescriptions[loopK].PRESCRIPTION.Comp[loopJ][loopI]= strTimeR1[loopI];
             }

        }
    }


    for(loopI = 0; loopI < 5; loopI ++){

        presStatus = 0;
        presStatus = loadPrescriptionToRam(loopI);

        if(presStatus == 0)
           savePrescriptionToFlash(loopI);

    }

    Init_UART1(9600);
    //saveMedicineNamesToFlash();
    loadMedicineNamesToRam();
    loadAlarmTriggers();

    TimeStr[0]= '1';
    TimeStr[1]= '0';
    TimeStr[2]= ':';
    TimeStr[3]= '5';
    TimeStr[4]= '8';

    AmpmStr[0]='a';
    AmpmStr[1]='m';

    YearStr[0]='2';
    YearStr[1]='0';
    YearStr[2]='1';
    YearStr[3]='3';

    MonthStr[0]='J';
    MonthStr[1]='a';
    MonthStr[2]='n';

    DateStr[0]='2';
    DateStr[1]='2';


    while(1){

        if (GOLDraw()){ // Draw GOL object

            TouchGetMsg(&msg); // Get message from  touch screen

            GOLMsg(&msg); // Process message
        }
    }
}

void loadAlarmTriggers(){

    int i,j,k;
    XCHAR _hour[3];
    XCHAR _min[3];
    int temp1 = 0;
    int temp2 = 0;

    for(k = 0; k< 5; k++){

        for(j = 0; j < 5; j++){

                if(Prescriptions[k].PRESCRIPTION.Times[j][0] == 0x002D){

                    alarmTriggeringTimes[k][j].time_hr = 0xff;
                    alarmTriggeringTimes[k][j].time_min = 0xff;
                    alarmTriggeringTimes[k][j].compartment = 0xff;
                    
                 }else{

                    if(Prescriptions[k].PRESCRIPTION.Times[j][0] >= '0' && Prescriptions[k].PRESCRIPTION.Times[j][0] <= '9'
                    && Prescriptions[k].PRESCRIPTION.Times[j][1] >= '0' && Prescriptions[k].PRESCRIPTION.Times[j][1] <= '9' ){

                        temp1 = (Prescriptions[k].PRESCRIPTION.Times[j][0] - 0x30);
                        temp2 = (Prescriptions[k].PRESCRIPTION.Times[j][1] - 0x30);

                        alarmTriggeringTimes[k][j].time_hr = (temp1*10) + temp2;
                        temp1 = 0;
                        temp2 = 0;

                        temp1 = (Prescriptions[k].PRESCRIPTION.Times[j][3] - 0x30);
                        temp2 = (Prescriptions[k].PRESCRIPTION.Times[j][4] - 0x30);

                        alarmTriggeringTimes[k][j].time_min = (temp1*10) + temp2;

                        if(Prescriptions[k].PRESCRIPTION.Comp[j][0] != 0x002D){
                           alarmTriggeringTimes[k][j].compartment = (Prescriptions[k].PRESCRIPTION.Comp[j][0] - 0x30);
                        }else{
                            alarmTriggeringTimes[k][j].compartment = 0xff;
                        }


                    }else if(Prescriptions[k].PRESCRIPTION.Times[j][0] >= '0' && Prescriptions[k].PRESCRIPTION.Times[j][0] <= '9'
                        && Prescriptions[k].PRESCRIPTION.Times[j][1] == ':' ){

                        alarmTriggeringTimes[k][j].time_hr = (Prescriptions[k].PRESCRIPTION.Times[j][0] - 0x30);

                        temp1 = 0;
                        temp2 = 0;

                        temp1 = (Prescriptions[k].PRESCRIPTION.Times[j][2] - 0x30);
                        temp2 = (Prescriptions[k].PRESCRIPTION.Times[j][3] - 0x30);

                        alarmTriggeringTimes[k][j].time_min = (temp2*10) + temp2;

                        if(Prescriptions[k].PRESCRIPTION.Comp[j][0] != 0x002D){
                           alarmTriggeringTimes[k][j].compartment = (Prescriptions[k].PRESCRIPTION.Comp[j][0] - 0x30);
                        }else{
                            alarmTriggeringTimes[k][j].compartment = 0xff;
                        }
                    }
                 }
              
        }//for i
    }//for j

}

void savePrescriptionToFlash(int prescriptionID){

    int i =0;
    char temp = 0;
    char temp2 = 0;
    int tempAddress;

    if(prescriptionID >= 0 && prescriptionID <= 5){

        SST25SectorErase(ADDRESS_PRESCRIPTION_START + (prescriptionID * 0x10000) );//NVMErasePage((void *)(NVM_PROGRAM_PAGE + (prescriptionID * 0x1000)));

        SST25WriteByte(1,(ADDRESS_PRESCRIPTION_START + (prescriptionID * 0x10000) + 0x200));//NVMWriteWord((void*)(NVM_PROGRAM_PAGE + (prescriptionID * 0x1000)+ 0x200), 0x1);

        for(i =0 ; i< 260;i ++){

            tempAddress =  (ADDRESS_PRESCRIPTION_START + (prescriptionID * 0x10000) + i);
            temp = Prescriptions[prescriptionID].Data[i];
            SST25WriteByte(temp,tempAddress);               //NVMWriteWord((void*)(tempAddress), temp);

            temp2 = SST25ReadByte(tempAddress);             //temp2 = (*(int *)(tempAddress));
            Prescriptions[prescriptionID].Data[i] = temp2;
        }

    }

}

char loadPrescriptionToRam(int prescriptionID){

    int i =0;
    char status = 0;
    char temp = 0;
    int tempAddress =0;

    status =  SST25ReadByte((ADDRESS_PRESCRIPTION_START + (prescriptionID * 0x10000) + 0x200));//status = (*(int *)(NVM_PROGRAM_PAGE + (prescriptionID * 0x1000)+ 0x200));

    if(status == 0){

        return status;

    }else if(status == 1){

        for(i =0 ; i< 260;i ++){

            tempAddress =  (ADDRESS_PRESCRIPTION_START + (prescriptionID * 0x10000) + i);
            temp = SST25ReadByte(tempAddress);                                              //temp = (*(int *)(tempAddress));
            Prescriptions[prescriptionID].Data[i] = temp;
        }
        return status;
    }
  
}

void saveMedicineNamesToFlash(){

    int i =0;
    int j = 0;
    short temp = 0;
    short temp2 = 0;
    int address = 0;

    SST25SectorErase(ADDRESS_MEDICINE_START);
    SST25SectorErase(ADDRESS_MEDICINE_START + 0x10000);

     for(j = 0; j<8 ; j++){

        for(i =0 ; i< 10;i ++){

            address = 2*(i + j*10) + ADDRESS_MEDICINE_START;
            temp = strMedicines[j][i];
            SST25WriteWord(temp, address);
            temp2 = SST25ReadWord(address);
            strMedicines[j][i] = temp2;
        }

     }




}

void loadMedicineNamesToRam(){

    int i =0;
    int j = 0;

     for(j = 0; j<8 ; j++){

        for(i =0 ; i< 10; i++){

            strMedicines[j][i] = SST25ReadWord(ADDRESS_MEDICINE_START + 2*(i + j*10));
        }

     }

}
// Call back functions must be defined and return a value of 1
// even though they are not used
WORD GOLMsgCallback(WORD objMsg, OBJ_HEADER* pObj, GOL_MSG* pMsg){

    WORD objectID;
    SLIDER *pSldObj;
    OBJ_HEADER  *pOtherMenuBtn;

    MsgMenu(objMsg, pObj, pMsg);

     switch(screenState)
     {


         case DISPLAY_MAINPAGE:
             prevState = CREATE_MAINPAGE;
             break;

         case DISPLAY_PRESCRIPTIONPAGE:
             prevState = CREATE_PRESCRIPTIONPAGE;
             break;

         case DISPLAY_MEDICINEPAGE:
             prevState = CREATE_MEDICINEPAGE;
             break;

         case DISPLAY_SETTINGSPAGE:
              prevState = CREATE_SETTINGSPAGE;
              break;

         case DISPLAY_KEYPAGE:
              //prevState = CREATE_KEYPAGE;
              break;

         case DISPLAY_ALARMPAGE:
             prevState = CREATE_ALARMPAGE;
             break;

         default:
             prevState = screenState;    // save the current create state
             break;
    }
    switch(screenState)
    {
//        case DISPLAY_MAINPAGE:
//            return (MsgButtons(objMsg, pObj, pMsg));

        case DISPLAY_PRESCRIPTIONPAGE:
            return (MsgPrescriptionPage(objMsg, pObj, pMsg));

        case DISPLAY_MEDICINEPAGE:
            return (MsgMedicinePage(objMsg, pObj, pMsg));

        case DISPLAY_SETTINGSPAGE:
            return (MsgSettingsPage(objMsg, pObj, pMsg));

        case DISPLAY_KEYPAGE:
            return (MsgKeyPadPage(objMsg, pObj, pMsg));
//
//        case DISPLAY_ALARMPAGE:
//            return (MsgSlider(objMsg, pObj, pMsg));


        default:

            // process message by default
            return (1);
    }
    return 1;
}

WORD MsgMenu(WORD objMsg, OBJ_HEADER* pObj, GOL_MSG* pMsg){

    WORD objectID;
    SLIDER *pSldObj;
    OBJ_HEADER  *pOtherMenuBtn;

    objectID = GetObjID(pObj);

    if (objectID == ID_BTN1) {

        if (objMsg == BTN_MSG_PRESSED) {
            screenState = CREATE_MAINPAGE;
        }
    }

    if (objectID == ID_BTN2) {

        if (objMsg == BTN_MSG_PRESSED) {
            screenState = CREATE_PRESCRIPTIONPAGE;
        }

    }

    if (objectID == ID_BTN3) {

        if (objMsg == BTN_MSG_PRESSED) {
            screenState = CREATE_MEDICINEPAGE;
        }

    }
    if (objectID == ID_BTN4) {

        if (objMsg == BTN_MSG_PRESSED) {
            screenState = CREATE_SETTINGSPAGE;
        }

    }

    return 1;
}

WORD MsgPrescriptionPage(WORD objMsg, OBJ_HEADER* pObj, GOL_MSG* pMsg){

    WORD objectID;
    OBJ_HEADER  *pTargetBtn;
    static DWORD    prevTick = 0;
    DWORD    diffTick = 0;

    objectID = GetObjID(pObj);

    //need to detect a long press over a button, we use a help of a tick here
    //when button pressed value is registered
    //when released the difference between the tick value is taken
    //if this value is large enough, it means it was a long press
    if(objMsg == BTN_MSG_PRESSED) {

        if(objectID >= ID_PRESCRIP_BTN1 && objectID <= ID_PRESCRIP_BTN5)
        prevTick = tick;
        compartmentState = ERROR;
        longPress = 0; //reset the variable to detect a long press upon a button

    }

    if (objMsg == BTN_MSG_RELEASED) {

        if(objectID >= ID_PRESCRIP_BTN1 && objectID <= ID_PRESCRIP_BTN5)
            diffTick = tick - prevTick;

        if(diffTick > 20000){
            longPress = 1;
            compartmentState = OK;
            keyPadOriginObjID = objectID;
        }
     switch(objectID){

        case ID_PRESCRIP_BTN1:

            if(longPress == 1){
                prevState = CREATE_PRESCRIPTIONPAGE;
                screenState = CREATE_KEYPAGE;
                keyPadArgID = 0;
                keyPadEditBoxMaxLength = 10;
            }else{
                selectedPrescriptionID = 1;
                currentPrescriptionID = 0;
                screenState = CREATE_PRESCRIPTIONPAGE;
            }

            break;
        case ID_PRESCRIP_BTN2:

            if(longPress == 1){
                prevState = CREATE_PRESCRIPTIONPAGE;
                screenState = CREATE_KEYPAGE;
                keyPadArgID = 0;
                keyPadEditBoxMaxLength = 10;
            }else{
                selectedPrescriptionID = 2;
                currentPrescriptionID = 1;
                screenState = CREATE_PRESCRIPTIONPAGE;
            }

            break;
        case ID_PRESCRIP_BTN3:

            if(longPress == 1){
                prevState = CREATE_PRESCRIPTIONPAGE;
                screenState = CREATE_KEYPAGE;
                keyPadArgID = 0;
                keyPadEditBoxMaxLength = 10;
            }else{
                selectedPrescriptionID = 3;
                currentPrescriptionID = 2;
                screenState = CREATE_PRESCRIPTIONPAGE;
            }

            break;
        case ID_PRESCRIP_BTN4:

            if(longPress == 1){
                prevState = CREATE_PRESCRIPTIONPAGE;
                screenState = CREATE_KEYPAGE;
                keyPadArgID = 0;
                keyPadEditBoxMaxLength = 10;
            }else{
                selectedPrescriptionID = 4;
                currentPrescriptionID = 3;
                screenState = CREATE_PRESCRIPTIONPAGE;
            }

            break;
        case ID_PRESCRIP_BTN5:

            if(longPress == 1){
                prevState = CREATE_PRESCRIPTIONPAGE;
                screenState = CREATE_KEYPAGE;
                keyPadArgID = 0;
                keyPadEditBoxMaxLength = 10;
            }else{
                selectedPrescriptionID = 5;
                currentPrescriptionID = 4;
                screenState = CREATE_PRESCRIPTIONPAGE;
            }

            break;

    }
    }

     if (objMsg == ST_MSG_SELECTED) {

        if(objectID >= ID_PRESCRIP_C1_R1 && objectID <= ID_PRESCRIP_C4_R5){

            keyPadOriginObjID = objectID;
            prevState = CREATE_PRESCRIPTIONPAGE;
            screenState = CREATE_KEYPAGE;

            switch(objectID){

                case ID_PRESCRIP_C1_R1:
                case ID_PRESCRIP_C1_R2:
                case ID_PRESCRIP_C1_R3:
                case ID_PRESCRIP_C1_R4:
                case ID_PRESCRIP_C1_R5:
                    keyPadArgID = 1;
                    keyPadEditBoxMaxLength = 5;
                    break;
                case ID_PRESCRIP_C2_R1:
                case ID_PRESCRIP_C2_R2:
                case ID_PRESCRIP_C2_R3:
                case ID_PRESCRIP_C2_R4:
                case ID_PRESCRIP_C2_R5:
                    keyPadArgID = 2;
                    keyPadEditBoxMaxLength = 10;
                    break;
                case ID_PRESCRIP_C3_R1:
                case ID_PRESCRIP_C3_R2:
                case ID_PRESCRIP_C3_R3:
                case ID_PRESCRIP_C3_R4:
                case ID_PRESCRIP_C3_R5:
                    keyPadArgID = 3;
                    keyPadEditBoxMaxLength = 4;
                    break;
                case ID_PRESCRIP_C4_R1:
                case ID_PRESCRIP_C4_R2:
                case ID_PRESCRIP_C4_R3:
                case ID_PRESCRIP_C4_R4:
                case ID_PRESCRIP_C4_R5:
                    keyPadArgID = 4;
                    keyPadEditBoxMaxLength = 1;
                    break;

                default:
                return 1;

         }



     }
    return 1;
     }
}

WORD MsgMedicinePage(WORD objMsg, OBJ_HEADER* pObj, GOL_MSG* pMsg){

    WORD objectID;
    OBJ_HEADER  *pTargetBtn;
    static DWORD    prevTick = 0;
    DWORD    diffTick = 0;

    objectID = GetObjID(pObj);

    //need to detect a long press over a button, we use a help of a tick here
    //when button pressed value is registered
    //when released the difference between the tick value is taken
    //if this value is large enough, it means it was a long press
    if(objMsg == BTN_MSG_PRESSED) {

        if(objectID >= ID_MEDICINE_BTN1 && objectID <= ID_MEDICINE_BTN8)
        prevTick = tick;
        compartmentState = ERROR;
        longPress = 0; //reset the variable to detect a long press upon a button
    }

    if (objMsg == BTN_MSG_RELEASED) {

        if(objectID >= ID_MEDICINE_BTN1 && objectID <= ID_MEDICINE_BTN8)
            diffTick = tick - prevTick;

        if(diffTick > 20000){
            longPress = 1;
            compartmentState = OK;
            keyPadOriginObjID = objectID;
        }
     switch(objectID){

        case ID_MEDICINE_BTN1:
            if(longPress == 1){
                prevState = CREATE_MEDICINEPAGE;
                screenState = CREATE_KEYPAGE;
                keyPadArgID = 2;
                keyPadEditBoxMaxLength = 10;
            }else{
                targetCompartment = 1;
                screenState = CREATE_MEDICINEPAGE;
            }
            break;
        case ID_MEDICINE_BTN2:
            if(longPress == 1){
                prevState = CREATE_MEDICINEPAGE;
                screenState = CREATE_KEYPAGE;
                keyPadArgID = 2;
                keyPadEditBoxMaxLength = 10;
            }else{
                targetCompartment = 2;
                screenState = CREATE_MEDICINEPAGE;
            }
            break;
        case ID_MEDICINE_BTN3:
            if(longPress == 1){
                prevState = CREATE_MEDICINEPAGE;
                screenState = CREATE_KEYPAGE;
                keyPadArgID = 2;
                keyPadEditBoxMaxLength = 10;
            }else{
                targetCompartment = 3;
                screenState = CREATE_MEDICINEPAGE;
            }
            break;
        case ID_MEDICINE_BTN4:
            if(longPress == 1){
                prevState = CREATE_MEDICINEPAGE;
                screenState = CREATE_KEYPAGE;
                keyPadArgID = 2;
                keyPadEditBoxMaxLength = 10;
            }else{
                targetCompartment = 4;
                screenState = CREATE_MEDICINEPAGE;
            }
            break;
        case ID_MEDICINE_BTN5:
            if(longPress == 1){
                prevState = CREATE_MEDICINEPAGE;
                screenState = CREATE_KEYPAGE;
                keyPadArgID = 2;
                keyPadEditBoxMaxLength = 10;
            }else{
                targetCompartment = 5;
                screenState = CREATE_MEDICINEPAGE;
            }
            break;
        case ID_MEDICINE_BTN6:
            if(longPress == 1){
                prevState = CREATE_MEDICINEPAGE;
                screenState = CREATE_KEYPAGE;
                keyPadArgID = 2;
                keyPadEditBoxMaxLength = 10;
            }else{
                targetCompartment = 6;
                screenState = CREATE_MEDICINEPAGE;
            }
            break;
        case ID_MEDICINE_BTN7:
            if(longPress == 1){
                prevState = CREATE_MEDICINEPAGE;
                screenState = CREATE_KEYPAGE;
                keyPadArgID = 2;
                keyPadEditBoxMaxLength = 10;
            }else{
                targetCompartment = 7;
                screenState = CREATE_MEDICINEPAGE;
            }
            break;
        case ID_MEDICINE_BTN8:
            if(longPress == 1){
                prevState = CREATE_MEDICINEPAGE;
                screenState = CREATE_KEYPAGE;
                keyPadArgID = 2;
                keyPadEditBoxMaxLength = 10;
            }else{
                targetCompartment = 8;
                screenState = CREATE_MEDICINEPAGE;
            }
            break;
        default:
            return 1;
    }
    }

    return 1;
}

// Months Items list
const XCHAR MonthItems[] = {'J','a','n',0x000A,
    'F','e','b',0x000A,
    'M','a','r',0x000A,
    'A','p','r',0x000A,
    'M','a','y',0x000A,
    'J','u','n',0x000A,
    'J','u','l',0x000A,
    'A','u','g',0x000A,
    'S','e','p',0x000A,
    'O','c','t',0x000A,
    'N','o','v',0x000A,
    'D','e','c',0x0000};

// Days Items list
const XCHAR YearItems[] = {'2','0','0','0',0x000A,'2','0','0','1',0x000A,'2','0', '0','2',0x000A,'2','0', '0','3',0x000A,'2','0', '0','4',0x000A,'2','0', '0','5',0x000A,
    '2','0','0','6',0x000A,'2','0','0','7',0x000A, '2','0','0','8',0x000A, '2','0','0','9',0x000A, '2','0','1','0',0x000A,
    '2','0','1','1',0x000A, '2','0','1','2',0x000A, '2','0','1','3',0x000A, '2','0','1','4',0x000A, '2','0','1','5',0x000A,
    '2','0','1','6',0x000A, '2','0','1','7',0x000A, '2','0','1','8',0x000A, '2','0','1','9',0x000A, '2','0','2','0',0x000A,
    '2','0','2','1',0x000A, '2','0','2','2',0x000A, '2','0','2','3',0x000A, '2','0','2','4',0x000A, '2','0','2','5',0x000A,
    '2','0','2','6',0x000A, '2','0','2','7',0x000A, '2','0','2','8',0x000A, '2','0','2','9',0x000A, '2','0','3','0',0x000A, '2','0','3','1',0x0000};

// Year Items list
const XCHAR DayItems[] = {'0','0',0x000A, '0','1',0x000A, '0','2',0x000A, '0','3',0x000A, '0','4',0x000A,
    '0','5',0x000A, '0','6',0x000A, '0','7',0x000A, '0','8',0x000A, '0','9',0x000A,
    '1','0',0x000A, '1','1',0x000A, '1','2',0x000A, '1','3',0x000A, '1','4',0x000A,
    '1','5',0x000A, '1','6',0x000A, '1','7',0x000A, '1','8',0x000A, '1','9',0x000A, '2','0',0x000A, '2','1',0x000A, '2','2',0x000A, '2','3',0x000A, '2','4',0x000A,
     '2','5',0x000A, '2','6',0x000A, '2','7',0x000A, '2','8',0x000A, '2','9',0x000A, '3','0',0x000A, '3','1',0x0000};

const XCHAR AlarmItems[] = {'O','F','F',0x000A,' ','O','N',0x0000};

XCHAR EmptyField[] = {'-',0x0000};

WORD MsgSettingsPage(WORD objMsg, OBJ_HEADER* pObj, GOL_MSG* pMsg){

    WORD objectID;
    OBJ_HEADER  *pTargetBtn;
    XCHAR buffer[3]={0,0,0};
    int i = 0;
    objectID = GetObjID(pObj);


    if(objMsg == BTN_MSG_PRESSED) {


        if(objectID >= ID_SETTINGS_YEAR_UP && objectID <= ID_SETTINGS_ALRM_DOWN){
            settingsPressedArrowBtnID = objectID;
            savedTick = tick;
            updateSettings = 1;
        }
        switch(objectID){

            case ID_SETTINGS_YEAR_UP:
                    //BtnSetBitmap(pObj, (void *)&uparrow_button_p);
                if(iYear < 31){
                    iYear++;
                }else{
                    iYear = 30;
                }
                pObj = GOLFindObject(ID_SETTINGS_YEAR_VALUE);
                EbSetText((EDITBOX *)pObj, (XCHAR *)&YearItems[(iYear*5)]);
                SetState(pObj, EB_DRAW);
                    return 1;
            case ID_SETTINGS_YEAR_DOWN:

                if(iYear > 0){
                    iYear--;
                }else{
                    iYear = 0;
                }
                pObj = GOLFindObject(ID_SETTINGS_YEAR_VALUE);
                EbSetText((EDITBOX *)pObj, (XCHAR *)&YearItems[(iYear*5)]);
                SetState(pObj, EB_DRAW);
                    return 1;
            case ID_SETTINGS_MNTH_UP:

                if(iMonth < 12){
                    iMonth++;
                }else{
                    iMonth = 11;
                }
                pObj = GOLFindObject(ID_SETTINGS_MNTH_VALUE);
                EbSetText((EDITBOX *)pObj, (XCHAR *)&MonthItems[(iMonth*4)]);
                SetState(pObj, EB_DRAW);
                    return 1;
            case ID_SETTINGS_MNTH_DOWN:
                if(iMonth > 0){
                    iMonth--;
                }else{
                    iMonth = 0;
                }
                pObj = GOLFindObject(ID_SETTINGS_MNTH_VALUE);
                EbSetText((EDITBOX *)pObj, (XCHAR *)&MonthItems[(iMonth*4)]);
                SetState(pObj, EB_DRAW);
                    return 1;
            case ID_SETTINGS_DATE_UP:
                if(iDate < 31){
                    iDate++;
                }else{
                    iDate = 31;
                }
                pObj = GOLFindObject(ID_SETTINGS_DATE_VALUE);
                EbSetText((EDITBOX *)pObj, (XCHAR *)&DayItems[(iDate*3)]);
                SetState(pObj, EB_DRAW);
                    return 1;
            case ID_SETTINGS_DATE_DOWN:

                   if(iDate > 0){
                    iDate--;
                }else{
                    iDate = 0;
                }
                pObj = GOLFindObject(ID_SETTINGS_DATE_VALUE);
                EbSetText((EDITBOX *)pObj, (XCHAR *)&DayItems[(iDate*3)]);
                SetState(pObj, EB_DRAW);
                    return 1;
            case ID_SETTINGS_TIME_HR_UP:
                if(iHour < 23){
                    iHour++;
                }else{
                    iHour = 23;
                }
                pObj = GOLFindObject(ID_SETTINGS_TIME_HR_VALUE);
                EbSetText((EDITBOX *)pObj, xItoA(buffer,iHour,10));
                SetState(pObj, EB_DRAW);
                    return 1;
            case ID_SETTINGS_TIME_HR_DOWN:
                 if(iHour > 0){
                    iHour--;
                }else{
                    iHour = 0;
                }
                pObj = GOLFindObject(ID_SETTINGS_TIME_HR_VALUE);
                EbSetText((EDITBOX *)pObj, xItoA(buffer,iHour,10));
                SetState(pObj, EB_DRAW);
                    return 1;
            case ID_SETTINGS_TIME_MN_UP:
                if(iMinute < 59){
                    iMinute++;
                }else{
                    iMinute = 23;
                }
                pObj = GOLFindObject(ID_SETTINGS_TIME_MN_VALUE);
                EbSetText((EDITBOX *)pObj, xItoA(buffer,iMinute,10));
                SetState(pObj, EB_DRAW);
                    return 1;
            case ID_SETTINGS_TIME_MN_DOWN:
                if(iMinute > 0){
                    iMinute--;
                }else{
                    iMinute = 0;
                }
                pObj = GOLFindObject(ID_SETTINGS_TIME_MN_VALUE);
                EbSetText((EDITBOX *)pObj, xItoA(buffer,iMinute,10));
                SetState(pObj, EB_DRAW);
                    return 1;
            case ID_SETTINGS_ALRM_UP:
                iAlarm = 1;
                pObj = GOLFindObject(ID_SETTINGS_ALRM_VALUE);
                EbSetText((EDITBOX *)pObj, (XCHAR *)&AlarmItems[(iAlarm*4)]);
                SetState(pObj, EB_DRAW);
                    return 1;
            case ID_SETTINGS_ALRM_DOWN:
                iAlarm = 0;
                pObj = GOLFindObject(ID_SETTINGS_ALRM_VALUE);
                EbSetText((EDITBOX *)pObj, (XCHAR *)&AlarmItems[(iAlarm*4)]);
                SetState(pObj, EB_DRAW);
                    return 1;
            default:
                return 1;
    }
    }

    if(objMsg == BTN_MSG_RELEASED) {


        switch(objectID){

            case ID_SETTINGS_YEAR_UP:
            case ID_SETTINGS_YEAR_DOWN:

                       mRTCCOff();
                       RTCCSetBinYear(iYear);
                       mRTCCSet();
                       return(1);

            case ID_SETTINGS_MNTH_UP:
            case ID_SETTINGS_MNTH_DOWN:

                       mRTCCOff();
                       RTCCSetBinMonth(iMonth + 1);
                       mRTCCSet();
                       return(1);

            case ID_SETTINGS_DATE_UP:
            case ID_SETTINGS_DATE_DOWN:

                       mRTCCOff();
                       RTCCSetBinDay(iDate);
                       mRTCCSet();
                       return(1);

            case ID_SETTINGS_TIME_HR_UP:
            case ID_SETTINGS_TIME_HR_DOWN:

                       mRTCCOff();
                       RTCCSetBinHour(iHour);
                       mRTCCSet();
                       return(1);


            case ID_SETTINGS_TIME_MN_UP:
            case ID_SETTINGS_TIME_MN_DOWN:
                
                       mRTCCOff();
                       RTCCSetBinMin(iMinute);
                       mRTCCSet();
                       return(1);

            case ID_SETTINGS_ALRM_UP:
                    
                    return 1;
            case ID_SETTINGS_ALRM_DOWN:
                    
                    return 1;
            default:
                return 1;
    }
    }

    return 1;
}

WORD MsgKeyPadPage(WORD objMsg, OBJ_HEADER* pObj, GOL_MSG* pMsg){

    WORD objectID;
    OBJ_HEADER  *pTargetBtn;
    EDITBOX     *pEb;
    XCHAR buffer[3]={0,0,0};
    int i = 0;
    objectID = GetObjID(pObj);
    static int keyState;
    XCHAR *Array;

    if(objMsg == BTN_MSG_PRESSED) {

        if((tick - savedTick < 20000) && prevKeyBtnID == objectID){

            keyState++;
        }else{
            keyState = 0;
        }

        if(objectID >= ID_KEYPAD_1 && objectID <= ID_KEYPAD_VARIABLE){
            
            currentKeyBtnID = objectID;
            prevKeyBtnID = objectID;
            savedTick = tick;
            updateKeyPad = 1;

        }


        pEb = (EDITBOX *)GOLFindObject(ID_KEYPAD_EDITBOX);
        switch(objectID){

            case ID_KEYPAD_1:

                EbAddChar(pEb, '1');
                SetState(pEb, EB_DRAW);
                return 1;

            case ID_KEYPAD_2ABC:

                if(keyState  > 0){
                   EbDeleteChar(pEb); 
                }
                switch(keyState % 4){

                    case 0:EbAddChar(pEb, '2');break;
                    case 1:EbAddChar(pEb, 'a');break;
                    case 2:EbAddChar(pEb, 'b');break;
                    case 3:EbAddChar(pEb, 'c');break;
                }

                SetState(pEb, EB_DRAW);
                return 1;

            case ID_KEYPAD_3DEF:

                if(keyState  > 0){
                   EbDeleteChar(pEb);
                }
                switch(keyState % 4){

                    case 0:EbAddChar(pEb, '3');break;
                    case 1:EbAddChar(pEb, 'd');break;
                    case 2:EbAddChar(pEb, 'e');break;
                    case 3:EbAddChar(pEb, 'f');break;
                }

                SetState(pEb, EB_DRAW);
                return 1;
            case ID_KEYPAD_4GHI:

                if(keyState  > 0){
                   EbDeleteChar(pEb);
                }
                switch(keyState % 4){

                    case 0:EbAddChar(pEb, '4');break;
                    case 1:EbAddChar(pEb, 'g');break;
                    case 2:EbAddChar(pEb, 'h');break;
                    case 3:EbAddChar(pEb, 'i');break;
                }

                SetState(pEb, EB_DRAW);
                return 1;
            case ID_KEYPAD_5JKL:

                if(keyState  > 0){
                   EbDeleteChar(pEb);
                }
                switch(keyState % 4){

                    case 0:EbAddChar(pEb, '5');break;
                    case 1:EbAddChar(pEb, 'j');break;
                    case 2:EbAddChar(pEb, 'k');break;
                    case 3:EbAddChar(pEb, 'l');break;
                }

                SetState(pEb, EB_DRAW);
                    return 1;
            case ID_KEYPAD_6MNO:

                if(keyState  > 0){
                   EbDeleteChar(pEb);
                }
                switch(keyState % 4){

                    case 0:EbAddChar(pEb, '6');break;
                    case 1:EbAddChar(pEb, 'm');break;
                    case 2:EbAddChar(pEb, 'n');break;
                    case 3:EbAddChar(pEb, 'o');break;
                }

                SetState(pEb, EB_DRAW);
                    return 1;
            case ID_KEYPAD_7PQRS:

                if(keyState  > 0){
                   EbDeleteChar(pEb);
                }
                switch(keyState % 5){

                    case 0:EbAddChar(pEb, '7');break;
                    case 1:EbAddChar(pEb, 'p');break;
                    case 2:EbAddChar(pEb, 'q');break;
                    case 3:EbAddChar(pEb, 'r');break;
                    case 4:EbAddChar(pEb, 's');break;
                }

                SetState(pEb, EB_DRAW);
                return 1;
            case ID_KEYPAD_8TUV:

                if(keyState  > 0){
                   EbDeleteChar(pEb);
                }
                switch(keyState % 4){

                    case 0:EbAddChar(pEb, '8');break;
                    case 1:EbAddChar(pEb, 't');break;
                    case 2:EbAddChar(pEb, 'u');break;
                    case 3:EbAddChar(pEb, 'v');break;
                }

                SetState(pEb, EB_DRAW);
                return 1;
            case ID_KEYPAD_9WXYZ:

                if(keyState  > 0){
                   EbDeleteChar(pEb);
                }
                switch(keyState % 5){

                    case 0:EbAddChar(pEb, '9');break;
                    case 1:EbAddChar(pEb, 'w');break;
                    case 2:EbAddChar(pEb, 'x');break;
                    case 3:EbAddChar(pEb, 'y');break;
                    case 4:EbAddChar(pEb, 'z');break;
                }

                SetState(pEb, EB_DRAW);
                return 1;
            case ID_KEYPAD_0SP:

                if(keyState  > 0){
                   EbDeleteChar(pEb);
                }
                switch(keyState % 2){

                    case 0:EbAddChar(pEb, '0');break;
                    case 1:EbAddChar(pEb, ' ');break;

                }

                SetState(pEb, EB_DRAW);
                return 1;
            case ID_KEYPAD_OK:


                    Array = EbGetText(pEb);
                    
                    switch(keyPadOriginObjID){

                        case ID_PRESCRIP_BTN1:
                            for(i = 0; i < 10; i++){
                             Prescriptions[0].PRESCRIPTION.Name[i] = *(Array + i);
                            }
                            savePrescriptionToFlash(0);
                            break;

                        case ID_PRESCRIP_BTN2:
                            for(i = 0; i < 10; i++){
                             Prescriptions[1].PRESCRIPTION.Name[i] = *(Array + i);
                            }
                            savePrescriptionToFlash(1);
                            break;
                        case ID_PRESCRIP_BTN3:
                            for(i = 0; i < 10; i++){
                             Prescriptions[2].PRESCRIPTION.Name[i] = *(Array + i);
                            }
                            savePrescriptionToFlash(2);
                            break;
                        case ID_PRESCRIP_BTN4:
                            for(i = 0; i < 10; i++){
                             Prescriptions[3].PRESCRIPTION.Name[i] = *(Array + i);
                            }
                            savePrescriptionToFlash(3);
                            break;
                        case ID_PRESCRIP_BTN5:
                            for(i = 0; i < 10; i++){
                             Prescriptions[4].PRESCRIPTION.Name[i] = *(Array + i);
                            }
                            savePrescriptionToFlash(4);
                            break;

                        case ID_PRESCRIP_C1_R1:
                            for(i = 0; i < 5; i++){
                             Prescriptions[currentPrescriptionID].PRESCRIPTION.Times[0][i] = *(Array + i);
                            }
                            break;
                         case ID_PRESCRIP_C1_R2:
                            for(i = 0; i < 5; i++){
                             Prescriptions[currentPrescriptionID].PRESCRIPTION.Times[1][i] = *(Array + i);
                            }
                            break;
                        case ID_PRESCRIP_C1_R3:
                            for(i = 0; i < 5; i++){
                             Prescriptions[currentPrescriptionID].PRESCRIPTION.Times[2][i] = *(Array + i);
                            }
                            break;
                        case ID_PRESCRIP_C1_R4:
                            for(i = 0; i < 5; i++){
                             Prescriptions[currentPrescriptionID].PRESCRIPTION.Times[3][i] = *(Array + i);
                            }
                            break;
                        case ID_PRESCRIP_C1_R5:
                            for(i = 0; i < 5; i++){
                             Prescriptions[currentPrescriptionID].PRESCRIPTION.Times[4][i] = *(Array + i);
                            }
                            break;

                        case ID_PRESCRIP_C2_R1:
                            for(i = 0; i < 10; i++){
                             Prescriptions[currentPrescriptionID].PRESCRIPTION.Medicines[0][i] = *(Array + i);
                            }
                            break;
                         case ID_PRESCRIP_C2_R2:
                            for(i = 0; i < 10; i++){
                             Prescriptions[currentPrescriptionID].PRESCRIPTION.Medicines[1][i] = *(Array + i);
                            }
                            break;
                        case ID_PRESCRIP_C2_R3:
                            for(i = 0; i < 10; i++){
                             Prescriptions[currentPrescriptionID].PRESCRIPTION.Medicines[2][i] = *(Array + i);
                            }
                            break;
                        case ID_PRESCRIP_C2_R4:
                            for(i = 0; i < 10; i++){
                             Prescriptions[currentPrescriptionID].PRESCRIPTION.Medicines[3][i] = *(Array + i);
                            }
                            break;
                        case ID_PRESCRIP_C2_R5:
                            for(i = 0; i < 10; i++){
                             Prescriptions[currentPrescriptionID].PRESCRIPTION.Medicines[4][i] = *(Array + i);
                            }
                            break;

                        case ID_PRESCRIP_C3_R1:
                            for(i = 0; i < 4; i++){
                             Prescriptions[currentPrescriptionID].PRESCRIPTION.Qty[0][i] = *(Array + i);
                            }
                            break;
                         case ID_PRESCRIP_C3_R2:
                            for(i = 0; i < 5; i++){
                             Prescriptions[currentPrescriptionID].PRESCRIPTION.Qty[1][i] = *(Array + i);
                            }
                            break;
                        case ID_PRESCRIP_C3_R3:
                            for(i = 0; i < 5; i++){
                             Prescriptions[currentPrescriptionID].PRESCRIPTION.Qty[2][i] = *(Array + i);
                            }
                            break;
                        case ID_PRESCRIP_C3_R4:
                            for(i = 0; i < 5; i++){
                             Prescriptions[currentPrescriptionID].PRESCRIPTION.Qty[3][i] = *(Array + i);
                            }
                            break;
                        case ID_PRESCRIP_C3_R5:
                            for(i = 0; i < 5; i++){
                             Prescriptions[currentPrescriptionID].PRESCRIPTION.Qty[4][i] = *(Array + i);
                            }
                            break;

                        case ID_PRESCRIP_C4_R1:
                            for(i = 0; i < 2; i++){
                             Prescriptions[currentPrescriptionID].PRESCRIPTION.Comp[0][i] = *(Array + i);
                            }
                            break;
                         case ID_PRESCRIP_C4_R2:
                            for(i = 0; i < 2; i++){
                             Prescriptions[currentPrescriptionID].PRESCRIPTION.Comp[1][i] = *(Array + i);
                            }
                            break;
                        case ID_PRESCRIP_C4_R3:
                            for(i = 0; i < 2; i++){
                             Prescriptions[currentPrescriptionID].PRESCRIPTION.Comp[2][i] = *(Array + i);
                            }
                            break;
                        case ID_PRESCRIP_C4_R4:
                            for(i = 0; i < 2; i++){
                             Prescriptions[currentPrescriptionID].PRESCRIPTION.Comp[3][i] = *(Array + i);
                            }
                            break;
                        case ID_PRESCRIP_C4_R5:
                            for(i = 0; i < 2; i++){
                             Prescriptions[currentPrescriptionID].PRESCRIPTION.Comp[4][i] = *(Array + i);
                            }
                            break;

                        case ID_MEDICINE_BTN1: 
                            for(i = 0; i < 10; i++){
                             strMedicines[0][i] = *(Array + i);
                            }
                            
                            break;
                        case ID_MEDICINE_BTN2:
                          
                            for(i = 0; i < 10; i++){
                             strMedicines[1][i] = *(Array + i);
                            }
                            
                            break;
                        case ID_MEDICINE_BTN3:
                            for(i = 0; i < 10; i++){
                             strMedicines[2][i] = *(Array + i);
                            }
                            
                            break;
                        case ID_MEDICINE_BTN4:
                            for(i = 0; i < 10; i++){
                             strMedicines[3][i] = *(Array + i);
                            }
                            
                            break;
                        case ID_MEDICINE_BTN5:
                            for(i = 0; i < 10; i++){
                             strMedicines[4][i] = *(Array + i);
                            }
                            
                            break;
                        case ID_MEDICINE_BTN6:
                            for(i = 0; i < 10; i++){
                             strMedicines[5][i] = *(Array + i);
                            }
                            
                            break;
                        case ID_MEDICINE_BTN7:
                            for(i = 0; i < 10; i++){
                             strMedicines[6][i] = *(Array + i);
                            }
                            
                            break;
                        case ID_MEDICINE_BTN8:
                            for(i = 0; i < 10; i++){
                             strMedicines[7][i] = *(Array + i);
                            }
                            
                            break;
                        default: return (1);
                    }

                    if(keyPadOriginObjID >= ID_MEDICINE_BTN1 && keyPadOriginObjID <= ID_MEDICINE_BTN8 ){

                        saveMedicineNamesToFlash();
                        loadMedicineNamesToRam();


                    }
                    if(keyPadOriginObjID >= ID_PRESCRIP_C1_R1 && keyPadOriginObjID <= ID_PRESCRIP_C4_R5 ){

                        savePrescriptionToFlash(currentPrescriptionID);
                        loadPrescriptionToRam(currentPrescriptionID);
                    }
                    return 1;
            case ID_KEYPAD_CANCEL:

                
                    return 1;
            case ID_KEYPAD_DEL:

                EbDeleteChar(pEb);
                SetState(pEb, EB_DRAW);
                return 1;
                    
            case ID_KEYPAD_COLON:

                if(keyState  > 0){
                   EbDeleteChar(pEb);
                }
                switch(keyState % 2){

                    case 0:EbAddChar(pEb, '.');break;
                    case 1:EbAddChar(pEb, ':');break;

                }
                SetState(pEb, EB_DRAW);
                return 1;

            default:
                return 1;
    }
    }

   return 1;
}

WORD GOLDrawCallback(){

    static DWORD    prevTick = 0;                           // keeps previous value of tick
    static BYTE     direction = 1;                          // direction switch for progress bar
    static BYTE     arrowPos = 0;                           // arrows pictures position for custom control demo
    static WORD     wDelay = 40;                           // progress bar delay variable
    OBJ_HEADER      *pObj = NULL;                           // used to change text in Window
    SLIDER          *pSld;                                  // used when updating date and time
    LISTBOX         *pLb;                                   // used when updating date and time
    OBJ_HEADER  *pOtherMenuBtn;
    OBJ_HEADER  *pTargetBtn;
    OBJ_HEADER  *pOtherBtn;
    OBJ_HEADER  *pSt;
    int i = 0;
    static XCHAR prevMin = 0;
    static XCHAR prevHour = 0;
    short unsigned int sYear[5] = {'2','2','2','2',0};
    XCHAR  sMonthStr[] = {'M','o','n','t','h',0};
    static DWORD    prevTime = 0;
    static DWORD    prevColon = 0;
    static int c = 0;

    if(screenState == CREATE_MAINPAGE || screenState == DISPLAY_MAINPAGE ){

        if((tick - prevTime) > 2000)
	        {
	            RTCCProcessEvents();                            // update the date and time string variabes
	            i = 0;

	            while(i < 12)
	            {
	                dateTimeStr[i] = _time_str[i];
	                dateTimeStr[i + 13] = _date_str[i];
	                i++;
	            }

                   iHour = mRTCCGetBinHour();
                   iMinute = mRTCCGetBinMin();
                   iYear  = mRTCCGetBinYear();
                   iDate  = mRTCCGetBinDay();
                   iMonth = mRTCCGetBinMonth() - 1;

                    if(iHour >= 12){

                        if(dateTimeStr[4] == '1' && dateTimeStr[5] == '3'){
                            HourStr[0] = '0';
                            HourStr[1] = '1';
                        }else if(dateTimeStr[4] == '1' && dateTimeStr[5] == '4'){
                            HourStr[0] = '0';
                            HourStr[1] = '2';
                        }else if(dateTimeStr[4] == '1' && dateTimeStr[5] == '2'){
                            HourStr[0] = '1';
                            HourStr[1] = '2';
                        }else if(dateTimeStr[4] == '1' && dateTimeStr[5] == '5'){
                            HourStr[0] = '0';
                            HourStr[1] = '3';

                        }else if(dateTimeStr[4] == '1' && dateTimeStr[5] == '6'){
                            HourStr[0] = '0';
                            HourStr[1] = '4';

                        }else if(dateTimeStr[4] == '1' && dateTimeStr[5] == '7'){
                            HourStr[0] = '0';
                            HourStr[1] = '5';

                        }else if(dateTimeStr[4] == '1' && dateTimeStr[5] == '8'){
                            HourStr[0] = '0';
                            HourStr[1] = '6';

                        }else if(dateTimeStr[4] == '1' && dateTimeStr[5] == '9'){
                            HourStr[0] = '0';
                            HourStr[1] = '7';

                        }else if(dateTimeStr[4] == '2' && dateTimeStr[5] == '0'){
                            HourStr[0] = '0';
                            HourStr[1] = '8';

                        }else if(dateTimeStr[4] == '2' && dateTimeStr[5] == '1'){
                            HourStr[0] = '0';
                            HourStr[1] = '9';

                        }else if(dateTimeStr[4] == '2' && dateTimeStr[5] == '2'){
                            HourStr[0] = '1';
                            HourStr[1] = '0';

                        }else if(dateTimeStr[4] == '2' && dateTimeStr[5] == '3'){
                            HourStr[0] = '1';
                            HourStr[1] = '1';

                        }
                           AmpmStr[0]='p';

                    }else if(iHour == 0){
                            HourStr[0] = '1';
                            HourStr[1] = '2';
                            AmpmStr[0]='a';
                    }else{
                        HourStr[0] = dateTimeStr[4];
                        HourStr[1] = dateTimeStr[5];
                        AmpmStr[0]='a';

                    }

                    HourStr[2] = 0;

                    MinStr[0] = dateTimeStr[7];
                    MinStr[1] = dateTimeStr[8];
                    MinStr[2] = 0;

                    if(prevMin != MinStr[1] ){

                        updateMin = 1;
                        prevMin = MinStr[1];
                    }else{

                        updateMin = 0;
                    }
                    if(prevHour != HourStr[1] ){

                        updateTime = 1;
                        prevHour = HourStr[1];
                    }else{

                        updateTime = 0;
                    }

                    
                    MonthStr[0] = dateTimeStr[13];
                    MonthStr[1] = dateTimeStr[14];
                    MonthStr[2] = dateTimeStr[15];
                    MonthStr[3] = 0;
                    
                    DateStr[0] = dateTimeStr[17];
                    DateStr[1] = dateTimeStr[18];
                    DateStr[2] = 0;

                    YearStr[0] = dateTimeStr[21];
                    YearStr[1] = dateTimeStr[22];
                    YearStr[2] = dateTimeStr[23];
                    YearStr[3] = dateTimeStr[24]; 
                    YearStr[4] = 0;

	            prevTime = tick;                                // reset tick timer
                    c++;
                    if(c > 10){

                        ColonStr[1] = 0;

                        if(ColonStr[0] == ':'){

                            ColonStr[0] = ' ';
                        }else{

                            ColonStr[0] = ':';
                        }

                        updateColon = 1;
                        c = 0;
                        loadAlarmTriggers();
                    }

	        }


    }

    switch(screenState)
    {
        case CREATE_MAINPAGE:
            prevRefreshState = CREATE_MAINPAGE;
            CreateMainPage();        // create window and buttons
            screenState = DISPLAY_MAINPAGE;                              // switch to next state
            return (1);                                                 // draw objects created

        case DISPLAY_MAINPAGE:
            pObj = GOLFindObject(ID_BTN1);
            BtnSetBitmap(pObj, (void *)&medidisp_button_p);

            pOtherMenuBtn = GOLFindObject(ID_BTN2);
            ClrState(pOtherMenuBtn, BTN_PRESSED);
            BtnSetBitmap(pOtherMenuBtn, (void *)&prescrip_button_n);
            SetState(pOtherMenuBtn, BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE);

            pOtherMenuBtn = GOLFindObject(ID_BTN3);
            ClrState(pOtherMenuBtn, BTN_PRESSED);
            BtnSetBitmap(pOtherMenuBtn, (void *)&medicine_button_n);
            SetState(pOtherMenuBtn, BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE);

            pOtherMenuBtn = GOLFindObject(ID_BTN4);
            ClrState(pOtherMenuBtn, BTN_PRESSED);
            BtnSetBitmap(pOtherMenuBtn, (void *)&settings_button_n);
            SetState(pOtherMenuBtn, BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE);

            SetState(pObj, BTN_PRESSED | BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE);

            if(updateTime == 1){
                pSt = GOLFindObject(ID_TIME_COLON_TEXT);
                SetState(pSt, ST_DRAW);
                pSt = GOLFindObject(ID_TIME_HR_TEXT);
                SetState(pSt, ST_DRAW);
                pSt = GOLFindObject(ID_TIME_MIN_TEXT);
                SetState(pSt, ST_DRAW);
                pSt = GOLFindObject(ID_MONTH_TEXT);
                SetState(pSt, ST_DRAW);
                pSt = GOLFindObject(ID_YEAR_TEXT);
                SetState(pSt, ST_DRAW);
                pSt = GOLFindObject(ID_AMPM_TEXT);
                SetState(pSt, ST_DRAW);
                pSt = GOLFindObject(ID_DATE_TEXT);
                SetState(pSt, ST_DRAW);
                updateTime = 0;
            }
            if(updateMin == 1){

                pSt = GOLFindObject(ID_TIME_MIN_TEXT);
                SetState(pSt, ST_DRAW);
                updateMin = 0;
            }
            if(updateColon == 1){
                pSt = GOLFindObject(ID_TIME_COLON_TEXT);
                SetState(pSt, ST_DRAW);
                updateColon = 0;
            }
            

            return (1);                                                 // redraw objects if needed

        case CREATE_PRESCRIPTIONPAGE:
            prevRefreshState = CREATE_PRESCRIPTIONPAGE;
            CreatePrescriptionPage();                                         // create window and check boxes
            screenState = DISPLAY_PRESCRIPTIONPAGE;                           // switch to next state
            selectedPrescriptionID = currentPrescriptionID + 1;
            return (1);                                                 // draw objects created

        case DISPLAY_PRESCRIPTIONPAGE:
            pObj = GOLFindObject(ID_BTN2);
            BtnSetBitmap(pObj, (void *)&prescrip_button_p);

            pOtherMenuBtn = GOLFindObject(ID_BTN1);
            ClrState(pOtherMenuBtn, BTN_PRESSED);
            BtnSetBitmap(pOtherMenuBtn, (void *)&medidisp_button_n);
            SetState(pOtherMenuBtn, BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE);

            pOtherMenuBtn = GOLFindObject(ID_BTN3);
            ClrState(pOtherMenuBtn, BTN_PRESSED);
            BtnSetBitmap(pOtherMenuBtn, (void *)&medicine_button_n);
            SetState(pOtherMenuBtn, BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE);

            pOtherMenuBtn = GOLFindObject(ID_BTN4);
            ClrState(pOtherMenuBtn, BTN_PRESSED);
            BtnSetBitmap(pOtherMenuBtn, (void *)&settings_button_n);
            SetState(pOtherMenuBtn, BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE);

            SetState(pObj, BTN_PRESSED | BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE);

            switch(selectedPrescriptionID){
                case 1:
                    pTargetBtn = GOLFindObject(ID_PRESCRIP_BTN1);
                    BtnSetBitmap(pTargetBtn, (void *)&compsel_button_p);
                    SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL);
                    //SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL|BTN_PRESSED|BTN_TOGGLE);
                    //FillCircle(140, 62, 12);
                    selectedPrescriptionID = 0xFF;
                    return(1);
                case 2:
                    pTargetBtn = GOLFindObject(ID_PRESCRIP_BTN2);
                    BtnSetBitmap(pTargetBtn, (void *)&compsel_button_p);
                    SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL);
                    //SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL|BTN_PRESSED|BTN_TOGGLE);
                    //FillCircle(114, 85, 12);
                    selectedPrescriptionID = 0xFF;
                    return(1);
                case 3:
                    pTargetBtn = GOLFindObject(ID_PRESCRIP_BTN3);
                    BtnSetBitmap(pTargetBtn, (void *)&compsel_button_p);
                    SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL);
                    //SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL|BTN_PRESSED|BTN_TOGGLE);
                    //FillCircle(114, 121, 12);
                    selectedPrescriptionID = 0xFF;
                    return(1);
                case 4:
                    pTargetBtn = GOLFindObject(ID_PRESCRIP_BTN4);
                    BtnSetBitmap(pTargetBtn, (void *)&compsel_button_p);
                    SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL);
                    //SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL|BTN_PRESSED|BTN_TOGGLE);
                    //FillCircle(140, 145, 12);
                    selectedPrescriptionID = 0xFF;
                    return(1);
                case 5:
                    pTargetBtn = GOLFindObject(ID_PRESCRIP_BTN5);
                    BtnSetBitmap(pTargetBtn, (void *)&compsel_button_p);
                    SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL);
                    //SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL|BTN_PRESSED|BTN_TOGGLE);
                    //FillCircle(174, 62, 12);
                    selectedPrescriptionID = 0xFF;
                    return(1);


            }

            return (1);                                                 // redraw objects if needed

                                               // redraw objects if needed

        case CREATE_MEDICINEPAGE:
            prevRefreshState = CREATE_MEDICINEPAGE;
            CreateMedicinePage();                                       // create window and radio buttons
            screenState = DISPLAY_MEDICINEPAGE;                         // switch to next state
            return (1);                                                 // draw objects created

        case DISPLAY_MEDICINEPAGE:
            pObj = GOLFindObject(ID_BTN3);
            BtnSetBitmap(pObj, (void *)&medicine_button_p);

            pOtherMenuBtn = GOLFindObject(ID_BTN1);
            ClrState(pOtherMenuBtn, BTN_PRESSED);
            BtnSetBitmap(pOtherMenuBtn, (void *)&medidisp_button_n);
            SetState(pOtherMenuBtn, BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE);

            pOtherMenuBtn = GOLFindObject(ID_BTN2);
            ClrState(pOtherMenuBtn, BTN_PRESSED);
            BtnSetBitmap(pOtherMenuBtn, (void *)&prescrip_button_n);
            SetState(pOtherMenuBtn, BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE);

            pOtherMenuBtn = GOLFindObject(ID_BTN4);
            ClrState(pOtherMenuBtn, BTN_PRESSED);
            BtnSetBitmap(pOtherMenuBtn, (void *)&settings_button_n);
            SetState(pOtherMenuBtn, BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE);

            SetState(pObj, BTN_PRESSED | BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE);

            switch(compartmentState){
               case ERROR:SetColor(BRIGHTRED);break;
               case WAIT :SetColor(ORANGE);break;
               case OK   :SetColor(GREEN);break;
               default   :SetColor(BLACK);break;
            }
            switch(targetCompartment){
                case 1:
                    pTargetBtn = GOLFindObject(ID_MEDICINE_BTN1);
                    BtnSetBitmap(pTargetBtn, (void *)&compsel_button_p);
                    SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL);
                    //SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL|BTN_PRESSED|BTN_TOGGLE);
                    FillCircle(140, 62, 12);

                    return(1);
                case 2:
                    pTargetBtn = GOLFindObject(ID_MEDICINE_BTN2);
                    BtnSetBitmap(pTargetBtn, (void *)&compsel_button_p);
                    SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL);
                    //SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL|BTN_PRESSED|BTN_TOGGLE);
                    FillCircle(114, 85, 12);
                    return(1);
                case 3:
                    pTargetBtn = GOLFindObject(ID_MEDICINE_BTN3);
                    BtnSetBitmap(pTargetBtn, (void *)&compsel_button_p);
                    SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL);
                    //SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL|BTN_PRESSED|BTN_TOGGLE);
                    FillCircle(114, 121, 12);
                    return(1);
                case 4:
                    pTargetBtn = GOLFindObject(ID_MEDICINE_BTN4);
                    BtnSetBitmap(pTargetBtn, (void *)&compsel_button_p);
                    SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL);
                    //SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL|BTN_PRESSED|BTN_TOGGLE);
                    FillCircle(140, 145, 12);
                    return(1);
                case 5:
                    pTargetBtn = GOLFindObject(ID_MEDICINE_BTN5);
                    BtnSetBitmap(pTargetBtn, (void *)&compsel_button_p);
                    SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL);
                    //SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL|BTN_PRESSED|BTN_TOGGLE);
                    FillCircle(174, 62, 12);

                    return(1);
                case 6:
                    pTargetBtn = GOLFindObject(ID_MEDICINE_BTN6);
                    BtnSetBitmap(pTargetBtn, (void *)&compsel_button_p);
                    SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL);
                    //SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL|BTN_PRESSED|BTN_TOGGLE);
                    FillCircle(200, 85, 12);

                    return(1);
                case 7:
                    pTargetBtn = GOLFindObject(ID_MEDICINE_BTN7);
                    BtnSetBitmap(pTargetBtn, (void *)&compsel_button_p);
                    SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL);
                    //SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL|BTN_PRESSED|BTN_TOGGLE);
                    FillCircle(200, 122, 12);
                    return(1);
                case 8:
                    pTargetBtn = GOLFindObject(ID_MEDICINE_BTN8);
                    BtnSetBitmap(pTargetBtn, (void *)&compsel_button_p);
                    SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL);
                    //SetState(pTargetBtn, BTN_DRAW|BTN_NOPANEL|BTN_PRESSED|BTN_TOGGLE);
                    FillCircle(174, 145, 12);
                    return(1);

            }

            return (1);                                                 // redraw objects if needed

        case CREATE_SETTINGSPAGE:
            prevRefreshState = CREATE_SETTINGSPAGE;
            CreateSettingsPage();                                         // create window, group box, static text
            screenState = DISPLAY_SETTINGSPAGE;                           // switch to next state
            return (1);                                                 // draw objects created

        case DISPLAY_SETTINGSPAGE:

            if(settingsPressedArrowBtnID != 0xFFFF){


                if((tick - savedTick) < 100){

                    pObj = GOLFindObject(settingsPressedArrowBtnID);

                    if(settingsPressedArrowBtnID % 2 == 1){
                        BtnSetBitmap(pObj, (void *)&uparrow_button_p);
                    }else{
                        BtnSetBitmap(pObj, (void *)&dwnarrow_button_p);
                    }
                }else{

                    pObj = GOLFindObject(settingsPressedArrowBtnID);

                    if(settingsPressedArrowBtnID % 2 == 1){
                        BtnSetBitmap(pObj, (void *)&uparrow_button_n);
                    }else{
                        BtnSetBitmap(pObj, (void *)&dwnarrow_button_n);
                    }

                    settingsPressedArrowBtnID = 0xFFFF;
                    savedTick = tick;

                }

            }
            
            //EbSetText(pObj,XCHAR *(itoa(iYear)));
            //itoa(char * buf, int val, int base);
            //EbSetText((EDITBOX *)pObj, (XCHAR *)itoa(sYear,iYear,10));
            //if(updateSettings == 1){

                pObj = GOLFindObject(ID_SETTINGS_YEAR_VALUE);
                EbSetText((EDITBOX *)pObj, (XCHAR *)&YearItems[(iYear*5)]);
                updateSettings = 0;
            //}
            
            pObj = GOLFindObject(ID_BTN4);
            BtnSetBitmap(pObj, (void *)&settings_button_p);

            pOtherMenuBtn = GOLFindObject(ID_BTN1);
            ClrState(pOtherMenuBtn, BTN_PRESSED);
            BtnSetBitmap(pOtherMenuBtn, (void *)&medidisp_button_n);
            SetState(pOtherMenuBtn, BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE);

            pOtherMenuBtn = GOLFindObject(ID_BTN2);
            ClrState(pOtherMenuBtn, BTN_PRESSED);
            BtnSetBitmap(pOtherMenuBtn, (void *)&prescrip_button_n);
            SetState(pOtherMenuBtn, BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE);

            pOtherMenuBtn = GOLFindObject(ID_BTN3);
            ClrState(pOtherMenuBtn, BTN_PRESSED);
            BtnSetBitmap(pOtherMenuBtn, (void *)&medicine_button_n);
            SetState(pOtherMenuBtn, BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE);

            SetState(pObj, BTN_PRESSED | BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE);
            return (1);                         // redraw objects if needed

        case CREATE_KEYPAGE:
            prevRefreshState = CREATE_KEYPAGE;
            CreateKeyPadPage(keyPadArgs[keyPadArgID]);                                         // create window, group box, static text
            // and radio buttons for control
            screenState = DISPLAY_KEYPAGE;                           // switch to next state
            return (1);

        case DISPLAY_KEYPAGE:

            if(currentKeyBtnID != 0xFFFF){


                if((tick - savedTick) < 400){

                    pObj = GOLFindObject(currentKeyBtnID);
                    BtnSetBitmap(pObj, (void *)&keypad_button_p);
                    //SetState(pObj, BTN_DRAW|BTN_NOPANEL);
                }else{

                    pObj = GOLFindObject(currentKeyBtnID);
                    BtnSetBitmap(pObj, (void *)&keypad_button_n);
                    //SetState(pObj, BTN_DRAW|BTN_NOPANEL);
                    //SetState(pObj, BTN_DRAW|BTN_NOPANEL);
                    if((currentKeyBtnID == ID_KEYPAD_CANCEL) || (currentKeyBtnID == ID_KEYPAD_OK))
                    screenState = prevState;
                    currentKeyBtnID = 0xFFFF;
                    savedTick = tick;

                }
                
            }

                updateKeyPad = 0;
            return(1);

        case CREATE_ALARMPAGE:
            CreateAlarmPage(0);
            screenState = DISPLAY_ALARMPAGE;
            return(1);
        case DISPLAY_ALARMPAGE:
            return(1);
        default:

            return (1); // release drawing control to GOL
    }
}

void CreateMenu(void){

    BtnCreate(ID_BTN1,0,209,98,236,0, BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE, (void *) &medidisp_button_n, NULL, altScheme);
    BtnCreate(ID_BTN2,101,209,172,236,0, BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE, (void *) &prescrip_button_n, NULL, altScheme);
    BtnCreate(ID_BTN3,175,209,246,236,0, BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE, (void *) &medicine_button_n, NULL, altScheme);
    BtnCreate(ID_BTN4,249,209,320,236,0, BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE, (void *) &settings_button_n, NULL, altScheme);


}

void CreateMainPage(void){

    OBJ_HEADER *pBtn;
    int i,j,k;
    
    GOLFree();
    SetColor(BLACK);
    ClearDevice();

    CreateMenu();


    StCreate(ID_TIME_COLON_TEXT,156,85,178,180,ST_DRAW,ColonStr,timeScheme);
    StCreate(ID_TIME_HR_TEXT,75,90,160,180,ST_DRAW,HourStr,timeScheme);
    StCreate(ID_TIME_MIN_TEXT,176,90,260,184,ST_DRAW,MinStr,timeScheme);
    StCreate(ID_AMPM_TEXT,260,127,320,180,ST_DRAW,AmpmStr,ampmScheme);
    StCreate(ID_YEAR_TEXT,8,91,63,115,ST_DRAW,YearStr,dateScheme);
    StCreate(ID_MONTH_TEXT,8,120,63,144,ST_DRAW,MonthStr,dateScheme);
    StCreate(ID_DATE_TEXT,8,149,63,173,ST_DRAW,DateStr,dateScheme);

    BtnCreate(ID_BELL_BTN1,8,8,58,75,0, BTN_DRAW|BTN_TOGGLE|BTN_TEXTBOTTOM , (void *) &bell_button_disabled, NULL, bellScheme);
    BtnCreate(ID_BELL_BTN2,68,8,118,75,0, BTN_DRAW|BTN_TOGGLE|BTN_TEXTBOTTOM , (void *) &bell_button_disabled, NULL, bellScheme);
    BtnCreate(ID_BELL_BTN3,128,8,178,75,0, BTN_DRAW|BTN_TOGGLE|BTN_TEXTBOTTOM , (void *) &bell_button_disabled, NULL, bellScheme);
    BtnCreate(ID_BELL_BTN4,188,8,238,75,0, BTN_DRAW|BTN_TOGGLE|BTN_TEXTBOTTOM , (void *) &bell_button_disabled, NULL, bellScheme);
    BtnCreate(ID_BELL_BTN5,248,8,298,75,0, BTN_DRAW|BTN_TOGGLE|BTN_TEXTBOTTOM , (void *) &bell_button_disabled, NULL, bellScheme);

    for(i = 0; i< 5; i++){

        switch(i){
            case 0:pBtn = GOLFindObject(ID_BELL_BTN1);break;
            case 1:pBtn = GOLFindObject(ID_BELL_BTN2);break;
            case 2:pBtn = GOLFindObject(ID_BELL_BTN3);break;
            case 3:pBtn = GOLFindObject(ID_BELL_BTN4);break;
            case 4:pBtn = GOLFindObject(ID_BELL_BTN5);break;
        }
        if(Prescriptions[i].PRESCRIPTION.Name[0] != 'P'){

            BtnSetBitmap(pBtn, (void *)&bell_button_n);
            BtnSetText((BUTTON *)pBtn,(XCHAR *)Prescriptions[i].PRESCRIPTION.Name);
        }

    }
    
}

void CreateMedicinePage(void){

    GOLFree();
    SetColor(BLACK);
    ClearDevice();

    CreateMenu();

    BtnCreate(ID_MEDICINE_BTN1,6,16,78,51,0, BTN_DRAW|BTN_NOPANEL , (void *) &compsel_button_n, (XCHAR *)&strMedicines[0], prescripScheme);
    BtnCreate(ID_MEDICINE_BTN2,6,62,78,97,0, BTN_DRAW|BTN_NOPANEL , (void *) &compsel_button_n, (XCHAR *)&strMedicines[1], prescripScheme);
    BtnCreate(ID_MEDICINE_BTN3,6,107,78,142,0, BTN_DRAW|BTN_NOPANEL , (void *) &compsel_button_n, (XCHAR *)&strMedicines[2], prescripScheme);
    BtnCreate(ID_MEDICINE_BTN4,6,152,78,187,0, BTN_DRAW|BTN_NOPANEL , (void *) &compsel_button_n, (XCHAR *)&strMedicines[3], prescripScheme);
    BtnCreate(ID_MEDICINE_BTN5,241,16,313,51,0, BTN_DRAW|BTN_NOPANEL , (void *) &compsel_button_n, (XCHAR *)&strMedicines[4], prescripScheme);
    BtnCreate(ID_MEDICINE_BTN6,241,62,313,97,0, BTN_DRAW|BTN_NOPANEL , (void *) &compsel_button_n, (XCHAR *)&strMedicines[5], prescripScheme);
    BtnCreate(ID_MEDICINE_BTN7,241,107,313,142,0, BTN_DRAW|BTN_NOPANEL , (void *) &compsel_button_n, (XCHAR *)&strMedicines[6], prescripScheme);
    BtnCreate(ID_MEDICINE_BTN8,241,152,313,187,0, BTN_DRAW|BTN_NOPANEL , (void *) &compsel_button_n, (XCHAR *)&strMedicines[7], prescripScheme);

//        BtnCreate(ID_MEDICINE_BTN1,6,16,78,51,0, BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE , (void *) &compsel_button_n, Bell1Str, altScheme);
//    BtnCreate(ID_MEDICINE_BTN2,6,62,78,97,0, BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE , (void *) &compsel_button_n, Bell1Str, altScheme);
//    BtnCreate(ID_MEDICINE_BTN3,6,107,78,142,0, BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE , (void *) &compsel_button_n, Bell1Str, altScheme);
//    BtnCreate(ID_MEDICINE_BTN4,6,152,78,187,0, BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE , (void *) &compsel_button_n, Bell1Str, altScheme);
//    BtnCreate(ID_MEDICINE_BTN5,241,16,313,51,0, BTN_DRAW||BTN_TOGGLE , (void *) &compsel_button_n, Bell1Str, altScheme);
//    BtnCreate(ID_MEDICINE_BTN6,241,62,313,97,0, BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE , (void *) &compsel_button_n, Bell1Str, altScheme);
//    BtnCreate(ID_MEDICINE_BTN7,241,107,313,142,0, BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE , (void *) &compsel_button_n, Bell1Str, altScheme);
//    BtnCreate(ID_MEDICINE_BTN8,241,152,313,187,0, BTN_DRAW|BTN_NOPANEL|BTN_TOGGLE , (void *) &compsel_button_n, Bell1Str, altScheme);

    //SetColor(BRIGHTRED);
    SetColor(GRAY230);
    //Outer Octagon
    WAIT_UNTIL_FINISH(Line(107,53,157,33));
    WAIT_UNTIL_FINISH(Line(107,53,86,103));
    WAIT_UNTIL_FINISH(Line(86,103,106,153));
    WAIT_UNTIL_FINISH(Line(106,153,156,175));
    WAIT_UNTIL_FINISH(Line(156,175,207,154));
    WAIT_UNTIL_FINISH(Line(207,154,229,103));
    WAIT_UNTIL_FINISH(Line(229,103,208,54));
    WAIT_UNTIL_FINISH(Line(208,54,157,33));
    //Cross Lines
    WAIT_UNTIL_FINISH(Line(157,33,157,82));
    WAIT_UNTIL_FINISH(Line(107,53,142,89));
    WAIT_UNTIL_FINISH(Line(86,103,135,103));
    WAIT_UNTIL_FINISH(Line(106,153,141,119));
    WAIT_UNTIL_FINISH(Line(156,175,156,125));
    WAIT_UNTIL_FINISH(Line(207,154,171,119));
    WAIT_UNTIL_FINISH(Line(229,103,178,103));
    WAIT_UNTIL_FINISH(Line(172,89,208,54));
    //Inner Octagon
    WAIT_UNTIL_FINISH(Line(142,89,157,82));
    WAIT_UNTIL_FINISH(Line(142,89,135,103));
    WAIT_UNTIL_FINISH(Line(135,103,141,119));
    WAIT_UNTIL_FINISH(Line(141,119,156,125));
    WAIT_UNTIL_FINISH(Line(156,125,171,119));
    WAIT_UNTIL_FINISH(Line(171,119,178,103));
    WAIT_UNTIL_FINISH(Line(178,103,171,89));
    WAIT_UNTIL_FINISH(Line(171,89,157,82));
    //Handles
    WAIT_UNTIL_FINISH(Line(79,31,120,31));
    WAIT_UNTIL_FINISH(Line(120,31,131,42));
    WAIT_UNTIL_FINISH(Line(240,31,199,31));
    WAIT_UNTIL_FINISH(Line(199,31,182,42));
    WAIT_UNTIL_FINISH(Line(78,173,119,173));
    WAIT_UNTIL_FINISH(Line(119,173,132,165));
    WAIT_UNTIL_FINISH(Line(240,173,198,173));
    WAIT_UNTIL_FINISH(Line(198,173,181,165));
    WAIT_UNTIL_FINISH(Line(79,80,95,80));
    WAIT_UNTIL_FINISH(Line(240,80,219,80));
    WAIT_UNTIL_FINISH(Line(79,125,94,125));
    WAIT_UNTIL_FINISH(Line(240,125,220,125));

    //WAIT_UNTIL_FINISH(Bar(0,0,100,100));
//    SetColor(BRIGHTRED);
//    FillCircle(140, 62, 12);
//    FillCircle(114, 85, 12);
//    FillCircle(114, 121, 12);
//    FillCircle(140, 145, 12);
//    FillCircle(174, 145, 12);
//    FillCircle(200, 122, 12);
//    FillCircle(200, 85, 12);
//    FillCircle(174, 62, 12);
}

void CreatePrescriptionPage(void){

//    struct PRESCRIPTION{
//
//    XCHAR Name[10];
//    XCHAR Times[5][6];
//    XCHAR Medicines[5][11];
//    XCHAR Qty[5][5];
//    XCHAR Comp[5][2];
//
//};
//
//struct PRESCRIPTION Prescriptions[6];

    GOLFree();
    SetColor(BLACK);
    ClearDevice();

    CreateMenu();

    SetColor(GRAY200);
    //Table
    WAIT_UNTIL_FINISH(Line(90,4,315,4));
    WAIT_UNTIL_FINISH(Line(90,199,315,199));
    WAIT_UNTIL_FINISH(Line(90,5,90,199));
    WAIT_UNTIL_FINISH(Line(150,5,150,199));
    WAIT_UNTIL_FINISH(Line(230,5,230,199));
    WAIT_UNTIL_FINISH(Line(270,5,270,199));
    WAIT_UNTIL_FINISH(Line(315,5,315,199));
    WAIT_UNTIL_FINISH(Line(90,23,315,23));


    BtnCreate(ID_PRESCRIP_BTN1,4,4,76,39,0, BTN_DRAW|BTN_NOPANEL , (void *) &compsel_button_n, (XCHAR *)Prescriptions[0].PRESCRIPTION.Name, prescripScheme);
    BtnCreate(ID_PRESCRIP_BTN2,4,44,76,79,0, BTN_DRAW|BTN_NOPANEL , (void *) &compsel_button_n, (XCHAR *)Prescriptions[1].PRESCRIPTION.Name, prescripScheme);
    BtnCreate(ID_PRESCRIP_BTN3,4,84,76,119,0, BTN_DRAW|BTN_NOPANEL , (void *) &compsel_button_n, (XCHAR *)Prescriptions[2].PRESCRIPTION.Name, prescripScheme);
    BtnCreate(ID_PRESCRIP_BTN4,4,124,76,159,0, BTN_DRAW|BTN_NOPANEL , (void *) &compsel_button_n, (XCHAR *)Prescriptions[3].PRESCRIPTION.Name, prescripScheme);
    BtnCreate(ID_PRESCRIP_BTN5,4,164,76,199,0, BTN_DRAW|BTN_NOPANEL , (void *) &compsel_button_n, (XCHAR *)Prescriptions[4].PRESCRIPTION.Name, prescripScheme);

    StCreate(ID_PRESCRIP_TEXT1,104,7,138,19,ST_DRAW,Time,prescripScheme);
    StCreate(ID_PRESCRIP_TEXT2,163,7,219,19,ST_DRAW,Medicine,prescripScheme);
    StCreate(ID_PRESCRIP_TEXT3,239,7,265,19,ST_DRAW,Qty,prescripScheme);
    StCreate(ID_PRESCRIP_TEXT4,275,7,312,19,ST_DRAW,Comp,prescripScheme);

    //Column1
    StCreate(ID_PRESCRIP_C1_R1,104,31,138,43,ST_DRAW,(XCHAR *)Prescriptions[currentPrescriptionID].PRESCRIPTION.Times[0],prescripScheme);
    StCreate(ID_PRESCRIP_C1_R2,104,52,138,64,ST_DRAW,(XCHAR *)Prescriptions[currentPrescriptionID].PRESCRIPTION.Times[1],prescripScheme);
    StCreate(ID_PRESCRIP_C1_R3,104,73,138,85,ST_DRAW,(XCHAR *)Prescriptions[currentPrescriptionID].PRESCRIPTION.Times[2],prescripScheme);
    StCreate(ID_PRESCRIP_C1_R4,104,94,138,106,ST_DRAW,(XCHAR *)Prescriptions[currentPrescriptionID].PRESCRIPTION.Times[3],prescripScheme);
    StCreate(ID_PRESCRIP_C1_R5,104,115,138,127,ST_DRAW,(XCHAR *)Prescriptions[currentPrescriptionID].PRESCRIPTION.Times[4],prescripScheme);


    //Column2
    StCreate(ID_PRESCRIP_C2_R1,163,31,219,43,ST_DRAW,(XCHAR *)Prescriptions[currentPrescriptionID].PRESCRIPTION.Medicines[0],prescripScheme);
    StCreate(ID_PRESCRIP_C2_R2,163,52,219,64,ST_DRAW,(XCHAR *)Prescriptions[currentPrescriptionID].PRESCRIPTION.Medicines[1],prescripScheme);
    StCreate(ID_PRESCRIP_C2_R3,163,73,219,85,ST_DRAW,(XCHAR *)Prescriptions[currentPrescriptionID].PRESCRIPTION.Medicines[2],prescripScheme);
    StCreate(ID_PRESCRIP_C2_R4,163,94,219,106,ST_DRAW,(XCHAR *)Prescriptions[currentPrescriptionID].PRESCRIPTION.Medicines[3],prescripScheme);
    StCreate(ID_PRESCRIP_C2_R5,163,115,219,127,ST_DRAW,(XCHAR *)Prescriptions[currentPrescriptionID].PRESCRIPTION.Medicines[4],prescripScheme);


    //Column3
    StCreate(ID_PRESCRIP_C3_R1,239,31,265,43,ST_DRAW,(XCHAR *)Prescriptions[currentPrescriptionID].PRESCRIPTION.Qty[0],prescripScheme);
    StCreate(ID_PRESCRIP_C3_R2,239,52,265,64,ST_DRAW,(XCHAR *)Prescriptions[currentPrescriptionID].PRESCRIPTION.Qty[1],prescripScheme);
    StCreate(ID_PRESCRIP_C3_R3,239,73,265,85,ST_DRAW,(XCHAR *)Prescriptions[currentPrescriptionID].PRESCRIPTION.Qty[2],prescripScheme);
    StCreate(ID_PRESCRIP_C3_R4,239,94,265,106,ST_DRAW,(XCHAR *)Prescriptions[currentPrescriptionID].PRESCRIPTION.Qty[3],prescripScheme);
    StCreate(ID_PRESCRIP_C3_R5,239,115,265,127,ST_DRAW,(XCHAR *)Prescriptions[currentPrescriptionID].PRESCRIPTION.Qty[4],prescripScheme);


    //Column4
    StCreate(ID_PRESCRIP_C4_R1,275,31,312,43,ST_DRAW,(XCHAR *)Prescriptions[currentPrescriptionID].PRESCRIPTION.Comp[0],prescripScheme);
    StCreate(ID_PRESCRIP_C4_R2,275,52,312,64,ST_DRAW,(XCHAR *)Prescriptions[currentPrescriptionID].PRESCRIPTION.Comp[1],prescripScheme);
    StCreate(ID_PRESCRIP_C4_R3,275,73,312,85,ST_DRAW,(XCHAR *)Prescriptions[currentPrescriptionID].PRESCRIPTION.Comp[2],prescripScheme);
    StCreate(ID_PRESCRIP_C4_R4,275,94,312,106,ST_DRAW,(XCHAR *)Prescriptions[currentPrescriptionID].PRESCRIPTION.Comp[3],prescripScheme);
    StCreate(ID_PRESCRIP_C4_R5,275,115,312,127,ST_DRAW,(XCHAR *)Prescriptions[currentPrescriptionID].PRESCRIPTION.Comp[4],prescripScheme);



}
void CreateSettingsPage(void){

    XCHAR buf[3] = {0,0,0};
    GOLFree();
    SetColor(BLACK);
    ClearDevice();

    CreateMenu();

    SetColor(GRAY200);

    WAIT_UNTIL_FINISH(Rectangle(20, 5, 235, 37));
    WAIT_UNTIL_FINISH(Rectangle(20, 45, 235, 77));
    WAIT_UNTIL_FINISH(Rectangle(20, 85, 235, 117));
    WAIT_UNTIL_FINISH(Rectangle(20, 125, 235, 157));
    WAIT_UNTIL_FINISH(Rectangle(20, 165, 235, 197));

    WAIT_UNTIL_FINISH(Line(107,6,107,36));
    WAIT_UNTIL_FINISH(Line(107,46,107,76));
    WAIT_UNTIL_FINISH(Line(107,86,107,116));
    WAIT_UNTIL_FINISH(Line(107,126,107,156));
    WAIT_UNTIL_FINISH(Line(107,166,107,196));

    BtnCreate(ID_SETTINGS_YEAR_UP,209,7,232,20,0, BTN_DRAW|BTN_NOPANEL , (void *) &uparrow_button_n, NULL, bellScheme);
    BtnCreate(ID_SETTINGS_YEAR_DOWN,209,21,232,34,0, BTN_DRAW|BTN_NOPANEL , (void *) &dwnarrow_button_n, NULL, bellScheme);
    BtnCreate(ID_SETTINGS_MNTH_UP,209,47,232,60,0, BTN_DRAW|BTN_NOPANEL , (void *) &uparrow_button_n, NULL, bellScheme);
    BtnCreate(ID_SETTINGS_MNTH_DOWN,209,61,232,74,0, BTN_DRAW|BTN_NOPANEL , (void *) &dwnarrow_button_n, NULL, bellScheme);
    BtnCreate(ID_SETTINGS_DATE_UP,209,87,232,100,0, BTN_DRAW|BTN_NOPANEL , (void *) &uparrow_button_n, NULL, bellScheme);
    BtnCreate(ID_SETTINGS_DATE_DOWN,209,101,232,114,0, BTN_DRAW|BTN_NOPANEL , (void *) &dwnarrow_button_n, NULL, bellScheme);
    BtnCreate(ID_SETTINGS_TIME_HR_UP,151,127,174,140,0, BTN_DRAW|BTN_NOPANEL , (void *) &uparrow_button_n, NULL, bellScheme);
    BtnCreate(ID_SETTINGS_TIME_HR_DOWN,151,141,174,154,0, BTN_DRAW|BTN_NOPANEL , (void *) &dwnarrow_button_n, NULL, bellScheme);
    BtnCreate(ID_SETTINGS_TIME_MN_UP,209,127,232,140,0, BTN_DRAW|BTN_NOPANEL , (void *) &uparrow_button_n, NULL, bellScheme);
    BtnCreate(ID_SETTINGS_TIME_MN_DOWN,209,141,232,154,0, BTN_DRAW|BTN_NOPANEL , (void *) &dwnarrow_button_n, NULL, bellScheme);
    BtnCreate(ID_SETTINGS_ALRM_UP,209,167,232,180,0, BTN_DRAW|BTN_NOPANEL , (void *) &uparrow_button_n, NULL, bellScheme);
    BtnCreate(ID_SETTINGS_ALRM_DOWN,209,181,232,194,0, BTN_DRAW|BTN_NOPANEL , (void *) &dwnarrow_button_n, NULL, bellScheme);


    StCreate(ID_SETTINGS_YEAR,30,13,94,33,ST_DRAW,SettingsYearStr,bellScheme);
    StCreate(ID_SETTINGS_MNTH,30,53,94,73,ST_DRAW,SettingsMonthStr,bellScheme);
    StCreate(ID_SETTINGS_DATE,30,93,94,113,ST_DRAW,SettingsDateStr,bellScheme);
    StCreate(ID_SETTINGS_TIME,30,133,94,153,ST_DRAW,SettingsTimeStr,bellScheme);
    StCreate(ID_SETTINGS_ALRM,30,173,94,193,ST_DRAW,SettingsAlarmStr,bellScheme);

    EbCreate(ID_SETTINGS_YEAR_VALUE,120,13,180,33,EB_DRAW,(XCHAR *)&YearItems[(iYear*5)],4,bellScheme);
    EbCreate(ID_SETTINGS_MNTH_VALUE,120,53,180,73,EB_DRAW,(XCHAR *)&MonthItems[(iMonth*4)],3,bellScheme);
    EbCreate(ID_SETTINGS_DATE_VALUE,120,93,180,113,EB_DRAW,(XCHAR *)&DayItems[(iDate*3)],2,bellScheme);
    EbCreate(ID_SETTINGS_TIME_HR_VALUE,118,133,140,153,EB_DRAW,xItoA(buf,iHour,10),2,bellScheme);
    EbCreate(ID_SETTINGS_TIME_MN_VALUE,178,133,198,153,EB_DRAW,xItoA(buf,iMinute,10),2,bellScheme);
    EbCreate(ID_SETTINGS_ALRM_VALUE,120,173,180,193,EB_DRAW,(XCHAR *)&AlarmItems[(iAlarm*4)],3,bellScheme);

//    StCreate(ID_SETTINGS_YEAR_VALUE,30,13,94,33,ST_DRAW,SettingsYearStr,prescripScheme);
//    StCreate(ID_SETTINGS_MNTH_VALUE,30,53,94,73,ST_DRAW,SettingsMonthStr,prescripScheme);
//    StCreate(ID_SETTINGS_DATE_VALUE,30,93,94,113,ST_DRAW,SettingsDateStr,prescripScheme);
//    StCreate(ID_SETTINGS_TIME_HR_VALUE,30,133,94,153,ST_DRAW,SettingsTimeStr,prescripScheme);
//    StCreate(ID_SETTINGS_TIME_MN_VALUE,30,133,94,153,ST_DRAW,SettingsTimeStr,prescripScheme);
//    StCreate(ID_SETTINGS_ALRM_VALUE,30,173,94,193,ST_DRAW,SettingsAlarmStr,prescripScheme);
}

void CreateKeyPadPage(XCHAR *str){

        static XCHAR    pTempXchar[][6] =  {   {'0',0},
        {'1',0},
        {'2','a','b','c',0},
        {'3','d','e','f',0},
        {'4','g','h','i',0},
        {'5','j','k','l',0},
        {'6','m','n','o',0},
        {'7','p','q','r','s',0},
        {'8','t','u','v',0},
        {'9','w','x','y','z',0},
        {'B','a','c','k',0},
        {'O','k',0},
        {'D','e','l',0},
        {'.',':',0}
    };
    GOLFree();
    SetColor(BLACK);
    ClearDevice();

    //CreateMenu();

    SetColor(ORANGE);

    //WAIT_UNTIL_FINISH(Rectangle(5, 5, 315, 235));

//175 + 6 spaces = 230
//6 spaces = 55
//space = 9
//
//
//72 * 3 + 4 spaces = 310
//216 + 4 spaces = 310
//4 spaces = 94
//
//2 + 2 spaces = 18 + 18 + 29 + 29
//starting point x = 5 + 29 , y = 5 + 9 ,starting point x = 5 + 29 + 72 + 18, y= 5 + 9 + 35 + 9,tarting point x = 5 + 29 + 72 + 18 + 90
// 72x35

//    BtnCreate(ID_KEYPAD_1,34,14,106,49,0, BTN_DRAW|BTN_NOPANEL , (void *) &compsel_button_n, NULL, prescripScheme);
//    BtnCreate(ID_KEYPAD_2ABC,124,14,196,49,0, BTN_DRAW|BTN_NOPANEL , (void *) &compsel_button_n, NULL, prescripScheme);
//    BtnCreate(ID_KEYPAD_3DEF,214,14,286,49,0, BTN_DRAW|BTN_NOPANEL , (void *) &compsel_button_n, NULL, prescripScheme);
    WAIT_UNTIL_FINISH(Rectangle(28, 14, 288, 49));
    WAIT_UNTIL_FINISH(Line(100,14,100,49));
    StCreate(ID_KEYPAD_VARIABLE,36,24,95,47,ST_DRAW,str,bellScheme);
    EbCreate(ID_KEYPAD_EDITBOX,130,16,284,47,EB_DRAW,NULL,keyPadEditBoxMaxLength,bellScheme);

    BtnCreate(ID_KEYPAD_1,28,58,90,93,0, BTN_DRAW|BTN_NOPANEL , (void *) &keypad_button_n, (XCHAR *)pTempXchar[1], bellScheme);
    BtnCreate(ID_KEYPAD_2ABC,94,58,156,93,0, BTN_DRAW|BTN_NOPANEL , (void *) &keypad_button_n, (XCHAR *)pTempXchar[2], bellScheme);
    BtnCreate(ID_KEYPAD_3DEF,160,58,222,93,0, BTN_DRAW|BTN_NOPANEL , (void *) &keypad_button_n, (XCHAR *)pTempXchar[3], bellScheme);
    BtnCreate(ID_KEYPAD_DEL,226,58,288,93,0, BTN_DRAW|BTN_NOPANEL , (void *) &keypad_button_n, (XCHAR *)pTempXchar[12], bellScheme);
    BtnCreate(ID_KEYPAD_4GHI,28,102,90,137,0, BTN_DRAW|BTN_NOPANEL , (void *) &keypad_button_n, (XCHAR *)pTempXchar[4], bellScheme);
    BtnCreate(ID_KEYPAD_5JKL,94,102,156,137,0, BTN_DRAW|BTN_NOPANEL , (void *) &keypad_button_n, (XCHAR *)pTempXchar[5], bellScheme);
    BtnCreate(ID_KEYPAD_6MNO,160,102,222,137,0, BTN_DRAW|BTN_NOPANEL , (void *) &keypad_button_n, (XCHAR *)pTempXchar[6], bellScheme);
    BtnCreate(ID_KEYPAD_COLON,226,102,288,137,0, BTN_DRAW|BTN_NOPANEL , (void *) &keypad_button_n, (XCHAR *)pTempXchar[13], bellScheme);
    BtnCreate(ID_KEYPAD_7PQRS,28,146,90,181,0, BTN_DRAW|BTN_NOPANEL , (void *) &keypad_button_n, (XCHAR *)pTempXchar[7], bellScheme);
    BtnCreate(ID_KEYPAD_8TUV,94,146,156,181,0, BTN_DRAW|BTN_NOPANEL , (void *) &keypad_button_n, (XCHAR *)pTempXchar[8], bellScheme);
    BtnCreate(ID_KEYPAD_9WXYZ,160,146,222,181,0, BTN_DRAW|BTN_NOPANEL , (void *) &keypad_button_n, (XCHAR *)pTempXchar[9], bellScheme);
    //BtnCreate(ID_KEYPAD_DEL,226,58,288,93,0, BTN_DRAW|BTN_NOPANEL , (void *) &keypad_button_n, NULL, prescripScheme);
    BtnCreate(ID_KEYPAD_CANCEL,28,190,90,225,0, BTN_DRAW|BTN_NOPANEL , (void *) &keypad_button_n, (XCHAR *)pTempXchar[10], bellScheme);
    BtnCreate(ID_KEYPAD_0SP,94,190,156,225,0, BTN_DRAW|BTN_NOPANEL , (void *) &keypad_button_n, (XCHAR *)pTempXchar[0], bellScheme);
    BtnCreate(ID_KEYPAD_OK,160,190,222,225,0, BTN_DRAW|BTN_NOPANEL , (void *) &keypad_button_n, (XCHAR *)pTempXchar[11], bellScheme);
    //BtnCreate(ID_KEYPAD_DEL,226,58,288,93,0, BTN_DRAW|BTN_NOPANEL , (void *) &keypad_button_n, NULL, prescripScheme);


}

void CreateAlarmPage(int ID){

    static XCHAR pBtnCaption[6][13] = {{'O','k',0},{'A','b','o','r','t',0},{'S','k','i','p',0},{'P','r','e','s','c','r','i','p','t','i','o','n',0},{'T','a','k','e',0},{'0','2','5',0}};
    GOLFree();
    SetColor(BLACK);
    ClearDevice();

    CreateMenu();

//    #define ID_ALARM_OK     300
//#define ID_ALARM_ABORT     301
//#define ID_ALARM_DESCRIPTION1     302
//#define ID_ALARM_DESCRIPTION2     303
//#define ID_ALARM_QTY     304
//#define ID_ALARM_IMAGE     305



    BtnCreate(ID_ALARM_OK,250,75,312,110,0, BTN_DRAW|BTN_NOPANEL , (void *) &keypad_button_n, (XCHAR *)pBtnCaption[0], bellScheme);
    BtnCreate(ID_ALARM_ABORT,250,115,312,150,0, BTN_DRAW|BTN_NOPANEL , (void *) &keypad_button_n, (XCHAR *)pBtnCaption[1], bellScheme);
    BtnCreate(ID_ALARM_SKIP,250,155,312,190,0, BTN_DRAW|BTN_NOPANEL , (void *) &keypad_button_n, (XCHAR *)pBtnCaption[2], bellScheme);
    BtnCreate(ID_ALARM_IMAGE,8,8,58,75,0, BTN_DRAW|BTN_NOPANEL , (void *) &bell_button_p, NULL, bellScheme);

    StCreate(ID_ALARM_DESCRIPTION1,60,8,175,65,ST_DRAW|ST_RIGHT_ALIGN,(XCHAR *)Prescriptions[ID].PRESCRIPTION.Name,dateScheme);
    StCreate(ID_ALARM_DESCRIPTION2,180,8,310,65,ST_DRAW,(XCHAR *)pBtnCaption[3],dateScheme);
    StCreate(ID_ALARM_DESCRIPTION3,40,70,100,130,ST_DRAW,(XCHAR *)pBtnCaption[4],dateScheme);
    StCreate(ID_ALARM_QTY,100,90,250,200,ST_DRAW,(XCHAR *)pBtnCaption[5],timeScheme);


}


void Init_UART1(int baudRate)
{
    UARTConfigure(UART1,UART_ENABLE_PINS_TX_RX_ONLY);          // Use only RX and TX pin for the UART (no handshake)
    UARTSetFifoMode(UART1, UART_INTERRUPT_ON_TX_NOT_FULL | UART_INTERRUPT_ON_RX_NOT_EMPTY); // Set the interrupt trigger condition for RX and TX
    UARTSetLineControl(UART1, UART_DATA_SIZE_8_BITS | UART_PARITY_NONE | UART_STOP_BITS_1); // Set the UART exchange protocol as 8-N-1
    UARTSetDataRate(UART1,GetSystemClock()/2,baudRate);        // Set the desired baud rate (see the #define on the top)
    UARTEnable(UART1,UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));    // Enable the UART module
    //U1MODEbits.FRZ=0;
    //U1MODEbits.

    INTSetVectorPriority(INT_VECTOR_UART(UART1), INT_PRIORITY_LEVEL_7);
    INTSetVectorSubPriority(INT_VECTOR_UART(UART1), INT_SUB_PRIORITY_LEVEL_0);   // Set the UART ISR priority and subpriority level

	INTEnable(INT_U1RX, INT_ENABLED);  // RX Interrupt is enabled
	INTEnable(INT_U1TX, INT_DISABLED);  // TX Interrupt is disabled, no need to fire into it now, only when we need to send out somethings!!
}











//
//
//
//
///*****************************************************************************
// * Microchip Graphics Library Demo Application
// * This program shows how to use the Graphics Objects Layer.
// *****************************************************************************
// * FileName:        MainDemo.c
// * Dependencies:    MainDemo.h
// * Processor:       PIC24F, PIC24H, dsPIC, PIC32
// * Compiler:       	MPLAB C30 V3.00, MPLAB C32
// * Linker:          MPLAB LINK30, MPLAB LINK32
// * Company:         Microchip Technology Incorporated
// *
// * Software License Agreement
// *
// * Copyright (c) 2008 Microchip Technology Inc.  All rights reserved.
// * Microchip licenses to you the right to use, modify, copy and distribute
// * Software only when embedded on a Microchip microcontroller or digital
// * signal controller, which is integrated into your product or third party
// * product (pursuant to the sublicense terms in the accompanying license
// * agreement).
// *
// * You should refer to the license agreement accompanying this Software
// * for additional information regarding your rights and obligations.
// *
// * SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
// * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY
// * OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR
// * PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR
// * OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,
// * BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT
// * DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL,
// * INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA,
// * COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY
// * CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
// * OR OTHER SIMILAR COSTS.
// *
// * Date         Comment
// *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// * 30/05/07	    ...
// * 09/20/07     Round buttons demo screen is added
// * 10/05/07     Modified navigation, added Meter, Dial,
// *				RTCC demos
// * 01/11/08     Added Chinese font
// * 02/07/08     PIC32 support
// * 06/25/09     dsPIC & PIC24H support
// * 06/29/09	    Added demo that shows buttons with
// *				multi-line text. See CreateCheckBoxes() demo.
// * 04/06/11     - Modified to use Graphics Library Version 3.00
// *              - Fixed Slider Demo to render primitives on the GOLDrawCallback()
// *****************************************************************************/
//#include "Main.h"
//#include "ChineseFontsfontref.h"
//#include "TimeDelay.h"
//
//// Configuration bits
//#if defined(__dsPIC33F__) || defined(__PIC24H__)
//_FOSCSEL(FNOSC_PRI);
//_FOSC(FCKSM_CSECMD &OSCIOFNC_OFF &POSCMD_XT);
//_FWDT(FWDTEN_OFF);
//#elif defined(__dsPIC33E__) || defined(__PIC24E__)
//_FOSCSEL(FNOSC_FRC);
//_FOSC(FCKSM_CSECMD & POSCMD_XT & OSCIOFNC_OFF & IOL1WAY_OFF);
//_FWDT(FWDTEN_OFF);
//_FPOR(FPWRT_PWR128 & BOREN_ON & ALTI2C1_ON & ALTI2C2_ON);
//_FICD(ICS_PGD1 & RSTPRI_PF & JTAGEN_OFF);
//#elif defined(__PIC32MX__)
//   #if defined(__32MX250F128D__)
//    #pragma config FPLLODIV = DIV_2, FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FWDTEN = OFF, FCKSM = CSECME, FPBDIV = DIV_1
//    #pragma config OSCIOFNC = OFF, POSCMOD = XT, FSOSCEN = OFF, FNOSC = PRIPLL
//    #pragma config CP = OFF, BWP = OFF, PWP = OFF
//   #else
//    #pragma config FPLLODIV = DIV_2, FPLLMUL = MUL_20, FPLLIDIV = DIV_1, FWDTEN = OFF, FCKSM = CSECME, FPBDIV = DIV_1
//    #pragma config OSCIOFNC = ON, POSCMOD = XT, FSOSCEN = ON, FNOSC = PRIPLL
//    #pragma config CP = OFF, BWP = OFF, PWP = OFF
//   #endif
//#else
//    #if defined(__PIC24FJ256GB110__)
//_CONFIG1(JTAGEN_OFF & GCP_OFF & GWRP_OFF & FWDTEN_OFF & ICS_PGx2)
//_CONFIG2(0xF7FF & IESO_OFF & FCKSM_CSDCMD & OSCIOFNC_OFF & POSCMOD_XT & FNOSC_PRIPLL & PLLDIV_DIV2 & IOL1WAY_OFF)
//    #endif
//    #if defined(__PIC24FJ256GA110__)
//_CONFIG1(JTAGEN_OFF & GCP_OFF & GWRP_OFF & FWDTEN_OFF & ICS_PGx2)
//_CONFIG2(IESO_OFF & FCKSM_CSDCMD & OSCIOFNC_OFF & POSCMOD_XT & FNOSC_PRIPLL & IOL1WAY_OFF)
//    #endif
//    #if defined(__PIC24FJ128GA010__)
//_CONFIG2(FNOSC_PRIPLL & POSCMOD_XT) // Primary XT OSC with PLL
//_CONFIG1(JTAGEN_OFF & FWDTEN_OFF)   // JTAG off, watchdog timer off
//    #endif
//	#if defined (__PIC24FJ256GB210__)
//_CONFIG1( WDTPS_PS32768 & FWPSA_PR128 & ALTVREF_ALTVREDIS & WINDIS_OFF & FWDTEN_OFF & ICS_PGx2 & GWRP_OFF & GCP_OFF & JTAGEN_OFF)
//_CONFIG2( POSCMOD_XT & IOL1WAY_OFF & OSCIOFNC_OFF & OSCIOFNC_OFF & FCKSM_CSDCMD & FNOSC_PRIPLL & PLL96MHZ_ON & PLLDIV_DIV2 & IESO_OFF)
//_CONFIG3( WPFP_WPFP255 & SOSCSEL_SOSC & WUTSEL_LEG & WPDIS_WPDIS & WPCFG_WPCFGDIS & WPEND_WPENDMEM)
//	#endif
//	#if defined (__PIC24FJ256DA210__)
//_CONFIG1( WDTPS_PS32768 & FWPSA_PR128 & ALTVREF_ALTVREDIS & WINDIS_OFF & FWDTEN_OFF & ICS_PGx2 & GWRP_OFF & GCP_OFF & JTAGEN_OFF)
//_CONFIG2( POSCMOD_XT & IOL1WAY_OFF & OSCIOFNC_OFF & OSCIOFNC_OFF & FCKSM_CSDCMD & FNOSC_PRIPLL & PLL96MHZ_ON & PLLDIV_DIV2 & IESO_OFF)
//_CONFIG3( WPFP_WPFP255 & SOSCSEL_EC & WUTSEL_LEG & ALTPMP_ALTPMPEN & WPDIS_WPDIS & WPCFG_WPCFGDIS & WPEND_WPENDMEM)
//	#endif
//#endif
//
///////////////////////////////////////////////////////////////////////////////
////                              OBJECT'S IDs
///////////////////////////////////////////////////////////////////////////////
//#define ID_WINDOW1          10
//
//#define ID_BUTTON1          11
//#define ID_BUTTON2          12
//#define ID_BUTTON3          13
//#define ID_BUTTON4          14
//#define ID_BUTTON5          15
//#define ID_BUTTON6          16
//#define ID_BUTTON7          17
//
//#define ID_BUTTON_BACK      18
//#define ID_BUTTON_NEXT      19
//
//#define ID_CHECKBOX1        20
//#define ID_CHECKBOX2        21
//#define ID_CHECKBOX3        22
//#define ID_CHECKBOX4        23
//#define ID_CHECKBOX5        24
//
//#define ID_RADIOBUTTON1     30
//#define ID_RADIOBUTTON2     31
//#define ID_RADIOBUTTON3     32
//#define ID_RADIOBUTTON4     33
//#define ID_RADIOBUTTON5     34
//#define ID_RADIOBUTTON6     35
//#define ID_RADIOBUTTON7     36
//#define ID_RADIOBUTTON8     37
//
//#define ID_SLIDER1          40
//#define ID_SLIDER2          41
//#define ID_SLIDER3          42
//
//#define ID_GROUPBOX1        50
//#define ID_GROUPBOX2        51
//#define ID_STATICTEXT1      52
//#define ID_STATICTEXT2      53
//#define ID_STATICTEXT3      54
//
//#define ID_PICTURE1         55
////#define ID_STATICTEXT4      56
//
//#define ID_PROGRESSBAR1     60
//#define ID_CUSTOM1          70
//
//#define ID_LISTBOX1         80
//#define ID_LISTBOX2         81
//#define ID_LISTBOX3         82
//#define ID_EDITBOX1         83
//
//#define ID_CALL             91
//#define ID_STOPCALL         92
//#define ID_HOLD             93
//#define ID_BACKSPACE        94
//#define ID_POUND            95
//#define ID_ASTERISK         96
//#define ID_KEYPAD           100                         /* uses 100 to 110 for phone key pad demo */
//
//#define ID_ROUNDDIAL        120
//#define ID_METER1           130
//#define ID_METER2           131
//#define ID_DIGITALMETER1    132
//#define ID_DIGITALMETER2    133
//
//#define ID_BUTTONHR_P       150
//#define ID_BUTTONHR_M       151
//#define ID_BUTTONMN_P       152
//#define ID_BUTTONMN_M       153
//#define ID_BUTTONSC_P       154
//#define ID_BUTTONSC_M       155
//
//#define ID_BUTTON_DATE_UP   180
//#define ID_BUTTON_DATE_DN   181
//
//#define ID_BUTTON_MO        186
//#define ID_BUTTON_DY        187
//#define ID_BUTTON_YR        188
//#define ID_BUTTON_RET       189
//
//#define ID_EB_MONTH         200
//#define ID_EB_DAY           201
//#define ID_EB_YEAR          202
//
//#define ID_EB_HOUR          205
//#define ID_EB_MINUTE        206
//#define ID_EB_SECOND        207
//
//#define NAV_BTN_WIDTH		25
//
//#define WAIT_UNTIL_FINISH(x)    while(!x)
//
//// Language offset definitions
//#define LANG_ENGLISH    0
//#define LANG_CHINESE    1
//
//    /////////////////////////////////////////////////////////////////////////////
//    //                            LOCAL PROTOTYPES
//    /////////////////////////////////////////////////////////////////////////////
//void                        StartScreen();                                              // draws intro screen
//void                        CreatePage(XCHAR *pText);                                   // creates the navigation buttons and window for each screen
//void                        CreateButtons(void);                                        // creates buttons demo screen
//WORD                        MsgButtons(WORD objMsg, OBJ_HEADER *pObj);                  // processes messages for buttons demo screen
//void                        CreateRoundButtons(void);                                   // creates rounded buttons demo screen
//WORD                        MsgRoundButtons(WORD objMsg, OBJ_HEADER *pObj);             // processes messages for rounded buttons demo screen
//void                        CreateCheckBoxes(void);                                     // creates checkboxes demo screen
//WORD                        MsgCheckBoxes(WORD objMsg, OBJ_HEADER *pObj);               // processes messages for checkboxes demo screen
//void                        CreateRadioButtons(void);                                   // creates radio buttons demo screen
//WORD                        MsgRadioButtons(WORD objMsg, OBJ_HEADER *pObj);             // processes messages for radio buttons demo screen
//void                        CreateStaticText(void);                                     // creates static text demo screen
//WORD                        MsgStaticText(WORD objMsg, OBJ_HEADER *pObj);               // processes messages for static text demo screen
//void                        CreatePicture(void);                                        // creates picture demo screen
//WORD                        MsgPicture(WORD objMsg, OBJ_HEADER *pObj);                  // processes messages for picture demo screen
//void                        CreateSlider(void);                                         // creates slider demo screen
//void                        DrawSliderCursor(WORD color, SHORT x, SHORT y);             // draws cursor for slider demo screen
//WORD                        MsgSlider(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg);    // processes messages for slider demo screen
//void                        CreateProgressBar(void);                                    // creates progress bar demo screen
//WORD                        MsgProgressBar(WORD objMsg, OBJ_HEADER *pObj);              //  processes messages for progress bar demo screen
//void                        CreateSignature(void);                                      // creates signature demo screen
//WORD                        PanelSignature(void);                                       // draws box for the signature
//WORD                        MsgSignature(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg); // processes messages for signature demo screen
//void                        CreatePotentiometer(void);                                  // scrolling graph demo screen
//WORD                        PanelPotentiometer(void);                                   // draws box for the scrolling graph
//void                        GraphPotentiometer(void);                                   // draws scrolling graph graph
//WORD                        GetPotSamples(WORD number);                                 // adds sample from ADC potentiometer channel into temporary buffer
//
//// returns zero if samples number in the buffer is less than defined by parameter
//WORD                        MsgPotentiometer(WORD objMsg, OBJ_HEADER *pObj);            // processes messages for ECG demo screen
//void                        CreateECG(void);                                            // creates ECG demo screen
//WORD                        PanelECG(void);                                             // draws box for the ECG
//void                        GraphECG(void);                                             // draws ECG graph
//WORD                        GetECGSamples(WORD number);                                 // adds sample from FLASH (can be any source) into temporary buffer
//
//// returns zero if samples number in the buffer is less than defined by parameter
//WORD                        MsgECG(WORD objMsg, OBJ_HEADER *pObj);                      // processes messages for ECG demo screen
//void                        CreateCustomControl(void);                                  // creates custom control demo screen
//WORD                        MsgCustomControl(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg); // processes messages for custom control demo screen
//void                        CreateListBox(void);                                        // creates list box demo screen
//WORD                        MsgListBox(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg);   // processes messages for list box demo screen
//void                        CreateEditBox(void);                                        // creates edit box demo screen
//WORD                        MsgEditBox(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg);   // processes messages for edit box demo screen
//void                        CreateDateTime(void);                                       // creates date time demo screen
//WORD                        MsgDateTime(WORD objMsg, OBJ_HEADER *pObj);                 // processes messages for date and time demo screen
//void                        UpdateRTCCDates(LISTBOX *pLb);                              // update the date edit boxes
//WORD                        MsgSetDate(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg);   // processes messages for setting dates
//void                        ShowPullDownMenu(void);                                     // create objects for pull down menu and draw
//WORD                        RemovePullDownMenu(void);                                   // removes pop out pull down menu from screen
//void                        updateDateTimeEb(void);                                     // update edit boxes with current date and time values
//void                        CreateMeter(void);                                          // creates meter demo screen
//void                        UpdateMeter(void);
//WORD                        MsgMeter(WORD objMsg, OBJ_HEADER *pObj);                    // processes messages for meter demo screen
//void                        CreateDial(void);                                           // creates dial demo screen
//WORD                        MsgDial(WORD objMsg, OBJ_HEADER *pObj);                     // processes messages for dial demo screen
//void                        ErrorTrap(XCHAR *message);                                  // outputs text message on screen and stop execution
//void                        TickInit(void);                                             // starts tick counter
//void                        CreatePullDown(void);
//WORD                        MsgPullDown(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg);  // processes screen pull down menu
//void                        DisplayPullDown(void);                                      // refresh the screen when switching screen using pulldown menu
//void                        InitializeBoard(void);                                      // Initializes the hardware components including the PIC device
//
///////////////////////////////////////////////////////////////////////////////
//// SPI Device Initialization Function
///////////////////////////////////////////////////////////////////////////////
//#if defined (USE_SST25VF016)
//    // initialize GFX3 SST25 flash SPI
//    #define FlashInit(pInitData) SST25Init((DRV_SPI_INIT_DATA*)pInitData)
//#elif defined (USE_MCHP25LC256)
//    // initialize EEPROM on Explorer 16
//    #define FlashInit(pInitData) MCHP25LC256Init((DRV_SPI_INIT_DATA*)pInitData)
//#elif defined (USE_M25P80)
//    #define FlashInit(pInitData) SST25Init((DRV_SPI_INIT_DATA*)pInitData)
//#endif
//
///////////////////////////////////////////////////////////////////////////////
////                             FONTS USED
///////////////////////////////////////////////////////////////////////////////
//extern const FONT_FLASH     GOLFontDefault;                 // default GOL font
//extern const FONT_FLASH     GOLSmallFont;                   // small font
//extern const FONT_FLASH     monofont;                       // equal width font
//
//	   const FONT_FLASH     *ptrLargeAsianFont = &GOLFontDefault;
//	   const FONT_FLASH     *ptrSmallAsianFont = &GOLSmallFont;
//
///////////////////////////////////////////////////////////////////////////////
////                            COLORS USED
///////////////////////////////////////////////////////////////////////////////
//#define GRAY20      RGBConvert(51, 51, 51)
//#define RED4        RGBConvert(139, 0, 0)
//#define FIREBRICK1  RGBConvert(255, 48, 48)
//#define DARKGREEN   RGBConvert(0, 100, 0)
//#define PALEGREEN   RGBConvert(152, 251, 152)
//
///////////////////////////////////////////////////////////////////////////////
////                            DEMO STATES
///////////////////////////////////////////////////////////////////////////////
//typedef enum
//{
//    CREATE_BUTTONS          = 0,
//    DISPLAY_BUTTONS,
//    CREATE_CHECKBOXES,
//    DISPLAY_CHECKBOXES,
//    CREATE_RADIOBUTTONS,
//    DISPLAY_RADIOBUTTONS,
//    CREATE_STATICTEXT,
//    DISPLAY_STATICTEXT,
//    CREATE_PICTURE,
//    DISPLAY_PICTURE,
//    CREATE_SLIDER,
//    DISPLAY_SLIDER,
//    CURSOR_DRAW_SLIDER,
//    CREATE_PROGRESSBAR,
//    DISPLAY_PROGRESSBAR,
//    CREATE_LISTBOX,
//    DISPLAY_LISTBOX,
//    CREATE_EDITBOX,
//    DISPLAY_EDITBOX,
//    CREATE_METER,
//    DISPLAY_METER,
//    CREATE_DIAL,
//    DISPLAY_DIAL,
//    CREATE_CUSTOMCONTROL,
//    DISPLAY_CUSTOMCONTROL,
//    CREATE_SIGNATURE,
//    DISPLAY_SIGNATURE,
//    BOX_DRAW_SIGNATURE,
//    CREATE_POT,
//    DISPLAY_POT,
//    BOX_DRAW_POT,
//    CREATE_ECG,
//    DISPLAY_ECG,
//    BOX_DRAW_ECG,
//    CREATE_PULLDOWN,
//    DISPLAY_PULLDOWN,
//
//    // these states are for time and date settings 0xF3xx is used here as a
//    // state ID to check when date and time are to be updated or not.
//    CREATE_DATETIME         = 0xF300,                       // creates the date and time setting menu
//    DISPLAY_DATETIME        = 0xF301,                       // displays the menu for the date and time setting
//    DISPLAY_DATE_PDMENU     = 0xF302,                       // displays the pulldown menu to set one of the date items (month, day or year)
//    SHOW_DATE_PDMENU        = 0xF303,                       // creates the pulldown menu to set one of the date items (month, day or year)
//    HIDE_DATE_PDMENU        = 0xF304,                       // hides the pulldown menu to set one of the date items (month, day or year)
//} SCREEN_STATES;
//
///////////////////////////////////////////////////////////////////////////////
////                       GLOBAL VARIABLES FOR DEMO
///////////////////////////////////////////////////////////////////////////////
//SCREEN_STATES   screenState = CREATE_BUTTONS;               // current state of main demo state mashine
//GOL_SCHEME      *altScheme;                                 // alternative style scheme
//GOL_SCHEME      *alt2Scheme;                                // alternative 2 style scheme
//GOL_SCHEME      *alt3Scheme;                                // alternative 3 style scheme
//GOL_SCHEME      *alt4Scheme;                                // alternative 4 style scheme
//GOL_SCHEME      *alt5Scheme;                                // alternative 5 style scheme
//GOL_SCHEME      *timeScheme;
//GOL_SCHEME      *meterScheme;                               // meter scheme
//GOL_SCHEME      *navScheme;                                 // style scheme for the navigation
//GOL_SCHEME      *redScheme;                                 // alternative red style scheme
//GOL_SCHEME      *greenScheme;                               // alternative green style scheme
//GOL_SCHEME      *yellowScheme;                              // alternative yellow style scheme
//OBJ_HEADER      *pNavList;                                  // pointer to navigation list
//volatile DWORD  tick = 0;                                   // tick counter
//char            animate;                                    // switch to control animation for picture demo
//OBJ_HEADER      *pGenObj;                                   // pointer to a general purpose object
//PICTURE         *pPicture;                                  // pointer to picture object for picture demo
//PROGRESSBAR     *pProgressBar;                              // pointer to progress bar object for progress bar demo
//SLIDER          *pSlider;                                   // pointer to the slider controlling the animation speed
//
//// DEFINITIONS FOR CUSTOM CONTROL DEMO
//#define CC_ORIGIN_X ((GetMaxX() - 180 + 1) / 2)
//#define CC_ORIGIN_Y ((40 + GetMaxY() - 175 + 1) / 2)
//
//// GLOBAL DEFINITIONS AND VARIABLES FOR SLIDER DEMO
//#define SLD_ORIGIN_X    ((GetMaxX() - 260 + 1) / 2)
//#define SLD_ORIGIN_Y    ((40 + GetMaxY() - 180 + 1) / 2)
//#define CUR_BAR_SIZE    3                                   // half size of center point for cursor
//#define CUR_BRD_LEFT    SLD_ORIGIN_X + 37 + CUR_BAR_SIZE    // cursor area left border
//#define CUR_BRD_RIGHT   SLD_ORIGIN_X + 223 - CUR_BAR_SIZE   // cursor area right border
//#define CUR_BRD_TOP     SLD_ORIGIN_Y + 2 + CUR_BAR_SIZE     // cursor area top border
//#define CUR_BRD_BOTTOM  SLD_ORIGIN_Y + 134 - CUR_BAR_SIZE   // cursor area bottom border
//SHORT           x, prevX;                                   // cursor X position
//SHORT           y, prevY;                                   // cursor Y position
//WORD            cursorUpdate;                               // update the cursor position if set
//// GLOBAL DEFINITIONS AND VARIABLES FOR ECG DEMO
//// Array of ECG points to emulate ECG input
//const SHORT ecgPoints[] ={
//    0x0068,0x0068,0x0068,0x0068,0x0068,0x0069,0x0068,0x0068,0x0068,0x0067,0x0067,0x0066,0x0066,0x0068,0x0068,0x0068,0x0067,0x0066,0x0066,0x0066,0x0066,0x0065,0x0065,0x0065,0x0065,0x0065,0x0065,0x0064,0x0063,0x0063,0x0063,0x0064,
//    0x0064,0x0065,0x0065,0x0064,0x0064,0x0064,0x0064,0x0065,0x0066,0x0066,0x0062,0x0061,0x0060,0x0059,0x0055,0x004a,0x0049,0x0047,0x0047,0x0048,0x004a,0x004f,0x0053,0x0056,0x005c,0x005d,0x0060,0x0061,0x0062,0x0064,0x0064,0x0064,
//    0x0065,0x0066,0x0067,0x0068,0x0068,0x0069,0x0070,0x0070,0x0055,0x0030,0x0004,0x0028,0x005d,0x006c,0x0069,0x0069,0x0069,0x0069,0x0068,0x0067,0x0065,0x0063,0x0061,0x005e,0x005e,0x0062,0x0064,0x0066,0x0067,0x0068,0x0068,0x006a
//};
//
//// Scanning window size
//#define ECG_WINDOW_SIZE 8
//
//// ECG data circular buffer size
//#define ECG_BUFFER_SIZE 256
//
//// ECG data circular buffer
//SHORT   ecgBuffer[ECG_BUFFER_SIZE];
//
//// GLOBAL DEFINITIONS AND VARIABLES FOR PLOTTING POTENTIOMETER DEMO
//// Graph shift
//#define POT_MOVE_DELTA  2
//
//// Potentiometer circular buffer size
//#define POT_BUFFER_SIZE 320
//
//// Potentiometer data circular buffer
//SHORT           potBuffer[POT_BUFFER_SIZE];
//
//// Temporary buffer for graph demo screens
//SHORT           tempBuffer[10];
//
//// Variables for the pulldown menus
//SHORT           pDwnLeft, pDwnTop, pDwnRight, pDwnBottom;
//
//// Variables for date and time
//SCREEN_STATES   prevState = CREATE_BUTTONS; // used to mark state where time setting was called
//SCREEN_STATES   prevRefreshState = CREATE_BUTTONS; // used to mark the start of the previous screen
//
//OBJ_HEADER      *pListSaved;                // temporary storage for object list
//WORD            DateItemID;                 // ID of date item being modified (ID_EB_MONTH(DAY)(YEAR))
//XCHAR           dateTimeStr[26];            // string variable for date and time display
//SHORT           List2Enable = 0, refreshScreen = 0;
//
//BYTE            PulldownId = 0;
//
///////////////////////////////////////////////////////////////////////////////
//// SPI Channel settings
///////////////////////////////////////////////////////////////////////////////
//#if defined SPI_CHANNEL_2_ENABLE || defined SPI_CHANNEL_1_ENABLE || defined SPI_CHANNEL_3_ENABLE || defined SPI_CHANNEL_4_ENABLE
//    #if defined (USE_SST25VF016)
//        #ifdef __PIC32MX
//            const DRV_SPI_INIT_DATA SPI_Init_Data = {SST25_SPI_CHANNEL, 1, 0, 0, 1, 1, 0};
//        #else
//            const DRV_SPI_INIT_DATA SPI_Init_Data = {SST25_SPI_CHANNEL, 3, 6, 0, 1, 1, 0};
//        #endif
//    #elif defined (USE_MCHP25LC256)
//        const DRV_SPI_INIT_DATA SPI_Init_Data = {MCHP25LC256_SPI_CHANNEL, 6, 3, 0, 1, 1, 0};
//    #elif defined (USE_M25P80)
//            const DRV_SPI_INIT_DATA SPI_Init_Data = {SST25_SPI_CHANNEL, 3, 6, 0, 1, 1, 0};
//    #endif
//#endif
//
//#define WAIT_UNTIL_FINISH(x)    while(!x)
//#define MIN(x,y)                ((x > y)? y: x)
//#define DEMODELAY				1000
//
//WORD ADCValue = 0xFFFF;
//
//void TouchTest(){
//
//      ResistiveTouchScreen_YMinus_Config_As_Output();
//      ResistiveTouchScreen_YPlus_Config_As_Output();
//
//      ResistiveTouchScreen_YPlus_Drive_High();
//      ResistiveTouchScreen_YMinus_Drive_Low();
//
//      ResistiveTouchScreen_XPlus_Config_As_Input();
//
//      ADPCFG_XPOS = 0;
//
//      AD1CON1 = 0x00E0;
//      AD1CHS = 0x000B0000;
//
//      AD1CSSL = 0;
//      AD1CON3 = 0x1F02;     // Sample time = 31 TAD
//      AD1CON2 = 0;
//
//      AD1CON1SET = 0x8000;  // turn ON the ADC
//      while (1)             // repeat continuously
//      {
//          AD1CON1SET = 0x8002;  // turn ON the ADC
//          //DelayMs(10);
//          AD1CON1CLR = 0x0002;              // start sampling then...
//                                            // after 31Tad go to conversion
//          while (!(AD1CON1 & 0x0001));      // conversion done?
//          ADCValue = ADC1BUF0;              // yes then get ADC value
//      }                                     // repeat
//
//}
///////////////////////////////////////////////////////////////////////////////
//
////                                  MAIN
///////////////////////////////////////////////////////////////////////////////
//int main(void)
//{
//    GOL_MSG msg;                        // GOL message structure to interact with GOL
//
//    TouchHardwareInit(NULL);
//    DelayMs(2);
//
////    while(1){
////        //TouchDetectPosition();
////        TouchTest();
////    }
//    InitializeBoard();
//
///*    while(1){
//   SetColor(BRIGHTRED);
//   WAIT_UNTIL_FINISH(Line(0,0,GetMaxX(),0));
//    }*/
//    StartScreen();                      // Show intro screen and wait for touch
//
//    // create the alternate schemes
//    navScheme = GOLCreateScheme();      // alternative scheme for the navigate buttons
//    altScheme = GOLCreateScheme();      // create alternative 1 style scheme
//    alt2Scheme = GOLCreateScheme();     // create alternative 2 style scheme
//    alt3Scheme = GOLCreateScheme();     // create alternative 3 style scheme
//    alt4Scheme = GOLCreateScheme();     // create alternative 4 style scheme
//    alt5Scheme = GOLCreateScheme();     // create alternative 5 style scheme
//    timeScheme = GOLCreateScheme();
//    meterScheme = GOLCreateScheme();    // create meter scheme
//    redScheme = GOLCreateScheme();      // create red style scheme
//    greenScheme = GOLCreateScheme();    // create green style scheme
//    yellowScheme = GOLCreateScheme();   // create yellow style scheme
//
//    /* for Truly display */
//    altScheme->Color0 = RGBConvert(0x4C, 0x8E, 0xFF);
//    altScheme->Color1 = RGBConvert(255, 102, 0);
//    altScheme->EmbossDkColor = RGBConvert(0x1E, 0x00, 0xE5);
//    altScheme->EmbossLtColor = RGBConvert(0xA9, 0xDB, 0xEF);
//    altScheme->ColorDisabled = RGBConvert(0xD4, 0xE1, 0xF7);
//    altScheme->TextColor1 = BRIGHTBLUE;
//    altScheme->TextColor0 = RGBConvert(255, 102, 0);
//    altScheme->TextColorDisabled = RGBConvert(0xB8, 0xB9, 0xBC);
//
//    altScheme->pFont = (void *)ptrLargeAsianFont;
//    navScheme->pFont = (void *)ptrLargeAsianFont;
//
//    alt2Scheme->TextColor1 = BRIGHTRED;
//    alt2Scheme->TextColor0 = BRIGHTBLUE;
//    alt2Scheme->pFont = (void *)ptrSmallAsianFont;
//
//    alt3Scheme->Color0 = LIGHTBLUE;
//    alt3Scheme->Color1 = BRIGHTGREEN;
//    alt3Scheme->TextColor0 = BLACK;
//    alt3Scheme->TextColor1 = WHITE;
//    alt3Scheme->pFont = (void *)ptrSmallAsianFont;
//
//    alt4Scheme->Color0 = LIGHTBLUE;
//    alt4Scheme->Color1 = BRIGHTGREEN;
//    alt4Scheme->TextColor0 = BLACK;
//    alt4Scheme->TextColor1 = WHITE;
//    alt4Scheme->pFont = (void *)ptrSmallAsianFont;
//
//    alt5Scheme->Color0 = LIGHTBLUE;
//    alt5Scheme->Color1 = BRIGHTRED;
//    alt5Scheme->TextColor0 = BLACK;
//    alt5Scheme->TextColor1 = WHITE;
//    alt5Scheme->pFont = (void *) &monofont; //monofont is equal width font, required for digitalmeter widget
//
//    redScheme->Color0 = RGBConvert(0xCC, 0x00, 0x00);
//    redScheme->Color1 = BRIGHTRED;
//    redScheme->EmbossDkColor = RED4;
//    redScheme->EmbossLtColor = FIREBRICK1;
//    redScheme->TextColor0 = RGBConvert(0xC8, 0xD5, 0x85);
//    redScheme->TextColor1 = BLACK;
//    redScheme->pFont = (void *)ptrLargeAsianFont;
//
//    greenScheme->Color0 = RGBConvert(0x23, 0x9E, 0x0A);
//    greenScheme->Color1 = BRIGHTGREEN;
//    greenScheme->EmbossDkColor = DARKGREEN;
//    greenScheme->EmbossLtColor = PALEGREEN;
//    greenScheme->TextColor0 = RGBConvert(0xDF, 0xAC, 0x83);
//    greenScheme->TextColor1 = BLACK;
//    greenScheme->pFont = (void *)ptrLargeAsianFont;
//
//    yellowScheme->Color0 = BRIGHTYELLOW;
//    yellowScheme->Color1 = YELLOW;
//    yellowScheme->EmbossDkColor = RGBConvert(0xFF, 0x94, 0x4C);
//    yellowScheme->EmbossLtColor = RGBConvert(0xFD, 0xFF, 0xB2);
//    yellowScheme->TextColor0 = RGBConvert(0xAF, 0x34, 0xF3);
//    yellowScheme->TextColor1 = RED;
//    yellowScheme->pFont = (void *)ptrLargeAsianFont;
//
//    timeScheme->Color0 = BLACK;
//    timeScheme->Color1 = WHITE;
//    timeScheme->TextColor0 = BRIGHTBLUE;
//    timeScheme->TextColor1 = WHITE;
//    timeScheme->EmbossDkColor = GRAY20;
//    timeScheme->EmbossLtColor = GRAY80;
//    timeScheme->pFont = (void *) &GOLSmallFont;
//
//    meterScheme->Color0 = BLACK;
//    meterScheme->Color1 = WHITE;
//    meterScheme->TextColor0 = BRIGHTBLUE;
//    meterScheme->TextColor1 = WHITE;
//    meterScheme->EmbossDkColor = GRAY20;
//    meterScheme->EmbossLtColor = GRAY80;
//    meterScheme->pFont = (void *)ptrSmallAsianFont;
//
//    while(1)
//    {
//        if(GOLDraw())
//        {                               // Draw GOL objects
//            // Drawing is done here, process messages
//            TouchGetMsg(&msg);          // Get message from touch screen
//            GOLMsg(&msg);               // Process message
//#if defined (USE_FOCUS)
//            #if !(defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__)||defined(GFX_PICTAIL_LCC)||defined(__32MX250F128D__))
//            SideButtonsMsg(&msg);       // Get message from side buttons
//            GOLMsg(&msg);               // Process message
//            #endif
//#endif //#if defined (USE_FOCUS)
//        }
//    }
//}
//
///////////////////////////////////////////////////////////////////////////////
//// Function: WORD GOLMsgCallback(WORD objMsg, OBJ_HEADER* pObj, GOL_MSG* pMsg)
//// Input: objMsg - translated message for the object,
////        pObj - pointer to the object,
////        pMsg - pointer to the non-translated, raw GOL message
//// Output: if the function returns non-zero the message will be processed by default
//// Overview: this function must be implemented by user. GOLMsg() function calls it each
////           time the valid message for the object received
///////////////////////////////////////////////////////////////////////////////
//WORD GOLMsgCallback(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg)
//{
//
//    // beep if button is pressed
//    if(objMsg == BTN_MSG_PRESSED)
//    {
//        Beep();
//    }
//    else
//    {
//        if(GetObjType(pObj) == OBJ_RADIOBUTTON)
//        {
//            Beep();
//
//            if(pObj->ID == ID_RADIOBUTTON5)
//            {
//                _language = LANG_ENGLISH;
//                screenState = prevRefreshState ; //Goto CREATE_XXX state
//                return(1);
//            }
//            else if(pObj->ID == ID_RADIOBUTTON6)
//            {
//                _language = LANG_CHINESE;
//                screenState = prevRefreshState ; //Goto CREATE_XXX state
//                return(1);
//            }
//        }
//        else
//        {
//            if(GetObjType(pObj) == OBJ_CHECKBOX)
//                Beep();
//        }
//    }
//
//    if((screenState & 0xF300) != 0xF300)
//    {
//
//        // check for time setting press, process only when not setting time and date
//        if(objMsg == ST_MSG_SELECTED)
//        {
//
//            /* note how the states are arranged in the enumeration, the display state is
//		       right after the create state. So at the time the static text box of the
//		       time is selected, the state is in one of the displays. So a minus one is needed
//		       to adjust to go back to the create state of the current page.
//		       After the date and time adjust screen is exited, the saved create state will
//		       be entered as the next state. So we get the effect of going back to the previous
//		       screen after date and time settings are done.
//		    */
//            if((GetObjID(pObj) == ID_STATICTEXT1) || (GetObjID(pObj) == ID_STATICTEXT2))
//            {
//                prevState = screenState - 1;        // save the current create state
//                screenState = CREATE_DATETIME;      // go to date and time setting screen
//                return (1);
//            }
//        }
//    }
//
//    // check if pull down menu is called
//    if(GetObjID(pObj) == ID_WINDOW1)
//    {
//        if((objMsg == WND_MSG_TITLE) && (screenState != DISPLAY_PULLDOWN))
//        {
//
//            // check area of press
//            if((pMsg->param1 <= 220) && (pMsg->param2 <= 40))
//            {
//                switch(screenState)
//                {
//
//                    // if one of these states we redraw the whole screen since
//                    // these screens have customized graphics.
//                    case DISPLAY_SLIDER:
//                        prevState = CREATE_SLIDER;
//                        break;
//
//                    case DISPLAY_CUSTOMCONTROL:
//                        prevState = CREATE_CUSTOMCONTROL;
//                        break;
//
//                    case DISPLAY_SIGNATURE:
//                        prevState = CREATE_SIGNATURE;
//                        break;
//
//                    case DISPLAY_POT:
//                        prevState = CREATE_POT;
//                        break;
//
//                    case DISPLAY_ECG:
//                        prevState = CREATE_ECG;
//                        break;
//
//                    case DISPLAY_PROGRESSBAR:
//                        prevState = CREATE_PROGRESSBAR;
//                        break;
//
//                    // pull down is disabled when setting date and time
//                    case CREATE_DATETIME:
//                    case DISPLAY_DATETIME:
//                    case DISPLAY_DATE_PDMENU:
//                    case SHOW_DATE_PDMENU:
//                    case HIDE_DATE_PDMENU:
//                        return (0);
//
//                    default:
//                        prevState = screenState;    // save the current create state
//                        break;
//                }
//
//                screenState = CREATE_PULLDOWN;      // go to show pulldown menu state
//
//                if(pMsg->param1 <= 136)
//                {
//                    PulldownId = 0;
//                }
//                else
//                {
//                    //PulldownId = 1;
//                }
//
//                return (1);
//            }
//        }
//    }
//
//    // process messages for demo screens
//    switch(screenState)
//    {
//        case DISPLAY_BUTTONS:
//            return (MsgButtons(objMsg, pObj));
//
//        case DISPLAY_CHECKBOXES:
//            return (MsgCheckBoxes(objMsg, pObj));
//
//        case DISPLAY_RADIOBUTTONS:
//            return (MsgRadioButtons(objMsg, pObj));
//
//        case DISPLAY_STATICTEXT:
//            return (MsgStaticText(objMsg, pObj));
//
//        case DISPLAY_PICTURE:
//            return (MsgPicture(objMsg, pObj));
//
//        case DISPLAY_SLIDER:
//            return (MsgSlider(objMsg, pObj, pMsg));
//
//        case DISPLAY_PROGRESSBAR:
//            return (MsgProgressBar(objMsg, pObj));
//
//        // date and time settings display
//        case DISPLAY_DATETIME:
//            return (MsgDateTime(objMsg, pObj));
//
//        case DISPLAY_DATE_PDMENU:
//            return (MsgSetDate(objMsg, pObj, pMsg));
//
//        case CREATE_DATETIME:
//        case SHOW_DATE_PDMENU:
//        case HIDE_DATE_PDMENU:
//            return (0);
//
//        case DISPLAY_METER:
//            return (MsgMeter(objMsg, pObj));
//
//        case DISPLAY_DIAL:
//            return (MsgDial(objMsg, pObj));
//
//        case DISPLAY_CUSTOMCONTROL:
//            return (MsgCustomControl(objMsg, pObj, pMsg));
//
//        case DISPLAY_LISTBOX:
//            return (MsgListBox(objMsg, pObj, pMsg));
//
//        case DISPLAY_EDITBOX:
//            return (MsgEditBox(objMsg, pObj, pMsg));
//
//        case DISPLAY_SIGNATURE:
//            return (MsgSignature(objMsg, pObj, pMsg));
//
//        case DISPLAY_POT:
//            return (MsgPotentiometer(objMsg, pObj));
//
//        case DISPLAY_ECG:
//            return (MsgECG(objMsg, pObj));
//
//        case DISPLAY_PULLDOWN:
//            return (MsgPullDown(objMsg, pObj, pMsg));
//
//        default:
//
//            // process message by default
//            return (1);
//    }
//}
//
///////////////////////////////////////////////////////////////////////////////
//// Function: WORD GOLDrawCallback()
//// Output: if the function returns non-zero the draw control will be passed to GOL
//// Overview: this function must be implemented by user. GOLDraw() function calls it each
////           time when GOL objects drawing is completed. User drawing should be done here.
////           GOL will not change color, line type and clipping region settings while
////           this function returns zero.
///////////////////////////////////////////////////////////////////////////////
//WORD GOLDrawCallback(void)
//{
//    static DWORD    prevTick = 0;                           // keeps previous value of tick
//    static BYTE     direction = 1;                          // direction switch for progress bar
//    static BYTE     arrowPos = 0;                           // arrows pictures position for custom control demo
//    static WORD     wDelay = 40;                           // progress bar delay variable
//    OBJ_HEADER      *pObj = NULL;                           // used to change text in Window
//    SLIDER          *pSld;                                  // used when updating date and time
//    LISTBOX         *pLb;                                   // used when updating date and time
//
//    #if !(defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__)||defined(GFX_PICTAIL_LCC)||defined(__32MX250F128D__))
//
//    static DWORD    prevTime = 0;                           // keeps previous value of time tick
//    WORD            i;
//
//	// check first of the objects for the time display is already created.
//	if (GOLFindObject(ID_STATICTEXT1) != NULL) {
//	    // update the time display
//	    if((screenState & 0x0000F300) != 0x0000F300)
//	    {                                                       // process only when NOT setting time and date
//	        if((tick - prevTime) > 1000)
//	        {
//	            RTCCProcessEvents();                            // update the date and time string variabes
//	            i = 0;
//	            while(i < 12)
//	            {
//	                dateTimeStr[i] = _time_str[i];
//	                dateTimeStr[i + 13] = _date_str[i];
//	                i++;
//	            }
//
//	            dateTimeStr[12] = 0x000A;                       // (XCHAR)'\n';
//	            dateTimeStr[25] = 0x0000;                       // (XCHAR)'\0';
//	            if((pObj = GOLFindObject(ID_STATICTEXT1)))
//	            {                                               // get the time display obj pointer
//	                StSetText((STATICTEXT *)pObj, dateTimeStr); // now display the new date & time
//	                SetState(pObj, ST_DRAW);                    // redraw the time display
//	            }
//
//	            prevTime = tick;                                // reset tick timer
//	        }
//	    }
//	    else
//	    {                               // process only when setting time and date
//	        if((screenState != DISPLAY_DATE_PDMENU) && (screenState != HIDE_DATE_PDMENU))
//	        {
//	            if((tick - prevTime) > 1000)
//	            {
//	                updateDateTimeEb(); // update edit boxes for date and time settings
//	                prevTime = tick;    // reset tick timer
//	            }
//	        }
//	    }
// 	}
//
//    #endif
//
//    #ifdef USE_DOUBLE_BUFFERING
//    switch(screenState)
//    {
//
//        case CREATE_BUTTONS:
//        case CREATE_CHECKBOXES:
//        case CREATE_RADIOBUTTONS:
//        case CREATE_STATICTEXT:
//        case CREATE_PICTURE:
//        case CREATE_SLIDER:
//        case CREATE_PROGRESSBAR:
//        case CREATE_LISTBOX:
//        case CREATE_EDITBOX:
//        case CREATE_METER:
//        case CREATE_DIAL:
//        case CREATE_DATETIME:
//                                    SwitchOnDoubleBuffering();
//                                    break;
//        case CREATE_CUSTOMCONTROL:
//        case CREATE_SIGNATURE:
//        case CREATE_POT:
//        case CREATE_ECG:
//                                    SwitchOffDoubleBuffering();
//                                    break;
//        default:                    break;
//    }
//    #endif
//
//    switch(screenState)
//    {
//        case CREATE_BUTTONS:
//            prevRefreshState = CREATE_BUTTONS;
//            CreateButtons();        // create window and buttons
//            screenState = DISPLAY_BUTTONS;                              // switch to next state
//            return (1);                                                 // draw objects created
//
//        case DISPLAY_BUTTONS:
//            return (1);                                                 // redraw objects if needed
//
//        case CREATE_CHECKBOXES:
//            prevRefreshState = CREATE_CHECKBOXES;
//            CreateCheckBoxes();                                         // create window and check boxes
//            screenState = DISPLAY_CHECKBOXES;                           // switch to next state
//            return (1);                                                 // draw objects created
//
//        case DISPLAY_CHECKBOXES:
//            return (1);                                                 // redraw objects if needed
//
//        case CREATE_RADIOBUTTONS:
//            prevRefreshState = CREATE_RADIOBUTTONS;
//            CreateRadioButtons();                                       // create window and radio buttons
//            screenState = DISPLAY_RADIOBUTTONS;                         // switch to next state
//            return (1);                                                 // draw objects created
//
//        case DISPLAY_RADIOBUTTONS:
//            return (1);                                                 // redraw objects if needed
//
//        case CREATE_STATICTEXT:
//            prevRefreshState = CREATE_STATICTEXT;
//            CreateStaticText();                                         // create window, group box, static text
//            // and radio buttons for control
//            screenState = DISPLAY_STATICTEXT;                           // switch to next state
//            return (1);                                                 // draw objects created
//
//        case DISPLAY_STATICTEXT:
//            if((tick - prevTick) > 40000)
//            {
//                pObj = GOLFindObject(ID_WINDOW1);
//                if(direction)
//                {
//                    WndSetText((WINDOW *)pObj, (XCHAR *)GroupBoxStr);   // "Group Box");
//                    direction = 0;
//                }
//                else
//                {
//                    WndSetText((WINDOW *)pObj, (XCHAR *)StaticTextStr); // "Static text");
//                    direction = 1;
//                }
//
//                // redraw the whole screen
//                GOLRedrawRec(0, 0, GetMaxX(), GetMaxY());
//
//                prevTick = tick;
//            }
//
//            return (1);                         // redraw objects if needed
//
//        case CREATE_SLIDER:
//            prevRefreshState = CREATE_SLIDER;
//            cursorUpdate = 1;
//            CreateSlider();                     // create window and sliders
//            screenState = CURSOR_DRAW_SLIDER;   // switch to next state
//            return (1);                         // draw objects created
//
//        case CURSOR_DRAW_SLIDER:
//            DrawSliderCursor(BLACK, x, y);              // draw sliders position cursor
//            prevX = x;
//            prevY = y;
//            screenState = DISPLAY_SLIDER;       // switch to next state
//
//        case DISPLAY_SLIDER:
//            if (cursorUpdate)
//            {
//                // hide previous position
//                DrawSliderCursor(altScheme->CommonBkColor, prevX, prevY);      // draw sliders position cursor
//                // draw new position
//                DrawSliderCursor(BLACK, x, y);              // draw sliders position cursor
//                prevX = x;
//                prevY = y;
//                cursorUpdate = 0;
//            }
//            return (1);                         // redraw objects if needed
//
//        case CREATE_PROGRESSBAR:
//            prevRefreshState = CREATE_PROGRESSBAR;
//            CreateProgressBar();                // create window and progress bar
//            screenState = DISPLAY_PROGRESSBAR;  // switch to next state
//            return (1);                         // draw objects created
//
//        case DISPLAY_PROGRESSBAR:
//            if(GetState(pGenObj, BTN_PRESSED))
//                wDelay = 0;
//            else
//                wDelay = 400;
//
//            if((tick - prevTick) > wDelay)
//            {
//                if(direction)
//                {
//                    if(pProgressBar->pos == pProgressBar->range)
//                        direction = 0;          // change direction
//                    else
//                        PbSetPos(pProgressBar, PbGetPos(pProgressBar) + 1); // increase
//                }
//                else
//                {
//                    if(pProgressBar->pos == 0)
//                        direction = 1;  // change direction
//                    else
//                        PbSetPos(pProgressBar, PbGetPos(pProgressBar) - 1); // decrease
//                }
//
//                SetState(pProgressBar, PB_DRAW_BAR);                        // redraw bar only
//                prevTick = tick;
//            }
//
//            return (1);                         // redraw objects if needed
//
//        case CREATE_EDITBOX:
//            prevRefreshState = CREATE_EDITBOX;
//            CreateEditBox();                    // create edit box test screen
//            screenState = DISPLAY_EDITBOX;      // switch to next state
//            return (1);                         // draw objects created
//
//        case DISPLAY_EDITBOX:
//            return (1);                         // draw objects
//
//        case CREATE_LISTBOX:
//            prevRefreshState = CREATE_LISTBOX;
//            CreateListBox();                    // create list box test screen
//            screenState = DISPLAY_LISTBOX;      // switch to next state
//            return (1);                         // draw objects created
//
//        case DISPLAY_LISTBOX:
//
//            // this moves the slider and editbox for the date setting to
//            // move while the up or down arrow buttons are pressed
//            if((tick - prevTick) > 5000)
//            {
//                pLb = (LISTBOX *)GOLFindObject(ID_LISTBOX1);
//                pSld = (SLIDER *)GOLFindObject(ID_SLIDER1);
//                pObj = GOLFindObject(ID_BUTTON1);
//
//                if(GetState(pObj, BTN_PRESSED))
//                {
//                    LbSetFocusedItem(pLb, LbGetFocusedItem(pLb) - 1);
//                    SetState(pLb, LB_DRAW_ITEMS);
//                    SldSetPos(pSld, SldGetPos(pSld) + 1);
//                    SetState(pSld, SLD_DRAW_THUMB);
//                }
//
//                pObj = GOLFindObject(ID_BUTTON2);
//
//                if(GetState(pObj, BTN_PRESSED))
//                {
//                    LbSetFocusedItem(pLb, LbGetFocusedItem(pLb) + 1);
//                    SetState(pLb, LB_DRAW_ITEMS);
//                    SldSetPos(pSld, SldGetPos(pSld) - 1);
//                    SetState(pSld, SLD_DRAW_THUMB);
//                }
//
//                prevTick = tick;
//            }
//
//            return (1);                         // draw objects
//
//        case CREATE_DATETIME:
//            CreateDateTime();                   // create date and time demo
//            screenState = DISPLAY_DATETIME;     // switch to next state
//            return (1);                         // draw objects created
//
//        case SHOW_DATE_PDMENU:
//            ShowPullDownMenu();
//            screenState = DISPLAY_DATE_PDMENU;
//            return (1);
//
//        case HIDE_DATE_PDMENU:
//            if(RemovePullDownMenu())
//                screenState = DISPLAY_DATETIME; // switch to next state
//            return (1);
//
//        case DISPLAY_DATE_PDMENU:
//
//            // this moves the slider and editbox for the date setting to
//            // move while the up or down arrow buttons are pressed
//            if((tick - prevTick) > 1000)
//            {
//                pLb = (LISTBOX *)GOLFindObject(ID_LISTBOX1);
//                pSld = (SLIDER *)GOLFindObject(ID_SLIDER1);
//                pObj = GOLFindObject(ID_BUTTON_DATE_UP);
//
//                if(GetState(pObj, BTN_PRESSED))
//                {
//                    LbSetFocusedItem(pLb, LbGetFocusedItem(pLb) - 1);
//                    SetState(pLb, LB_DRAW_ITEMS);
//                    SldSetPos(pSld, SldGetPos(pSld) + 1);
//                    SetState(pSld, SLD_DRAW_THUMB);
//                }
//
//                pObj = GOLFindObject(ID_BUTTON_DATE_DN);
//
//                if(GetState(pObj, BTN_PRESSED))
//                {
//                    LbSetFocusedItem(pLb, LbGetFocusedItem(pLb) + 1);
//                    SetState(pLb, LB_DRAW_ITEMS);
//                    SldSetPos(pSld, SldGetPos(pSld) - 1);
//                    SetState(pSld, SLD_DRAW_THUMB);
//                }
//
//                prevTick = tick;
//            }
//
//            return (1);
//
//        case DISPLAY_DATETIME:
//
//            // Checks if the pull down menus are to be created or not
//            pObj = GOLFindObject(ID_BUTTON_MO);
//            if(GetState(pObj, BTN_PRESSED))
//            {
//                screenState = SHOW_DATE_PDMENU; // change state
//                return (1);
//            }
//
//            pObj = GOLFindObject(ID_BUTTON_YR);
//            if(GetState(pObj, BTN_PRESSED))
//            {
//                screenState = SHOW_DATE_PDMENU; // change state
//                return (1);
//            }
//
//            pObj = GOLFindObject(ID_BUTTON_DY);
//            if(GetState(pObj, BTN_PRESSED))
//            {
//                screenState = SHOW_DATE_PDMENU; // change state
//                return (1);
//            }
//
//            // this increments the values for the time settings
//            // while the + or - buttons are pressed
//            if((tick - prevTick) > 2000)
//            {
//                pObj = GOLFindObject(ID_BUTTONHR_P);
//                if(GetState(pObj, BTN_PRESSED))
//                {
//                    MsgDateTime(BTN_MSG_PRESSED, pObj);
//                }
//
//                pObj = GOLFindObject(ID_BUTTONHR_M);
//                if(GetState(pObj, BTN_PRESSED))
//                {
//                    MsgDateTime(BTN_MSG_PRESSED, pObj);
//                }
//
//                pObj = GOLFindObject(ID_BUTTONMN_P);
//                if(GetState(pObj, BTN_PRESSED))
//                {
//                    MsgDateTime(BTN_MSG_PRESSED, pObj);
//                }
//
//                pObj = GOLFindObject(ID_BUTTONMN_M);
//                if(GetState(pObj, BTN_PRESSED))
//                {
//                    MsgDateTime(BTN_MSG_PRESSED, pObj);
//                }
//
//                pObj = GOLFindObject(ID_BUTTONSC_P);
//                if(GetState(pObj, BTN_PRESSED))
//                {
//                    MsgDateTime(BTN_MSG_PRESSED, pObj);
//                }
//
//                pObj = GOLFindObject(ID_BUTTONSC_M);
//                if(GetState(pObj, BTN_PRESSED))
//                {
//                    MsgDateTime(BTN_MSG_PRESSED, pObj);
//                }
//
//                prevTick = tick;
//            }
//
//            return (1);
//
//        case CREATE_METER:
//            prevRefreshState = CREATE_METER;
//            CreateMeter();                      // create meter demo
//            screenState = DISPLAY_METER;        // switch to next state
//            return (1);                         // draw objects created
//
//        case DISPLAY_METER:
//            if((tick - prevTick) > 600)
//            {
//                UpdateMeter();
//                prevTick = tick;
//            }
//
//            return (1);                         // redraw objects if needed
//
//        case CREATE_DIAL:
//            prevRefreshState = CREATE_DIAL;
//            CreateDial();                       // create dial demo
//            screenState = DISPLAY_DIAL;         // switch to next state
//            return (1);                         // draw objects created
//
//        case DISPLAY_DIAL:
//            return (1);                         // redraw objects if needed
//
//        case CREATE_PICTURE:
//            prevRefreshState = CREATE_PICTURE;
//            CreatePicture();                    // create window, picture control and some check boxes
//            screenState = DISPLAY_PICTURE;      // switch to next state
//            return (1);                         // draw objects created
//
//        case DISPLAY_PICTURE:
//            if(animate)
//            {   // if animation is on change picture
//                if((tick - prevTick) > (SldGetPos(pSlider) + 40) * 10)
//                {
//                    switch(animate)
//                    {
//                        case 1: PictSetBitmap(pPicture, (void *) &Engine1); animate++; break;
//                        case 2: PictSetBitmap(pPicture, (void *) &Engine2); animate++; break;
//                        case 3: PictSetBitmap(pPicture, (void *) &Engine3); animate++; break;
//                        case 4: PictSetBitmap(pPicture, (void *) &Engine4); animate = 1; break;
//                    }
//
//                    SetState(pPicture, PICT_DRAW);  // must be redrawn
//                    prevTick = tick;
//                }
//            }
//
//            return (1);                             // redraw objects if needed
//
//        case CREATE_CUSTOMCONTROL:
//            prevRefreshState = CREATE_CUSTOMCONTROL;
//            CreateCustomControl();                  // create window and custom control
//            screenState = DISPLAY_CUSTOMCONTROL;    // switch to next state
//            return (1);                             // draw objects created
//
//        case DISPLAY_CUSTOMCONTROL:
//            #define SX_ARROW    18
//            #define SY_ARROW    26
//            if((tick - prevTick) > 20)
//            {
//                arrowPos++;                         // change arrows' position
//                if(arrowPos > 60 - SY_ARROW)
//                    arrowPos = 0;
//
//                WAIT_UNTIL_FINISH(PutImage(CC_ORIGIN_X + 0, CC_ORIGIN_Y + 60 - SY_ARROW - arrowPos, (void *) &arrowUp, 1)); // draw arrows
//                WAIT_UNTIL_FINISH(PutImage(CC_ORIGIN_X + 0, CC_ORIGIN_Y + 60 + arrowPos, (void *) &arrowDown, 1));
//                WAIT_UNTIL_FINISH(PutImage(CC_ORIGIN_X + 180 - SX_ARROW, CC_ORIGIN_Y + 60 - SY_ARROW - arrowPos, (void *) &arrowUp, 1));
//                WAIT_UNTIL_FINISH(PutImage(CC_ORIGIN_X + 180 - SX_ARROW, CC_ORIGIN_Y + 60 + arrowPos, (void *) &arrowDown, 1));
//                prevTick = tick;
//
//                #ifdef USE_DOUBLE_BUFFERING
//                    InvalidateRectangle(CC_ORIGIN_X, CC_ORIGIN_Y, CC_ORIGIN_X + SX_ARROW, CC_ORIGIN_Y + 120);
//                    InvalidateRectangle(CC_ORIGIN_X + 180 - SX_ARROW, CC_ORIGIN_Y, CC_ORIGIN_X + 180, CC_ORIGIN_Y + 120);
//                    UpdateDisplayNow();
//                #endif
//            }
//
//            return (1);                         // redraw objects if needed
//
//        case CREATE_SIGNATURE:
//            prevRefreshState = CREATE_SIGNATURE;
//            CreateSignature();                  // create window
//            screenState = BOX_DRAW_SIGNATURE;   // switch to next state
//            return (1);                         // draw objects created
//
//        case BOX_DRAW_SIGNATURE:
//            if(0 == PanelSignature())           // draw box for signature
//                return (0);                     // drawing is not completed, don't pass
//
//            // drawing control to GOL, try it again
//            screenState = DISPLAY_SIGNATURE;    // switch to next state
//            return (1);                         // pass drawing control to GOL, redraw objects if needed
//
//        case DISPLAY_SIGNATURE:
//            return (1);                         // redraw objects if needed
//
//        case CREATE_POT:
//            #if defined(__dsPIC33F__) || defined(__PIC24H__)
//            ADC_POT_TRIS = 1;
//            ADC_POT_PCFG = 0;
//            #endif
//            prevRefreshState = CREATE_POT;
//            CreatePotentiometer();              // create window
//            screenState = BOX_DRAW_POT;         // switch to next state
//            return (1);                         // draw objects created
//
//        case BOX_DRAW_POT:
//            if(0 == PanelPotentiometer())       // draw box for potentiometer graph
//                return (0);                     // drawing is not completed, don't pass
//
//            // drawing control to GOL, try it again
//            screenState = DISPLAY_POT;          // switch to next state
//            return (1);                         // pass drawing control to GOL, redraw objects if needed
//
//        case DISPLAY_POT:
//            if((tick - prevTick) > 200)
//            {
//                if(GetPotSamples(POT_MOVE_DELTA))
//                    GraphPotentiometer();       // redraw graph
//                prevTick = tick;
//            }
//
//            return (1);                         // redraw objects if needed
//
//        case CREATE_ECG:
//            prevRefreshState = CREATE_ECG;
//            CreateECG();                        // create window
//            screenState = BOX_DRAW_ECG;         // switch to next state
//            return (1);                         // draw objects created
//
//        case BOX_DRAW_ECG:
//            if(0 == PanelECG())                 // draw box for ECG graph
//                return (0);                     // drawing is not completed, don't pass
//
//            // drawing control to GOL, try it again
//            screenState = DISPLAY_ECG;          // switch to next state
//            return (1);                         // pass drawing control to GOL, redraw objects if needed
//
//        case DISPLAY_ECG:
//            if((tick - prevTick) > 10)
//            {
//                if(GetECGSamples(ECG_WINDOW_SIZE))
//                    GraphECG();                 // redraw graph
//                prevTick = tick;
//            }
//
//            return (1);                         // redraw objects if needed
//
//        case CREATE_PULLDOWN:
//            CreatePullDown();
//            screenState = DISPLAY_PULLDOWN;
//            return (1);
//
//        case DISPLAY_PULLDOWN:
//            DisplayPullDown();
//            return (1);                         // redraw objects if needed
//    }
//
//    return (1); // release drawing control to GOL
//}
//
//// Shows intro screen and waits for touch
//void StartScreen(void)
//{
//    #define SS_ORIGIN_X ((GetMaxX() - 316 + 1) / 2)
//    #define SS_ORIGIN_Y ((GetMaxY() - 140 + 1) / 2)
//
//    SHORT   counter;
//    WORD    i, j, k;
//    WORD    ytemp, xtemp, srRes = 0x0001;
//
//    SetColor(WHITE);
//    ClearDevice();
//    WAIT_UNTIL_FINISH(PutImage(0, 0, (void *) &mchpLogo, IMAGE_NORMAL));
//    WAIT_UNTIL_FINISH(PutImage(SS_ORIGIN_X, SS_ORIGIN_Y, (void *) &intro, IMAGE_X2));
//
//    for(counter = 0; counter < (GetMaxX() + 1 - 32); counter++)
//    {                               // move Microchip icon
//        #ifdef __PIC24FJ256DA210__
//            if(counter == 0)
//            {
//                WAIT_UNTIL_FINISH(PutImage(counter, GetMaxY() - 34, (void *) &mchpIcon0, IMAGE_NORMAL));
//            }
//            else
//            {
//                DWORD x = counter;
//                DWORD y = GetMaxY() - 34;
//
//                GFX_WaitForCommandQueue(4);
//                GFX_SetWorkArea1(GFX_DISPLAY_BUFFER_START_ADDRESS);
//                GFX_SetWorkArea2(GFX_DISPLAY_BUFFER_START_ADDRESS);
//
//                #if (DISP_ORIENTATION == 0)
//                {
//                    GFX_RCC_SetSrcOffset((y * DISP_HOR_RESOLUTION) + (x - 1));
//                    GFX_RCC_SetDestOffset((y * DISP_HOR_RESOLUTION) + x);
//                    GFX_RCC_SetSize(GetImageWidth((void *) &mchpIcon0), GetImageHeight((void *) &mchpIcon0));
//                    GFX_RCC_StartCopy(RCC_COPY, RCC_ROP_C, RCC_SRC_ADDR_DISCONTINUOUS, RCC_DEST_ADDR_DISCONTINUOUS);
//                    DelayMs(1);
//                }
//                #elif (DISP_ORIENTATION == 90)
//                {
//                    DWORD t = x;
//                    x = y;
//                    y = GetMaxX() - t - GetImageWidth((void *) &mchpIcon0);
//                    GFX_RCC_SetSrcOffset(((y + 1) * DISP_HOR_RESOLUTION) + x);
//                    GFX_RCC_SetDestOffset((y * DISP_HOR_RESOLUTION) + x);
//                    GFX_RCC_SetSize(GetImageHeight((void *) &mchpIcon0), GetImageWidth((void *) &mchpIcon0));
//                    GFX_RCC_StartCopy(RCC_COPY, RCC_ROP_C, RCC_SRC_ADDR_DISCONTINUOUS, RCC_DEST_ADDR_DISCONTINUOUS);
//                    DelayMs(1);
//                }
//                #else
//                    WAIT_UNTIL_FINISH(PutImage(counter, GetMaxY() - 34, (void *) &mchpIcon0, IMAGE_NORMAL));
//                #endif
//            }
//        #else
//            WAIT_UNTIL_FINISH(PutImage(counter, GetMaxY() - 34, (void *) &mchpIcon0, IMAGE_NORMAL));
//        #endif
//    }
//
//    SetColor(BRIGHTRED);
//    SetFont((void *)ptrLargeAsianFont);
//
//    MoveTo((GetMaxX() - GetTextWidth((XCHAR *)eTouchScreenStr, (void *)ptrLargeAsianFont)) >> 1, SS_ORIGIN_Y + 120);
//    while(!OutText((XCHAR *)eTouchScreenStr));
//    MoveTo((GetMaxX() - GetTextWidth((XCHAR *)cTouchScreenStr, (void *)ptrLargeAsianFont)) >> 1, SS_ORIGIN_Y + 122 + GetTextHeight((void *)ptrLargeAsianFont));
//    while(!OutText((XCHAR *)cTouchScreenStr));
//
//    // wait for touch
//	while(TouchGetX() == -1);
//    Beep();
//
//    SetClipRgn
//    (
//        SS_ORIGIN_X,
//        SS_ORIGIN_Y,
//        SS_ORIGIN_X + (GetImageWidth((void *) &intro) << 1),
//        SS_ORIGIN_Y + (GetImageHeight((void *) &intro) << 1)
//    );
//    SetClip(CLIP_ENABLE);
//
//    // random fade effect using a Linear Feedback Shift Register (LFSR)
//    SetColor(WHITE);
//    for(i = 1800; i > 0; i--)
//    {
//
//        // for a 16 bit LFSR variable the taps are at bits: 1, 2, 4, and 15
//        srRes = (srRes >> 1) ^ (-(int)(srRes & 1) & 0x8006);
//        xtemp = (srRes & 0x00FF) % 40;
//        ytemp = (srRes >> 8) % 30;
//
//        // by replicating the white (1x1) bars into 8 areas fading is faster
//        for(j = 0; j < 8; j++)
//        {
//            for(k = 0; k < 8; k++)
//                PutPixel(SS_ORIGIN_X + xtemp + (j * 40), ytemp + (k * 30));
//        }
//    }
//
//    SetClip(CLIP_DISABLE);
//
//    #if !(defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__)||defined(GFX_PICTAIL_LCC)||defined(__32MX250F128D__))
//
////    // initialize date and time
//    mRTCCOff();
//    RTCCSetBinHour(RTCC_DEFAULT_HOUR);      // set the hour value
//    RTCCSetBinMin(RTCC_DEFAULT_MINUTE);     // set the minute value
//    RTCCSetBinSec(RTCC_DEFAULT_SECOND);     // set the second value
//    RTCCSetBinDay(RTCC_DEFAULT_DAY);        // set the day value
//    RTCCSetBinMonth(RTCC_DEFAULT_MONTH);    // set the month value
//    RTCCSetBinYear(RTCC_DEFAULT_YEAR);      // set the year value
//    RTCCCalculateWeekDay();         		// calculate the weekday from this new value
//    mRTCCSet();                     		// copy the new values to the RTCC registers
//    RTCCProcessEvents();            		// update the date and time strings
//    #endif
//
//}
//
///* */
//void CreatePage(XCHAR *pText)
//{
//    OBJ_HEADER  *obj;
//    #if !(defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__)||defined(GFX_PICTAIL_LCC)||defined(__32MX250F128D__))
//    SHORT       i;
//	#endif
//
//    WndCreate
//    (
//        ID_WINDOW1,                 // ID
//        0,
//        0,
//        GetMaxX(),
//        GetMaxY(),                  // dimension
//        WND_DRAW,                   // will be dislayed after creation
//        (void *) &mchpIcon,         // icon
//        pText,                      // set text
//        navScheme
//    );                              // default GOL scheme
//    BtnCreate
//    (
//        ID_BUTTON_BACK,             // button ID
//        0,
//        40,                         // left, top corner
//        NAV_BTN_WIDTH,
//        GetMaxY(),
//        0,                          // right, bottom corner (with radius = 0)
//        BTN_DRAW,                   // will be dislayed after creation
//        NULL,                       // no bitmap
//        (XCHAR *)LeftArrowStr,      // LEFT arrow as text
//        navScheme
//    );                              // use navigation scheme
//    obj = (OBJ_HEADER *)BtnCreate
//        (
//            ID_BUTTON_NEXT,         // button ID
//            GetMaxX() - NAV_BTN_WIDTH,
//            40,
//            GetMaxX(),
//            GetMaxY(),
//            0,                      // dimension (with radius = 0)
//            BTN_DRAW,               // will be dislayed and disabled after creation
//            NULL,                   // no bitmap
//            (XCHAR *)RightArrowStr, // RIGHT arrow as text
//            navScheme
//        );                          // use navigation scheme
//
//    #if !(defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__)||defined(GFX_PICTAIL_LCC)||defined(__32MX250F128D__))
//    RTCCProcessEvents();            // update the date and time strings
//    i = 0;
//    while(i < 12)
//    {
//        dateTimeStr[i] = (XCHAR) _time_str[i];
//        dateTimeStr[i + 13] = (XCHAR) _date_str[i];
//        i++;
//    }
//
//    dateTimeStr[12] = (XCHAR) '\n';
//    dateTimeStr[25] = (XCHAR) '\0';
//
//    StCreate
//    (
//        ID_STATICTEXT1,             // ID
//        GetMaxX() - (GetTextWidth(dateTimeStr, (void *) &GOLSmallFont) + 15),
//        3,                          // dimensions
//        GetMaxX() - 5,
//        3 + (GetTextHeight((void *) &GOLSmallFont) << 1),
//        ST_DRAW | ST_FRAME | ST_CENTER_ALIGN,   // will be dislayed, has frame and center aligned
//        dateTimeStr,                            // text is from time value
//        timeScheme
//    );                  // alternate scheme
//    #endif
//#if defined (USE_FOCUS)
//    GOLSetFocus(obj);   // set focus for the button
//#endif
//}
//
///* definitions for the pull down menu demo */
//#define BOTTOM_NORMAL   40
//#define BOTTOM_DROPPED  220
//
//#define ScreenItems ScrSelList1
//#define ScreenItems2 ScrSelList2
//
///* */
//
//void CreatePullDown(void)
//{
//    OBJ_HEADER  *pFObj;
//
//    // before moving to a new list the current focused object is set to be not focused.
//    // this saves us the effort to save the pointer to the object and setting
//    // the global pointer to the focused object to that saved object.
//    // this application does not need it to be saved.
//    pFObj = GOLGetFocus();          // get the focused object
//    if(pFObj != NULL)
//    {
//        ClrState(pFObj, FOCUSED);   // clear the focus state
//        SetState(pFObj, DRAW);      // set to be redrawn
//    }
//
//    pListSaved = GOLGetList();
//    GOLNewList();
//
//    if(PulldownId == 0)
//    {
//        LbCreate
//        (
//            ID_LISTBOX2,                // ID
//            20,
//            BOTTOM_NORMAL,              // dimensions
//            136,
//            BOTTOM_DROPPED,
//            LB_SINGLE_SEL | LB_DRAW | LB_FOCUSED,   // will be created with single select and focused
//            (XCHAR *)ScreenItems,                   // list of demo screens
//            alt2Scheme
//        );                  // use alternate scheme
//    }
//
//    // This object is a ghost object to enable to get messages that touch is outside
//    // the list box. It will never be displayed.
//    GbCreate
//    (
//        ID_GROUPBOX2,   // ID
//        0,
//        0,
//        GetMaxX(),
//        GetMaxY(),      // cover the whole screen
//        0,              // do not display
//        NULL,           // no text
//        NULL
//    );
//}
//
///* this adds items on the items list of the list box */
//void AddItemList(XCHAR *pText, LISTBOX *pLb)
//{
//    XCHAR   *pointer;
//    WORD    ctr;
//
//    if(pText != NULL)
//    {
//        pointer = pText;
//        ctr = 0;
//        while(*pointer)
//        {
//            if(NULL == LbAddItem(pLb, NULL, pointer, NULL, 0, ctr))
//                break;
//            while(*pointer++ > 31);
//            if(*(pointer - 1) == 0)
//                break;
//            ctr++;
//        }
//    }
//}
//
///* */
//WORD MsgPullDown(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg)
//{
//    LISTBOX *pLb = NULL;
//    SHORT   item;
//
//    if(PulldownId == 0)
//    {
//        pLb = (LISTBOX *)GOLFindObject(ID_LISTBOX2);   // find the pull down object
//    }
//
//    if(pMsg->uiEvent == EVENT_RELEASE)
//    {                           // state transition must be done
//        if(GetObjID(pObj) == ID_LISTBOX2)
//        {                       // if released outside list box, go back
//            refreshScreen = 1;  // refresh screen only when an item was
//        }                       // selected
//
//        return (1);             // if release was done outside the
//        // list box, ignore the selection
//    }
//    else
//    {
//        if((pMsg->uiEvent == EVENT_MOVE) || (pMsg->uiEvent == EVENT_PRESS))
//        {
//            if(GetObjID(pObj) == ID_LISTBOX2)
//            {                   // process only for list box(pull down menu)
//                pMsg->uiEvent = EVENT_PRESS;                    // now convert the message
//                item = LbGetFocusedItem(pLb);                  // check item selected
//                if((!List2Enable) && (item == 8))
//                {                                               // if item MORE.... change menu
//                    List2Enable = 1;
//                    LbDelItemsList(pLb);                       // remove the current item
//                    AddItemList((XCHAR *)ScreenItems2, pLb);   // set the items list to ScreenItems2
//                    SetState(pLb, LB_DRAW);
//                }
//
//                if((List2Enable) && (item == 0))
//                {                       // if item BACK.... change back menu
//                    List2Enable = 0;    // remove the current item
//                    LbDelItemsList(pLb);
//                    AddItemList((XCHAR *)ScreenItems, pLb);    // set the items list to ScreenItems
//                    SetState(pLb, LB_DRAW);
//                }
//
//                return (1);
//            }
//        }
//
//        return (0);
//    }
//}
//
///* */
//void DisplayPullDown(void)
//{
//    LISTBOX *pLb = NULL;
//    SHORT   item, left, top, right, bottom;
//
//    if(refreshScreen)
//    {
//        if(PulldownId == 0)
//        {
//            pLb = (LISTBOX *)GOLFindObject(ID_LISTBOX2);   // find the pull down object
//            item = LbGetFocusedItem(pLb);                  // get selected page/screen
//
//            if(!List2Enable)
//            {                       // For list 1
//                switch(item)
//                {
//                    default:
//
//                    case 0:
//                        screenState = CREATE_BUTTONS;
//                        break;
//
//                    case 1:
//                        screenState = CREATE_CHECKBOXES;
//                        break;
//
//                    case 2:
//                        screenState = CREATE_RADIOBUTTONS;
//                        break;
//
//                    case 3:
//                        screenState = CREATE_STATICTEXT;
//                        break;
//
//                    case 4:
//                        screenState = CREATE_SLIDER;
//                        break;
//
//                    case 5:
//                        screenState = CREATE_PROGRESSBAR;
//                        break;
//
//                    case 6:
//                        screenState = CREATE_LISTBOX;
//                        break;
//
//                    case 7:
//                        screenState = CREATE_EDITBOX;
//                        break;
//
//                    case 8:
//                        screenState = prevState;
//                        break;
//                }
//            }
//            else
//            {
//                switch(item)
//                {                   // For list 2
//                    default:
//
//                    case 0:
//                        screenState = prevState;
//                        break;
//
//                    case 1:
//                        screenState = CREATE_METER;
//                        break;
//
//                    case 2:
//                        screenState = CREATE_DIAL;
//                        break;
//
//                    case 3:
//                        screenState = CREATE_PICTURE;
//                        break;
//
//                    case 4:
//                        screenState = CREATE_CUSTOMCONTROL;
//                        break;
//
//                    case 5:
//                        screenState = CREATE_SIGNATURE;
//                        break;
//
//                    case 6:
//                        screenState = CREATE_POT;
//                        break;
//
//                    case 7:
//                        screenState = CREATE_ECG;
//                        break;
//                }
//            }
//        }
//        else
//        {
//            screenState = prevRefreshState ; //Goto CREATE_XXX state
//        }
//
//        left = pLb->hdr.left;
//        top = pLb->hdr.top;    // save the dimensions
//        right = pLb->hdr.right;
//        bottom = pLb->hdr.bottom;
//        SetColor(pLb->hdr.pGolScheme->CommonBkColor);      // set the color
//        WAIT_UNTIL_FINISH(Bar(left, top, right, bottom));   // hide the pull down menu
//        GOLFree();              // remove the pull down menu
//        GOLSetList(pListSaved); // set active list back to saved list
//        GOLRedrawRec(left, top, right, bottom);
//        // reset the window so it will not be redrawn
//        ClrState(GOLFindObject(ID_WINDOW1), WND_DRAW);
//
//
//        refreshScreen = 0;      // reset the flag to no refresh
//    }
//}
//
///* */
//void CreateButtons(void)
//{
//    #define BTN_ORIGIN_X    ((GetMaxX() - 258 + 1) / 2)
//    #define BTN_ORIGIN_Y    ((40 + GetMaxY() - 177 + 1) / 2)
//
//    GOLFree();                      // free memory for the objects in the previous linked list and start new list
//    CreatePage((XCHAR *)ButtonStr);
//    BtnCreate
//    (
//        ID_BUTTON1,                 // button ID
//        BTN_ORIGIN_X + 0,
//        BTN_ORIGIN_Y + 7,
//        BTN_ORIGIN_X + 126,
//        BTN_ORIGIN_Y + 57,			// dimension
//        10,                         // set radius
//        BTN_DRAW,                   // draw a beveled button
//        NULL,                       // no bitmap
//        (XCHAR *)ButtonStr,         // text
//        altScheme
//    );                              // use alternate scheme
//    BtnCreate
//    (
//        ID_BUTTON2,                 // button ID
//        BTN_ORIGIN_X + 0,
//        BTN_ORIGIN_Y + 67,
//        BTN_ORIGIN_X + 126,
//        BTN_ORIGIN_Y + 117,         // dimension
//        0,
//        BTN_DRAW,                   // will be dislayed after creation
//        NULL,                       // use bitmap
//        (XCHAR *)HomeStr,           // text
//        altScheme
//    );                              // alternative GOL scheme
//    BtnCreate
//    (
//        ID_BUTTON3,                 // button ID
//        BTN_ORIGIN_X + 135,
//        BTN_ORIGIN_Y + 7,
//        BTN_ORIGIN_X + 185,
//        BTN_ORIGIN_Y + 117,         // dimension
//        25,                         // set radius
//        BTN_DRAW | BTN_TOGGLE,      // draw a vertical capsule button
//        							// that has a toggle behavior
//        NULL, 						// no bitmap
//        (XCHAR *)LowStr,            // text
//        yellowScheme
//    );                          	// use alternate scheme
//    BtnCreate
//    (
//        ID_BUTTON4,             	// button ID
//        BTN_ORIGIN_X + 195,
//        BTN_ORIGIN_Y + 0,
//        BTN_ORIGIN_X + 255,
//        BTN_ORIGIN_Y + 60,      	// dimension
//        30,                     	// set radius
//        BTN_DRAW,               	// draw a vertical capsule button
//        NULL,                   	// no bitmap
//        (XCHAR *)OnStr,         	// text
//        greenScheme
//    );                          	// use alternate scheme
//    BtnCreate
//    (
//        ID_BUTTON5,             	// button ID
//        BTN_ORIGIN_X + 195,
//        BTN_ORIGIN_Y + 64,
//        BTN_ORIGIN_X + 255,
//        BTN_ORIGIN_Y + 124,     	// dimension
//        30,                     	// set radius
//        BTN_DRAW | BTN_PRESSED, 	// draw a vertical capsule button
//        							// that is initially pressed
//        NULL,  						// no bitmap
//        (XCHAR *)OffStr,            // text
//        redScheme
//    );                      		// use alternate scheme
//    BtnCreate
//    (
//        ID_BUTTON6,         		// button ID
//        BTN_ORIGIN_X + 0,
//        BTN_ORIGIN_Y + 127,
//        BTN_ORIGIN_X + 126,
//        BTN_ORIGIN_Y + 177, 		// dimension
//        0,
//        BTN_DRAW | BTN_TEXTLEFT 	// will be dislayed after creation with text
//        | BTN_TEXTTOP, 				// left top position
//        (void *) &bulboff,          // use bitmap
//        (XCHAR *)OffBulbStr,        // text
//        alt2Scheme
//    );                              // alternative GOL scheme
//    BtnCreate
//    (
//        ID_BUTTON7,                 // button ID
//        BTN_ORIGIN_X + 132,
//        BTN_ORIGIN_Y + 127,
//        BTN_ORIGIN_X + 258,
//        BTN_ORIGIN_Y + 177,         // dimension
//        0,
//        BTN_DRAW | BTN_DISABLED,    // will be dislayed and disabled after creation
//        NULL,                       // no bitmap
//        (XCHAR *)DisabledStr,       // "Disabled",  // text
//        altScheme
//    );                              // use alternate scheme
//}
//
///* */
//WORD MsgButtons(WORD objMsg, OBJ_HEADER *pObj)
//{
//    OBJ_HEADER  *pOtherRbtn;
//
//    switch(GetObjID(pObj))
//    {
//        case ID_BUTTON_NEXT:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_CHECKBOXES;    // goto check box demo screen
//            }
//
//            return (1);                             // process by default
//
//        case ID_BUTTON_BACK:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_ECG;           // goto ECG demo screen
//            }
//
//            return (1);                             // process by default
//
//        case ID_BUTTON3:
//            if(objMsg == BTN_MSG_PRESSED)
//            {                           // change text and scheme
//                BtnSetText((BUTTON *)pObj, (XCHAR *)HighStr);
//            }
//            else
//            {
//                BtnSetText((BUTTON *)pObj, (XCHAR *)LowStr);
//            }
//
//            return (1);                 // process by default
//
//        case ID_BUTTON4:
//            if(objMsg == BTN_MSG_PRESSED)
//            {
//                if(!GetState(pObj, BTN_PRESSED))
//                {
//                    pOtherRbtn = GOLFindObject(ID_BUTTON5);
//                    ClrState(pOtherRbtn, BTN_PRESSED);
//                    SetState(pOtherRbtn, BTN_DRAW);
//                    SetState(pObj, BTN_PRESSED | BTN_DRAW);
//#if defined (USE_FOCUS)
//                    GOLSetFocus(pObj);  // set focus for the button
//#endif
//                }
//            }
//
//            return (0);                 // Do not process by default
//
//        case ID_BUTTON5:
//            if(objMsg == BTN_MSG_PRESSED)
//            {
//                if(!GetState(pObj, BTN_PRESSED))
//                {
//                    pOtherRbtn = GOLFindObject(ID_BUTTON4);
//                    ClrState(pOtherRbtn, BTN_PRESSED);
//                    SetState(pOtherRbtn, BTN_DRAW);
//                    SetState(pObj, BTN_PRESSED | BTN_DRAW);
//#if defined (USE_FOCUS)
//                    GOLSetFocus(pObj);  // set focus for the button
//#endif
//                }
//            }
//
//            return (0);                 // Do not process by default
//
//        case ID_BUTTON6:
//            if(objMsg == BTN_MSG_PRESSED)
//            {                           // change face picture
//                BtnSetBitmap(pObj, (void *) &bulbon);
//                BtnSetText((BUTTON *)pObj, (XCHAR *)OnBulbStr);
//                ClrState(pObj, 0x00F0);
//                SetState(pObj, BTN_TEXTBOTTOM | BTN_TEXTRIGHT);
//            }
//
//            if((objMsg == BTN_MSG_RELEASED) || (objMsg == BTN_MSG_CANCELPRESS))
//            {
//                BtnSetBitmap(pObj, (void *) &bulboff);
//                BtnSetText((BUTTON *)pObj, (XCHAR *)OffBulbStr);
//                ClrState(pObj, 0x00F0);
//                SetState(pObj, BTN_TEXTTOP | BTN_TEXTLEFT);
//            }
//
//            return (1);                 // process by default
//
//        default:
//            return (1);                 // process by default
//    }
//}
//
///* */
//void CreateCheckBoxes(void)
//{
//    #define CB_ORIGIN_X ((GetMaxX() - 115 + 1) / 2)
//    #define CB_ORIGIN_Y ((40 + GetMaxY() - 175 + 1) / 2)
//
//    GOLFree();                          // free memory for the objects in the previous linked list and start new list
//    CreatePage((XCHAR *)CheckBoxStr);   // CreatePage("Checkboxes");
//    CbCreate
//    (
//        ID_CHECKBOX1,                   // ID
//        CB_ORIGIN_X + 0,
//        CB_ORIGIN_Y + 65,
//        CB_ORIGIN_X + 165,
//        CB_ORIGIN_Y + 100,              // dimension
//        CB_DRAW,                        // will be dislayed after creation
//        (XCHAR *)TextLeftStr,           // "Text Left"
//        altScheme
//    );                              // alternative GOL scheme
//    CbCreate
//    (
//        ID_CHECKBOX2,               // ID
//        CB_ORIGIN_X + 0,
//        CB_ORIGIN_Y + 105,
//        CB_ORIGIN_X + 165,
//        CB_ORIGIN_Y + 140,          // dimension
//        CB_DRAW,                    // will be dislayed and checked after creation
//        (XCHAR *)TextBottomStr,     // "Text Bottom"
//        altScheme
//    );                              // alternative GOL scheme
//    CbCreate
//    (
//        ID_CHECKBOX3,               // ID
//        CB_ORIGIN_X + 0,
//        CB_ORIGIN_Y + 145,
//        CB_ORIGIN_X + 150,
//        CB_ORIGIN_Y + 180,          // dimension
//        CB_DRAW | CB_DISABLED,      // will be dislayed and disabled after creation
//        (XCHAR *)DisabledStr,       // "Disabled"
//        altScheme
//    );                              // alternative GOL scheme
//    pGenObj = (OBJ_HEADER *)BtnCreate
//        (
//            ID_BUTTON1,             // button ID
//            CB_ORIGIN_X + 0,
//            CB_ORIGIN_Y - 8,
//            CB_ORIGIN_X + 115,
//            CB_ORIGIN_Y + 62,       // dimension
//            10,                     // set radius
//            BTN_DRAW,               // draw a beveled button
//            NULL,                   // no bitmap
//            (XCHAR *)HomeLinesStr,  // "Home1\nHome2" the string has two lines \n is the new line character
//            altScheme
//        );                          // use alternate scheme
//}
//
///* */
//WORD MsgCheckBoxes(WORD objMsg, OBJ_HEADER *pObj)
//{
//    switch(GetObjID(pObj))
//    {
//        case ID_CHECKBOX1:
//            if(objMsg == CB_MSG_CHECKED)
//            {
//                SetState(pGenObj, BTN_TEXTLEFT | BTN_DRAW); // set align left and redraw button
//            }
//            else
//            {
//                ClrState(pGenObj, BTN_TEXTLEFT);            // clear all text alignment
//                SetState(pGenObj, BTN_DRAW);                // set align left and redraw button
//            }
//
//            return (1); // process by default
//
//        case ID_CHECKBOX2:
//            if(objMsg == CB_MSG_CHECKED)
//            {
//                SetState(pGenObj, BTN_TEXTBOTTOM | BTN_DRAW);   // set align bottom and redraw button
//            }
//            else
//            {
//                ClrState(pGenObj, BTN_TEXTBOTTOM);              // clear all text alignment
//                SetState(pGenObj, BTN_DRAW);                    // set align left and redraw button
//            }
//
//            return (1);                             // process by default
//
//        case ID_BUTTON_NEXT:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_RADIOBUTTONS;  // goto radio buttons screen
//            }
//
//            return (1);                             // process by default
//
//        case ID_BUTTON_BACK:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_BUTTONS;       // goto round buttons screen
//            }
//
//            return (1);                             // process by default
//
//        default:
//            return (1);                             // process by default
//    }
//}
//
///* */
//void CreateRadioButtons(void)
//{
//    #define RB_ORIGIN_X ((GetMaxX() - 260 + 1) / 2)
//    #define RB_ORIGIN_Y ((40 + GetMaxY() - 185 + 1) / 2)
//
//    GOLFree();                              // free memory for the objects in the previous linked list and start new list
//    CreatePage((XCHAR *)RadioButtonStr);    // CreatePage("Radio buttons");
//    GbCreate
//    (
//        ID_GROUPBOX1,                       // ID
//        RB_ORIGIN_X + 0,
//        RB_ORIGIN_Y + 0,
//        RB_ORIGIN_X + 127,
//        RB_ORIGIN_Y + 185,                  // dimension
//        GB_DRAW | GB_CENTER_ALIGN,          // will be dislayed after creation
//        (XCHAR *)Group1Str,                 // "Group 1"
//        alt2Scheme
//    );                              // alternate scheme
//    GbCreate
//    (
//        ID_GROUPBOX2,               // ID
//        RB_ORIGIN_X + 130,
//        RB_ORIGIN_Y + 0,
//        RB_ORIGIN_X + 260,
//        RB_ORIGIN_Y + 185,          // dimension
//        GB_DRAW | GB_CENTER_ALIGN,  // will be dislayed after creation
//        (XCHAR *)Group2Str,         // "Group 2"
//        alt2Scheme
//    );                              // alternate scheme
//    RbCreate
//    (
//        ID_RADIOBUTTON1,            // ID
//        RB_ORIGIN_X + 5,
//        RB_ORIGIN_Y + 25,
//        RB_ORIGIN_X + 125,
//        RB_ORIGIN_Y + 60,           // dimension
//        RB_DRAW | RB_GROUP | RB_CHECKED,                // will be dislayed and checked after creation
//        // first button in the group
//        (XCHAR *)Rb1Str,   // "Rb1"
//        altScheme
//    );                          // alternative GOL scheme
//    RbCreate
//    (
//        ID_RADIOBUTTON2,        // ID
//        RB_ORIGIN_X + 5,
//        RB_ORIGIN_Y + 65,
//        RB_ORIGIN_X + 125,
//        RB_ORIGIN_Y + 100,      // dimension
//        RB_DRAW,                // will be dislayed
//        (XCHAR *)Rb2Str,        // "Rb2"
//        altScheme
//    );                          // alternative GOL scheme
//    RbCreate
//    (
//        ID_RADIOBUTTON3,        // ID
//        RB_ORIGIN_X + 5,
//        RB_ORIGIN_Y + 105,
//        RB_ORIGIN_X + 125,
//        RB_ORIGIN_Y + 140,      // dimension
//        RB_DRAW,                // will be dislayed after creation
//        (XCHAR *)Rb3Str,        // "Rb3"
//        altScheme
//    );                          // alternative GOL scheme
//    RbCreate
//    (
//        ID_RADIOBUTTON4,        // ID
//        RB_ORIGIN_X + 5,
//        RB_ORIGIN_Y + 145,
//        RB_ORIGIN_X + 125,
//        RB_ORIGIN_Y + 180,      // dimension
//        RB_DRAW | RB_DISABLED,  // will be dislayed and disabled after creation
//        (XCHAR *)DisabledStr,   // "Disabled"
//        altScheme
//    );                          // alternative GOL scheme
//    RbCreate
//    (
//        ID_RADIOBUTTON5,        // ID
//        RB_ORIGIN_X + 135,
//        RB_ORIGIN_Y + 25,
//        RB_ORIGIN_X + 255,
//        RB_ORIGIN_Y + 60,       // dimension
//        RB_DRAW | RB_GROUP,     // will be dislayed and focused after creation
//        // first button in the group
//        (XCHAR *)Rb4Str,   // "Rb4"
//        altScheme
//    );                          // alternative GOL scheme
//    RbCreate
//    (
//        ID_RADIOBUTTON6,        // ID
//        RB_ORIGIN_X + 135,
//        RB_ORIGIN_Y + 65,
//        RB_ORIGIN_X + 255,
//        RB_ORIGIN_Y + 100,      // dimension
//        RB_DRAW,   // will be dislayed and checked after creation
//        (XCHAR *)Rb5Str,        // "Rb5"
//        altScheme
//    );                          // alternative GOL scheme
//
//    if(_language == LANG_ENGLISH)
//    {
//        SetState(GOLFindObject(ID_RADIOBUTTON5), RB_CHECKED);
//    }
//    else if(_language == LANG_CHINESE)
//    {
//        SetState(GOLFindObject(ID_RADIOBUTTON6), RB_CHECKED);
//    }
//}
//
///* */
//WORD MsgRadioButtons(WORD objMsg, OBJ_HEADER *pObj)
//{
//    switch(GetObjID(pObj))
//    {
//        case ID_BUTTON_NEXT:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_STATICTEXT;    // goto static text screen
//            }
//
//            return (1);                             // process by default
//
//        case ID_BUTTON_BACK:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_CHECKBOXES;    // goto check boxes screen
//            }
//
//            return (1);                             // process by default
//
//        default:
//            return (1);                             // process by default
//    }
//}
//
///* */
//void CreateStaticText(void)
//{
//    #define ST_ORIGIN_X ((GetMaxX() - 260 + 1) / 2)
//    #define ST_ORIGIN_Y ((40 + GetMaxY() - 185 + 1) / 2)
//
//    GOLFree();                          // free memory for the objects in the previous linked list and start new list
//    CreatePage((XCHAR *)StaticTextStr); // CreatePage("Static text");
//    GbCreate
//    (
//        ID_GROUPBOX1,                   // ID
//        ST_ORIGIN_X + 0,
//        ST_ORIGIN_Y + 0,
//        ST_ORIGIN_X + 205,
//        ST_ORIGIN_Y + 185,              // dimension
//        GB_DRAW,                        // will be dislayed after creation
//        (XCHAR *)GroupBoxStr,           // "Group Box"
//        NULL
//    );                              // default GOL scheme
//    StCreate
//    (
//        ID_STATICTEXT3,             // ID
//        ST_ORIGIN_X + 5,
//        ST_ORIGIN_Y + 35,
//        ST_ORIGIN_X + 195,
//        ST_ORIGIN_Y + 175,          // dimension
//        ST_DRAW | ST_FRAME,         // will be dislayed, has frame
//        (XCHAR *)StaticTextLstStr,  // "Microchip\nGraphics\nLibrary\nStatic Text and\nGroup Box Test.", // multi-line text
//        altScheme
//    );                              // use alternate scheme scheme
//    RbCreate
//    (
//        ID_RADIOBUTTON1,            // ID
//        ST_ORIGIN_X + 210,
//        ST_ORIGIN_Y + 25,
//        ST_ORIGIN_X + 260,
//        ST_ORIGIN_Y + 55,           // dimension
//        RB_DRAW | RB_GROUP | RB_CHECKED,                // will be dislayed and checked after creation
//        // first button in the group
//        (XCHAR *)LeftStr,  // "Left"
//        altScheme
//    );                      // use alternate scheme
//    RbCreate
//    (
//        ID_RADIOBUTTON2,    // ID
//        ST_ORIGIN_X + 210,
//        ST_ORIGIN_Y + 65,
//        ST_ORIGIN_X + 260,
//        ST_ORIGIN_Y + 95,   // dimension
//        RB_DRAW,            // will be dislayed after creation
//        (XCHAR *)CenterStr, // "Center"
//        altScheme
//    );                      // use alternate scheme
//    RbCreate
//    (
//        ID_RADIOBUTTON3,    // ID
//        ST_ORIGIN_X + 210,
//        ST_ORIGIN_Y + 105,
//        ST_ORIGIN_X + 260,
//        ST_ORIGIN_Y + 135,  // dimension
//        RB_DRAW,            // will be dislayed after creation
//        (XCHAR *)RightStr,  // "Right"
//        altScheme
//    );                      // use alternate scheme
//}
//
///* */
//WORD MsgStaticText(WORD objMsg, OBJ_HEADER *pObj)
//{
//    GROUPBOX    *pGb;
//    STATICTEXT  *pSt;
//
//    switch(GetObjID(pObj))
//    {
//        case ID_RADIOBUTTON1:   // change aligment to left
//            pGb = (GROUPBOX *)GOLFindObject(ID_GROUPBOX1);      // get pointer to group box
//            ClrState(pGb, GB_RIGHT_ALIGN | GB_CENTER_ALIGN);    // clear right and center alignment states
//            SetState(pGb, GB_DRAW);                             // set redraw state
//            pSt = (STATICTEXT *)GOLFindObject(ID_STATICTEXT3);  // get pointer to static text
//            ClrState(pSt, ST_RIGHT_ALIGN | ST_CENTER_ALIGN);    // clear right and center alignment states
//            SetState(pSt, ST_UPDATE);                           // set update state
//            return (1); // process by default
//
//        case ID_RADIOBUTTON2:
//            pGb = (GROUPBOX *)GOLFindObject(ID_GROUPBOX1);      // get pointer to group box
//            ClrState(pGb, GB_RIGHT_ALIGN);                      // clear right alignment state
//            SetState(pGb, GB_CENTER_ALIGN | GB_DRAW);           // set center alignment and redraw states
//            pSt = (STATICTEXT *)GOLFindObject(ID_STATICTEXT3);  // get pointer to static text
//            ClrState(pSt, ST_RIGHT_ALIGN);                      // clear right aligment state
//            SetState(pSt, ST_UPDATE | ST_CENTER_ALIGN);         // set center alignment and update states
//            return (1); // process by default
//
//        case ID_RADIOBUTTON3:
//            pGb = (GROUPBOX *)GOLFindObject(ID_GROUPBOX1);      // get pointer to group box
//            ClrState(pGb, GB_CENTER_ALIGN);                     // clear center alignment state
//            SetState(pGb, GB_RIGHT_ALIGN | GB_DRAW);            // set right alignment and redraw state
//            pSt = (STATICTEXT *)GOLFindObject(ID_STATICTEXT3);  // get pointer to static text
//            ClrState(pSt, ST_CENTER_ALIGN);                     // clear center aligment state
//            SetState(pSt, ST_RIGHT_ALIGN | ST_UPDATE);          // set right alignment and update states
//            return (1);                             // process by default
//
//        case ID_BUTTON_NEXT:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_SLIDER;        // goto slider screen
//            }
//
//            return (1);                             // process by default
//
//        case ID_BUTTON_BACK:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_RADIOBUTTONS;  // goto radio buttons screen
//            }
//
//            return (1);                             // process by default
//
//        default:
//            return (1);
//    }
//}
//
///* */
//void CreateSlider(void)
//{
//    GOLFree();                              // free memory for the objects in the previous linked list and start new list
//    CreatePage((XCHAR *)SliderStr);         //
//    GbCreate
//    (
//        ID_GROUPBOX1,                       // ID
//        SLD_ORIGIN_X + 35,
//        SLD_ORIGIN_Y + 0,
//        SLD_ORIGIN_X + 225,
//        SLD_ORIGIN_Y + 135,                 // dimension
//        GB_DRAW,                            // will be dislayed after creation
//        NULL,                               // no text
//        altScheme
//    );                                      // alternative GOL scheme
//    SldCreate
//    (
//        ID_SLIDER1,                         // ID
//        SLD_ORIGIN_X + 0,
//        SLD_ORIGIN_Y + 140,
//        SLD_ORIGIN_X + 260,
//        SLD_ORIGIN_Y + 170,                 // dimension
//        SLD_DRAW,                           // will be dislayed after creation
//        CUR_BRD_RIGHT - CUR_BRD_LEFT,       // range
//        10,                                 // page
//        (CUR_BRD_RIGHT - CUR_BRD_LEFT) / 2, // pos
//        altScheme
//    );                      // alternative GOL scheme
//    SldCreate
//    (
//        ID_SLIDER2,         // ID
//        SLD_ORIGIN_X + 0,
//        SLD_ORIGIN_Y + 0,
//        SLD_ORIGIN_X + 30,
//        SLD_ORIGIN_Y + 135, // dimension
//        SLD_DRAW | SLD_VERTICAL | SLD_DISABLED, // vertical, will be dislayed and disabled after creation
//        100,                                // range
//        100,                                // page
//        50,                                 // pos
//        altScheme
//    );                                      // alternative GOL scheme
//    SldCreate
//    (
//        ID_SLIDER3,                         // ID
//        SLD_ORIGIN_X + 230,
//        SLD_ORIGIN_Y + 0,
//        SLD_ORIGIN_X + 260,
//        SLD_ORIGIN_Y + 135,                 // dimension
//        SLD_DRAW | SLD_VERTICAL,            // vertical, will be dislayed after creation
//        CUR_BRD_BOTTOM - CUR_BRD_TOP,       // range
//        10,                                 // page
//        (CUR_BRD_BOTTOM - CUR_BRD_TOP) / 2, // pos
//        altScheme
//    );  // alternative GOL scheme
//
//    // Set cursor to the middle
//    prevX = x = (CUR_BRD_RIGHT + CUR_BRD_LEFT) / 2; // cursor X position
//    prevY = y = (CUR_BRD_BOTTOM + CUR_BRD_TOP) / 2; // cursor Y position
//}
//
//// Draw sliders' position cursor
//void DrawSliderCursor(WORD color, SHORT xPos, SHORT yPos)
//{
//    SetColor(color);
//    WAIT_UNTIL_FINISH(Bar(xPos - CUR_BAR_SIZE, yPos - CUR_BAR_SIZE, xPos + CUR_BAR_SIZE, yPos + CUR_BAR_SIZE));
//    WAIT_UNTIL_FINISH(Line(xPos, CUR_BRD_TOP, xPos, CUR_BRD_BOTTOM));
//    WAIT_UNTIL_FINISH(Line(CUR_BRD_LEFT, yPos, CUR_BRD_RIGHT, yPos));
//
//#ifdef USE_DOUBLE_BUFFERING
//    InvalidateAll();
//#endif
//}
//
//// Process messages for slider screen
//WORD MsgSlider(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg)
//{
//    WORD    id;
//    SLIDER  *pSld;
//
//    switch(id = GetObjID(pObj))
//    {
//        case ID_WINDOW1:
//
//            // check if window is touched in cursor box area
//            if
//            (
//                (pMsg->param1 > CUR_BRD_LEFT) &&
//                (pMsg->param1 < CUR_BRD_RIGHT) &&
//                (pMsg->param2 > CUR_BRD_TOP) &&
//                (pMsg->param2 < CUR_BRD_BOTTOM)
//            )
//            {
//                // do some kind of debouncing so the lines on the screen will be stable.
//                if ((abs((pMsg->param1 - x)) > 2) || (abs((pMsg->param2 - y)) > 2))
//                {
//                    // get new cursor x,y
//                    x = pMsg->param1;
//                    y = pMsg->param2;
//                    cursorUpdate = 1;
//
//                    // set new sliders positions
//                    pSld = (SLIDER *)GOLFindObject(ID_SLIDER1); // get pointer for horizontal slider
//                    SldSetPos(pSld, x - CUR_BRD_LEFT);          // set new position
//                    SetState(pSld, SLD_DRAW_THUMB);             // redraw thumb only
//                    pSld = (SLIDER *)GOLFindObject(ID_SLIDER3); // get pointer for vertical slider
//                    SldSetPos(pSld, CUR_BRD_BOTTOM - y);        // set new position
//                    SetState(pSld, SLD_DRAW_THUMB);             // redraw thumb only
//                }
//
//            }
//
//            return (1);                             // process by default
//
//        case ID_SLIDER1:
//        case ID_SLIDER3:
//
//			if((objMsg == SLD_MSG_INC) || (objMsg == SLD_MSG_DEC))
//            {
//	            // process message by default
//	            SldMsgDefault(objMsg, (SLIDER *)pObj, pMsg);
//
//	            // get new X position from horizontal slider
//	            if(id == ID_SLIDER1)
//	            {
//	                x = CUR_BRD_LEFT + SldGetPos((SLIDER *)pObj);
//	                if(x > CUR_BRD_RIGHT)
//	                    x = CUR_BRD_RIGHT;
//	            }
//
//	            // get new Y position from vertical slider
//	            if(id == ID_SLIDER3)
//	            {
//	                y = CUR_BRD_BOTTOM - SldGetPos((SLIDER *)pObj);
//	                if(y < CUR_BRD_TOP)
//	                    y = CUR_BRD_TOP;
//	            }
//	            cursorUpdate = 1;
//
//			}
//            return (0);                             // it was processed
//
//        case ID_BUTTON_NEXT:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_PROGRESSBAR;   // goto progress bar screen
//            }
//
//            return (1);                             // process by default
//
//        case ID_BUTTON_BACK:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_STATICTEXT;    // goto static text screen
//            }
//
//            return (1);                             // process by default
//
//        default:
//            return (1);                             // process by default
//    }
//}
//
//// Creates progress bar screen
//void CreateProgressBar(void)
//{
//    #define PB_ORIGIN_X ((GetMaxX() - 240 + 1) / 2)
//    #define PB_ORIGIN_Y ((40 + GetMaxY() - 130 + 1) / 2)
//
//    GOLFree();                              // free memory for the objects in the previous linked list and start new list
//    CreatePage((XCHAR *)ProgressBarStr);    //
//    pProgressBar = PbCreate
//        (
//            ID_PROGRESSBAR1,                // ID
//            PB_ORIGIN_X + 0,
//            PB_ORIGIN_Y + 0,
//            PB_ORIGIN_X + 240,
//            PB_ORIGIN_Y + 50,               // dimension
//            PB_DRAW,                        // will be dislayed after creation
//            25,                             // position
//            50,                             // range
//            NULL
//        );                          // use default scheme
//    StCreate
//    (
//        ID_STATICTEXT3,             // ID
//        PB_ORIGIN_X + 30,
//        PB_ORIGIN_Y + 70,
//        PB_ORIGIN_X + 185,
//        PB_ORIGIN_Y + 130,          // dimension
//        ST_DRAW | ST_CENTER_ALIGN,  // display text
//        (XCHAR *)PIC24SpeedStr,     // text
//        altScheme
//    );                              // use alternate scheme
//    pGenObj = (OBJ_HEADER *)BtnCreate
//        (
//            ID_BUTTON1,             // button ID
//            PB_ORIGIN_X + 180,
//            PB_ORIGIN_Y + 83,
//            PB_ORIGIN_X + 220,
//            PB_ORIGIN_Y + 113,      // dimension
//            10,                     // set radius
//            BTN_DRAW | BTN_TOGGLE,  // draw button
//            NULL,                   // no bitmap
//            (XCHAR *)QuestionStr,   // "?",               			// text
//            altScheme
//        );                          // use alternate scheme
//}
//
//// Processes messages for progress bar screen
//WORD MsgProgressBar(WORD objMsg, OBJ_HEADER *pObj)
//{
//    switch(GetObjID(pObj))
//    {
//        case ID_BUTTON_NEXT:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_LISTBOX;   // goto list box screen
//            }
//
//            return (1);                         // process by default
//
//        case ID_BUTTON_BACK:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_SLIDER;    // goto slider screen
//            }
//
//            return (1);                         // process by default
//
//        default:
//            return (1);                         // process by default
//    }
//}
//
//#define pMyItemList (XCHAR*)ListboxLstStr
//
//// creates list box demo screen
//void CreateListBox(void)
//{
//    LISTBOX *pLb;
//
//    #define LB_ORIGIN_X ((GetMaxX() - 260 + 1) / 2)
//    #define LB_ORIGIN_Y ((40 + GetMaxY() - 192 + 1) / 2)
//
//    GOLFree();                                      // free memory for the objects in the previous linked list and start new list
//    CreatePage((XCHAR *)ListBoxStr);                //
//    pLb = LbCreate
//        (
//            ID_LISTBOX1,                            // ID
//            LB_ORIGIN_X + 10,
//            LB_ORIGIN_Y + 52,
//            LB_ORIGIN_X + 220,
//            LB_ORIGIN_Y + 192,                      // dimension
//            LB_DRAW | LB_FOCUSED,                   // will be dislayed after creation
//            pMyItemList,
//            altScheme
//        );                                          // use alternate scheme
//    SldCreate
//    (
//        ID_SLIDER1,                                 // ID
//        LB_ORIGIN_X + 220,
//        LB_ORIGIN_Y + 82,
//        LB_ORIGIN_X + 250,
//        LB_ORIGIN_Y + 160,                          // dimension
//        SLD_DRAW | SLD_SCROLLBAR | SLD_VERTICAL,    // vertical, will be dislayed after creation
//        LbGetCount(pLb),                            // range
//        1,                          // page
//        LbGetCount(pLb) - 1,        // pos
//        altScheme
//    );                              // use alternate scheme
//    BtnCreate
//    (
//        ID_BUTTON1,                 // ID
//        LB_ORIGIN_X + 220,
//        LB_ORIGIN_Y + 52,
//        LB_ORIGIN_X + 250,
//        LB_ORIGIN_Y + 82,
//        0,                          // dimension (no radius)
//        BTN_DRAW,                   // will be dislayed after creation
//        NULL,                       // no bitmap
//        (XCHAR *)UpArrowStr,        // Up Arrow
//        altScheme
//    );                              // use alternate scheme
//    BtnCreate
//    (
//        ID_BUTTON2,                 // ID
//        LB_ORIGIN_X + 220,
//        LB_ORIGIN_Y + 162,
//        LB_ORIGIN_X + 250,
//        LB_ORIGIN_Y + 192,
//        0,                          // dimension (no radius)
//        BTN_DRAW,                   // will be dislayed after creation
//        NULL,                       // no bitmap
//        (XCHAR *)DownArrowStr,      // Down Arrow
//        altScheme
//    );                              // use alternate scheme
//    CbCreate
//    (
//        ID_CHECKBOX1,               // ID
//        LB_ORIGIN_X + 10,
//        LB_ORIGIN_Y + 20,
//        LB_ORIGIN_X + 110,
//        LB_ORIGIN_Y + 45,           // dimension
//        CB_DRAW,                    // will be dislayed after creation
//        (XCHAR *)SingleStr,         // "Single"
//        altScheme
//    );                              // alternative GOL scheme
//    CbCreate
//    (
//        ID_CHECKBOX2,               // ID
//        LB_ORIGIN_X + 140,
//        LB_ORIGIN_Y + 20,
//        LB_ORIGIN_X + 240,
//        LB_ORIGIN_Y + 45,           // dimension
//        CB_DRAW,                    // will be dislayed after creation
//        (XCHAR *)AlignCenterStr,    // "Center"
//        altScheme
//    );                              // alternative GOL scheme
//    GbCreate
//    (
//        ID_GROUPBOX1,               // ID
//        LB_ORIGIN_X + 0,
//        LB_ORIGIN_Y + 0,
//        LB_ORIGIN_X + 127,
//        LB_ORIGIN_Y + 50,           // dimension
//        GB_DRAW | GB_CENTER_ALIGN,  // will be dislayed after creation
//        (XCHAR *)SelectionStr,      // "Selection"
//        alt4Scheme
//    );                              // alternate scheme
//    GbCreate
//    (
//        ID_GROUPBOX2,               // ID
//        LB_ORIGIN_X + 130,
//        LB_ORIGIN_Y + 0,
//        LB_ORIGIN_X + 260,
//        LB_ORIGIN_Y + 50,           // dimension
//        GB_DRAW | GB_CENTER_ALIGN,  // will be dislayed after creation
//        (XCHAR *)AlignmentStr,      // "Alignment"
//        alt4Scheme
//    );                              // alternate scheme
//}
//
//// processes messages for list box demo screen
//WORD MsgListBox(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg)
//{
//    LISTBOX *pLb;
//    SLIDER  *pSld;
//
//    pLb = (LISTBOX *)GOLFindObject(ID_LISTBOX1);
//    pSld = (SLIDER *)GOLFindObject(ID_SLIDER1);
//
//    switch(GetObjID(pObj))
//    {
//        case ID_LISTBOX1:
//
//            // Process message by default
//            LbMsgDefault(objMsg, (LISTBOX *)pObj, pMsg);
//
//            // Set new list box position
//            SldSetPos(pSld, LbGetCount(pLb) - LbGetFocusedItem(pLb));
//            SetState(pSld, SLD_DRAW_THUMB);
//
//            // The message was processed
//            return (0);
//
//        case ID_SLIDER1:
//
//			if((objMsg == SLD_MSG_INC) || (objMsg == SLD_MSG_DEC))
//            {
//	        	// Process message by default
//	            SldMsgDefault(objMsg, (SLIDER *)pObj, pMsg);
//
//	            // Set new list box position
//	            if(LbGetFocusedItem(pLb) != LbGetCount(pLb) - SldGetPos(pSld))
//	            {
//	                LbSetFocusedItem(pLb, LbGetCount(pLb) - SldGetPos(pSld));
//	                SetState(pLb, LB_DRAW_ITEMS);
//	            }
//	        }
//
//            // The message was processed
//            return (0);
//
//        case ID_BUTTON1:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                LbSetFocusedItem(pLb, LbGetFocusedItem(pLb) - 1);
//                SetState(pLb, LB_DRAW_ITEMS);
//                SldSetPos(pSld, SldGetPos(pSld) + 1);
//                SetState(pSld, SLD_DRAW_THUMB);
//            }
//
//            return (1);
//
//        case ID_BUTTON2:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                LbSetFocusedItem(pLb, LbGetFocusedItem(pLb) + 1);
//                SetState(pLb, LB_DRAW_ITEMS);
//                SldSetPos(pSld, SldGetPos(pSld) - 1);
//                SetState(pSld, SLD_DRAW_THUMB);
//            }
//
//            return (1);
//
//        case ID_CHECKBOX1:
//            if(objMsg == CB_MSG_CHECKED)
//            {
//                SetState(pLb, LB_SINGLE_SEL | LB_DRAW);
//                LbChangeSel(pLb, pLb->pFocusItem);
//            }
//            else
//            {
//                ClrState(pLb, LB_SINGLE_SEL);
//            }
//
//            return (1);
//
//        case ID_CHECKBOX2:
//            if(objMsg == CB_MSG_CHECKED)
//            {
//                SetState(pLb, LB_CENTER_ALIGN);
//            }
//            else
//            {
//                ClrState(pLb, LB_CENTER_ALIGN);
//            }
//
//            SetState(pLb, LB_DRAW);
//            return (1);
//
//        case ID_BUTTON_NEXT:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_EDITBOX;       // goto edit box screen
//            }
//
//            return (1);                             // process by default
//
//        case ID_BUTTON_BACK:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_PROGRESSBAR;   // goto progress bar screen
//            }
//
//            return (1);                             // process by default
//
//        default:
//            return (1);                             // process by default
//    }
//}
//
//// Creates the edit box demo screen
//void CreateEditBox(void)
//{
//    static XCHAR    pTempXchar[][2] =  {   {'0',0},
//        {'1',0},
//        {'2',0},
//        {'3',0},
//        {'4',0},
//        {'5',0},
//        {'6',0},
//        {'7',0},
//        {'8',0},
//        {'9',0},
//        {'*',0},
//        {'#',0}
//    };
//
//    GOLFree();          // free memory for the objects in the previous linked list and start new list
//    CreatePage((XCHAR *)EditBoxStr);
//
//    #define EB_ORIGIN_X ((GetMaxX() - 212 + 1) / 2)
//    #define EB_ORIGIN_Y ((40 + GetMaxY() - 195 + 1) / 2)
//    #define KEYSTARTX   EB_ORIGIN_X
//    #define KEYSTARTY   EB_ORIGIN_Y
//    #define KEYSIZEX    53
//    #define KEYSIZEY    39
//    #define MAXCHARSIZE 17
//
//    EbCreate
//    (
//        ID_EDITBOX1,    			// ID
//        KEYSTARTX,
//        KEYSTARTY + 1,
//        KEYSTARTX + 4 * KEYSIZEX,
//        KEYSTARTY + 1 * KEYSIZEY - GOL_EMBOSS_SIZE, // dimension
//        EB_DRAW,         // will be dislayed after creation
//        NULL,
//        MAXCHARSIZE,
//        altScheme
//    );                              // default GOL scheme
//    BtnCreate
//    (
//        ID_KEYPAD + 0,              // ID
//        KEYSTARTX + 1 * KEYSIZEX,
//        KEYSTARTY + 4 * KEYSIZEY,
//        KEYSTARTX + 2 * KEYSIZEX,
//        KEYSTARTY + 5 * KEYSIZEY,   // dimension
//        0,
//        BTN_DRAW,                   // will be dislayed after creation
//        NULL,                       // no bitmap
//        pTempXchar[0],              // text
//        altScheme
//    );                              // alternative GOL scheme
//    BtnCreate
//    (
//        ID_KEYPAD + 1,              // ID
//        KEYSTARTX + 0 * KEYSIZEX,
//        KEYSTARTY + 1 * KEYSIZEY,
//        KEYSTARTX + 1 * KEYSIZEX,
//        KEYSTARTY + 2 * KEYSIZEY,   // dimension
//        0,
//        BTN_DRAW,                   // will be dislayed after creation
//        NULL,                       // no bitmap
//        pTempXchar[1],              // text
//        altScheme
//    );                              // alternative GOL scheme
//    BtnCreate
//    (
//        ID_KEYPAD + 2,              // ID
//        KEYSTARTX + 1 * KEYSIZEX,
//        KEYSTARTY + 1 * KEYSIZEY,
//        KEYSTARTX + 2 * KEYSIZEX,
//        KEYSTARTY + 2 * KEYSIZEY,   // dimension
//        0,
//        BTN_DRAW,                   // will be dislayed after creation
//        NULL,                       // no bitmap
//        pTempXchar[2],              // text
//        altScheme
//    );                              // alternative GOL scheme
//    BtnCreate
//    (
//        ID_KEYPAD + 3,              // ID
//        KEYSTARTX + 2 * KEYSIZEX,
//        KEYSTARTY + 1 * KEYSIZEY,
//        KEYSTARTX + 3 * KEYSIZEX,
//        KEYSTARTY + 2 * KEYSIZEY,   // dimension
//        0,
//        BTN_DRAW,                   // will be dislayed after creation
//        NULL,                       // no bitmap
//        pTempXchar[3],              // text
//        altScheme
//    );                              // alternative GOL scheme
//    BtnCreate
//    (
//        ID_KEYPAD + 4,              // ID
//        KEYSTARTX + 0 * KEYSIZEX,
//        KEYSTARTY + 2 * KEYSIZEY,
//        KEYSTARTX + 1 * KEYSIZEX,
//        KEYSTARTY + 3 * KEYSIZEY,   // dimension
//        0,
//        BTN_DRAW,                   // will be dislayed after creation
//        NULL,                       // no bitmap
//        pTempXchar[4],              // text
//        altScheme
//    );                              // alternative GOL scheme
//    BtnCreate
//    (
//        ID_KEYPAD + 5,              // ID
//        KEYSTARTX + 1 * KEYSIZEX,
//        KEYSTARTY + 2 * KEYSIZEY,
//        KEYSTARTX + 2 * KEYSIZEX,
//        KEYSTARTY + 3 * KEYSIZEY,   // dimension
//        0,
//        BTN_DRAW,                   // will be dislayed after creation
//        NULL,                       // no bitmap
//        pTempXchar[5],              // text
//        altScheme
//    );                              // alternative GOL scheme
//    BtnCreate
//    (
//        ID_KEYPAD + 6,              // ID
//        KEYSTARTX + 2 * KEYSIZEX,
//        KEYSTARTY + 2 * KEYSIZEY,
//        KEYSTARTX + 3 * KEYSIZEX,
//        KEYSTARTY + 3 * KEYSIZEY,   // dimension
//        0,
//        BTN_DRAW,                   // will be dislayed after creation
//        NULL,                       // no bitmap
//        pTempXchar[6],              // text
//        altScheme
//    );                              // alternative GOL scheme
//    BtnCreate
//    (
//        ID_KEYPAD + 7,              // ID
//        KEYSTARTX + 0 * KEYSIZEX,
//        KEYSTARTY + 3 * KEYSIZEY,
//        KEYSTARTX + 1 * KEYSIZEX,
//        KEYSTARTY + 4 * KEYSIZEY,   // dimension
//        0,
//        BTN_DRAW,                   // will be dislayed after creation
//        NULL,                       // no bitmap
//        pTempXchar[7],              // text
//        altScheme
//    );                              // alternative GOL scheme
//    BtnCreate
//    (
//        ID_KEYPAD + 8,              // ID
//        KEYSTARTX + 1 * KEYSIZEX,
//        KEYSTARTY + 3 * KEYSIZEY,
//        KEYSTARTX + 2 * KEYSIZEX,
//        KEYSTARTY + 4 * KEYSIZEY,   // dimension
//        0,
//        BTN_DRAW,                   // will be dislayed after creation
//        NULL,                       // no bitmap
//        pTempXchar[8],              // text
//        altScheme
//    );                              // alternative GOL scheme
//    BtnCreate
//    (
//        ID_KEYPAD + 9,              // ID
//        KEYSTARTX + 2 * KEYSIZEX,
//        KEYSTARTY + 3 * KEYSIZEY,
//        KEYSTARTX + 3 * KEYSIZEX,
//        KEYSTARTY + 4 * KEYSIZEY,   // dimension
//        0,
//        BTN_DRAW,                   // will be dislayed after creation
//        NULL,                       // no bitmap
//        pTempXchar[9],              // text
//        altScheme
//    );                              // alternative GOL scheme
//    BtnCreate
//    (
//        ID_ASTERISK,                // ID
//        KEYSTARTX + 0 * KEYSIZEX,
//        KEYSTARTY + 4 * KEYSIZEY,
//        KEYSTARTX + 1 * KEYSIZEX,
//        KEYSTARTY + 5 * KEYSIZEY,   // dimension
//        0,
//        BTN_DRAW,                   // will be dislayed after creation
//        NULL,                       // no bitmap
//        pTempXchar[10],             // text
//        altScheme
//    );                              // alternative GOL scheme
//    BtnCreate
//    (
//        ID_POUND,                   // ID
//        KEYSTARTX + 2 * KEYSIZEX,
//        KEYSTARTY + 4 * KEYSIZEY,
//        KEYSTARTX + 3 * KEYSIZEX,
//        KEYSTARTY + 5 * KEYSIZEY,   // dimension
//        0,
//        BTN_DRAW,                   // will be dislayed after creation
//        NULL,                       // no bitmap
//        pTempXchar[11],             // text
//        altScheme
//    );                              // alternative GOL scheme
//    BtnCreate
//    (
//        ID_BACKSPACE,               // ID
//        KEYSTARTX + 3 * KEYSIZEX,
//        KEYSTARTY + 1 * KEYSIZEY,
//        KEYSTARTX + 4 * KEYSIZEX,
//        KEYSTARTY + 2 * KEYSIZEY,   // dimension
//        0,
//        BTN_DRAW,                   // will be dislayed after creation
//        NULL,                       // no bitmap
//        (XCHAR *)LeftArrowStr,      // Left Arrow
//        altScheme
//    );                              // alternative GOL scheme
//    BtnCreate
//    (
//        ID_CALL,                    // ID
//        KEYSTARTX + 3 * KEYSIZEX,
//        KEYSTARTY + 2 * KEYSIZEY,
//        KEYSTARTX + 4 * KEYSIZEX,
//        KEYSTARTY + 3 * KEYSIZEY,   // dimension
//        0,
//        BTN_DRAW,                   // will be dislayed after creation
//        (void *) &greenphone,       // use green phone bitmap
//        NULL,                       // text
//        altScheme
//    );                              // alternative GOL scheme
//    BtnCreate
//    (
//        ID_STOPCALL,                // ID
//        KEYSTARTX + 3 * KEYSIZEX,
//        KEYSTARTY + 3 * KEYSIZEY,
//        KEYSTARTX + 4 * KEYSIZEX,
//        KEYSTARTY + 4 * KEYSIZEY,   // dimension
//        0,
//        BTN_DRAW,                   // will be dislayed after creation
//        (void *) &redphone,         // use redphone bitmap
//        NULL,                       // text
//        altScheme
//    );                              // alternative GOL scheme
//    BtnCreate
//    (
//        ID_HOLD,                    // ID
//        KEYSTARTX + 3 * KEYSIZEX,
//        KEYSTARTY + 4 * KEYSIZEY,
//        KEYSTARTX + 4 * KEYSIZEX,
//        KEYSTARTY + 5 * KEYSIZEY,   // dimension
//        0,
//        BTN_DRAW,                   // will be dislayed after creation
//        NULL,                       // no bitmap
//        (XCHAR *)HoldStr,           // "Hld"
//        altScheme
//    );                              // alternative GOL scheme
//}
//
//// Processes messages for the edit box demo screen
//WORD MsgEditBox(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg)
//{
//    EDITBOX     *pEb;
//    SHORT       id;
//    XCHAR       temp;
//    static char status = 0; // status to check if calling, holding or not
//    id = GetObjID(pObj);
//
//    // ignore all touch screen messages to the edit box
//    // since we do not want the caret to show up
//    if ((id == ID_EDITBOX1) && (pMsg->type == TYPE_TOUCHSCREEN))
//    {
//        return 0;
//    }
//
//    // If number key is pressed
//    if(objMsg == BTN_MSG_RELEASED)
//    {
//        if(id >= ID_KEYPAD)
//            if(id < ID_KEYPAD + 10)
//            {
//                if(!status)
//                {
//                    pEb = (EDITBOX *)GOLFindObject(ID_EDITBOX1);
//                    EbAddChar(pEb, '0' + id - ID_KEYPAD);
//                    SetState(pEb, EB_DRAW);
//                }
//
//                return (1);
//            }
//
//	    switch(id)
//	    {
//	        case ID_CALL:
//                pEb = (EDITBOX *)GOLFindObject(ID_EDITBOX1);
//                EbSetText(pEb, (XCHAR *)CallingStr);
//                SetState(pEb, EB_DRAW);
//                status = 1;
//                break;
//
//	        case ID_STOPCALL:
//                pEb = (EDITBOX *)GOLFindObject(ID_EDITBOX1);
//                temp = 0x0000;
//                EbSetText(pEb, &temp);
//                SetState(pEb, EB_DRAW);
//                status = 0;
//                break;
//
//	        case ID_BACKSPACE:
//                if(!status)
//                {
//                    pEb = (EDITBOX *)GOLFindObject(ID_EDITBOX1);
//                    EbDeleteChar(pEb);
//                    SetState(pEb, EB_DRAW);
//                }
//                break;
//
//	        case ID_HOLD:
//                pEb = (EDITBOX *)GOLFindObject(ID_EDITBOX1);
//                if(status == 1)
//                {
//                    EbSetText(pEb, (XCHAR *)HoldingStr);
//                    status = 2;
//                }
//                else if(status == 2)
//                {
//                    EbSetText(pEb, (XCHAR *)CallingStr);
//                    status = 1;
//                }
//
//                SetState(pEb, EB_DRAW);
//                break;
//
//	        case ID_ASTERISK:
//	            if(!status)
//	            {
//                    pEb = (EDITBOX *)GOLFindObject(ID_EDITBOX1);
//                    EbAddChar(pEb, (XCHAR) '*');
//                    SetState(pEb, EB_DRAW);
//	            }
//                break;
//
//	        case ID_POUND:
//	            if(!status)
//	            {
//                    pEb = (EDITBOX *)GOLFindObject(ID_EDITBOX1);
//                    EbAddChar(pEb, (XCHAR) '#');
//                    SetState(pEb, EB_DRAW);
//	            }
//                break;
//
//	        case ID_BUTTON_NEXT:
//                screenState = CREATE_METER;     // goto meter screen
//	            status = 0;
//                break;
//
//	        case ID_BUTTON_BACK:
//                screenState = CREATE_LISTBOX;   // goto list box screen
//	            status = 0;
//                break;
//
//	        default:
//                break;
//	    }
//	}
//	return (1);                         		// process by default
//}
//
///*********************************************************************************/
//
///*********************************************************************************/
//
///*********************************************************************************/
//
///*********************************************************************************/
//
////			START OF DATE AND TIME SETTING
//
///*********************************************************************************/
//#define EB1STARTX       30
//#define EB2STARTX       122
//#define EB3STARTX       200
//#define EBSTARTY        55
//#define EB4STARTX       40
//#define EB5STARTX       125
//#define EB6STARTX       210
//#define EBSTARTY2       110
//
//#define SELECTBTNWIDTH  25
//
//// Items list
//// Months Items list
//const XCHAR MonthItems[] = {'J','a','n',0x000A,
//    'F','e','b',0x000A,
//    'M','a','r',0x000A,
//    'A','p','r',0x000A,
//    'M','a','y',0x000A,
//    'J','u','n',0x000A,
//    'J','u','l',0x000A,
//    'A','u','g',0x000A,
//    'S','e','p',0x000A,
//    'O','c','t',0x000A,
//    'N','o','v',0x000A,
//    'D','e','c',0x0000};
//
//// Days Items list
//const XCHAR DayItems[] = {'0','1',0x000A, '0','2',0x000A, '0','3',0x000A, '0','4',0x000A, '0','5',0x000A,
//    '0','6',0x000A, '0','7',0x000A, '0','8',0x000A, '0','9',0x000A, '1','0',0x000A,
//    '1','1',0x000A, '1','2',0x000A, '1','3',0x000A, '1','4',0x000A, '1','5',0x000A,
//    '1','6',0x000A, '1','7',0x000A, '1','8',0x000A, '1','9',0x000A, '2','0',0x000A,
//    '2','1',0x000A, '2','2',0x000A, '2','3',0x000A, '2','4',0x000A, '2','5',0x000A,
//    '2','6',0x000A, '2','7',0x000A, '2','8',0x000A, '2','9',0x000A, '3','0',0x000A, '3','1',0x0000};
//
//// Year Items list
//const XCHAR YearItems[] = {'0','0',0x000A, '0','1',0x000A, '0','2',0x000A, '0','3',0x000A, '0','4',0x000A,
//    '0','5',0x000A, '0','6',0x000A, '0','7',0x000A, '0','8',0x000A, '0','9',0x000A,
//    '1','0',0x000A, '1','1',0x000A, '1','2',0x000A, '1','3',0x000A, '1','4',0x000A,
//    '1','5',0x000A, '1','6',0x000A, '1','7',0x000A, '1','8',0x000A, '1','9',0x000A, '2','0',0x0000};
//
//#define DTSetText   (XCHAR *)SetDateTimeStr
//#define DTDoneText  (XCHAR *)ExitStr
//#define DTDownArrow (XCHAR *)DownArrowStr
//#define DTUpArrow   (XCHAR *)UpArrowStr
//
//XCHAR       DTPlusSym[] = {'+',0};
//XCHAR       DTMinusSym[] = {'-',0};
//
//// Creates date and time screen
//void CreateDateTime(void)
//{
//    WORD    textWidth, textHeight, tempStrWidth;
//    XCHAR   tempStr[] = {'M',0};
//
//    // free memory for the objects in the previous linked list and start new list
//    GOLFree();
//    RTCCProcessEvents();    // update the global time and date strings
//
//    /* ************************************* */
//
//    /* Create Month, Day and Year Edit Boxes */
//
//    /* ************************************* */
//    tempStrWidth = GetTextWidth(tempStr, altScheme->pFont);
//    textHeight = (GetTextHeight(altScheme->pFont) >> 1) + GetTextHeight(altScheme->pFont) + (GOL_EMBOSS_SIZE << 1);
//
//    WndCreate
//    (
//        ID_WINDOW1,         // ID
//        0,
//        0,
//        GetMaxX(),
//        GetMaxY(),          // dimension
//        WND_DRAW,           // will be dislayed after creation
//        (void *) &mchpIcon, // icon
//        DTSetText,          // set text
//        navScheme
//    );                      // use default scheme
//
//    /* *************************** */
//
//    // create month components
//
//    /* *************************** */
//
//    // months has three characters+space, thus we multiply by four
//    textWidth = (tempStrWidth * 4) + (GOL_EMBOSS_SIZE << 1);
//
//    EbCreate
//    (
//        ID_EB_MONTH,        // ID
//        EB1STARTX,
//        EBSTARTY,
//        EB1STARTX + textWidth,
//        EBSTARTY + textHeight,
//        EB_DRAW,            // will be dislayed after creation
//        NULL,
//        3,                  // max characters is 3
//        altScheme
//    );                      // use alternate scheme
//    BtnCreate
//    (
//        ID_BUTTON_MO,       // button ID
//        EB1STARTX + textWidth + 1,
//        EBSTARTY,
//        EB1STARTX + textWidth + SELECTBTNWIDTH + 1,
//        EBSTARTY + textHeight,
//        0,                  // draw rectangular button
//        BTN_DRAW,           // will be dislayed after creation
//        NULL,               // no bitmap
//        DTDownArrow,        // DOWN arrow as text
//        altScheme
//    );                      // use alternate scheme
//
//    /* *************************** */
//
//    // create day components
//
//    /* *************************** */
//
//    // day has two characters+space, thus we multiply by three
//    textWidth = (tempStrWidth * 3) + (GOL_EMBOSS_SIZE << 1);
//
//    EbCreate
//    (
//        ID_EB_DAY,          // ID
//        EB2STARTX,
//        EBSTARTY,
//        EB2STARTX + textWidth,
//        EBSTARTY + textHeight,
//        EB_DRAW,            // will be dislayed after creation
//        NULL,
//        2,                  // max characters is 3
//        altScheme
//    );                      // use alternate scheme
//    BtnCreate
//    (
//        ID_BUTTON_DY,       // button ID
//        EB2STARTX + textWidth + 1,
//        EBSTARTY,
//        EB2STARTX + textWidth + SELECTBTNWIDTH + 1,
//        EBSTARTY + textHeight,
//        0,                  // draw rectangular button
//        BTN_DRAW,           // will be dislayed after creation
//        NULL,               // no bitmap
//        DTDownArrow,        // DOWN arrow as text
//        altScheme
//    );                      // use alternate scheme
//
//    /* *************************** */
//
//    // create year components
//
//    /* *************************** */
//
//    // year has four characters+space, thus we multiply by five
//    textWidth = (tempStrWidth * 5) + (GOL_EMBOSS_SIZE << 1);
//
//    EbCreate
//    (
//        ID_EB_YEAR,         // ID
//        EB3STARTX,
//        EBSTARTY,
//        EB3STARTX + textWidth,
//        EBSTARTY + textHeight,
//        EB_DRAW,            // will be dislayed after creation
//        NULL,
//        4,                  // max characters is 4
//        altScheme
//    );                      // use alternate scheme
//    BtnCreate
//    (
//        ID_BUTTON_YR,       // button ID
//        EB3STARTX + textWidth + 1,
//        EBSTARTY,
//        EB3STARTX + textWidth + SELECTBTNWIDTH + 1,
//        EBSTARTY + textHeight,
//        0,                  // draw rectangular button
//        BTN_DRAW,           // will be dislayed after creation
//        NULL,               // no bitmap
//        DTDownArrow,        // DOWN arrow as text
//        altScheme
//    );                      // use alternate scheme
//
//    /* ****************************************** */
//
//    /* Create Hour, Minute and Seconds Edit Boxes */
//
//    /* ****************************************** */
//    RTCCProcessEvents();    // update the time and date
//    tempStrWidth = GetTextWidth(tempStr, altScheme->pFont);
//
//    /* *************************** */
//
//    // create hour components
//
//    /* *************************** */
//
//    // items here have 2 characters each so we use 2 as multiplier
//    textWidth = (tempStrWidth * 3) + (GOL_EMBOSS_SIZE << 1);
//
//    EbCreate
//    (
//        ID_EB_HOUR,         // ID
//        EB4STARTX,
//        EBSTARTY2,
//        EB4STARTX + textWidth,
//        EBSTARTY2 + textHeight,
//        EB_DRAW,            // will be dislayed after creation
//        NULL,
//        2,                  // max characters is 2
//        altScheme
//    );                      // use alternate scheme
//    BtnCreate
//    (
//        ID_BUTTONHR_P,      // button ID
//        EB4STARTX + textWidth + 1,
//        EBSTARTY2,
//        EB4STARTX + textWidth + SELECTBTNWIDTH + 1,
//        EBSTARTY2 + (textHeight >> 1),
//        0,                  // draw rectangular button
//        BTN_DRAW,           // will be dislayed after creation
//        NULL,               // no bitmap
//        DTPlusSym,          // plus symbol as text
//        altScheme
//    );                      // use alternate scheme
//    BtnCreate
//    (
//        ID_BUTTONHR_M,      // button ID
//        EB4STARTX + textWidth + 1,
//        EBSTARTY2 + (textHeight >> 1) + 1,
//        EB4STARTX + textWidth + SELECTBTNWIDTH + 1,
//        EBSTARTY2 + textHeight,
//        0,                  // draw rectangular button
//        BTN_DRAW,           // will be dislayed after creation
//        NULL,               // no bitmap
//        DTMinusSym,         // minus symbols as text
//        altScheme
//    );                      // use alternate scheme
//
//    /* *************************** */
//
//    // create minute components
//
//    /* *************************** */
//    EbCreate
//    (
//        ID_EB_MINUTE,       // ID
//        EB5STARTX,
//        EBSTARTY2,
//        EB5STARTX + textWidth,
//        EBSTARTY2 + textHeight,
//        EB_DRAW,            // will be dislayed after creation
//        NULL,
//        2,                  // max characters is 2
//        altScheme
//    );                      // use alternate scheme
//    BtnCreate
//    (
//        ID_BUTTONMN_P,      // button ID
//        EB5STARTX + textWidth + 1,
//        EBSTARTY2,
//        EB5STARTX + textWidth + SELECTBTNWIDTH + 1,
//        EBSTARTY2 + (textHeight >> 1),
//        0,                  // draw rectangular button
//        BTN_DRAW,           // will be dislayed after creation
//        NULL,               // no bitmap
//        DTPlusSym,          // plus symbol as text
//        altScheme
//    );                      // use alternate scheme
//    BtnCreate
//    (
//        ID_BUTTONMN_M,      // button ID
//        EB5STARTX + textWidth + 1,
//        EBSTARTY2 + (textHeight >> 1) + 1,
//        EB5STARTX + textWidth + SELECTBTNWIDTH + 1,
//        EBSTARTY2 + textHeight,
//        0,                  // draw rectangular button
//        BTN_DRAW,           // will be dislayed after creation
//        NULL,               // no bitmap
//        DTMinusSym,         // minus symbols as text
//        altScheme
//    );                      // use alternate scheme
//
//    /* *************************** */
//
//    // create seconds components
//
//    /* *************************** */
//    EbCreate
//    (
//        ID_EB_SECOND,       // ID
//        EB6STARTX,
//        EBSTARTY2,
//        EB6STARTX + textWidth,
//        EBSTARTY2 + textHeight,
//        EB_DRAW,            // will be dislayed after creation
//        NULL,
//        2,                  // max characters is 2
//        altScheme
//    );                      // use alternate scheme
//    BtnCreate
//    (
//        ID_BUTTONSC_P,      // button ID
//        EB6STARTX + textWidth + 1,
//        EBSTARTY2,
//        EB6STARTX + textWidth + SELECTBTNWIDTH + 1,
//        EBSTARTY2 + (textHeight >> 1),
//        0,                  // draw rectangular button
//        BTN_DRAW,           // will be dislayed after creation
//        NULL,               // no bitmap
//        DTPlusSym,          // plus symbol as text
//        altScheme
//    );                      // use alternate scheme
//    BtnCreate
//    (
//        ID_BUTTONSC_M,      // button ID
//        EB6STARTX + textWidth + 1,
//        EBSTARTY2 + (textHeight >> 1) + 1,
//        EB6STARTX + textWidth + SELECTBTNWIDTH + 1,
//        EBSTARTY2 + textHeight,
//        0,                  // draw rectangular button
//        BTN_DRAW,           // will be dislayed after creation
//        NULL,               // no bitmap
//        DTMinusSym,         // minus symbols as text
//        altScheme
//    );                      // use alternate scheme
//
//    //-----------------------------------------------------
//    // Done Button
//    textHeight = GetTextHeight(altScheme->pFont) + (GOL_EMBOSS_SIZE << 1) + 5;
//
//    BtnCreate
//    (
//        ID_BUTTON4,         // button ID
//        EB6STARTX,
//        175,
//        EB6STARTX + textWidth + SELECTBTNWIDTH,
//        175 + textHeight,
//        8,                  // draw rectangular button
//        BTN_DRAW,           // will be dislayed after creation
//        NULL,               // no bitmap
//        DTDoneText,         // set text
//        altScheme
//    );                      // use alternate scheme
//    updateDateTimeEb();
//}
//
///* */
//void updateDateTimeEb(void)
//{
//    OBJ_HEADER  *obj;
//    SHORT       i;
//
//    RTCCProcessEvents();        // update the time and date
//    i = 0;
//    while(i < 12)
//    {
//        dateTimeStr[i] = _time_str[i];
//        dateTimeStr[i + 13] = _date_str[i];
//        i++;
//    }
//
//    dateTimeStr[12] = 0x000A;   // (XCHAR)'\n';
//    dateTimeStr[25] = 0x0000;   // (XCHAR)'\0';
//
//    // update date edit boxes
//    obj = GOLFindObject(ID_EB_MONTH);
//    EbSetText((EDITBOX *)obj, &dateTimeStr[13]);
//    SetState(obj, EB_DRAW);
//
//    obj = GOLFindObject(ID_EB_DAY);
//    EbSetText((EDITBOX *)obj, &dateTimeStr[17]);
//    SetState(obj, EB_DRAW);
//
//    obj = GOLFindObject(ID_EB_YEAR);
//    EbSetText((EDITBOX *)obj, &dateTimeStr[21]);
//    SetState(obj, EB_DRAW);
//
//    // update time edit boxes
//    obj = GOLFindObject(ID_EB_HOUR);
//    EbSetText((EDITBOX *)obj, &dateTimeStr[4]);
//    SetState(obj, EB_DRAW);
//
//    obj = GOLFindObject(ID_EB_MINUTE);
//    EbSetText((EDITBOX *)obj, &dateTimeStr[7]);
//    SetState(obj, EB_DRAW);
//
//    obj = GOLFindObject(ID_EB_SECOND);
//    EbSetText((EDITBOX *)obj, &dateTimeStr[10]);
//    SetState(obj, EB_DRAW);
//}
//
///* this will show the pull down menus */
//void ShowPullDownMenu(void)
//{
//    WORD    textWidth = 0, textHeight, tempStrWidth;
//    LISTBOX *pLb;
//    XCHAR   *pItems = NULL;
//    XCHAR   tempString[] = {'M',0};
//
//    pListSaved = GOLGetList();
//    GOLNewList();
//
//    textHeight = GetTextHeight(altScheme->pFont) + (GOL_EMBOSS_SIZE << 1);
//
//    // Note: pDwnBottom, pDwnTop, pDwnLeft and pDwnRight are globals that will
//    // 		 be used to redraw the area where the pulldown menu covered.
//    pDwnBottom = 230;
//    pDwnTop = EBSTARTY;
//
//    tempStrWidth = GetTextWidth(tempString, altScheme->pFont);
//    switch(DateItemID)
//    {
//        case ID_EB_MONTH:
//            textWidth = (tempStrWidth * 4) + (GOL_EMBOSS_SIZE << 1);
//            pDwnLeft = EB1STARTX;
//            pDwnRight = EB1STARTX + textWidth + SELECTBTNWIDTH;
//            pItems = (XCHAR *)MonthItems;
//            break;
//
//        case ID_EB_DAY:
//            textWidth = (tempStrWidth * 3) + (GOL_EMBOSS_SIZE << 1);
//            pDwnLeft = EB2STARTX;
//            pDwnRight = EB2STARTX + textWidth + SELECTBTNWIDTH;
//            pItems = (XCHAR *)DayItems;
//            break;
//
//        case ID_EB_YEAR:
//            textWidth = (tempStrWidth * 5) + (GOL_EMBOSS_SIZE << 1);
//            pDwnLeft = EB3STARTX;
//            pDwnRight = EB3STARTX + textWidth + SELECTBTNWIDTH;
//            pItems = (XCHAR *)YearItems;
//            break;
//    }
//
//    pLb = (LISTBOX *)LbCreate
//        (
//            ID_LISTBOX1,                            // List Box ID
//            pDwnLeft,                               // left
//            pDwnTop + textHeight,                   // top
//            pDwnRight - SELECTBTNWIDTH,             // right
//            pDwnBottom,                             // bottom dimension
//            LB_DRAW | LB_SINGLE_SEL,                // draw after creation, single selection
//            pItems,                                 // items list
//            altScheme
//        );
//
//    SldCreate
//    (
//        ID_SLIDER1,                                 // Slider ID
//        pDwnRight - SELECTBTNWIDTH + 1,
//        pDwnTop + (textHeight << 1),
//        pDwnRight,
//        pDwnBottom - textHeight,
//        SLD_DRAW | SLD_SCROLLBAR | SLD_VERTICAL,    // vertical, draw after creation
//        LbGetCount(pLb),                            // range
//        5,                      // page
//        LbGetCount(pLb) - 1,    // pos
//        altScheme
//    );
//
//    BtnCreate
//    (
//        ID_BUTTON_DATE_UP,      // up button ID
//        pDwnRight - SELECTBTNWIDTH + 1,
//        pDwnTop + textHeight,
//        pDwnRight,
//        pDwnTop + (textHeight << 1),
//        0,
//        BTN_DRAW,               // draw after creation
//        NULL,                   // no bitmap
//        DTUpArrow,              // text
//        altScheme
//    );
//
//    BtnCreate
//    (
//        ID_BUTTON_DATE_DN,      // down button ID
//        pDwnRight - SELECTBTNWIDTH + 1,
//        pDwnBottom - textHeight,
//        pDwnRight,
//        pDwnBottom,
//        0,
//        BTN_DRAW,               // draw after creation
//        NULL,                   // no bitmap
//        DTDownArrow,            // text
//        altScheme
//    );
//}
//
///* */
//WORD RemovePullDownMenu(void)
//{
//    OBJ_HEADER  *pObjTemp;
//
//    // check if objects has been hidden
//    pObjTemp = GOLGetList();
//    while(pObjTemp)
//    {   // parse the active list
//        if(GetState(pObjTemp, HIDE))    // an object is still not hidden
//            return (0);                 // go back without changing state
//        pObjTemp = pObjTemp->pNxtObj;   // go to next object
//    }
//
//    // all objects are hidden we can now remove the list
//    GOLFree();                          // remove the list of pull down menu
//    GOLSetList(pListSaved);             // set active list back to saved list
//
//    // redraw objects that were overlapped by pulldown menu
//    GOLRedrawRec(pDwnLeft, pDwnTop, pDwnRight, pDwnBottom);
//    // reset the window so it will not be redrawn
//    ClrState(GOLFindObject(ID_WINDOW1), WND_DRAW);
//
//    // must reset the pressed button, this code is more compact than searching
//    // which one of the three is pressed.
//    pObjTemp = GOLFindObject(ID_BUTTON_MO);
//    ClrState(pObjTemp, BTN_PRESSED);
//    pObjTemp = GOLFindObject(ID_BUTTON_YR);
//    ClrState(pObjTemp, BTN_PRESSED);
//    pObjTemp = GOLFindObject(ID_BUTTON_DY);
//    ClrState(pObjTemp, BTN_PRESSED);
//
//    updateDateTimeEb();                 // Update the edit boxes to reflect the new dates
//    return (1);                         // go back normally
//}
//
///* this selects the new month or day or year from the list box*/
//WORD MsgSetDate(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg)
//{
//    LISTBOX     *pLb;
//    SLIDER      *pSld;
//    OBJ_HEADER  *pObjHide;
//    LISTITEM    *pItemSel;
//
//    pLb = (LISTBOX *)GOLFindObject(ID_LISTBOX1);
//    pSld = (SLIDER *)GOLFindObject(ID_SLIDER1);
//
//    switch(GetObjID(pObj))
//    {
//        case ID_LISTBOX1:
//            if(pMsg->uiEvent == EVENT_MOVE)
//            {
//                pMsg->uiEvent = EVENT_PRESS;    // change event for listbox
//
//                // Process message by default
//                LbMsgDefault(objMsg, (LISTBOX *)pObj, pMsg);
//
//                // Set new list box position
//                SldSetPos(pSld, LbGetCount(pLb) - LbGetFocusedItem(pLb) - 1);
//                SetState(pSld, SLD_DRAW_THUMB);
//                pMsg->uiEvent = EVENT_MOVE;     // restore event for listbox
//            }
//            else if(pMsg->uiEvent == EVENT_PRESS)
//            {
//
//                // call the message default processing of the list box to select the item
//                LbMsgDefault(objMsg, (LISTBOX *)pObj, pMsg);
//            }
//            else if(pMsg->uiEvent == EVENT_RELEASE)
//            {
//                pObjHide = GOLGetList();        // hide all the objects in the current list
//                while(pObjHide)
//                {                               // set all objects with HIDE state
//                    SetState(pObjHide, HIDE);
//                    pObjHide = pObjHide->pNxtObj;
//                }
//
//                pItemSel = LbGetSel(pLb, NULL); // get the selected item
//                if(pItemSel != NULL)            // process only when an item was selected
//                    UpdateRTCCDates(pLb);       // update the RTCC values
//                screenState = HIDE_DATE_PDMENU; // go to hide state
//            }
//
//            // The message was processed
//            return (0);
//
//        case ID_SLIDER1:
//
//			if((objMsg == SLD_MSG_INC) || (objMsg == SLD_MSG_DEC))
//            {
//	            // Process message by default
//	            SldMsgDefault(objMsg, (SLIDER *)pObj, pMsg);
//
//	            // Set new list box position
//	            if(LbGetFocusedItem(pLb) != LbGetCount(pLb) - SldGetPos(pSld))
//	            {
//	                LbSetFocusedItem(pLb, LbGetCount(pLb) - SldGetPos(pSld));
//	                SetState(pLb, LB_DRAW_ITEMS);
//	            }
//			}
//
//            // The message was processed
//            return (0);
//
//        case ID_BUTTON_DATE_UP:                 // slider button up was pressed
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                LbSetFocusedItem(pLb, LbGetFocusedItem(pLb) - 1);
//                SetState(pLb, LB_DRAW_ITEMS);
//                SldSetPos(pSld, SldGetPos(pSld) + 1);
//                SetState(pSld, SLD_DRAW_THUMB);
//            }
//
//            return (1);
//
//        case ID_BUTTON_DATE_DN:                 // slider button down was pressed
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                LbSetFocusedItem(pLb, LbGetFocusedItem(pLb) + 1);
//                SetState(pLb, LB_DRAW_ITEMS);
//                SldSetPos(pSld, SldGetPos(pSld) - 1);
//                SetState(pSld, SLD_DRAW_THUMB);
//            }
//
//            return (1);
//    }
//
//    return (1);
//}
//
//// Processes messages for date and time screen
//WORD MsgDateTime(WORD objMsg, OBJ_HEADER *pObj)
//{
//    char    hour = 0, minute = 0, second = 0;
//    WORD    btnID;
//    WORD    ebID = 0, i;
//
//    switch(btnID = GetObjID(pObj))
//    {
//        // ignore all touch screen messages to all edit boxes
//        // since we do not want the caret to show up
//        case ID_EB_MONTH:
//        case ID_EB_DAY:
//        case ID_EB_YEAR:
//        case ID_EB_HOUR:
//        case ID_EB_MINUTE:
//        case ID_EB_SECOND:
//            return 0;
//
//        case ID_BUTTON4:                    // exit setting of date and time
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = prevState;    // goto last state screen
//                return (1);
//            }
//
//            break;
//
//        //////////////////////////////////////////////////////////////////////////
//        // 		Date update: this will create the pulldown menu
//        		//////////////////////////////////////////////////////////////////////////
//        case ID_BUTTON_MO:                  // month is selected show the pull down menu
//            if(objMsg == BTN_MSG_PRESSED)
//            {
//                DateItemID = ID_EB_MONTH;
//                return (1);
//            }
//
//            break;
//
//        case ID_BUTTON_DY:                  // month is selected show the pull down menu
//            if(objMsg == BTN_MSG_PRESSED)
//            {
//                DateItemID = ID_EB_DAY;
//                return (1);
//            }
//
//            break;
//
//        case ID_BUTTON_YR:                  // month is selected show the pull down menu
//            if(objMsg == BTN_MSG_PRESSED)
//            {
//                DateItemID = ID_EB_YEAR;
//                return (1);
//            }
//
//            break;
//
//        //////////////////////////////////////////////////////////////////////////
//        // 		Time update through the '+' and '-' buttons
//        		//////////////////////////////////////////////////////////////////////////
//        case ID_BUTTONHR_P:                 // increment hour value
//            if(objMsg == BTN_MSG_PRESSED)
//            {
//                hour = +1;
//                ebID = ID_EB_HOUR;
//                i = 4;
//            }
//
//            break;
//
//        case ID_BUTTONHR_M:                 // decrement hour value
//            if(objMsg == BTN_MSG_PRESSED)
//            {
//                hour = -1;
//                ebID = ID_EB_HOUR;
//                i = 4;
//            }
//
//            break;
//
//        case ID_BUTTONMN_P:                 // increment minute value
//            if(objMsg == BTN_MSG_PRESSED)
//            {
//                minute = +1;
//                ebID = ID_EB_MINUTE;
//                i = 7;
//            }
//
//            break;
//
//        case ID_BUTTONMN_M:                 // decrement minute value
//            if(objMsg == BTN_MSG_PRESSED)
//            {
//                minute = -1;
//                ebID = ID_EB_MINUTE;
//                i = 7;
//            }
//
//            break;
//
//        case ID_BUTTONSC_P:                 // increment seconds value
//            if(objMsg == BTN_MSG_PRESSED)
//            {
//                second = +1;
//                ebID = ID_EB_SECOND;
//                i = 10;
//            }
//
//            break;
//
//        case ID_BUTTONSC_M:                 // decrement seconds value
//            if(objMsg == BTN_MSG_PRESSED)
//            {
//                second = -1;
//                ebID = ID_EB_SECOND;
//                i = 10;
//            }
//
//            break;
//
//        default:
//            ebID = 0;
//            break;
//    }
//
//    if(ebID)
//    {   // check if time was modified
//        mRTCCOff();
//        RTCCSetBinHour(mRTCCGetBinHour() + hour);   // update RTCC registers
//        RTCCSetBinMin(mRTCCGetBinMin() + minute);
//        RTCCSetBinSec(mRTCCGetBinSec() + second);
//        mRTCCSet();             // copy the new values to the RTCC registers
//
//        // update the edit box that was changed. This is done to immediately update
//        // the values on the edit box. The normal update by updateDateTimeEb() is done
//        // for every second. This may be too long to wait when the increment or decrement
//        // was successfully performed.
//        RTCCProcessEvents();    // update string values
//        updateDateTimeEb();
//    }
//
//    return (1);
//}
//
////void UpdateRTCCDates(XCHAR *pText, LISTBOX* pLb) {
//void UpdateRTCCDates(LISTBOX *pLb)
//{
//    static char value;
//    char        ch;
//    XCHAR       *pItemText;
//
//    // get the selected item
//    pItemText = LbGetSel(pLb, pLb->pItemList)->pText;
//    switch(DateItemID)
//    {
//        default:
//
//        case ID_EB_MONTH:
//            value = LbGetFocusedItem(pLb) + 1;  // get the selected month item +1 is needed since
//
//            // RTCC stores months from index 1 as january
//            RTCCSetBinMonth(value);             // set the month value in RTCC module
//            RTCCCalculateWeekDay();             // calculate the weekday from this new value
//            break;
//
//        case ID_EB_YEAR:
//        case ID_EB_DAY:
//            ch = *pItemText++;                  // get the first character
//            value = (ch - 48) * 10;             // get the value of the first character
//            ch = *pItemText;                    // get the next character
//            value = value + (ch - 48);          // add the value of the second character to the first one
//            if(DateItemID == ID_EB_DAY)
//                RTCCSetBinDay(value);           // set the day value in the RTCC module
//            else
//            {
//                RTCCSetBinYear(value);          // set the day value in the RTCC module
//            }
//
//            RTCCCalculateWeekDay();             // calculate the weekday from this new value
//            break;
//    }
//
//    mRTCCSet(); // copy the new values to the RTCC registers
//}
//
///*********************************************************************************/
//
////			END OF DATE AND TIME SETTING
//
///*********************************************************************************/
//
///*********************************************************************************/
//
///*********************************************************************************/
//
///*********************************************************************************/
//#define MAXMETER1VALUE  150
//#define MAXMETER2VALUE  30
//
//#define MINMETER1VALUE  0
//#define MINMETER2VALUE  0
//
//// Creates meter screen
//void CreateMeter(void)
//{
//    #define MTR_ORIGIN_X    ((GetMaxX() - 260 + 1) / 2)
//    #define MTR_ORIGIN_Y    (((40 + GetMaxY() - 180 + 1) / 2) - 10)
//
//    METER   *pMtr;
//
//    GOLFree();                  // free memory for the objects in the previous linked list and start new list
//    CreatePage((XCHAR *)MeterStr);       // CreatePage("Meter");
//    pMtr = MtrCreate
//        (
//            ID_METER1,
//            MTR_ORIGIN_X + 0,
//            MTR_ORIGIN_Y + 0,
//            MTR_ORIGIN_X + 128,
//            MTR_ORIGIN_Y + 130, // set dimension
//            MTR_DRAW | MTR_RING | MTR_ACCURACY, // draw meter object with ring scale & accuracy set
//            MINMETER1VALUE,                     // set initial value
//            MINMETER1VALUE,                     // meter minimum value
//            MAXMETER1VALUE,                     // meter maximum value
//            NULL,
//            NULL,
//            (XCHAR *)Meter1Str,                          // "METER1"
//            meterScheme
//        );                      // alternative GOL scheme
//
//    // set scaling values
//    MtrSetScaleColors(pMtr, BRIGHTGREEN, BRIGHTGREEN, BRIGHTGREEN, BRIGHTGREEN, BRIGHTYELLOW, BRIGHTRED);
//
//    // set title and values fonts
//    MtrSetTitleFont(pMtr, (void *)ptrSmallAsianFont);
//    MtrSetValueFont(pMtr, (void *)ptrSmallAsianFont);
//
//    pMtr = MtrCreate
//        (
//            ID_METER2,
//            MTR_ORIGIN_X + 130,
//            MTR_ORIGIN_Y + 0,
//            MTR_ORIGIN_X + 258,
//            MTR_ORIGIN_Y + 130, // set dimension
//            MTR_DRAW,           // draw normal meter object
//            MINMETER2VALUE,     // set initial value
//            MINMETER2VALUE,     // set minimum value
//            MAXMETER2VALUE,     // set maximum value
//            NULL,
//            NULL,
//            (XCHAR *)Meter2Str,          // "METER2"
//            meterScheme
//        );                      // alternative GOL scheme
//
//    // set title and values fonts
//    MtrSetTitleFont(pMtr, (void *) &GOLSmallFont);
//    MtrSetValueFont(pMtr, (void *) &GOLSmallFont);
//
//    BtnCreate
//    (
//        ID_BUTTON1,             // button ID
//        MTR_ORIGIN_X + 20,
//        MTR_ORIGIN_Y + 165,     // left, top corner
//        MTR_ORIGIN_X + 100,
//        MTR_ORIGIN_Y + 195,     // right, bottom corner
//        0,                      // draw rectangular button
//        BTN_DRAW | BTN_TOGGLE,  // will be dislayed after creation
//        NULL,                   // no bitmap
//        (XCHAR *)DecelStr,               // decelerate
//        altScheme
//    );                          // use alternate scheme
//    BtnCreate
//    (
//        ID_BUTTON2,             // button ID
//        MTR_ORIGIN_X + 150,
//        MTR_ORIGIN_Y + 165,     // left, top corner
//        MTR_ORIGIN_X + 230,
//        MTR_ORIGIN_Y + 195,     // right, bottom corner
//        0,                      // draw rectangular button
//        BTN_DRAW | BTN_TOGGLE,  // will be dislayed after creation
//        NULL,                   // no bitmap
//        (XCHAR *)DecelStr,               // decelerate
//        altScheme
//    );                          // use alternate scheme
//    DmCreate
//    (
//        ID_DIGITALMETER1,
//        MTR_ORIGIN_X + 20,
//        MTR_ORIGIN_Y + 140,     // left, top corner
//        MTR_ORIGIN_X + 100,
//        MTR_ORIGIN_Y + 160,     // right, bottom corner
//        DM_DRAW | DM_CENTER_ALIGN | DM_FRAME,
//        0,
//        3,
//        1,
//        alt5Scheme
//    );
//
//    DmCreate
//    (
//        ID_DIGITALMETER2,
//        MTR_ORIGIN_X + 150,
//        MTR_ORIGIN_Y + 140,     // left, top corner
//        MTR_ORIGIN_X + 230,
//        MTR_ORIGIN_Y + 160,     // right, bottom corner
//        DM_DRAW | DM_CENTER_ALIGN | DM_FRAME,
//        0,
//        2,
//        0,
//        alt5Scheme
//    );
//}
//
//// Processes messages for meter screen
//WORD MsgMeter(WORD objMsg, OBJ_HEADER *pObj)
//{
//    switch(GetObjID(pObj))
//    {
//        case ID_BUTTON_NEXT:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_DIAL;                      // goto dial screen
//            }
//
//            return (1);                                         // process by default
//
//        case ID_BUTTON1:
//        case ID_BUTTON2:
//            if(objMsg == BTN_MSG_PRESSED)
//            {
//                BtnSetText((BUTTON *)pObj, (XCHAR *)AccelStr);  // set text to accelerate
//            }
//
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                BtnSetText((BUTTON *)pObj, (XCHAR *)DecelStr);  // set text to decelerate
//            }
//
//            return (1);                         // process by default
//
//        case ID_BUTTON_BACK:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_EDITBOX;   // goto edit box screen
//            }
//
//            return (1);                         // process by default
//
//        default:
//            return (1);                         // process by default
//    }
//}
//
//// this updates the meters on the screen
//void UpdateMeter(void)
//{
//    OBJ_HEADER  *pObj, *pDigMtrObj1, *pDigMtrObj2;
//    METER       *pMtrObj;
//    WORD        i, value;
//
//    pDigMtrObj1 = GOLFindObject(ID_DIGITALMETER1);
//    pDigMtrObj2 = GOLFindObject(ID_DIGITALMETER2);
//
//    /* Meter 1 is controlled by ID_BUTTON1
//  	   Meter 2 is controlled by ID_BUTTON2
//	   Both meters goes from 0 to maximum when their respective
//	   buttons are pressed.	Both button have a toggle property. So
//	   when pressed it will remain to be pressed until the meter has reached
//	   the maximum value. The only difference is that ID_BUTTON1 is controlled
//	   by the code while ID_BUTTON2 is manually controlled.
//	*/
//    for(i = ID_BUTTON1; i < ID_BUTTON2 + 1; i++)
//    {
//        pObj = GOLFindObject(i);
//
//        if(i == ID_BUTTON1)
//        {
//            pMtrObj = (METER *)GOLFindObject(ID_METER1);    // get meter 1 pointer
//            value = MtrGetVal(pMtrObj);                     // get current value
//            if(value == MINMETER1VALUE)
//            {   // when zero turn on ID_BUTTON1
//                BtnSetText((BUTTON *)pObj, (XCHAR *)AccelStr);  // set text to accelerate
//                SetState(pObj, BTN_PRESSED | BTN_DRAW);
//            }
//
//            if(value == MAXMETER1VALUE)
//            {   // when maximum turn off ID_BUTTON1
//                BtnSetText((BUTTON *)pObj, (XCHAR *)DecelStr);  // set text to decelerate
//                ClrState(pObj, BTN_PRESSED);
//                SetState(pObj, BTN_DRAW);
//            }
//
//            if(GetState(pObj, BTN_PRESSED))                 // increment meter value when button
//                value += 2;                                 // is pressed
//            else
//                value -= 2;
//            MtrSetVal(pMtrObj, value);                      // decrement meter value when button
//            DmSetValue((DIGITALMETER *)pDigMtrObj1, value);
//            SetState(pDigMtrObj1, DM_UPDATE);
//            SetState(pMtrObj, MTR_DRAW_UPDATE);             // is released
//        }
//        else
//        {
//            pMtrObj = (METER *)GOLFindObject(ID_METER2);        // get meter 2 pointer
//            value = MtrGetVal(pMtrObj);                         // get meter current value
//            if(GetState(pObj, BTN_PRESSED))
//            {   // check if ID_BUTTON2 is pressed
//                MtrSetVal(pMtrObj, value + 1);      // increment value of meter
//                DmSetValue((DIGITALMETER *)pDigMtrObj2, MtrGetVal(pMtrObj));
//                SetState(pMtrObj, MTR_DRAW_UPDATE); // redraw meter
//                SetState(pDigMtrObj2, DM_UPDATE);
//            }
//            else
//            {
//                if(value > 0)
//                {   // if ID_BUTTON2 is released
//                    MtrSetVal(pMtrObj, value - 1);      // decrement meter if not yet zero
//                    DmSetValue((DIGITALMETER *)pDigMtrObj2, MtrGetVal(pMtrObj));
//                    SetState(pMtrObj, MTR_DRAW_UPDATE); // redraw meter
//                    SetState(pDigMtrObj2, DM_UPDATE);
//                }
//            }
//
//            if(value == MAXMETER2VALUE)
//            {   // check if meter 2 reached max value
//                ClrState(pObj, BTN_PRESSED);                    // release ID_BUTTON2 when max is reached
//                BtnSetText((BUTTON *)pObj, (XCHAR *)DecelStr);  // set text to decelerate
//                SetState(pObj, BTN_DRAW);                       // redraw button
//            }
//        }
//    }
//}
//
//// Creates dial screen
//void CreateDial(void)
//{
//    #define DIAL_ORIGIN_X   ((GetMaxX() - 247 + 1) / 2)
//    #define DIAL_ORIGIN_Y   ((40 + GetMaxY() - 143 + 1) / 2)
//
//
//    GOLFree();                          // free memory for the objects in the previous linked list and start new list
//    #if !(defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__) || defined(__PIC24FJ256DA210__) || defined(MEB_BOARD)|| defined(GFX_PICTAIL_LCC)||defined(__32MX250F128D__))
//    TRISA = 0xFF80;                     // set IO pins (0:6) to output mode,
//
//    // pin 7 is used as side button S5 switch for press and release
//    LATA = 0x0001;                      // light only one LED
//    #endif
//    CreatePage((XCHAR *)DialStr);       //
//    RdiaCreate
//    (
//        ID_ROUNDDIAL,                   // ID
//        DIAL_ORIGIN_X + 50,
//        DIAL_ORIGIN_Y + 72,
//        55,                             // dimensions
//        RDIA_DRAW,                      // draw after creation
//        1,                              // resolution
//        400,                            // initial value
//        700,                            // maximum value
//        altScheme
//    );                                  // use alternative scheme
//    MtrCreate
//    (
//        ID_METER1,
//        DIAL_ORIGIN_X + 112,
//        DIAL_ORIGIN_Y + 0,
//        DIAL_ORIGIN_X + 247,
//        DIAL_ORIGIN_Y + 135,            // set dimension
//        MTR_DRAW,                       // draw object after creation
//        400,                            // set initial value
//        0,                              // set minimum value
//        700,                            // set maximum value
//        (void *) &GOLFontDefault,       // set title font
//        (void *) &ptrSmallAsianFont,    // set value font
//        (XCHAR *)ValueLabelStr,         // "VALUE"
//        meterScheme
//    );  // alternative GOL scheme
//
//    // set scaling values
//    MtrSetScaleColors
//    (
//        ((METER *)GOLFindObject(ID_METER1)),
//        BRIGHTGREEN,
//        BRIGHTGREEN,
//        BRIGHTGREEN,
//        BRIGHTBLUE,
//        BRIGHTYELLOW,
//        BRIGHTRED
//    );
//
//    // set values fonts
//    MtrSetValueFont(GOLFindObject(ID_METER1), (void *) &GOLSmallFont);
//}
//
//// Processes messages for dial screen
//WORD MsgDial(WORD objMsg, OBJ_HEADER *pObj)
//{
//    OBJ_HEADER  *pMtrObj;
//    SHORT       dialVal;
//
//    switch(GetObjID(pObj))
//    {
//        case ID_ROUNDDIAL:
//            dialVal = RdiaGetVal((ROUNDDIAL *)pObj);
//            pMtrObj = GOLFindObject(ID_METER1);
//            MtrSetVal((METER *)pMtrObj, dialVal);
//            SetState(pMtrObj, MTR_DRAW_UPDATE);
//            if(objMsg == RD_MSG_CLOCKWISE)
//                if(dialVal == 700)
//                    return (0);
//            if(objMsg == RD_MSG_CTR_CLOCKWISE)
//                if(dialVal == 0)
//                    return (0);
//
//            dialVal = (dialVal - 1) % 70;       // -1 is used to avoid 70 which is also 0 after mod.
//            #if !(defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__) || defined(__PIC24FJ256DA210__) || defined(MEB_BOARD)|| defined(GFX_PICTAIL_LCC)||defined(__32MX250F128D__))
//            if(dialVal <= 10)
//                LATA = 0x0001;                  // light LED 0
//            else if(dialVal <= 20)
//                LATA = 0x0002;                  // light LED 1
//            else if(dialVal <= 30)
//                LATA = 0x0004;                  // light LED 2
//            else if(dialVal <= 40)
//                LATA = 0x0008;                  // light LED 3
//            else if(dialVal <= 50)
//                LATA = 0x0010;                  // light LED 4
//            else if(dialVal <= 60)
//                LATA = 0x0020;                  // light LED 5
//            else if(dialVal <= 70)
//                LATA = 0x0040;                  // light LED 6
//            #endif
//            break;                              // process by default
//
//        case ID_BUTTON_NEXT:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                #if !(defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__) || defined(__PIC24FJ256DA210__) || defined(MEB_BOARD)|| defined(GFX_PICTAIL_LCC)||defined(__32MX250F128D__))
//                LATA = 0xFF00;                  // turn off all LED
//                TRISA = 0xFFFF;                 // set IO pin to input mode
//                #endif
//                screenState = CREATE_PICTURE;   // goto picture control screen
//            }
//
//            break;                              // process by default
//
//        case ID_BUTTON_BACK:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                #if !(defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__) || defined(__PIC24FJ256DA210__) || defined(MEB_BOARD)|| defined(GFX_PICTAIL_LCC)||defined(__32MX250F128D__))
//                LATA = 0xFF00;                  // turn off all LED
//                TRISA = 0xFFFF;                 // set IO pin to input mode
//                #endif
//                screenState = CREATE_METER;     // goto meter screen
//            }
//
//            break;                              // process by default
//
//        default:
//            break;                              // process by default
//    }
//
//    return (1);
//}
//
///* */
//void CreatePicture(void)
//{
//    #define PIC_ORIGIN_X    ((GetMaxX() - 190 + 1) / 2)
//    #define PIC_ORIGIN_Y    ((40 + GetMaxY() - 170 + 1) / 2)
//
//    GOLFree();                                      // free memory for the objects in the previous linked list and start new list
//    CreatePage((XCHAR *)PictureStr);                // CreatePage("Picture control");
//    pPicture = PictCreate
//        (
//            ID_PICTURE1,                            // ID
//            PIC_ORIGIN_X + 0,
//            PIC_ORIGIN_Y + 0,
//            PIC_ORIGIN_X + 155,
//            PIC_ORIGIN_Y + 120,                     // dimension
//            PICT_DRAW | PICT_FRAME,                 // will be dislayed, has frame
//            1,                                      // scale factor is x1
//            (void *) &Engine1,                      // bitmap
//            altScheme
//        );                                          // default GOL scheme
//    pSlider = SldCreate
//        (
//            ID_SLIDER1,                             // ID
//            PIC_ORIGIN_X + 160,
//            PIC_ORIGIN_Y + 0,
//            PIC_ORIGIN_X + 190,
//            PIC_ORIGIN_Y + 120,                     // dimension
//            SLD_DRAW | SLD_DISABLED | SLD_VERTICAL, // draw with disabled state
//            50,                 // range
//            1,                  // page
//            25,                 // pos
//            altScheme
//        );                      // alternative GOL scheme
//    CbCreate
//    (
//        ID_CHECKBOX1,           // ID
//        PIC_ORIGIN_X - 20,
//        PIC_ORIGIN_Y + 130,
//        PIC_ORIGIN_X + 80,
//        PIC_ORIGIN_Y + 170,     // dimension
//        CB_DRAW,                // will be dislayed after creation
//        (XCHAR *)ScaleStr,      // "Scale"
//        altScheme
//    );                          // alternative GOL scheme
//    CbCreate
//    (
//        ID_CHECKBOX2,           // ID
//        PIC_ORIGIN_X + 90,
//        PIC_ORIGIN_Y + 130,
//        PIC_ORIGIN_X + 220,
//        PIC_ORIGIN_Y + 170,     // dimension
//        CB_DRAW,                // will be dislayed after creation
//        (XCHAR *)AnimateStr,    // "Animate"
//        altScheme
//    );                          // alternative GOL scheme
//}
//
///* */
//WORD MsgPicture(WORD objMsg, OBJ_HEADER *pObj)
//{
//    switch(GetObjID(pObj))
//    {
//        case ID_CHECKBOX1:
//            if(objMsg == CB_MSG_CHECKED)
//            {                               // set new scale factor
//                PictSetScale(pPicture, 2);  // x2
//            }
//            else
//            {
//                PictSetScale(pPicture, 1);  // x1
//            }
//
//            SetState(pPicture, PICT_DRAW);  // set redraw state
//            return (1);                     // process by default
//
//        case ID_CHECKBOX2:
//            if(objMsg == CB_MSG_CHECKED)
//            {                               // switch on/off animation
//                ClrState(pSlider, SLD_DISABLED);            // enable slider
//                SetState(pSlider, SLD_DRAW);                // redraw slider to show new state
//                animate = 1;
//            }
//            else
//            {
//                SetState(pSlider, SLD_DISABLED | SLD_DRAW); // disable the slider and redraw
//                animate = 0;
//            }
//
//            return (1);                             // process by default
//
//        case ID_BUTTON_NEXT:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_CUSTOMCONTROL; // goto cutom control screen
//                animate = 0;                        // switch off animation
//            }
//
//            return (1);                             // process by default
//
//        case ID_BUTTON_BACK:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_DIAL;          // goto dial screen
//                animate = 0;                        // switch off animation
//            }
//
//            return (1);                             // process by default
//
//        default:
//            return (1);                             // process by default
//    }
//}
//
//// Creates custom control screen
//void CreateCustomControl(void)
//{
//    GOLFree();                                              // free memory for the objects in the previous linked list and start new list
//    CreatePage((XCHAR *)CustomStr);                         // CreatePage("Custom control");
//    CcCreate
//    (
//        ID_CUSTOM1,                                         // ID
//        CC_ORIGIN_X + 30,
//        CC_ORIGIN_Y + 0,
//        CC_ORIGIN_X + 150,
//        CC_ORIGIN_Y + 120,                                  // dimension
//        CC_DRAW,                                            // will be dislayed after creation
//        alt3Scheme
//    );                                                      // use alternate 3 scheme
//    RbCreate
//    (
//        ID_RADIOBUTTON1,                                    // ID
//        CC_ORIGIN_X - 20,
//        CC_ORIGIN_Y + 130,
//        CC_ORIGIN_X + 80,
//        CC_ORIGIN_Y + 150,                                  // dimension
//        RB_DRAW | RB_GROUP,                                 // will be dislayed and focused after creation
//        // first button in the group
//        (XCHAR *)HeavyLoadStr, // "Heavy Load"
//        alt2Scheme
//    );                          // alternative GOL scheme
//    RbCreate
//    (
//        ID_RADIOBUTTON2,        // ID
//        CC_ORIGIN_X - 20,
//        CC_ORIGIN_Y + 155,
//        CC_ORIGIN_X + 80,
//        CC_ORIGIN_Y + 175,      // dimension
//        RB_DRAW | RB_CHECKED,   // will be dislayed and checked after creation
//        (XCHAR *)NormalLoadStr, // "Normal Load"
//        alt2Scheme
//    );                          // alternative GOL scheme
//    RbCreate
//    (
//        ID_RADIOBUTTON3,        // ID
//        CC_ORIGIN_X + 100,
//        CC_ORIGIN_Y + 130,
//        CC_ORIGIN_X + 200,
//        CC_ORIGIN_Y + 150,      // dimension
//        RB_DRAW,                // will be dislayed after creation
//        (XCHAR *)LightLoadStr,  // "Light Load"
//        alt2Scheme
//    );                          // alternative GOL scheme
//}
//
//// Processes messages for custom control screen
//WORD MsgCustomControl(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg)
//{
//    RADIOBUTTON *pRb;
//    CUSTOM      *pCc;
//
//    switch(GetObjID(pObj))
//    {
//        case ID_RADIOBUTTON1:   // set load to high
//            pCc = (CUSTOM *)GOLFindObject(ID_CUSTOM1);  // get pointer to custom control object
//            CcSetPos(pCc, 75);
//            SetState(pCc, CC_DRAW_BAR);                 // set to redraw the level
//            return (1);         // process by default
//
//        case ID_RADIOBUTTON2:   // set load to normal
//            pCc = (CUSTOM *)GOLFindObject(ID_CUSTOM1);  // get pointer to custom control object
//            CcSetPos(pCc, 120);
//            SetState(pCc, CC_DRAW_BAR);                 // set to redraw the level
//            return (1);         // process by default
//
//        case ID_RADIOBUTTON3:   // set load to light
//            pCc = (CUSTOM *)GOLFindObject(ID_CUSTOM1);  // get pointer to custom control object
//            CcSetPos(pCc, 150);
//            SetState(pCc, CC_DRAW_BAR);                 // set to redraw the level
//            return (1);     // process by default
//
//        case ID_CUSTOM1:    // level is changed
//            if(objMsg == CC_MSG_SELECTED)
//            {
//                if(pMsg->param2 <= 110)
//                {
//                    pRb = (RADIOBUTTON *)GOLFindObject(ID_RADIOBUTTON1);    // get pointer heavy load setting
//                    RbSetCheck(pRb, ID_RADIOBUTTON1);                       // set radio button for heavy to be checked
//                    SetState(pRb, RB_DRAW_CHECK);
//                }
//                else if(pMsg->param2 <= 140)
//                {
//                    pRb = (RADIOBUTTON *)GOLFindObject(ID_RADIOBUTTON2);    // get pointer heavy load setting
//                    RbSetCheck(pRb, ID_RADIOBUTTON2);                       // set radio button for normal to be checked
//                    SetState(pRb, RB_DRAW_CHECK);
//                }
//                else
//                {
//                    pRb = (RADIOBUTTON *)GOLFindObject(ID_RADIOBUTTON3);    // get pointer heavy load setting
//                    RbSetCheck(pRb, ID_RADIOBUTTON3);                       // set radio button for light to be checked
//                    SetState(pRb, RB_DRAW_CHECK);
//                }
//            }
//
//            return (1);
//
//        case ID_BUTTON_NEXT:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_SIGNATURE;                             // goto signature screen
//            }
//
//            return (1);                         // process by default
//
//        case ID_BUTTON_BACK:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_PICTURE;   // goto picture screen
//            }
//
//            return (1);                         // process by default
//
//        default:
//            return (1);                         // process by default
//    }
//}
//
//// dimensions for signature box
//#define SIG_ORIGIN_X        ((GetMaxX() - 260 + 1) / 2)
//#define SIG_ORIGIN_Y        ((40 + GetMaxY() - 170 + 1) / 2)
//#define SIG_PANEL_LEFT      35
//#define SIG_PANEL_RIGHT     GetMaxX() - 35
//#define SIG_PANEL_TOP       50
//#define SIG_PANEL_BOTTOM    GetMaxY() - 10
//
//// Creates signature screen
//void CreateSignature(void)
//{
//    GOLFree();  // free memory for the objects in the previous linked list and start new list
//    CreatePage((XCHAR *)SignatureStr);
//}
//
//// Draws box for signature
//WORD PanelSignature(void)
//{
//    #define SIG_STATE_SET   0
//    #define SIG_STATE_DRAW  1
//
//    static BYTE state = SIG_STATE_SET;
//
//    if(state == SIG_STATE_SET)
//    {                           // set data for panel drawing
//        GOLPanelDraw
//        (
//            SIG_PANEL_LEFT,
//            SIG_PANEL_TOP,
//            SIG_PANEL_RIGHT,
//            SIG_PANEL_BOTTOM,
//            0,
//            WHITE,
//            altScheme->EmbossLtColor,
//            altScheme->EmbossDkColor,
//            NULL,
//            GOL_EMBOSS_SIZE
//        );
//
//        state = SIG_STATE_DRAW; // change state
//    }
//
//    if(!GOLPanelDrawTsk())
//    {
//        return (0);             // drawing is not completed
//    }
//    else
//    {
//        state = SIG_STATE_SET;  // set state to initial
//        return (1);             // drawing is done
//    }
//}
//
//// Processes messages for signature screen
//WORD MsgSignature(WORD objMsg, OBJ_HEADER *pObj, GOL_MSG *pMsg)
//{
//    static SHORT    prevX = -1;     // previous point
//    static SHORT    prevY = -1;
//    SHORT           x, y;           // current point
//    switch(GetObjID(pObj))
//    {
//        case ID_WINDOW1:
//
//            // get touched position
//            x = pMsg->param1;
//            y = pMsg->param2;
//
//            // Check if it falls in the signature box
//            if
//            (
//                ((SIG_PANEL_LEFT + GOL_EMBOSS_SIZE) < x) &&
//                ((SIG_PANEL_RIGHT - GOL_EMBOSS_SIZE) > x) &&
//                ((SIG_PANEL_TOP + GOL_EMBOSS_SIZE) < y) &&
//                ((SIG_PANEL_BOTTOM - GOL_EMBOSS_SIZE) > y)
//            )
//            {
//                SetColor(BRIGHTRED);
//
//                // if previous position is not valid or event is PRESS
//                if((pMsg->uiEvent == EVENT_PRESS) || (prevX < 0))
//                {
//                    PutPixel(x, y); // draw pixel
//                }
//                else
//                {
//                    WAIT_UNTIL_FINISH(Line(prevX, prevY, x, y));    // connect with thick line previous and current points
//                    WAIT_UNTIL_FINISH(Line(prevX - 1, prevY, x - 1, y));
//                    WAIT_UNTIL_FINISH(Line(prevX + 1, prevY, x + 1, y));
//                    WAIT_UNTIL_FINISH(Line(prevX, prevY - 1, x, y - 1));
//                    WAIT_UNTIL_FINISH(Line(prevX, prevY + 1, x, y + 1));
//                }
//
//                prevX = x;
//                prevY = y;                          // store position
//            }
//            else
//            {
//
//                // reset if outside of box
//                prevX = -1;
//            }
//
//            return (1);                             // process by default
//
//        case ID_BUTTON_NEXT:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_POT;           // goto potentiometer graph screen
//                animate = 0;
//            }
//
//            return (1);                             // process by default
//
//        case ID_BUTTON_BACK:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_CUSTOMCONTROL; // goto custom control screen
//                animate = 0;
//            }
//
//            return (1);                             // process by default
//
//        default:
//            return (1);                             // process by default
//    }
//}
//
//// dimensions for potentiometer graph area
//#define POT_ORIGIN_X        ((GetMaxX() - 260 + 1) / 2)
//#define POT_ORIGIN_Y        ((40 + GetMaxY() - 185 + 1) / 2)
//#define POT_PANEL_LEFT      POT_ORIGIN_X
//#define POT_PANEL_RIGHT     POT_ORIGIN_X + 260
//#define POT_PANEL_TOP       POT_ORIGIN_Y
//#define POT_PANEL_BOTTOM    POT_ORIGIN_Y + 160
//
//// Graph area borders
//#define POTGR_LEFT      (POT_PANEL_LEFT + GOL_EMBOSS_SIZE)
//#define POTGR_RIGHT     (POT_PANEL_RIGHT - GOL_EMBOSS_SIZE)
//#define POTGR_TOP       (POT_PANEL_TOP + GOL_EMBOSS_SIZE)
//#define POTGR_BOTTOM    (POT_PANEL_BOTTOM - GOL_EMBOSS_SIZE)
//
//volatile SHORT  buffer[256];
//volatile SHORT  counter = 0;
//volatile SHORT  inc = 10;
//
//// Creates ntr screen
//void CreatePotentiometer(void)
//{
//    GOLFree();  // free memory for the objects in the previous linked list and start new list
//    CreatePage((XCHAR *)PlottingStr);
//}
//
//// Draws box for potentiometer graph
//WORD PanelPotentiometer(void)
//{
//    #define POTPNL_STATE_SET    0
//    #define POTPNL_STATE_DRAW   1
//    #define POTPNL_STATE_TEXT   2
//
//    static BYTE state = POTPNL_STATE_SET;
//
//    if(state == POTPNL_STATE_SET)
//    {                               // set data for panel
//        GOLPanelDraw
//        (
//            POT_PANEL_LEFT,
//            POT_PANEL_TOP,
//            POT_PANEL_RIGHT,
//            POT_PANEL_BOTTOM,
//            0,
//            WHITE,
//            altScheme->EmbossDkColor,
//            altScheme->EmbossLtColor,
//            NULL,
//            GOL_EMBOSS_SIZE
//        );
//
//        state = POTPNL_STATE_DRAW;  // change state
//    }
//
//    if(state == POTPNL_STATE_DRAW)
//    {
//        if(!GOLPanelDrawTsk())
//        {                           // draw box for graph
//            return (0);             // drawing is not completed
//        }
//        else
//        {
//            state = POTPNL_STATE_TEXT;          // change to initial state
//            SetFont((void *)ptrSmallAsianFont); // SetFont(&ptrSmallAsianFont);
//            SetColor(BRIGHTBLUE);
//            MoveTo
//            (
//                (GetMaxX() - GetTextWidth((XCHAR *)UseR6PotStr, (void *)ptrSmallAsianFont)) >> 1,
//                POT_ORIGIN_Y + 165
//            );
//        }
//    }
//
//    if(state == POTPNL_STATE_TEXT)
//    {
//        while(!OutText((XCHAR *)UseR6PotStr))   // "Using R6 potentiometer"))
//            return (0);
//        state = POTPNL_STATE_SET;               // change to initial state
//        return (1);                             // drawing is done
//    }
//
//    return (1);
//}
//
//// Add sample from potentiometer ADC channel into temporary buffer
//
//// Returns zero if samples number in the buffer is less than defined by parameter
//WORD GetPotSamples(WORD number)
//{
//    static BYTE     counter = 0;
//    volatile SHORT  temp =0;
//
//      #ifdef ADC_POT
//    temp = ADCGetPot() >> 3;
//    if((temp + POTGR_TOP) > POTGR_BOTTOM)
//        temp = POTGR_BOTTOM - POTGR_TOP;
//      #endif
//    tempBuffer[counter++] = temp;
//    if(counter >= number)
//    {
//        counter = 0;
//        return (1);
//    }
//
//    return (0);
//}
//
//// Draws graph
//void GraphPotentiometer(void)
//{
//    SHORT           x, y;
//    SHORT           sy, ey;
//    SHORT           *ptr;
//    SHORT           counter;
//    static SHORT    pos;
//
//    // remove graph
//    SetColor(WHITE);
//    ptr = potBuffer + pos;
//    sy = *ptr++;
//    for(x = POTGR_RIGHT; x >= POTGR_LEFT; x--)
//    {
//        if(ptr == (potBuffer + POT_BUFFER_SIZE))
//            ptr = potBuffer;
//        ey = *ptr++;
//        if(ey > sy)
//        {
//            for(y = sy + POTGR_TOP; y < ey + POTGR_TOP + 1; y++)
//                PutPixel(x, y);
//        }
//        else
//        {
//            for(y = ey + POTGR_TOP; y < sy + POTGR_TOP + 1; y++)
//                PutPixel(x, y);
//        }
//
//        sy = ey;
//    }
//
//    // draw grid
//    SetColor(LIGHTGRAY);
//    for(x = POTGR_LEFT + ((POTGR_RIGHT - POTGR_LEFT) >> 3); x < POTGR_RIGHT; x += (POTGR_RIGHT - POTGR_LEFT) >> 3)
//        WAIT_UNTIL_FINISH(Bar(x, POTGR_TOP, x, POTGR_BOTTOM));
//
//    for(y = POTGR_TOP + ((POTGR_BOTTOM - POTGR_TOP) >> 3); y < POTGR_BOTTOM; y += (POTGR_BOTTOM - POTGR_TOP) >> 3)
//        WAIT_UNTIL_FINISH(Bar(POTGR_LEFT, y, POTGR_RIGHT, y));
//
//    pos -= POT_MOVE_DELTA;
//    if(pos < 0)
//        pos = POT_BUFFER_SIZE - 1;
//
//    // copy new data from temporary buffer
//    ptr = potBuffer + pos;
//    for(counter = POT_MOVE_DELTA - 1; counter >= 0; counter--)
//    {
//        *ptr++ = tempBuffer[counter];
//        if(ptr == (potBuffer + POT_BUFFER_SIZE))
//            ptr = potBuffer;
//    }
//
//    // draw graph
//    SetColor(BRIGHTRED);
//    ptr = potBuffer + pos;
//    sy = *ptr++;
//    for(x = POTGR_RIGHT; x >= POTGR_LEFT; x--)
//    {
//        if(ptr == (potBuffer + POT_BUFFER_SIZE))
//            ptr = potBuffer;
//        ey = *ptr++;
//        if(ey > sy)
//        {
//            for(y = sy + POTGR_TOP; y < ey + POTGR_TOP + 1; y++)
//                PutPixel(x, y);
//        }
//        else
//        {
//            for(y = ey + POTGR_TOP; y < sy + POTGR_TOP + 1; y++)
//                PutPixel(x, y);
//        }
//
//        sy = ey;
//    }
//}
//
//// Processes messages for ECG screen
//WORD MsgPotentiometer(WORD objMsg, OBJ_HEADER *pObj)
//{
//    switch(GetObjID(pObj))
//    {
//        case ID_BUTTON_NEXT:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_ECG;       // goto ECG screen
//            }
//
//            return (1);                         // process by default
//
//        case ID_BUTTON_BACK:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_SIGNATURE; // goto signature screen
//            }
//
//            return (1);                         // process by default
//
//        default:
//            return (1);                         // process by default
//    }
//}
//
//// dimensions for ECG graph area
//#define ECG_ORIGIN_X        ((GetMaxX() - 262 + 1) / 2)
//#define ECG_ORIGIN_Y        ((40 + GetMaxY() - 190 + 1) / 2)
//#define ECG_PANEL_LEFT      ECG_ORIGIN_X
//#define ECG_PANEL_RIGHT     ECG_ORIGIN_X + 262
//#define ECG_PANEL_TOP       ECG_ORIGIN_Y
//#define ECG_PANEL_BOTTOM    ECG_ORIGIN_Y + 165
//
//// Graph area borders
//#define GR_LEFT     ECG_PANEL_LEFT + GOL_EMBOSS_SIZE
//#define GR_RIGHT    ECG_PANEL_RIGHT - GOL_EMBOSS_SIZE
//#define GR_TOP      ECG_PANEL_TOP + GOL_EMBOSS_SIZE
//#define GR_BOTTOM   ECG_PANEL_BOTTOM - GOL_EMBOSS_SIZE
//
//// Creates ECG screen
//void CreateECG(void)
//{
//    GOLFree();  // free memory for the objects in the previous linked list and start new list
//    CreatePage((XCHAR *)EcgStr);
//}
//
//// Add sample from FLASH (can be any source) into temporary buffer
//
//// Returns zero if samples number in the buffer is less than defined by parameter
//WORD GetECGSamples(WORD number)
//{
//    static const SHORT  *pointer = ecgPoints;
//    static BYTE         counter = 0;
//
//    if(pointer == (ecgPoints + sizeof(ecgPoints) / sizeof(SHORT)))
//        pointer = ecgPoints;
//
//    tempBuffer[counter++] = *pointer++;
//
//    if(counter >= number)
//    {
//        counter = 0;
//        return (1);
//    }
//
//    return (0);
//}
//
//// Draws box for ECG
//WORD PanelECG(void)
//{
//    #define ECG_STATE_SET       0
//    #define ECG_STATE_DRAW      1
//    #define ECG_STATE_VERLINE   2
//    #define ECG_STATE_HORLINE   3
//    #define ECG_STATE_TEXT      4
//
//    static BYTE     state = ECG_STATE_SET;
//    static SHORT    pos;
//
//    switch(state)
//    {
//        case ECG_STATE_SET:
//
//            // set parameters for panel
//            GOLPanelDraw
//            (
//                ECG_PANEL_LEFT,
//                ECG_PANEL_TOP,
//                ECG_PANEL_RIGHT,
//                ECG_PANEL_BOTTOM,
//                0,
//                WHITE,
//                altScheme->EmbossDkColor,
//                altScheme->EmbossLtColor,
//                NULL,
//                GOL_EMBOSS_SIZE
//            );
//
//            state = ECG_STATE_DRAW;     // change state
//
//        case ECG_STATE_DRAW:
//            if(!GOLPanelDrawTsk())      // draw panel for graph
//                return (0);             // drawing is not completed
//            SetColor(LIGHTGRAY);
//            SetLineType(DOTTED_LINE);
//            pos = GR_LEFT + ((GR_RIGHT - GR_LEFT) >> 3);
//            state = ECG_STATE_VERLINE;  // change state
//
//        case ECG_STATE_VERLINE:
//            while(pos < GR_RIGHT)
//            {                           // draw vertical grid lines
//                if(IsDeviceBusy())
//                    return (0);         // drawing is not completed
//                WAIT_UNTIL_FINISH(Line(pos, GR_TOP, pos, GR_BOTTOM));
//                pos += (GR_RIGHT - GR_LEFT) >> 3;
//            }
//
//            pos = GR_TOP + ((GR_BOTTOM - GR_TOP) >> 3);
//            state = ECG_STATE_HORLINE;  // change state
//
//        case ECG_STATE_HORLINE:
//            while(pos < GR_BOTTOM)
//            {                           // draw vertical grid lines
//                if(IsDeviceBusy())
//                    return (0);         // drawing is not completed
//                WAIT_UNTIL_FINISH(Line(GR_LEFT, pos, GR_RIGHT, pos));
//                pos += (GR_BOTTOM - GR_TOP) >> 3;
//            }
//
//            SetLineType(SOLID_LINE);
//            SetFont((void *)ptrSmallAsianFont);
//
//            SetColor(BRIGHTBLUE);
//
//            MoveTo((GetMaxX() - GetTextWidth((XCHAR *)ScanModeStr, (void *)ptrSmallAsianFont)) >> 1, ECG_ORIGIN_Y + 170);
//            state = ECG_STATE_TEXT;     // change to text display state
//
//        case ECG_STATE_TEXT:
//            while(!OutText((XCHAR *)ScanModeStr))   // while(!OutText("Scan mode"))
//                return (0);
//            state = ECG_STATE_SET;                  // change to initial state
//            return (1);                             // drawing is done
//    }
//
//    return (1);
//}
//
//// Draws graph
//void GraphECG(void)
//{
//    SHORT           x, y;
//    static SHORT    sy = 0;
//    static SHORT    tsy = 0;
//    SHORT           ey;
//    static SHORT    *ptr = ecgBuffer;
//    static SHORT    pos = 0;
//    SHORT           counter;
//    SHORT           *pTemp;
//    SHORT           temp;
//
//    // remove graph
//    SetColor(WHITE);
//
//    pTemp = ptr;
//    temp = pos;
//
//    for(x = 0; x < ECG_WINDOW_SIZE; x++)
//    {
//        ey = *ptr++;
//        pos++;
//
//        if(ey > sy)
//        {
//            for(y = sy + GR_TOP; y < ey + GR_TOP + 1; y++)
//                PutPixel(GR_LEFT + pos, y);
//        }
//        else
//        {
//            for(y = ey + GR_TOP; y < sy + GR_TOP + 1; y++)
//                PutPixel(GR_LEFT + pos, y);
//        }
//
//        if(ptr == (ecgBuffer + ECG_BUFFER_SIZE))
//        {
//            ptr = ecgBuffer;
//            pos = 0;
//        }
//
//        sy = ey;
//    }
//
//    // copy new data from temporary buffer
//    ptr = pTemp;
//    pos = temp;
//
//    for(counter = 0; counter < ECG_WINDOW_SIZE; counter++)
//    {
//        *ptr++ = tempBuffer[counter];
//        pos++;
//        if(ptr == (ecgBuffer + ECG_BUFFER_SIZE))
//        {
//            ptr = ecgBuffer;
//            pos = 0;
//        }
//    }
//
//    // draw graph
//    SetColor(BRIGHTRED);
//
//    ptr = pTemp;
//    pos = temp;
//
//    for(x = 0; x < ECG_WINDOW_SIZE; x++)
//    {
//        ey = *ptr++;
//        pos++;
//
//        if(ey > tsy)
//        {
//            for(y = tsy + GR_TOP; y < ey + GR_TOP + 1; y++)
//                PutPixel(GR_LEFT + pos, y);
//        }
//        else
//        {
//            for(y = ey + GR_TOP; y < tsy + GR_TOP + 1; y++)
//                PutPixel(GR_LEFT + pos, y);
//        }
//
//        if(ptr == (ecgBuffer + ECG_BUFFER_SIZE))
//        {
//            ptr = ecgBuffer;
//            pos = 0;
//        }
//
//        tsy = ey;
//    }
//
//    // draw grid
//    SetColor(LIGHTGRAY);
//    SetLineType(DOTTED_LINE);
//    for(x = GR_LEFT + ((GR_RIGHT - GR_LEFT) >> 3); x < GR_RIGHT; x += (GR_RIGHT - GR_LEFT) >> 3)
//    {
//        if((x >= GR_LEFT + temp) && (x <= GR_LEFT + ECG_WINDOW_SIZE + temp))
//            WAIT_UNTIL_FINISH(Line(x, GR_TOP, x, GR_BOTTOM));
//    }
//
//    for(y = GR_TOP + ((GR_BOTTOM - GR_TOP) >> 3); y < GR_BOTTOM; y += (GR_BOTTOM - GR_TOP) >> 3)
//        WAIT_UNTIL_FINISH(Line(GR_LEFT + temp, y, temp + GR_LEFT + ECG_WINDOW_SIZE, y));
//    SetLineType(SOLID_LINE);
//}
//
//// Processes messages for ECG screen
//WORD MsgECG(WORD objMsg, OBJ_HEADER *pObj)
//{
//    switch(GetObjID(pObj))
//    {
//        case ID_BUTTON_NEXT:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_BUTTONS;   // goto buttons screen
//            }
//
//            return (1);                         // process by default
//
//        case ID_BUTTON_BACK:
//            if(objMsg == BTN_MSG_RELEASED)
//            {
//                screenState = CREATE_POT;       // goto potentiometer screen
//            }
//
//            return (1);                         // process by default
//
//        default:
//            return (1);                         // process by default
//    }
//}
//
//// Output text message on screen and stop execution
//void ErrorTrap(XCHAR *message)
//{
//    SetColor(BLACK);
//    ClearDevice();
//    SetFont((void *) &FONTDEFAULT);
//    SetColor(WHITE);
//    while(!OutTextXY(0, 0, message));
//    while(1);
//}
//
//








/*********************************************************************
* Function: Timer4 ISR
*
* PreCondition: none
*
* Input: none
*
* Output: none
*
* Side Effects: none
*
* Overview: increments tick counter. Tick is approx. 1 ms.
*
* Note: none
*
********************************************************************/
#ifdef __PIC32MX__
    #define __T4_ISR    __ISR(_TIMER_4_VECTOR, ipl1)
#else
    #define __T4_ISR    __attribute__((interrupt, shadow, auto_psv))
#endif

void __T4_ISR _T4Interrupt(void)
{
    tick++;

    TMR4 = 0;
    // Clear flag
    #ifdef __PIC32MX__
    mT4ClearIntFlag();
    #else
    IFS1bits.T4IF = 0;
    #endif

	TouchDetectPosition();
}

/////////////////////////////////////////////////////////////////////////////
// Function: void TickInit(void)
// Input: none
// Output: none
// Overview: Initilizes the tick timer.
/////////////////////////////////////////////////////////////////////////////

/*********************************************************************
 * Section: Tick Delay
 *********************************************************************/
#define SAMPLE_PERIOD       500 // us
#define TICK_PERIOD			(GetPeripheralClock() * SAMPLE_PERIOD) / 4000000

/* */
void TickInit(void)
{
    // Initialize Timer4
    #ifdef __PIC32MX__
    OpenTimer4(T4_ON | T4_PS_1_8, TICK_PERIOD);
    ConfigIntTimer4(T4_INT_ON | T4_INT_PRIOR_1);
    #else
    TMR4 = 0;
    PR4 = TICK_PERIOD;
    IFS1bits.T4IF = 0;  //Clear flag
    IEC1bits.T4IE = 1;  //Enable interrupt
    T4CONbits.TON = 1;  //Run timer
    #endif
}

/////////////////////////////////////////////////////////////////////////////
// Function: InitializeBoard()
// Input: none
// Output: none
// Overview: Initializes the hardware components including the PIC device
//           used.
/////////////////////////////////////////////////////////////////////////////
void InitializeBoard(void)
{

    #if defined (PIC24FJ256DA210_DEV_BOARD) && defined(USE_KEYBOARD)

     ANSA = 0x0000;
     ANSB = 0x0020;		// RB5 as potentiometer input
     ANSC = 0x0010;		// RC4 as touch screen X+, RC14 as external source of secondary oscillator
     ANSD = 0x0000;
     ANSE = 0x0000;		// RE9 used as S2
     ANSF = 0x0000;
     ANSG = 0x0080;		// RG8 used as S1, RG7 as touch screen Y+

    #else
        /////////////////////////////////////////////////////////////////////////////
        // ADC Explorer 16 Development Board Errata (work around 2)
        // RB15 should be output
        /////////////////////////////////////////////////////////////////////////////
        #ifndef MEB_BOARD
            LATBbits.LATB15 = 0;
            TRISBbits.TRISB15 = 0;
        #endif
    #endif

    #ifdef MEB_BOARD
       // CPLDInitialize();
       // CPLDSetGraphicsConfiguration(GRAPHICS_HW_CONFIG);
       // CPLDSetSPIFlashConfiguration(SPI_FLASH_CHANNEL);
    #endif // #ifdef MEB_BOARD

    #if defined(__dsPIC33F__) || defined(__PIC24H__) || defined(__dsPIC33E__) || defined(__PIC24E__)

        // Configure Oscillator to operate the device at 40Mhz
        // Fosc= Fin*M/(N1*N2), Fcy=Fosc/2
        #if defined(__dsPIC33E__) || defined(__PIC24E__)
			//Fosc = 8M * 60/(2*2) = 120MHz for 8M input clock
			PLLFBD = 58;    			// M=60
		#else
        	// Fosc= 8M*40(2*2)=80Mhz for 8M input clock
        	PLLFBD = 38;                    // M=40
        #endif
        CLKDIVbits.PLLPOST = 0;         // N1=2
        CLKDIVbits.PLLPRE = 0;          // N2=2
        OSCTUN = 0;                     // Tune FRC oscillator, if FRC is used

        // Disable Watch Dog Timer
        RCONbits.SWDTEN = 0;

        // Clock switching to incorporate PLL
        __builtin_write_OSCCONH(0x03);  // Initiate Clock Switch to Primary

        // Oscillator with PLL (NOSC=0b011)
        __builtin_write_OSCCONL(0x01);  // Start clock switching
        while(OSCCONbits.COSC != 0b011);

        // Wait for Clock switch to occur
        // Wait for PLL to lock
        while(OSCCONbits.LOCK != 1)
        { };

        #if defined(__dsPIC33F__) || defined(__PIC24H__)
        // Set PMD0 pin functionality to digital
        AD1PCFGL = AD1PCFGL | 0x1000;

            #if defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__)
                AD1PCFGLbits.PCFG6 = 1;
                AD1PCFGLbits.PCFG7 = 1;
                AD1PCFGLbits.PCFG8 = 1;
            #endif

        #elif defined(__dsPIC33E__) || defined(__PIC24E__)
            ANSELE = 0x00;
            ANSELDbits.ANSD6 = 0;

		    // Set all touch screen related pins to Analog mode.
	        ANSELBbits.ANSB11 = 1;
        #endif

    #elif defined(__PIC32MX__)
        INTEnableSystemMultiVectoredInt();
        SYSTEMConfigPerformance(GetSystemClock());
        #if defined(__32MX250F128D__)
        DDPCONbits.JTAGEN = 0; // Disable JTAG
        ANSELA = ANSELB = ANSELC = 0x0000; // Disable all ADC inputs
        #endif
    #endif // #if defined(__dsPIC33F__) || defined(__PIC24H__)


    #if defined (EXPLORER_16)
/************************************************************************
* For Explorer 16 RD12 is connected to EEPROM chip select.
* To prevent a conflict between this EEPROM and SST25 flash
* the chip select of the EEPROM SPI should be pulled up.
************************************************************************/
        // Set IOs directions for EEPROM SPI
        #if !defined(__32MX250F128D__)
        MCHP25LC256_CS_LAT = 1;			    // set initial CS value to 1 (not asserted)
    	MCHP25LC256_CS_TRIS = 0;			// set CS pin to output
        #endif
	#endif // #if defined (EXPLORER_16)

    // Initialize graphics library and create default style scheme for GOL
    GOLInit();

// Set the other chip selects to a known state
#ifdef MIKRO_BOARD
    // SD Card chip select
    LATGbits.LATG9 = 1;
    TRISGbits.TRISG9 = 0;

    // MP3 Codec
    // reset
    LATAbits.LATA5 = 0;
    TRISAbits.TRISA5 = 0;
    // chip select
    LATAbits.LATA2 = 1;
    TRISAbits.TRISA2 = 0;
    // chip select
    LATAbits.LATA3 = 1;
    TRISAbits.TRISA3 = 0;

    AD1PCFGbits.PCFG11 = 1;
    AD1PCFGbits.PCFG10 = 1;
#endif

    //The following are PIC device specific settings for the SPI channel
    //used.
#if defined(USE_SST25VF016) || defined (USE_M25P80)
    //Set IOs directions for SST25 SPI
    #if defined (GFX_PICTAIL_V3) || defined (MEB_BOARD) || defined(GFX_PICTAIL_LCC) || defined(MIKRO_BOARD) ||defined (GFX_PICTAIL_V3E)

        SST25_CS_LAT = 1;
        SST25_CS_TRIS = 0;

        #ifndef __PIC32MX__
            SST25_SCK_TRIS = 0;
            SST25_SDO_TRIS = 0;
            SST25_SDI_TRIS = 1;
            #if defined(__PIC24FJ256GB210__) || defined(__dsPIC33E__) || defined(__PIC24E__)
            	SST25_SDI_ANS = 0;
    	    #endif
        #endif
    #elif defined (PIC24FJ256DA210_DEV_BOARD)
        SST25_CS_LAT = 1;
        SST25_CS_TRIS = 0;

        // Set the pins to be digital
    	SST25_SDI_ANS = 0;
        SST25_SDO_ANS = 0;

        SST25_SCK_TRIS = 0;
        SST25_SDO_TRIS = 0;
        SST25_SDI_TRIS = 1;

	#endif

    // set the peripheral pin select for the SPI channel used
    #if defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__)
        AD1PCFGL = 0xFFFF;
        RPOR9bits.RP18R = 11;                   // assign RP18 for SCK2
        RPOR8bits.RP16R = 10;                   // assign RP16 for SDO2
        RPINR22bits.SDI2R = 17;                 // assign RP17 for SDI2
    #elif defined(__PIC24FJ256GB110__) || defined(__PIC24FJ256GA110__) || defined (__PIC24FJ256GB210__)
        __builtin_write_OSCCONL(OSCCON & 0xbf); // unlock PPS
        RPOR10bits.RP21R = 11;                  // assign RP21 for SCK2
        RPOR9bits.RP19R = 10;                   // assign RP19 for SDO2
        RPINR22bits.SDI2R = 26;                 // assign RP26 for SDI2
        __builtin_write_OSCCONL(OSCCON | 0x40); // lock   PPS
    #elif defined(__PIC24FJ256DA210__)

        __builtin_write_OSCCONL(OSCCON & 0xbf); // unlock PPS

    	#if (SST25_SPI_CHANNEL == 1)
    	    RPOR1bits.RP2R = 8;                 // assign RP2 for SCK1
    	    RPOR0bits.RP1R = 7;                 // assign RP1 for SDO1
    	    RPINR20bits.SDI1R = 0;              // assign RP0 for SDI1
        #elif (SST25_SPI_CHANNEL == 2)
            RPOR1bits.RP2R = 11;                // assign RP2 for SCK2
    	    RPOR0bits.RP1R = 10;                // assign RP1 for SDO2
    	    RPINR22bits.SDI2R = 0;              // assign RP0 for SDI2
    	#endif

        __builtin_write_OSCCONL(OSCCON | 0x40); // lock   PPS

    #endif

	// initialize the Flash Memory driver
    FlashInit(&SPI_Init_Data);
#endif
    // initialize the timer that manages the tick counter
    TickInit();

    // initialize the components for Resistive Touch Screen
    TouchInit(NVMWrite, NVMRead, NVMSectorErase, NULL);

    //HardwareButtonInit();           	// Initialize the hardware buttons

    #if !(defined(__dsPIC33FJ128GP804__) || defined(__PIC24HJ128GP504__)||defined(GFX_USE_DISPLAY_CONTROLLER_DMA)||defined(__32MX250F128D__))
        RTCCInit();                         // Setup the RTCC
        RTCCProcessEvents();
        //    // initialize date and time
    mRTCCOff();
    RTCCSetBinHour(0x9);      // set the hour value
    RTCCSetBinMin(0x8);     // set the minute value
    RTCCSetBinSec(0x7);     // set the second value
    RTCCSetBinDay(RTCC_DEFAULT_DAY);        // set the day value
    RTCCSetBinMonth(RTCC_DEFAULT_MONTH);    // set the month value
    RTCCSetBinYear(RTCC_DEFAULT_YEAR);      // set the year value
    RTCCCalculateWeekDay();         		// calculate the weekday from this new value
    mRTCCSet();
    #endif

}


