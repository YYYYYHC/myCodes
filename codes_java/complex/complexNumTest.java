public class complexNumTest {
    public static void main(String[] args) {
        System.out.println("测试toSting");
        complexNum testNum1 = new complexNum(1,2.5);
        complexNum testNum2 = new complexNum(-3.2,2);
        System.out.println("Num1="+testNum1);
        System.out.println("Num2="+testNum2);
        System.out.println("测试加法");
        System.out.println("Num1+Num2="+complexNum.complexAdd(testNum1,testNum2));
        System.out.println("测试减法");
        System.out.println("Num1-Num2="+complexNum.complexSub(testNum1,testNum2));
        System.out.println("测试乘法");
        System.out.println("Num1*Num2="+complexNum.complexMulti(testNum1,testNum2));
        //没注意 写多了个除法 
        // System.out.println("第一次测试除法");
        // System.out.println("Num1/Num2="+complexNum.complexDiv(testNum1,testNum2));
        // System.out.println("第二次测试除法");
        // System.out.println("Num1/Num1="+complexNum.complexDiv(testNum1,testNum1));
    }
}