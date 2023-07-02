#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

LiquidCrystal_I2C lcd(0x27,16,2);  

void setup()
{
  mlx.begin();  
  lcd.begin();                      
  lcd.backlight();
}


void loop()
{
  lcd.setCursor(1,0);
  if(mlx.readObjectTempC()+2.2>37.3)
  {
    lcd.print("HUBUNGI UKS!");
    lcd.setCursor(2,1);
    lcd.print("Suhu: ");
     lcd.print(mlx.readObjectTempC()+2.2);
     lcd.print("C    ");
    delay(3000);
    
    
  }
  lcd.setCursor(1,0);
  lcd.print(" Bebas Corona");
  lcd.setCursor(2,1);
  lcd.print("Suhu: ");
  lcd.print(mlx.readObjectTempC()+2.2);
  lcd.print("C    ");
  delay(3000);
}
