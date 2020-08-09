/**
 * @file Interview.cpp
 * @author FridaySky
 * @date October 2019
 * 
 * @brief C++ interview prep
 */


/**
 * @todo
 * 1. Dynamic memory - 1/2 DONE
 * 2. Dynamic array allocation - 1/2 DONE
 * 3. Polymorphism (virtual keyword) - DONE
 * 4. Templates - DONE
 * 5. Vector iterators - 1/2 DONE
 * 6. std::arrays - 1/2 DONE
 * 7. Vector operations - 1/4 DONE
 * 8. Pointer galore - 1/2 DONE
 * 9. Bit shifting - 1/2 DONE
 * 10. Garbage collector - 1/2 DONE
 * 11. std::map - 1/4 DONE
 * 12. Classes - 1/2 DONE
 * 13. https://www.fluentcpp.com/2018/12/14/named-arguments-cpp/
 */


/* C++ imports */
#include <array>
#include <iostream>
#include <string>
#include <vector>


/* Classes */

/**
 * Polygon class
 * 
 * @note This is an abstract base class since it has a pure virtual function
 * @note Abstract base classes cannot be used to instantiate objects
 */
class Polygon {

    protected:

        size_t width, height;

    public:
    
        /**
         * Set width and height of shape
         * 
         * @param[in] width  - Unsigned integer indicating width of shape
         * @param[in] height - Unsigned integer indicating height of shape
         */
        void setDimensions(size_t width, size_t height) {
            this->width  = width;
            this->height = height;
        }

        /**
         * Return area of polygon
         * 
         * @return 0 since we cannot compute the area of a generic polygon
         */
        virtual size_t getArea() {
            return 0;
        }

        /**
         * Return perimeter of polygon
         * 
         * @note This is a pure virtual function since it has no definition (replaced by = 0)
         * @return 0 since we cannot compute the perimeter of a generic polygon
         */
        virtual size_t getPerimeter() = 0;

        /**
         * Print perimeter of polygon
         * 
         * @note We can use the special pointer 'this' to access a pure virtual function
         * But we can also do it without using this
         */
        void printPerimeter() {
            std::cout << "Perimeter: " << this->getPerimeter() << "\n";
        }
};

/**
 * Rectangle class inherited from Polygon class
 */
class Rectangle : public Polygon {

    public:

        /**
         * Compute area of rectangle
         * 
         * @return Unsigned integer indicating area of rectangle
         */
        size_t getArea() {
            return width * height;
        }

        /**
         * Compute perimeter of rectangle
         * 
         * @return Unsigned integer indicating perimeter of rectangle
         */
        size_t getPerimeter() {
            return 2 * width + 2 * height;
        }
};

/**
 * Triangle class inherited from Polygon class
 * 
 * @note To create a Triangle object, we need to override the pure virtual function getPerimeter()
 *       inherited from the Polygon class
 */
class Triangle : public Polygon {

    public:

        /**
         * Compute area of triangle
         * 
         * @return Unsigned integer indicating area of triangle
         */
        size_t getArea() {
            return width * height / 2;
        }

        /**
         * Computer perimeter of triangle
         * 
         * @return Unsigned integer indicatnig perimeter of triangle
         */
        size_t getPerimeter() {
            return 1; // too lazy to computer perimeter of triangle
        }
};


/* Structs */
struct movies_t {
    std::string title;
    int year;
};


/* Function prototypes */
// C arrays
void print1DIntArray(int a [], size_t size);
void print2DIntArray(int a[][2], size_t size);

// std::array
template<std::size_t SIZE>
void modifyContainerArrayByReference(std::array<int, SIZE> *a);

template<std::size_t SIZE>
void modifyContainerArrayByValue(std::array<int, SIZE> a);

template<std::size_t SIZE>
void printContainerArray(std::array<int, SIZE> a);

// Templates
template <class T>
T getGreater(T a, T b);

// Vectors
void printIntVector(std::vector<int> v);

// Pointer functions
int addition(int a, int b);
int subtraction(int a, int b);
int operation(int a, int b, int *funcToCall(int, int));
void incrementByOne(void *data, int dataSize);


/*** ================================================== C ARRAYS ================================================== ***/

void print1DIntArray(int a [], size_t size) {
    
    for (size_t i = 0; i< size; ++i) {
        std::cout << a[i] << " ";
    }
    
    std::cout << "\n" << "\n";
}

