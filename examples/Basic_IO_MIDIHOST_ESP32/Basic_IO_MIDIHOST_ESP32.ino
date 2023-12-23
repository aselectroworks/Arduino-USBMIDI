#define ESP32_USB_HOST // Need to define it before include USB-MIDI.h
#include <USB-MIDI.h>

// Simple tutorial on how to receive and send MIDI messages.
// Here, when receiving any message on channel 4, the Arduino
// will blink a led and play back a note for 1 second.

USBMIDI_CREATE_DEFAULT_INSTANCE();

void setup()
{
    Serial.begin(115200); 
    pinMode(LED_BUILTIN, OUTPUT);
    MIDI.begin(MIDI_CHANNEL_OMNI);      // Launch MIDI and listen to all channel
}

uint32_t cur_time = 0;
void loop()
{
    if (MIDI.read())                    // If we have received a message
    {
        Serial.println("MIDI IN"); 
        digitalWrite(LED_BUILTIN, HIGH);
        MIDI.sendNoteOn(42, 127, 1);    // Send a Note (pitch 42, velo 127 on channel 1)
        delay(100);		            // Wait for a second
        MIDI.sendNoteOff(42, 0, 1);     // Stop the note
        digitalWrite(LED_BUILTIN, LOW);
    }

}
