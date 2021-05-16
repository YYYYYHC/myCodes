public class Triangle {
    public static void main(String[] arg) {
        int[][] triArray = new int[10][];//动态初始化 不浪费空间
        for(int i=0;i<triArray.length;i++){
            triArray[i] = new int[i+1];
            triArray[i][0] = triArray[i][i] = 1;
            for(int j=1;j<triArray[i].length-1;j++){
                triArray[i][j]=triArray[i-1][j]+triArray[i-1][j-1];
            }
        }

        for(int i=0;i<triArray.length;i++){
            for(int j=0;j<triArray[i].length;j++){
                System.out.print(triArray[i][j]+" ");
            }
            System.out.println();
        }
    }
}