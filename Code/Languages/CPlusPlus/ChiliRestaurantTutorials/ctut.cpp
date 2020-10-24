/*
    Kevin Tran
    C++ Programming Tutorial

    Compile:
      g++ -std=c++11 ctut.cpp

    Run:
      On Windows:
        a
      On Linux:
        ./a.out
*/

// Note that we don't need to specify '.h'
#include <iostream> // cout
#include <vector>
#include <string>
#include <fstream>

using namespace std; // to avoid typing out std::cout every time

// Function (default values have to come last)
int addNumbers(int firstNum, int secondNum = 0) {
    int combinedValue = firstNum + secondNum;
    return combinedValue;
}

// Function overloading
int addNumbers(int firstNum, int secondNum, int thirdNum) {
    return firstNum + secondNum + thirdNum;
}

// Classes
class Animal {
    // Attributes: Height Weight variables
    // Capabilities: Run Eat functions / methods

// Encapsulation
private:
    int height;
    int weight;
    string name;

    // This variable's value is going to be shared by every object of type animal that will ever be created.
    static int numOfAnimals;

// Access methods that access the values inside of private variables
public:
    // Return the height of the animal object.
    int getHeight() {
        return height;
    }

    // Return the weight of the animal object.
    int getWeight() {
        return weight;
    }

    // Return the name.
    string getName() {
        return name;
    }

    // Set the height.
    void setHeight(int cm) {
        height = cm;
    }

    // Set the weight.
    void setWeight(int kg) {
        weight = kg;
    }

    // Set the name.
    void setName(string animalName) {
        name = animalName;
    }

    // Declare a prototype.
    void setAll(int , int, string);

    // Whenever an object is created.
    Animal(int, int, string);

    // Destructure
    ~Animal();

    // Overload a constructor with empty constructor.
    Animal();

    // Since our variable is static
    static int getNumOfAnimals() {
        return numOfAnimals;
    }

    void toString();
};

// Our static number of animals
int Animal::numOfAnimals = 0;

// Define setAll from the prototype
void Animal::setAll(int height, int weight, string name) {
    // Refer to a specific animal object's height.
    // Substitute for cm, kg, etc.
    this -> height = height;
    this -> weight = weight;
    this -> name = name;
    Animal::numOfAnimals++;
}

// Constructor definition
// Happens to do everything our setAll() method does
Animal::Animal(int height, int weight, string name) {
    this -> height = height;
    this -> weight = weight;
    this -> name = name;
    Animal::numOfAnimals++;
}

// Deconstructor
Animal::~Animal() {
    cout << "Animal " << this-> name << " destroyed" << endl;
}

// Constructor without arguments
Animal::Animal() {
    cout << this -> name << " is " << this -> height <<
        " cms talls and " << this -> weight << " kgs in weight" << endl;
}

// Inherit from Animal
class Mouse : public Animal {
private:
    string sound = "Squeak";

public:
    void getSound() {
        cout << sound << endl;
    }

    // Constructor
    Mouse(int, int, string, string);

    // Declare a default constructor, and on top of that call, a default superclass destructor
    Mouse() : Animal(){};

    // Overwrite toString() since we're printing the sound too.
    void toString();
};

// Define the constructor for our Mouse
// Reference the Animal class for the Animal constructor to handle the height, weight, and name
// But for this constructor, handle the sound
Mouse::Mouse(int height, int weight, string name, string squeak) :
Animal(height, weight, name) {
    this -> sound = squeak;
}

// Since the variables are private in the other class, we have to use the getters.
void Mouse::toString() {
    cout << this -> getName() << " is " << this -> getHeight() <<
    " cms tall and " << this -> getWeight() << " kgs in weight and says " <<
    this -> sound;
}

// Recursive function
int getFactorial(int number) {
    int sum;
    if (number == 1) sum = 1;
    else sum = getFactorial(number - 1) * number;
    return sum;
}

