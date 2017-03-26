// write a function that takes in an int and returns a string that would be how one would say that number (ex: 123 - one hundred twenty three; 50019 - five thousand nineteen). 

#include <string>
#include <math.h>
using namespace std;

string number_as_words(int number)
{
    string output = "";
    string ones[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "ninteen"};
    string tens[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    string magnitudes[] = {"hundred", "thousand"};
    for (int i = floor(log10(abs(number))); i < 0; i++)
    {
        
    }
}

int main()
{
    return 0;
}
