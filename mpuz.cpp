#include <iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<sstream>
#include<vector>

char letter = {'Y'};
char answer = {'n'};
char letters[]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
int  nums[18];
int unums[10];
char newletters[10];
char mult1a[3];
int mult1, mult2, prod1, prod2, prodsum, i, j, pick, hit, value, uniq, cand, stored, solved, plac;

void display(){
	// print some blank lines to create some space
	for(i=0;i<6;i++){
		std::cout << "\n";
	}
	
	// print letters -- comment out for true puzzle 
	std::cout << "\n\t";
	for(i=0;i<10;i++){
	std::cout << letters[i] << " ";
	}
	
	// print number scale -- comment out for true puzzle 
	std::cout << "\n\t";
	std::cout << "0|1|2|3|4|5|6|7|8|9|\n";
	
	// print unums
	std::cout << "\n\t";
	for(i = 0;i<(stored-solved);i++){
		std::cout << unums[i] << " ";
	}
	std::cout << "\n\tSolved " << solved << " of " << stored;

	// mult1
	std::cout << "\n\n\t\t  " << letters[(mult1/100)%10] << " ";
	std::cout << letters[(mult1/10)%10] << " ";
	std::cout << letters[mult1%10] << "\n";
	
	// mult2
	std::cout << "\t\tx   " << letters[(mult2/10)%10] << " ";
	std::cout << letters[mult2%10] << "\n";

	// line 1
	std::cout << "\t\t_______\n";
	
	// prod1
	std::cout << "\t\t" << letters[(prod1/1000)%10] << " ";
	std::cout << letters[(prod1/100)%10] << " ";
	std::cout << letters[(prod1/10)%10] << " ";
	std::cout << letters[prod1%10] << "\n";
	
	// prod2
	std::cout << "\t      " << letters[(prod2/1000)%10] << " ";
	std::cout << letters[(prod2/100)%10] << " ";
	std::cout << letters[(prod2/10)%10] << " ";
	std::cout << letters[prod2%10] << "\n";
	
	// line 2
	std::cout << "\t      _________\n";
	
	// prodsum
	std::cout << "\t      " << letters[(prodsum/10000)%10] << " ";
	std::cout << letters[(prodsum/1000)%10] << " ";
	std::cout << letters[(prodsum/100)%10] << " ";
	std::cout << letters[(prodsum/10)%10] << " ";
	std::cout << letters[prodsum%10] << "\n\n";
}// end of void display()

int main(){
	// genereate numbers for the puzzle
	srand(time(NULL));

	mult1 = 100 + std::rand() % 899;
	mult2 = 10 + std::rand() % 89;
	prod1 = mult1*(mult2%10);
	prod2 = mult1*(mult2/10);
	prodsum = prod1 + prod2*10;
 	

	// put digits into nums array
	nums[0] = (mult1/100)%10;
	nums[1] = (mult1/10)%10;
	nums[2] = mult1%10;

	nums[3] = (mult2/10)%10;
	nums[4]  = mult2%10;

	nums[5] = (prod1/1000)%10;
	nums[6] = (prod1/100)%10;
	nums[7] = (prod1/10)%10;
	nums[8] = prod1%10;

	nums[9] = (prod2/1000)%10;
	nums[10] = (prod2/100)%10;
	nums[11] = (prod2/10)%10;
	nums[12] = prod2%10;

	nums[13] = (prodsum/10000)%10;
	nums[14] = (prodsum/1000)%10;
	nums[15] = (prodsum/100)%10;
	nums[16] = (prodsum/10)%10;
	nums[17] = prodsum%10;

	// store unique digits in unums array
	unums[0] = nums[0];// first one is a sure thing
	stored = 1;
	hit = 0;
	for(i = 0; i < 18; i++){
		hit = 0;
		for(j = 0; j < stored; j++){
			if(nums[i] == unums[j]){hit++;}
		}
		if(hit == 0){
			unums[stored] = nums[i];
			stored++;
		}
	}


	i = 0;
	while(i < 10){
		pick = std::rand() % 10;
	// shuffling letters to newletters and back
		hit = 0;
		for(j=0;j<10;j++){
			if(newletters[j] == letters[pick]){hit++;}
		}
		if(hit == 0){
			newletters[i] = letters[pick];
			i++;
		}
	}
	for(i = 0; i < 10; i++){
		letters[i]=newletters[i];
		newletters[i] = '-';
	}

	
	solved = 0;
	while(solved < stored){// this loop runs until every unique number is placed
		display();

		// get letter from user
		std::cout << "\tLetter(A..J) ? ";
		std::cin >> letter;
		if(int(letter) < 65 || int(letter) > 74){return(0);}//letter out of range
		std::cout << "\tOkay .. " << letter << " is what number?(0-9) ";

		// get value from user
		std::cin >> value;
		if(value < 0 || value > 9){return(0);}//value out of range
		std::cout << "\tChecking the " << letter << " / " << value << " combination ...\n";
		
		// evaluate value/letter combination
		if(letters[value] == letter){
			std::cout << "\tYou are right!\t";
			letters[value] = value+48;
			solved++;
			for(i=0;i<(stored-solved);i++){
				if(unums[i] == value){		/*if(letters[value] == letter){*/
			// find value in unums
			// end of find loop
			// for(i = plac; i< (stored-solved); i++){unums[i] = unums[i+1];}// end of replace loop
			// unums[plac] = unums[plac+1];
			// auto end = std::remove(unums, unums + store, vjalue);
			// }//end of delete loop
		//end of find loop
		//end of if evaluate
		//end of else evaluate

				plac = i;
				std::cout << "plac is " << plac;
				}
			}for(j=plac;j<(stored);j++){unums[j] = unums[j+1];}
		
		}
		else{
		std::cout << "\tNope, try again!\t";}

}
display();
std::cout << "\n\n\t\tYou did it!\n\n";
} 

