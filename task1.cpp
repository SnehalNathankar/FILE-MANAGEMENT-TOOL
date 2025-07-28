/*CREATE A C++ APPLICATION TO READ,
WRITE, AND APPEND DATA TO TEXT
FILES.(task1)*/
#include <iostream> // for input and output operations
#include <fstream>  // For file operations and reading/writing files
#include <string> // to work with strings
using namespace std;

//function write to file
void writeToFile(const string & filename,const string & data)
{
    ofstream file(filename);//opens file for witting or for write mode
    if(file.is_open())//checks the file if its open
    {
        file<<data;//writes the data to the file
        file.close();//closes the file
        cout<<"data is written to the file successfully."<<endl;
    }
    else//if file is not open
    {
       cout<<"error opening file for writting."<<endl;
       cout<<"please check the file path and try again."<<endl;
    }
}

// function to append data to file
void appendToFile(const string & filename, const string & data)
{
    ofstream file(filename, ios::app); // opens file in append mode
    if(file.is_open())
    {
        file<<data;
        file.close();
        cout<<"data appended to the file successfully."<<endl;
    }
    else{
        cout<<"error opening file for appending,"<<endl;
        cout<<"please check the file path and try again."<<endl;
    }
}

// function to read data from file
void readFromFile(const string & filename)
{
    ifstream file(filename);//opens the file for reading
    if(file.is_open())
    {
        cout<<"\n--- file contents ---\n";
        string line;
        while(getline(file,line))//reads the file line by line
        {
            cout<<line<<endl;//prints each line
            //add a new line for better readability
            cout<<endl;
        }
        file.close();//closes file after reading all contents
        cout<<"file read successfully."<<endl;
        cout<<"---end of file contetents---"<<endl;
        }
else
{
    cout<<"error opening file for reading."<<endl;
    cout<<"please check the file path and try again."<<endl;
    cout<<"---end of file contents---"<<endl;
}
}
//main function with menu
int main()
{
    string filename,data;
    int choice;
    cout<<"enter the file name(with e.g,data.txt,task1.txt): "<<endl;
    cin>>filename; // takes the file name from user
    do{
    cout<<"choose an option:\n";
    cout<<"1.write to file\n";
    cout<<"2.append to file\n";
    cout<<"3.read from file\n";
    cout<<"4.exit\n";
    cout<<"enter your choice:";
    cin>>choice;//tasks user to enter choice
    switch (choice)
    {
        case 1:
        cout<<"enter text to write to file:";
        data="";
        while(true)
        {
            string line;
            getline(cin,line);
            if (line == "END") break;
            data += line +"\n";
        }
        writeToFile(filename,data);
        break;

        case 2:
        cout<<"enter text to append to file:";
        data="";
        while(true)
        {
            string line;
            getline(cin,line);
            if (line == "END") break;
            data += line +"\n";
        }
        appendToFile(filename, data);
        break;

        case 3:
        readFromFile(filename);
        break;
        case 4:
        cout<<"existing program. Thank you!"<<endl;
        break;
        default:
        cout<<"invalid choice. Please try again."<<endl;
    }
}while(choice != 4); // loop until user chooses to exit
return 0;
}

// End of file
// This code is a simple C++ application that allows users to read, write, and append data to text files.


