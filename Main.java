import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String x = scanner.nextLine();

        String[] t = x.split(" ");
        
        double f = Double.parseDouble(t[2]);


        System.out.print("Student " + t[0] + " bearing roll number " + t[1] + " got ");
        System.out.printf("%.2f", f);
        System.out.print("%");

        scanner.close();
    }
}