//TestArrays.java

import java.util.Arrays;

public class TestArrays
{
    public static void main(String args[])
    {
        //One-dimensional array initialization and processing loops
        int[] a1 = {1, 3, 5, 7, 9};  //OK, and recommended
        int a2[] = {2, 4, 6, 8, 10}; //OK, but not recommended
        //int[5] a3 = {2, 4, 6, 8, 10};  //illegal
        //int a4[5] = {2, 4, 6, 8, 10};  //illegal
        for (int i=0; i<a1.length; i++ System.out.print(a1[i] + " ");
        System.out.println();
        for (int entry: a2) System.out.print(entry + " ");
        System.out.println();

        //Illustrates sort() method of the Arrays class
        int[] b = {6, 2, 8, 10, 4};
        Arrays.sort(b);
        for (int entry: b) System.out.print(entry + " ");
        System.out.println();

        //Declare, initialize and display a rectangular two-dimensional array
        int [][] twoDimArray1 = { {1, 2, 3}, {4, 5, 6}};
        for (int row = 0; row < 2; row++)
        {
            for (int col = 0; col < 3; col++)
                System.out.print(twoDimArray1[row][col] + " ");
            System.out.println();
        }

        //Declare, initialize and display a jagged two-dimensional array
        int [][] twoDimArray2 = { {1, 2}, {3, 4, 5, 6}, {7, 8, 9} };
        for (int row = 0; row < twoDimArray2.length; row++)
        {
            for (int col = 0; col < twoDimArray2[row].length; col++)
                System.out.print(twoDimArray2[row][col] + " ");
            System.out.println();
        }
    }
}

