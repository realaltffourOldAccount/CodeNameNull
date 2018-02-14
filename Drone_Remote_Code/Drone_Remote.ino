////////////////////////////////////////////////////////////////////////////////////////
//    Notes:
/*
 *   The remote board will have two joystick and four buttons, 1 HC-04, 1 LCD DISPLAY SHIELD
 *   an arduino uno
 *   
 *   The left joystick will have two axis: x and y.
 *   The X axis will have a range from 0 to 1023
 *   The Y axis will have a range from 0 to 1023
 *   The normal state of X is 494
 *   The normal state of Y is 496
 *   
 *   X axis:
 *   The X axis will control the movement of the drone to the left with the range of tilt depending on the joystick(i.e from 494 to 1023)
 *   The Negative X axis will control the movement of the drone to the right  with the range of tilt depending on the joystick(i.e from 494 to 0)
 *   
 *   Y axis:
 *   The Y axis will control the movmennt of the drone to the front with the range of tilt depending on the joystick (i.e from 496 to 1023)
 *   The Negateve Y axis will control the movement of the drone to the back with the range of tilt depending on the Joystick (i.e from 496 to 0)
 *   
 *   SW Button:
 *   STABLE MODE:
 *   the button of the left joystick is used to stabilize the drone and make so if it was moved by another external object it will stay stable at the appropiate hight
 *   
 *   The right joystick will have two axis: x and y
 *   The X axis will have a range from 0 to 1023
 *   The Y axis will have a range from 0 to 1023
 *   The normal state of X is 502
 *   The normal state of Y is 510
 *   
 *   X axis:
 *   The Y axis will control the thrust of the engines on the drone if the joystick is on normal state the engine will be off or running on enough power to hold the drone depending 
 *   on the mode choosen
 *   The X axis will control the rotation of the drone, the more the stick is on left it will rotate anticlockwise and vise versa
 *   
 *   SW button:
 *   ABORT:
 *   Used for auto landing, normally in case of emergency
 *   
 *   The negative is the value which is below the normal state of an axis on the joystick
 *   
 *   The button will be laid on the remote as a square
 *   Button 1 will be on the top left
 *   And button 2 will be on the top right
 *   And button 3 will be on the buttom left
 *   And button 4 will be on the buttom right
 *   
 *   Button 1:
 *   the output of the button will be connected on the arduino PWM11
 *   Use:
 *   Enable safe mode
 *   Safe mode is a mode that ensourse that the plan will not fall below 30 cm
 *   Better to be used when doing stunts for saftey measures. 
 *   WARNING THIS DOES NOT WORKING WITH 360 MODE ENABLED
 *   
 *   Button 2:
 *   the output of the button will be connected on the arduino PWM10
 *   Use:
 *   Enable disable safety measures
 *   To turn off or on the all safety measure. just like manuall flight.
 *   This clearly puts all the responsiblity on the pilot of the drone. AND THE PROGRAM HAVE NOTHING TO DO IN CASE OF A CRASH
 *   
 *   Button 3:
 *   the output of the button will be connected on the arduino PWM9
 *   Use:
 *   Enable/Disable Lights:
 *   Enable the lights on the drone representing the drone mode.
 *   
 *   Button 4:
 *   the output of the button will be connected on teh arduino DIG8
 *   Use:
 *   Enable Revirse thrust:
 *   This enables the engines to reverse thrust, and bring the drone lower faster.
 *   This should not be used only in stunts
 *   NOTE: THIS ONLY ENABLE OR DISABLES THE NEGATIVE PART OF THE RIGHT Y AXIS JOYSTICK
*/
////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////
//
//              Includes
//
////////////////////////////////////////////////////////////////////////////////////////

#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

/////////////////////////////////////////////////////////////////////////////////////////
//
//                  Defines, Variables, Structs, Enums
//
/////////////////////////////////////////////////////////////////////////////////////////

// joystick 1 is LEFT
#define PIN_JS1_X A0
#define PIN_JS1_Y A1
#define PIN_JS1_SW 13

// joystick 2 is RIGHT
#define PIN_JS2_X A2
#define PIN_JS2_Y A3
#define PIN_JS2_SW 12

#define PIN_BTN_1 11
#define PIN_BTN_2 10
#define PIN_BTN_3 9
#define PIN_BTN_4 8

