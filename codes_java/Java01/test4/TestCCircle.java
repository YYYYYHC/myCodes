class CCircle   {
    final double pi=3.14159;    
    double radius;
    public CCircle()
    {}
    public CCircle(double inputRadius){
        radius = inputRadius;
    }

    double getSquare(){
       return pi*radius*radius; 
    }
    double getRadius(){
        return radius;
  }
    void setCircle(double r){     
        radius=r;   
     }
  }

  public class TestCCircle{
    public static void main(String args[])   {
       CCircle cir1=new CCircle(2.0);   
       //cir1.setCircle(2.0);
       System.out.println("radius="+cir1.getRadius()); 
       System.out.println("square="+cir1.getSquare()); 
    }
 }
 
  