#ifndef LIB_TP_CONTROLLER
#define LIB_TP_CONTROLLER

#include <stdint.h>
#include "addrs.h"
#include "utils.h"

namespace Controller {
    namespace Pad {
        const uint16_t DPAD_LEFT = 0x0001;
        const uint16_t DPAD_RIGHT = 0x0002;
        const uint16_t DPAD_DOWN = 0x0004;
        const uint16_t DPAD_UP = 0x0008;
        const uint16_t Z = 0x0010;
        const uint16_t R = 0x0020;
        const uint16_t L = 0x0040;
        const uint16_t A = 0x0100;
        const uint16_t B = 0x0200;
        const uint16_t X = 0x0400;
        const uint16_t Y = 0x0800;
        const uint16_t START = 0x1000;
    }  // namespace Pad

    struct PadStatus {
        uint16_t sval;
    };
    static_assert(sizeof(PadStatus) == 0x2);

    struct PadSticks {
        int8_t control_x;
        int8_t control_y;
        int8_t c_x;
        int8_t c_y;
    };
    static_assert(sizeof(PadSticks) == 0x4);

    struct PadTriggers {
        uint8_t trig_L;
        uint8_t trig_R;
    };
    static_assert(sizeof(PadTriggers) == 0x2);
    
    struct ATriggers {
        float l, r;
    };
    static_assert(sizeof(ATriggers) == 0x8);

    struct PadButton {
        uint8_t analog_cardinal;
        uint8_t c_cardinal;
        uint16_t buttons;
        uint8_t _p1[2];
        uint16_t buttons_down;
        uint8_t _p2[18];
        uint16_t sval;
        uint8_t _p3[0xA4];
    };
    static_assert(sizeof(PadButton) == 0xC0);

#define tp_mPadButton (*(Controller::PadButton *)tp_mPadButton_addr)
#define tp_mPadStatus (*(Controller::PadStatus *)tp_mPadStatus_addr)
#define tp_mPadSticks (*(Controller::PadSticks *)tp_mPadSticks_addr)
#define tp_mPadTriggers (*(Controller::PadTriggers *)tp_mPadTriggers_addr)
#define tp_mPadATriggers (*(Controller::ATriggers *)tp_mPadATriggers_addr)
#define tp_mPadAStick (*(Vec2 *)tp_mPadAStick_addr)
#define tp_mPadACStick (*(Vec2 *)tp_mPadACStick_addr)

    uint16_t buttons_down();
    uint16_t buttons_pressed();
    void set_buttons_down(uint16_t buttons);
    void set_buttons_pressed(uint16_t buttons);
    bool is_down(uint16_t buttons);
    bool is_pressed(uint16_t buttons);
}  // namespace Controller

#endif  // LIB_TP_CONTROLLER