int main(void) {
//    // Outputs the text shown below and a carriage return.
//    // endl is a stream manipulator rather than a newline character
//    // Note that flushing the output takes more time than using \n
//    // Most streams by default are lined buffered, which means they flush
//    // any time they see a \n, so in most cases, there will be no difference.
//    cout << "Hello World" << endl;
//
//    // Variables and data types
//    const double PI = 3.1415926535; // Constant variable (this value cannot be changed)
//    char myGrade = 'A';
//    bool isHappy = true; // comparable to 1
//    int myAge = 39;
//    float favNum = 3.14; // accurate up to ~6 decimal places
//    double otherFavNum = 1.618; // floats with accuracy up to ~15 digits
//
//    // Output variable to screen
//    cout << "Favorite Number: " << favNum << endl;
//
//    // Other types include:
//    // Note that int is guaranteed to be at least equal to or bigger than short int.
//    // short int : At least 16 bits
//    // long int : At least 32 bits
//    // long long int: At least 64 bits
//    // unsigned int : Same size as signed version
//    // long double : Not less than double
//
//    // myAge is an 'int' so we can use this variable.
//    cout << "Size of int: " << sizeof(myAge);
//
//    // Largest integer is 2147483647.
//    // This will print the number as a negative number.
//    int largestInt = 2147483648;
//    cout << "Largest int: " << largestInt << endl;
//
//    // Arithmetic: +, -, *, /, %, ++, --
//    cout << "5 + 2 = " << 5 + 2 << endl;
//    cout << "5 - 2 = " << 5 - 2 << endl;
//    cout << "5 * 2 = " << 5 * 2 << endl;
//    cout << "5 / 2 = " << 5 / 2 << endl;
//    cout << "5 % 2 = " << 5 % 2 << endl;
//
//    // Prefix vs postfix
//    int five = 5;
//    cout << "5++ = " << five++ << endl; // 5 (prints before incrementing)
//    cout << "++5 = " << ++five << endl; // 7 (prints after incrementing)
//    cout << "5-- = " << five-- << endl; // 7 (prints before decrementing)
//    cout << "--5 = " << --five << endl; // 5 (prints after decrementing)
//
//    // +=, -=, *=, /=
//    // This is valid as long as we have semi-colons to separate the statements.
//    five += 6; five = five + 6;
//
//    // Order of Operation States * and / is performed before + and -
//    cout << "1 + 2 - 3 * 2 = " << 1 + 2 - 3 * 2 << endl; // -3
//    cout << "(1 + 2 - 3) * 2 = " << (1 + 2 + 3) * 2 << endl; // 0
//
//    // Division and casting.
//    cout << "4 / 5 = " << 4 / 5 << endl; // 0
//    cout << "4 / 5 = " << (float) 4 / 5 << endl; // 0.8
//    cout << "4 / 5 = " << 4 / (float) 5 << endl; // 0.8
//
//    // If statement
//    // Comparison operators: == != > < >= <=
//    // Logical operators: && || !
//    int age = 70;
//    int ageAtLastExam = 16;
//    bool isNotIntoxicated = true;
//
//    if (age >= 1 && age < 16) {
//        cout << "You can't drive." << endl;
//    } else if (age >= 80 && (age > 100 || (age - ageAtLastExam) > 5)) {
//        cout << "You can't drive." << endl;
//    } else {
//        cout << "You can drive!" << endl;
//    }
//
//    // Switch statement
//    int greetingOption = 2;
//
//    switch (greetingOption) {
//      case 1:
//        cout << "Bonjour" << endl;
//        break;
//      case 2:
//        cout << "Hola" << endl;
//        break;
//      case 3:
//        cout << "Hallo" << endl;
//        break;
//      default:
//        cout << "Hello" << endl;
//    }
//
//    // Ternary operator
//    // variable = (condition) ? true : false
//
//    int largestNum = (5 > 2) ? 5 : 2;
//    cout << "Largest number is " << largestNum << endl;
//
//    // Arrays
//    int myFavNum[5];
//
//    int badNums[5] = {4, 13, 14, 24, 34};
//
//    cout << "Bad Number 1: " << badNums[0] << endl;
//
//    // 2D arrays
//    char myName[5][5] = {{'D', 'e', 'r', 'e', 'k'},
//                         {'B', 'a', 'n', 'a', 's'}};
//
//    cout << "2nd letter in 2nd array: " << myName[1][1] << endl;
//
//    myName[0][2] = 'e';
//
//    cout << "New Value: " << myName[0][2] << endl;
//
//    // For loops
//    for (int i = 1; i <= 10; i++) {
//        cout << i << endl;
//    }
//
//    for (int i = 0; i < 5; i++) {
//        for (int j = 0; j < 5; j++) {
//            cout << myName[i][j];
//        }
//        cout << endl; // new line
//    }
//
//    // While loops
//    int randNum = (rand() % 100) + 1;
//
//    while (randNum != 100) {
//        cout << randNum << ", ";
//        randNum = (rand() % 100) + 1;
//    }
//
//    cout << endl;
//
//    int index = 1;
//    while (index <= 10) {
//        cout << index << endl;
//        index++;
//    }
//
//    // Do while loops
//    string numberGuessed;
//    int intNumberGuessed = 0;
//    do {
//        cout << "Guess a number between 1 and 10: ";
//
//        // Get user input from keyboard to store inside string.
//        // 'cin' is the source of the user input.
//        getline(cin, numberGuessed);
//
//        // Convert string to integer with stoi()
//        intNumberGuessed = stoi(numberGuessed);
//
//    } while (intNumberGuessed != 4);
//    cout << "You win!" << endl;

//    =======================================

//    // Strings (both ways are valid in C++)
//    char happyArray[6] = {'H', 'a', 'p', 'p', 'y', '\0'};
//    string birthdayString = " Birthday";
//    cout << happyArray + birthdayString << endl;
//
//    string yourName;
//    cout << "What is your name?" << endl;
//    getline(cin, yourName);
//    cout << "Hello, " << yourName << "!" << endl;
//
//    double eulersConstant = .57721;
//    string eulerGuess;
//    double eulerGuessDouble;
//
//    cout << "What is Euler's Constant?" << endl;
//    getline(cin, eulerGuess);
//    eulerGuessDouble = stoi(eulerGuess);
//    if (eulerGuessDouble == eulersConstant) {
//        cout << "You are right!" << endl;
//    } else {
//        cout << "You are wrong!" << endl;
//    }
//
//    // Get the size of the string ( == # characters)
//    cout << "Size of string: " << eulerGuess.size() << endl;
//
//    // Return 0 if false
//    cout << "Empty string: " << eulerGuess.empty() << endl;
//
//    // Print eulerGuess before string " was your guess."
//    cout << eulerGuess.append(" was your guess.") << endl;
//
//    // Return 1, 0, or -1 depending on lexicographical comparison
//    string dogString = "dog";
//    string catString = "cat";
//    cout << dogString.compare(catString) << endl;
//    cout << dogString.compare(dogString) << endl;
//    cout << catString.compare(dogString) << endl;
//
//    // Copy string value to variable
//    string wholeName = yourName.assign(yourName);
//    cout << wholeName << endl;
//
//    // Assign substrings
//    string firstName = wholeName.assign(wholeName, 0, 5);
//    cout << firstName << endl;
//
//    // Easily find start of substring
//    int lastNameIndex = yourName.find("Tran", 0);
//    cout << "Index for last name: " << lastNameIndex << endl;
//
//    // Insert
//    yourName.insert(5, " Kiet");
//    cout << yourName << endl;
//
//    // Delete 5 characters starting at index 5
//    yourName.erase(6, 5);
//    cout << yourName << endl;
//
//    // Replace 5 characters starting from index 6
//    yourName.replace(6, 5, "Maximus");
//    cout << yourName << endl;

//    =======================================

//      // Vectors - arrays whose size can change
//      vector <int> lotteryNumVect(10);
//
//      int lotteryNumArray[5] = {4, 13, 14, 24, 34};
//
//      // Put the array inside our vector (take only the first 3 numbers)
//      lotteryNumVect.insert(lotteryNumVect.begin(), lotteryNumArray, lotteryNumArray+3);
//
//      // Get the 3rd index from the vector.
//      cout << lotteryNumVect.at(2) << endl;
//
//      // Add our arbitrary value '44' to the fifth index.
//      lotteryNumVect.insert(lotteryNumVect.begin()+5, 44);
//
//      // Get the 5th index from the vector.
//      cout << lotteryNumVect.at(5) << endl;
//
//      // Add the value to the end of the vector.
//      lotteryNumVect.push_back(64);
//
//      // Get the last value of the vector.
//      cout << "Final Value: " << lotteryNumVect.back() << endl;
//
//      // Remove the last element of the vector.
//      lotteryNumVect.pop_back();
//      cout << "After pop: " << lotteryNumVect.back() << endl;
//
//      // Check if the vector is empty (returns 0 if not empty).
//      cout << "Is vector empty: " << lotteryNumVect.empty() << endl;
//
//      // Get the size of the vector.
//      cout << "Vector size: " << lotteryNumVect.size() << endl;

//        =======================================
//
//        // Call functions
//        cout << addNumbers(1) << endl;
//        cout << addNumbers(1, 5, 6) << endl;
//        cout << "The factorial of 3 is " << getFactorial(3) << endl;

//        =======================================

//    // File I/O
//    string steveQuote = "A day without sunshine is like, you know, night";
//
//    // Output file stream called 'writer'
//    ofstream writer("stevequote.txt");
//
//    // Check whether able to write to the file
//    if (!writer) {
//        cout << "Error opening file" << endl;
//        return -1;
//    } else {
//        writer << steveQuote << endl;
//        writer.close();
//    }
//
//    // Append to the file
//    ofstream writer2("stevequote.txt", ios::app);
//
//    // Open a stream to append to the what's there with ios::app
//    // ios::binary : Treat the file as binary
//    // ios::in : Open a file to read input
//    // ios::trunc : Default (what happens when you don't use any of these symbols)
//    // ios::out : Open a file to write output
//
//    // Check whether able to write to the file
//    if (!writer2) {
//        cout << "Error opening file" << endl;
//        return -1;
//    } else {
//        writer2 << "\n - Steve Martin" << endl;
//        writer2.close();
//    }
//
//    // Read from file via input file stream
//    char letter;
//
//    ifstream reader("stevequote.txt");
//
//    if (!reader) {
//        cout << "Error opening file" << endl;
//        return -1;
//    } else {
//        for (int i = 0; !reader.eof(); i++) {
//            reader.get(letter);
//            cout << letter;
//        }
//
//        cout << endl;
//        reader.close();
//    }

//    // =======================================

//    // Exception Handling
//    int number = 0;
//
//    // Try this code, else throw an error.
//    try {
//        if (number != 0) {
//            cout << 2 / number << endl;
//        } else throw (number);
//    }
//    catch (int number) {
//        cout << number << " is not valid" << endl;
//    }
//

//    // =======================================
//
//    // Pointers
//    int myAge = 39;
//    char myGrade = 'A';
//
//    cout << "Size of int " << sizeof(myAge) << endl;
//    cout << "Size of char " << sizeof(myGrade) << endl;
//
//    cout << "myAge is located at " << &myAge << endl;
//
//    // Give address of variable to agePtr.
//    int *agePtr = &myAge;
//
//    cout << "Address of pointer " << agePtr << endl;
//    cout << "Data at memory address " << *agePtr << endl;
//
//    // Prints 4, then 13 for value
//    int badNums[5] = {4, 13, 14, 24, 34};
//    int *numArrayPtr = badNums;
//    cout << "Address " << numArrayPtr << " Value " << *numArrayPtr << endl;
//    numArrayPtr++;
//    cout << "Address " << numArrayPtr << " Value " << *numArrayPtr << endl;
//
//    // changing this variable affects myAge
//    // a reference needs to be initialized unlike a pointer
//    // a pointer can deal with more than one variable unlike a reference
//    // use a pointer if you're not changing what you're pointing at
//    int &ageRef = myAge;
//    cout << "myAge : " << myAge << endl;
//    ageRef++;
//    cout << "myAge : " << myAge << endl;

    // =======================================

    // Create objects
    Animal dog;

    dog.setHeight(33);
    dog.setWeight(10);
    dog.setName("Fred");

    cout << dog.getName() << " is " << dog.getHeight() <<
        " cms tall and " << dog.getWeight() << " kgs in weight" << endl;

    Animal cat(36, 15, "Tom");
    cout << cat.getName() << " is " << cat.getHeight() <<
        " cms tall and " << cat.getWeight() << " kgs in weight" << endl;

    // Make a mouse
    Mouse jerry(38, 16, "Jerry", "Squeakity");

    // Test static method
    cout << "Number of Animals " << Animal::getNumOfAnimals();

    jerry.getSound();
    cat.toString();
    jerry.toString();

    // Call the superclass version of a method with the scope operator (::).
    jerry.Animal::toString();

    // Execution went through perfectly fine.
    return 0;
}
