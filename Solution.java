
public class Solution {

    public PolyNode addPoly(PolyNode firstPolynomial, PolyNode secondPolynomial) {
        PolyNode headAdditionTwoPolynomials = new PolyNode();
        PolyNode current = headAdditionTwoPolynomials;

        while (firstPolynomial != null && secondPolynomial != null) {

            if (firstPolynomial.power > secondPolynomial.power) {
                current.next = new PolyNode(firstPolynomial.coefficient, firstPolynomial.power);
                firstPolynomial = firstPolynomial.next;
                current = current.next;
                continue;
            }

            if (firstPolynomial.power < secondPolynomial.power) {
                current.next = new PolyNode(secondPolynomial.coefficient, secondPolynomial.power);
                secondPolynomial = secondPolynomial.next;
                current = current.next;
                continue;
            }

            if (firstPolynomial.coefficient + secondPolynomial.coefficient != 0) {
                int newCoefficient = firstPolynomial.coefficient + secondPolynomial.coefficient;
                current.next = new PolyNode(newCoefficient, firstPolynomial.power);
                current = current.next;
            }

            firstPolynomial = firstPolynomial.next;
            secondPolynomial = secondPolynomial.next;
        }

        current.next = (firstPolynomial != null) ? firstPolynomial : secondPolynomial;

        return headAdditionTwoPolynomials.next;
    }
}

/*
Class PolyNode is in-built in the solution file on leetcode.com. 
When running the code on the website, do not include this class.
 */
class PolyNode {

    int coefficient, power;
    PolyNode next = null;

    PolyNode() {
    }

    PolyNode(int x, int y) {
        this.coefficient = x;
        this.power = y;
    }

    PolyNode(int x, int y, PolyNode next) {
        this.coefficient = x;
        this.power = y;
        this.next = next;
    }
}
