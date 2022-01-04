#include "MyWindow.h"
#include "Flight.h"
#include "FileHandler.h"
#include "Window.h"

MyWindow::MyWindow(Point xy, int w, int h, const string& title)
	: Window(xy, w, h, title),

	button_exit(Point(220, 250), 70, 20, "QUIT", exit_click),
	button_ok(Point(130, 250), 70, 20, "OK", ok_click),
	button_nextStep(Point(130, 250), 70, 20, "NextStep", nextStep_click),
	inputFile(Point(160, 120), 200, 20, "Input File location:"),
	outputFile(Point(160, 150), 200, 20, "Output File location:"),
	sortType(Point(130, 30), 20, 20, "1.Merge Sort\n 2.Selection Sort\n"),
	sortCrit(Point(300, 30), 20, 20, "Sort by:\n1.Destination\n 2.Departure\n 3.FlightNo \n 4.GateNo")
	
{
	attach(inputFile);
	attach(outputFile);
	attach(sortCrit);
	attach(sortType);
	attach(button_ok);
	attach(button_exit);
	attach(button_nextStep);
	button_nextStep.hide();
	this->color(Color::green);
	current_iteration = 1;
}

bool MyWindow::wait_for_button()
{
	return false;
}

void MyWindow::exit()
{
	hide();
}

void MyWindow::exit_click(Address, Address pw)
{
	reference_to<MyWindow>(pw).exit();
}

void MyWindow::nextStep()
{
	if (current_iteration <= 8) {
		display_from_vector();
		current_iteration++;
		redraw();
	}
	else {
		cout << "END of Sort";
		
	}	
}

void MyWindow::nextStep_click(Address, Address window)
{
	reference_to<MyWindow>(window).nextStep();
}

void MyWindow::ok()
{

	
	hide();
		
	MyWindow *win = new MyWindow(Point(100, 100), 400, 300, "Sorting Flights");

	Gather(win);
	second_window(win);
	win->wait_for_button();
	
}
void MyWindow::ok_click(Address, Address window)
{
	reference_to<MyWindow>(window).ok();
}

void MyWindow::second_window(MyWindow *win)
{
	win->button_ok.hide();
	win->inputFile.hide();
	win->outputFile.hide();
	win->sortCrit.hide();
	win->sortType.hide();
	win->resize(400, 600);
	win->color(Color::green);
	Table *t = new Table(Point(10, 85), 150, 40, 10);
	win->attach(*t);
	win->button_nextStep.show();	

}

void MyWindow::Gather(MyWindow *win) {

	FileHandler filehandler;
	SelectionSort selectionsort;
	MergeSort mergesort;


	string inputpath = inputFile.get_string();
	string outputpath = outputFile.get_string();
	filehandler.setInputFile(inputpath);
	filehandler.load();

	vector<Flight> allFlights;

	allFlights = filehandler.getFlights();
	//cout << "num:" << allFlights.size();

	int sort_choice = sortType.get_int();
	int choice = sortCrit.get_int();

	if (sort_choice = 1) {
		selectionsort.sort(allFlights, win->datacollector,choice);
	}
	else if(sort_choice = 2)
		mergesort.sort(allFlights, win->datacollector,choice);
	else {
		cout << "Wrong input!";
	}
}

string MyWindow::display_from_vector()
{
	//cout << datacollector.flight_iterations.size();
	//cout << current_iteration;
	detachTexts();
	texts.clear();
	for (int i = 0; i <= datacollector.flight_iterations[current_iteration].size()-1;  i++) {
		Text *t = new Text(Point(15, 80 + (i + 1) * 40), datacollector.flight_iterations[current_iteration ][i].getDestination());
		attach(*t);
		texts.push_back(t);

	}
	redraw();
	return string();
}


void MyWindow::detachTexts()
{
	for (Text *t : texts) {
		detach(*t);
		delete(t);
	}
}

void MyWindow::setArguments(CommandArgs &ca) {

	this->inputFile.put(ca.inputfile);
	this->outputFile.put(ca.outputfile);
	this->sortType.put(to_string(ca.sortType));
	this->sortCrit.put(to_string(ca.sortCrit));

}