// standard joystick defines
#define JS1_MAX_X  1023
#define JS1_MAX_Y  1023
#define JS1_MIN_X  0
#define JS1_MIN_Y  0
#define JS1_MID_X  494
#define JS1_MID_Y  496

#define JS2_MAX_X  1023
#define JS2_MAX_Y  1023
#define JS2_MIN_X  0
#define JS2_MIN_Y  0
#define JS2_MID_X  502
#define JS2_MID_Y  510
// end of standard joystick defines

// LCD standard defines
#define LCD_D4 4
#define LCD_D5 5 
#define LCD_D6 6
#define LCD_D7 7
#define LCD_RS 2
#define LCD_RW 3
// end of LCD standard defines

// data containers
int JS1_X_VAL;
int JS1_Y_VAL;
int JS2_X_VAL;
int JS2_Y_VAL;
bool JS1_SW_VAL;
bool JS2_SW_VAL;

bool BTN1_VAL = false;
bool BTN2_VAL = false;
bool BTN3_VAL = false;
bool BTN4_VAL = false;
// end of data contianers

/* Recieving Data of drone, may be zero if recall false is enabled */
int drone_attitude1 = 0;  // first sensor
// second senser should be manipulated by the drone

// LCD Message
String _LCD_MSG_REMOTE_STARTED = "Remote Started";
String _LCD_MSG_CONNECTED = "Drone Connected!";
String _LCD_MSG_FAIL_CONNECT = "Failed Connection . . . ";
String _LCD_MSG_FAILURE = "Failure . . . ";
String _LCD_MSG_WARNING = "WARNING!";
String _LCD_MSG_WARN_RES = "Warning Resolved...";
String _LCD_MSG_READY = "READY!";
String _LCD_MSG_DEFUALT_DRONE = "Defualting Drone Settings";
String _LCD_MSG_VERIFICATION = "Verifying Drone . . . ";
String _LCD_MSG_SAFE_MODE_SWT = "Safe Mode: ";
String _LCD_MSG_SAFETY_MEAS_SWT = "Safety Mesuares Mode: ";
String _LCD_MSG_STABLE_MODE_SWT = "Stable Mode: ";
String _LCD_MSG_360_MODE_SWT = "360 Mode: ";
String _LCD_MSG_REVERSE_THRUST_SWT = "Reverse Thrust: ";
String _LCD_MSG_LIGHTS_MODE_SWT = "Lights Mode: ";
//end of LCD Message

