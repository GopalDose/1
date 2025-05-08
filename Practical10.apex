public class GeometryTest {

    // Circle class
    public class Circle {
        Decimal radius;

        public Circle(Decimal r) {
            radius = r;
        }

        public Decimal area() {
            return Decimal.valueOf(Math.PI) * radius * radius;
        }
    }

    // Square class
    public class Square {
        Decimal side;

        public Square(Decimal s) {
            side = s;
        }

        public Decimal area() {
            return side * side;
        }
    }

    // Rectangle class
    public class Rectangle {
        Decimal length;
        Decimal width;

        public Rectangle(Decimal l, Decimal w) {
            length = l;
            width = w;
        }

        public Decimal area() {
            return length * width;
        }
    }

    // Method to run and display area calculations
    public static void main() {
        Circle c = new Circle(3.0D);
        Square s = new Square(4.0D);
        Rectangle r = new Rectangle(5.0D, 2.0D);

        System.debug('Circle Area: ' + c.area());
        System.debug('Square Area: ' + s.area());
        System.debug('Rectangle Area: ' + r.area());
    }
}
