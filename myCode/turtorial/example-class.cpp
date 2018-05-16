#include <iostream>
using namespace std;

// ---------- "Introduction to Classes" ----------
class Lamp {
public:
    // methods
    Lamp() {			// default constructor
	max_brightness = 0;
	switched_on = false;
    }
    
    Lamp(int brightness_rating) { // constructor
	max_brightness = brightness_rating;
	switched_on = false;
    }

    void switch_on() {
	if (!switched_on) {
	    switched_on = true;
	    brightness = max_brightness;
	}
    }

    void switch_off() {
	if (switched_on) {
	    switched_on = false;
	    brightness = 0;
	}
    }

    void dim(int percentage) {
	if (switched_on && (percentage >= 0 && percentage <= 100))
	    brightness = max_brightness * percentage / 100;
    }

    int set_max_brightness(int brightness_rating) {
	// maybe we changed light bulb
	if (!switched_on)
	    max_brightness = brightness_rating;
    }

    int get_max_brightness() {
	return max_brightness;
    }

    int get_current_brightness() {
	return brightness;
    }
     
    ~Lamp() {			// destructor
	switch_off();
    }

private:
    // data members
    int max_brightness;
    bool switched_on;
    int brightness;
};
// ---------- "Introduction to Classes" ----------


// ------------ "Instantiate a Class" ------------
int main()
{
    Lamp dim_lamp(60);		// call constructor
    Lamp bright_lamp;		// call default constructor
    bright_lamp.set_max_brightness(1000);

    cout << "Max brightness for a dim lamp: " << dim_lamp.get_max_brightness() << endl;
    cout << "Max brightness for a bright lamp: " << bright_lamp.get_max_brightness() << endl;

    cout << "Switching on the dim lamp..." << endl;
    dim_lamp.switch_on();
    cout << "Current brightness for the dim lamp: " << dim_lamp.get_current_brightness() << endl;
    cout << "Current brightness for the bright lamp: " << bright_lamp.get_current_brightness() << endl;

    cout << "Adjust brightness to 50%..." << endl;
    dim_lamp.dim(50);
    bright_lamp.dim(50);
    cout << "Current brightness for the dim lamp: " << dim_lamp.get_current_brightness() << endl;
    cout << "Current brightness for the bright lamp: " << bright_lamp.get_current_brightness() << endl;
    
    return 0;
    // at the end of program, destructor is automatically called
}
// ------------ "Instantiate a Class" ------------
