#include "Arduboy2Ext.h"

Arduboy2Ext::Arduboy2Ext() : Arduboy2Base() { }

uint8_t Arduboy2Ext::justPressedButtons() const {

    return (~previousButtonState & currentButtonState);

}

uint8_t Arduboy2Ext::pressedButtons() const {

    return currentButtonState;

}

void Arduboy2Ext::clearButtonState() {

    currentButtonState = previousButtonState = 0;

}


void Arduboy2Ext::resetFrameCount() {

    frameCount = 0;

}

uint8_t Arduboy2Ext::getFrameCount() const {

    return frameCount;

}

uint8_t Arduboy2Ext::getFrameCount(uint8_t mod) const {

    return frameCount % mod;

}

bool Arduboy2Ext::getFrameCountHalf(uint8_t mod) const {

	return getFrameCount(mod) >= (mod / 2);

}

bool Arduboy2Ext::isFrameCount(uint8_t mod) const {

    return (frameCount % mod) == 0;

}

bool Arduboy2Ext::isFrameCount(uint8_t mod, uint8_t val) const {

    return (frameCount % mod) == val;

}


void Arduboy2Ext::displayClearToPattern(uint8_t idx) {


    const uint8_t pattern[] = { 32, 2, 136, 34, 85, 170, 119, 221, 223, 253, 0, 0, 255, 255 };

    display(true);
    memset(sBuffer, 0xff, 1024);

    for (uint8_t y = 0; y < 5; y++) {

        for (uint8_t x = 0; x < WIDTH; x++) {

            sBuffer[(y * WIDTH) + x] = pattern[(idx * 2) + (x % 2)];
            
        }

    }


}


/* ----------------------------------------------------------------------------
 *  Draw a horizontal dotted line. 
 */
void Arduboy2Ext::drawHorizontalDottedLine(uint8_t x1, uint8_t x2, uint8_t y, uint8_t colour) {

	uint8_t diff = (x2 - x1);

	for (uint8_t x = 0; x <= diff; x += 2) {

		drawPixel(x1 + x, y, colour);

    }

}


/* ----------------------------------------------------------------------------
 *  Draw a vertical dotted line. 
 */
void Arduboy2Ext::drawVerticalDottedLine(uint8_t y1, uint8_t y2, uint8_t x, uint8_t colour) {

	uint8_t diff = (y2 - y1);

	for (uint8_t y = 0; y <= diff; y += 2) {

		drawPixel(x, y1 + y, colour);

    }
  
}