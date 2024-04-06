
using namespace std;

/*
Struct PolyNode is in-built in the solution file on leetcode.com.
When running the code on the website, do not include this struct.
 */
struct PolyNode {
    int coefficient, power;
    PolyNode* next;
    PolyNode() : coefficient(0), power(0), next(nullptr) {};
    PolyNode(int x, int y) : coefficient(x), power(y), next(nullptr) {};
    PolyNode(int x, int y, PolyNode* next) : coefficient(x), power(y), next(next) {};
};


class Solution {

public:
    PolyNode* addPoly(PolyNode* firstPolynomial, PolyNode* secondPolynomial) const {
        PolyNode* headAdditionTwoPolynomials = new PolyNode();
        PolyNode* current = headAdditionTwoPolynomials;

        while (firstPolynomial != nullptr && secondPolynomial != nullptr) {

            if (firstPolynomial->power > secondPolynomial->power) {
                current->next = new PolyNode(firstPolynomial->coefficient, firstPolynomial->power);
                firstPolynomial = firstPolynomial->next;
                current = current->next;
                continue;
            }

            if (firstPolynomial->power < secondPolynomial->power) {
                current->next = new PolyNode(secondPolynomial->coefficient, secondPolynomial->power);
                secondPolynomial = secondPolynomial->next;
                current = current->next;
                continue;
            }

            if (firstPolynomial->coefficient + secondPolynomial->coefficient != 0) {
                int newCoefficient = firstPolynomial->coefficient + secondPolynomial->coefficient;
                current->next = new PolyNode(newCoefficient, firstPolynomial->power);
                current = current->next;
            }

            firstPolynomial = firstPolynomial->next;
            secondPolynomial = secondPolynomial->next;
        }

        current->next = (firstPolynomial != nullptr) ? firstPolynomial : secondPolynomial;

        return headAdditionTwoPolynomials->next;
    }
};