SoftwareSerial _TRANS(0,1);  // TX, RX
LiquidCrystal _LCD(LCD_RS, LCD_RW, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

/////////////////////////////////////////////////////////////////////////////////////////
//
//                  Communication system
//
/////////////////////////////////////////////////////////////////////////////////////////

// commands
String _START_STREEM = "BEGIN_STREEM";    // to begin streem, drone must return 1 to succed stream opening
String _END_STREEM = "END_STREEM";        // to end stream, drome must return 1 to succed stream closing
String _IDLE = "IDLE";                    // idle state, sends 1 on succed if report is on
String _ENABLE = "ENABLE<000>";           // enable state, sends 1 on succed if report is on, sends -1 in case of fail, abortion is must
String _DISABLE = "DISABLE<000>";         // disable state, sends 1 on succed if report is on, sends -1 in case of fail, abortion is recommended
String _JS1_X = "JS1X<000>";              // sends joystick state, sends 1 on succed if report is on, -1 in case of fail, abortion is must
String _JS1_Y = "JS1Y<000>";              // sends joystick state, sends 1 on succed if report is on, -1 in case of fail, abortion is must
String _JS2_X = "JS2X<000>";              // sends joystick state, sends 1 on succed if report is on, -1 in case of fail, abortion is must
String _JS2_Y = "JS2Y<000>";              // sends joystick state, sends 1 on succed if reprot is on, -1 in case of fail, aobrtion is must
String _ABORT = "ABORT";                  // to land the drone automatically in case of failure or pilot no capable of landing
String _REQUEST_DATA = "DATA<000>";       // to request data from drone, ex: request component power state, request safety senser, request leds light state
String _SHOWCASE = "SHOWCASE";            // to show case the drone
String _VERIFY = "TEST123";                 // to be sent to the drone for verification callback should be expected
String _REPORT_TRIG = "REPORT";           // to enable/disable reports
// end of commands

// state codes
const String _INVALID_CODE  = "-1";           // if the code is invalid

// LED 1 controller codes
String _LED1_R_PWR = "000";                   // LED1 RED PIN POWER CTR
String _LED1_G_PWR = "001";                   // LED1 GREEN PIN POWER CTR
String _LED1_B_PWR = "002";                   // LED1 BLUE PIN POWER CTR
// LED 2 controller codes 
String _LED2_R_PWR = "003";                   // LED2 RED PIN POWER CTR
String _LED2_G_PWR = "004";                   // LED2 GREEN PIN POWER CTR
String _LED2_B_PWR = "005";                   // LED2 BLUE PIN POWER CTR
// LED 3 controller codes
String _LED3_R_PWR = "006";                   // LED3 RED PIN POWER CTR
String _LED3_G_PWR = "007";                   // LED3 GREEN PIN POWER CTR
String _LED3_B_PWR = "008";                   // LED3 BLUE PIN POWER CTR
// LED 4 controller codes
String _LED4_R_PWR = "009";                   // LED4 RED PIN POWER CTR
String _LED4_G_PWR = "010";                   // LED4 GREEN PIN POWER CTR
String _LED4_B_PWR = "011";                   // LED4 BLUE PIN POWER CTR

// ENGINES controller codes
String _ENG1_PWR = "012";                     // ENG1 POWER CTR
String _ENG2_PWR = "013";                     // ENG2 POWER CTR
String _ENG3_PWR = "014";                     // ENG3 POWER CTR
String _ENG4_PWR = "015";                     // ENG4 POWER CTR

// features
String SAFE_MODE = "015";                    // SAFE MODE CTR
String SAFETY_MEAS = "016";                  // SAFETY MEAS CTR
String LIGHTS_MODE = "017";                  // LIGHTS MODE CTR
String REVERSE_THRUST = "018";               // REVERSE THRUST CTR

// request data codes
String REQ_SAFE_SENSER = "019";              // request code for safe sensor
String REQ_LIGHT_STATE = "020";              // request code for light states
// end of request data codes

// light states codes
String _SAFE_LIGHTS = "021";                 // safe lights are all green
String _SEMI_SAFE_LIGHTS = "022";            // semi-safe lights are for stable mode which are blue
String _UN_SAFE_LIGHTS = "023";              // un-safe lights are for stable mode off which are 3.3V Red(red apparently is way to bright and might burn itself)
String _ABORTION_LIGHTS = "024";             // abortion lights are enabled only on abortion process, 
                                             // they are blinking every .5 secs and the lights are changing except red for safety measures
String _SUCCESS = "025";                     // returned by drone in case of success
String _FAILURE = "026";                     // returned by drone in case of failure, abortion must be invoked if needed
// end of light stat`es codes

// end of state codes

// drone states values
bool STREAM_BOOTED = false;
bool IDLE_STATE = false;
bool LED1_R_STE = false;
bool LED1_G_STE = false;
bool LED1_B_STE = false;

bool LED2_R_STE = false;
bool LED2_G_STE = false;
bool LED2_B_STE = false;

bool LED3_R_STE = false;
bool LED3_G_STE = false;
bool LED3_B_STE = false;

bool LED4_R_STE = false;
bool LED4_G_STE = false;
bool LED4_B_STE = false;

bool ENG1_STE = false;
bool ENG2_STE = false;
bool ENG3_STE = false;
bool ENG4_STE = false;

bool SAFE_MODE_STE = false;
bool SAFETY_MEAS_STE = false;
bool LIGHTS_MODE_STE = false;
bool REVERSE_THRUST_STE = false;
bool REPORT_STE = true;

bool SAFE_LIGHTS_STE = false;
bool SEMI_SAFE_LIGHTS_STE = false;
bool UN_SAFE_LIGHTS_STE = false;
bool ABORTION_LIGHTS_STE = false;
// end of drone states

// data containers
String RECIEVED_DATA;          // reveived raw data  unproccessed or unutilized
String DRONE_ATITUDE;          // drone atitude i.e. first sensor
String DRONE_SAFE_SENSER_VL;   // drone safe sensor i.e second sensor
String LIGHTS_STATE;           // lights state
// end of data containers

// misc. variables
const int TICK_VL = 5;
const int MAX_RETRY_COUNTER = 5;
int RETRY_COUNTER = 0;        // for mem saving
int TICK_COUNTER = 0;         // must cleaned if TICK_VL is reached, must be updated every insturction, must be checked very update
int STANDARD_DELAY = 25;
int LONG_DELAY = 100;
int VLONG_DELAY = 2000;
int FAIL_DELAY = 120000;
int TICK_VER_COUNTER = 0; // for mem saving

String temp_instruction;
// end of misc. variables

// Function prototypes of communication system
void SendRaw(String raw);                          // to send data to the drone
void SendInst(String inst, String args);           // to send instruction to the drone
void RecieveData();                                // invoke when REPORT_STE is true
void ProcessRecievedData();                        // to process the data recieved

void StartConnection();                            // to start the connection
void EndConnection();                              // to end the connection
void VerifyConnection();                           // to verify the conection; should be invoked every 5 ticks are done

String GenerateInsturction(String instruction, String args)      // to add args to the instruction and return a string
// should only be done with instruction includeing arguments, DO NOT USE IT WITH NON-ARGUMENTALE INSTRUCTION, MAY CUZ AN ERROR
{
  String final_inst;
  final_inst = instruction;
  final_inst.replace("000", args);
  return final_inst;
}

void CheckFailure(int delay_value)
{
    RecieveData();
    if (RECIEVED_DATA == _FAILURE)
     {_LCD.print(_LCD_MSG_FAILURE); delay(delay_value);}
}

bool EnableState(String State_code)
// State should be updated manually
{
    SendInst(_ENABLE, State_code);
    
    CheckFailure(FAIL_DELAY);       // if failed the remote will hang
    return true;
}
bool DisableState(String State_code)
// State should be update manually
{
  SendInst(_DISABLE, State_code);
  
  CheckFailure(FAIL_DELAY);
  return true;
}
// end of Functions defines of communication system

// Function difinitions
void SendRaw(String raw)
{
  _TRANS.print(raw);
}
void SendInst(String inst, String args)
{
  temp_instruction = GenerateInsturction(inst, args);
  _TRANS.print(temp_instruction);
}
void RecieveData()
{
 RECIEVED_DATA = _TRANS.read();
}
void VerifyConnection()
{
  SendRaw(_VERIFY);
  delay(35);
  RecieveData();
  if (RECIEVED_DATA != _SUCCESS)
  {
    _LCD.print(_LCD_MSG_WARNING);
    for (int i = 0; MAX_RETRY_COUNTER; i++)
    {
      SendRaw(_VERIFY);
      delay(35);
      RecieveData();
      if (RECIEVED_DATA != _SUCCESS)
      {
        RETRY_COUNTER++;
        if (RETRY_COUNTER == MAX_RETRY_COUNTER)
          {break;}
        else {continue;}
      }
      else if (RECIEVED_DATA == _SUCCESS)
      {
        _LCD.print(_LCD_MSG_WARN_RES);
        RETRY_COUNTER = 0;
      }
    }
  }
  else {return;}
}
void StartConnection()
{
  SendRaw(_START_STREEM);
  delay(LONG_DELAY);                // to give time for the drone to recieve
  
  for (int i = 0; i < MAX_RETRY_COUNTER; i++)   // to retry connection depending on MAX_RETRY_COUNTER var
  {
    RecieveData();
    if (RECIEVED_DATA != _SUCCESS)      // failed to connect/open stream
      SendRaw(_START_STREEM);
    else if (RECIEVED_DATA = _SUCCESS){
      STREAM_BOOTED = true;
      _LCD.clear();
      _LCD.home();
      _LCD.print(_LCD_MSG_CONNECTED);
      break;
    }
    
    RETRY_COUNTER++;
    if (RETRY_COUNTER == MAX_RETRY_COUNTER)     // to check if clear is needed
    {
      RETRY_COUNTER = 0;
      STREAM_BOOTED = false;
      _LCD.clear();
      _LCD.home();
      _LCD.print(_LCD_MSG_FAIL_CONNECT);
      delay(25000);       // delaytion so the user can turn off the remote and the drone, and fix the problem
      break;
    }
  }
  delay(45000);
  
  // Connection estabilished, drone startup showcase is procces on the drone(for latency issues)
  if (STREAM_BOOTED == true)
  // the verification is off during the process of the drone startup showcase
  {
    _LCD.clear();
    _LCD.home();
    _LCD.print(_LCD_MSG_DEFUALT_DRONE);
    
    EnableState(_LED1_R_PWR);
    LED1_R_STE = true;
    EnableState(_LED1_G_PWR);
    LED1_G_STE = true;
    EnableState(_LED1_B_PWR);
    LED1_B_STE = true;
    
    EnableState(_LED2_R_PWR);
    LED2_R_STE = true;
    EnableState(_LED2_G_PWR);
    LED2_G_STE = true;
    EnableState(_LED2_B_PWR);
    LED2_B_STE = true;
    
    EnableState(_LED3_R_PWR);
    LED3_R_STE = true;
    EnableState(_LED3_G_PWR);
    LED3_G_STE = true;
    EnableState(_LED3_B_PWR);
    LED3_B_STE = true;
    
    EnableState(_LED4_R_PWR);
    LED4_R_STE = true;
    EnableState(_LED4_G_PWR);
    LED4_G_STE = true;
    EnableState(_LED4_B_PWR);
    LED4_B_STE = true;
    
    EnableState(_ENG1_PWR);
    ENG1_STE = true;
    EnableState(_ENG2_PWR);
    ENG2_STE = true;
    EnableState(_ENG3_PWR);
    ENG3_STE = true;
    EnableState(_ENG4_PWR);
    ENG4_STE = true;
    
    EnableState(LIGHTS_MODE);
    LIGHTS_MODE_STE = true;
    
    EnableState(SAFE_MODE);
    SAFE_MODE_STE = true;
    
    EnableState(SAFETY_MEAS);
    SAFETY_MEAS_STE = true;
    
    DisableState(REVERSE_THRUST);
    REVERSE_THRUST_STE = false;
    
    SendRaw(_REPORT_TRIG);
    SendRaw(_SHOWCASE);
    CheckFailure(FAIL_DELAY);
    delay(60000);
    _LCD.clear();
    _LCD.home();
    _LCD.print(_LCD_MSG_READY);
  }
}
void EndConnection()
{
  SendRaw(_END_STREEM);
  CheckFailure(FAIL_DELAY);
  delay(120000);
}
//end of function difinitions

// NOTE: a tick is TICK_VL insturction recieved or send

/////////////////////////////////////////////////////////////////////////////////////////
//
//          End of Comunnication system
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
//
//                      Function Prototypes
//
/////////////////////////////////////////////////////////////////////////////////////////

void ProcessJS();
void ProcessBTN();

/////////////////////////////////////////////////////////////////////////////////////////
//
//                    Stock Functions
//
/////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  // pin Modes for the joysticks
  pinMode(PIN_JS1_X, INPUT);
  pinMode(PIN_JS1_Y, INPUT);
  pinMode(PIN_JS2_X, INPUT); 
  pinMode(PIN_JS2_Y, INPUT);  

  // pin  modes for the buttons
  pinMode(PIN_BTN_1, INPUT);
  pinMode(PIN_BTN_2, INPUT);
  pinMode(PIN_BTN_3, INPUT);
  pinMode(PIN_BTN_4, INPUT);
  
  pinMode(LCD_D4, OUTPUT);
  pinMode(LCD_D5, OUTPUT);
  pinMode(LCD_D6, OUTPUT);
  pinMode(LCD_D7, OUTPUT);
  pinMode(LCD_RS, OUTPUT);
  pinMode(LCD_RW, OUTPUT);
  
  // display setup
  _LCD.begin(16,2);

  
  Serial.begin(9800); // computer communications
  _TRANS.begin(9800); // bluetooth communications 
  
  _LCD.print(_LCD_MSG_REMOTE_STARTED);
  
  delay(352);
  
  _LCD.clear();
  _LCD.home();
  
  StartConnection();
}

