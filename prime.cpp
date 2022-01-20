// TALHA ASGHAR

#include<iostream>
#include<string>			
#include<fstream>
#include<math.h>
#include<unistd.h>
#include<iomanip>
#include<time.h>

using namespace std;

bool isPrime(int);
int getLineCount(string);
void findPrimes(int[], int, int);
void removePreviousPrimeNumbers();

int main(int argc, char** argv){
    
    int numJobs = 8;

    removePreviousPrimeNumbers();

    int lines = getLineCount("numbers.txt");
    int randomNumbers[lines];
    
    // read numbers.txt into an array
    fstream inputFile;
    inputFile.open("numbers.txt", ios::in);
	if (!(inputFile.is_open())){
		cout << "Error in opening file!\n";
	}
    else{
        int num=0, i = 0;	
		while (!inputFile.eof())		
		{
			inputFile >> randomNumbers[i++] ;
		}
	}
    inputFile.close();


    cout<<"Creating "<<numJobs<<" jobs in parallel.\n";

    // create forks and divide the array for each thread and let it find prime numbers
    int pid;
    clock_t clockTime;
    cout<<"Job #"<<setw(5)<<"|pid"<<setw(15)<<"|First Index"<<setw(15)<<"|Last Index"<<setw(15)<<"|Time Taken (s)"<<endl;
    for(int i = 0; i < numJobs; i++){    
        pid = fork();
        if(pid != 0){
            clockTime = clock();
            // divide array and assign some part of it to this thread
            int firstIndex = floor((lines * i) / numJobs);
            int lastIndex = ((lines * (i+1)) / numJobs);
            // let this thread find prime numbers in this portion of array
            findPrimes(randomNumbers, firstIndex, lastIndex);
            clockTime = clock()-clockTime;
            cout<<i+1<<setw(10)<<pid<<setw(15)<<firstIndex<<setw(15)<<lastIndex<<setw(15)<<((float)clockTime)/CLOCKS_PER_SEC<<endl;
            fflush(stdin);

       }
       else{
           return 0;
       }
    }

}


bool isPrime(int number){

	//https://github.com/iamtalhaasghar/deitel-cpp-how-to-program/blob/master/Chapter%236/6.29-Prime%20Numbers.cpp

	for(int i=2; i<=sqrt(number); i++){
		if(number % i == 0){
			return false;
		}
	}
	return true;
}



int getLineCount(string fileName){
     
    fstream inputFile;
	inputFile.open(fileName, ios::in);

    int lines = 0;
	if (!inputFile.is_open()){
		cout << "Error in opening file!\n";
	}
	else{
        string temp;
       while (!inputFile.eof())		
		{
            inputFile >> temp;
			lines++;
		}	
	}
	inputFile.close();
    return lines;
}

void findPrimes(int numbers[], int start, int end){
    fstream outputFile;
    outputFile.open("prime.txt", ios::app);
	if (!(outputFile.is_open())){
		cout << "Error in opening file!\n";
	}
    else{
        for(int i = start; i < end; i++){
         if (isPrime(numbers[i])){
            outputFile<<numbers[i]<<endl;
         }
        }
	
	}

    outputFile.close();
}
void removePreviousPrimeNumbers(){
    fstream outputFile;
    outputFile.open("prime.txt", ios::out);
	if (!(outputFile.is_open())){
		cout << "Error in opening file!\n";
	}
    else{        
        outputFile<<"";        
	}
    outputFile.close();
}