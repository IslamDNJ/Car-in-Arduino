//based on CharacterDisplayEv_I2C for YWROBOT https://github.com/marcoschwartz/CharacterDisplayEv_I2C

#include "CharacterDisplayEv_I2C.h"
#include <inttypes.h>
#if defined(ARDUINO) && ARDUINO >= 100

#include "Arduino.h"

#define printIIC(args)	Wire.write(args)
inline size_t CharacterDisplayEv_I2C::write(uint8_t value) {
	send(value, Rs);
	return 1;
}

#else
#include "WProgram.h"

#define printIIC(args)	Wire.send(args)
inline void CharacterDisplayEv_I2C::write(uint8_t value) {
	send(value, Rs);
}

#endif
#include "Wire.h"

// When the display powers up, it is configured as follows:
//
// 1. Display clear
// 2. Function set: 
//    DL = 1; 8-bit interface data 
//    N = 0; 1-line display 
//    F = 0; 5x8 dot character font 
// 3. Display on/off control: 
//    D = 0; Display off 
//    C = 0; Cursor off 
//    B = 0; Blinking off 
// 4. Entry mode set: 
//    I/D = 1; Increment by 1
//    S = 0; No shift 
//
// Note, however, that resetting the Arduino doesn't reset the LCD, so we
// can't assume that its in that state when a sketch starts (and the
// LiquidCrystal constructor is called).

CharacterDisplayEv_I2C::CharacterDisplayEv_I2C(uint8_t lcd_Addr,uint8_t lcd_cols,uint8_t lcd_rows)
{
  _Addr = lcd_Addr;
  _cols = lcd_cols;
  _rows = lcd_rows;
  _backlightval = LCD_NOBACKLIGHT;
}

void CharacterDisplayEv_I2C::init(){
	init_priv();
}

void CharacterDisplayEv_I2C::init_priv()
{
	Wire.begin();
	_displayfunction = LCD_4BITMODE | LCD_1LINE | LCD_5x8DOTS | 0x02;
	begin(_cols, _rows);  
}

void CharacterDisplayEv_I2C::begin(uint8_t cols, uint8_t lines, uint8_t dotsize) {
	if (lines > 1) {
		_displayfunction |= LCD_2LINE;
	}
	_numlines = lines;

	// for some 1 line displays you can select a 10 pixel high font
	if ((dotsize != 0) && (lines == 1)) {
		_displayfunction |= LCD_5x10DOTS;
	}

	// SEE PAGE 45/46 FOR INITIALIZATION SPECIFICATION!
	// according to datasheet, we need at least 40ms after power rises above 2.7V
	// before sending commands. Arduino can turn on way befer 4.5V so we'll wait 50
	delay(50); 
  
	// Now we pull both RS and R/W low to begin commands
	expanderWrite(_backlightval);	// reset expanderand turn backlight off (Bit 8 =1)
	delay(1000);

  	//put the LCD into 4 bit mode
	// this is according to the hitachi HD44780 datasheet
	// figure 24, pg 46
	
	  // we start in 8bit mode, try to set 4 bit mode
//   write4bits(0x03 << 4);
//   delayMicroseconds(4500); // wait min 4.1ms
   
   // second try
//   write4bits(0x03 << 4);
//   delayMicroseconds(4500); // wait min 4.1ms
   
   // third go!
//   write4bits(0x03 << 4); 
//   delayMicroseconds(150);
	write4bits(0x00);
	delayMicroseconds(100);
	write4bits(0x00);
	delayMicroseconds(100);
	write4bits(0x00);
	delayMicroseconds(100);
	write4bits(0x00);
	delayMicroseconds(100);
	write4bits(0x00); 
	delayMicroseconds(150);

   // finally, set to 4-bit interface
   write4bits(0x02 << 4); 
   
	// set # lines, font size, etc.
	command(LCD_FUNCTIONSET | _displayfunction);  
	
	// turn the display on with no cursor or blinking default
	_displaycontrol = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;
	display();
	
	// clear it off
//	clear();
	
	// Initialize to default text direction (for roman languages)
	_displaymode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;
	
	// set the entry mode
	command(LCD_ENTRYMODESET | _displaymode);
	
	home();
  
}

