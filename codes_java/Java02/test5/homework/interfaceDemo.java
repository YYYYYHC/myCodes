interface Vehicle{
    public void start(int speed);
    public void stop();
}

class Bike implements Vehicle{
    @Override
    public void start (int speed){
        System.out.println("自行车以速度"+speed);
    }
    @Override
    public void stop(){
        System.out.println("自行车停下了");
    }
}
class Bus implements Vehicle{
    @Override
    public void start(int speed){
        System.out.println("公交车以速度"+speed+"启动了");
    }
    @Override
    public void stop(){
        System.out.println("汽车停下了");
    }
}

public class interfaceDemo{
    public static void main(String[] args) {
        Bike aBkie = new Bike();
        aBkie.start(10); aBkie.stop();
        Bus aBus = new Bus();
        aBus.start(100); aBus.stop();
    }
}