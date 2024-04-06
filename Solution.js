
/**
 * @param {PolyNode} firstPolynomial
 * @param {PolyNode} secondPolynomial
 * @return {PolyNode}
 */
var addPoly = function (firstPolynomial, secondPolynomial) {
    let headAdditionTwoPolynomials = new PolyNode();
    let current = headAdditionTwoPolynomials;

    while (firstPolynomial !== null && secondPolynomial !== null) {

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

        if (firstPolynomial.coefficient + secondPolynomial.coefficient !== 0) {
            let newCoefficient = firstPolynomial.coefficient + secondPolynomial.coefficient;
            current.next = new PolyNode(newCoefficient, firstPolynomial.power);
            current = current.next;
        }

        firstPolynomial = firstPolynomial.next;
        secondPolynomial = secondPolynomial.next;
    }

    current.next = (firstPolynomial !== null) ? firstPolynomial : secondPolynomial;

    return headAdditionTwoPolynomials.next;
};

/*
 Function PolyNode is in-built in the solution file on leetcode.com. 
 When running the code on the website, do not include this function.
 */
function PolyNode(x = 0, y = 0, next = null) {
    this.coefficient = x;
    this.power = y;
    this.next = next;
}
