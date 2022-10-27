package algorithm;

import java.util.Scanner;

public class Algorithm {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int numTestCase = in.nextInt();
		for(int i = 0; i < numTestCase; i++) {
			int num = in.nextInt();
			System.out.println(fib(num)[0][1]);
			
		}
	}
	
	public static int[][] MulArr(int[][] a, int[][] b) {
        int[][] arr = new int[2][2];
        arr[0][0] = (a[0][0] * b[0][0] % 1000 + a[0][1] * b[1][0] % 1000) % 1000;
        arr[1][0] = (a[0][0] * b[0][1] % 1000 + a[0][1] * b[1][1] % 1000) % 1000;
        arr[0][1] = (a[1][0] * b[0][0] % 1000 + a[1][1] * b[1][0] % 1000) % 1000;
        arr[1][1] = (a[1][0] * b[0][1] % 1000 + a[1][1] * b[1][1] % 1000) % 1000;
        return arr;
    }

    public static int[][] fib(int n) {
    	if (n == 0) {
            int[][] arr = {{0,0},{0,0}};
            return arr;
        }
        if (n == 1) {
            int[][] arr = {{1,1},{1,0}};
            return arr;
        }
        
        if (n%2==1) {
        	int[][] tmp = fib((n-1)/2);
            return MulArr(MulArr(tmp, tmp), fib(1));
        } else {
        	int[][] tmp = fib(n/2);
            return MulArr(tmp, tmp);
        }
    }
}
