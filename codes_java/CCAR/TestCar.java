class Car {
    int door = 2;
}

public class TestCar{
    Integer i = 3;
    static int getDoor(){
        Car car = new Car();
        return car.door;
    }
    
}