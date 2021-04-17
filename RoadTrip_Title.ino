#include <Arduboy2.h>

// ----------------------------------------------------------------------------
//  Initialise state ..
//
void title_Init() {

    #ifdef SOUNDS
        sound.tones(Sounds::Theme);
    #endif
    
    cameraPos.setX(0);
    cameraPos.setY(UPM);
    cameraPos.setZ(-40);

    world.reset();
    gamePlayVars.reset();
    titleVars.reset();
    //gamePlayVars.timeOfDay = 1700;
    gameState = GameState::Title;

    #ifdef CACTII
        placeCactii();
    #endif
    
}   


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void title() {

    // Update position of text ..

    if (titleVars.flyIn && titleVars.offset < Constants::Title_MaxOffset) {

        titleVars.offset = titleVars.offset + 3;

    }

    if (!titleVars.flyIn) {

        if (titleVars.offset > 0) {
            titleVars.offset = titleVars.offset - 3;
        }
        else {

            switch (titleVars.cursor) {
        
                case 0:
                    titleVars.titleState = TitleState::SelectTransmission;
                    break;
        
                case 1:
                    gameState = GameState::HighScore_Init;
                    break;

            }

        }

    }


    draw(false);

    switch (titleVars.titleState) {

        case TitleState::StartGame:

            Sprites::drawPlusMask(WIDTH - titleVars.offset, 7, Images::RoadTrip_00, 0);
            Sprites::drawPlusMask(-69 + titleVars.offset, 35, Images::RoadTrip_01, 0);
        
            if (titleVars.offset == Constants::Title_MaxOffset) {

                if (arduboy.justPressed(A_BUTTON)) { 

                    titleVars.flyIn = false;

                }         
                
                if (arduboy.justPressed(UP_BUTTON)) { 

                    titleVars.cursor = 0;

                }

                if (arduboy.justPressed(DOWN_BUTTON)) { 

                    titleVars.cursor = 1;

                }

                arduboy.fillRect(84, 8, 44, 15, WHITE);
                arduboy.drawRect(85, 10 + (titleVars.cursor == 1 ? 7 : 0), 3, 3, BLACK);

                Sprites::drawErase(90, 9, Images::Title_Start, 0);
                Sprites::drawErase(90, 16, Images::Title_HighScore, 0);

            }

            break;

        case TitleState::SelectTransmission:

            Sprites::drawExternalMask(27, 16, Images::TransmissionType_Auto, Images::TransmissionType_Mask, 0, 0);
            Sprites::drawExternalMask(69, 16, Images::TransmissionType_Manual, Images::TransmissionType_Mask, 0, 0);

            Sprites::drawExternalMask(25 + (car.getTransmissionType() == TransmissionType::Manual ? 42 : 0), 14, Images::TransmissionType_Highlight, Images::TransmissionType_Highlight_Mask, 0, 0);

            if (arduboy.justPressed(A_BUTTON)) { 

                gameState = GameState::Game_Init;

            }         
            
            if (arduboy.justPressed(LEFT_BUTTON)) { 

                car.setTransmissionType(TransmissionType::Auto);

            }

            if (arduboy.justPressed(RIGHT_BUTTON)) { 

                car.setTransmissionType(TransmissionType::Manual);

            }

            break;

    }


    houseKeeping();

    #ifdef CACTII
        moveCactii();
    #endif
    
    cameraPos.setZ(cameraPos.getZ() + 6);
    cameraPos.setY(world.roadHeightAt(cameraPos.getZ() + 2 * UPM) + UPM);


    // Reset the time to ensure a white (day) screen ..

    gamePlayVars.timeOfDay = 700;

//Serial.println(arduboy.getLastFrameDuration());

}
