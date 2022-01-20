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
	
	}			// end of else`s body 

    outputFile.close();


}