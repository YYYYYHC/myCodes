interface Speakable{
    public void speak();
  }
  interface Runner{
    public void run();
  }
  class Dog implements Speakable,Runner{
    @Override
    public void speak(){
      System.out.println("狗的声音:汪、汪！");
    }
    @Override
    public void run(){
      System.out.println("狗用四肢跑步");
    }
  }
  class Bird implements Speakable,Runner{
      @Override
      public void speak(){
          System.out.println("叽叽叽叽叽叽");
      }
      @Override
      public void run(){
          System.out.println("芜湖 起飞");
      }
  }
  class Person implements Speakable,Runner{
    @Override
    public void speak(){
      System.out.println("人们见面时经常说:您好！");
    }
    @Override
    public void run(){
      System.out.println("人用两腿跑步");
    }
  }
  public class TestInterface{
    public static void main(String[] args) {
      Dog d=new Dog();
      d.speak(); d.run();
      Person p=new Person();
      p.speak();  p.run();
      Bird b=new Bird();
      b.speak(); b.run();
    }
  }
  