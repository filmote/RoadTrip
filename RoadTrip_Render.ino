#include <Arduboy2.h>

void renderHud() {


    // Gearbox ..

    switch (car.getTransmissionType()) {

        case TransmissionType::Manual:
            {
                uint8_t frame = arduboy.getFrameCount(8) / 2;
                Sprites::drawPlusMask(1, 1, Images::Gearbox, 0);

                switch (car.getGear()) {

                    case 0:
                        Sprites::drawPlusMask(7 + ((frame % 3) - 1), 7 + ((frame % 3) - 1), Images::Gearbox_Knob, 0);
                        break;

                    case 1 ... 5:
                        Sprites::drawPlusMask(pgm_read_byte(&Constants::GearboxX[car.getGear()]), pgm_read_byte(&Constants::GearboxY[car.getGear()]), Images::Gearbox_Knob, 0);
                        break;

                    default: break;

                }

            }
            
            break;

        case TransmissionType::Auto:
        
            switch (car.getGear()) {

                case 0:
                    Sprites::drawExternalMask(1, 1, Images::AutoP, Images::AutoMask, 0, 0);
                    break;

                case 1 ... 5:
                    Sprites::drawExternalMask(1, 1, Images::AutoD, Images::AutoMask, 0, 0);
                    Sprites::drawOverwrite(18, 6, Images::AutoNumbers, car.getGear() - 1);
                    break;

                default: break;

            }
            
            break;

    }


    // Render Tacho ..

    {
        uint8_t tacho = car.getTacho();
        uint8_t offset = car.getTransmissionType() == TransmissionType::Manual ? 0 : 4;
        
        Sprites::drawExternalMask(26 + offset, 1, Images::Tacho, Images::Tacho_Mask, 0, 0);

        if (tacho == 1) {

            if (arduboy.getFrameCountHalf(32)) {

                arduboy.drawRect(28 + offset, 3, 2, 5, BLACK);

            }

        }
        else {

            for (uint8_t i = 0, x = 28; i < tacho; i++, x = x + 3) {

                switch (i) {

                    case 0 ... 5:
                        arduboy.drawFastVLine(x + offset, 3, 5, BLACK);
                        break;

                    case 6 ... 7:

                        arduboy.drawRect(x + offset, 3, 2, 5, BLACK);
                        break;

                }

            } 

        }

    }


    // Render distance travelled ..

    {
		uint8_t digits[5] = {};
		extractDigits(digits, gamePlayVars.distance / 10);
		
		for (uint8_t i = 0, x2 = 84 ; i < 5; ++i, x2 -= 6) {
			Sprites::drawOverwrite(x2, 1, Images::numbers_white, digits[i]);
		}

		Sprites::drawOverwrite(90, 1, Images::numbers_black, gamePlayVars.distance % 10);
        arduboy.drawFastHLine(60, 1, 37, BLACK);
        arduboy.drawFastHLine(60, 9, 37, BLACK);

        arduboy.drawFastVLine(90, 1, 8, BLACK);

        if (gamePlayVars.getTimeOfDay() == TimeOfDay::Day) {
            arduboy.drawFastVLine(96, 1, 8, BLACK);
        }
        else {
           arduboy.drawFastVLine(97, 2, 7, BLACK);
           arduboy.drawFastVLine(96, 2, 7, WHITE);
        }

	}



    // Render car counter ..

    Sprites::drawPlusMask(104, 1, Images::CarCounter, 0);

    #ifdef SOUNDS

        if (gamePlayVars.carsPassed > 0 && (gamePlayVars.timeOfDay > 3000) && arduboy.getFrameCount(32) == 0) {

            sound.tones(Sounds::Alert);

        }

    #endif

    if ((gamePlayVars.carsPassed > 0 && gamePlayVars.timeOfDay > 3000 && arduboy.getFrameCountHalf(32)) || gamePlayVars.timeOfDay <= 3000) {

		uint8_t digits[3] = {};
		extractDigits(digits, gamePlayVars.carsPassed);
		
		for (uint8_t i = 0, x2 = 118 ; i < 3; ++i, x2 -= 6) {
			Sprites::drawOverwrite(x2, 3, Images::numbers_white, digits[i]);
		}

	}

}

