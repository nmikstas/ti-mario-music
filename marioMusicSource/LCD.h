#ifndef LCD_H_
#define LCD_H_

#define LCD_BUF_SIZE 1024

//LCD screen buffer.
static uint8_t lcd_buffer[LCD_BUF_SIZE];

//Column and row markers.
static uint8_t cur_row = 0, cur_col = 0;

//Array of LCD characters.
static uint8_t LCD_chars[][5] =
{
    //0x00
    {0x01, 0x01, 0x01, 0x01, 0x01}, //1 pixel black top
    {0x03, 0x03, 0x03, 0x03, 0x03}, //2 pixel black top
    {0x07, 0x07, 0x07, 0x07, 0x07}, //3 pixel black top
    {0x0F, 0x0F, 0x0F, 0x0F, 0x0F}, //4 pixel black top
    {0x1F, 0x1F, 0x1F, 0x1F, 0x1F}, //5 pixel black top
    {0x3F, 0x3F, 0x3F, 0x3F, 0x3F}, //6 pixel black top
    {0x7F, 0x7F, 0x7F, 0x7F, 0x7F}, //7 pixel black top
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF}, //Full black
    //0x08
    {0xFE, 0xFE, 0xFE, 0xFE, 0xFE}, //7 pixel black bottom(Backspace)
    {0xFC, 0xFC, 0xFC, 0xFC, 0xFC}, //6 pixel black bottom(Tab)
    {0xF8, 0xF8, 0xF8, 0xF8, 0xF8}, //5 pixel black bottom(Line feed)
    {0xF0, 0xF0, 0xF0, 0xF0, 0xF0}, //4 pixel black bottom
    {0xE0, 0xE0, 0xE0, 0xE0, 0xE0}, //3 pixel black bottom
    {0xC0, 0xC0, 0xC0, 0xC0, 0xC0}, //2 pixel black bottom(Carriage return)
    {0x80, 0x80, 0x80, 0x80, 0x80}, //1 pixel black bottom
    {0x00, 0x00, 0x00, 0x00, 0x00}, //No character
    //0x10
    {0x00, 0x00, 0x00, 0x00, 0x00}, //No character
    {0x00, 0x00, 0x00, 0x00, 0x00}, //No character
    {0x00, 0x00, 0x00, 0x00, 0x00}, //No character
    {0x00, 0x00, 0x00, 0x00, 0x00}, //No character
    {0x00, 0x00, 0x00, 0x00, 0x00}, //No character
    {0x00, 0x00, 0x00, 0x00, 0x00}, //No character
    {0x00, 0x00, 0x00, 0x00, 0x00}, //No character
    {0x00, 0x00, 0x00, 0x00, 0x00}, //No character
    //0x18
    {0x00, 0x00, 0x00, 0x00, 0x00}, //No character
    {0x00, 0x00, 0x00, 0x00, 0x00}, //No character
    {0x00, 0x00, 0x00, 0x00, 0x00}, //No character
    {0x08, 0x1C, 0x3E, 0x08, 0x0F}, //Enter.
    {0x20, 0x30, 0x38, 0x30, 0x20}, //Arrow up
    {0x08, 0x18, 0x38, 0x18, 0x08}, //Arrow down
    {0x00, 0x08, 0x1C, 0x3E, 0x00}, //Arrow left
    {0x00, 0x3E, 0x1C, 0x08, 0x00}, //Arrow right
    //0x20
    {0x00, 0x00, 0x00, 0x00, 0x00}, //Space
    {0x4F, 0x00, 0x00, 0x00, 0x00}, //!
    {0x00, 0x07, 0x00, 0x07, 0x00}, //"
    {0x14, 0x7F, 0x14, 0x7F, 0x14}, //#
    {0x24, 0x2A, 0x7F, 0x2A, 0x12}, //$
    {0x23, 0x13, 0x08, 0x64, 0x62}, //%
    {0x36, 0x49, 0x55, 0x22, 0x50}, //&
    {0x00, 0x05, 0x03, 0x00, 0x00}, //'
    //0x28
    {0x00, 0x1C, 0x22, 0x41, 0x00}, //(
    {0x00, 0x41, 0x22, 0x1C, 0x00}, //)
    {0x14, 0x08, 0x3E, 0x08, 0x14}, //Asterisk
    {0x08, 0x08, 0x3E, 0x08, 0x08}, //+
    {0x00, 0x50, 0x30, 0x00, 0x00}, //,
    {0x08, 0x08, 0x08, 0x08, 0x08}, //-
    {0x60, 0x60, 0x00, 0x00, 0x00}, //.
    {0x20, 0x10, 0x08, 0x04, 0x02}, ///
    //0x30
    {0x3E, 0x51, 0x49, 0x45, 0x3E}, //0
    {0x00, 0x42, 0x7F, 0x40, 0x00}, //1
    {0x42, 0x61, 0x51, 0x49, 0x46}, //2
    {0x21, 0x41, 0x45, 0x4B, 0x31}, //3
    {0x18, 0x14, 0x12, 0x7F, 0x10}, //4
    {0x27, 0x45, 0x45, 0x45, 0x39}, //5
    {0x3C, 0x4A, 0x49, 0x49, 0x30}, //6
    {0x01, 0x71, 0x09, 0x05, 0x03}, //7
    //0x38
    {0x36, 0x49, 0x49, 0x49, 0x36}, //8
    {0x06, 0x49, 0x49, 0x29, 0x1E}, //9
    {0x00, 0x36, 0x36, 0x00, 0x00}, //:
    {0x56, 0x36, 0x00, 0x00, 0x00}, //;
    {0x08, 0x14, 0x22, 0x41, 0x00}, //<
    {0x14, 0x14, 0x14, 0x14, 0x14}, //=
    {0x00, 0x41, 0x22, 0x14, 0x08}, //>
    {0x02, 0x01, 0x51, 0x09, 0x06}, //?
    //0x40
    {0x32, 0x49, 0x79, 0x41, 0x3E}, //@
    {0x7E, 0x11, 0x11, 0x11, 0x7E}, //A
    {0x7F, 0x49, 0x49, 0x49, 0x36}, //B
    {0x3E, 0x41, 0x41, 0x41, 0x22}, //C
    {0x7F, 0x41, 0x41, 0x22, 0x1C}, //D
    {0x7F, 0x49, 0x49, 0x49, 0x41}, //E
    {0x7F, 0x09, 0x09, 0x09, 0x01}, //F
    {0x3E, 0x41, 0x49, 0x49, 0x7A}, //G
    //0x48
    {0x7F, 0x08, 0x08, 0x08, 0x7F}, //H
    {0x41, 0x41, 0x7F, 0x41, 0x41}, //I
    {0x20, 0x40, 0x41, 0x3F, 0x01}, //J
    {0x7F, 0x08, 0x14, 0x22, 0x41}, //K
    {0x7F, 0x40, 0x40, 0x40, 0x40}, //L
    {0x7F, 0x02, 0x0C, 0x02, 0x7F}, //M
    {0x7F, 0x04, 0x08, 0x10, 0x7F}, //N
    {0x3E, 0x41, 0x41, 0x41, 0x3E}, //O
    //0x50
    {0x7F, 0x09, 0x09, 0x09, 0x06}, //P
    {0x3E, 0x41, 0x51, 0x21, 0x5E}, //Q
    {0x7F, 0x09, 0x19, 0x29, 0x46}, //R
    {0x46, 0x49, 0x49, 0x49, 0x31}, //S
    {0x01, 0x01, 0x7F, 0x01, 0x01}, //T
    {0x3F, 0x40, 0x40, 0x40, 0x3F}, //U
    {0x1F, 0x20, 0x40, 0x20, 0x1F}, //V
    {0x3F, 0x40, 0x38, 0x40, 0x3F}, //W
    //0x58
    {0x63, 0x14, 0x08, 0x14, 0x63}, //X
    {0x07, 0x08, 0x70, 0x08, 0x07}, //Y
    {0x61, 0x51, 0x49, 0x45, 0x43}, //Z
    {0x00, 0x7F, 0x41, 0x41, 0x00}, //[
    {0x02, 0x04, 0x08, 0x10, 0x20}, //Backslash
    {0x00, 0x41, 0x41, 0x7F, 0x00}, //]
    {0x04, 0x02, 0x01, 0x02, 0x04}, //^
    {0x40, 0x40, 0x40, 0x40, 0x40}, //_
    //0x60
    {0x00, 0x01, 0x02, 0x04, 0x00}, //Back tick
    {0x20, 0x54, 0x54, 0x54, 0x78}, //a
    {0x7F, 0x48, 0x44, 0x44, 0x38}, //b
    {0x38, 0x44, 0x44, 0x44, 0x20}, //c
    {0x38, 0x44, 0x44, 0x48, 0x7F}, //d
    {0x38, 0x54, 0x54, 0x54, 0x18}, //e
    {0x08, 0x7E, 0x09, 0x01, 0x02}, //f
    {0x0C, 0x52, 0x52, 0x52, 0x3E}, //g
    //0x68
    {0x7F, 0x08, 0x04, 0x04, 0x78}, //h
    {0x00, 0x44, 0x7D, 0x40, 0x00}, //i
    {0x20, 0x40, 0x44, 0x3D, 0x00}, //j
    {0x7F, 0x10, 0x28, 0x44, 0x00}, //k
    {0x00, 0x41, 0x7F, 0x40, 0x00}, //l
    {0x7C, 0x04, 0x18, 0x04, 0x78}, //m
    {0x7C, 0x08, 0x04, 0x04, 0x78}, //n
    {0x38, 0x44, 0x44, 0x44, 0x38}, //o
    //0x70
    {0x7C, 0x14, 0x14, 0x14, 0x08}, //p
    {0x08, 0x14, 0x14, 0x18, 0x7C}, //q
    {0x7C, 0x08, 0x04, 0x04, 0x08}, //r
    {0x48, 0x54, 0x54, 0x54, 0x20}, //s
    {0x04, 0x3F, 0x44, 0x40, 0x20}, //t
    {0x3C, 0x40, 0x40, 0x20, 0x7C}, //u
    {0x1C, 0x20, 0x40, 0x20, 0x1C}, //v
    {0x3C, 0x40, 0x30, 0x40, 0x3C}, //w
    //0x78
    {0x44, 0x28, 0x10, 0x28, 0x44}, //x
    {0x0C, 0x50, 0x50, 0x50, 0x3C}, //y
    {0x44, 0x64, 0x54, 0x4C, 0x44}, //z
    {0x00, 0x08, 0x36, 0x41, 0x00}, //{
    {0x00, 0x00, 0x7F, 0x00, 0x00}, //|
    {0x00, 0x41, 0x36, 0x08, 0x00}, //}
    {0x08, 0x04, 0x08, 0x04, 0x00}, //~
    {0x00, 0x00, 0x00, 0x00, 0x00}  //No character (Delete)
};

