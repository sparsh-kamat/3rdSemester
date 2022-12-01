#include <iostream>
using namespace std;
class Distance {
    private:
        int feet;
        int inches;
   public:
        Distance() {
            feet = 0;
            inches = 0;
        }
        friend ostream &operator<<( ostream &output, const Distance &D ) {
            output << "F : " << D.feet << " I : " << D.inches;
            return output;
        }
        friend istream &operator>>( istream &input, Distance &D ) {
            input >> D.feet >> D.inches;
            return input;
        }
};
int main() {
   Distance D;
   cout << "Enter the distance(Feet-inches): ";
   cin >> D;
   cout << "The Distance: " << D << endl;
   return 0;
}