void renderPlayerCar() {


    // Calculate an index for the wheel graphic using the speed ..
    
    uint8_t index = 34 - (car.getSpeed_Display() * 2);  // 0 - 16

    if (index != 34) {
        index = arduboy.getFrameCountHalf(index);
    }
    else {
        index = 0;
    }
  
    
    // Set car X to camera X (as car is always in the middle of screen) ..

    car.setX(cameraPos.getX());
    car.setY(world.roadHeightAt(car.getZ()));



    // Render the car ..

    #ifndef DEBUG_COLLISIONS

        // Sprites::drawPlusMask(43, 64 - Constants::PlayerCarHeightPX, Images::Player, index);
        Sprites::drawExternalMask(46, 64 - Constants::PlayerCarHeightPX, Images::Player, Images::Player_Mask, index, 0);

    #else

        Vec3 leftTopCorner = car.clone();
        leftTopCorner.setX(leftTopCorner.getX() - (Constants::PlayerCarWidthUnits / 2));
        leftTopCorner.setZ(leftTopCorner.getZ() + Constants::PlayerCarLengthUnits);

        Vec3 rightTopCorner = car.clone();
        rightTopCorner.setX(rightTopCorner.getX() + (Constants::PlayerCarWidthUnits / 2));
        rightTopCorner.setZ(rightTopCorner.getZ() + Constants::PlayerCarLengthUnits);
        
        Vec3 leftBottomCorner = car.clone();
        leftBottomCorner.setX(leftBottomCorner.getX() - (Constants::PlayerCarWidthUnits / 2));

        Vec3 rightBottomCorner = car.clone();
        rightBottomCorner.setX(rightBottomCorner.getX() + (Constants::PlayerCarWidthUnits / 2));
        
        Vec3 leftTopCornerPersepective = world.perspective(leftTopCorner, cameraPos);
        Vec3 rightTopCornerPersepective = world.perspective(rightTopCorner, cameraPos);
        Vec3 leftBottomCornerPersepective = world.perspective(leftBottomCorner, cameraPos);
        Vec3 rightBottomCornerPersepective = world.perspective(rightBottomCorner, cameraPos);

        arduboy.drawLine(leftTopCornerPersepective.getX(), leftTopCornerPersepective.getY(), rightTopCornerPersepective.getX(), rightTopCornerPersepective.getY());
        arduboy.drawLine(rightTopCornerPersepective.getX(), rightTopCornerPersepective.getY(), rightBottomCornerPersepective.getX(), rightBottomCornerPersepective.getY());
        arduboy.drawLine(rightBottomCornerPersepective.getX(), rightBottomCornerPersepective.getY(), leftBottomCornerPersepective.getX(), leftBottomCornerPersepective.getY());
        arduboy.drawLine(leftBottomCornerPersepective.getX(), leftBottomCornerPersepective.getY(), leftTopCornerPersepective.getX(), leftTopCornerPersepective.getY());

    #endif


    // Render brake cloud if braking ..

    if (gamePlayVars.brakeCount > 0) {

        gamePlayVars.brakeCount--;

        uint8_t idx = (gamePlayVars.brakeCount / 2) % 3;

        if (gamePlayVars.brakeSide != Direction::Right)     Sprites::drawPlusMask(40, 58, Images::Dirt_Cloud_Left, idx);
        if (gamePlayVars.brakeSide != Direction::Left)      Sprites::drawPlusMask(71, 58, Images::Dirt_Cloud_Right, idx);

    }

}

void renderRoadEdge_Black(int16_t &startPos, int16_t endPos, int16_t y, bool &color) {

    while (startPos <= endPos) {
        arduboy.drawPixel(startPos, y, BLACK);
        color = !color;
        ++startPos;
    }

}

void renderRoadEdge_Dark(int16_t &startPos, int16_t endPos, int16_t y, bool &color) {

    while (startPos <= endPos) {
        arduboy.drawPixel(startPos, y, color ? WHITE : BLACK);
        color = !color;
        ++startPos;
    }

}

void renderRoadEdge_Light(int16_t &startPos, int16_t endPos, int16_t y) {

    while (startPos <= endPos) {
        arduboy.drawPixel(startPos, y, WHITE);
        ++startPos;
    }

}

void renderRoad_Black(int16_t &startPos, int16_t endPos, int16_t y, bool &color) {

    while (startPos < endPos) {
        arduboy.drawPixel(startPos, y, BLACK );
        ++startPos;
        color = !color;
    }     

}

void renderRoad_Dither_Dark(int16_t &startPos, int16_t endPos, int16_t y, bool &dither, bool &color) {

    while (startPos < endPos) {
        arduboy.drawPixel(startPos, y, dither && color ? WHITE : BLACK);
        ++startPos;
        color = !color;
    }     

}

void renderRoad_Dither_Light(int16_t &startPos, int16_t endPos, int16_t y, bool &color) {

    while (startPos < endPos) {
        arduboy.drawPixel(startPos, y, color ? BLACK : WHITE);
        ++startPos;
        color = !color;
    }     

}

void renderDayBanner() {

    uint8_t x = 0;

    if (gamePlayVars.showDayBannerCount > 0) {

        Sprites::drawExternalMask(16, 8, Images::StartOfDay, Images::StartOfDay_Mask, 0, 0);

        switch (gamePlayVars.days) {

            case 1 ... 9:
                x = 48 + 5;
                break;

            case 10 ... 99:
                x = 48 + 2;
                break;

            case 100 ... 9999:
                x = 48;
                break;

        }

        font4x6.setCursor(x, 17);
        font4x6.setTextColor(WHITE);
        font4x6.print("Day");
        font4x6.setCursor(x + 18, 17);
        font4x6.print(gamePlayVars.days);

    }

}

void renderGameOver() { // 0  to 108

    Sprites::drawPlusMask(WIDTH - gameOverVars.offset, 13, Images::GameOver_00, 0);
    Sprites::drawPlusMask(-59 + gameOverVars.offset, 37, Images::GameOver_01, 0);

}