static uint8_t LCD_graph[][8] =
{
    //0x00
    {0xFF, 0x01, 0x05, 0x01, 0x71, 0x79, 0x09, 0x09},   //Question Mark, UL
    {0xFF, 0x80, 0xA0, 0x80, 0x80, 0x80, 0x80, 0x9B},   //Question Mark, LL
    {0x89, 0xF9, 0xF1, 0x01, 0x01, 0x05, 0x01, 0xFF},   //Question Mark, UR
    {0x9B, 0x80, 0x80, 0x80, 0x80, 0xA0, 0x80, 0xFF},   //Question Mark, LR
    //0x04
    {0x89, 0x89, 0x89, 0xF9, 0x89, 0x89, 0x89, 0x8F},   //Bricks, UL
    {0x88, 0x88, 0x88, 0xF8, 0x88, 0x88, 0x88, 0x8F},   //Bricks, LL
    {0x89, 0x89, 0x89, 0xF9, 0x89, 0x89, 0x89, 0x8F},   //Bricks, UR
    {0x88, 0x88, 0x88, 0xF8, 0x88, 0x88, 0x88, 0x8F},   //Bricks, LR
    //0x08
    {0x00, 0x00, 0x00, 0xF0, 0x0C, 0xF2, 0x0A, 0x0A},   //Coin, UL
    {0x00, 0x00, 0x00, 0x0F, 0x30, 0x4F, 0x50, 0x50},   //Coin, LL
    {0xF2, 0x02, 0x0E, 0xFC, 0xF0, 0x00, 0x00, 0x00},   //Coin, UR
    {0x4F, 0x40, 0x70, 0x3F, 0x0F, 0x00, 0x00, 0x00},   //Coin, LR
    //0x0C
    {0xC0, 0x30, 0xE8, 0xF4, 0xF2, 0xF2, 0xE1, 0x01},   //Mushroom, UL
    {0x03, 0x04, 0x04, 0x0D, 0x77, 0x83, 0x9E, 0x82},   //Mushroom, LL
    {0x07, 0x0F, 0x0E, 0x0E, 0xC4, 0xC8, 0xF0, 0xC0},   //Mushroom, UR
    {0x82, 0x9E, 0xE2, 0x7E, 0x0C, 0x05, 0x05, 0x03},   //Mushroom, LR
    //0x10
    {0x00, 0x80, 0xE0, 0x1C, 0x1E, 0xFE, 0xCF, 0x0F},   //Mario Stand L1
    {0x00, 0x83, 0x43, 0x26, 0x1C, 0xF0, 0x10, 0x10},   //Mario Stand L2
    {0x3E, 0xC9, 0x08, 0x88, 0xFF, 0xF7, 0xFC, 0xFC},   //Mario Stand L3
    {0xC0, 0xCE, 0xBF, 0x9F, 0x9F, 0xFF, 0x03, 0x01},   //Mario Stand L4
    {0x3F, 0x2F, 0x8F, 0x18, 0x28, 0x28, 0xC0, 0x00},   //Mario Stand R1
    {0x11, 0x13, 0xFB, 0x17, 0x27, 0x43, 0x80, 0x00},   //Mario Stand R2
    {0xFC, 0xFC, 0xF7, 0xFF, 0x88, 0x08, 0xC9, 0x3E},   //Mario Stand R3
    {0x01, 0x03, 0xFF, 0x8F, 0x8F, 0xBF, 0xCE, 0xC0},   //Mario Stand R4
    //0x18
    {0x00, 0x00, 0x00, 0x80, 0x70, 0x78, 0xF8, 0x3C},   //Mario Run1 L1
    {0x00, 0x00, 0x06, 0xCF, 0xE8, 0x30, 0x23, 0x23},   //Mario Run1 L2
    {0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFC, 0xF0, 0xE0},   //Mario Run1 L3
    {0x7F, 0x21, 0x11, 0x10, 0x0F, 0x0F, 0x0F, 0x03},   //Mario Run1 L4
    {0x3C, 0xFC, 0xBC, 0x3C, 0x60, 0xA0, 0xA0, 0x00},   //Mario Run1 R1
    {0x40, 0xC4, 0xAC, 0x1E, 0x1C, 0x1C, 0x0C, 0x03},   //Mario Run1 R2
    {0xE0, 0xC0, 0xC1, 0xC1, 0x67, 0x99, 0x12, 0x1E},   //Mario Run1 R3
    {0x03, 0xFD, 0x8D, 0x8E, 0xBF, 0xC3, 0xC0, 0x00},   //Mario Run1 R4
    //0x20
    {0x00, 0x00, 0xC0, 0x38, 0x3C, 0xFC, 0x9E, 0x1E},   //Mario Run2 L1
    {0x00, 0x03, 0xC7, 0xEC, 0x38, 0x11, 0x11, 0x30},   //Mario Run2 L2
    {0x00, 0x00, 0x7F, 0xFF, 0xF0, 0xE0, 0xC0, 0xC0},   //Mario Run2 L3
    {0x00, 0x00, 0x00, 0x00, 0x63, 0x5F, 0x8D, 0x88},   //Mario Run2 L4
    {0x7E, 0x5E, 0x1E, 0x30, 0x50, 0x50, 0x80, 0x00},   //Mario Run2 R1
    {0xE2, 0xF6, 0x6F, 0x8E, 0x0E, 0x06, 0x01, 0x00},   //Mario Run2 R2
    {0x3D, 0x23, 0x61, 0xF7, 0xF8, 0x70, 0x00, 0x00},   //Mario Run2 R3
    {0xB8, 0xC8, 0xDC, 0x1A, 0x01, 0x00, 0x00, 0x00},   //Mario Run2 R4
    //0x28
    {0x00, 0x80, 0xE0, 0x1C, 0x1E, 0xFE, 0xCF, 0x0F},   //Mario Run3 L1
    {0x00, 0x83, 0x63, 0x26, 0x14, 0x18, 0x10, 0x30},   //Mario Run3 L2
    {0x7C, 0x8B, 0x88, 0x08, 0xC8, 0xF8, 0xFC, 0xFE},   //Mario Run3 L3
    {0x1C, 0x64, 0x82, 0xE3, 0x9E, 0x1D, 0x0B, 0x0B},   //Mario Run3 L4
    {0x3F, 0x2F, 0x8F, 0x18, 0x28, 0x28, 0xC0, 0x00},   //Mario Run3 R1
    {0xF1, 0xDB, 0x17, 0x67, 0xC7, 0x23, 0x10, 0xE0},   //Mario Run3 R2
    {0xFF, 0xFB, 0xFC, 0x7C, 0x7B, 0x87, 0x42, 0xE1},   //Mario Run3 R3
    {0x07, 0x07, 0x07, 0x08, 0x08, 0x08, 0x08, 0x0F},   //Mario Run3 R4
};

//Function prototypes.
void lcd_write_command(Uint16, CSL_SpiHandle);
void lcd_write_byte(Uint16, CSL_SpiHandle);
void lcd_clear(CSL_SpiHandle);
void lcd_init(CSL_SpiHandle);
void lcd_clear_buffer(void);
void lcd_display_buffer(CSL_SpiHandle);
void draw_pixel(int, int);
void draw_line(int, int, int, int);
void draw_circle(int, int, int);
void set_cursor(uint8_t, uint8_t);
void get_cursor(uint8_t*, uint8_t*);
void write_string(const char*);
void write_tile(const char, uint8_t, uint8_t);
void write_char(const char);
void clear_char(void);
void validate_cursor(void);
#endif
