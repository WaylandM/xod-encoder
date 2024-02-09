// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/PaulStoffregen/Encoder"

// User optimized interrupt code
#define ENCODER_OPTIMIZE_INTERRUPTS

//Include C++ libraries
#include <Encoder.h>

node {
    meta {
        // Define our custom type as a pointer on the class instance.
        using Type = Encoder*;
    }
    
    static_assert(isValidDigitalPort(constant_input_P1), "must be a valid digital port");
    static_assert(isValidDigitalPort(constant_input_P2), "must be a valid digitial port");

    Encoder enc = Encoder(constant_input_P1, constant_input_P2);

    void evaluate(Context ctx) {

        if (isInputDirty<input_Read>(ctx)) {
            emitValue<output_Pos>(ctx, enc.read());
            emitValue<output_Done>(ctx, 1);
        }
    }
}
