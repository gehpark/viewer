#include <QtGui>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "window.h"

// export DYLD_LIBRARY_PATH="/Volumes/Macintosh HD/Applications/MATLAB_R2012a.app/bin/maci64/"

#include "/Volumes/Macintosh HD/Applications/MATLAB_R2012a.app/extern/include/engine.h"

int main(int argv, char **args)
{	
    srand(1);
	QApplication app(argv, args);


	app.setApplicationName("Random Walk");
	MainWindow window;
	window.createStatusBar();
   	window.show();
   	if (argv != 1 && !window.isMovingParticlesq())
	{
		window.run_batch(args);
	}

	return app.exec();
}
