public class complexNum {
    double realPart;
    double imgPart;

    public complexNum(){}
    public complexNum(double real,double img){
        realPart = real;
        imgPart =img;
    }

    @Override
    public String toString(){
        return realPart + "+"+imgPart+"i";
    }

    public static complexNum complexAdd(complexNum x1,complexNum x2){
        complexNum res = new complexNum();
        res.realPart = x1.realPart + x2.realPart;
        res.imgPart = x1.imgPart + x2.imgPart;
        return res;
    }

    public static complexNum complexSub(complexNum x1,complexNum x2){
        complexNum res = new complexNum();
        res.realPart = x1.realPart - x2.realPart;
        res.imgPart = x1.imgPart - x2.imgPart;
        return res;
    }

    public static complexNum complexMulti(complexNum x1, complexNum x2){
        complexNum res = new complexNum();
        res.realPart = x1.realPart*x2.realPart - x1.imgPart*x2.imgPart;
        res.imgPart = x1.realPart*x2.imgPart + x1.imgPart*x2.realPart;
        return res;
    }

    // public static complexNum complexDiv(complexNum x1, complexNum x2){
    //     complexNum res = new complexNum();
    //     final double deno = x2.realPart*x2.realPart + x2.imgPart*x2.imgPart;
    //     res.realPart = (x1.realPart*x2.realPart + x1.imgPart*x2.imgPart)/deno;
    //     res.imgPart = (x1.imgPart*x2.realPart - x1.realPart*x2.imgPart)/deno;
    //     return res;
    // }
}