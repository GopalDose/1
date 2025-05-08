public class prime {
    public static void main(){
        Integer num = 20;
        Boolean isPrime = true;
        for(Integer i = 2; i < Math.sqrt(num); i++){
            if(Math.mod(num, i) == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
	        System.debug('The number is Prime');
        }
        else{
            System.debug('The number is Not Prime');
        }
    }
}