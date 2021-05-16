public class Car {
    int color_number;
    int door_number;
    int speed;
    Car(){}
    Car(int i){
        speed=i;
    }
    void showSpeed(){
        System.out.println("Current speed is "+(speed));
    }

    public void brake(){
        System.out.println("Stop! My speed is: "+(speed));
        speed = 0;
    }
    void speedUp(int speedUpNum){
        System.out.println("speed up "+(speedUpNum)+".Now the speed is "+(speed+speedUpNum));
        speed+=speedUpNum;
    }
    void slowDown(int slowDownNum){
        System.out.println("slow down "+(slowDownNum)+".Now the speed is "+(speed-slowDownNum));
        speed-=slowDownNum;
    }

    public static void main(String[] arg){
        Car testCar=new Car(1);
        System.out.println("I am a car!");
        testCar.brake();
        testCar.speedUp(5);
        testCar.slowDown(3);
        testCar.brake();
        testCar.showSpeed();

        System.out.println("I an a miniCar!");
        miniCar testMiniCar = new miniCar(1);
        testMiniCar.speedUp(10);
        testMiniCar.showSpeed();
        testMiniCar.miniCarSpeedMonitor();
    }
}
class miniCar
extends Car{
    miniCar(int i)
    {
        speed = i;
    }
    int carSize;
    void miniCarSpeedMonitor(){
        if(speed>4) System.out.println("the minicar is too fast!!");
    }
}