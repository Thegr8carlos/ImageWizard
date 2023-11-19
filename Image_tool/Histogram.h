#pragma once
class Histogram
{
public:
	Histogram(long int max, long int* fr, long int* fg, long int* fb);
	// For deleting a SELECTED histogram
	// Check an event for a currently selected histogram
	~Histogram ();
	void display ();
private:
	long int max_frec = 0;
	long int* frec_r = nullptr;
	long int* frec_g = nullptr;
	long int* frec_b = nullptr;
};