void loop() {
  ProcessJS();
  ProcessBTN();
  if (TICK_VER_COUNTER >= TICK_VL)
  {
    VerifyConnection();
    TICK_VER_COUNTER = 0;
  }
}


/////////////////////////////////////////////////////////////////////////////////////////
//
//                      Function Declarations
//
/////////////////////////////////////////////////////////////////////////////////////////

void ProcessJS()
{
  JS1_X_VAL = analogRead(PIN_JS1_X);
  JS1_Y_VAL = analogRead(PIN_JS1_Y);
  
  JS2_X_VAL = analogRead(PIN_JS2_X);
  JS2_Y_VAL = analogRead(PIN_JS2_Y);
  
  if (JS1_X_VAL == JS1_MID_X || JS1_Y_VAL == JS1_MID_Y ||
      JS2_X_VAL == JS2_MID_X || JS2_X_VAL == JS2_MID_Y) SendRaw(_IDLE);
  else {
  SendInst(_JS1_X, String(JS1_X_VAL, DEC));
  SendInst(_JS1_Y, String(JS1_Y_VAL, DEC));
  
  SendInst(_JS2_X, String(JS2_X_VAL, DEC));
  SendInst(_JS2_Y, String(JS2_Y_VAL, DEC));
  
  TICK_VER_COUNTER += 4;
  }
}

