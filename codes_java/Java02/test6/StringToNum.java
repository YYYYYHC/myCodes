public class StringToNum {
    public static void main(String[] args){
        String str = "123";
        // try{
        int intValue = Integer.parseInt(str);
        System.out.println(intValue);
        double dbValue = Double.parseDouble(str);
        System.out.println(dbValue);
        
        long longValue = Long.parseLong(str);
        System.out.println(longValue);
        
        float floatValue = Float.parseFloat(str);
        System.out.println(floatValue);
        
        short shortValue = Short.parseShort(str);
        System.out.println(shortValue);
        // }catch (NumberFormatException nbFmtExp){
        // System.out.println("Error format string to parse!");
        // }finally{
        //     System.out.println("end converting");
        // }
        }
}