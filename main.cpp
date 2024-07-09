#include "mbed.h"

// Button input PC_13
InterruptIn button(PC_13);

// Printf handle
EventQueue queue;

// Number of button presses
volatile int button_press_count = 0;

// Interrupt button press
void button_pressed() {
    button_press_count++;  // Button press count
    queue.call(printf, "Button pressed %d times\n", button_press_count);  // Print count
}

int main() {
    // Button initialise
    button.mode(PullUp);
    
    // Falling edge button press
    button.fall(&button_pressed);
    
    // Dispatch EventQueue 
    queue.dispatch_forever();
    
    // Keep the program running
    while (true) {
        // Wait for button presses
        ThisThread::sleep_for(1000);  // Sleep 
    }
}