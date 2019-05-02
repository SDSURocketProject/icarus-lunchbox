Icarus Lunch Box Code

After a long year, the Lunch Box has finally been pulled out of the closet and is used for testing

How to operate
1. Download Termite Terminal Emulator
2. Upload code to the arudino
3. Create a .txt file naming it what you want
4. In Termite go to settings, then double click "log file" in the bottom right corner
5. Find the new .txt file you just created and open it after you double clicked "log file"
6. Click the connect button on termite to connect to the arduino
	*Make sure you are not uploading to the arduino when doing this*
	*Make sure you are connected to the correct COM port*
7. Everything that is displayed on the terminal will be logged onto the .txt file
8. You can use the python graphing software to plot data points, all you have to do is change 
	timestamp, temperature, load, chamber = np.loadtxt('data.txt', delimiter=',', unpack= True)
	change the "data.txt" to whatever you named your .txt file