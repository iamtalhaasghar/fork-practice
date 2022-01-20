// TALHA ASGHAR

#include<iostream>
#include<string>			
#include<fstream>

using namespace std;

void generateRandomNumbers(int, int, int, string);

int main(){
    generateRandomNumbers(1, 1000000, 10000, "numbers.txt");
}

void generateRandomNumbers(int start, int end, int total, string fileName){
    printf("Generating %d Random Numbers within range from %d to %d...\n", total, start, end);
    unsigned int randomNumbers[total];
    // seed the rand() with time(0) and convert type of "time(0)" to "unsigned int"
    srand(static_cast <unsigned int >(time(0)));
    for(int i = 0 ; i < total; i++){
        randomNumbers[i] = (rand() % end) + 1;
    }
    fstream outputFile;
	outputFile.open(fileName, ios::out);


	if (!outputFile.is_open()){
		cout << "Error in opening file!\n";
	}
	else{
        cout<<"Saving generated random numbers to "<<fileName<<"...\n";
        for(int i = 0 ; i < total; i++){
            outputFile << randomNumbers[i];
            if(i != total -1){
                outputFile << endl;
            }
        }   
	}
	outputFile.close();
    
}