/**
 * Print a language built-in 2D integer array inherited from C
 * 
 * Notice that the first brackets [] are left empty, while the following ones specify sizes for their respective dimensions.
 * This is necessary in order for the compiler to be able to determine the depth of each additional dimension
 * 
 * @param[in] a    - Two-dimensional integer array with 'size' rows and 2 columns
 * @param[in] size - Unsigned integer indicating number of rows in array 'a'
 */
void print2DIntArray(int a [][2], size_t size) {

    for (size_t i = 0; i < size; ++i) {

        for (size_t j = 0; j < 2; j++) {

            std::cout << a[i][j] << " ";
        }

        std::cout << "\n" << "\n";
    }

    std::cout << "\n";
}


/*** ================================================== C++ ARRAYS ================================================== ***/

/**
 * Modify the actual std::array 'a'
 * 
 * @tparam SIZE  - Unsigned integer indicating size of array 'a'
 * @param[out] a - Pointer to a one-dimensional integer std::array of size 'SIZE'
 */
template<std::size_t SIZE>
void modifyContainerArrayByReference(std::array<int, SIZE> *a) {

    std::cout << "modifyContainerArrayByReference()";

    for (size_t i = 0; i < a->size(); ++i) {

        ++(*a)[i];
    }

    std::cout << "\n";

    printContainerArray(*a);
}

/**
 * Modify a copy of the std::array 'a'
 * 
 * @tparam SIZE - Unsigned integer indicating size of array 'a'
 * @param[in] a - PointerOne-dimensional integer std::array of size 'SIZE'
 */
template<std::size_t SIZE>
void modifyContainerArrayByValue(std::array<int, SIZE> a) {

    std::cout << "modifyContainerArrayByValue()";

    for (size_t i = 0; i < a.size(); ++i) {

        ++a[i];
    }

    std::cout << "\n";

    printContainerArray(a);
}

/**
 * Print a std::array
 * 
 * @tparam SIZE - Unsigned integer indicating size of array 'a'
 * @param[in] a - One-dimensional integer std::array of size 'SIZE'
 */
template<std::size_t SIZE>
void printContainerArray(std::array<int, SIZE> a) {
    
    for (auto e : a) {

        std::cout << e << "\n";
    }

    std::cout << "\n";
}


/*** ================================================== POINTERS ================================================== ***/

/**
 * Add two numbers
 * 
 * @param[in] a - First integer operand
 * @param[in] b - Second integer operand
 * @return Sum of a and b
 */
int addition(int a, int b) {
    return (a + b);
}

/**
 * Subtract two numbers
 * 
 * @param[in] a - First integer operand
 * @param[in] b - Second integer operand
 * @return Subtract b from a
 */
int subtraction(int a, int b) {
    return (a - b);
}

/**
 * Perform an operation on two numbers
 * 
 * @param[in] a          - First integer operand
 * @param[in] b          - Second integer operand
 * @param[in] funcToCall - Pointer to function to call
 * @return Integer computed from funcToCall()
 */
int operation(int a, int b, int *funcToCall(int, int)) {
    return *funcToCall(a, b);
}

/**
 * Increment the value of the pointer by one
 * 
 * @param[out] *data    - Void pointer to any type of data
 * @param[in]  dataSize - Size of data
 */
void incrementByOne(void *data, int dataSize) {
    if (dataSize == sizeof(char)) {
        ++(* (char *) data); // cast to character pointer type, and dereference character pointer to increment value
    }
    else if (dataSize == sizeof(int)) {
        ++(* (int *) data);
    }
}


/*** ================================================== TEMPLATES ================================================== ***/

/**
 * Return the argument with the greater value
 * 
 * @tparam T    - Template argument that accepts different data types
 * @param[in] a - First argument
 * @param[in] b - Second argument
 * @return Return greater of two arguments; if equal, return b
 */
template <class T>
T getGreater(T a, T b) {
    return (a > b) ? a : b;
}

/*** ================================================== VECTORS ================================================== ***/

/**
 * Print an integer-type vector
 * 
 * @param[in] v - Integer vector
 */
void printIntVector(std::vector<int> v) {

    std::cout << "printIntVector()" << "\n";

    for (auto i = v.begin(); i != v.end(); ++i) {
        std::cout << *i << " ";
    }

    std::cout << "\n" << "\n";
}


/*** ================================================== MAIN ================================================== ***/

/**
 * Function to be called at program startup
 * 
 * @param[in] argc - Number of arguments, including the program name
 * @param[in] argv - Array of character pointers listing all arguments
 * @return 0 to indicate successful exit status
 */