/********** high level commands, for the user! */
void CharacterDisplayEv_I2C::clear(){
//  command(LCD_CLEARDISPLAY);  // clear display, set cursor position to zero
//  delayMicroseconds(2000);  // this command takes a long time!
    command(0x08);//��������� �����
	delayMicroseconds(1000); 
    command(0x17);//������������ � ��������� �����
	delayMicroseconds(1000); 
    command(0x01);//���������� clear, �������� �� ������ ���
	delayMicroseconds(1000); 
    command(0x04 | 0x08);//�������� �����
	delayMicroseconds(1000); 
}

void CharacterDisplayEv_I2C::home(){
	command(LCD_RETURNHOME);  // set cursor position to zero
	delayMicroseconds(2000);  // this command takes a long time!
}

void CharacterDisplayEv_I2C::setCursor(uint8_t col, uint8_t row){
	int row_offsets[] = { 0x00, 0x40, 0x14, 0x54 };
	if ( row > _numlines ) {
		row = _numlines-1;    // we count rows starting w/0
	}
	command(LCD_SETDDRAMADDR | (col + row_offsets[row]));
}

// Turn the display on/off (quickly)
void CharacterDisplayEv_I2C::noDisplay() {
	_displaycontrol &= ~LCD_DISPLAYON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void CharacterDisplayEv_I2C::display() {
	_displaycontrol |= LCD_DISPLAYON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Turns the underline cursor on/off
void CharacterDisplayEv_I2C::noCursor() {
	_displaycontrol &= ~LCD_CURSORON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void CharacterDisplayEv_I2C::cursor() {
	_displaycontrol |= LCD_CURSORON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Turn on and off the blinking cursor
void CharacterDisplayEv_I2C::noBlink() {
	_displaycontrol &= ~LCD_BLINKON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void CharacterDisplayEv_I2C::blink() {
	_displaycontrol |= LCD_BLINKON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// These commands scroll the display without changing the RAM
void CharacterDisplayEv_I2C::scrollDisplayLeft(void) {
	command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVELEFT);
}
void CharacterDisplayEv_I2C::scrollDisplayRight(void) {
	command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVERIGHT);
}

// This is for text that flows Left to Right
void CharacterDisplayEv_I2C::leftToRight(void) {
	_displaymode |= LCD_ENTRYLEFT;
	command(LCD_ENTRYMODESET | _displaymode);
}

// This is for text that flows Right to Left
void CharacterDisplayEv_I2C::rightToLeft(void) {
	_displaymode &= ~LCD_ENTRYLEFT;
	command(LCD_ENTRYMODESET | _displaymode);
}

// This will 'right justify' text from the cursor
void CharacterDisplayEv_I2C::autoscroll(void) {
	_displaymode |= LCD_ENTRYSHIFTINCREMENT;
	command(LCD_ENTRYMODESET | _displaymode);
}

// This will 'left justify' text from the cursor
void CharacterDisplayEv_I2C::noAutoscroll(void) {
	_displaymode &= ~LCD_ENTRYSHIFTINCREMENT;
	command(LCD_ENTRYMODESET | _displaymode);
}

// Allows us to fill the first 8 CGRAM locations
// with custom characters
void CharacterDisplayEv_I2C::createChar(uint8_t location, uint8_t charmap[]) {
	location &= 0x7; // we only have 8 locations 0-7
	command(LCD_SETCGRAMADDR | (location << 3));
	for (int i=0; i<8; i++) {
		write(charmap[i]);
	}
}

//createChar with PROGMEM input
void CharacterDisplayEv_I2C::createChar(uint8_t location, const char *charmap) {
	location &= 0x7; // we only have 8 locations 0-7
	command(LCD_SETCGRAMADDR | (location << 3));
	for (int i=0; i<8; i++) {
	    	write(pgm_read_byte_near(charmap++));
	}
}

// Turn the (optional) backlight off/on
void CharacterDisplayEv_I2C::noBacklight(void) {
	_backlightval=LCD_NOBACKLIGHT;
	expanderWrite(0);
}

void CharacterDisplayEv_I2C::backlight(void) {
	_backlightval=LCD_BACKLIGHT;
	expanderWrite(0);
}



/*********** mid level commands, for sending data/cmds */

inline void CharacterDisplayEv_I2C::command(uint8_t value) {
	send(value, 0);
}

void CharacterDisplayEv_I2C::outStr(char str[]){  
      int nn = 0; // symbol counter
      while (str[nn] != '\0')        {
            switch (str[nn]&0xFF){
			case 0xd0: break;	
			case 0xd1: break;	
            case 0x30: send(0xEE,HIGH); break; //0->'O'    
            case 0x80: send(0xF0,HIGH); break; //'�'    
            case 0x81: send(0xF1,HIGH); break; //'�'    
            case 0x82: send(0xF2,HIGH); break; //'�'   
            case 0x83: send(0xF3,HIGH); break; //'�'   
            case 0x84: send(0xF4,HIGH); break; //'�'   
            case 0x85: send(0xF5,HIGH); break; //'�'   
            case 0x86: send(0xF6,HIGH); break; //'�'    
            case 0x87: send(0xF7,HIGH); break; //'�'    
            case 0x88: send(0xF8,HIGH); break; //'�'    
            case 0x89: send(0xF9,HIGH); break; //'�'   
            case 0x8A: send(0xFA,HIGH); break; //'�'   
            case 0x8B: send(0xFB,HIGH); break; //'�'   
            case 0x8C: send(0xFC,HIGH); break; //'�'   
            case 0x8D: send(0xFD,HIGH); break; //'�'    
            case 0x8E: send(0xFE,HIGH); break; //'�'    
            case 0x8F: send(0xFF,HIGH); break; //'�'    
//      --------------------  
            case 0x90: send(0xC0,HIGH); break; //'�'
            case 0x91: send(0xC1,HIGH); break; //'�'
            case 0x92: send(0xC2,HIGH); break; //'�'
            case 0x93: send(0xC3,HIGH); break; //'�'
            case 0x94: send(0xC4,HIGH); break; //'�'
            case 0x95: send(0xC5,HIGH); break; //'�'
            case 0x96: send(0xC6,HIGH); break; //'�'
            case 0x97: send(0xC7,HIGH); break; //'�'
            case 0x98: send(0xC8,HIGH); break; //'�'
            case 0x99: send(0xC9,HIGH); break; //'�'
            case 0x9A: send(0xCA,HIGH); break; //'�'
            case 0x9B: send(0xCB,HIGH); break; //'�'
            case 0x9C: send(0xCC,HIGH); break; //'�'
            case 0x9D: send(0xCD,HIGH); break; //'�'
            case 0x9E: send(0xCE,HIGH); break; //'�'
            case 0x9F: send(0xCF, HIGH); break; //'�'
//      --------------------  
            case 0xA0: send(0xD0,HIGH); break; //'�'
            case 0xA1: send(0xD1,HIGH); break; //'�'
            case 0xA2: send(0xD2,HIGH); break; //'�'
            case 0xA3: send(0xD3,HIGH); break; //'�'
            case 0xA4: send(0xD4,HIGH); break; //'�'
            case 0xA5: send(0xD5,HIGH); break; //'�'
            case 0xA6: send(0xD6,HIGH); break; //'�'
            case 0xA7: send(0xD7,HIGH); break; //'�'
            case 0xA8: send(0xD8,HIGH); break; //'�'
            case 0xA9: send(0xD9,HIGH); break; //'�'
            case 0xAA: send(0xDA,HIGH); break; //'�'
            case 0xAB: send(0xDB,HIGH); break; //'�'
            case 0xAC: send(0xDC,HIGH); break; //eng'b'
            case 0xAD: send(0xDD,HIGH); break; //'�'
            case 0xAE: send(0xDE,HIGH); break; //'�'
            case 0xAF: send(0xDF,HIGH); break; //'�'
//      --------------------
            case 0xB0: send(0xE0,HIGH); break; //'�'
            case 0xB1: send(0xE1,HIGH); break; //'�'
            case 0xB2: send(0xE2,HIGH); break; //'�'
            case 0xB3: send(0xE3,HIGH); break; //'�'
            case 0xB4: send(0xE4,HIGH); break; //'�'
            case 0xB5: send(0xE5,HIGH); break; //'�'
            case 0xB6: send(0xE6,HIGH); break; //'�'
            case 0xB7: send(0xE7,HIGH); break; //'�'
            case 0xB8: send(0xE8,HIGH); break; //'�'
            case 0xB9: send(0xE9,HIGH); break; //'�'
            case 0xBA: send(0xEA,HIGH); break; //'�'
            case 0xBB: send(0xEB,HIGH); break; //'�'
            case 0xBC: send(0xEC,HIGH); break; //'�'
            case 0xBD: send(0xED,HIGH); break; //'�'
            case 0xBE: send(0xEE,HIGH); break; //'�'
            case 0xBF: send(0xEF,HIGH); break; //'�'
            default: send(str[nn], HIGH); 
        }
   nn++;
  }
}


/************ low level data pushing commands **********/

// write either command or data
void CharacterDisplayEv_I2C::send(uint8_t value, uint8_t mode) {
	uint8_t highnib=value&0xf0;
	uint8_t lownib=(value<<4)&0xf0;
       write4bits((highnib)|mode);
	write4bits((lownib)|mode); 
}

void CharacterDisplayEv_I2C::write4bits(uint8_t value) {
	expanderWrite(value);
	pulseEnable(value);
}


void CharacterDisplayEv_I2C::expanderWrite(uint8_t _data){                                        
	Wire.beginTransmission(_Addr);
	printIIC((int)(_data) | _backlightval);
	Wire.endTransmission();   
}

void CharacterDisplayEv_I2C::pulseEnable(uint8_t _data){
	expanderWrite(_data | En);	// En high
	delayMicroseconds(1);		// enable pulse must be >450ns
	
	expanderWrite(_data & ~En);	// En low
	delayMicroseconds(50);		// commands need > 37us to settle
} 


// Alias functions

void CharacterDisplayEv_I2C::cursor_on(){
	cursor();
}

void CharacterDisplayEv_I2C::cursor_off(){
	noCursor();
}

void CharacterDisplayEv_I2C::blink_on(){
	blink();
}

void CharacterDisplayEv_I2C::blink_off(){
	noBlink();
}

void CharacterDisplayEv_I2C::load_custom_character(uint8_t char_num, uint8_t *rows){
		createChar(char_num, rows);
}

void CharacterDisplayEv_I2C::setBacklight(uint8_t new_val){
	if(new_val){
		backlight();		// turn backlight on
	}else{
		noBacklight();		// turn backlight off
	}
}

void CharacterDisplayEv_I2C::printstr(const char c[]){
	//This function is not identical to the function used for "real" I2C displays
	//it's here so the user sketch doesn't have to be changed 
	print(c);
}


// unsupported API functions
void CharacterDisplayEv_I2C::off(){}
void CharacterDisplayEv_I2C::on(){}
void CharacterDisplayEv_I2C::setDelay (int cmdDelay,int charDelay) {}
uint8_t CharacterDisplayEv_I2C::status(){return 0;}
uint8_t CharacterDisplayEv_I2C::keypad (){return 0;}
uint8_t CharacterDisplayEv_I2C::init_bargraph(uint8_t graphtype){return 0;}
void CharacterDisplayEv_I2C::draw_horizontal_graph(uint8_t row, uint8_t column, uint8_t len,  uint8_t pixel_col_end){}
void CharacterDisplayEv_I2C::draw_vertical_graph(uint8_t row, uint8_t column, uint8_t len,  uint8_t pixel_row_end){}
void CharacterDisplayEv_I2C::setContrast(uint8_t new_val){}

	
