public class Temperature {
    // Method to convert Celsius to Fahrenheit
    public Decimal CtoF(Decimal temp) {
        return (temp * 9 / 5) + 32;
    }

    // Method to convert Fahrenheit to Celsius
    public Decimal FtoC(Decimal temp) {
        return (temp - 32) * 5 / 9;
    }

    // Method to demonstrate conversion (can be called from Anonymous Apex or test method)
    public static void main() {
        Temperature t = new Temperature();
        Decimal celsius = 25.0;
        Decimal fahrenheit = 98.6;

        Decimal convertedToF = t.CtoF(celsius);
        Decimal convertedToC = t.FtoC(fahrenheit);

        System.debug('Celsius to Fahrenheit (' + celsius + ' °C): ' + convertedToF + ' °F');
        System.debug('Fahrenheit to Celsius (' + fahrenheit + ' °F): ' + convertedToC + ' °C');
    }
}
