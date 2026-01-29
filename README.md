
# Hybrid Repository
A hybrid repository of projects for Arduino IDE and PlatformIO using a single source code file set.

HOWTO: Sharing Source Files Between Arduino IDE and PlatformIO

## Overview
The [Arduino IDE](https://www.arduino.cc/en/software/) is undeniably a valuable asset to the Arduino platform student, hobbyist and professional.  For those creating [GitHub](https://github.com/) repositories and sharing their code with others, offering the customary [Arduino IDE Sketch](https://docs.arduino.cc/learn/programming/sketches/) INO file makes their ideas and charity accessible to a majority of consumers.

But the Arduino IDE has some limitations.  Among them, a single library folder shared across all projects.  As the number of projects grow, this eventually becomes an issue where the library for one project conflict with another.

For professionals seeking stricter coding practices of industry standards, improved organization, testing, and a more robust coding experience, many choose [Visual Studio Code](https://code.visualstudio.com/) using [PlatformIO](https://platformio.org/) for development and project management.  Among its features, is a per-project library model.

This repository demonstrates how to maintain a single code set for Arduino IDE, facilitating an open source and sharing philosophy, while giving the developer access to advanced tools using PlatformIO.

The resulting projects may be opened and edited in either Arduino IDE or PlatformIO, viewed, edited, compiled, uploaded and tested while minimizing redundancy and maintaining a single code set easily shared via GitHub.

Generally, Arduino IDE makes it challenging to include files and libraries outside their default locations.  But PlatformIO makes it easy to include files from Arduino IDE sketches within its project folder.

### File Structure
```
~/GitHub/WonderWidget
+---Arduino
+---PlatformIO
+---assets
+---docs
|   LICENSE
|   README.md
```
* `Arduino/`: the Arduino sketch and source code folder.
* `Platform/`: the PlatformIO (PIO) workspace project folder.  Generally includes the source code contained in `Arduino/` with `#include` directives.
* `assets/`: Repository images and other assets.
* `docs/`: Project documentation, including datasheets.
* `LICENSE`: The project's license.
* `README.md`: This overview file.

### Creation Procedure
Given you're starting with an Arduino sketch you both want to share, and develop in PlatformIO, the procedure is as follows:
1. **[Create](https://docs.github.com/en/repositories/creating-and-managing-repositories/quickstart-for-repositories)** the hybrid [GitHub repository](https://github.com/new) you will share with the Arduino community.  For this procedure, we shall refer to the name as *WonderWidget*.
2. **[Clone](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository)** the repo to your workstation using the tool of your choice, such as [GitHub CLI](https://cli.github.com/), [GitHub Desktop](https://docs.github.com/en/desktop) to place the repo into the GitHub collection of your workstation.  For example,  `~/Documents/GitHub/WonderWidget/`
	* For the purposes of this procedure, let us condense references and refer to the repo folder as `~/repo/`
3. **Create** the `Arduino` folder inside the repo.  For example, `~/repo/Arduino`
4. Copy/Create/Save-As the desired **Arduino IDE sketch** into the `~/repo/Arduino` folder.  One must take care to name both the INO file name to match the parent project folder name, because Arduino IDE likes that.
	* to **Copy** an existing Arduino IDE project, copy the existing Arduino sketch you want to share to your repo's Arduino folder with (recommended) same name as the repo. Results in: `~/repo/Arduino/WonderWidget/WonderWidget.ino`
	* to **Create** a new sketch, select `File > New Sketch` inside Arduino IDE, then select `File > Save As` to the name: `~/repo/Arduino/WonderWidget` which results in: `~/repo/Arduino/WonderWidget/WonderWidget.ino`
	* to **Save-As** an existing Arduino IDE project, open the desired INO project in Arduino IDE, and select `File > Save As` to the name: `~/repo/Arduino/WonderWidget` which results in: `~/repo/Arduino/WonderWidget/WonderWidget.ino`
5.	**Create** the `PlatformIO` folder inside the repo.  For example, `~/repo/Platform`
6.	Create the **PlatformIO project** linking to the INO file.  
	* **Open** the [VSCode](https://code.visualstudio.com/) editor with the [PlatformIO](https://platformio.org/) extension [installed](https://docs.platformio.org/en/latest/integration/ide/vscode.html) and navigate to the PIO Home page.
	* **Create** *New Project* and specify the (recommended) same name as the repo:
		* Name: `WonderWidget`
		* Board: `Arduino Uno` or desired
		* Framework: `Arduino` or appropriate
		* Location: **important!** uncheck and choose: `~/repo/PlatformIO`
		* Click *Finish*
		* If the GIT repository in the parent folder is detected, and when asked to open it, choose Yes.
	* **Save** the workspace using `File > Save Workspace As...` and save it inside the project folder `~/repo/PlatformIO/WonderWidget/WonderWidget.code-workspace`
7. Modify the PlatformIO project to include the Arduino IDE (.ino) sketch.
	* **Modify** the `platformio.ini` settings file and add the `build_flags` directive with our relative include path (`..`) to the (.ino) sketch folder.  The content will look something like:
		```
		[env:uno]
		platform = atmelavr
		board = uno
		framework = arduino

		build_flags =
		  -I../../Arduino/WonderWidget
		```
	* Save and close the modified `platformio.ini` file.
	* **Modify** the `src/main.cpp` file and remove all its default content.  At the top, add a one-liner to include the .ino file into the build.  The content will look something like:
		```
		#include "WonderWidget.ino"
		```
	* Save the modified `main.cpp` file.
	* **Build** within PlatformIO to test.  Upload as desired.
* The .ino file can now be opened by right-clicking the `#include` file name `"WonderWidget.ino"` in `main.cpp` and selecting `Go To Definition`
* Library dependencies are resolved by loading libraries through `PIO > Libraries`

### Usage
* GitHub
	* Users may push changes to their GitHub repository, and manage the project all within the local parent GitHub repository folder.
* Arduino IDE
	* As desired, users may open their sketches using the Arduino IDE by the `.ino` file located at: `~/repo/Arduino/WonderWidget/WonderWidget.ino`
	* Libraries added through the IDE are generally added to the shared (across all projects) library folder located at `~/Documents/Arduino/libraries`
	* The sketch may be built, uploaded, tested, debugged, and so forth, just as their other Arduino projects.
* PlatformIO
	* As desired, users may open their sketches using PlatformIO by the `.code-workspace` file located at: `~/repo/PlatformIO/WonderWidget/WonderWidget.code-workspace`
		* Initially, one opens the `.ino` sketch with a right-click of the `#include` filename and a `Go To Definition`
		* Files are reopened the same as prior edit sessions. 
	* The code may be built, uploaded, tested, debugged, and so forth, just as their other PlatformIO projects.

## Change to Suit
Not every project warrants structure within a GitHub Repository.  The hybrid project can still be used to manage sketches and code projects usable by both Arduino IDE and PlatformIO.
These ideas presented here are just to get users started.  They're invited to modify things to better suit their needs.
An alternate method involves grouping projects by their IDE of choice.  
* Projects created by the Arduino IDE fall under the customary `~/Documents/Arduino` projects folder.
* Projects created by PlatformIO would fall under its customary `~/Documents/PlatformIO` projects folder.

While we cannot easily change Arduino IDE to link with files located in PlatformIO, PIO is flexible enough allowing it to link with `.ino` sketches in the Arduino projects folder.

### Alternate File Structure
```
~/Documents
+---Arduino
|		+---libraries
|		|		library_1
|		\---WonderWidget
|				WonderWidget.ino
|				some-header.h
\---PlatformIO
		+---WonderWidget
				WonderWidget.code-workspace
				platformio.ini
				+---include
				+---lib
				+---src
						main.cpp
```
* `Arduino/`: the customary Arduino IDE projects folder.  Note the shared `libraries` folder.
* `Platform/`: the customary PlatformIO (PIO) projects folder.  

### Alternate Creation Procedure
1. Follow the [Creation Procedure](#creation-procedure), above, and deviate folder locations to suit your needs.
2. Link the PlatformIO project to the Arduino IDE sketch using a more specific include path in the `platformio.ini` file.  The actual path will vary by installation.  But the content will look something like:
	```
	[env:uno]
	platform = atmelavr
	board = uno
	framework = arduino

	build_flags =
		; Windows path to the Arduino IDE Project Folder
		-I/Users/wendell/OneDrive/Documents/Arduino/WonderWidget
	```
3. The `main.cpp` file continues to be minimal.  The content will look something like:
		```
		#include "WonderWidget.ino"
		```
4. File includes in the `WonderWdiget.ino` file still work the same way, too.  This is because the build-flags provides the include path and tell PlatformIO where to look for files.
