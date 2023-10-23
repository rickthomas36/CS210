#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
using namespace std;

int main() {
    //Required variables to hold city name and temperature
    string cityName;
    int fahrenheit, celcius;

    /**
        FILE OBJECT TO READ FROM FILE
    **/
    //Creating file object to read from a file
    ifstream inFile;
    //Opening the file "FahrenheitTemperature.txt' using the input file object
    inFile.open("FahrenheitTemperature.txt");

    /**
        FILE OBJECT TO WRITE TO FILE
    **/
    //Creating file object to write to a file
    ofstream outFile;
    //Opening the file "CelsiusTemperature.txt' using the output file object
    //Creates the file if the file doesn't exist
    outFile.open("CelsiusTemperature.txt");

    //Checks if input file cannot be opened
    if (!inFile) {
        cout << "File cannot be opened." << endl;
    }
    else {
        //Loops till end of the file
        //Reads city name and fahrenheit in each line of file
        while (inFile >> cityName >> fahrenheit) {
            //Converts fahrenheit temperature to celcius temperature
            celcius = (int)round(((fahrenheit - 32) * 5) / (double)9);
            //Writes the city name and celcius value to 'CelsiusTemperature.txt' file
            outFile << cityName << " " << celcius << endl;
        }
    }


    cout << "Data has been written to CelsiusTemperature.txt file successfully!" << endl;

    //Close both file objects
    inFile.close();
    outFile.close();

    return 0;
}