class Book {
    public String Title;
    public String Pdate;//格式约定为xxxx.xx.xx 如2001.11.01
    public long Words;
    double price()
    {
        double dateRelate;
        if((((int)Pdate.charAt(5)+(int)Pdate.charAt(6))<=6))
            dateRelate=1.2;
        else
            dateRelate=1.18;
        return Words/1000*35*dateRelate;
    };
    void outPutBook()
    {
        System.out.println("The title is: "+Title);
        System.out.println("The publication date is: "+Pdate);
        System.out.println("The words number is: "+Words);
    } 
}

public class TestClass{
    
    public static void main(String[] args) {
        Book aBook = new Book();
        aBook.Title="I am a book";
        aBook.Pdate="2001.11.01";
        aBook.Words=10000;
        aBook.outPutBook();
        System.out.println("The price is: "+aBook.price());
        
    }
}