void ProcessBTN()
{
  BTN1_VAL = digitalRead(PIN_BTN_1);
  BTN2_VAL = digitalRead(PIN_BTN_2);
  BTN3_VAL = digitalRead(PIN_BTN_3);
  BTN4_VAL = digitalRead(PIN_BTN_4);
  
  if (BTN1_VAL == HIGH)
  {
    // SAFE_MODE trig, proceed
    if (SAFE_MODE_STE == true) 
    { 
      SAFE_MODE_STE = false;
      DisableState(SAFE_MODE);
      _LCD.clear();
      _LCD.home();
      _LCD.print(_LCD_MSG_SAFE_MODE_SWT + "0");
      CheckFailure(FAIL_DELAY);
      TICK_VER_COUNTER += 1;
    }
    else if (SAFE_MODE_STE == false)
    { 
      SAFE_MODE_STE = true;
      EnableState(SAFE_MODE);
      _LCD.clear();
      _LCD.home();
      _LCD.print(_LCD_MSG_SAFE_MODE_SWT + "1");
      CheckFailure(FAIL_DELAY);
      TICK_VER_COUNTER += 1;
    };
    BTN1_VAL == LOW;
  }
  else if (BTN2_VAL == HIGH)
  {
    //  SAFETY_MEAS trig, proceed
    if (SAFETY_MEAS_STE == true)
    {
      SAFETY_MEAS_STE == false;
      DisableState(SAFETY_MEAS);
      _LCD.clear();
      _LCD.home();
      _LCD.print(_LCD_MSG_SAFETY_MEAS_SWT + "0");
      CheckFailure(FAIL_DELAY);
      TICK_VER_COUNTER += 1;
    }
    else if (SAFETY_MEAS == false)
    {
      SAFETY_MEAS_STE == true;
      EnableState(SAFETY_MEAS);
      _LCD.clear();
      _LCD.home();
      _LCD.print(_LCD_MSG_SAFETY_MEAS_SWT + "1");
      CheckFailure(FAIL_DELAY);
      TICK_VER_COUNTER += 1;
    }
    BTN2_VAL = LOW;
  }
  else if (BTN3_VAL == HIGH)
  {
    //  LIGHTS_MODE trig, proceed
    if (LIGHTS_MODE_STE == true)
    {
      LIGHTS_MODE_STE == false;
      DisableState(LIGHTS_MODE);
      _LCD.clear();
      _LCD.home();
      _LCD.print(_LCD_MSG_LIGHTS_MODE_SWT + "0");
      CheckFailure(FAIL_DELAY);
      TICK_VER_COUNTER += 1;
    }
    else if (LIGHTS_MODE_STE == false)
    {
      LIGHTS_MODE_STE == true;
      EnableState(LIGHTS_MODE);
      _LCD.clear();
      _LCD.home();
      _LCD.print(_LCD_MSG_LIGHTS_MODE_SWT + "1");
      CheckFailure(FAIL_DELAY);
      TICK_VER_COUNTER += 1;
    }
    BTN3_VAL = LOW;
  }
  else if (BTN4_VAL == HIGH)
  {
    // REVERSE_THRUST trig, proceed
    if (REVERSE_THRUST_STE == true)
    {
      REVERSE_THRUST_STE == false;
      DisableState(REVERSE_THRUST);
      _LCD.clear();
      _LCD.home();
      _LCD.print(_LCD_MSG_REVERSE_THRUST_SWT + "0");
      CheckFailure(FAIL_DELAY);
      TICK_VER_COUNTER += 1;
    }
    else if (REVERSE_THRUST_STE == false)
    {
      REVERSE_THRUST_STE == true;
      EnableState(REVERSE_THRUST);
      _LCD.clear();
      _LCD.home();
      _LCD.print(_LCD_MSG_REVERSE_THRUST_SWT + "1");
      CheckFailure(FAIL_DELAY);
      TICK_VER_COUNTER += 1;
    }
    BTN4_VAL = LOW;
  }
}