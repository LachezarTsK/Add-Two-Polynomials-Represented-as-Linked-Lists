
using System;

public class Solution
{
    public PolyNode AddPoly(PolyNode firstPolynomial, PolyNode secondPolynomial)
    {
        PolyNode headAdditionTwoPolynomials = new PolyNode();
        PolyNode current = headAdditionTwoPolynomials;

        while (firstPolynomial != null && secondPolynomial != null)
        {
            if (firstPolynomial.power > secondPolynomial.power)
            {
                current.next = new PolyNode(firstPolynomial.coefficient, firstPolynomial.power);
                firstPolynomial = firstPolynomial.next;
                current = current.next;
                continue;
            }

            if (firstPolynomial.power < secondPolynomial.power)
            {
                current.next = new PolyNode(secondPolynomial.coefficient, secondPolynomial.power);
                secondPolynomial = secondPolynomial.next;
                current = current.next;
                continue;
            }

            if (firstPolynomial.coefficient + secondPolynomial.coefficient != 0)
            {
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
public class PolyNode
{
    public int coefficient, power;
    public PolyNode next;

    public PolyNode(int x = 0, int y = 0, PolyNode next = null)
    {
        this.coefficient = x;
        this.power = y;
        this.next = next;
    }
}
