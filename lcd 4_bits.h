
#define LCD_Data_Dir DDRA
#define LCD_Command_Dir DDRB
#define LCD_Data_Port PORTA
#define LCD_Command_Port PORTB
#define RS PB1
#define RW PB2
#define EN PB3


//Prototypes
void LCD_Command(unsigned char cmnd);
void LCD_Char (unsigned char char_data);
void LCD_Init (void);
void LCD_String (char *str);
void LCD_String_xy (char row, char pos, char *str);
void LCD_Clear();
void lcd_into_string(char data);