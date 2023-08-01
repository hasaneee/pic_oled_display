

#include "config.h"
#include "i2c.h"
#include "unbuffered_ssd1306.h"

void oled_puts(const char* c, uint8_t size) {
    while(*c != '\0') {
        SSD1306_PutStretchC(*c, size);
        c++;
    }
}

void main(void) {
    TRISD = 0x00;
    
    __delay_ms(1000);
    
    
    I2C_Initialize(2000);
    
    SSD1306_Init(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);
    // clear the display
    SSD1306_ClearDisplay();
        
    
    while(1) {
        PORTD ^= 0xFF;
        
        SSD1306_GotoXY(1,1);
        oled_puts("Embeddedthere.com", 1);
        SSD1306_GotoXY(1,2);
        oled_puts("Hi!", 2);
        __delay_ms(5000);
        SSD1306_ClearDisplay();
        
    }

    return;
}