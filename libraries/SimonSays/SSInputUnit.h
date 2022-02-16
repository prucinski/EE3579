#ifdef COMPILE_CPP_NOT_ARDUINO
#include "..\All_Arduino_or_Cpp_symboldefines\All_Arduino_or_Cpp_symboldefines.h"
#else
#include <Arduino.h>
#endif

#include <Basic_Input.h>

class inputUnit(){
protected:
	//array of binary inputs, for each button.
	
	bool binaryInputs[5] = {false, false, false, false, false};
	in_digital digitalPins[5];
	int size;
public:
	inputUnit(int givenSize){
		size = givenSize;
	}
	void setDigitalPins(int[5] pins){
		for(int i = 0; i < size; i++){
		//initializaiton of the in_digital array.
			digitalPins[i] = new in_digital(pins[i]);
		}
	}
	void readBinaryInputs(){
		for(int i = 0; i < size; i++){
			//detection variable. Not necessary for implementation
			int detection;
			digitalPins[i].read_input(detection);
			if(detection == LOW){
				Serial.println("Button pressed at index "+ i);
				buttonInputs[i] = true;

			}

		}
	}
	void resetButtons(){
		for(int i = 0; i < size; i++){
			binaryInputs[i] = false;
		}
	}

	int returnPressedButton(){
		for(int i = 0; i < size; i++){
			if(binaryInputs[i]){
			//for now, assuming that the user will click one button at a time.
				return i;
			}
		}
		resetButtons();
	}
}

#endif