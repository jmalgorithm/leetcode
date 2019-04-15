
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Solution {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		int test = Integer.parseInt(scan.nextLine());
		
		for (int num=1; num<test+1; num++) {
			int N = Integer.parseInt(scan.nextLine());
			String[] X = scan.nextLine().split(" ");
			String[] Y = scan.nextLine().split(" ");
			List<Double[]> points = new ArrayList<>();
			for (int i=0; i<N; i++) {
				Double[] p = new Double[2];
				p[0] = Double.parseDouble(X[i]);
				p[1] = Double.parseDouble(Y[i]);
				points.add(p);
			}
			double E = Double.parseDouble(scan.nextLine());
			
			double[][] distance = new double[N][N];
			for (int i=0; i<N; i++) {
				for (int j=i; j<N; j++) {
					if (i == j) distance[i][j] = Double.MAX_VALUE - 0.1;
					else {
						distance[i][j] = getL2(points.get(i), points.get(j));
						distance[j][i] = distance[i][j];
					}
				}
			}
			
			boolean[] visit = new boolean[N];
			for (int i=0; i<N; i++) visit[i] = false;
			visit[0]= true;
			List<int[]> edges = new LinkedList<>();
			
			for (int i=0; i<N-1; i++) {
				int[] edge = new int[2];
				double min = Double.MAX_VALUE;
				for (int j=0; j<N; j++) {
					for (int k=0; k<N; k++) {
						if (!visit[j]) break;
						else if(!visit[k] && min > distance[j][k]) {
							min = distance[j][k];
							edge[0] = j;
							edge[1] = k;
						}
					}
				}
				if (!visit[edge[1]]) visit[edge[1]] = true;	
				edges.add(edge);
			}
			double answer = 0;
			for (int[] edge: edges) {
				answer += distance[edge[0]][edge[1]];
			}
			System.out.println("#" + num + " " + Math.round(E*answer));
		}
		
	}
	public static Double getL2(Double[] p1, Double[] p2) {
		return (p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]);
	}

}
