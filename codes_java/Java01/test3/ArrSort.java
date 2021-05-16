public class ArrSort {
    public static void main(String[] args) {
     int arr[]=new int[5];
     int i;
     arr[0]=10;
     arr[1]=20;
     arr[2]=-9;
     arr[3]=8;
     arr[4]=98;
     int min=0,max=0;
     for(i=0;i<5;i++){
       if(max<arr[i])
          max=arr[i];
       if(min>arr[i])
          min=arr[i];
     }
   System.out.println("数组的最大值是:" +max);
   System.out.println("数组的最小值是:"+min);
   int temp=0;
   for(i=0;i<5;i++){
       for(int j=i;j<5;j++)
       {
           if(arr[i]>arr[j])
           {
               temp = arr[i];
               arr[i]=arr[j];
               arr[j]=temp;
           }
       }
   }
   for(i=0;i<5;i++) System.out.print(arr[i]+" ");
   System.out.println();
   ArrSort.findNumPos(arr,1);
   ArrSort.findNumPos(arr,8);
   
}
    static void findNumPos(int arr[],int numToFind)
    {
        int finded=0;
        for(int i=0;i<5;i++)
        {
            if(arr[i]==numToFind){
                finded=1;
                System.out.println("the pos of " +(numToFind)+" is:"+i);
            }
        }
        if(finded==0) System.out.println((numToFind)+" Not finded");
    }
 }
 