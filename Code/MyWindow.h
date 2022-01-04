#pragma once
#include "std_lib_facilities.h"
#include "Graph.h"
#include "GUI.h"
#include "Sort.h"
#include "CommandArgs.h"

using namespace Graph_lib;


class MyWindow : public Window

{

public:
	MyWindow(Point xy, int w, int h, const string& title);

	//setting start arguments
	//void setArguments(CommandArgs &ca);
	//collecting data
	//void collectdata();
	bool wait_for_button(); // simple event loop
	bool button_pushed;     // implementation detail
	void second_window(MyWindow *win);

	void Gather(MyWindow *win);
	void detachTexts();
	void MyWindow::setArguments(CommandArgs &ca);
	
private:
	//Data collector. 
	DataCollector datacollector;
	//Flights read from input file.
	vector<Flight> allflights;
	string display_from_vector();
	int current_iteration;
	Button button_exit;
	Button button_ok;
	Button button_nextStep;

	In_box inputFile;
	In_box outputFile;
	In_box sortType;
	In_box sortCrit;
	vector<Text *> texts;

	void exit();
	void ok();
	void nextStep();
	
	static void nextStep_click(Address, Address window);
	static void exit_click(Address, Address window);
	static void ok_click(Address, Address window);
};
