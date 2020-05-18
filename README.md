# KE-Final-Project-Graphics

Virtual Piano

Team Members: Kwasi Efah

References:

irrKlang Documentation Author: Nikolaus Gebhardt Date: 2003 - 2018 Site: https://www.ambiera.com/irrklang/docu/index.html

Real Piano Key Sounds Author: TEDAGame Date: Nov. 20, 2018 Site: https://freesound.org/people/TEDAgame/packs/25405/

Installations/downloads:

irrKlang
OpenGL/glut
(PROGRAM ONLY TESTED ON WINDOWS)

Setup PC:

To install irrKlang:

follow this link: https://www.ambiera.com/irrklang/downloads.html

Click on irrKlang-32bit-1.6.0.zip or latest version to download

Unzip the folder

Add an 'irrklang' folder in this directory: C:/Program Files/Common Files/irrklang/

Copy the include/ and lib/ folders from irrKlang-1.6.0 into that irrklang/ folder.

Add irrKlang.dll, ikpMP3.dll, and ikpFlac.dll from irrKlang-1.6.0/bin/win32-gcc to the Clion cmake-build-debug/ folder

To install openGL/glut:

Unzip/extract the freeglut zip file.

Add a freeglut folder in this directory: C:/Program Files/Common Files/freeglut/

Copy the include/ and lib/ folders from freeglut into that freeglut/ folder.

Add freeglut.dll from freeglut/bin/ to the cmake-build-debug/ folder.

Program is ready to run.

Summary:

This program is a virtual simulation of a piano. It begins with a welcome screen and then the user may click 'p' to move onto the main screen. It only includes the 12 middle keys of a piano. The notes that the virtual piano plays are from a real piano and was downloaded as .ogg files. These sounds are played using the irrKlang library whenever a specific key is pressed. Polymorphism is used within the Key draw() method.

Known bugs:

Some combinations of three or more normal keys and sharp keys are not responsive when pressed simultaneously.
