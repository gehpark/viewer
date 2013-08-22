#include <QtGui>
#include "window.h"


#include "/Volumes/Macintosh HD/Applications/MATLAB_R2012a.app/extern/include/engine.h"
//#include "/Volumes/Macintosh\ HD/Applications/MATLAB_R2012a.app/bin/maci64/"
//-L
//#

int main(int argv, char **args)
{	
    srand(1);
	QApplication app(argv, args);

	app.setApplicationName("Random Walk");
	MainWindow window1;
	window1.createStatusBar();
   	window1.show();

	Engine *ep;
	if (!(ep = engOpen(""))) 
	{
		fprintf(stderr, "\nCan't start MATLAB engine\n");
		return EXIT_FAILURE;
	}
	engEvalString(ep, stringHistogram);
	engEvalString(ep, stringHeatMap);
	engEvalString(ep, stringRadius);
	
	return app.exec();
}
