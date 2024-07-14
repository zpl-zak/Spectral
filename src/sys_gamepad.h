static
unsigned gamepad_update(GAMEPAD_DEVICE dev, float rumbleA, float rumbleB) {

    if (!GamepadIsConnected(dev)) {
        return 0;
    }

    GamepadSetRumble(dev, rumbleA, rumbleB); // 0.25f, 0.25f);

#if 0
    for(int i = 0; i < BUTTON_COUNT; ++i)
        printf("%d", GamepadButtonDown(dev, i));
    printf("\n");
#endif

    unsigned U = !!GamepadButtonDown(dev, BUTTON_DPAD_UP);
    unsigned D = !!GamepadButtonDown(dev, BUTTON_DPAD_DOWN);
    unsigned L = !!GamepadButtonDown(dev, BUTTON_DPAD_LEFT);
    unsigned R = !!GamepadButtonDown(dev, BUTTON_DPAD_RIGHT);

    unsigned A = !!GamepadButtonDown(dev, BUTTON_A);
    unsigned B = !!GamepadButtonDown(dev, BUTTON_B);
    unsigned X = !!GamepadButtonDown(dev, BUTTON_X);
    unsigned Y = !!GamepadButtonDown(dev, BUTTON_Y);
#if 0
    unsigned Bk= !!GamepadButtonDown(dev, BUTTON_BACK);
    unsigned St= !!GamepadButtonDown(dev, BUTTON_START);

    unsigned LB = !!GamepadButtonDown(dev, BUTTON_LEFT_SHOULDER);
    unsigned RB = !!GamepadButtonDown(dev, BUTTON_RIGHT_SHOULDER);
    unsigned LS = !!GamepadButtonDown(dev, BUTTON_LEFT_THUMB);
    unsigned RS = !!GamepadButtonDown(dev, BUTTON_RIGHT_THUMB);

    float lx, ly, rx, ry;
    GamepadStickNormXY(dev, STICK_LEFT, &lx, &ly);
    GamepadStickNormXY(dev, STICK_RIGHT, &rx, &ry);
        GamepadStickAngle(dev, STICK_LEFT);
        GamepadStickLength(dev, STICK_LEFT);
        GamepadStickAngle(dev, STICK_RIGHT);
        GamepadStickLength(dev, STICK_RIGHT);

    float LT = GamepadTriggerLength(dev, TRIGGER_LEFT);
    float RT = GamepadTriggerLength(dev, TRIGGER_RIGHT));

                for (j = 0; j != BUTTON_COUNT; ++j) {
                    if (GamepadButtonTriggered(i, j)) {
                        printf("[%d] button triggered: %s", i, button_names[j]);
                    } else if (GamepadButtonReleased(i, j)) {
                        printf("[%d] button released:  %s", i, button_names[j]);
                    }
                }
                for (j = 0; j != TRIGGER_COUNT; ++j) {
                    if (GamepadTriggerTriggered(i, j)) {
                        printf("[%d] trigger pressed:  %d", i, j);
                    } else if (GamepadTriggerReleased(i, j)) {
                        printf("[%d] trigger released: %d", i, j);
                    }
                }
                for (j = 0; j != STICK_COUNT; ++j) {
                    for (k = 0; k != STICKDIR_COUNT; ++k) {
                        if (GamepadStickDirTriggered(i, j, k)) {
                            printf("[%d] stick direction:  %d -> %d", i, j, k);
                        }
                    }
                }
#endif

    unsigned F = A || B || X || Y;
    return F<<4|R<<3|L<<2|D<<1|U<<0;
}

unsigned gamepad() {
    do_once GamepadInit();
    GamepadUpdate();

    unsigned pad0 = gamepad_update(GAMEPAD_0, 0, 0);
#if 0
    unsigned pad1 = gamepad_update(GAMEPAD_1, 0, 0);
    unsigned pad2 = gamepad_update(GAMEPAD_2, 0, 0);
    unsigned pad3 = gamepad_update(GAMEPAD_3, 0, 0);
#endif

    return pad0;
}
