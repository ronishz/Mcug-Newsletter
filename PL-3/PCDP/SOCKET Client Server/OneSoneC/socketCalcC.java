import java.io.*;
import java.net.*;
import java.util.Scanner;

public class socketCalcC {
	public static void main(String[] args) {
		try{
			Scanner sc = new Scanner(System.in);
			System.out.print("Enter Number 1:");
			int num1 = sc.nextInt();
			System.out.print("Enter Number 2:");
			int num2 = sc.nextInt();
			System.out.print("\n1.Add\n2.Subtract\n3.Multiply\n4.Divide\nEnter Choice:");
			int choice = sc.nextInt();
			Socket s = new Socket("localhost",6665);
			DataOutputStream dout = new DataOutputStream(s.getOutputStream());
			dout.write(num1);
			dout.write(num2);
			dout.write(choice);
			DataInputStream dis = new DataInputStream(s.getInputStream());
			int result = dis.read();
			System.out.println("Result:"+result);
			dout.flush();
			dout.close();
		}catch(Exception e){System.out.println(e);}
	}
}
