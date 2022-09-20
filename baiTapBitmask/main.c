#include <stdio.h>
#include <unistd.h>
__int8 PORTA = 0x00;
typedef enum {
    GPIO_PIN_0 = 1, 
    GPIO_PIN_1 = 1 << 1,
    GPIO_PIN_2 = 1 << 2,
    GPIO_PIN_3 = 1 << 3,
    GPIO_PIN_4 = 1 << 4,
    GPIO_PIN_5 = 1 << 5,
    GPIO_PIN_6 = 1 << 6,
    GPIO_PIN_7 = 1 << 7
}GPIO_PIN;

typedef enum{
    HIGH,
    LOW
}STATUS;

void digitalWrite(GPIO_PIN PIN, STATUS status){
    switch (PIN)
    {
    case 0:
        if(status == HIGH) PORTA |= GPIO_PIN_0;
        else PORTA &= ~GPIO_PIN_0;
        printf("\nport A: %d", PORTA);
        break;
    case 1:
        if(status == HIGH) PORTA |= GPIO_PIN_1;
        else PORTA &= ~GPIO_PIN_1;
        printf("\nport A: %d", PORTA);
        break;
    case 2:
        if(status == HIGH) PORTA |= GPIO_PIN_2;
        else PORTA &= ~GPIO_PIN_2;
        printf("\nport A: %d", PORTA);
        break;
    case 3:
        if(status == HIGH) PORTA |= GPIO_PIN_3;
        else PORTA &= ~GPIO_PIN_3;
        printf("\nport A: %d", PORTA);
        break;
    case 4:
        if(status == HIGH) PORTA |= GPIO_PIN_4;
        else PORTA &= ~GPIO_PIN_4;
        printf("\nport A: %d", PORTA);
        break;
    case 5:
        if(status == HIGH) PORTA |= GPIO_PIN_5;
        else PORTA &= ~GPIO_PIN_5;
        printf("\nport A: %d", PORTA);
        break;
    case 6:
        if(status == HIGH) PORTA |= GPIO_PIN_6;
        else PORTA &= ~GPIO_PIN_6;
        printf("\nport A: %d", PORTA);
        break;
    case 7:
        if(status == HIGH) PORTA |= GPIO_PIN_7;
        else PORTA &= ~GPIO_PIN_7;
        printf("\nport A: %d", PORTA);
        break;
    default:
        break;
    }
}

void delay_x100ms(__int8 delay){
    while(delay-- > 0)
    {
        usleep(100000);
    }
}
void blinkLED(GPIO_PIN PIN, __int8 value){
    switch (PIN)
    {
    case 0:
        PORTA |= GPIO_PIN_0;
        printf("\nPIN %d --> STATUS: %d", PIN, PORTA);
        delay_x100ms(value);
        PORTA &= ~GPIO_PIN_0;
        printf("\nPIN %d --> STATUS: %d", PIN, PORTA);
        delay_x100ms(value);
        break;
    case 1:
        PORTA |= GPIO_PIN_1;
        printf("\nPIN %d --> STATUS: %d", PIN, PORTA);
        delay_x100ms(value);
        PORTA &= ~GPIO_PIN_1;
        printf("\nPIN %d --> STATUS: %d", PIN, PORTA);
        delay_x100ms(value);
        break;
    case 2:
        PORTA |= GPIO_PIN_2;
        printf("\nPIN %d --> STATUS: %d", PIN, PORTA);
        delay_x100ms(value);
        PORTA &= ~GPIO_PIN_2;
        printf("\nPIN %d --> STATUS: %d", PIN, PORTA);
        delay_x100ms(value);
        break;
    case 3:
        PORTA |= GPIO_PIN_3;
        printf("\nPIN %d --> STATUS: %d", PIN, PORTA);
        delay_x100ms(value);
        PORTA &= ~GPIO_PIN_3;
        printf("\nPIN %d --> STATUS: %d", PIN, PORTA);
        delay_x100ms(value);
        break;
    case 4:
        PORTA |= GPIO_PIN_4;
        printf("\nPIN %d --> STATUS: %d", PIN, PORTA);
        delay_x100ms(value);
        PORTA &= ~GPIO_PIN_4;
        printf("\nPIN %d --> STATUS: %d", PIN, PORTA);
        delay_x100ms(value);
        break;
    case 5:
        PORTA |= GPIO_PIN_5;
        printf("\nPIN %d --> STATUS: %d", PIN, PORTA);
        delay_x100ms(value);
        PORTA &= ~GPIO_PIN_5;
        printf("\nPIN %d --> STATUS: %d", PIN, PORTA);
        delay_x100ms(value);
        break;
    case 6:
        PORTA |= GPIO_PIN_6;
        printf("\nPIN %d --> STATUS: %d", PIN, PORTA);
        delay_x100ms(value);
        PORTA &= ~GPIO_PIN_6;
        printf("\nPIN %d --> STATUS: %d", PIN, PORTA);
        delay_x100ms(value);
        break;
    case 7:
        PORTA |= GPIO_PIN_7;
        printf("\nPIN %d --> STATUS: %d", PIN, PORTA);
        delay_x100ms(value);
        PORTA &= ~GPIO_PIN_7;
        printf("\nPIN %d --> STATUS: %d", PIN, PORTA);
        delay_x100ms(value);
        break;
    default:
        break;
    }

}


int main(void){
    digitalWrite(1,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(1,LOW);
    blinkLED(0,10);   
    return 0;
}