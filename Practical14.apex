public class CurrencyExchange {
    private static Map<String, Decimal> currencyA = new  Map<String, Decimal>{
		'USD' => 1.0,
        'INR' => 83.53,
        'EUR' => 0.93,
        'JPY' => 156.0
    };
    
    public Decimal convert(String fromA, String toA, Integer amount){
        if(!currencyA.containsKey(fromA) ||  !currencyA.containsKey(toA)){
            throw new IllegalArgumentException('Unsupported');
        }
        
        Decimal amountInUsd = amount / currencyA.get(fromA);
        Decimal ans = amountInUsd * currencyA.get(toA);
        return ans;
    }
    
    public static void main(){
		CurrencyExchange c = new CurrencyExchange();
        System.debug(c.convert('USD', 'INR', 100));
    }
}