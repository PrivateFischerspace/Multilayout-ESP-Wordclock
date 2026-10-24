#pragma once

#include "DE10x11.nero.hpp"

/*
 *           Layout Front
 *                COL
 *       X 9 8 7 6 5 4 3 2 1 0
 * ROW + - - - - - - - - - - -
 *  0  | E S J I S T L F Ü N F
 *  1  | Z E H N Z W A N Z I G
 *  2  | D R E I V I E R T E L
 *  3  | T F N A C H V O R J M
 *  4  | H A L B X Z W Ö L F T
 *  5  | Z W E I N S I E B E N
 *  6  | L D R E I C I F Ü N F
 *  7  | E L F N E U N V I E R
 *  8  | U A C H T Z E H N S I
 *  9  | C S E C H S T L U H R
 */

class De10x11NeroFrame_t : public De10x11Nero_t {
public:
    virtual inline uint8_t numPixelsFrameMatrix() override { return 120; }

    //------------------------------------------------------------------------------

    virtual bool hasSecondsFrame() override { return true; }

    //------------------------------------------------------------------------------

    virtual uint8_t numPixelsMinuteMatrix() override { return 8; }

    //------------------------------------------------------------------------------

    virtual uint8_t numPixelsPerMinuteIndicator() override { return 2; }

    //------------------------------------------------------------------------------

    virtual bool hasLed7x() override { return false; }

    //------------------------------------------------------------------------------

    virtual void getMinuteArray(uint16_t *returnArr,
                                MinuteVariant variant) override {
        const uint16_t firstMinute = numPixelsWordMatrixAdjusted();
        for (uint8_t i = 0; i < 4; i++) {
            returnArr[i] = firstMinute + i * 2;
        }
    };
};

De10x11NeroFrame_t _de10x11NeroFrame;