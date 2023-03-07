#include <iostream>
#include <string>
#include <sstream>
using namespace std;


string shiftByOneByte(string text) {
    //right shift function
    //put the first element at the end
	return text.substr(1) + text[0];
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
    string plainText;
    string key;
    int round;
    string CipherText = "";
    
    cout << "Plain Text: ";
    cin >> plainText;
    cout << "Key: ";
    cin >> key;
	cout<<"Please, enter how many round: ";
	cin >> round;
	
	//divid the plain text to halve 
    string left = plainText.substr(0, (plainText.length()/2));
    string right = plainText.substr((plainText.length()/2));
    
    //Times of calling the functions depand on number of round 
    for (int i = 0; i < round; i++) {
        string temp = right; //store the right part because Feistel's keep it as it is
        right = shiftByOneByte(xorf(left, key, (plainText.length()/2))); //fisrt calls XORFunction(left part, key, the halve size of the plain text as integer) 
								//second calls shiftByOneByte function take (left) ignore the reast	
		left = temp; // put the orginal right part into the left part
    	
    	CipherText = left + right; //concatenation
    	
    	// in case of there is more than one round, we need to implement divid process on the new one
    	left = CipherText.substr(0, (CipherText.length()/2));
    	right = CipherText.substr((CipherText.length()/2));
	}
	
	
    cout << "Encrypted Text: " << CipherText << endl;

    return 0;
}