int main(int argc, char **argv) {

    /* ---------------------------------------------------------------------------------------------------- */
    /* Polymorphism and virtual */
    // Polygon Pam; // We cannot create this object since it has a pure virtual function
    Rectangle Rick;
    Triangle Tora;

    // For demonstration purposes, we can use superclass pointer as such
    // Polygon *pPam  = &Pam; // Abstract base classes cannot be instantiated
    Polygon *pRick = &Rick;
    Polygon *pTora = &Tora;

    // pPam->setDimensions(4000, 900); // getArea() = 0 (if it was not an abstract base class)
    pRick->setDimensions(5, 5); // getArea() = 25
    pTora->setDimensions(4, 4); // getArea() = 4

    // std::cout << << "Area of generic polygon: " << pPam->getArea();
    std::cout << pRick->getArea() << " " << pTora->getArea() << "\n";

    Tora.setDimensions(2, 2); // getArea() = 2
    std::cout << pTora->getArea() << "\n";

    // NOTE: if Polygon.getArea() was NOT virtual, all inherited getArea() would return 0

    Rick.printPerimeter();


    // /* ---------------------------------------------------------------------------------------------------- */
    // /* Templates */
    // std::cout << getGreater(1, 2) << "\n";
    // std::cout << getGreater(3.4, 1.6) << "\n";

    /* ---------------------------------------------------------------------------------------------------- */
    /* TODO: http://www.cplusplus.com/doc/tutorial/other_data_types/ */

    // /* ---------------------------------------------------------------------------------------------------- */
    // /* Structs */
    // movies_t rushHour;
    // movies_t *pRushHour;
    // pRushHour = &rushHour;
    // rushHour.title = "Rush Hour";
    // pRushHour->year = 1998;
    // std::cout << (*pRushHour).title << " (" << pRushHour->year << ")" << "\n";

    // /* ---------------------------------------------------------------------------------------------------- */
    // /* Dynamic memory allocation */
    // int *foo;
    // foo = new int [5] {
    //     1, 2, 3, 4, 5
    // };
    // print1DIntArray(foo, 5);
    // foo = new int [10] {
    //     1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    // };
    // print1DIntArray(foo, 10);

    // /* ---------------------------------------------------------------------------------------------------- */
    // /* Function pointers */
    // int (*minus)(int, int) = &subtraction;
    // std::cout << operation(20, 5, minus) << "\n"; // TODO

    // /* ---------------------------------------------------------------------------------------------------- */
    // /* Void pointers */
    // char x = 'x';
    // int y  = 1602;
    // incrementByOne(&x, sizeof(x));
    // incrementByOne(&y, sizeof(y));
    // std::cout << x << " " << y << "\n";
    

    // /* ---------------------------------------------------------------------------------------------------- */
    // /* User input */
    // char question [] = "What is your name? ";
    // std::string answer;
    // std::cout << question;
    // std::cin >> answer;
    // std::cout << "Hello, " << answer << "\n";

    // /* ---------------------------------------------------------------------------------------------------- */
    // /* Vectors are the same as dynamic arrays with the ability to resize itself
    //    automatically when an element is inserted or deleted, with their storage
    //    being handled automatically by the container.
    //    Vector elements are placed in contiguous storage so that they can be accessed
    //    and traversed using iterators. In vectors, data is inserted at the end.
    //    Inserting at the end takes differential time, as sometimes there may be a need
    //    of extending the array. Removing the last element takes only constant time
    //    because no resizing happens. Inserting and erasing at the beginning or in the
    //    middle is linear in time.
    // */
    // std::vector<int> v;

    // // Add elements to back of vector
    // for (size_t i = 1; i <= 5; ++i) {
    //     v.push_back(i);
    // }
    // printIntVector(v);

    /* ---------------------------------------------------------------------------------------------------- */
    /* Container library array (aka std::array) */
    // std::array<int, 3> b {10, 20, 30};

    // /* ************************************************** */
    // /* Show that actual contents were not changed because we passed in 'b' by value */
    // modifyContainerArrayByValue(b);

    // std::cout << "Printing std::array from main() after passing-by-value" << "\n";
    // printContainerArray(b);

    // /* ************************************************** */
    // /* Show that actual contents were changed because we passed in 'b' by reference */
    // modifyContainerArrayByReference(&b);
    
    // std::cout << "Printing std::array from main() after passing-by-reference" << "\n";
    // printContainerArray(b);

    // /* ---------------------------------------------------------------------------------------------------- */
    // /* Language built-in array */
    // int a [2][2] {
    //     1, 2, 3, 4
    // };

    // print2DIntArray(a, 2);

    return 0;
}

