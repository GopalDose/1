public class ScientificCalc {

    // Basic Arithmetic
    public static Double add(Double a, Double b) {
        return a + b;
    }

    public static Double subtract(Double a, Double b) {
        return a - b;
    }

    public static Double multiply(Double a, Double b) {
        return a * b;
    }

    public static Double divide(Double a, Double b) {
        if (b == 0) {
            System.debug('Error: Division by zero');
            return null;
        }
        return a / b;
    }

    // Power and Root
    public static Double power(Double base, Double exponent) {
        return Math.pow(base, exponent);
    }

    public static Double squareRoot(Double num) {
        if (num < 0) {
            System.debug('Error: Cannot compute square root of a negative number');
            return null;
        }
        return Math.sqrt(num);
    }

    // Trigonometric Functions (radians)
    public static Double sin(Double radians) {
        return Math.sin(radians);
    }

    public static Double cos(Double radians) {
        return Math.cos(radians);
    }

    public static Double tan(Double radians) {
        return Math.tan(radians);
    }

    // Logarithmic and Exponential Functions
    public static Double log(Double num) {
        if (num <= 0) {
            System.debug('Error: Logarithm undefined for zero or negative numbers');
            return null;
        }
        return Math.log(num);
    }

    public static Double exp(Double exponent) {
        return Math.exp(exponent);
    }

    // Test method
    public static void main() {
        System.debug('Addition: ' + add(10, 5));
        System.debug('Subtraction: ' + subtract(10, 5));
        System.debug('Multiplication: ' + multiply(10, 5));
        System.debug('Division: ' + divide(10, 5));
        System.debug('Power: ' + power(2, 3));
        System.debug('Square Root: ' + squareRoot(16));
        System.debug('Sine (π/2): ' + sin(Math.PI / 2));
        System.debug('Cosine (π): ' + cos(Math.PI));
        System.debug('Tangent (π/4): ' + tan(Math.PI / 4));
        System.debug('Logarithm: ' + log(Math.E));
        System.debug('Exponential: ' + exp(1));
    }
}
