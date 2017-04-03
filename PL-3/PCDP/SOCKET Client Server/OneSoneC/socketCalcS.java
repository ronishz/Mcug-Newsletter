import java.io.*;
import java.net.*;

public class socketCalcS {
	public static void main(String[] args) {
		try{
			int result=0;
			ServerSocket ss = new ServerSocket(6665);
			Socket s = ss.accept();
			DataInputStream dis = new DataInputStream(s.getInputStream());
			int num1 = dis.read();
			int num2 = dis.read();
			int choice = dis.read();
			System.out.println("Number 1:"+num1);
			System.out.println("Number 2:"+num2);
			if(choice == 1){
				System.out.println("Choice is Addition");
				result = num1+num2;
			}
			else if(choice == 2){
				System.out.println("Choice is Subtraction");
				result = num1-num2;
			}
			else if(choice == 3){
				System.out.println("Choice is Multiplication");
				result = num1*num2;
			}
			else if(choice == 4){
				System.out.println("Choice is Division");
				result = num1/num2;
			}
			DataOutputStream dout = new DataOutputStream(s.getOutputStream());
			dout.write(result);
			ss.close();			
		}catch(Exception e){System.out.println(e);}
	}	
}
