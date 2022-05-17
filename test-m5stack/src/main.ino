#include <NeoPixelBus.h>

const uint16_t PixelCount = 1; // this example assumes 4 pixels, making it smaller will cause a failure
const uint8_t PixelPin = 27;  // make sure to set this to the correct pin, ignored for Esp8266

#define colorSaturation 128

// three element pixels, in different order and speeds
NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip(PixelCount, PixelPin);
//NeoPixelBus<NeoRgbFeature, Neo400KbpsMethod> strip(PixelCount, PixelPin);

// For Esp8266, the Pin is omitted and it uses GPIO3 due to DMA hardware use.  
// There are other Esp8266 alternative methods that provide more pin options, but also have
// other side effects.
// for details see wiki linked here https://github.com/Makuna/NeoPixelBus/wiki/ESP8266-NeoMethods 

// You can also use one of these for Esp8266, 
// each having their own restrictions
//
// These two are the same as above as the DMA method is the default
// NOTE: These will ignore the PIN and use GPI03 pin
//NeoPixelBus<NeoGrbFeature, NeoEsp8266Dma800KbpsMethod> strip(PixelCount, PixelPin);
//NeoPixelBus<NeoRgbFeature, NeoEsp8266Dma400KbpsMethod> strip(PixelCount, PixelPin);

// Uart method is good for the Esp-01 or other pin restricted modules
// for details see wiki linked here https://github.com/Makuna/NeoPixelBus/wiki/ESP8266-NeoMethods 
// NOTE: These will ignore the PIN and use GPI02 pin
//NeoPixelBus<NeoGrbFeature, NeoEsp8266Uart1800KbpsMethod> strip(PixelCount, PixelPin);
//NeoPixelBus<NeoRgbFeature, NeoEsp8266Uart1400KbpsMethod> strip(PixelCount, PixelPin);

// The bitbang method is really only good if you are not using WiFi features of the ESP
// It works with all but pin 16
//NeoPixelBus<NeoGrbFeature, NeoEsp8266BitBang800KbpsMethod> strip(PixelCount, PixelPin);
//NeoPixelBus<NeoRgbFeature, NeoEsp8266BitBang400KbpsMethod> strip(PixelCount, PixelPin);

// four element pixels, RGBW
//NeoPixelBus<NeoRgbwFeature, Neo800KbpsMethod> strip(PixelCount, PixelPin);

RgbColor red(colorSaturation, 0, 0);
RgbColor green(0, colorSaturation, 0);
RgbColor blue(0, 0, colorSaturation);
RgbColor white(colorSaturation);
RgbColor black(0);

HslColor hslRed(red);
HslColor hslGreen(green);
HslColor hslBlue(blue);
HslColor hslWhite(white);
HslColor hslBlack(black);
#include "Button.h"


void setup()
{
    Serial.begin(115200);
    while (!Serial); // wait for serial attach

    Serial.println();
    Serial.println("Initializing...");
    Serial.flush();

    // this resets all the neopixels to an off state
    strip.Begin();
    strip.Show();

    Serial.println();
    Serial.println("Running...");

}


void loop()
{
    Button button = Button(39, true, 10);
    if(button.isPressed()){
        // set the colors, 
        // if they don't match in order, you need to use NeoGrbFeature feature
        strip.SetPixelColor(0, red);
        strip.Show();
        delay(1000);
        
        strip.SetPixelColor(0, green);
        strip.Show();
        delay(1000);

        strip.SetPixelColor(0, blue);
        strip.Show();
        delay(1000);
        strip.SetPixelColor(0, white);
        strip.Show();

        delay(1000);

        Serial.println("Off ...");

        // turn off the pixels
        strip.SetPixelColor(0, black);
        strip.Show();
    

        delay(1000);

        // set the colors, 
        // if they don't match in order, you may need to use NeoGrbFeature feature
        strip.SetPixelColor(0, hslRed);
        strip.Show();
        delay(500);
        strip.SetPixelColor(0, hslGreen);
        strip.Show();
        delay(500);
        strip.SetPixelColor(0, hslBlue);
        strip.Show();
        delay(500);
        strip.SetPixelColor(0, hslWhite);
        strip.Show();


        delay(1000);

        Serial.println("Off again...");
        
        // turn off the pixels
        strip.SetPixelColor(0, hslBlack);

        strip.Show();
        
    }
}
