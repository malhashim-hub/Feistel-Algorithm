#include <iostream>
#include <string>
#include <sstream>
using namespace std;


string DeShiftByOneByte(string text) {
    //left shift function
    //put the last element at the beginning
	return text[(text.length()-1)] + text.substr(0,(text.length()-1));
}

string xorf(string text, string key, int len) {
    string concat = "";
    int textn, keyn, resultn; //Numerical
    stringstream constr; //for CONverting to STRing
    
for(int j=key.length(); key.length()<len; j++)//only in case of the key length is less than the length of the left part 
    key= key + key; // then key concatants itself, until key length is equal or greater than the left part
    
    for (int i = 0; i < len; i++) {
    	
    	stringstream conint; //for CONverting to INTeger
		conint<<text[i]; //we give text[i] char to conint
    	conint>>textn; //Convert to int and store it as numerical
    	
    	stringstream conint2; //same as above for the key 
    	conint2<<key[i];
    	conint2>>keyn;
    	
    	
		resultn = (textn ^ keyn ); //XOR 
		
		constr <<resultn; //Convert from int to string
		string temp = constr.str(); //convert and stroe
		concat = temp;
	}
    return concat;
}

int main() {
    string CipherText;
    string key;
    int round;
    string PlainText = "";
    
    cout << "Cipher Text: ";
    cin >> CipherText;
    cout << "Key: ";
    cin >> key;
	cout << "Please, enter how many round: ";
	cin >> round;
	
	//divid the cipher text to halve 
    string left = CipherText.substr(0, (CipherText.length()/2));
    string right = CipherText.substr((CipherText.length()/2));
    
    //calling the function depand on number of round 
    for (int i = 0; i < round; i++) {    	
        string temp = left; //store the left part 
        left = DeShiftByOneByte(xorf(right, key, (CipherText.length()/2))); //fisrt calls XORFunction(right part, key, the halve size of the cipher text as integer) 
								//second calls shiftByOneByte function take (right) ignore the reast	
		right = temp; // put the orginal left part into the right part
    	PlainText = left + right; //concatenation
    	
    	// in case of there is more than one round, we need to implement divid process on the new one
    	left = PlainText.substr(0, (PlainText.length()/2));
    	right = PlainText.substr((PlainText.length()/2));
	}
				
    cout << "Decrypted Text: " << PlainText << endl;

    return 0;
}
